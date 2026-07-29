/*
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
*/

#ifndef RELOAD_H
#define RELOAD_H
#if defined(__cplusplus)
extern "C" {
#endif

#include <stdbool.h>

typedef struct reload_lib reload_lib;

typedef struct {
    const char *path;      /* path to the shared library (.dylib/.so/.dll) */
    const char *symbol;    /* primary export looked up after every load, e.g. "scene" */
    void *userdata;

    /* Called right after a successful dlopen, before cwcgl_reload_open()/
     * cwcgl_reload_poll() return -- `lib` is already usable at this point
     * (cwcgl_reload_lookup works), even on the very first load, before
     * cwcgl_reload_open has handed back its result. `sym` is the resolved
     * primary export. Return false to reject the load (cwcgl_reload_open
     * fails / cwcgl_reload_poll leaves the previous library loaded). */
    bool (*on_load)(reload_lib *lib, void *sym, void *userdata);

    /* Called right before dlclose, whether due to a reload or
     * cwcgl_reload_close(). `sym` is the primary export of the library
     * about to be unloaded. */
    void (*on_unload)(reload_lib *lib, void *sym, void *userdata);
} reload_desc;

/* Opens and loads the library for the first time. Returns NULL on failure
 * (file missing, dlopen failed, symbol missing, or on_load returned false). */
reload_lib *cwcgl_reload_open(const reload_desc *desc);

/* Checks whether the on-disk library has changed since the last (re)load, and
 * if so, unloads the old one (on_unload, dlclose) and loads the new one
 * (dlopen, dlsym, on_load). Returns false if a reload was attempted and
 * failed -- the previous library stays loaded and active in that case.
 * Returns true if no reload was needed, or a reload succeeded. */
bool cwcgl_reload_poll(reload_lib *lib);

/* The primary export (as passed via reload_desc.symbol), valid until the next
 * reload or cwcgl_reload_close. */
void *cwcgl_reload_symbol(reload_lib *lib);

/* Looks up an additional named export in the currently loaded library. */
void *cwcgl_reload_lookup(reload_lib *lib, const char *name);

/* Unloads (on_unload, dlclose) and frees the reload_lib. */
void cwcgl_reload_close(reload_lib *lib);

#if defined(__cplusplus)
}
#endif
#endif // RELOAD_H
