@echo off
pushd "%~dp0"
call "C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\VC\\Auxiliary\\Build\\vcvarsall.bat" arm64_x64
popd
cd build
cl /EHsc /Zi /W3 /utf-8 /D_CRT_SECURE_NO_WARNINGS /DGL_LEGACY /I..\ /I..\src ..\tools\test.c ..\src\glWindows.c /link /subsystem:console /out:test.exe
cd ..
