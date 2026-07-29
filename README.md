# cwcGL

> [!WARNING]
> Work in progress

_cwcGL_ is an OpenGL 3.3 core loader with hot-reload support for C/C++. `gl.rb`
generates the bindings from Khronos's `aux/gl.xml`; the generated loader hands
a pre-resolved function-pointer table to reloadable dylibs at load time, so a
dylib can be recompiled and swapped in while a host process keeps running,
with no dangling GL objects or GL state carried over from the previous load.

![zap](./aux/zap.jpg)

Open tickets, including known limitations and follow-up work, are tracked at
[todo.sr.ht/~takeiteasy/cwcGL](https://todo.sr.ht/~takeiteasy/cwcGL).

## Layout

Two independent static libraries, and a test host that links both. Users
include a single header, `src/cwcgl.h`, which bundles the three pieces
below in dependency order:

| Path | What | Depends on |
|---|---|---|
| `src/reload.{h,c}` | Generic dylib hot-reload core (stat/dlopen/dlclose). No GL, no windowing. | libc + dlfcn |
| `src/loader.{h,c}` | Generated OpenGL 3.3 core bindings + `cwcgl_InitOpenGL()` loader (host-only). | OpenGL |
| `src/client.c` | Generated; defines the `__glFoo` globals a reloadable dylib calls through, plus the exported `cwcglLoadAPI()` that receives them from the host (child-only). | OpenGL |
| `src/registry.{h,c}` | Hand-written GL object lifecycle tracking: reclaims anything a reloaded dylib allocated and didn't free, and resets fixed-function state, between loads. Host-only. | `loader.h` |
| `test/host.c` | GLFW test host: opens a window/context, loads a dylib via `cwcgl.h`, exercises the above. Not part of the library. | reload + loader + GLFW |
| `test/leak_test.c` | The dylib `test/host.c` loads -- deliberately leaks a texture and leaves `GL_BLEND` enabled, to prove teardown reclaims both. | `cwcgl.h` |

`gl.rb` regenerates `src/loader.h`, `src/loader.c`, and `src/client.c` from
`aux/gl.xml` + `aux/khrplatform.h` -- run `ruby gl.rb` from the repo root.
`CWCGL_VERSION` (default `3030`, i.e. GL 3.3) controls how much of the core
API gets emitted. File names drop the `cwcgl`/`cwcgl_` prefix (`loader.c`,
not `cwcgl.c`); public C identifiers keep it (`CwcGL_API`, `cwcgl_reload_open`,
`cwcgl_registry_teardown`, ...) so every function a caller sees is
recognizably part of this library regardless of which file it came from.

## How the reload handoff works

A dylib built against `client.c` has **zero undefined GL symbols** --
`nm -u` on it shows nothing but libc. The host resolves every real GL entry
point once via `cwcgl_InitOpenGL()`, builds a `CwcGL_API` struct from those
pointers, and hands it to the dylib's exported `cwcglLoadAPI()` on every
load (including reloads) via `cwcgl_reload_lookup()`. The struct starts with
a `magic`/`abi_version`/`struct_size` header so a dylib built against a
mismatched `CWCGL_VERSION` is rejected with a clear error instead of running
with corrupt pointers.

For the ~20 functions that allocate or free a GL object (`glGenTextures`,
`glCreateProgram`, `glDeleteBuffers`, ...), the host substitutes its own
tracking wrappers (`cwcgl_registry_install()`) instead of the raw driver
pointer -- everything else is zero-cost passthrough. Between one load and
the next, `cwcgl_registry_teardown()` unbinds everything, deletes every
object the previous load's wrappers saw allocated and never freed, and
resets fixed-function GL state (blend/depth/cull/scissor/stencil/clear
color/polygon mode). This runs whether or not the reloaded code cleaned up
after itself -- see `test/leak_test.c` for a dylib that relies on exactly
that.

A debug-only build (`make DEBUG=1`, defining `CWCGL_DEBUG_VALIDATE`) also
installs validation wrappers on a representative set of consumer functions
(`glBindTexture`, `glUseProgram`, `glAttachShader`, and siblings) that flag
handles from a stale reload epoch, and makes teardown log what it reclaims.
Release builds skip all of this and pay for none of the extra wrappers.

## Building

```sh
make             # build test/host.c only
make tests       # build every test/*.c dylib
make all         # both
make run         # build everything, run the host against leak_test
make DEBUG=1 ... # any of the above, with CWCGL_DEBUG_VALIDATE on
```

Requires `pkg-config` and GLFW 3 on the include/library path. On macOS,
OpenGL/Cocoa/IOKit frameworks are linked automatically.

## License

```text
The MIT License (MIT)

Copyright (c) 2022 George Watson

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
