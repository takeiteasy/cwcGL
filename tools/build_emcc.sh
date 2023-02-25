#!/bin/sh
emcc tools/test.c glWindow.c -Isrc -I. -sFULL_ES2=1 -o build/test.html
