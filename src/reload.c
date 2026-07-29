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

#include "reload.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#if defined(_WIN32)
#define RELOAD_WINDOWS
#include <windows.h>
#include <io.h>
#define reload_access _access
#define RELOAD_F_OK 0
#else
#define RELOAD_POSIX
#include <dlfcn.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define reload_access access
#define RELOAD_F_OK F_OK
#endif

struct reload_lib {
    reload_desc desc;
    char *path;
    void *handle;
    void *sym;
#if defined(RELOAD_WINDOWS)
    FILETIME write_time;
    char *shadow_path; /* the .tmp.dll copy actually dlopen'd */
#else
    ino_t inode;
#endif
};

#if defined(RELOAD_WINDOWS)
static FILETIME reload_win32_write_time(const char *path) {
    FILETIME time = {0};
    WIN32_FILE_ATTRIBUTE_DATA data;
    if (GetFileAttributesExA(path, GetFileExInfoStandard, &data))
        time = data.ftLastWriteTime;
    return time;
}

static char *reload_win32_remove_ext(const char *path) {
    char *ret = malloc(strlen(path) + 1);
    if (!ret)
        return NULL;
    strcpy(ret, path);
    char *ext = strrchr(ret, '.');
    if (ext)
        *ext = '\0';
    return ret;
}
#endif

static bool reload_changed(reload_lib *lib) {
#if defined(RELOAD_WINDOWS)
    FILETIME new_time = reload_win32_write_time(lib->path);
    bool changed = CompareFileTime(&new_time, &lib->write_time) != 0;
    if (changed)
        lib->write_time = new_time;
    return changed;
#else
    struct stat attr;
    bool changed = !stat(lib->path, &attr) && lib->inode != attr.st_ino;
    if (changed)
        lib->inode = attr.st_ino;
    return changed;
#endif
}

static void reload_unload_current(reload_lib *lib) {
    if (!lib->handle)
        return;
    if (lib->desc.on_unload)
        lib->desc.on_unload(lib, lib->sym, lib->desc.userdata);
#if defined(RELOAD_WINDOWS)
    FreeLibrary((HMODULE)lib->handle);
    if (lib->shadow_path) {
        DeleteFileA(lib->shadow_path);
        free(lib->shadow_path);
        lib->shadow_path = NULL;
    }
#else
    dlclose(lib->handle);
#endif
    lib->handle = NULL;
    lib->sym = NULL;
}

static bool reload_load_current(reload_lib *lib) {
#if defined(RELOAD_WINDOWS)
    char *no_ext = reload_win32_remove_ext(lib->path);
    if (!no_ext)
        return false;
    size_t shadow_size = strlen(no_ext) + strlen(".tmp.dll") + 1;
    char *shadow = malloc(shadow_size);
    if (!shadow) {
        free(no_ext);
        return false;
    }
    snprintf(shadow, shadow_size, "%s.tmp.dll", no_ext);
    free(no_ext);
    if (!CopyFileA(lib->path, shadow, 0)) {
        free(shadow);
        return false;
    }
    lib->handle = LoadLibraryA(shadow);
    if (!lib->handle) {
        DeleteFileA(shadow);
        free(shadow);
        return false;
    }
    lib->shadow_path = shadow;
    lib->sym = (void *)GetProcAddress((HMODULE)lib->handle, lib->desc.symbol);
#else
    lib->handle = dlopen(lib->path, RTLD_NOW | RTLD_LOCAL);
    if (!lib->handle)
        return false;
    lib->sym = dlsym(lib->handle, lib->desc.symbol);
#endif
    if (!lib->sym)
        goto fail;
    if (lib->desc.on_load && !lib->desc.on_load(lib, lib->sym, lib->desc.userdata))
        goto fail;
    return true;

fail:
#if defined(RELOAD_WINDOWS)
    FreeLibrary((HMODULE)lib->handle);
    if (lib->shadow_path) {
        DeleteFileA(lib->shadow_path);
        free(lib->shadow_path);
        lib->shadow_path = NULL;
    }
#else
    dlclose(lib->handle);
#endif
    lib->handle = NULL;
    lib->sym = NULL;
    return false;
}

reload_lib *cwcgl_reload_open(const reload_desc *desc) {
    if (!desc || !desc->path || !desc->symbol)
        return NULL;
    if (reload_access(desc->path, RELOAD_F_OK) != 0)
        return NULL;

    reload_lib *lib = calloc(1, sizeof(reload_lib));
    if (!lib)
        return NULL;
    lib->desc = *desc;
    lib->path = strdup(desc->path);
    lib->desc.path = lib->path;

    reload_changed(lib); /* prime the change-detection baseline */
    if (!reload_load_current(lib)) {
        free(lib->path);
        free(lib);
        return NULL;
    }
    return lib;
}

bool cwcgl_reload_poll(reload_lib *lib) {
    if (!lib)
        return false;
    if (!reload_changed(lib))
        return true;

    reload_unload_current(lib);
    if (!reload_load_current(lib))
        return false;
    return true;
}

void *cwcgl_reload_symbol(reload_lib *lib) {
    return lib ? lib->sym : NULL;
}

void *cwcgl_reload_lookup(reload_lib *lib, const char *name) {
    if (!lib || !lib->handle || !name)
        return NULL;
#if defined(RELOAD_WINDOWS)
    return (void *)GetProcAddress((HMODULE)lib->handle, name);
#else
    return dlsym(lib->handle, name);
#endif
}

void cwcgl_reload_close(reload_lib *lib) {
    if (!lib)
        return;
    reload_unload_current(lib);
    free(lib->path);
    free(lib);
}
