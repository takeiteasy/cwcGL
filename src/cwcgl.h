/* cwcgl.h -- https://github.com/takeiteasy/cwcGL
 
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
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef __cwcgl_h__
#define __cwcgl_h__
#ifdef __cplusplus
extern "C" {
#endif

#if !defined(CWCGL_CUSTOM_BACKEND)
#if defined(__EMSCRIPTEN__) || defined(EMSCRIPTEN)
#define CWCGL_EMSCRIPTEN
#include <emscripten.h>
#endif

#if defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#define CWCGL_MAC
#elif defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__)
#define CWCGL_WINDOWS
#elif defined(__gnu_linux__) || defined(__linux__) || defined(__unix__)
#define CWCGL_LINUX
#endif
#endif

#define __gl_glcorearb_h_ 1  /* Khronos core */
#define __gl_glext_h_ 1      /* Khronos compatibility */
#define __gl_h_ 1            /* Windows/Linux */
#define __GL_H__ 1           /* Windows */
#define __gl3_h_ 1           /* Mac */

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#define APIENTRY __stdcall
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#if defined(GLAD_GLAPI_EXPORT)
#if defined(_WIN32) || defined(__CYGWIN__)
#if defined(GLAD_GLAPI_EXPORT_BUILD)
#if defined(__GNUC__)
#define GLAPI __attribute__ ((dllexport)) extern
#else
#define GLAPI __declspec(dllexport) extern
#endif
#else
#if defined(__GNUC__)
#define GLAPI __attribute__ ((dllimport)) extern
#else
#define GLAPI __declspec(dllimport) extern
#endif
#endif
#elif defined(__GNUC__) && defined(GLAD_GLAPI_EXPORT_BUILD)
#define GLAPI __attribute__ ((visibility ("default"))) extern
#else
#define GLAPI extern
#endif
#else
#define GLAPI extern
#endif
#endif

#if !defined(CWCGL_VERSION)
#define CWCGL_VERSION 1000
#endif
#define GL_VERSION_1_0 1000
#define GL_VERSION_1_1 1010
#define GL_VERSION_1_2 1020
#define GL_VERSION_1_3 1030
#define GL_VERSION_1_4 1040
#define GL_VERSION_1_5 1050
#define GL_VERSION_2_0 2000
#define GL_VERSION_2_1 2010
#define GL_VERSION_3_0 3000
#define GL_VERSION_3_1 3010
#define GL_VERSION_3_2 3020
#define GL_VERSION_3_3 3030
#define GL_VERSION_4_0 4000
#define GL_VERSION_4_1 4010
#define GL_VERSION_4_2 4020
#define GL_VERSION_4_3 4030
#define GL_VERSION_4_4 4040
#define GL_VERSION_4_5 4050

/* khrplatform.h -- [https://registry.khronos.org/EGL/api/KHR/khrplatform.h]
** Copyright (c) 2008-2018 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

/* Khronos platform-specific types and definitions.
 *
 * The master copy of khrplatform.h is maintained in the Khronos EGL
 * Registry repository at https://github.com/KhronosGroup/EGL-Registry
 * The last semantic modification to khrplatform.h was at commit ID:
 *      67a3e0864c2d75ea5287b9f3d2eb74a745936692
 *
 * Adopters may modify this file to suit their platform. Adopters are
 * encouraged to submit platform specific modifications to the Khronos
 * group so that they can be included in future versions of this file.
 * Please submit changes by filing pull requests or issues on
 * the EGL Registry repository linked above.
 *
 *
 * See the Implementer's Guidelines for information about where this file
 * should be located on your system and for more details of its use:
 *    http://www.khronos.org/registry/implementers_guide.pdf
 *
 * This file should be included as
 *        #include <KHR/khrplatform.h>
 * by Khronos client API header files that use its types and defines.
 *
 * The types in khrplatform.h should only be used to define API-specific types.
 *
 * Types defined in khrplatform.h:
 *    khronos_int8_t              signed   8  bit
 *    khronos_uint8_t             unsigned 8  bit
 *    khronos_int16_t             signed   16 bit
 *    khronos_uint16_t            unsigned 16 bit
 *    khronos_int32_t             signed   32 bit
 *    khronos_uint32_t            unsigned 32 bit
 *    khronos_int64_t             signed   64 bit
 *    khronos_uint64_t            unsigned 64 bit
 *    khronos_intptr_t            signed   same number of bits as a pointer
 *    khronos_uintptr_t           unsigned same number of bits as a pointer
 *    khronos_ssize_t             signed   size
 *    khronos_usize_t             unsigned size
 *    khronos_float_t             signed   32 bit floating point
 *    khronos_time_ns_t           unsigned 64 bit time in nanoseconds
 *    khronos_utime_nanoseconds_t unsigned time interval or absolute time in
 *                                         nanoseconds
 *    khronos_stime_nanoseconds_t signed time interval in nanoseconds
 *    khronos_boolean_enum_t      enumerated boolean type. This should
 *      only be used as a base type when a client API's boolean type is
 *      an enum. Client APIs which use an integer or other type for
 *      booleans cannot use this as the base type for their boolean.
 *
 * Tokens defined in khrplatform.h:
 *
 *    KHRONOS_FALSE, KHRONOS_TRUE Enumerated boolean false/true values.
 *
 *    KHRONOS_SUPPORT_INT64 is 1 if 64 bit integers are supported; otherwise 0.
 *    KHRONOS_SUPPORT_FLOAT is 1 if floats are supported; otherwise 0.
 *
 * Calling convention macros defined in this file:
 *    KHRONOS_APICALL
 *    KHRONOS_APIENTRY
 *    KHRONOS_APIATTRIBUTES
 *
 * These may be used in function prototypes as:
 *
 *      KHRONOS_APICALL void KHRONOS_APIENTRY funcname(
 *                                  int arg1,
 *                                  int arg2) KHRONOS_APIATTRIBUTES;
 */

#if defined(__SCITECH_SNAP__) && !defined(KHRONOS_STATIC)
#   define KHRONOS_STATIC 1
#endif

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APICALL
 *-------------------------------------------------------------------------
 * This precedes the return type of the function in the function prototype.
 */
#if defined(KHRONOS_STATIC)
    /* If the preprocessor constant KHRONOS_STATIC is defined, make the
     * header compatible with static linking. */
#   define KHRONOS_APICALL
#elif defined(_WIN32)
#   define KHRONOS_APICALL __declspec(dllimport)
#elif defined (__SYMBIAN32__)
#   define KHRONOS_APICALL IMPORT_C
#elif defined(__ANDROID__)
#   define KHRONOS_APICALL __attribute__((visibility("default")))
#else
#   define KHRONOS_APICALL
#endif

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APIENTRY
 *-------------------------------------------------------------------------
 * This follows the return type of the function  and precedes the function
 * name in the function prototype.
 */
#if defined(_WIN32) && !defined(_WIN32_WCE) && !defined(__SCITECH_SNAP__)
    /* Win32 but not WinCE */
#   define KHRONOS_APIENTRY __stdcall
#else
#   define KHRONOS_APIENTRY
#endif

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APIATTRIBUTES
 *-------------------------------------------------------------------------
 * This follows the closing parenthesis of the function prototype arguments.
 */
#if defined (__ARMCC_2__)
#define KHRONOS_APIATTRIBUTES __softfp
#else
#define KHRONOS_APIATTRIBUTES
#endif

/*-------------------------------------------------------------------------
 * basic type definitions
 *-----------------------------------------------------------------------*/
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__SCO__) || defined(__USLC__)


/*
 * Using <stdint.h>
 */
#include <stdint.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1
/*
 * To support platform where unsigned long cannot be used interchangeably with
 * inptr_t (e.g. CHERI-extended ISAs), we can use the stdint.h intptr_t.
 * Ideally, we could just use (u)intptr_t everywhere, but this could result in
 * ABI breakage if khronos_uintptr_t is changed from unsigned long to
 * unsigned long long or similar (this results in different C++ name mangling).
 * To avoid changes for existing platforms, we restrict usage of intptr_t to
 * platforms where the size of a pointer is larger than the size of long.
 */
#if defined(__SIZEOF_LONG__) && defined(__SIZEOF_POINTER__)
#if __SIZEOF_POINTER__ > __SIZEOF_LONG__
#define KHRONOS_USE_INTPTR_T
#endif
#endif

#elif defined(__VMS ) || defined(__sgi)

/*
 * Using <inttypes.h>
 */
#include <inttypes.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(_WIN32) && !defined(__SCITECH_SNAP__)

/*
 * Win32
 */
typedef __int32                 khronos_int32_t;
typedef unsigned __int32        khronos_uint32_t;
typedef __int64                 khronos_int64_t;
typedef unsigned __int64        khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__sun__) || defined(__digital__)

/*
 * Sun or Digital
 */
typedef int                     khronos_int32_t;
typedef unsigned int            khronos_uint32_t;
#if defined(__arch64__) || defined(_LP64)
typedef long int                khronos_int64_t;
typedef unsigned long int       khronos_uint64_t;
#else
typedef long long int           khronos_int64_t;
typedef unsigned long long int  khronos_uint64_t;
#endif /* __arch64__ */
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif 0

/*
 * Hypothetical platform with no float or int64 support
 */
typedef int                     khronos_int32_t;
typedef unsigned int            khronos_uint32_t;
#define KHRONOS_SUPPORT_INT64   0
#define KHRONOS_SUPPORT_FLOAT   0

#else

/*
 * Generic fallback
 */
#include <stdint.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#endif


/*
 * Types that are (so far) the same on all platforms
 */
typedef signed   char          khronos_int8_t;
typedef unsigned char          khronos_uint8_t;
typedef signed   short int     khronos_int16_t;
typedef unsigned short int     khronos_uint16_t;

/*
 * Types that differ between LLP64 and LP64 architectures - in LLP64,
 * pointers are 64 bits, but 'long' is still 32 bits. Win64 appears
 * to be the only LLP64 architecture in current use.
 */
#ifdef KHRONOS_USE_INTPTR_T
typedef intptr_t               khronos_intptr_t;
typedef uintptr_t              khronos_uintptr_t;
#elif defined(_WIN64)
typedef signed   long long int khronos_intptr_t;
typedef unsigned long long int khronos_uintptr_t;
#else
typedef signed   long  int     khronos_intptr_t;
typedef unsigned long  int     khronos_uintptr_t;
#endif

#if defined(_WIN64)
typedef signed   long long int khronos_ssize_t;
typedef unsigned long long int khronos_usize_t;
#else
typedef signed   long  int     khronos_ssize_t;
typedef unsigned long  int     khronos_usize_t;
#endif

#if KHRONOS_SUPPORT_FLOAT
/*
 * Float type
 */
typedef          float         khronos_float_t;
#endif

#if KHRONOS_SUPPORT_INT64
/* Time types
 *
 * These types can be used to represent a time interval in nanoseconds or
 * an absolute Unadjusted System Time.  Unadjusted System Time is the number
 * of nanoseconds since some arbitrary system event (e.g. since the last
 * time the system booted).  The Unadjusted System Time is an unsigned
 * 64 bit value that wraps back to 0 every 584 years.  Time intervals
 * may be either signed or unsigned.
 */
typedef khronos_uint64_t       khronos_utime_nanoseconds_t;
typedef khronos_int64_t        khronos_stime_nanoseconds_t;
#endif

/*
 * Dummy value used to pad enum types to 32 bits.
 */
#ifndef KHRONOS_MAX_ENUM
#define KHRONOS_MAX_ENUM 0x7FFFFFFF
#endif

/*
 * Enumerated boolean type
 *
 * Values other than zero should be considered to be true.  Therefore
 * comparisons should not be made against KHRONOS_TRUE.
 */
typedef enum {
    KHRONOS_FALSE = 0,
    KHRONOS_TRUE  = 1,
    KHRONOS_BOOLEAN_ENUM_FORCE_SIZE = KHRONOS_MAX_ENUM
} khronos_boolean_enum_t;
/* end of khrplatform.h */

#if CWCGL_VERSION >= GL_VERSION_1_0
typedef unsigned int GLenum;
typedef khronos_float_t GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef khronos_uint8_t GLubyte;
typedef khronos_int8_t GLbyte;
typedef short GLshort;
typedef unsigned short GLushort;
typedef void GLvoid;
typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
#define glCullFace cwcglglCullFace
typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
#define glFrontFace cwcglglFrontFace
typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
#define glHint cwcglglHint
typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
#define glLineWidth cwcglglLineWidth
typedef void (APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
#define glPointSize cwcglglPointSize
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
#define glPolygonMode cwcglglPolygonMode
typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
#define glScissor cwcglglScissor
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
#define glTexParameterf cwcglglTexParameterf
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat * params);
#define glTexParameterfv cwcglglTexParameterfv
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
#define glTexParameteri cwcglglTexParameteri
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint * params);
#define glTexParameteriv cwcglglTexParameteriv
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage1D cwcglglTexImage1D
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage2D cwcglglTexImage2D
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum buf);
#define glDrawBuffer cwcglglDrawBuffer
typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
#define glClear cwcglglClear
typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glClearColor cwcglglClearColor
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
#define glClearStencil cwcglglClearStencil
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble depth);
#define glClearDepth cwcglglClearDepth
typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
#define glStencilMask cwcglglStencilMask
typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
#define glColorMask cwcglglColorMask
typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
#define glDepthMask cwcglglDepthMask
typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
#define glDisable cwcglglDisable
typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
#define glEnable cwcglglEnable
typedef void (APIENTRYP PFNGLFINISHPROC)(void);
#define glFinish cwcglglFinish
typedef void (APIENTRYP PFNGLFLUSHPROC)(void);
#define glFlush cwcglglFlush
typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
#define glBlendFunc cwcglglBlendFunc
typedef void (APIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
#define glLogicOp cwcglglLogicOp
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
#define glStencilFunc cwcglglStencilFunc
typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
#define glStencilOp cwcglglStencilOp
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
#define glDepthFunc cwcglglDepthFunc
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
#define glPixelStoref cwcglglPixelStoref
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
#define glPixelStorei cwcglglPixelStorei
typedef void (APIENTRYP PFNGLREADBUFFERPROC)(GLenum src);
#define glReadBuffer cwcglglReadBuffer
typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
#define glReadPixels cwcglglReadPixels
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean * data);
#define glGetBooleanv cwcglglGetBooleanv
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble * data);
#define glGetDoublev cwcglglGetDoublev
typedef GLenum (APIENTRYP PFNGLGETERRORPROC)(void);
#define glGetError cwcglglGetError
typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat * data);
#define glGetFloatv cwcglglGetFloatv
typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint * data);
#define glGetIntegerv cwcglglGetIntegerv
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
#define glGetString cwcglglGetString
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
#define glGetTexImage cwcglglGetTexImage
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat * params);
#define glGetTexParameterfv cwcglglGetTexParameterfv
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetTexParameteriv cwcglglGetTexParameteriv
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat * params);
#define glGetTexLevelParameterfv cwcglglGetTexLevelParameterfv
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint * params);
#define glGetTexLevelParameteriv cwcglglGetTexLevelParameteriv
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
#define glIsEnabled cwcglglIsEnabled
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble near, GLdouble far);
#define glDepthRange cwcglglDepthRange
typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
#define glViewport cwcglglViewport
typedef void (APIENTRYP PFNGLNEWLISTPROC)(GLuint list, GLenum mode);
#define glNewList cwcglglNewList
typedef void (APIENTRYP PFNGLENDLISTPROC)(void);
#define glEndList cwcglglEndList
typedef void (APIENTRYP PFNGLCALLLISTPROC)(GLuint list);
#define glCallList cwcglglCallList
typedef void (APIENTRYP PFNGLCALLLISTSPROC)(GLsizei n, GLenum type, const void * lists);
#define glCallLists cwcglglCallLists
typedef void (APIENTRYP PFNGLDELETELISTSPROC)(GLuint list, GLsizei range);
#define glDeleteLists cwcglglDeleteLists
typedef GLuint (APIENTRYP PFNGLGENLISTSPROC)(GLsizei range);
#define glGenLists cwcglglGenLists
typedef void (APIENTRYP PFNGLLISTBASEPROC)(GLuint base);
#define glListBase cwcglglListBase
typedef void (APIENTRYP PFNGLBEGINPROC)(GLenum mode);
#define glBegin cwcglglBegin
typedef void (APIENTRYP PFNGLBITMAPPROC)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap);
#define glBitmap cwcglglBitmap
typedef void (APIENTRYP PFNGLCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
#define glColor3b cwcglglColor3b
typedef void (APIENTRYP PFNGLCOLOR3BVPROC)(const GLbyte * v);
#define glColor3bv cwcglglColor3bv
typedef void (APIENTRYP PFNGLCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
#define glColor3d cwcglglColor3d
typedef void (APIENTRYP PFNGLCOLOR3DVPROC)(const GLdouble * v);
#define glColor3dv cwcglglColor3dv
typedef void (APIENTRYP PFNGLCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
#define glColor3f cwcglglColor3f
typedef void (APIENTRYP PFNGLCOLOR3FVPROC)(const GLfloat * v);
#define glColor3fv cwcglglColor3fv
typedef void (APIENTRYP PFNGLCOLOR3IPROC)(GLint red, GLint green, GLint blue);
#define glColor3i cwcglglColor3i
typedef void (APIENTRYP PFNGLCOLOR3IVPROC)(const GLint * v);
#define glColor3iv cwcglglColor3iv
typedef void (APIENTRYP PFNGLCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
#define glColor3s cwcglglColor3s
typedef void (APIENTRYP PFNGLCOLOR3SVPROC)(const GLshort * v);
#define glColor3sv cwcglglColor3sv
typedef void (APIENTRYP PFNGLCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
#define glColor3ub cwcglglColor3ub
typedef void (APIENTRYP PFNGLCOLOR3UBVPROC)(const GLubyte * v);
#define glColor3ubv cwcglglColor3ubv
typedef void (APIENTRYP PFNGLCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
#define glColor3ui cwcglglColor3ui
typedef void (APIENTRYP PFNGLCOLOR3UIVPROC)(const GLuint * v);
#define glColor3uiv cwcglglColor3uiv
typedef void (APIENTRYP PFNGLCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
#define glColor3us cwcglglColor3us
typedef void (APIENTRYP PFNGLCOLOR3USVPROC)(const GLushort * v);
#define glColor3usv cwcglglColor3usv
typedef void (APIENTRYP PFNGLCOLOR4BPROC)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
#define glColor4b cwcglglColor4b
typedef void (APIENTRYP PFNGLCOLOR4BVPROC)(const GLbyte * v);
#define glColor4bv cwcglglColor4bv
typedef void (APIENTRYP PFNGLCOLOR4DPROC)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
#define glColor4d cwcglglColor4d
typedef void (APIENTRYP PFNGLCOLOR4DVPROC)(const GLdouble * v);
#define glColor4dv cwcglglColor4dv
typedef void (APIENTRYP PFNGLCOLOR4FPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glColor4f cwcglglColor4f
typedef void (APIENTRYP PFNGLCOLOR4FVPROC)(const GLfloat * v);
#define glColor4fv cwcglglColor4fv
typedef void (APIENTRYP PFNGLCOLOR4IPROC)(GLint red, GLint green, GLint blue, GLint alpha);
#define glColor4i cwcglglColor4i
typedef void (APIENTRYP PFNGLCOLOR4IVPROC)(const GLint * v);
#define glColor4iv cwcglglColor4iv
typedef void (APIENTRYP PFNGLCOLOR4SPROC)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
#define glColor4s cwcglglColor4s
typedef void (APIENTRYP PFNGLCOLOR4SVPROC)(const GLshort * v);
#define glColor4sv cwcglglColor4sv
typedef void (APIENTRYP PFNGLCOLOR4UBPROC)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
#define glColor4ub cwcglglColor4ub
typedef void (APIENTRYP PFNGLCOLOR4UBVPROC)(const GLubyte * v);
#define glColor4ubv cwcglglColor4ubv
typedef void (APIENTRYP PFNGLCOLOR4UIPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
#define glColor4ui cwcglglColor4ui
typedef void (APIENTRYP PFNGLCOLOR4UIVPROC)(const GLuint * v);
#define glColor4uiv cwcglglColor4uiv
typedef void (APIENTRYP PFNGLCOLOR4USPROC)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
#define glColor4us cwcglglColor4us
typedef void (APIENTRYP PFNGLCOLOR4USVPROC)(const GLushort * v);
#define glColor4usv cwcglglColor4usv
typedef void (APIENTRYP PFNGLEDGEFLAGPROC)(GLboolean flag);
#define glEdgeFlag cwcglglEdgeFlag
typedef void (APIENTRYP PFNGLEDGEFLAGVPROC)(const GLboolean * flag);
#define glEdgeFlagv cwcglglEdgeFlagv
typedef void (APIENTRYP PFNGLENDPROC)(void);
#define glEnd cwcglglEnd
typedef void (APIENTRYP PFNGLINDEXDPROC)(GLdouble c);
#define glIndexd cwcglglIndexd
typedef void (APIENTRYP PFNGLINDEXDVPROC)(const GLdouble * c);
#define glIndexdv cwcglglIndexdv
typedef void (APIENTRYP PFNGLINDEXFPROC)(GLfloat c);
#define glIndexf cwcglglIndexf
typedef void (APIENTRYP PFNGLINDEXFVPROC)(const GLfloat * c);
#define glIndexfv cwcglglIndexfv
typedef void (APIENTRYP PFNGLINDEXIPROC)(GLint c);
#define glIndexi cwcglglIndexi
typedef void (APIENTRYP PFNGLINDEXIVPROC)(const GLint * c);
#define glIndexiv cwcglglIndexiv
typedef void (APIENTRYP PFNGLINDEXSPROC)(GLshort c);
#define glIndexs cwcglglIndexs
typedef void (APIENTRYP PFNGLINDEXSVPROC)(const GLshort * c);
#define glIndexsv cwcglglIndexsv
typedef void (APIENTRYP PFNGLNORMAL3BPROC)(GLbyte nx, GLbyte ny, GLbyte nz);
#define glNormal3b cwcglglNormal3b
typedef void (APIENTRYP PFNGLNORMAL3BVPROC)(const GLbyte * v);
#define glNormal3bv cwcglglNormal3bv
typedef void (APIENTRYP PFNGLNORMAL3DPROC)(GLdouble nx, GLdouble ny, GLdouble nz);
#define glNormal3d cwcglglNormal3d
typedef void (APIENTRYP PFNGLNORMAL3DVPROC)(const GLdouble * v);
#define glNormal3dv cwcglglNormal3dv
typedef void (APIENTRYP PFNGLNORMAL3FPROC)(GLfloat nx, GLfloat ny, GLfloat nz);
#define glNormal3f cwcglglNormal3f
typedef void (APIENTRYP PFNGLNORMAL3FVPROC)(const GLfloat * v);
#define glNormal3fv cwcglglNormal3fv
typedef void (APIENTRYP PFNGLNORMAL3IPROC)(GLint nx, GLint ny, GLint nz);
#define glNormal3i cwcglglNormal3i
typedef void (APIENTRYP PFNGLNORMAL3IVPROC)(const GLint * v);
#define glNormal3iv cwcglglNormal3iv
typedef void (APIENTRYP PFNGLNORMAL3SPROC)(GLshort nx, GLshort ny, GLshort nz);
#define glNormal3s cwcglglNormal3s
typedef void (APIENTRYP PFNGLNORMAL3SVPROC)(const GLshort * v);
#define glNormal3sv cwcglglNormal3sv
typedef void (APIENTRYP PFNGLRASTERPOS2DPROC)(GLdouble x, GLdouble y);
#define glRasterPos2d cwcglglRasterPos2d
typedef void (APIENTRYP PFNGLRASTERPOS2DVPROC)(const GLdouble * v);
#define glRasterPos2dv cwcglglRasterPos2dv
typedef void (APIENTRYP PFNGLRASTERPOS2FPROC)(GLfloat x, GLfloat y);
#define glRasterPos2f cwcglglRasterPos2f
typedef void (APIENTRYP PFNGLRASTERPOS2FVPROC)(const GLfloat * v);
#define glRasterPos2fv cwcglglRasterPos2fv
typedef void (APIENTRYP PFNGLRASTERPOS2IPROC)(GLint x, GLint y);
#define glRasterPos2i cwcglglRasterPos2i
typedef void (APIENTRYP PFNGLRASTERPOS2IVPROC)(const GLint * v);
#define glRasterPos2iv cwcglglRasterPos2iv
typedef void (APIENTRYP PFNGLRASTERPOS2SPROC)(GLshort x, GLshort y);
#define glRasterPos2s cwcglglRasterPos2s
typedef void (APIENTRYP PFNGLRASTERPOS2SVPROC)(const GLshort * v);
#define glRasterPos2sv cwcglglRasterPos2sv
typedef void (APIENTRYP PFNGLRASTERPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glRasterPos3d cwcglglRasterPos3d
typedef void (APIENTRYP PFNGLRASTERPOS3DVPROC)(const GLdouble * v);
#define glRasterPos3dv cwcglglRasterPos3dv
typedef void (APIENTRYP PFNGLRASTERPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glRasterPos3f cwcglglRasterPos3f
typedef void (APIENTRYP PFNGLRASTERPOS3FVPROC)(const GLfloat * v);
#define glRasterPos3fv cwcglglRasterPos3fv
typedef void (APIENTRYP PFNGLRASTERPOS3IPROC)(GLint x, GLint y, GLint z);
#define glRasterPos3i cwcglglRasterPos3i
typedef void (APIENTRYP PFNGLRASTERPOS3IVPROC)(const GLint * v);
#define glRasterPos3iv cwcglglRasterPos3iv
typedef void (APIENTRYP PFNGLRASTERPOS3SPROC)(GLshort x, GLshort y, GLshort z);
#define glRasterPos3s cwcglglRasterPos3s
typedef void (APIENTRYP PFNGLRASTERPOS3SVPROC)(const GLshort * v);
#define glRasterPos3sv cwcglglRasterPos3sv
typedef void (APIENTRYP PFNGLRASTERPOS4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glRasterPos4d cwcglglRasterPos4d
typedef void (APIENTRYP PFNGLRASTERPOS4DVPROC)(const GLdouble * v);
#define glRasterPos4dv cwcglglRasterPos4dv
typedef void (APIENTRYP PFNGLRASTERPOS4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glRasterPos4f cwcglglRasterPos4f
typedef void (APIENTRYP PFNGLRASTERPOS4FVPROC)(const GLfloat * v);
#define glRasterPos4fv cwcglglRasterPos4fv
typedef void (APIENTRYP PFNGLRASTERPOS4IPROC)(GLint x, GLint y, GLint z, GLint w);
#define glRasterPos4i cwcglglRasterPos4i
typedef void (APIENTRYP PFNGLRASTERPOS4IVPROC)(const GLint * v);
#define glRasterPos4iv cwcglglRasterPos4iv
typedef void (APIENTRYP PFNGLRASTERPOS4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
#define glRasterPos4s cwcglglRasterPos4s
typedef void (APIENTRYP PFNGLRASTERPOS4SVPROC)(const GLshort * v);
#define glRasterPos4sv cwcglglRasterPos4sv
typedef void (APIENTRYP PFNGLRECTDPROC)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
#define glRectd cwcglglRectd
typedef void (APIENTRYP PFNGLRECTDVPROC)(const GLdouble * v1, const GLdouble * v2);
#define glRectdv cwcglglRectdv
typedef void (APIENTRYP PFNGLRECTFPROC)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
#define glRectf cwcglglRectf
typedef void (APIENTRYP PFNGLRECTFVPROC)(const GLfloat * v1, const GLfloat * v2);
#define glRectfv cwcglglRectfv
typedef void (APIENTRYP PFNGLRECTIPROC)(GLint x1, GLint y1, GLint x2, GLint y2);
#define glRecti cwcglglRecti
typedef void (APIENTRYP PFNGLRECTIVPROC)(const GLint * v1, const GLint * v2);
#define glRectiv cwcglglRectiv
typedef void (APIENTRYP PFNGLRECTSPROC)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
#define glRects cwcglglRects
typedef void (APIENTRYP PFNGLRECTSVPROC)(const GLshort * v1, const GLshort * v2);
#define glRectsv cwcglglRectsv
typedef void (APIENTRYP PFNGLTEXCOORD1DPROC)(GLdouble s);
#define glTexCoord1d cwcglglTexCoord1d
typedef void (APIENTRYP PFNGLTEXCOORD1DVPROC)(const GLdouble * v);
#define glTexCoord1dv cwcglglTexCoord1dv
typedef void (APIENTRYP PFNGLTEXCOORD1FPROC)(GLfloat s);
#define glTexCoord1f cwcglglTexCoord1f
typedef void (APIENTRYP PFNGLTEXCOORD1FVPROC)(const GLfloat * v);
#define glTexCoord1fv cwcglglTexCoord1fv
typedef void (APIENTRYP PFNGLTEXCOORD1IPROC)(GLint s);
#define glTexCoord1i cwcglglTexCoord1i
typedef void (APIENTRYP PFNGLTEXCOORD1IVPROC)(const GLint * v);
#define glTexCoord1iv cwcglglTexCoord1iv
typedef void (APIENTRYP PFNGLTEXCOORD1SPROC)(GLshort s);
#define glTexCoord1s cwcglglTexCoord1s
typedef void (APIENTRYP PFNGLTEXCOORD1SVPROC)(const GLshort * v);
#define glTexCoord1sv cwcglglTexCoord1sv
typedef void (APIENTRYP PFNGLTEXCOORD2DPROC)(GLdouble s, GLdouble t);
#define glTexCoord2d cwcglglTexCoord2d
typedef void (APIENTRYP PFNGLTEXCOORD2DVPROC)(const GLdouble * v);
#define glTexCoord2dv cwcglglTexCoord2dv
typedef void (APIENTRYP PFNGLTEXCOORD2FPROC)(GLfloat s, GLfloat t);
#define glTexCoord2f cwcglglTexCoord2f
typedef void (APIENTRYP PFNGLTEXCOORD2FVPROC)(const GLfloat * v);
#define glTexCoord2fv cwcglglTexCoord2fv
typedef void (APIENTRYP PFNGLTEXCOORD2IPROC)(GLint s, GLint t);
#define glTexCoord2i cwcglglTexCoord2i
typedef void (APIENTRYP PFNGLTEXCOORD2IVPROC)(const GLint * v);
#define glTexCoord2iv cwcglglTexCoord2iv
typedef void (APIENTRYP PFNGLTEXCOORD2SPROC)(GLshort s, GLshort t);
#define glTexCoord2s cwcglglTexCoord2s
typedef void (APIENTRYP PFNGLTEXCOORD2SVPROC)(const GLshort * v);
#define glTexCoord2sv cwcglglTexCoord2sv
typedef void (APIENTRYP PFNGLTEXCOORD3DPROC)(GLdouble s, GLdouble t, GLdouble r);
#define glTexCoord3d cwcglglTexCoord3d
typedef void (APIENTRYP PFNGLTEXCOORD3DVPROC)(const GLdouble * v);
#define glTexCoord3dv cwcglglTexCoord3dv
typedef void (APIENTRYP PFNGLTEXCOORD3FPROC)(GLfloat s, GLfloat t, GLfloat r);
#define glTexCoord3f cwcglglTexCoord3f
typedef void (APIENTRYP PFNGLTEXCOORD3FVPROC)(const GLfloat * v);
#define glTexCoord3fv cwcglglTexCoord3fv
typedef void (APIENTRYP PFNGLTEXCOORD3IPROC)(GLint s, GLint t, GLint r);
#define glTexCoord3i cwcglglTexCoord3i
typedef void (APIENTRYP PFNGLTEXCOORD3IVPROC)(const GLint * v);
#define glTexCoord3iv cwcglglTexCoord3iv
typedef void (APIENTRYP PFNGLTEXCOORD3SPROC)(GLshort s, GLshort t, GLshort r);
#define glTexCoord3s cwcglglTexCoord3s
typedef void (APIENTRYP PFNGLTEXCOORD3SVPROC)(const GLshort * v);
#define glTexCoord3sv cwcglglTexCoord3sv
typedef void (APIENTRYP PFNGLTEXCOORD4DPROC)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#define glTexCoord4d cwcglglTexCoord4d
typedef void (APIENTRYP PFNGLTEXCOORD4DVPROC)(const GLdouble * v);
#define glTexCoord4dv cwcglglTexCoord4dv
typedef void (APIENTRYP PFNGLTEXCOORD4FPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#define glTexCoord4f cwcglglTexCoord4f
typedef void (APIENTRYP PFNGLTEXCOORD4FVPROC)(const GLfloat * v);
#define glTexCoord4fv cwcglglTexCoord4fv
typedef void (APIENTRYP PFNGLTEXCOORD4IPROC)(GLint s, GLint t, GLint r, GLint q);
#define glTexCoord4i cwcglglTexCoord4i
typedef void (APIENTRYP PFNGLTEXCOORD4IVPROC)(const GLint * v);
#define glTexCoord4iv cwcglglTexCoord4iv
typedef void (APIENTRYP PFNGLTEXCOORD4SPROC)(GLshort s, GLshort t, GLshort r, GLshort q);
#define glTexCoord4s cwcglglTexCoord4s
typedef void (APIENTRYP PFNGLTEXCOORD4SVPROC)(const GLshort * v);
#define glTexCoord4sv cwcglglTexCoord4sv
typedef void (APIENTRYP PFNGLVERTEX2DPROC)(GLdouble x, GLdouble y);
#define glVertex2d cwcglglVertex2d
typedef void (APIENTRYP PFNGLVERTEX2DVPROC)(const GLdouble * v);
#define glVertex2dv cwcglglVertex2dv
typedef void (APIENTRYP PFNGLVERTEX2FPROC)(GLfloat x, GLfloat y);
#define glVertex2f cwcglglVertex2f
typedef void (APIENTRYP PFNGLVERTEX2FVPROC)(const GLfloat * v);
#define glVertex2fv cwcglglVertex2fv
typedef void (APIENTRYP PFNGLVERTEX2IPROC)(GLint x, GLint y);
#define glVertex2i cwcglglVertex2i
typedef void (APIENTRYP PFNGLVERTEX2IVPROC)(const GLint * v);
#define glVertex2iv cwcglglVertex2iv
typedef void (APIENTRYP PFNGLVERTEX2SPROC)(GLshort x, GLshort y);
#define glVertex2s cwcglglVertex2s
typedef void (APIENTRYP PFNGLVERTEX2SVPROC)(const GLshort * v);
#define glVertex2sv cwcglglVertex2sv
typedef void (APIENTRYP PFNGLVERTEX3DPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glVertex3d cwcglglVertex3d
typedef void (APIENTRYP PFNGLVERTEX3DVPROC)(const GLdouble * v);
#define glVertex3dv cwcglglVertex3dv
typedef void (APIENTRYP PFNGLVERTEX3FPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glVertex3f cwcglglVertex3f
typedef void (APIENTRYP PFNGLVERTEX3FVPROC)(const GLfloat * v);
#define glVertex3fv cwcglglVertex3fv
typedef void (APIENTRYP PFNGLVERTEX3IPROC)(GLint x, GLint y, GLint z);
#define glVertex3i cwcglglVertex3i
typedef void (APIENTRYP PFNGLVERTEX3IVPROC)(const GLint * v);
#define glVertex3iv cwcglglVertex3iv
typedef void (APIENTRYP PFNGLVERTEX3SPROC)(GLshort x, GLshort y, GLshort z);
#define glVertex3s cwcglglVertex3s
typedef void (APIENTRYP PFNGLVERTEX3SVPROC)(const GLshort * v);
#define glVertex3sv cwcglglVertex3sv
typedef void (APIENTRYP PFNGLVERTEX4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertex4d cwcglglVertex4d
typedef void (APIENTRYP PFNGLVERTEX4DVPROC)(const GLdouble * v);
#define glVertex4dv cwcglglVertex4dv
typedef void (APIENTRYP PFNGLVERTEX4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertex4f cwcglglVertex4f
typedef void (APIENTRYP PFNGLVERTEX4FVPROC)(const GLfloat * v);
#define glVertex4fv cwcglglVertex4fv
typedef void (APIENTRYP PFNGLVERTEX4IPROC)(GLint x, GLint y, GLint z, GLint w);
#define glVertex4i cwcglglVertex4i
typedef void (APIENTRYP PFNGLVERTEX4IVPROC)(const GLint * v);
#define glVertex4iv cwcglglVertex4iv
typedef void (APIENTRYP PFNGLVERTEX4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertex4s cwcglglVertex4s
typedef void (APIENTRYP PFNGLVERTEX4SVPROC)(const GLshort * v);
#define glVertex4sv cwcglglVertex4sv
typedef void (APIENTRYP PFNGLCLIPPLANEPROC)(GLenum plane, const GLdouble * equation);
#define glClipPlane cwcglglClipPlane
typedef void (APIENTRYP PFNGLCOLORMATERIALPROC)(GLenum face, GLenum mode);
#define glColorMaterial cwcglglColorMaterial
typedef void (APIENTRYP PFNGLFOGFPROC)(GLenum pname, GLfloat param);
#define glFogf cwcglglFogf
typedef void (APIENTRYP PFNGLFOGFVPROC)(GLenum pname, const GLfloat * params);
#define glFogfv cwcglglFogfv
typedef void (APIENTRYP PFNGLFOGIPROC)(GLenum pname, GLint param);
#define glFogi cwcglglFogi
typedef void (APIENTRYP PFNGLFOGIVPROC)(GLenum pname, const GLint * params);
#define glFogiv cwcglglFogiv
typedef void (APIENTRYP PFNGLLIGHTFPROC)(GLenum light, GLenum pname, GLfloat param);
#define glLightf cwcglglLightf
typedef void (APIENTRYP PFNGLLIGHTFVPROC)(GLenum light, GLenum pname, const GLfloat * params);
#define glLightfv cwcglglLightfv
typedef void (APIENTRYP PFNGLLIGHTIPROC)(GLenum light, GLenum pname, GLint param);
#define glLighti cwcglglLighti
typedef void (APIENTRYP PFNGLLIGHTIVPROC)(GLenum light, GLenum pname, const GLint * params);
#define glLightiv cwcglglLightiv
typedef void (APIENTRYP PFNGLLIGHTMODELFPROC)(GLenum pname, GLfloat param);
#define glLightModelf cwcglglLightModelf
typedef void (APIENTRYP PFNGLLIGHTMODELFVPROC)(GLenum pname, const GLfloat * params);
#define glLightModelfv cwcglglLightModelfv
typedef void (APIENTRYP PFNGLLIGHTMODELIPROC)(GLenum pname, GLint param);
#define glLightModeli cwcglglLightModeli
typedef void (APIENTRYP PFNGLLIGHTMODELIVPROC)(GLenum pname, const GLint * params);
#define glLightModeliv cwcglglLightModeliv
typedef void (APIENTRYP PFNGLLINESTIPPLEPROC)(GLint factor, GLushort pattern);
#define glLineStipple cwcglglLineStipple
typedef void (APIENTRYP PFNGLMATERIALFPROC)(GLenum face, GLenum pname, GLfloat param);
#define glMaterialf cwcglglMaterialf
typedef void (APIENTRYP PFNGLMATERIALFVPROC)(GLenum face, GLenum pname, const GLfloat * params);
#define glMaterialfv cwcglglMaterialfv
typedef void (APIENTRYP PFNGLMATERIALIPROC)(GLenum face, GLenum pname, GLint param);
#define glMateriali cwcglglMateriali
typedef void (APIENTRYP PFNGLMATERIALIVPROC)(GLenum face, GLenum pname, const GLint * params);
#define glMaterialiv cwcglglMaterialiv
typedef void (APIENTRYP PFNGLPOLYGONSTIPPLEPROC)(const GLubyte * mask);
#define glPolygonStipple cwcglglPolygonStipple
typedef void (APIENTRYP PFNGLSHADEMODELPROC)(GLenum mode);
#define glShadeModel cwcglglShadeModel
typedef void (APIENTRYP PFNGLTEXENVFPROC)(GLenum target, GLenum pname, GLfloat param);
#define glTexEnvf cwcglglTexEnvf
typedef void (APIENTRYP PFNGLTEXENVFVPROC)(GLenum target, GLenum pname, const GLfloat * params);
#define glTexEnvfv cwcglglTexEnvfv
typedef void (APIENTRYP PFNGLTEXENVIPROC)(GLenum target, GLenum pname, GLint param);
#define glTexEnvi cwcglglTexEnvi
typedef void (APIENTRYP PFNGLTEXENVIVPROC)(GLenum target, GLenum pname, const GLint * params);
#define glTexEnviv cwcglglTexEnviv
typedef void (APIENTRYP PFNGLTEXGENDPROC)(GLenum coord, GLenum pname, GLdouble param);
#define glTexGend cwcglglTexGend
typedef void (APIENTRYP PFNGLTEXGENDVPROC)(GLenum coord, GLenum pname, const GLdouble * params);
#define glTexGendv cwcglglTexGendv
typedef void (APIENTRYP PFNGLTEXGENFPROC)(GLenum coord, GLenum pname, GLfloat param);
#define glTexGenf cwcglglTexGenf
typedef void (APIENTRYP PFNGLTEXGENFVPROC)(GLenum coord, GLenum pname, const GLfloat * params);
#define glTexGenfv cwcglglTexGenfv
typedef void (APIENTRYP PFNGLTEXGENIPROC)(GLenum coord, GLenum pname, GLint param);
#define glTexGeni cwcglglTexGeni
typedef void (APIENTRYP PFNGLTEXGENIVPROC)(GLenum coord, GLenum pname, const GLint * params);
#define glTexGeniv cwcglglTexGeniv
typedef void (APIENTRYP PFNGLFEEDBACKBUFFERPROC)(GLsizei size, GLenum type, GLfloat * buffer);
#define glFeedbackBuffer cwcglglFeedbackBuffer
typedef void (APIENTRYP PFNGLSELECTBUFFERPROC)(GLsizei size, GLuint * buffer);
#define glSelectBuffer cwcglglSelectBuffer
typedef GLint (APIENTRYP PFNGLRENDERMODEPROC)(GLenum mode);
#define glRenderMode cwcglglRenderMode
typedef void (APIENTRYP PFNGLINITNAMESPROC)(void);
#define glInitNames cwcglglInitNames
typedef void (APIENTRYP PFNGLLOADNAMEPROC)(GLuint name);
#define glLoadName cwcglglLoadName
typedef void (APIENTRYP PFNGLPASSTHROUGHPROC)(GLfloat token);
#define glPassThrough cwcglglPassThrough
typedef void (APIENTRYP PFNGLPOPNAMEPROC)(void);
#define glPopName cwcglglPopName
typedef void (APIENTRYP PFNGLPUSHNAMEPROC)(GLuint name);
#define glPushName cwcglglPushName
typedef void (APIENTRYP PFNGLCLEARACCUMPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glClearAccum cwcglglClearAccum
typedef void (APIENTRYP PFNGLCLEARINDEXPROC)(GLfloat c);
#define glClearIndex cwcglglClearIndex
typedef void (APIENTRYP PFNGLINDEXMASKPROC)(GLuint mask);
#define glIndexMask cwcglglIndexMask
typedef void (APIENTRYP PFNGLACCUMPROC)(GLenum op, GLfloat value);
#define glAccum cwcglglAccum
typedef void (APIENTRYP PFNGLPOPATTRIBPROC)(void);
#define glPopAttrib cwcglglPopAttrib
typedef void (APIENTRYP PFNGLPUSHATTRIBPROC)(GLbitfield mask);
#define glPushAttrib cwcglglPushAttrib
typedef void (APIENTRYP PFNGLMAP1DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points);
#define glMap1d cwcglglMap1d
typedef void (APIENTRYP PFNGLMAP1FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points);
#define glMap1f cwcglglMap1f
typedef void (APIENTRYP PFNGLMAP2DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points);
#define glMap2d cwcglglMap2d
typedef void (APIENTRYP PFNGLMAP2FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points);
#define glMap2f cwcglglMap2f
typedef void (APIENTRYP PFNGLMAPGRID1DPROC)(GLint un, GLdouble u1, GLdouble u2);
#define glMapGrid1d cwcglglMapGrid1d
typedef void (APIENTRYP PFNGLMAPGRID1FPROC)(GLint un, GLfloat u1, GLfloat u2);
#define glMapGrid1f cwcglglMapGrid1f
typedef void (APIENTRYP PFNGLMAPGRID2DPROC)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
#define glMapGrid2d cwcglglMapGrid2d
typedef void (APIENTRYP PFNGLMAPGRID2FPROC)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
#define glMapGrid2f cwcglglMapGrid2f
typedef void (APIENTRYP PFNGLEVALCOORD1DPROC)(GLdouble u);
#define glEvalCoord1d cwcglglEvalCoord1d
typedef void (APIENTRYP PFNGLEVALCOORD1DVPROC)(const GLdouble * u);
#define glEvalCoord1dv cwcglglEvalCoord1dv
typedef void (APIENTRYP PFNGLEVALCOORD1FPROC)(GLfloat u);
#define glEvalCoord1f cwcglglEvalCoord1f
typedef void (APIENTRYP PFNGLEVALCOORD1FVPROC)(const GLfloat * u);
#define glEvalCoord1fv cwcglglEvalCoord1fv
typedef void (APIENTRYP PFNGLEVALCOORD2DPROC)(GLdouble u, GLdouble v);
#define glEvalCoord2d cwcglglEvalCoord2d
typedef void (APIENTRYP PFNGLEVALCOORD2DVPROC)(const GLdouble * u);
#define glEvalCoord2dv cwcglglEvalCoord2dv
typedef void (APIENTRYP PFNGLEVALCOORD2FPROC)(GLfloat u, GLfloat v);
#define glEvalCoord2f cwcglglEvalCoord2f
typedef void (APIENTRYP PFNGLEVALCOORD2FVPROC)(const GLfloat * u);
#define glEvalCoord2fv cwcglglEvalCoord2fv
typedef void (APIENTRYP PFNGLEVALMESH1PROC)(GLenum mode, GLint i1, GLint i2);
#define glEvalMesh1 cwcglglEvalMesh1
typedef void (APIENTRYP PFNGLEVALPOINT1PROC)(GLint i);
#define glEvalPoint1 cwcglglEvalPoint1
typedef void (APIENTRYP PFNGLEVALMESH2PROC)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
#define glEvalMesh2 cwcglglEvalMesh2
typedef void (APIENTRYP PFNGLEVALPOINT2PROC)(GLint i, GLint j);
#define glEvalPoint2 cwcglglEvalPoint2
typedef void (APIENTRYP PFNGLALPHAFUNCPROC)(GLenum func, GLfloat ref);
#define glAlphaFunc cwcglglAlphaFunc
typedef void (APIENTRYP PFNGLPIXELZOOMPROC)(GLfloat xfactor, GLfloat yfactor);
#define glPixelZoom cwcglglPixelZoom
typedef void (APIENTRYP PFNGLPIXELTRANSFERFPROC)(GLenum pname, GLfloat param);
#define glPixelTransferf cwcglglPixelTransferf
typedef void (APIENTRYP PFNGLPIXELTRANSFERIPROC)(GLenum pname, GLint param);
#define glPixelTransferi cwcglglPixelTransferi
typedef void (APIENTRYP PFNGLPIXELMAPFVPROC)(GLenum map, GLsizei mapsize, const GLfloat * values);
#define glPixelMapfv cwcglglPixelMapfv
typedef void (APIENTRYP PFNGLPIXELMAPUIVPROC)(GLenum map, GLsizei mapsize, const GLuint * values);
#define glPixelMapuiv cwcglglPixelMapuiv
typedef void (APIENTRYP PFNGLPIXELMAPUSVPROC)(GLenum map, GLsizei mapsize, const GLushort * values);
#define glPixelMapusv cwcglglPixelMapusv
typedef void (APIENTRYP PFNGLCOPYPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
#define glCopyPixels cwcglglCopyPixels
typedef void (APIENTRYP PFNGLDRAWPIXELSPROC)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glDrawPixels cwcglglDrawPixels
typedef void (APIENTRYP PFNGLGETCLIPPLANEPROC)(GLenum plane, GLdouble * equation);
#define glGetClipPlane cwcglglGetClipPlane
typedef void (APIENTRYP PFNGLGETLIGHTFVPROC)(GLenum light, GLenum pname, GLfloat * params);
#define glGetLightfv cwcglglGetLightfv
typedef void (APIENTRYP PFNGLGETLIGHTIVPROC)(GLenum light, GLenum pname, GLint * params);
#define glGetLightiv cwcglglGetLightiv
typedef void (APIENTRYP PFNGLGETMAPDVPROC)(GLenum target, GLenum query, GLdouble * v);
#define glGetMapdv cwcglglGetMapdv
typedef void (APIENTRYP PFNGLGETMAPFVPROC)(GLenum target, GLenum query, GLfloat * v);
#define glGetMapfv cwcglglGetMapfv
typedef void (APIENTRYP PFNGLGETMAPIVPROC)(GLenum target, GLenum query, GLint * v);
#define glGetMapiv cwcglglGetMapiv
typedef void (APIENTRYP PFNGLGETMATERIALFVPROC)(GLenum face, GLenum pname, GLfloat * params);
#define glGetMaterialfv cwcglglGetMaterialfv
typedef void (APIENTRYP PFNGLGETMATERIALIVPROC)(GLenum face, GLenum pname, GLint * params);
#define glGetMaterialiv cwcglglGetMaterialiv
typedef void (APIENTRYP PFNGLGETPIXELMAPFVPROC)(GLenum map, GLfloat * values);
#define glGetPixelMapfv cwcglglGetPixelMapfv
typedef void (APIENTRYP PFNGLGETPIXELMAPUIVPROC)(GLenum map, GLuint * values);
#define glGetPixelMapuiv cwcglglGetPixelMapuiv
typedef void (APIENTRYP PFNGLGETPIXELMAPUSVPROC)(GLenum map, GLushort * values);
#define glGetPixelMapusv cwcglglGetPixelMapusv
typedef void (APIENTRYP PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte * mask);
#define glGetPolygonStipple cwcglglGetPolygonStipple
typedef void (APIENTRYP PFNGLGETTEXENVFVPROC)(GLenum target, GLenum pname, GLfloat * params);
#define glGetTexEnvfv cwcglglGetTexEnvfv
typedef void (APIENTRYP PFNGLGETTEXENVIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetTexEnviv cwcglglGetTexEnviv
typedef void (APIENTRYP PFNGLGETTEXGENDVPROC)(GLenum coord, GLenum pname, GLdouble * params);
#define glGetTexGendv cwcglglGetTexGendv
typedef void (APIENTRYP PFNGLGETTEXGENFVPROC)(GLenum coord, GLenum pname, GLfloat * params);
#define glGetTexGenfv cwcglglGetTexGenfv
typedef void (APIENTRYP PFNGLGETTEXGENIVPROC)(GLenum coord, GLenum pname, GLint * params);
#define glGetTexGeniv cwcglglGetTexGeniv
typedef GLboolean (APIENTRYP PFNGLISLISTPROC)(GLuint list);
#define glIsList cwcglglIsList
typedef void (APIENTRYP PFNGLFRUSTUMPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glFrustum cwcglglFrustum
typedef void (APIENTRYP PFNGLLOADIDENTITYPROC)(void);
#define glLoadIdentity cwcglglLoadIdentity
typedef void (APIENTRYP PFNGLLOADMATRIXFPROC)(const GLfloat * m);
#define glLoadMatrixf cwcglglLoadMatrixf
typedef void (APIENTRYP PFNGLLOADMATRIXDPROC)(const GLdouble * m);
#define glLoadMatrixd cwcglglLoadMatrixd
typedef void (APIENTRYP PFNGLMATRIXMODEPROC)(GLenum mode);
#define glMatrixMode cwcglglMatrixMode
typedef void (APIENTRYP PFNGLMULTMATRIXFPROC)(const GLfloat * m);
#define glMultMatrixf cwcglglMultMatrixf
typedef void (APIENTRYP PFNGLMULTMATRIXDPROC)(const GLdouble * m);
#define glMultMatrixd cwcglglMultMatrixd
typedef void (APIENTRYP PFNGLORTHOPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glOrtho cwcglglOrtho
typedef void (APIENTRYP PFNGLPOPMATRIXPROC)(void);
#define glPopMatrix cwcglglPopMatrix
typedef void (APIENTRYP PFNGLPUSHMATRIXPROC)(void);
#define glPushMatrix cwcglglPushMatrix
typedef void (APIENTRYP PFNGLROTATEDPROC)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
#define glRotated cwcglglRotated
typedef void (APIENTRYP PFNGLROTATEFPROC)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
#define glRotatef cwcglglRotatef
typedef void (APIENTRYP PFNGLSCALEDPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glScaled cwcglglScaled
typedef void (APIENTRYP PFNGLSCALEFPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glScalef cwcglglScalef
typedef void (APIENTRYP PFNGLTRANSLATEDPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glTranslated cwcglglTranslated
typedef void (APIENTRYP PFNGLTRANSLATEFPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glTranslatef cwcglglTranslatef
#endif

#if CWCGL_VERSION >= GL_VERSION_1_1
typedef khronos_float_t GLclampf;
typedef double GLclampd;
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_ZERO 0
#define GL_ONE 1
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_NONE 0
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408
#define GL_NO_ERROR 0
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_OUT_OF_MEMORY 0x0505
#define GL_CW 0x0900
#define GL_CCW 0x0901
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_VIEWPORT 0x0BA2
#define GL_DITHER 0x0BD0
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLEND 0x0BE2
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_DRAW_BUFFER 0x0C01
#define GL_READ_BUFFER 0x0C02
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_DOUBLEBUFFER 0x0C32
#define GL_STEREO 0x0C33
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_DONT_CARE 0x1100
#define GL_FASTEST 0x1101
#define GL_NICEST 0x1102
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_DOUBLE 0x140A
#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_CLEAR 0x1500
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
#define GL_SET 0x150F
#define GL_TEXTURE 0x1702
#define GL_COLOR 0x1800
#define GL_DEPTH 0x1801
#define GL_STENCIL 0x1802
#define GL_STENCIL_INDEX 0x1901
#define GL_DEPTH_COMPONENT 0x1902
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_REPEAT 0x2901
#define GL_R3_G3_B2 0x2A10
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB8 0x8051
#define GL_RGB10 0x8052
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGB5_A1 0x8057
#define GL_RGBA8 0x8058
#define GL_RGB10_A2 0x8059
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
#define GL_CURRENT_BIT 0x00000001
#define GL_POINT_BIT 0x00000002
#define GL_LINE_BIT 0x00000004
#define GL_POLYGON_BIT 0x00000008
#define GL_POLYGON_STIPPLE_BIT 0x00000010
#define GL_PIXEL_MODE_BIT 0x00000020
#define GL_LIGHTING_BIT 0x00000040
#define GL_FOG_BIT 0x00000080
#define GL_ACCUM_BUFFER_BIT 0x00000200
#define GL_VIEWPORT_BIT 0x00000800
#define GL_TRANSFORM_BIT 0x00001000
#define GL_ENABLE_BIT 0x00002000
#define GL_HINT_BIT 0x00008000
#define GL_EVAL_BIT 0x00010000
#define GL_LIST_BIT 0x00020000
#define GL_TEXTURE_BIT 0x00040000
#define GL_SCISSOR_BIT 0x00080000
#define GL_ALL_ATTRIB_BITS 0xFFFFFFFF
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF
#define GL_QUAD_STRIP 0x0008
#define GL_POLYGON 0x0009
#define GL_ACCUM 0x0100
#define GL_LOAD 0x0101
#define GL_RETURN 0x0102
#define GL_MULT 0x0103
#define GL_ADD 0x0104
#define GL_AUX0 0x0409
#define GL_AUX1 0x040A
#define GL_AUX2 0x040B
#define GL_AUX3 0x040C
#define GL_2D 0x0600
#define GL_3D 0x0601
#define GL_3D_COLOR 0x0602
#define GL_3D_COLOR_TEXTURE 0x0603
#define GL_4D_COLOR_TEXTURE 0x0604
#define GL_PASS_THROUGH_TOKEN 0x0700
#define GL_POINT_TOKEN 0x0701
#define GL_LINE_TOKEN 0x0702
#define GL_POLYGON_TOKEN 0x0703
#define GL_BITMAP_TOKEN 0x0704
#define GL_DRAW_PIXEL_TOKEN 0x0705
#define GL_COPY_PIXEL_TOKEN 0x0706
#define GL_LINE_RESET_TOKEN 0x0707
#define GL_EXP 0x0800
#define GL_EXP2 0x0801
#define GL_COEFF 0x0A00
#define GL_ORDER 0x0A01
#define GL_DOMAIN 0x0A02
#define GL_PIXEL_MAP_I_TO_I 0x0C70
#define GL_PIXEL_MAP_S_TO_S 0x0C71
#define GL_PIXEL_MAP_I_TO_R 0x0C72
#define GL_PIXEL_MAP_I_TO_G 0x0C73
#define GL_PIXEL_MAP_I_TO_B 0x0C74
#define GL_PIXEL_MAP_I_TO_A 0x0C75
#define GL_PIXEL_MAP_R_TO_R 0x0C76
#define GL_PIXEL_MAP_G_TO_G 0x0C77
#define GL_PIXEL_MAP_B_TO_B 0x0C78
#define GL_PIXEL_MAP_A_TO_A 0x0C79
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_COLOR_ARRAY_POINTER 0x8090
#define GL_INDEX_ARRAY_POINTER 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#define GL_SELECTION_BUFFER_POINTER 0x0DF3
#define GL_CURRENT_COLOR 0x0B00
#define GL_CURRENT_INDEX 0x0B01
#define GL_CURRENT_NORMAL 0x0B02
#define GL_CURRENT_TEXTURE_COORDS 0x0B03
#define GL_CURRENT_RASTER_COLOR 0x0B04
#define GL_CURRENT_RASTER_INDEX 0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#define GL_CURRENT_RASTER_POSITION 0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
#define GL_CURRENT_RASTER_DISTANCE 0x0B09
#define GL_POINT_SMOOTH 0x0B10
#define GL_LINE_STIPPLE 0x0B24
#define GL_LINE_STIPPLE_PATTERN 0x0B25
#define GL_LINE_STIPPLE_REPEAT 0x0B26
#define GL_LIST_MODE 0x0B30
#define GL_MAX_LIST_NESTING 0x0B31
#define GL_LIST_BASE 0x0B32
#define GL_LIST_INDEX 0x0B33
#define GL_POLYGON_STIPPLE 0x0B42
#define GL_EDGE_FLAG 0x0B43
#define GL_LIGHTING 0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_LIGHT_MODEL_AMBIENT 0x0B53
#define GL_SHADE_MODEL 0x0B54
#define GL_COLOR_MATERIAL_FACE 0x0B55
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#define GL_COLOR_MATERIAL 0x0B57
#define GL_FOG 0x0B60
#define GL_FOG_INDEX 0x0B61
#define GL_FOG_DENSITY 0x0B62
#define GL_FOG_START 0x0B63
#define GL_FOG_END 0x0B64
#define GL_FOG_MODE 0x0B65
#define GL_FOG_COLOR 0x0B66
#define GL_ACCUM_CLEAR_VALUE 0x0B80
#define GL_MATRIX_MODE 0x0BA0
#define GL_NORMALIZE 0x0BA1
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#define GL_PROJECTION_STACK_DEPTH 0x0BA4
#define GL_TEXTURE_STACK_DEPTH 0x0BA5
#define GL_MODELVIEW_MATRIX 0x0BA6
#define GL_PROJECTION_MATRIX 0x0BA7
#define GL_TEXTURE_MATRIX 0x0BA8
#define GL_ATTRIB_STACK_DEPTH 0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define GL_ALPHA_TEST 0x0BC0
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_ALPHA_TEST_REF 0x0BC2
#define GL_INDEX_LOGIC_OP 0x0BF1
#define GL_LOGIC_OP 0x0BF1
#define GL_AUX_BUFFERS 0x0C00
#define GL_INDEX_CLEAR_VALUE 0x0C20
#define GL_INDEX_WRITEMASK 0x0C21
#define GL_INDEX_MODE 0x0C30
#define GL_RGBA_MODE 0x0C31
#define GL_RENDER_MODE 0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_POINT_SMOOTH_HINT 0x0C51
#define GL_FOG_HINT 0x0C54
#define GL_TEXTURE_GEN_S 0x0C60
#define GL_TEXTURE_GEN_T 0x0C61
#define GL_TEXTURE_GEN_R 0x0C62
#define GL_TEXTURE_GEN_Q 0x0C63
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define GL_MAP_COLOR 0x0D10
#define GL_MAP_STENCIL 0x0D11
#define GL_INDEX_SHIFT 0x0D12
#define GL_INDEX_OFFSET 0x0D13
#define GL_RED_SCALE 0x0D14
#define GL_RED_BIAS 0x0D15
#define GL_ZOOM_X 0x0D16
#define GL_ZOOM_Y 0x0D17
#define GL_GREEN_SCALE 0x0D18
#define GL_GREEN_BIAS 0x0D19
#define GL_BLUE_SCALE 0x0D1A
#define GL_BLUE_BIAS 0x0D1B
#define GL_ALPHA_SCALE 0x0D1C
#define GL_ALPHA_BIAS 0x0D1D
#define GL_DEPTH_SCALE 0x0D1E
#define GL_DEPTH_BIAS 0x0D1F
#define GL_MAX_EVAL_ORDER 0x0D30
#define GL_MAX_LIGHTS 0x0D31
#define GL_MAX_CLIP_PLANES 0x0D32
#define GL_MAX_PIXEL_MAP_TABLE 0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_MAX_NAME_STACK_DEPTH 0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#define GL_INDEX_BITS 0x0D51
#define GL_RED_BITS 0x0D52
#define GL_GREEN_BITS 0x0D53
#define GL_BLUE_BITS 0x0D54
#define GL_ALPHA_BITS 0x0D55
#define GL_DEPTH_BITS 0x0D56
#define GL_STENCIL_BITS 0x0D57
#define GL_ACCUM_RED_BITS 0x0D58
#define GL_ACCUM_GREEN_BITS 0x0D59
#define GL_ACCUM_BLUE_BITS 0x0D5A
#define GL_ACCUM_ALPHA_BITS 0x0D5B
#define GL_NAME_STACK_DEPTH 0x0D70
#define GL_AUTO_NORMAL 0x0D80
#define GL_MAP1_COLOR_4 0x0D90
#define GL_MAP1_INDEX 0x0D91
#define GL_MAP1_NORMAL 0x0D92
#define GL_MAP1_TEXTURE_COORD_1 0x0D93
#define GL_MAP1_TEXTURE_COORD_2 0x0D94
#define GL_MAP1_TEXTURE_COORD_3 0x0D95
#define GL_MAP1_TEXTURE_COORD_4 0x0D96
#define GL_MAP1_VERTEX_3 0x0D97
#define GL_MAP1_VERTEX_4 0x0D98
#define GL_MAP2_COLOR_4 0x0DB0
#define GL_MAP2_INDEX 0x0DB1
#define GL_MAP2_NORMAL 0x0DB2
#define GL_MAP2_TEXTURE_COORD_1 0x0DB3
#define GL_MAP2_TEXTURE_COORD_2 0x0DB4
#define GL_MAP2_TEXTURE_COORD_3 0x0DB5
#define GL_MAP2_TEXTURE_COORD_4 0x0DB6
#define GL_MAP2_VERTEX_3 0x0DB7
#define GL_MAP2_VERTEX_4 0x0DB8
#define GL_MAP1_GRID_DOMAIN 0x0DD0
#define GL_MAP1_GRID_SEGMENTS 0x0DD1
#define GL_MAP2_GRID_DOMAIN 0x0DD2
#define GL_MAP2_GRID_SEGMENTS 0x0DD3
#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
#define GL_SELECTION_BUFFER_SIZE 0x0DF4
#define GL_VERTEX_ARRAY 0x8074
#define GL_NORMAL_ARRAY 0x8075
#define GL_COLOR_ARRAY 0x8076
#define GL_INDEX_ARRAY 0x8077
#define GL_TEXTURE_COORD_ARRAY 0x8078
#define GL_EDGE_FLAG_ARRAY 0x8079
#define GL_VERTEX_ARRAY_SIZE 0x807A
#define GL_VERTEX_ARRAY_TYPE 0x807B
#define GL_VERTEX_ARRAY_STRIDE 0x807C
#define GL_NORMAL_ARRAY_TYPE 0x807E
#define GL_NORMAL_ARRAY_STRIDE 0x807F
#define GL_COLOR_ARRAY_SIZE 0x8081
#define GL_COLOR_ARRAY_TYPE 0x8082
#define GL_COLOR_ARRAY_STRIDE 0x8083
#define GL_INDEX_ARRAY_TYPE 0x8085
#define GL_INDEX_ARRAY_STRIDE 0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
#define GL_TEXTURE_COMPONENTS 0x1003
#define GL_TEXTURE_BORDER 0x1005
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_TEXTURE_INTENSITY_SIZE 0x8061
#define GL_TEXTURE_PRIORITY 0x8066
#define GL_TEXTURE_RESIDENT 0x8067
#define GL_AMBIENT 0x1200
#define GL_DIFFUSE 0x1201
#define GL_SPECULAR 0x1202
#define GL_POSITION 0x1203
#define GL_SPOT_DIRECTION 0x1204
#define GL_SPOT_EXPONENT 0x1205
#define GL_SPOT_CUTOFF 0x1206
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_LINEAR_ATTENUATION 0x1208
#define GL_QUADRATIC_ATTENUATION 0x1209
#define GL_COMPILE 0x1300
#define GL_COMPILE_AND_EXECUTE 0x1301
#define GL_2_BYTES 0x1407
#define GL_3_BYTES 0x1408
#define GL_4_BYTES 0x1409
#define GL_EMISSION 0x1600
#define GL_SHININESS 0x1601
#define GL_AMBIENT_AND_DIFFUSE 0x1602
#define GL_COLOR_INDEXES 0x1603
#define GL_MODELVIEW 0x1700
#define GL_PROJECTION 0x1701
#define GL_COLOR_INDEX 0x1900
#define GL_LUMINANCE 0x1909
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_BITMAP 0x1A00
#define GL_RENDER 0x1C00
#define GL_FEEDBACK 0x1C01
#define GL_SELECT 0x1C02
#define GL_FLAT 0x1D00
#define GL_SMOOTH 0x1D01
#define GL_S 0x2000
#define GL_T 0x2001
#define GL_R 0x2002
#define GL_Q 0x2003
#define GL_MODULATE 0x2100
#define GL_DECAL 0x2101
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_TEXTURE_ENV 0x2300
#define GL_EYE_LINEAR 0x2400
#define GL_OBJECT_LINEAR 0x2401
#define GL_SPHERE_MAP 0x2402
#define GL_TEXTURE_GEN_MODE 0x2500
#define GL_OBJECT_PLANE 0x2501
#define GL_EYE_PLANE 0x2502
#define GL_CLAMP 0x2900
#define GL_ALPHA4 0x803B
#define GL_ALPHA8 0x803C
#define GL_ALPHA12 0x803D
#define GL_ALPHA16 0x803E
#define GL_LUMINANCE4 0x803F
#define GL_LUMINANCE8 0x8040
#define GL_LUMINANCE12 0x8041
#define GL_LUMINANCE16 0x8042
#define GL_LUMINANCE4_ALPHA4 0x8043
#define GL_LUMINANCE6_ALPHA2 0x8044
#define GL_LUMINANCE8_ALPHA8 0x8045
#define GL_LUMINANCE12_ALPHA4 0x8046
#define GL_LUMINANCE12_ALPHA12 0x8047
#define GL_LUMINANCE16_ALPHA16 0x8048
#define GL_INTENSITY 0x8049
#define GL_INTENSITY4 0x804A
#define GL_INTENSITY8 0x804B
#define GL_INTENSITY12 0x804C
#define GL_INTENSITY16 0x804D
#define GL_V2F 0x2A20
#define GL_V3F 0x2A21
#define GL_C4UB_V2F 0x2A22
#define GL_C4UB_V3F 0x2A23
#define GL_C3F_V3F 0x2A24
#define GL_N3F_V3F 0x2A25
#define GL_C4F_N3F_V3F 0x2A26
#define GL_T2F_V3F 0x2A27
#define GL_T4F_V4F 0x2A28
#define GL_T2F_C4UB_V3F 0x2A29
#define GL_T2F_C3F_V3F 0x2A2A
#define GL_T2F_N3F_V3F 0x2A2B
#define GL_T2F_C4F_N3F_V3F 0x2A2C
#define GL_T4F_C4F_N3F_V4F 0x2A2D
#define GL_CLIP_PLANE0 0x3000
#define GL_CLIP_PLANE1 0x3001
#define GL_CLIP_PLANE2 0x3002
#define GL_CLIP_PLANE3 0x3003
#define GL_CLIP_PLANE4 0x3004
#define GL_CLIP_PLANE5 0x3005
#define GL_LIGHT0 0x4000
#define GL_LIGHT1 0x4001
#define GL_LIGHT2 0x4002
#define GL_LIGHT3 0x4003
#define GL_LIGHT4 0x4004
#define GL_LIGHT5 0x4005
#define GL_LIGHT6 0x4006
#define GL_LIGHT7 0x4007
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
#define glDrawArrays cwcglglDrawArrays
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices);
#define glDrawElements cwcglglDrawElements
typedef void (APIENTRYP PFNGLGETPOINTERVPROC)(GLenum pname, void ** params);
#define glGetPointerv cwcglglGetPointerv
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
#define glPolygonOffset cwcglglPolygonOffset
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyTexImage1D cwcglglCopyTexImage1D
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyTexImage2D cwcglglCopyTexImage2D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTexSubImage1D cwcglglCopyTexSubImage1D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage2D cwcglglCopyTexSubImage2D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage1D cwcglglTexSubImage1D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage2D cwcglglTexSubImage2D
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
#define glBindTexture cwcglglBindTexture
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint * textures);
#define glDeleteTextures cwcglglDeleteTextures
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint * textures);
#define glGenTextures cwcglglGenTextures
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
#define glIsTexture cwcglglIsTexture
typedef void (APIENTRYP PFNGLARRAYELEMENTPROC)(GLint i);
#define glArrayElement cwcglglArrayElement
typedef void (APIENTRYP PFNGLCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glColorPointer cwcglglColorPointer
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEPROC)(GLenum array);
#define glDisableClientState cwcglglDisableClientState
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTERPROC)(GLsizei stride, const void * pointer);
#define glEdgeFlagPointer cwcglglEdgeFlagPointer
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEPROC)(GLenum array);
#define glEnableClientState cwcglglEnableClientState
typedef void (APIENTRYP PFNGLINDEXPOINTERPROC)(GLenum type, GLsizei stride, const void * pointer);
#define glIndexPointer cwcglglIndexPointer
typedef void (APIENTRYP PFNGLINTERLEAVEDARRAYSPROC)(GLenum format, GLsizei stride, const void * pointer);
#define glInterleavedArrays cwcglglInterleavedArrays
typedef void (APIENTRYP PFNGLNORMALPOINTERPROC)(GLenum type, GLsizei stride, const void * pointer);
#define glNormalPointer cwcglglNormalPointer
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glTexCoordPointer cwcglglTexCoordPointer
typedef void (APIENTRYP PFNGLVERTEXPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexPointer cwcglglVertexPointer
typedef GLboolean (APIENTRYP PFNGLARETEXTURESRESIDENTPROC)(GLsizei n, const GLuint * textures, GLboolean * residences);
#define glAreTexturesResident cwcglglAreTexturesResident
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESPROC)(GLsizei n, const GLuint * textures, const GLfloat * priorities);
#define glPrioritizeTextures cwcglglPrioritizeTextures
typedef void (APIENTRYP PFNGLINDEXUBPROC)(GLubyte c);
#define glIndexub cwcglglIndexub
typedef void (APIENTRYP PFNGLINDEXUBVPROC)(const GLubyte * c);
#define glIndexubv cwcglglIndexubv
typedef void (APIENTRYP PFNGLPOPCLIENTATTRIBPROC)(void);
#define glPopClientAttrib cwcglglPopClientAttrib
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield mask);
#define glPushClientAttrib cwcglglPushClientAttrib
#endif

#if CWCGL_VERSION >= GL_VERSION_1_2
#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_TEXTURE_3D 0x806F
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_BGR 0x80E0
#define GL_BGRA 0x80E1
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_RESCALE_NORMAL 0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#define GL_SINGLE_COLOR 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
#define glDrawRangeElements cwcglglDrawRangeElements
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage3D cwcglglTexImage3D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage3D cwcglglTexSubImage3D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage3D cwcglglCopyTexSubImage3D
#endif

#if CWCGL_VERSION >= GL_VERSION_1_3
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_MULTISAMPLE 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_MULTISAMPLE_BIT 0x20000000
#define GL_NORMAL_MAP 0x8511
#define GL_REFLECTION_MAP 0x8512
#define GL_COMPRESSED_ALPHA 0x84E9
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMBINE 0x8570
#define GL_COMBINE_RGB 0x8571
#define GL_COMBINE_ALPHA 0x8572
#define GL_SOURCE0_RGB 0x8580
#define GL_SOURCE1_RGB 0x8581
#define GL_SOURCE2_RGB 0x8582
#define GL_SOURCE0_ALPHA 0x8588
#define GL_SOURCE1_ALPHA 0x8589
#define GL_SOURCE2_ALPHA 0x858A
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND2_ALPHA 0x859A
#define GL_RGB_SCALE 0x8573
#define GL_ADD_SIGNED 0x8574
#define GL_INTERPOLATE 0x8575
#define GL_SUBTRACT 0x84E7
#define GL_CONSTANT 0x8576
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
#define glActiveTexture cwcglglActiveTexture
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
#define glSampleCoverage cwcglglSampleCoverage
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage3D cwcglglCompressedTexImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage2D cwcglglCompressedTexImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage1D cwcglglCompressedTexImage1D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage3D cwcglglCompressedTexSubImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage2D cwcglglCompressedTexSubImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage1D cwcglglCompressedTexSubImage1D
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint level, void * img);
#define glGetCompressedTexImage cwcglglGetCompressedTexImage
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREPROC)(GLenum texture);
#define glClientActiveTexture cwcglglClientActiveTexture
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DPROC)(GLenum target, GLdouble s);
#define glMultiTexCoord1d cwcglglMultiTexCoord1d
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord1dv cwcglglMultiTexCoord1dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FPROC)(GLenum target, GLfloat s);
#define glMultiTexCoord1f cwcglglMultiTexCoord1f
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord1fv cwcglglMultiTexCoord1fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IPROC)(GLenum target, GLint s);
#define glMultiTexCoord1i cwcglglMultiTexCoord1i
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord1iv cwcglglMultiTexCoord1iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SPROC)(GLenum target, GLshort s);
#define glMultiTexCoord1s cwcglglMultiTexCoord1s
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord1sv cwcglglMultiTexCoord1sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DPROC)(GLenum target, GLdouble s, GLdouble t);
#define glMultiTexCoord2d cwcglglMultiTexCoord2d
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord2dv cwcglglMultiTexCoord2dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FPROC)(GLenum target, GLfloat s, GLfloat t);
#define glMultiTexCoord2f cwcglglMultiTexCoord2f
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord2fv cwcglglMultiTexCoord2fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IPROC)(GLenum target, GLint s, GLint t);
#define glMultiTexCoord2i cwcglglMultiTexCoord2i
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord2iv cwcglglMultiTexCoord2iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SPROC)(GLenum target, GLshort s, GLshort t);
#define glMultiTexCoord2s cwcglglMultiTexCoord2s
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord2sv cwcglglMultiTexCoord2sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
#define glMultiTexCoord3d cwcglglMultiTexCoord3d
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord3dv cwcglglMultiTexCoord3dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
#define glMultiTexCoord3f cwcglglMultiTexCoord3f
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord3fv cwcglglMultiTexCoord3fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IPROC)(GLenum target, GLint s, GLint t, GLint r);
#define glMultiTexCoord3i cwcglglMultiTexCoord3i
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord3iv cwcglglMultiTexCoord3iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
#define glMultiTexCoord3s cwcglglMultiTexCoord3s
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord3sv cwcglglMultiTexCoord3sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#define glMultiTexCoord4d cwcglglMultiTexCoord4d
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord4dv cwcglglMultiTexCoord4dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#define glMultiTexCoord4f cwcglglMultiTexCoord4f
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord4fv cwcglglMultiTexCoord4fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
#define glMultiTexCoord4i cwcglglMultiTexCoord4i
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord4iv cwcglglMultiTexCoord4iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
#define glMultiTexCoord4s cwcglglMultiTexCoord4s
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord4sv cwcglglMultiTexCoord4sv
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat * m);
#define glLoadTransposeMatrixf cwcglglLoadTransposeMatrixf
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble * m);
#define glLoadTransposeMatrixd cwcglglLoadTransposeMatrixd
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat * m);
#define glMultTransposeMatrixf cwcglglMultTransposeMatrixf
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble * m);
#define glMultTransposeMatrixd cwcglglMultTransposeMatrixd
#endif

#if CWCGL_VERSION >= GL_VERSION_1_4
#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_MIRRORED_REPEAT 0x8370
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_TEXTURE_LOD_BIAS 0x8501
#define GL_INCR_WRAP 0x8507
#define GL_DECR_WRAP 0x8508
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_POINT_SIZE_MIN 0x8126
#define GL_POINT_SIZE_MAX 0x8127
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_GENERATE_MIPMAP 0x8191
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_FOG_COORDINATE_SOURCE 0x8450
#define GL_FOG_COORDINATE 0x8451
#define GL_FRAGMENT_DEPTH 0x8452
#define GL_CURRENT_FOG_COORDINATE 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define GL_FOG_COORDINATE_ARRAY 0x8457
#define GL_COLOR_SUM 0x8458
#define GL_CURRENT_SECONDARY_COLOR 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define GL_SECONDARY_COLOR_ARRAY 0x845E
#define GL_TEXTURE_FILTER_CONTROL 0x8500
#define GL_DEPTH_TEXTURE_MODE 0x884B
#define GL_COMPARE_R_TO_TEXTURE 0x884E
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#define glBlendFuncSeparate cwcglglBlendFuncSeparate
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
#define glMultiDrawArrays cwcglglMultiDrawArrays
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount);
#define glMultiDrawElements cwcglglMultiDrawElements
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
#define glPointParameterf cwcglglPointParameterf
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat * params);
#define glPointParameterfv cwcglglPointParameterfv
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
#define glPointParameteri cwcglglPointParameteri
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC)(GLenum pname, const GLint * params);
#define glPointParameteriv cwcglglPointParameteriv
typedef void (APIENTRYP PFNGLFOGCOORDFPROC)(GLfloat coord);
#define glFogCoordf cwcglglFogCoordf
typedef void (APIENTRYP PFNGLFOGCOORDFVPROC)(const GLfloat * coord);
#define glFogCoordfv cwcglglFogCoordfv
typedef void (APIENTRYP PFNGLFOGCOORDDPROC)(GLdouble coord);
#define glFogCoordd cwcglglFogCoordd
typedef void (APIENTRYP PFNGLFOGCOORDDVPROC)(const GLdouble * coord);
#define glFogCoorddv cwcglglFogCoorddv
typedef void (APIENTRYP PFNGLFOGCOORDPOINTERPROC)(GLenum type, GLsizei stride, const void * pointer);
#define glFogCoordPointer cwcglglFogCoordPointer
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
#define glSecondaryColor3b cwcglglSecondaryColor3b
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte * v);
#define glSecondaryColor3bv cwcglglSecondaryColor3bv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
#define glSecondaryColor3d cwcglglSecondaryColor3d
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble * v);
#define glSecondaryColor3dv cwcglglSecondaryColor3dv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
#define glSecondaryColor3f cwcglglSecondaryColor3f
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat * v);
#define glSecondaryColor3fv cwcglglSecondaryColor3fv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IPROC)(GLint red, GLint green, GLint blue);
#define glSecondaryColor3i cwcglglSecondaryColor3i
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IVPROC)(const GLint * v);
#define glSecondaryColor3iv cwcglglSecondaryColor3iv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
#define glSecondaryColor3s cwcglglSecondaryColor3s
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVPROC)(const GLshort * v);
#define glSecondaryColor3sv cwcglglSecondaryColor3sv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
#define glSecondaryColor3ub cwcglglSecondaryColor3ub
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte * v);
#define glSecondaryColor3ubv cwcglglSecondaryColor3ubv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
#define glSecondaryColor3ui cwcglglSecondaryColor3ui
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint * v);
#define glSecondaryColor3uiv cwcglglSecondaryColor3uiv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
#define glSecondaryColor3us cwcglglSecondaryColor3us
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USVPROC)(const GLushort * v);
#define glSecondaryColor3usv cwcglglSecondaryColor3usv
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glSecondaryColorPointer cwcglglSecondaryColorPointer
typedef void (APIENTRYP PFNGLWINDOWPOS2DPROC)(GLdouble x, GLdouble y);
#define glWindowPos2d cwcglglWindowPos2d
typedef void (APIENTRYP PFNGLWINDOWPOS2DVPROC)(const GLdouble * v);
#define glWindowPos2dv cwcglglWindowPos2dv
typedef void (APIENTRYP PFNGLWINDOWPOS2FPROC)(GLfloat x, GLfloat y);
#define glWindowPos2f cwcglglWindowPos2f
typedef void (APIENTRYP PFNGLWINDOWPOS2FVPROC)(const GLfloat * v);
#define glWindowPos2fv cwcglglWindowPos2fv
typedef void (APIENTRYP PFNGLWINDOWPOS2IPROC)(GLint x, GLint y);
#define glWindowPos2i cwcglglWindowPos2i
typedef void (APIENTRYP PFNGLWINDOWPOS2IVPROC)(const GLint * v);
#define glWindowPos2iv cwcglglWindowPos2iv
typedef void (APIENTRYP PFNGLWINDOWPOS2SPROC)(GLshort x, GLshort y);
#define glWindowPos2s cwcglglWindowPos2s
typedef void (APIENTRYP PFNGLWINDOWPOS2SVPROC)(const GLshort * v);
#define glWindowPos2sv cwcglglWindowPos2sv
typedef void (APIENTRYP PFNGLWINDOWPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glWindowPos3d cwcglglWindowPos3d
typedef void (APIENTRYP PFNGLWINDOWPOS3DVPROC)(const GLdouble * v);
#define glWindowPos3dv cwcglglWindowPos3dv
typedef void (APIENTRYP PFNGLWINDOWPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glWindowPos3f cwcglglWindowPos3f
typedef void (APIENTRYP PFNGLWINDOWPOS3FVPROC)(const GLfloat * v);
#define glWindowPos3fv cwcglglWindowPos3fv
typedef void (APIENTRYP PFNGLWINDOWPOS3IPROC)(GLint x, GLint y, GLint z);
#define glWindowPos3i cwcglglWindowPos3i
typedef void (APIENTRYP PFNGLWINDOWPOS3IVPROC)(const GLint * v);
#define glWindowPos3iv cwcglglWindowPos3iv
typedef void (APIENTRYP PFNGLWINDOWPOS3SPROC)(GLshort x, GLshort y, GLshort z);
#define glWindowPos3s cwcglglWindowPos3s
typedef void (APIENTRYP PFNGLWINDOWPOS3SVPROC)(const GLshort * v);
#define glWindowPos3sv cwcglglWindowPos3sv
#define GL_FUNC_ADD 0x8006
#define GL_FUNC_SUBTRACT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_MIN 0x8007
#define GL_MAX 0x8008
#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glBlendColor cwcglglBlendColor
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
#define glBlendEquation cwcglglBlendEquation
#endif

#if CWCGL_VERSION >= GL_VERSION_1_5
typedef khronos_ssize_t GLsizeiptr;
typedef khronos_intptr_t GLintptr;
#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_CURRENT_QUERY 0x8865
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY 0x88B8
#define GL_WRITE_ONLY 0x88B9
#define GL_READ_WRITE 0x88BA
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA
#define GL_SAMPLES_PASSED 0x8914
#define GL_SRC1_ALPHA 0x8589
#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
#define GL_FOG_COORD_SRC 0x8450
#define GL_FOG_COORD 0x8451
#define GL_CURRENT_FOG_COORD 0x8453
#define GL_FOG_COORD_ARRAY_TYPE 0x8454
#define GL_FOG_COORD_ARRAY_STRIDE 0x8455
#define GL_FOG_COORD_ARRAY_POINTER 0x8456
#define GL_FOG_COORD_ARRAY 0x8457
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
#define GL_SRC0_RGB 0x8580
#define GL_SRC1_RGB 0x8581
#define GL_SRC2_RGB 0x8582
#define GL_SRC0_ALPHA 0x8588
#define GL_SRC2_ALPHA 0x858A
typedef void (APIENTRYP PFNGLGENQUERIESPROC)(GLsizei n, GLuint * ids);
#define glGenQueries cwcglglGenQueries
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint * ids);
#define glDeleteQueries cwcglglDeleteQueries
typedef GLboolean (APIENTRYP PFNGLISQUERYPROC)(GLuint id);
#define glIsQuery cwcglglIsQuery
typedef void (APIENTRYP PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
#define glBeginQuery cwcglglBeginQuery
typedef void (APIENTRYP PFNGLENDQUERYPROC)(GLenum target);
#define glEndQuery cwcglglEndQuery
typedef void (APIENTRYP PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetQueryiv cwcglglGetQueryiv
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC)(GLuint id, GLenum pname, GLint * params);
#define glGetQueryObjectiv cwcglglGetQueryObjectiv
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint * params);
#define glGetQueryObjectuiv cwcglglGetQueryObjectuiv
typedef void (APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
#define glBindBuffer cwcglglBindBuffer
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint * buffers);
#define glDeleteBuffers cwcglglDeleteBuffers
typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint * buffers);
#define glGenBuffers cwcglglGenBuffers
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
#define glIsBuffer cwcglglIsBuffer
typedef void (APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
#define glBufferData cwcglglBufferData
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
#define glBufferSubData cwcglglBufferSubData
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, void * data);
#define glGetBufferSubData cwcglglGetBufferSubData
typedef void * (APIENTRYP PFNGLMAPBUFFERPROC)(GLenum target, GLenum access);
#define glMapBuffer cwcglglMapBuffer
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum target);
#define glUnmapBuffer cwcglglUnmapBuffer
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetBufferParameteriv cwcglglGetBufferParameteriv
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void ** params);
#define glGetBufferPointerv cwcglglGetBufferPointerv
#endif

#if CWCGL_VERSION >= GL_VERSION_2_0
typedef char GLchar;
#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_POINT_SPRITE 0x8861
#define GL_COORD_REPLACE 0x8862
#define GL_MAX_TEXTURE_COORDS 0x8871
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparate cwcglglBlendEquationSeparate
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum * bufs);
#define glDrawBuffers cwcglglDrawBuffers
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
#define glStencilOpSeparate cwcglglStencilOpSeparate
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
#define glStencilFuncSeparate cwcglglStencilFuncSeparate
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
#define glStencilMaskSeparate cwcglglStencilMaskSeparate
typedef void (APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
#define glAttachShader cwcglglAttachShader
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar * name);
#define glBindAttribLocation cwcglglBindAttribLocation
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
#define glCompileShader cwcglglCompileShader
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC)(void);
#define glCreateProgram cwcglglCreateProgram
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
#define glCreateShader cwcglglCreateShader
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
#define glDeleteProgram cwcglglDeleteProgram
typedef void (APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
#define glDeleteShader cwcglglDeleteShader
typedef void (APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
#define glDetachShader cwcglglDetachShader
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
#define glDisableVertexAttribArray cwcglglDisableVertexAttribArray
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
#define glEnableVertexAttribArray cwcglglEnableVertexAttribArray
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
#define glGetActiveAttrib cwcglglGetActiveAttrib
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
#define glGetActiveUniform cwcglglGetActiveUniform
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
#define glGetAttachedShaders cwcglglGetAttachedShaders
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar * name);
#define glGetAttribLocation cwcglglGetAttribLocation
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint * params);
#define glGetProgramiv cwcglglGetProgramiv
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetProgramInfoLog cwcglglGetProgramInfoLog
typedef void (APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint * params);
#define glGetShaderiv cwcglglGetShaderiv
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetShaderInfoLog cwcglglGetShaderInfoLog
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
#define glGetShaderSource cwcglglGetShaderSource
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar * name);
#define glGetUniformLocation cwcglglGetUniformLocation
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat * params);
#define glGetUniformfv cwcglglGetUniformfv
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint * params);
#define glGetUniformiv cwcglglGetUniformiv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribdv cwcglglGetVertexAttribdv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat * params);
#define glGetVertexAttribfv cwcglglGetVertexAttribfv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint * params);
#define glGetVertexAttribiv cwcglglGetVertexAttribiv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void ** pointer);
#define glGetVertexAttribPointerv cwcglglGetVertexAttribPointerv
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
#define glIsProgram cwcglglIsProgram
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC)(GLuint shader);
#define glIsShader cwcglglIsShader
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
#define glLinkProgram cwcglglLinkProgram
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length);
#define glShaderSource cwcglglShaderSource
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
#define glUseProgram cwcglglUseProgram
typedef void (APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
#define glUniform1f cwcglglUniform1f
typedef void (APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
#define glUniform2f cwcglglUniform2f
typedef void (APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glUniform3f cwcglglUniform3f
typedef void (APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glUniform4f cwcglglUniform4f
typedef void (APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
#define glUniform1i cwcglglUniform1i
typedef void (APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
#define glUniform2i cwcglglUniform2i
typedef void (APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
#define glUniform3i cwcglglUniform3i
typedef void (APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glUniform4i cwcglglUniform4i
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform1fv cwcglglUniform1fv
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform2fv cwcglglUniform2fv
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform3fv cwcglglUniform3fv
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform4fv cwcglglUniform4fv
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform1iv cwcglglUniform1iv
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform2iv cwcglglUniform2iv
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform3iv cwcglglUniform3iv
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform4iv cwcglglUniform4iv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix2fv cwcglglUniformMatrix2fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3fv cwcglglUniformMatrix3fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4fv cwcglglUniformMatrix4fv
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
#define glValidateProgram cwcglglValidateProgram
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC)(GLuint index, GLdouble x);
#define glVertexAttrib1d cwcglglVertexAttrib1d
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib1dv cwcglglVertexAttrib1dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
#define glVertexAttrib1f cwcglglVertexAttrib1f
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib1fv cwcglglVertexAttrib1fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC)(GLuint index, GLshort x);
#define glVertexAttrib1s cwcglglVertexAttrib1s
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib1sv cwcglglVertexAttrib1sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttrib2d cwcglglVertexAttrib2d
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib2dv cwcglglVertexAttrib2dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
#define glVertexAttrib2f cwcglglVertexAttrib2f
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib2fv cwcglglVertexAttrib2fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC)(GLuint index, GLshort x, GLshort y);
#define glVertexAttrib2s cwcglglVertexAttrib2s
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib2sv cwcglglVertexAttrib2sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttrib3d cwcglglVertexAttrib3d
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib3dv cwcglglVertexAttrib3dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
#define glVertexAttrib3f cwcglglVertexAttrib3f
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib3fv cwcglglVertexAttrib3fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
#define glVertexAttrib3s cwcglglVertexAttrib3s
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib3sv cwcglglVertexAttrib3sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC)(GLuint index, const GLbyte * v);
#define glVertexAttrib4Nbv cwcglglVertexAttrib4Nbv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC)(GLuint index, const GLint * v);
#define glVertexAttrib4Niv cwcglglVertexAttrib4Niv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib4Nsv cwcglglVertexAttrib4Nsv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
#define glVertexAttrib4Nub cwcglglVertexAttrib4Nub
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC)(GLuint index, const GLubyte * v);
#define glVertexAttrib4Nubv cwcglglVertexAttrib4Nubv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttrib4Nuiv cwcglglVertexAttrib4Nuiv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC)(GLuint index, const GLushort * v);
#define glVertexAttrib4Nusv cwcglglVertexAttrib4Nusv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC)(GLuint index, const GLbyte * v);
#define glVertexAttrib4bv cwcglglVertexAttrib4bv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttrib4d cwcglglVertexAttrib4d
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib4dv cwcglglVertexAttrib4dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertexAttrib4f cwcglglVertexAttrib4f
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib4fv cwcglglVertexAttrib4fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC)(GLuint index, const GLint * v);
#define glVertexAttrib4iv cwcglglVertexAttrib4iv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertexAttrib4s cwcglglVertexAttrib4s
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib4sv cwcglglVertexAttrib4sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC)(GLuint index, const GLubyte * v);
#define glVertexAttrib4ubv cwcglglVertexAttrib4ubv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttrib4uiv cwcglglVertexAttrib4uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC)(GLuint index, const GLushort * v);
#define glVertexAttrib4usv cwcglglVertexAttrib4usv
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
#define glVertexAttribPointer cwcglglVertexAttribPointer
#endif

#if CWCGL_VERSION >= GL_VERSION_2_1
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_SRGB 0x8C40
#define GL_SRGB8 0x8C41
#define GL_SRGB_ALPHA 0x8C42
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_COMPRESSED_SRGB 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_SLUMINANCE_ALPHA 0x8C44
#define GL_SLUMINANCE8_ALPHA8 0x8C45
#define GL_SLUMINANCE 0x8C46
#define GL_SLUMINANCE8 0x8C47
#define GL_COMPRESSED_SLUMINANCE 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix2x3fv cwcglglUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3x2fv cwcglglUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix2x4fv cwcglglUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4x2fv cwcglglUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3x4fv cwcglglUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4x3fv cwcglglUniformMatrix4x3fv
#endif

#if CWCGL_VERSION >= GL_VERSION_3_0
#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_CLIP_DISTANCE0 0x3000
#define GL_CLIP_DISTANCE1 0x3001
#define GL_CLIP_DISTANCE2 0x3002
#define GL_CLIP_DISTANCE3 0x3003
#define GL_CLIP_DISTANCE4 0x3004
#define GL_CLIP_DISTANCE5 0x3005
#define GL_CLIP_DISTANCE6 0x3006
#define GL_CLIP_DISTANCE7 0x3007
#define GL_MAX_CLIP_DISTANCES 0x0D32
#define GL_MAJOR_VERSION 0x821B
#define GL_MINOR_VERSION 0x821C
#define GL_NUM_EXTENSIONS 0x821D
#define GL_CONTEXT_FLAGS 0x821E
#define GL_COMPRESSED_RED 0x8225
#define GL_COMPRESSED_RG 0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_RGBA32F 0x8814
#define GL_RGB32F 0x8815
#define GL_RGBA16F 0x881A
#define GL_RGB16F 0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_FIXED_ONLY 0x891D
#define GL_MAX_VARYING_COMPONENTS 0x8B4B
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_RGB9_E5 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI 0x8D70
#define GL_RGB32UI 0x8D71
#define GL_RGBA16UI 0x8D76
#define GL_RGB16UI 0x8D77
#define GL_RGBA8UI 0x8D7C
#define GL_RGB8UI 0x8D7D
#define GL_RGBA32I 0x8D82
#define GL_RGB32I 0x8D83
#define GL_RGBA16I 0x8D88
#define GL_RGB16I 0x8D89
#define GL_RGBA8I 0x8D8E
#define GL_RGB8I 0x8D8F
#define GL_RED_INTEGER 0x8D94
#define GL_GREEN_INTEGER 0x8D95
#define GL_BLUE_INTEGER 0x8D96
#define GL_RGB_INTEGER 0x8D98
#define GL_RGBA_INTEGER 0x8D99
#define GL_BGR_INTEGER 0x8D9A
#define GL_BGRA_INTEGER 0x8D9B
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_QUERY_WAIT 0x8E13
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121
typedef void (APIENTRYP PFNGLCOLORMASKIPROC)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
#define glColorMaski cwcglglColorMaski
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum target, GLuint index, GLboolean * data);
#define glGetBooleani_v cwcglglGetBooleani_v
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint * data);
#define glGetIntegeri_v cwcglglGetIntegeri_v
typedef void (APIENTRYP PFNGLENABLEIPROC)(GLenum target, GLuint index);
#define glEnablei cwcglglEnablei
typedef void (APIENTRYP PFNGLDISABLEIPROC)(GLenum target, GLuint index);
#define glDisablei cwcglglDisablei
typedef GLboolean (APIENTRYP PFNGLISENABLEDIPROC)(GLenum target, GLuint index);
#define glIsEnabledi cwcglglIsEnabledi
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
#define glBeginTransformFeedback cwcglglBeginTransformFeedback
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)(void);
#define glEndTransformFeedback cwcglglEndTransformFeedback
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glBindBufferRange cwcglglBindBufferRange
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
#define glBindBufferBase cwcglglBindBufferBase
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);
#define glTransformFeedbackVaryings cwcglglTransformFeedbackVaryings
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
#define glGetTransformFeedbackVarying cwcglglGetTransformFeedbackVarying
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC)(GLenum target, GLenum clamp);
#define glClampColor cwcglglClampColor
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC)(GLuint id, GLenum mode);
#define glBeginConditionalRender cwcglglBeginConditionalRender
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC)(void);
#define glEndConditionalRender cwcglglEndConditionalRender
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribIPointer cwcglglVertexAttribIPointer
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint * params);
#define glGetVertexAttribIiv cwcglglGetVertexAttribIiv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint * params);
#define glGetVertexAttribIuiv cwcglglGetVertexAttribIuiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC)(GLuint index, GLint x);
#define glVertexAttribI1i cwcglglVertexAttribI1i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC)(GLuint index, GLint x, GLint y);
#define glVertexAttribI2i cwcglglVertexAttribI2i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC)(GLuint index, GLint x, GLint y, GLint z);
#define glVertexAttribI3i cwcglglVertexAttribI3i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
#define glVertexAttribI4i cwcglglVertexAttribI4i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC)(GLuint index, GLuint x);
#define glVertexAttribI1ui cwcglglVertexAttribI1ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC)(GLuint index, GLuint x, GLuint y);
#define glVertexAttribI2ui cwcglglVertexAttribI2ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
#define glVertexAttribI3ui cwcglglVertexAttribI3ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
#define glVertexAttribI4ui cwcglglVertexAttribI4ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI1iv cwcglglVertexAttribI1iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI2iv cwcglglVertexAttribI2iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI3iv cwcglglVertexAttribI3iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI4iv cwcglglVertexAttribI4iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI1uiv cwcglglVertexAttribI1uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI2uiv cwcglglVertexAttribI2uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI3uiv cwcglglVertexAttribI3uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI4uiv cwcglglVertexAttribI4uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC)(GLuint index, const GLbyte * v);
#define glVertexAttribI4bv cwcglglVertexAttribI4bv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttribI4sv cwcglglVertexAttribI4sv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC)(GLuint index, const GLubyte * v);
#define glVertexAttribI4ubv cwcglglVertexAttribI4ubv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC)(GLuint index, const GLushort * v);
#define glVertexAttribI4usv cwcglglVertexAttribI4usv
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint * params);
#define glGetUniformuiv cwcglglGetUniformuiv
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program, GLuint color, const GLchar * name);
#define glBindFragDataLocation cwcglglBindFragDataLocation
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar * name);
#define glGetFragDataLocation cwcglglGetFragDataLocation
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
#define glUniform1ui cwcglglUniform1ui
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
#define glUniform2ui cwcglglUniform2ui
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glUniform3ui cwcglglUniform3ui
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glUniform4ui cwcglglUniform4ui
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform1uiv cwcglglUniform1uiv
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform2uiv cwcglglUniform2uiv
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform3uiv cwcglglUniform3uiv
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform4uiv cwcglglUniform4uiv
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, const GLint * params);
#define glTexParameterIiv cwcglglTexParameterIiv
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, const GLuint * params);
#define glTexParameterIuiv cwcglglTexParameterIuiv
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetTexParameterIiv cwcglglGetTexParameterIiv
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, GLuint * params);
#define glGetTexParameterIuiv cwcglglGetTexParameterIuiv
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint * value);
#define glClearBufferiv cwcglglClearBufferiv
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint * value);
#define glClearBufferuiv cwcglglClearBufferuiv
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat * value);
#define glClearBufferfv cwcglglClearBufferfv
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
#define glClearBufferfi cwcglglClearBufferfi
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
#define glGetStringi cwcglglGetStringi
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_DEPTH_STENCIL 0x84F9
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_COLOR_ATTACHMENT16 0x8CF0
#define GL_COLOR_ATTACHMENT17 0x8CF1
#define GL_COLOR_ATTACHMENT18 0x8CF2
#define GL_COLOR_ATTACHMENT19 0x8CF3
#define GL_COLOR_ATTACHMENT20 0x8CF4
#define GL_COLOR_ATTACHMENT21 0x8CF5
#define GL_COLOR_ATTACHMENT22 0x8CF6
#define GL_COLOR_ATTACHMENT23 0x8CF7
#define GL_COLOR_ATTACHMENT24 0x8CF8
#define GL_COLOR_ATTACHMENT25 0x8CF9
#define GL_COLOR_ATTACHMENT26 0x8CFA
#define GL_COLOR_ATTACHMENT27 0x8CFB
#define GL_COLOR_ATTACHMENT28 0x8CFC
#define GL_COLOR_ATTACHMENT29 0x8CFD
#define GL_COLOR_ATTACHMENT30 0x8CFE
#define GL_COLOR_ATTACHMENT31 0x8CFF
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_FRAMEBUFFER 0x8D40
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_STENCIL_INDEX16 0x8D49
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES 0x8D57
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
#define glIsRenderbuffer cwcglglIsRenderbuffer
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
#define glBindRenderbuffer cwcglglBindRenderbuffer
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint * renderbuffers);
#define glDeleteRenderbuffers cwcglglDeleteRenderbuffers
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint * renderbuffers);
#define glGenRenderbuffers cwcglglGenRenderbuffers
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorage cwcglglRenderbufferStorage
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetRenderbufferParameteriv cwcglglGetRenderbufferParameteriv
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
#define glIsFramebuffer cwcglglIsFramebuffer
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
#define glBindFramebuffer cwcglglBindFramebuffer
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint * framebuffers);
#define glDeleteFramebuffers cwcglglDeleteFramebuffers
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint * framebuffers);
#define glGenFramebuffers cwcglglGenFramebuffers
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
#define glCheckFramebufferStatus cwcglglCheckFramebufferStatus
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture1D cwcglglFramebufferTexture1D
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture2D cwcglglFramebufferTexture2D
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
#define glFramebufferTexture3D cwcglglFramebufferTexture3D
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glFramebufferRenderbuffer cwcglglFramebufferRenderbuffer
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
#define glGetFramebufferAttachmentParameteriv cwcglglGetFramebufferAttachmentParameteriv
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
#define glGenerateMipmap cwcglglGenerateMipmap
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitFramebuffer cwcglglBlitFramebuffer
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisample cwcglglRenderbufferStorageMultisample
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glFramebufferTextureLayer cwcglglFramebufferTextureLayer
#define GL_INDEX 0x8222
#define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE 0x8C15
#define GL_FRAMEBUFFER_SRGB 0x8DB9
typedef unsigned short GLhalf;
#define GL_HALF_FLOAT 0x140B
#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
typedef void * (APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapBufferRange cwcglglMapBufferRange
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
#define glFlushMappedBufferRange cwcglglFlushMappedBufferRange
#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE
#define GL_RG 0x8227
#define GL_RG_INTEGER 0x8228
#define GL_R8 0x8229
#define GL_R16 0x822A
#define GL_RG8 0x822B
#define GL_RG16 0x822C
#define GL_R16F 0x822D
#define GL_R32F 0x822E
#define GL_RG16F 0x822F
#define GL_RG32F 0x8230
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C
#define GL_VERTEX_ARRAY_BINDING 0x85B5
#define GL_CLAMP_VERTEX_COLOR 0x891A
#define GL_CLAMP_FRAGMENT_COLOR 0x891B
#define GL_ALPHA_INTEGER 0x8D97
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
#define glBindVertexArray cwcglglBindVertexArray
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint * arrays);
#define glDeleteVertexArrays cwcglglDeleteVertexArrays
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint * arrays);
#define glGenVertexArrays cwcglglGenVertexArrays
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
#define glIsVertexArray cwcglglIsVertexArray
#endif

#if CWCGL_VERSION >= GL_VERSION_3_1
#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_R8_SNORM 0x8F94
#define GL_RG8_SNORM 0x8F95
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA8_SNORM 0x8F97
#define GL_R16_SNORM 0x8F98
#define GL_RG16_SNORM 0x8F99
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGBA16_SNORM 0x8F9B
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
#define glDrawArraysInstanced cwcglglDrawArraysInstanced
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount);
#define glDrawElementsInstanced cwcglglDrawElementsInstanced
typedef void (APIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
#define glTexBuffer cwcglglTexBuffer
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
#define glPrimitiveRestartIndex cwcglglPrimitiveRestartIndex
#define GL_COPY_READ_BUFFER 0x8F36
#define GL_COPY_WRITE_BUFFER 0x8F37
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyBufferSubData cwcglglCopyBufferSubData
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_UNIFORM_TYPE 0x8A37
#define GL_UNIFORM_SIZE 0x8A38
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX 0xFFFFFFFF
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices);
#define glGetUniformIndices cwcglglGetUniformIndices
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
#define glGetActiveUniformsiv cwcglglGetActiveUniformsiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
#define glGetActiveUniformName cwcglglGetActiveUniformName
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar * uniformBlockName);
#define glGetUniformBlockIndex cwcglglGetUniformBlockIndex
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
#define glGetActiveUniformBlockiv cwcglglGetActiveUniformBlockiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
#define glGetActiveUniformBlockName cwcglglGetActiveUniformBlockName
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#define glUniformBlockBinding cwcglglUniformBlockBinding
#endif

#if CWCGL_VERSION >= GL_VERSION_3_2
typedef struct __GLsync *GLsync;
typedef khronos_uint64_t GLuint64;
typedef khronos_int64_t GLint64;
#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY 0x000A
#define GL_LINE_STRIP_ADJACENCY 0x000B
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
#define GL_PROGRAM_POINT_SIZE 0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT 0x8916
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_CONTEXT_PROFILE_MASK 0x9126
#define GL_DEPTH_CLAMP 0x864F
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
#define glDrawElementsBaseVertex cwcglglDrawElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
#define glDrawRangeElementsBaseVertex cwcglglDrawRangeElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
#define glDrawElementsInstancedBaseVertex cwcglglDrawElementsInstancedBaseVertex
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex);
#define glMultiDrawElementsBaseVertex cwcglglMultiDrawElementsBaseVertex
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
#define glProvokingVertex cwcglglProvokingVertex
#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_OBJECT_TYPE 0x9112
#define GL_SYNC_CONDITION 0x9113
#define GL_SYNC_STATUS 0x9114
#define GL_SYNC_FLAGS 0x9115
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_UNSIGNALED 0x9118
#define GL_SIGNALED 0x9119
#define GL_ALREADY_SIGNALED 0x911A
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_CONDITION_SATISFIED 0x911C
#define GL_WAIT_FAILED 0x911D
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
typedef GLsync (APIENTRYP PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
#define glFenceSync cwcglglFenceSync
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
#define glIsSync cwcglglIsSync
typedef void (APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
#define glDeleteSync cwcglglDeleteSync
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glClientWaitSync cwcglglClientWaitSync
typedef void (APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glWaitSync cwcglglWaitSync
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64 * data);
#define glGetInteger64v cwcglglGetInteger64v
typedef void (APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values);
#define glGetSynciv cwcglglGetSynciv
#define GL_SAMPLE_POSITION 0x8E50
#define GL_SAMPLE_MASK 0x8E51
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_MAX_INTEGER_SAMPLES 0x9110
typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64 * data);
#define glGetInteger64i_v cwcglglGetInteger64i_v
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64 * params);
#define glGetBufferParameteri64v cwcglglGetBufferParameteri64v
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
#define glFramebufferTexture cwcglglFramebufferTexture
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexImage2DMultisample cwcglglTexImage2DMultisample
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexImage3DMultisample cwcglglTexImage3DMultisample
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat * val);
#define glGetMultisamplefv cwcglglGetMultisamplefv
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
#define glSampleMaski cwcglglSampleMaski
#endif

#if CWCGL_VERSION >= GL_VERSION_3_3
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#define GL_SRC1_COLOR 0x88F9
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name);
#define glBindFragDataLocationIndexed cwcglglBindFragDataLocationIndexed
typedef GLint (APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar * name);
#define glGetFragDataIndex cwcglglGetFragDataIndex
#define GL_ANY_SAMPLES_PASSED 0x8C2F
#define GL_SAMPLER_BINDING 0x8919
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint * samplers);
#define glGenSamplers cwcglglGenSamplers
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint * samplers);
#define glDeleteSamplers cwcglglDeleteSamplers
typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
#define glIsSampler cwcglglIsSampler
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
#define glBindSampler cwcglglBindSampler
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
#define glSamplerParameteri cwcglglSamplerParameteri
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameteriv cwcglglSamplerParameteriv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
#define glSamplerParameterf cwcglglSamplerParameterf
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat * param);
#define glSamplerParameterfv cwcglglSamplerParameterfv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameterIiv cwcglglSamplerParameterIiv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint * param);
#define glSamplerParameterIuiv cwcglglSamplerParameterIuiv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameteriv cwcglglGetSamplerParameteriv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameterIiv cwcglglGetSamplerParameterIiv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat * params);
#define glGetSamplerParameterfv cwcglglGetSamplerParameterfv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint * params);
#define glGetSamplerParameterIuiv cwcglglGetSamplerParameterIuiv
#define GL_RGB10_A2UI 0x906F
#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46
#define GL_TIME_ELAPSED 0x88BF
#define GL_TIMESTAMP 0x8E28
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
#define glQueryCounter cwcglglQueryCounter
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64 * params);
#define glGetQueryObjecti64v cwcglglGetQueryObjecti64v
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64 * params);
#define glGetQueryObjectui64v cwcglglGetQueryObjectui64v
#define GL_INT_2_10_10_10_REV 0x8D9F
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
#define glVertexAttribDivisor cwcglglVertexAttribDivisor
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP1ui cwcglglVertexAttribP1ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP1uiv cwcglglVertexAttribP1uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP2ui cwcglglVertexAttribP2ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP2uiv cwcglglVertexAttribP2uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP3ui cwcglglVertexAttribP3ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP3uiv cwcglglVertexAttribP3uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP4ui cwcglglVertexAttribP4ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP4uiv cwcglglVertexAttribP4uiv
typedef void (APIENTRYP PFNGLVERTEXP2UIPROC)(GLenum type, GLuint value);
#define glVertexP2ui cwcglglVertexP2ui
typedef void (APIENTRYP PFNGLVERTEXP2UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP2uiv cwcglglVertexP2uiv
typedef void (APIENTRYP PFNGLVERTEXP3UIPROC)(GLenum type, GLuint value);
#define glVertexP3ui cwcglglVertexP3ui
typedef void (APIENTRYP PFNGLVERTEXP3UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP3uiv cwcglglVertexP3uiv
typedef void (APIENTRYP PFNGLVERTEXP4UIPROC)(GLenum type, GLuint value);
#define glVertexP4ui cwcglglVertexP4ui
typedef void (APIENTRYP PFNGLVERTEXP4UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP4uiv cwcglglVertexP4uiv
typedef void (APIENTRYP PFNGLTEXCOORDP1UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP1ui cwcglglTexCoordP1ui
typedef void (APIENTRYP PFNGLTEXCOORDP1UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP1uiv cwcglglTexCoordP1uiv
typedef void (APIENTRYP PFNGLTEXCOORDP2UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP2ui cwcglglTexCoordP2ui
typedef void (APIENTRYP PFNGLTEXCOORDP2UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP2uiv cwcglglTexCoordP2uiv
typedef void (APIENTRYP PFNGLTEXCOORDP3UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP3ui cwcglglTexCoordP3ui
typedef void (APIENTRYP PFNGLTEXCOORDP3UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP3uiv cwcglglTexCoordP3uiv
typedef void (APIENTRYP PFNGLTEXCOORDP4UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP4ui cwcglglTexCoordP4ui
typedef void (APIENTRYP PFNGLTEXCOORDP4UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP4uiv cwcglglTexCoordP4uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP1ui cwcglglMultiTexCoordP1ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP1uiv cwcglglMultiTexCoordP1uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP2ui cwcglglMultiTexCoordP2ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP2uiv cwcglglMultiTexCoordP2uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP3ui cwcglglMultiTexCoordP3ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP3uiv cwcglglMultiTexCoordP3uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP4ui cwcglglMultiTexCoordP4ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP4uiv cwcglglMultiTexCoordP4uiv
typedef void (APIENTRYP PFNGLNORMALP3UIPROC)(GLenum type, GLuint coords);
#define glNormalP3ui cwcglglNormalP3ui
typedef void (APIENTRYP PFNGLNORMALP3UIVPROC)(GLenum type, const GLuint * coords);
#define glNormalP3uiv cwcglglNormalP3uiv
typedef void (APIENTRYP PFNGLCOLORP3UIPROC)(GLenum type, GLuint color);
#define glColorP3ui cwcglglColorP3ui
typedef void (APIENTRYP PFNGLCOLORP3UIVPROC)(GLenum type, const GLuint * color);
#define glColorP3uiv cwcglglColorP3uiv
typedef void (APIENTRYP PFNGLCOLORP4UIPROC)(GLenum type, GLuint color);
#define glColorP4ui cwcglglColorP4ui
typedef void (APIENTRYP PFNGLCOLORP4UIVPROC)(GLenum type, const GLuint * color);
#define glColorP4uiv cwcglglColorP4uiv
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIPROC)(GLenum type, GLuint color);
#define glSecondaryColorP3ui cwcglglSecondaryColorP3ui
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC)(GLenum type, const GLuint * color);
#define glSecondaryColorP3uiv cwcglglSecondaryColorP3uiv
#endif

#if CWCGL_VERSION >= GL_VERSION_4_0
#define GL_SAMPLE_SHADING 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC)(GLfloat value);
#define glMinSampleShading cwcglglMinSampleShading
typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC)(GLuint buf, GLenum mode);
#define glBlendEquationi cwcglglBlendEquationi
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparatei cwcglglBlendEquationSeparatei
typedef void (APIENTRYP PFNGLBLENDFUNCIPROC)(GLuint buf, GLenum src, GLenum dst);
#define glBlendFunci cwcglglBlendFunci
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#define glBlendFuncSeparatei cwcglglBlendFuncSeparatei
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const void * indirect);
#define glDrawArraysIndirect cwcglglDrawArraysIndirect
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void * indirect);
#define glDrawElementsIndirect cwcglglDrawElementsIndirect
#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS 0x8E71
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_DOUBLE_VEC4 0x8FFE
#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT3 0x8F47
#define GL_DOUBLE_MAT4 0x8F48
#define GL_DOUBLE_MAT2x3 0x8F49
#define GL_DOUBLE_MAT2x4 0x8F4A
#define GL_DOUBLE_MAT3x2 0x8F4B
#define GL_DOUBLE_MAT3x4 0x8F4C
#define GL_DOUBLE_MAT4x2 0x8F4D
#define GL_DOUBLE_MAT4x3 0x8F4E
typedef void (APIENTRYP PFNGLUNIFORM1DPROC)(GLint location, GLdouble x);
#define glUniform1d cwcglglUniform1d
typedef void (APIENTRYP PFNGLUNIFORM2DPROC)(GLint location, GLdouble x, GLdouble y);
#define glUniform2d cwcglglUniform2d
typedef void (APIENTRYP PFNGLUNIFORM3DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z);
#define glUniform3d cwcglglUniform3d
typedef void (APIENTRYP PFNGLUNIFORM4DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glUniform4d cwcglglUniform4d
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform1dv cwcglglUniform1dv
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform2dv cwcglglUniform2dv
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform3dv cwcglglUniform3dv
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform4dv cwcglglUniform4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2dv cwcglglUniformMatrix2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3dv cwcglglUniformMatrix3dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4dv cwcglglUniformMatrix4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x3dv cwcglglUniformMatrix2x3dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x4dv cwcglglUniformMatrix2x4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x2dv cwcglglUniformMatrix3x2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x4dv cwcglglUniformMatrix3x4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x2dv cwcglglUniformMatrix4x2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x3dv cwcglglUniformMatrix4x3dv
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint program, GLint location, GLdouble * params);
#define glGetUniformdv cwcglglGetUniformdv
#define GL_ACTIVE_SUBROUTINES 0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B
typedef GLint (APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint program, GLenum shadertype, const GLchar * name);
#define glGetSubroutineUniformLocation cwcglglGetSubroutineUniformLocation
typedef GLuint (APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint program, GLenum shadertype, const GLchar * name);
#define glGetSubroutineIndex cwcglglGetSubroutineIndex
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values);
#define glGetActiveSubroutineUniformiv cwcglglGetActiveSubroutineUniformiv
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineUniformName cwcglglGetActiveSubroutineUniformName
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineName cwcglglGetActiveSubroutineName
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum shadertype, GLsizei count, const GLuint * indices);
#define glUniformSubroutinesuiv cwcglglUniformSubroutinesuiv
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum shadertype, GLint location, GLuint * params);
#define glGetUniformSubroutineuiv cwcglglGetUniformSubroutineuiv
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint program, GLenum shadertype, GLenum pname, GLint * values);
#define glGetProgramStageiv cwcglglGetProgramStageiv
#define GL_PATCHES 0x000E
#define GL_PATCH_VERTICES 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TESS_GEN_MODE 0x8E76
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_ISOLINES 0x8E7A
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_TESS_CONTROL_SHADER 0x8E88
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum pname, GLint value);
#define glPatchParameteri cwcglglPatchParameteri
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum pname, const GLfloat * values);
#define glPatchParameterfv cwcglglPatchParameterfv
#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
#define glBindTransformFeedback cwcglglBindTransformFeedback
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint * ids);
#define glDeleteTransformFeedbacks cwcglglDeleteTransformFeedbacks
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint * ids);
#define glGenTransformFeedbacks cwcglglGenTransformFeedbacks
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
#define glIsTransformFeedback cwcglglIsTransformFeedback
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);
#define glPauseTransformFeedback cwcglglPauseTransformFeedback
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);
#define glResumeTransformFeedback cwcglglResumeTransformFeedback
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum mode, GLuint id);
#define glDrawTransformFeedback cwcglglDrawTransformFeedback
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum mode, GLuint id, GLuint stream);
#define glDrawTransformFeedbackStream cwcglglDrawTransformFeedbackStream
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum target, GLuint index, GLuint id);
#define glBeginQueryIndexed cwcglglBeginQueryIndexed
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum target, GLuint index);
#define glEndQueryIndexed cwcglglEndQueryIndexed
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum target, GLuint index, GLenum pname, GLint * params);
#define glGetQueryIndexediv cwcglglGetQueryIndexediv
#endif

#if CWCGL_VERSION >= GL_VERSION_4_1
#define GL_FIXED 0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT 0x8DF0
#define GL_MEDIUM_FLOAT 0x8DF1
#define GL_HIGH_FLOAT 0x8DF2
#define GL_LOW_INT 0x8DF3
#define GL_MEDIUM_INT 0x8DF4
#define GL_HIGH_INT 0x8DF5
#define GL_SHADER_COMPILER 0x8DFA
#define GL_SHADER_BINARY_FORMATS 0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_MAX_VARYING_VECTORS 0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define GL_RGB565 0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH 0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define GL_PROGRAM_BINARY_FORMATS 0x87FF
#define GL_VERTEX_SHADER_BIT 0x00000001
#define GL_FRAGMENT_SHADER_BIT 0x00000002
#define GL_GEOMETRY_SHADER_BIT 0x00000004
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#define GL_ALL_SHADER_BITS 0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE 0x8258
#define GL_ACTIVE_PROGRAM 0x8259
#define GL_PROGRAM_PIPELINE_BINDING 0x825A
#define GL_MAX_VIEWPORTS 0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS 0x825C
#define GL_VIEWPORT_BOUNDS_RANGE 0x825D
#define GL_LAYER_PROVOKING_VERTEX 0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX 0x8260
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC)(void);
#define glReleaseShaderCompiler cwcglglReleaseShaderCompiler
typedef void (APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint * shaders, GLenum binaryformat, const void * binary, GLsizei length);
#define glShaderBinary cwcglglShaderBinary
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
#define glGetShaderPrecisionFormat cwcglglGetShaderPrecisionFormat
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
#define glDepthRangef cwcglglDepthRangef
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
#define glClearDepthf cwcglglClearDepthf
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
#define glGetProgramBinary cwcglglGetProgramBinary
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
#define glProgramBinary cwcglglProgramBinary
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
#define glProgramParameteri cwcglglProgramParameteri
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
#define glUseProgramStages cwcglglUseProgramStages
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint pipeline, GLuint program);
#define glActiveShaderProgram cwcglglActiveShaderProgram
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum type, GLsizei count, const GLchar *const* strings);
#define glCreateShaderProgramv cwcglglCreateShaderProgramv
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glBindProgramPipeline cwcglglBindProgramPipeline
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei n, const GLuint * pipelines);
#define glDeleteProgramPipelines cwcglglDeleteProgramPipelines
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei n, GLuint * pipelines);
#define glGenProgramPipelines cwcglglGenProgramPipelines
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glIsProgramPipeline cwcglglIsProgramPipeline
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint pipeline, GLenum pname, GLint * params);
#define glGetProgramPipelineiv cwcglglGetProgramPipelineiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint program, GLint location, GLint v0);
#define glProgramUniform1i cwcglglProgramUniform1i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform1iv cwcglglProgramUniform1iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint program, GLint location, GLfloat v0);
#define glProgramUniform1f cwcglglProgramUniform1f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform1fv cwcglglProgramUniform1fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint program, GLint location, GLdouble v0);
#define glProgramUniform1d cwcglglProgramUniform1d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform1dv cwcglglProgramUniform1dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint program, GLint location, GLuint v0);
#define glProgramUniform1ui cwcglglProgramUniform1ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform1uiv cwcglglProgramUniform1uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint program, GLint location, GLint v0, GLint v1);
#define glProgramUniform2i cwcglglProgramUniform2i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform2iv cwcglglProgramUniform2iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
#define glProgramUniform2f cwcglglProgramUniform2f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform2fv cwcglglProgramUniform2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
#define glProgramUniform2d cwcglglProgramUniform2d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform2dv cwcglglProgramUniform2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
#define glProgramUniform2ui cwcglglProgramUniform2ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform2uiv cwcglglProgramUniform2uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
#define glProgramUniform3i cwcglglProgramUniform3i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform3iv cwcglglProgramUniform3iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glProgramUniform3f cwcglglProgramUniform3f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform3fv cwcglglProgramUniform3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
#define glProgramUniform3d cwcglglProgramUniform3d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform3dv cwcglglProgramUniform3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glProgramUniform3ui cwcglglProgramUniform3ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform3uiv cwcglglProgramUniform3uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glProgramUniform4i cwcglglProgramUniform4i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform4iv cwcglglProgramUniform4iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glProgramUniform4f cwcglglProgramUniform4f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform4fv cwcglglProgramUniform4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
#define glProgramUniform4d cwcglglProgramUniform4d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform4dv cwcglglProgramUniform4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glProgramUniform4ui cwcglglProgramUniform4ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform4uiv cwcglglProgramUniform4uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2fv cwcglglProgramUniformMatrix2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3fv cwcglglProgramUniformMatrix3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4fv cwcglglProgramUniformMatrix4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2dv cwcglglProgramUniformMatrix2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3dv cwcglglProgramUniformMatrix3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4dv cwcglglProgramUniformMatrix4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x3fv cwcglglProgramUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x2fv cwcglglProgramUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x4fv cwcglglProgramUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x2fv cwcglglProgramUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x4fv cwcglglProgramUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x3fv cwcglglProgramUniformMatrix4x3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x3dv cwcglglProgramUniformMatrix2x3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x2dv cwcglglProgramUniformMatrix3x2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x4dv cwcglglProgramUniformMatrix2x4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x2dv cwcglglProgramUniformMatrix4x2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x4dv cwcglglProgramUniformMatrix3x4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x3dv cwcglglProgramUniformMatrix4x3dv
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glValidateProgramPipeline cwcglglValidateProgramPipeline
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetProgramPipelineInfoLog cwcglglGetProgramPipelineInfoLog
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint index, GLdouble x);
#define glVertexAttribL1d cwcglglVertexAttribL1d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttribL2d cwcglglVertexAttribL2d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttribL3d cwcglglVertexAttribL3d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttribL4d cwcglglVertexAttribL4d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL1dv cwcglglVertexAttribL1dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL2dv cwcglglVertexAttribL2dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL3dv cwcglglVertexAttribL3dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL4dv cwcglglVertexAttribL4dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribLPointer cwcglglVertexAttribLPointer
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribLdv cwcglglGetVertexAttribLdv
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint first, GLsizei count, const GLfloat * v);
#define glViewportArrayv cwcglglViewportArrayv
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
#define glViewportIndexedf cwcglglViewportIndexedf
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint index, const GLfloat * v);
#define glViewportIndexedfv cwcglglViewportIndexedfv
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint first, GLsizei count, const GLint * v);
#define glScissorArrayv cwcglglScissorArrayv
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
#define glScissorIndexed cwcglglScissorIndexed
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint index, const GLint * v);
#define glScissorIndexedv cwcglglScissorIndexedv
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint first, GLsizei count, const GLdouble * v);
#define glDepthRangeArrayv cwcglglDepthRangeArrayv
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint index, GLdouble n, GLdouble f);
#define glDepthRangeIndexed cwcglglDepthRangeIndexed
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC)(GLenum target, GLuint index, GLfloat * data);
#define glGetFloati_v cwcglglGetFloati_v
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum target, GLuint index, GLdouble * data);
#define glGetDoublei_v cwcglglGetDoublei_v
#endif

#if CWCGL_VERSION >= GL_VERSION_4_2
#define GL_COPY_READ_BUFFER_BINDING 0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37
#define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E
#define GL_NUM_SAMPLE_COUNTS 0x9380
#define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC
#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#define GL_UNIFORM_BARRIER_BIT 0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT 0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#define GL_ALL_BARRIER_BITS 0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_IMAGE_1D 0x904C
#define GL_IMAGE_2D 0x904D
#define GL_IMAGE_3D 0x904E
#define GL_IMAGE_2D_RECT 0x904F
#define GL_IMAGE_CUBE 0x9050
#define GL_IMAGE_BUFFER 0x9051
#define GL_IMAGE_1D_ARRAY 0x9052
#define GL_IMAGE_2D_ARRAY 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#define GL_IMAGE_2D_MULTISAMPLE 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
#define GL_INT_IMAGE_1D 0x9057
#define GL_INT_IMAGE_2D 0x9058
#define GL_INT_IMAGE_3D 0x9059
#define GL_INT_IMAGE_2D_RECT 0x905A
#define GL_INT_IMAGE_CUBE 0x905B
#define GL_INT_IMAGE_BUFFER 0x905C
#define GL_INT_IMAGE_1D_ARRAY 0x905D
#define GL_INT_IMAGE_2D_ARRAY 0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES 0x906D
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
#define GL_COMPRESSED_RGBA_BPTC_UNORM 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
#define glDrawArraysInstancedBaseInstance cwcglglDrawArraysInstancedBaseInstance
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
#define glDrawElementsInstancedBaseInstance cwcglglDrawElementsInstancedBaseInstance
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#define glDrawElementsInstancedBaseVertexBaseInstance cwcglglDrawElementsInstancedBaseVertexBaseInstance
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint * params);
#define glGetInternalformativ cwcglglGetInternalformativ
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params);
#define glGetActiveAtomicCounterBufferiv cwcglglGetActiveAtomicCounterBufferiv
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
#define glBindImageTexture cwcglglBindImageTexture
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC)(GLbitfield barriers);
#define glMemoryBarrier cwcglglMemoryBarrier
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTexStorage1D cwcglglTexStorage1D
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTexStorage2D cwcglglTexStorage2D
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTexStorage3D cwcglglTexStorage3D
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum mode, GLuint id, GLsizei instancecount);
#define glDrawTransformFeedbackInstanced cwcglglDrawTransformFeedbackInstanced
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#define glDrawTransformFeedbackStreamInstanced cwcglglDrawTransformFeedbackStreamInstanced
#endif

#if CWCGL_VERSION >= GL_VERSION_4_3
typedef void ( *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
#define GL_NUM_SHADING_LANGUAGE_VERSIONS 0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG 0x874E
#define GL_COMPRESSED_RGB8_ETC2 0x9274
#define GL_COMPRESSED_SRGB8_ETC2 0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC 0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC 0x9271
#define GL_COMPRESSED_RG11_EAC 0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX 0x8D6B
#define GL_COMPUTE_SHADER 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE 0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER_BIT 0x00000020
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM 0x8245
#define GL_DEBUG_SOURCE_API 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249
#define GL_DEBUG_SOURCE_APPLICATION 0x824A
#define GL_DEBUG_SOURCE_OTHER 0x824B
#define GL_DEBUG_TYPE_ERROR 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
#define GL_DEBUG_TYPE_PORTABILITY 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE 0x8250
#define GL_DEBUG_TYPE_OTHER 0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#define GL_DEBUG_LOGGED_MESSAGES 0x9145
#define GL_DEBUG_SEVERITY_HIGH 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM 0x9147
#define GL_DEBUG_SEVERITY_LOW 0x9148
#define GL_DEBUG_TYPE_MARKER 0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
#define GL_DEBUG_TYPE_POP_GROUP 0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH 0x826D
#define GL_BUFFER 0x82E0
#define GL_SHADER 0x82E1
#define GL_PROGRAM 0x82E2
#define GL_QUERY 0x82E3
#define GL_PROGRAM_PIPELINE 0x82E4
#define GL_SAMPLER 0x82E6
#define GL_MAX_LABEL_LENGTH 0x82E8
#define GL_DEBUG_OUTPUT 0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002
#define GL_MAX_UNIFORM_LOCATIONS 0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318
#define GL_INTERNALFORMAT_SUPPORTED 0x826F
#define GL_INTERNALFORMAT_PREFERRED 0x8270
#define GL_INTERNALFORMAT_RED_SIZE 0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE 0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE 0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE 0x8277
#define GL_INTERNALFORMAT_RED_TYPE 0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE 0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE 0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D
#define GL_MAX_WIDTH 0x827E
#define GL_MAX_HEIGHT 0x827F
#define GL_MAX_DEPTH 0x8280
#define GL_MAX_LAYERS 0x8281
#define GL_MAX_COMBINED_DIMENSIONS 0x8282
#define GL_COLOR_COMPONENTS 0x8283
#define GL_DEPTH_COMPONENTS 0x8284
#define GL_STENCIL_COMPONENTS 0x8285
#define GL_COLOR_RENDERABLE 0x8286
#define GL_DEPTH_RENDERABLE 0x8287
#define GL_STENCIL_RENDERABLE 0x8288
#define GL_FRAMEBUFFER_RENDERABLE 0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND 0x828B
#define GL_READ_PIXELS 0x828C
#define GL_READ_PIXELS_FORMAT 0x828D
#define GL_READ_PIXELS_TYPE 0x828E
#define GL_TEXTURE_IMAGE_FORMAT 0x828F
#define GL_TEXTURE_IMAGE_TYPE 0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE 0x8292
#define GL_MIPMAP 0x8293
#define GL_MANUAL_GENERATE_MIPMAP 0x8294
#define GL_AUTO_GENERATE_MIPMAP 0x8295
#define GL_COLOR_ENCODING 0x8296
#define GL_SRGB_READ 0x8297
#define GL_SRGB_WRITE 0x8298
#define GL_FILTER 0x829A
#define GL_VERTEX_TEXTURE 0x829B
#define GL_TESS_CONTROL_TEXTURE 0x829C
#define GL_TESS_EVALUATION_TEXTURE 0x829D
#define GL_GEOMETRY_TEXTURE 0x829E
#define GL_FRAGMENT_TEXTURE 0x829F
#define GL_COMPUTE_TEXTURE 0x82A0
#define GL_TEXTURE_SHADOW 0x82A1
#define GL_TEXTURE_GATHER 0x82A2
#define GL_TEXTURE_GATHER_SHADOW 0x82A3
#define GL_SHADER_IMAGE_LOAD 0x82A4
#define GL_SHADER_IMAGE_STORE 0x82A5
#define GL_SHADER_IMAGE_ATOMIC 0x82A6
#define GL_IMAGE_TEXEL_SIZE 0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8
#define GL_IMAGE_PIXEL_FORMAT 0x82A9
#define GL_IMAGE_PIXEL_TYPE 0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3
#define GL_CLEAR_BUFFER 0x82B4
#define GL_TEXTURE_VIEW 0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS 0x82B6
#define GL_FULL_SUPPORT 0x82B7
#define GL_CAVEAT_SUPPORT 0x82B8
#define GL_IMAGE_CLASS_4_X_32 0x82B9
#define GL_IMAGE_CLASS_2_X_32 0x82BA
#define GL_IMAGE_CLASS_1_X_32 0x82BB
#define GL_IMAGE_CLASS_4_X_16 0x82BC
#define GL_IMAGE_CLASS_2_X_16 0x82BD
#define GL_IMAGE_CLASS_1_X_16 0x82BE
#define GL_IMAGE_CLASS_4_X_8 0x82BF
#define GL_IMAGE_CLASS_2_X_8 0x82C0
#define GL_IMAGE_CLASS_1_X_8 0x82C1
#define GL_IMAGE_CLASS_11_11_10 0x82C2
#define GL_IMAGE_CLASS_10_10_10_2 0x82C3
#define GL_VIEW_CLASS_128_BITS 0x82C4
#define GL_VIEW_CLASS_96_BITS 0x82C5
#define GL_VIEW_CLASS_64_BITS 0x82C6
#define GL_VIEW_CLASS_48_BITS 0x82C7
#define GL_VIEW_CLASS_32_BITS 0x82C8
#define GL_VIEW_CLASS_24_BITS 0x82C9
#define GL_VIEW_CLASS_16_BITS 0x82CA
#define GL_VIEW_CLASS_8_BITS 0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
#define GL_VIEW_CLASS_RGTC1_RED 0x82D0
#define GL_VIEW_CLASS_RGTC2_RG 0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3
#define GL_UNIFORM 0x92E1
#define GL_UNIFORM_BLOCK 0x92E2
#define GL_PROGRAM_INPUT 0x92E3
#define GL_PROGRAM_OUTPUT 0x92E4
#define GL_BUFFER_VARIABLE 0x92E5
#define GL_SHADER_STORAGE_BLOCK 0x92E6
#define GL_VERTEX_SUBROUTINE 0x92E8
#define GL_TESS_CONTROL_SUBROUTINE 0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE 0x92EA
#define GL_GEOMETRY_SUBROUTINE 0x92EB
#define GL_FRAGMENT_SUBROUTINE 0x92EC
#define GL_COMPUTE_SUBROUTINE 0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
#define GL_ACTIVE_RESOURCES 0x92F5
#define GL_MAX_NAME_LENGTH 0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH 0x92F9
#define GL_TYPE 0x92FA
#define GL_ARRAY_SIZE 0x92FB
#define GL_OFFSET 0x92FC
#define GL_BLOCK_INDEX 0x92FD
#define GL_ARRAY_STRIDE 0x92FE
#define GL_MATRIX_STRIDE 0x92FF
#define GL_IS_ROW_MAJOR 0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
#define GL_BUFFER_BINDING 0x9302
#define GL_BUFFER_DATA_SIZE 0x9303
#define GL_NUM_ACTIVE_VARIABLES 0x9304
#define GL_ACTIVE_VARIABLES 0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
#define GL_LOCATION 0x930E
#define GL_LOCATION_INDEX 0x930F
#define GL_IS_PER_PATCH 0x92E7
#define GL_SHADER_STORAGE_BUFFER 0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
#define GL_SHADER_STORAGE_BUFFER_START 0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT 0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA
#define GL_TEXTURE_BUFFER_OFFSET 0x919D
#define GL_TEXTURE_BUFFER_SIZE 0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF
#define GL_VERTEX_ATTRIB_BINDING 0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
#define GL_VERTEX_BINDING_DIVISOR 0x82D6
#define GL_VERTEX_BINDING_OFFSET 0x82D7
#define GL_VERTEX_BINDING_STRIDE 0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA
#define GL_VERTEX_BINDING_BUFFER 0x8F4F
typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearBufferData cwcglglClearBufferData
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearBufferSubData cwcglglClearBufferSubData
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
#define glDispatchCompute cwcglglDispatchCompute
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
#define glDispatchComputeIndirect cwcglglDispatchComputeIndirect
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#define glCopyImageSubData cwcglglCopyImageSubData
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
#define glFramebufferParameteri cwcglglFramebufferParameteri
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetFramebufferParameteriv cwcglglGetFramebufferParameteriv
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 * params);
#define glGetInternalformati64v cwcglglGetInternalformati64v
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
#define glInvalidateTexSubImage cwcglglInvalidateTexSubImage
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC)(GLuint texture, GLint level);
#define glInvalidateTexImage cwcglglInvalidateTexImage
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glInvalidateBufferSubData cwcglglInvalidateBufferSubData
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC)(GLuint buffer);
#define glInvalidateBufferData cwcglglInvalidateBufferData
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateFramebuffer cwcglglInvalidateFramebuffer
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateSubFramebuffer cwcglglInvalidateSubFramebuffer
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawArraysIndirect cwcglglMultiDrawArraysIndirect
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawElementsIndirect cwcglglMultiDrawElementsIndirect
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program, GLenum programInterface, GLenum pname, GLint * params);
#define glGetProgramInterfaceiv cwcglglGetProgramInterfaceiv
typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceIndex cwcglglGetProgramResourceIndex
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
#define glGetProgramResourceName cwcglglGetProgramResourceName
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params);
#define glGetProgramResourceiv cwcglglGetProgramResourceiv
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocation cwcglglGetProgramResourceLocation
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocationIndex cwcglglGetProgramResourceLocationIndex
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
#define glShaderStorageBlockBinding cwcglglShaderStorageBlockBinding
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTexBufferRange cwcglglTexBufferRange
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexStorage2DMultisample cwcglglTexStorage2DMultisample
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexStorage3DMultisample cwcglglTexStorage3DMultisample
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#define glTextureView cwcglglTextureView
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glBindVertexBuffer cwcglglBindVertexBuffer
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexAttribFormat cwcglglVertexAttribFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribIFormat cwcglglVertexAttribIFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribLFormat cwcglglVertexAttribLFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
#define glVertexAttribBinding cwcglglVertexAttribBinding
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
#define glVertexBindingDivisor cwcglglVertexBindingDivisor
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
#define glDebugMessageControl cwcglglDebugMessageControl
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
#define glDebugMessageInsert cwcglglDebugMessageInsert
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void * userParam);
#define glDebugMessageCallback cwcglglDebugMessageCallback
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
#define glGetDebugMessageLog cwcglglGetDebugMessageLog
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum source, GLuint id, GLsizei length, const GLchar * message);
#define glPushDebugGroup cwcglglPushDebugGroup
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC)(void);
#define glPopDebugGroup cwcglglPopDebugGroup
typedef void (APIENTRYP PFNGLOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
#define glObjectLabel cwcglglObjectLabel
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectLabel cwcglglGetObjectLabel
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC)(const void * ptr, GLsizei length, const GLchar * label);
#define glObjectPtrLabel cwcglglObjectPtrLabel
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC)(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectPtrLabel cwcglglGetObjectPtrLabel
#define GL_DISPLAY_LIST 0x82E7
#endif

#if CWCGL_VERSION >= GL_VERSION_4_4
#define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_TEXTURE_BUFFER_BINDING 0x8C2A
#define GL_MAP_PERSISTENT_BIT 0x0040
#define GL_MAP_COHERENT_BIT 0x0080
#define GL_DYNAMIC_STORAGE_BIT 0x0100
#define GL_CLIENT_STORAGE_BIT 0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE 0x821F
#define GL_BUFFER_STORAGE_FLAGS 0x8220
typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC)(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags);
#define glBufferStorage cwcglglBufferStorage
#define GL_CLEAR_TEXTURE 0x9365
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
#define glClearTexImage cwcglglClearTexImage
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
#define glClearTexSubImage cwcglglClearTexSubImage
#define GL_LOCATION_COMPONENT 0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers);
#define glBindBuffersBase cwcglglBindBuffersBase
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes);
#define glBindBuffersRange cwcglglBindBuffersRange
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindTextures cwcglglBindTextures
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint * samplers);
#define glBindSamplers cwcglglBindSamplers
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindImageTextures cwcglglBindImageTextures
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glBindVertexBuffers cwcglglBindVertexBuffers
#define GL_QUERY_BUFFER 0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000
#define GL_QUERY_BUFFER_BINDING 0x9193
#define GL_QUERY_RESULT_NO_WAIT 0x9194
#define GL_MIRROR_CLAMP_TO_EDGE 0x8743
#endif

#if CWCGL_VERSION >= GL_VERSION_4_5
#define GL_CONTEXT_LOST 0x0507
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC)(GLenum origin, GLenum depth);
#define glClipControl cwcglglClipControl
#define GL_NEGATIVE_ONE_TO_ONE 0x935E
#define GL_ZERO_TO_ONE 0x935F
#define GL_CLIP_ORIGIN 0x935C
#define GL_CLIP_DEPTH_MODE 0x935D
#define GL_QUERY_WAIT_INVERTED 0x8E17
#define GL_QUERY_NO_WAIT_INVERTED 0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED 0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_MAX_CULL_DISTANCES 0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_TEXTURE_TARGET 0x1006
#define GL_QUERY_TARGET 0x82EA
typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint * ids);
#define glCreateTransformFeedbacks cwcglglCreateTransformFeedbacks
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint xfb, GLuint index, GLuint buffer);
#define glTransformFeedbackBufferBase cwcglglTransformFeedbackBufferBase
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTransformFeedbackBufferRange cwcglglTransformFeedbackBufferRange
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint xfb, GLenum pname, GLint * param);
#define glGetTransformFeedbackiv cwcglglGetTransformFeedbackiv
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint * param);
#define glGetTransformFeedbacki_v cwcglglGetTransformFeedbacki_v
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint64 * param);
#define glGetTransformFeedbacki64_v cwcglglGetTransformFeedbacki64_v
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei n, GLuint * buffers);
#define glCreateBuffers cwcglglCreateBuffers
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
#define glNamedBufferStorage cwcglglNamedBufferStorage
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
#define glNamedBufferData cwcglglNamedBufferData
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
#define glNamedBufferSubData cwcglglNamedBufferSubData
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyNamedBufferSubData cwcglglCopyNamedBufferSubData
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferData cwcglglClearNamedBufferData
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferSubData cwcglglClearNamedBufferSubData
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint buffer, GLenum access);
#define glMapNamedBuffer cwcglglMapNamedBuffer
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapNamedBufferRange cwcglglMapNamedBufferRange
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint buffer);
#define glUnmapNamedBuffer cwcglglUnmapNamedBuffer
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glFlushMappedNamedBufferRange cwcglglFlushMappedNamedBufferRange
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint buffer, GLenum pname, GLint * params);
#define glGetNamedBufferParameteriv cwcglglGetNamedBufferParameteriv
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint buffer, GLenum pname, GLint64 * params);
#define glGetNamedBufferParameteri64v cwcglglGetNamedBufferParameteri64v
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint buffer, GLenum pname, void ** params);
#define glGetNamedBufferPointerv cwcglglGetNamedBufferPointerv
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
#define glGetNamedBufferSubData cwcglglGetNamedBufferSubData
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei n, GLuint * framebuffers);
#define glCreateFramebuffers cwcglglCreateFramebuffers
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glNamedFramebufferRenderbuffer cwcglglNamedFramebufferRenderbuffer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint framebuffer, GLenum pname, GLint param);
#define glNamedFramebufferParameteri cwcglglNamedFramebufferParameteri
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
#define glNamedFramebufferTexture cwcglglNamedFramebufferTexture
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glNamedFramebufferTextureLayer cwcglglNamedFramebufferTextureLayer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint framebuffer, GLenum buf);
#define glNamedFramebufferDrawBuffer cwcglglNamedFramebufferDrawBuffer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint framebuffer, GLsizei n, const GLenum * bufs);
#define glNamedFramebufferDrawBuffers cwcglglNamedFramebufferDrawBuffers
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint framebuffer, GLenum src);
#define glNamedFramebufferReadBuffer cwcglglNamedFramebufferReadBuffer
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateNamedFramebufferData cwcglglInvalidateNamedFramebufferData
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateNamedFramebufferSubData cwcglglInvalidateNamedFramebufferSubData
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value);
#define glClearNamedFramebufferiv cwcglglClearNamedFramebufferiv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value);
#define glClearNamedFramebufferuiv cwcglglClearNamedFramebufferuiv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat * value);
#define glClearNamedFramebufferfv cwcglglClearNamedFramebufferfv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
#define glClearNamedFramebufferfi cwcglglClearNamedFramebufferfi
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitNamedFramebuffer cwcglglBlitNamedFramebuffer
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint framebuffer, GLenum target);
#define glCheckNamedFramebufferStatus cwcglglCheckNamedFramebufferStatus
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint framebuffer, GLenum pname, GLint * param);
#define glGetNamedFramebufferParameteriv cwcglglGetNamedFramebufferParameteriv
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
#define glGetNamedFramebufferAttachmentParameteriv cwcglglGetNamedFramebufferAttachmentParameteriv
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei n, GLuint * renderbuffers);
#define glCreateRenderbuffers cwcglglCreateRenderbuffers
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorage cwcglglNamedRenderbufferStorage
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisample cwcglglNamedRenderbufferStorageMultisample
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint renderbuffer, GLenum pname, GLint * params);
#define glGetNamedRenderbufferParameteriv cwcglglGetNamedRenderbufferParameteriv
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC)(GLenum target, GLsizei n, GLuint * textures);
#define glCreateTextures cwcglglCreateTextures
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint texture, GLenum internalformat, GLuint buffer);
#define glTextureBuffer cwcglglTextureBuffer
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTextureBufferRange cwcglglTextureBufferRange
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTextureStorage1D cwcglglTextureStorage1D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTextureStorage2D cwcglglTextureStorage2D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTextureStorage3D cwcglglTextureStorage3D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTextureStorage2DMultisample cwcglglTextureStorage2DMultisample
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTextureStorage3DMultisample cwcglglTextureStorage3DMultisample
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage1D cwcglglTextureSubImage1D
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage2D cwcglglTextureSubImage2D
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage3D cwcglglTextureSubImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage1D cwcglglCompressedTextureSubImage1D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage2D cwcglglCompressedTextureSubImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage3D cwcglglCompressedTextureSubImage3D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTextureSubImage1D cwcglglCopyTextureSubImage1D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage2D cwcglglCopyTextureSubImage2D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage3D cwcglglCopyTextureSubImage3D
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint texture, GLenum pname, GLfloat param);
#define glTextureParameterf cwcglglTextureParameterf
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, const GLfloat * param);
#define glTextureParameterfv cwcglglTextureParameterfv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint texture, GLenum pname, GLint param);
#define glTextureParameteri cwcglglTextureParameteri
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, const GLint * params);
#define glTextureParameterIiv cwcglglTextureParameterIiv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, const GLuint * params);
#define glTextureParameterIuiv cwcglglTextureParameterIuiv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, const GLint * param);
#define glTextureParameteriv cwcglglTextureParameteriv
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint texture);
#define glGenerateTextureMipmap cwcglglGenerateTextureMipmap
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint unit, GLuint texture);
#define glBindTextureUnit cwcglglBindTextureUnit
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureImage cwcglglGetTextureImage
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureImage cwcglglGetCompressedTextureImage
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint texture, GLint level, GLenum pname, GLfloat * params);
#define glGetTextureLevelParameterfv cwcglglGetTextureLevelParameterfv
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint texture, GLint level, GLenum pname, GLint * params);
#define glGetTextureLevelParameteriv cwcglglGetTextureLevelParameteriv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, GLfloat * params);
#define glGetTextureParameterfv cwcglglGetTextureParameterfv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameterIiv cwcglglGetTextureParameterIiv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, GLuint * params);
#define glGetTextureParameterIuiv cwcglglGetTextureParameterIuiv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameteriv cwcglglGetTextureParameteriv
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei n, GLuint * arrays);
#define glCreateVertexArrays cwcglglCreateVertexArrays
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
#define glDisableVertexArrayAttrib cwcglglDisableVertexArrayAttrib
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
#define glEnableVertexArrayAttrib cwcglglEnableVertexArrayAttrib
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint vaobj, GLuint buffer);
#define glVertexArrayElementBuffer cwcglglVertexArrayElementBuffer
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glVertexArrayVertexBuffer cwcglglVertexArrayVertexBuffer
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glVertexArrayVertexBuffers cwcglglVertexArrayVertexBuffers
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
#define glVertexArrayAttribBinding cwcglglVertexArrayAttribBinding
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexArrayAttribFormat cwcglglVertexArrayAttribFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribIFormat cwcglglVertexArrayAttribIFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribLFormat cwcglglVertexArrayAttribLFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#define glVertexArrayBindingDivisor cwcglglVertexArrayBindingDivisor
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint vaobj, GLenum pname, GLint * param);
#define glGetVertexArrayiv cwcglglGetVertexArrayiv
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint * param);
#define glGetVertexArrayIndexediv cwcglglGetVertexArrayIndexediv
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param);
#define glGetVertexArrayIndexed64iv cwcglglGetVertexArrayIndexed64iv
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei n, GLuint * samplers);
#define glCreateSamplers cwcglglCreateSamplers
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei n, GLuint * pipelines);
#define glCreateProgramPipelines cwcglglCreateProgramPipelines
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC)(GLenum target, GLsizei n, GLuint * ids);
#define glCreateQueries cwcglglCreateQueries
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjecti64v cwcglglGetQueryBufferObjecti64v
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectiv cwcglglGetQueryBufferObjectiv
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectui64v cwcglglGetQueryBufferObjectui64v
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectuiv cwcglglGetQueryBufferObjectuiv
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
#define glMemoryBarrierByRegion cwcglglMemoryBarrierByRegion
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureSubImage cwcglglGetTextureSubImage
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureSubImage cwcglglGetCompressedTextureSubImage
#define GL_GUILTY_CONTEXT_RESET 0x8253
#define GL_INNOCENT_CONTEXT_RESET 0x8254
#define GL_UNKNOWN_CONTEXT_RESET 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY 0x8256
#define GL_LOSE_CONTEXT_ON_RESET 0x8252
#define GL_NO_RESET_NOTIFICATION 0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)(void);
#define glGetGraphicsResetStatus cwcglglGetGraphicsResetStatus
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint lod, GLsizei bufSize, void * pixels);
#define glGetnCompressedTexImage cwcglglGetnCompressedTexImage
typedef void (APIENTRYP PFNGLGETNTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetnTexImage cwcglglGetnTexImage
typedef void (APIENTRYP PFNGLGETNUNIFORMDVPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble * params);
#define glGetnUniformdv cwcglglGetnUniformdv
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
#define glGetnUniformfv cwcglglGetnUniformfv
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint * params);
#define glGetnUniformiv cwcglglGetnUniformiv
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint * params);
#define glGetnUniformuiv cwcglglGetnUniformuiv
typedef void (APIENTRYP PFNGLREADNPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
#define glReadnPixels cwcglglReadnPixels
typedef void (APIENTRYP PFNGLGETNMAPDVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v);
#define glGetnMapdv cwcglglGetnMapdv
typedef void (APIENTRYP PFNGLGETNMAPFVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v);
#define glGetnMapfv cwcglglGetnMapfv
typedef void (APIENTRYP PFNGLGETNMAPIVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint * v);
#define glGetnMapiv cwcglglGetnMapiv
typedef void (APIENTRYP PFNGLGETNPIXELMAPFVPROC)(GLenum map, GLsizei bufSize, GLfloat * values);
#define glGetnPixelMapfv cwcglglGetnPixelMapfv
typedef void (APIENTRYP PFNGLGETNPIXELMAPUIVPROC)(GLenum map, GLsizei bufSize, GLuint * values);
#define glGetnPixelMapuiv cwcglglGetnPixelMapuiv
typedef void (APIENTRYP PFNGLGETNPIXELMAPUSVPROC)(GLenum map, GLsizei bufSize, GLushort * values);
#define glGetnPixelMapusv cwcglglGetnPixelMapusv
typedef void (APIENTRYP PFNGLGETNPOLYGONSTIPPLEPROC)(GLsizei bufSize, GLubyte * pattern);
#define glGetnPolygonStipple cwcglglGetnPolygonStipple
typedef void (APIENTRYP PFNGLGETNCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table);
#define glGetnColorTable cwcglglGetnColorTable
typedef void (APIENTRYP PFNGLGETNCONVOLUTIONFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image);
#define glGetnConvolutionFilter cwcglglGetnConvolutionFilter
typedef void (APIENTRYP PFNGLGETNSEPARABLEFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span);
#define glGetnSeparableFilter cwcglglGetnSeparableFilter
typedef void (APIENTRYP PFNGLGETNHISTOGRAMPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
#define glGetnHistogram cwcglglGetnHistogram
typedef void (APIENTRYP PFNGLGETNMINMAXPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
#define glGetnMinmax cwcglglGetnMinmax
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC)(void);
#define glTextureBarrier cwcglglTextureBarrier
#define GL_CONTEXT_RELEASE_BEHAVIOR 0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
#endif


#define GL_FUNCTIONS_1_0 \
    X(PFNGLCULLFACEPROC, glCullFace) \
    X(PFNGLFRONTFACEPROC, glFrontFace) \
    X(PFNGLHINTPROC, glHint) \
    X(PFNGLLINEWIDTHPROC, glLineWidth) \
    X(PFNGLPOINTSIZEPROC, glPointSize) \
    X(PFNGLPOLYGONMODEPROC, glPolygonMode) \
    X(PFNGLSCISSORPROC, glScissor) \
    X(PFNGLTEXPARAMETERFPROC, glTexParameterf) \
    X(PFNGLTEXPARAMETERFVPROC, glTexParameterfv) \
    X(PFNGLTEXPARAMETERIPROC, glTexParameteri) \
    X(PFNGLTEXPARAMETERIVPROC, glTexParameteriv) \
    X(PFNGLTEXIMAGE1DPROC, glTexImage1D) \
    X(PFNGLTEXIMAGE2DPROC, glTexImage2D) \
    X(PFNGLDRAWBUFFERPROC, glDrawBuffer) \
    X(PFNGLCLEARPROC, glClear) \
    X(PFNGLCLEARCOLORPROC, glClearColor) \
    X(PFNGLCLEARSTENCILPROC, glClearStencil) \
    X(PFNGLCLEARDEPTHPROC, glClearDepth) \
    X(PFNGLSTENCILMASKPROC, glStencilMask) \
    X(PFNGLCOLORMASKPROC, glColorMask) \
    X(PFNGLDEPTHMASKPROC, glDepthMask) \
    X(PFNGLDISABLEPROC, glDisable) \
    X(PFNGLENABLEPROC, glEnable) \
    X(PFNGLFINISHPROC, glFinish) \
    X(PFNGLFLUSHPROC, glFlush) \
    X(PFNGLBLENDFUNCPROC, glBlendFunc) \
    X(PFNGLLOGICOPPROC, glLogicOp) \
    X(PFNGLSTENCILFUNCPROC, glStencilFunc) \
    X(PFNGLSTENCILOPPROC, glStencilOp) \
    X(PFNGLDEPTHFUNCPROC, glDepthFunc) \
    X(PFNGLPIXELSTOREFPROC, glPixelStoref) \
    X(PFNGLPIXELSTOREIPROC, glPixelStorei) \
    X(PFNGLREADBUFFERPROC, glReadBuffer) \
    X(PFNGLREADPIXELSPROC, glReadPixels) \
    X(PFNGLGETBOOLEANVPROC, glGetBooleanv) \
    X(PFNGLGETDOUBLEVPROC, glGetDoublev) \
    X(PFNGLGETERRORPROC, glGetError) \
    X(PFNGLGETFLOATVPROC, glGetFloatv) \
    X(PFNGLGETINTEGERVPROC, glGetIntegerv) \
    X(PFNGLGETSTRINGPROC, glGetString) \
    X(PFNGLGETTEXIMAGEPROC, glGetTexImage) \
    X(PFNGLGETTEXPARAMETERFVPROC, glGetTexParameterfv) \
    X(PFNGLGETTEXPARAMETERIVPROC, glGetTexParameteriv) \
    X(PFNGLGETTEXLEVELPARAMETERFVPROC, glGetTexLevelParameterfv) \
    X(PFNGLGETTEXLEVELPARAMETERIVPROC, glGetTexLevelParameteriv) \
    X(PFNGLISENABLEDPROC, glIsEnabled) \
    X(PFNGLDEPTHRANGEPROC, glDepthRange) \
    X(PFNGLVIEWPORTPROC, glViewport) \
    X(PFNGLNEWLISTPROC, glNewList) \
    X(PFNGLENDLISTPROC, glEndList) \
    X(PFNGLCALLLISTPROC, glCallList) \
    X(PFNGLCALLLISTSPROC, glCallLists) \
    X(PFNGLDELETELISTSPROC, glDeleteLists) \
    X(PFNGLGENLISTSPROC, glGenLists) \
    X(PFNGLLISTBASEPROC, glListBase) \
    X(PFNGLBEGINPROC, glBegin) \
    X(PFNGLBITMAPPROC, glBitmap) \
    X(PFNGLCOLOR3BPROC, glColor3b) \
    X(PFNGLCOLOR3BVPROC, glColor3bv) \
    X(PFNGLCOLOR3DPROC, glColor3d) \
    X(PFNGLCOLOR3DVPROC, glColor3dv) \
    X(PFNGLCOLOR3FPROC, glColor3f) \
    X(PFNGLCOLOR3FVPROC, glColor3fv) \
    X(PFNGLCOLOR3IPROC, glColor3i) \
    X(PFNGLCOLOR3IVPROC, glColor3iv) \
    X(PFNGLCOLOR3SPROC, glColor3s) \
    X(PFNGLCOLOR3SVPROC, glColor3sv) \
    X(PFNGLCOLOR3UBPROC, glColor3ub) \
    X(PFNGLCOLOR3UBVPROC, glColor3ubv) \
    X(PFNGLCOLOR3UIPROC, glColor3ui) \
    X(PFNGLCOLOR3UIVPROC, glColor3uiv) \
    X(PFNGLCOLOR3USPROC, glColor3us) \
    X(PFNGLCOLOR3USVPROC, glColor3usv) \
    X(PFNGLCOLOR4BPROC, glColor4b) \
    X(PFNGLCOLOR4BVPROC, glColor4bv) \
    X(PFNGLCOLOR4DPROC, glColor4d) \
    X(PFNGLCOLOR4DVPROC, glColor4dv) \
    X(PFNGLCOLOR4FPROC, glColor4f) \
    X(PFNGLCOLOR4FVPROC, glColor4fv) \
    X(PFNGLCOLOR4IPROC, glColor4i) \
    X(PFNGLCOLOR4IVPROC, glColor4iv) \
    X(PFNGLCOLOR4SPROC, glColor4s) \
    X(PFNGLCOLOR4SVPROC, glColor4sv) \
    X(PFNGLCOLOR4UBPROC, glColor4ub) \
    X(PFNGLCOLOR4UBVPROC, glColor4ubv) \
    X(PFNGLCOLOR4UIPROC, glColor4ui) \
    X(PFNGLCOLOR4UIVPROC, glColor4uiv) \
    X(PFNGLCOLOR4USPROC, glColor4us) \
    X(PFNGLCOLOR4USVPROC, glColor4usv) \
    X(PFNGLEDGEFLAGPROC, glEdgeFlag) \
    X(PFNGLEDGEFLAGVPROC, glEdgeFlagv) \
    X(PFNGLENDPROC, glEnd) \
    X(PFNGLINDEXDPROC, glIndexd) \
    X(PFNGLINDEXDVPROC, glIndexdv) \
    X(PFNGLINDEXFPROC, glIndexf) \
    X(PFNGLINDEXFVPROC, glIndexfv) \
    X(PFNGLINDEXIPROC, glIndexi) \
    X(PFNGLINDEXIVPROC, glIndexiv) \
    X(PFNGLINDEXSPROC, glIndexs) \
    X(PFNGLINDEXSVPROC, glIndexsv) \
    X(PFNGLNORMAL3BPROC, glNormal3b) \
    X(PFNGLNORMAL3BVPROC, glNormal3bv) \
    X(PFNGLNORMAL3DPROC, glNormal3d) \
    X(PFNGLNORMAL3DVPROC, glNormal3dv) \
    X(PFNGLNORMAL3FPROC, glNormal3f) \
    X(PFNGLNORMAL3FVPROC, glNormal3fv) \
    X(PFNGLNORMAL3IPROC, glNormal3i) \
    X(PFNGLNORMAL3IVPROC, glNormal3iv) \
    X(PFNGLNORMAL3SPROC, glNormal3s) \
    X(PFNGLNORMAL3SVPROC, glNormal3sv) \
    X(PFNGLRASTERPOS2DPROC, glRasterPos2d) \
    X(PFNGLRASTERPOS2DVPROC, glRasterPos2dv) \
    X(PFNGLRASTERPOS2FPROC, glRasterPos2f) \
    X(PFNGLRASTERPOS2FVPROC, glRasterPos2fv) \
    X(PFNGLRASTERPOS2IPROC, glRasterPos2i) \
    X(PFNGLRASTERPOS2IVPROC, glRasterPos2iv) \
    X(PFNGLRASTERPOS2SPROC, glRasterPos2s) \
    X(PFNGLRASTERPOS2SVPROC, glRasterPos2sv) \
    X(PFNGLRASTERPOS3DPROC, glRasterPos3d) \
    X(PFNGLRASTERPOS3DVPROC, glRasterPos3dv) \
    X(PFNGLRASTERPOS3FPROC, glRasterPos3f) \
    X(PFNGLRASTERPOS3FVPROC, glRasterPos3fv) \
    X(PFNGLRASTERPOS3IPROC, glRasterPos3i) \
    X(PFNGLRASTERPOS3IVPROC, glRasterPos3iv) \
    X(PFNGLRASTERPOS3SPROC, glRasterPos3s) \
    X(PFNGLRASTERPOS3SVPROC, glRasterPos3sv) \
    X(PFNGLRASTERPOS4DPROC, glRasterPos4d) \
    X(PFNGLRASTERPOS4DVPROC, glRasterPos4dv) \
    X(PFNGLRASTERPOS4FPROC, glRasterPos4f) \
    X(PFNGLRASTERPOS4FVPROC, glRasterPos4fv) \
    X(PFNGLRASTERPOS4IPROC, glRasterPos4i) \
    X(PFNGLRASTERPOS4IVPROC, glRasterPos4iv) \
    X(PFNGLRASTERPOS4SPROC, glRasterPos4s) \
    X(PFNGLRASTERPOS4SVPROC, glRasterPos4sv) \
    X(PFNGLRECTDPROC, glRectd) \
    X(PFNGLRECTDVPROC, glRectdv) \
    X(PFNGLRECTFPROC, glRectf) \
    X(PFNGLRECTFVPROC, glRectfv) \
    X(PFNGLRECTIPROC, glRecti) \
    X(PFNGLRECTIVPROC, glRectiv) \
    X(PFNGLRECTSPROC, glRects) \
    X(PFNGLRECTSVPROC, glRectsv) \
    X(PFNGLTEXCOORD1DPROC, glTexCoord1d) \
    X(PFNGLTEXCOORD1DVPROC, glTexCoord1dv) \
    X(PFNGLTEXCOORD1FPROC, glTexCoord1f) \
    X(PFNGLTEXCOORD1FVPROC, glTexCoord1fv) \
    X(PFNGLTEXCOORD1IPROC, glTexCoord1i) \
    X(PFNGLTEXCOORD1IVPROC, glTexCoord1iv) \
    X(PFNGLTEXCOORD1SPROC, glTexCoord1s) \
    X(PFNGLTEXCOORD1SVPROC, glTexCoord1sv) \
    X(PFNGLTEXCOORD2DPROC, glTexCoord2d) \
    X(PFNGLTEXCOORD2DVPROC, glTexCoord2dv) \
    X(PFNGLTEXCOORD2FPROC, glTexCoord2f) \
    X(PFNGLTEXCOORD2FVPROC, glTexCoord2fv) \
    X(PFNGLTEXCOORD2IPROC, glTexCoord2i) \
    X(PFNGLTEXCOORD2IVPROC, glTexCoord2iv) \
    X(PFNGLTEXCOORD2SPROC, glTexCoord2s) \
    X(PFNGLTEXCOORD2SVPROC, glTexCoord2sv) \
    X(PFNGLTEXCOORD3DPROC, glTexCoord3d) \
    X(PFNGLTEXCOORD3DVPROC, glTexCoord3dv) \
    X(PFNGLTEXCOORD3FPROC, glTexCoord3f) \
    X(PFNGLTEXCOORD3FVPROC, glTexCoord3fv) \
    X(PFNGLTEXCOORD3IPROC, glTexCoord3i) \
    X(PFNGLTEXCOORD3IVPROC, glTexCoord3iv) \
    X(PFNGLTEXCOORD3SPROC, glTexCoord3s) \
    X(PFNGLTEXCOORD3SVPROC, glTexCoord3sv) \
    X(PFNGLTEXCOORD4DPROC, glTexCoord4d) \
    X(PFNGLTEXCOORD4DVPROC, glTexCoord4dv) \
    X(PFNGLTEXCOORD4FPROC, glTexCoord4f) \
    X(PFNGLTEXCOORD4FVPROC, glTexCoord4fv) \
    X(PFNGLTEXCOORD4IPROC, glTexCoord4i) \
    X(PFNGLTEXCOORD4IVPROC, glTexCoord4iv) \
    X(PFNGLTEXCOORD4SPROC, glTexCoord4s) \
    X(PFNGLTEXCOORD4SVPROC, glTexCoord4sv) \
    X(PFNGLVERTEX2DPROC, glVertex2d) \
    X(PFNGLVERTEX2DVPROC, glVertex2dv) \
    X(PFNGLVERTEX2FPROC, glVertex2f) \
    X(PFNGLVERTEX2FVPROC, glVertex2fv) \
    X(PFNGLVERTEX2IPROC, glVertex2i) \
    X(PFNGLVERTEX2IVPROC, glVertex2iv) \
    X(PFNGLVERTEX2SPROC, glVertex2s) \
    X(PFNGLVERTEX2SVPROC, glVertex2sv) \
    X(PFNGLVERTEX3DPROC, glVertex3d) \
    X(PFNGLVERTEX3DVPROC, glVertex3dv) \
    X(PFNGLVERTEX3FPROC, glVertex3f) \
    X(PFNGLVERTEX3FVPROC, glVertex3fv) \
    X(PFNGLVERTEX3IPROC, glVertex3i) \
    X(PFNGLVERTEX3IVPROC, glVertex3iv) \
    X(PFNGLVERTEX3SPROC, glVertex3s) \
    X(PFNGLVERTEX3SVPROC, glVertex3sv) \
    X(PFNGLVERTEX4DPROC, glVertex4d) \
    X(PFNGLVERTEX4DVPROC, glVertex4dv) \
    X(PFNGLVERTEX4FPROC, glVertex4f) \
    X(PFNGLVERTEX4FVPROC, glVertex4fv) \
    X(PFNGLVERTEX4IPROC, glVertex4i) \
    X(PFNGLVERTEX4IVPROC, glVertex4iv) \
    X(PFNGLVERTEX4SPROC, glVertex4s) \
    X(PFNGLVERTEX4SVPROC, glVertex4sv) \
    X(PFNGLCLIPPLANEPROC, glClipPlane) \
    X(PFNGLCOLORMATERIALPROC, glColorMaterial) \
    X(PFNGLFOGFPROC, glFogf) \
    X(PFNGLFOGFVPROC, glFogfv) \
    X(PFNGLFOGIPROC, glFogi) \
    X(PFNGLFOGIVPROC, glFogiv) \
    X(PFNGLLIGHTFPROC, glLightf) \
    X(PFNGLLIGHTFVPROC, glLightfv) \
    X(PFNGLLIGHTIPROC, glLighti) \
    X(PFNGLLIGHTIVPROC, glLightiv) \
    X(PFNGLLIGHTMODELFPROC, glLightModelf) \
    X(PFNGLLIGHTMODELFVPROC, glLightModelfv) \
    X(PFNGLLIGHTMODELIPROC, glLightModeli) \
    X(PFNGLLIGHTMODELIVPROC, glLightModeliv) \
    X(PFNGLLINESTIPPLEPROC, glLineStipple) \
    X(PFNGLMATERIALFPROC, glMaterialf) \
    X(PFNGLMATERIALFVPROC, glMaterialfv) \
    X(PFNGLMATERIALIPROC, glMateriali) \
    X(PFNGLMATERIALIVPROC, glMaterialiv) \
    X(PFNGLPOLYGONSTIPPLEPROC, glPolygonStipple) \
    X(PFNGLSHADEMODELPROC, glShadeModel) \
    X(PFNGLTEXENVFPROC, glTexEnvf) \
    X(PFNGLTEXENVFVPROC, glTexEnvfv) \
    X(PFNGLTEXENVIPROC, glTexEnvi) \
    X(PFNGLTEXENVIVPROC, glTexEnviv) \
    X(PFNGLTEXGENDPROC, glTexGend) \
    X(PFNGLTEXGENDVPROC, glTexGendv) \
    X(PFNGLTEXGENFPROC, glTexGenf) \
    X(PFNGLTEXGENFVPROC, glTexGenfv) \
    X(PFNGLTEXGENIPROC, glTexGeni) \
    X(PFNGLTEXGENIVPROC, glTexGeniv) \
    X(PFNGLFEEDBACKBUFFERPROC, glFeedbackBuffer) \
    X(PFNGLSELECTBUFFERPROC, glSelectBuffer) \
    X(PFNGLRENDERMODEPROC, glRenderMode) \
    X(PFNGLINITNAMESPROC, glInitNames) \
    X(PFNGLLOADNAMEPROC, glLoadName) \
    X(PFNGLPASSTHROUGHPROC, glPassThrough) \
    X(PFNGLPOPNAMEPROC, glPopName) \
    X(PFNGLPUSHNAMEPROC, glPushName) \
    X(PFNGLCLEARACCUMPROC, glClearAccum) \
    X(PFNGLCLEARINDEXPROC, glClearIndex) \
    X(PFNGLINDEXMASKPROC, glIndexMask) \
    X(PFNGLACCUMPROC, glAccum) \
    X(PFNGLPOPATTRIBPROC, glPopAttrib) \
    X(PFNGLPUSHATTRIBPROC, glPushAttrib) \
    X(PFNGLMAP1DPROC, glMap1d) \
    X(PFNGLMAP1FPROC, glMap1f) \
    X(PFNGLMAP2DPROC, glMap2d) \
    X(PFNGLMAP2FPROC, glMap2f) \
    X(PFNGLMAPGRID1DPROC, glMapGrid1d) \
    X(PFNGLMAPGRID1FPROC, glMapGrid1f) \
    X(PFNGLMAPGRID2DPROC, glMapGrid2d) \
    X(PFNGLMAPGRID2FPROC, glMapGrid2f) \
    X(PFNGLEVALCOORD1DPROC, glEvalCoord1d) \
    X(PFNGLEVALCOORD1DVPROC, glEvalCoord1dv) \
    X(PFNGLEVALCOORD1FPROC, glEvalCoord1f) \
    X(PFNGLEVALCOORD1FVPROC, glEvalCoord1fv) \
    X(PFNGLEVALCOORD2DPROC, glEvalCoord2d) \
    X(PFNGLEVALCOORD2DVPROC, glEvalCoord2dv) \
    X(PFNGLEVALCOORD2FPROC, glEvalCoord2f) \
    X(PFNGLEVALCOORD2FVPROC, glEvalCoord2fv) \
    X(PFNGLEVALMESH1PROC, glEvalMesh1) \
    X(PFNGLEVALPOINT1PROC, glEvalPoint1) \
    X(PFNGLEVALMESH2PROC, glEvalMesh2) \
    X(PFNGLEVALPOINT2PROC, glEvalPoint2) \
    X(PFNGLALPHAFUNCPROC, glAlphaFunc) \
    X(PFNGLPIXELZOOMPROC, glPixelZoom) \
    X(PFNGLPIXELTRANSFERFPROC, glPixelTransferf) \
    X(PFNGLPIXELTRANSFERIPROC, glPixelTransferi) \
    X(PFNGLPIXELMAPFVPROC, glPixelMapfv) \
    X(PFNGLPIXELMAPUIVPROC, glPixelMapuiv) \
    X(PFNGLPIXELMAPUSVPROC, glPixelMapusv) \
    X(PFNGLCOPYPIXELSPROC, glCopyPixels) \
    X(PFNGLDRAWPIXELSPROC, glDrawPixels) \
    X(PFNGLGETCLIPPLANEPROC, glGetClipPlane) \
    X(PFNGLGETLIGHTFVPROC, glGetLightfv) \
    X(PFNGLGETLIGHTIVPROC, glGetLightiv) \
    X(PFNGLGETMAPDVPROC, glGetMapdv) \
    X(PFNGLGETMAPFVPROC, glGetMapfv) \
    X(PFNGLGETMAPIVPROC, glGetMapiv) \
    X(PFNGLGETMATERIALFVPROC, glGetMaterialfv) \
    X(PFNGLGETMATERIALIVPROC, glGetMaterialiv) \
    X(PFNGLGETPIXELMAPFVPROC, glGetPixelMapfv) \
    X(PFNGLGETPIXELMAPUIVPROC, glGetPixelMapuiv) \
    X(PFNGLGETPIXELMAPUSVPROC, glGetPixelMapusv) \
    X(PFNGLGETPOLYGONSTIPPLEPROC, glGetPolygonStipple) \
    X(PFNGLGETTEXENVFVPROC, glGetTexEnvfv) \
    X(PFNGLGETTEXENVIVPROC, glGetTexEnviv) \
    X(PFNGLGETTEXGENDVPROC, glGetTexGendv) \
    X(PFNGLGETTEXGENFVPROC, glGetTexGenfv) \
    X(PFNGLGETTEXGENIVPROC, glGetTexGeniv) \
    X(PFNGLISLISTPROC, glIsList) \
    X(PFNGLFRUSTUMPROC, glFrustum) \
    X(PFNGLLOADIDENTITYPROC, glLoadIdentity) \
    X(PFNGLLOADMATRIXFPROC, glLoadMatrixf) \
    X(PFNGLLOADMATRIXDPROC, glLoadMatrixd) \
    X(PFNGLMATRIXMODEPROC, glMatrixMode) \
    X(PFNGLMULTMATRIXFPROC, glMultMatrixf) \
    X(PFNGLMULTMATRIXDPROC, glMultMatrixd) \
    X(PFNGLORTHOPROC, glOrtho) \
    X(PFNGLPOPMATRIXPROC, glPopMatrix) \
    X(PFNGLPUSHMATRIXPROC, glPushMatrix) \
    X(PFNGLROTATEDPROC, glRotated) \
    X(PFNGLROTATEFPROC, glRotatef) \
    X(PFNGLSCALEDPROC, glScaled) \
    X(PFNGLSCALEFPROC, glScalef) \
    X(PFNGLTRANSLATEDPROC, glTranslated) \
    X(PFNGLTRANSLATEFPROC, glTranslatef) \

#define GL_FUNCTIONS_1_1 \
    X(PFNGLDRAWARRAYSPROC, glDrawArrays) \
    X(PFNGLDRAWELEMENTSPROC, glDrawElements) \
    X(PFNGLGETPOINTERVPROC, glGetPointerv) \
    X(PFNGLPOLYGONOFFSETPROC, glPolygonOffset) \
    X(PFNGLCOPYTEXIMAGE1DPROC, glCopyTexImage1D) \
    X(PFNGLCOPYTEXIMAGE2DPROC, glCopyTexImage2D) \
    X(PFNGLCOPYTEXSUBIMAGE1DPROC, glCopyTexSubImage1D) \
    X(PFNGLCOPYTEXSUBIMAGE2DPROC, glCopyTexSubImage2D) \
    X(PFNGLTEXSUBIMAGE1DPROC, glTexSubImage1D) \
    X(PFNGLTEXSUBIMAGE2DPROC, glTexSubImage2D) \
    X(PFNGLBINDTEXTUREPROC, glBindTexture) \
    X(PFNGLDELETETEXTURESPROC, glDeleteTextures) \
    X(PFNGLGENTEXTURESPROC, glGenTextures) \
    X(PFNGLISTEXTUREPROC, glIsTexture) \
    X(PFNGLARRAYELEMENTPROC, glArrayElement) \
    X(PFNGLCOLORPOINTERPROC, glColorPointer) \
    X(PFNGLDISABLECLIENTSTATEPROC, glDisableClientState) \
    X(PFNGLEDGEFLAGPOINTERPROC, glEdgeFlagPointer) \
    X(PFNGLENABLECLIENTSTATEPROC, glEnableClientState) \
    X(PFNGLINDEXPOINTERPROC, glIndexPointer) \
    X(PFNGLINTERLEAVEDARRAYSPROC, glInterleavedArrays) \
    X(PFNGLNORMALPOINTERPROC, glNormalPointer) \
    X(PFNGLTEXCOORDPOINTERPROC, glTexCoordPointer) \
    X(PFNGLVERTEXPOINTERPROC, glVertexPointer) \
    X(PFNGLARETEXTURESRESIDENTPROC, glAreTexturesResident) \
    X(PFNGLPRIORITIZETEXTURESPROC, glPrioritizeTextures) \
    X(PFNGLINDEXUBPROC, glIndexub) \
    X(PFNGLINDEXUBVPROC, glIndexubv) \
    X(PFNGLPOPCLIENTATTRIBPROC, glPopClientAttrib) \
    X(PFNGLPUSHCLIENTATTRIBPROC, glPushClientAttrib) \

#define GL_FUNCTIONS_1_2 \
    X(PFNGLDRAWRANGEELEMENTSPROC, glDrawRangeElements) \
    X(PFNGLTEXIMAGE3DPROC, glTexImage3D) \
    X(PFNGLTEXSUBIMAGE3DPROC, glTexSubImage3D) \
    X(PFNGLCOPYTEXSUBIMAGE3DPROC, glCopyTexSubImage3D) \

#define GL_FUNCTIONS_1_3 \
    X(PFNGLACTIVETEXTUREPROC, glActiveTexture) \
    X(PFNGLSAMPLECOVERAGEPROC, glSampleCoverage) \
    X(PFNGLCOMPRESSEDTEXIMAGE3DPROC, glCompressedTexImage3D) \
    X(PFNGLCOMPRESSEDTEXIMAGE2DPROC, glCompressedTexImage2D) \
    X(PFNGLCOMPRESSEDTEXIMAGE1DPROC, glCompressedTexImage1D) \
    X(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC, glCompressedTexSubImage3D) \
    X(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, glCompressedTexSubImage2D) \
    X(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC, glCompressedTexSubImage1D) \
    X(PFNGLGETCOMPRESSEDTEXIMAGEPROC, glGetCompressedTexImage) \
    X(PFNGLCLIENTACTIVETEXTUREPROC, glClientActiveTexture) \
    X(PFNGLMULTITEXCOORD1DPROC, glMultiTexCoord1d) \
    X(PFNGLMULTITEXCOORD1DVPROC, glMultiTexCoord1dv) \
    X(PFNGLMULTITEXCOORD1FPROC, glMultiTexCoord1f) \
    X(PFNGLMULTITEXCOORD1FVPROC, glMultiTexCoord1fv) \
    X(PFNGLMULTITEXCOORD1IPROC, glMultiTexCoord1i) \
    X(PFNGLMULTITEXCOORD1IVPROC, glMultiTexCoord1iv) \
    X(PFNGLMULTITEXCOORD1SPROC, glMultiTexCoord1s) \
    X(PFNGLMULTITEXCOORD1SVPROC, glMultiTexCoord1sv) \
    X(PFNGLMULTITEXCOORD2DPROC, glMultiTexCoord2d) \
    X(PFNGLMULTITEXCOORD2DVPROC, glMultiTexCoord2dv) \
    X(PFNGLMULTITEXCOORD2FPROC, glMultiTexCoord2f) \
    X(PFNGLMULTITEXCOORD2FVPROC, glMultiTexCoord2fv) \
    X(PFNGLMULTITEXCOORD2IPROC, glMultiTexCoord2i) \
    X(PFNGLMULTITEXCOORD2IVPROC, glMultiTexCoord2iv) \
    X(PFNGLMULTITEXCOORD2SPROC, glMultiTexCoord2s) \
    X(PFNGLMULTITEXCOORD2SVPROC, glMultiTexCoord2sv) \
    X(PFNGLMULTITEXCOORD3DPROC, glMultiTexCoord3d) \
    X(PFNGLMULTITEXCOORD3DVPROC, glMultiTexCoord3dv) \
    X(PFNGLMULTITEXCOORD3FPROC, glMultiTexCoord3f) \
    X(PFNGLMULTITEXCOORD3FVPROC, glMultiTexCoord3fv) \
    X(PFNGLMULTITEXCOORD3IPROC, glMultiTexCoord3i) \
    X(PFNGLMULTITEXCOORD3IVPROC, glMultiTexCoord3iv) \
    X(PFNGLMULTITEXCOORD3SPROC, glMultiTexCoord3s) \
    X(PFNGLMULTITEXCOORD3SVPROC, glMultiTexCoord3sv) \
    X(PFNGLMULTITEXCOORD4DPROC, glMultiTexCoord4d) \
    X(PFNGLMULTITEXCOORD4DVPROC, glMultiTexCoord4dv) \
    X(PFNGLMULTITEXCOORD4FPROC, glMultiTexCoord4f) \
    X(PFNGLMULTITEXCOORD4FVPROC, glMultiTexCoord4fv) \
    X(PFNGLMULTITEXCOORD4IPROC, glMultiTexCoord4i) \
    X(PFNGLMULTITEXCOORD4IVPROC, glMultiTexCoord4iv) \
    X(PFNGLMULTITEXCOORD4SPROC, glMultiTexCoord4s) \
    X(PFNGLMULTITEXCOORD4SVPROC, glMultiTexCoord4sv) \
    X(PFNGLLOADTRANSPOSEMATRIXFPROC, glLoadTransposeMatrixf) \
    X(PFNGLLOADTRANSPOSEMATRIXDPROC, glLoadTransposeMatrixd) \
    X(PFNGLMULTTRANSPOSEMATRIXFPROC, glMultTransposeMatrixf) \
    X(PFNGLMULTTRANSPOSEMATRIXDPROC, glMultTransposeMatrixd) \

#define GL_FUNCTIONS_1_4 \
    X(PFNGLBLENDFUNCSEPARATEPROC, glBlendFuncSeparate) \
    X(PFNGLMULTIDRAWARRAYSPROC, glMultiDrawArrays) \
    X(PFNGLMULTIDRAWELEMENTSPROC, glMultiDrawElements) \
    X(PFNGLPOINTPARAMETERFPROC, glPointParameterf) \
    X(PFNGLPOINTPARAMETERFVPROC, glPointParameterfv) \
    X(PFNGLPOINTPARAMETERIPROC, glPointParameteri) \
    X(PFNGLPOINTPARAMETERIVPROC, glPointParameteriv) \
    X(PFNGLFOGCOORDFPROC, glFogCoordf) \
    X(PFNGLFOGCOORDFVPROC, glFogCoordfv) \
    X(PFNGLFOGCOORDDPROC, glFogCoordd) \
    X(PFNGLFOGCOORDDVPROC, glFogCoorddv) \
    X(PFNGLFOGCOORDPOINTERPROC, glFogCoordPointer) \
    X(PFNGLSECONDARYCOLOR3BPROC, glSecondaryColor3b) \
    X(PFNGLSECONDARYCOLOR3BVPROC, glSecondaryColor3bv) \
    X(PFNGLSECONDARYCOLOR3DPROC, glSecondaryColor3d) \
    X(PFNGLSECONDARYCOLOR3DVPROC, glSecondaryColor3dv) \
    X(PFNGLSECONDARYCOLOR3FPROC, glSecondaryColor3f) \
    X(PFNGLSECONDARYCOLOR3FVPROC, glSecondaryColor3fv) \
    X(PFNGLSECONDARYCOLOR3IPROC, glSecondaryColor3i) \
    X(PFNGLSECONDARYCOLOR3IVPROC, glSecondaryColor3iv) \
    X(PFNGLSECONDARYCOLOR3SPROC, glSecondaryColor3s) \
    X(PFNGLSECONDARYCOLOR3SVPROC, glSecondaryColor3sv) \
    X(PFNGLSECONDARYCOLOR3UBPROC, glSecondaryColor3ub) \
    X(PFNGLSECONDARYCOLOR3UBVPROC, glSecondaryColor3ubv) \
    X(PFNGLSECONDARYCOLOR3UIPROC, glSecondaryColor3ui) \
    X(PFNGLSECONDARYCOLOR3UIVPROC, glSecondaryColor3uiv) \
    X(PFNGLSECONDARYCOLOR3USPROC, glSecondaryColor3us) \
    X(PFNGLSECONDARYCOLOR3USVPROC, glSecondaryColor3usv) \
    X(PFNGLSECONDARYCOLORPOINTERPROC, glSecondaryColorPointer) \
    X(PFNGLWINDOWPOS2DPROC, glWindowPos2d) \
    X(PFNGLWINDOWPOS2DVPROC, glWindowPos2dv) \
    X(PFNGLWINDOWPOS2FPROC, glWindowPos2f) \
    X(PFNGLWINDOWPOS2FVPROC, glWindowPos2fv) \
    X(PFNGLWINDOWPOS2IPROC, glWindowPos2i) \
    X(PFNGLWINDOWPOS2IVPROC, glWindowPos2iv) \
    X(PFNGLWINDOWPOS2SPROC, glWindowPos2s) \
    X(PFNGLWINDOWPOS2SVPROC, glWindowPos2sv) \
    X(PFNGLWINDOWPOS3DPROC, glWindowPos3d) \
    X(PFNGLWINDOWPOS3DVPROC, glWindowPos3dv) \
    X(PFNGLWINDOWPOS3FPROC, glWindowPos3f) \
    X(PFNGLWINDOWPOS3FVPROC, glWindowPos3fv) \
    X(PFNGLWINDOWPOS3IPROC, glWindowPos3i) \
    X(PFNGLWINDOWPOS3IVPROC, glWindowPos3iv) \
    X(PFNGLWINDOWPOS3SPROC, glWindowPos3s) \
    X(PFNGLWINDOWPOS3SVPROC, glWindowPos3sv) \
    X(PFNGLBLENDCOLORPROC, glBlendColor) \
    X(PFNGLBLENDEQUATIONPROC, glBlendEquation) \

#define GL_FUNCTIONS_1_5 \
    X(PFNGLGENQUERIESPROC, glGenQueries) \
    X(PFNGLDELETEQUERIESPROC, glDeleteQueries) \
    X(PFNGLISQUERYPROC, glIsQuery) \
    X(PFNGLBEGINQUERYPROC, glBeginQuery) \
    X(PFNGLENDQUERYPROC, glEndQuery) \
    X(PFNGLGETQUERYIVPROC, glGetQueryiv) \
    X(PFNGLGETQUERYOBJECTIVPROC, glGetQueryObjectiv) \
    X(PFNGLGETQUERYOBJECTUIVPROC, glGetQueryObjectuiv) \
    X(PFNGLBINDBUFFERPROC, glBindBuffer) \
    X(PFNGLDELETEBUFFERSPROC, glDeleteBuffers) \
    X(PFNGLGENBUFFERSPROC, glGenBuffers) \
    X(PFNGLISBUFFERPROC, glIsBuffer) \
    X(PFNGLBUFFERDATAPROC, glBufferData) \
    X(PFNGLBUFFERSUBDATAPROC, glBufferSubData) \
    X(PFNGLGETBUFFERSUBDATAPROC, glGetBufferSubData) \
    X(PFNGLMAPBUFFERPROC, glMapBuffer) \
    X(PFNGLUNMAPBUFFERPROC, glUnmapBuffer) \
    X(PFNGLGETBUFFERPARAMETERIVPROC, glGetBufferParameteriv) \
    X(PFNGLGETBUFFERPOINTERVPROC, glGetBufferPointerv) \

#define GL_FUNCTIONS_2_0 \
    X(PFNGLBLENDEQUATIONSEPARATEPROC, glBlendEquationSeparate) \
    X(PFNGLDRAWBUFFERSPROC, glDrawBuffers) \
    X(PFNGLSTENCILOPSEPARATEPROC, glStencilOpSeparate) \
    X(PFNGLSTENCILFUNCSEPARATEPROC, glStencilFuncSeparate) \
    X(PFNGLSTENCILMASKSEPARATEPROC, glStencilMaskSeparate) \
    X(PFNGLATTACHSHADERPROC, glAttachShader) \
    X(PFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation) \
    X(PFNGLCOMPILESHADERPROC, glCompileShader) \
    X(PFNGLCREATEPROGRAMPROC, glCreateProgram) \
    X(PFNGLCREATESHADERPROC, glCreateShader) \
    X(PFNGLDELETEPROGRAMPROC, glDeleteProgram) \
    X(PFNGLDELETESHADERPROC, glDeleteShader) \
    X(PFNGLDETACHSHADERPROC, glDetachShader) \
    X(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray) \
    X(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray) \
    X(PFNGLGETACTIVEATTRIBPROC, glGetActiveAttrib) \
    X(PFNGLGETACTIVEUNIFORMPROC, glGetActiveUniform) \
    X(PFNGLGETATTACHEDSHADERSPROC, glGetAttachedShaders) \
    X(PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation) \
    X(PFNGLGETPROGRAMIVPROC, glGetProgramiv) \
    X(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog) \
    X(PFNGLGETSHADERIVPROC, glGetShaderiv) \
    X(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog) \
    X(PFNGLGETSHADERSOURCEPROC, glGetShaderSource) \
    X(PFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation) \
    X(PFNGLGETUNIFORMFVPROC, glGetUniformfv) \
    X(PFNGLGETUNIFORMIVPROC, glGetUniformiv) \
    X(PFNGLGETVERTEXATTRIBDVPROC, glGetVertexAttribdv) \
    X(PFNGLGETVERTEXATTRIBFVPROC, glGetVertexAttribfv) \
    X(PFNGLGETVERTEXATTRIBIVPROC, glGetVertexAttribiv) \
    X(PFNGLGETVERTEXATTRIBPOINTERVPROC, glGetVertexAttribPointerv) \
    X(PFNGLISPROGRAMPROC, glIsProgram) \
    X(PFNGLISSHADERPROC, glIsShader) \
    X(PFNGLLINKPROGRAMPROC, glLinkProgram) \
    X(PFNGLSHADERSOURCEPROC, glShaderSource) \
    X(PFNGLUSEPROGRAMPROC, glUseProgram) \
    X(PFNGLUNIFORM1FPROC, glUniform1f) \
    X(PFNGLUNIFORM2FPROC, glUniform2f) \
    X(PFNGLUNIFORM3FPROC, glUniform3f) \
    X(PFNGLUNIFORM4FPROC, glUniform4f) \
    X(PFNGLUNIFORM1IPROC, glUniform1i) \
    X(PFNGLUNIFORM2IPROC, glUniform2i) \
    X(PFNGLUNIFORM3IPROC, glUniform3i) \
    X(PFNGLUNIFORM4IPROC, glUniform4i) \
    X(PFNGLUNIFORM1FVPROC, glUniform1fv) \
    X(PFNGLUNIFORM2FVPROC, glUniform2fv) \
    X(PFNGLUNIFORM3FVPROC, glUniform3fv) \
    X(PFNGLUNIFORM4FVPROC, glUniform4fv) \
    X(PFNGLUNIFORM1IVPROC, glUniform1iv) \
    X(PFNGLUNIFORM2IVPROC, glUniform2iv) \
    X(PFNGLUNIFORM3IVPROC, glUniform3iv) \
    X(PFNGLUNIFORM4IVPROC, glUniform4iv) \
    X(PFNGLUNIFORMMATRIX2FVPROC, glUniformMatrix2fv) \
    X(PFNGLUNIFORMMATRIX3FVPROC, glUniformMatrix3fv) \
    X(PFNGLUNIFORMMATRIX4FVPROC, glUniformMatrix4fv) \
    X(PFNGLVALIDATEPROGRAMPROC, glValidateProgram) \
    X(PFNGLVERTEXATTRIB1DPROC, glVertexAttrib1d) \
    X(PFNGLVERTEXATTRIB1DVPROC, glVertexAttrib1dv) \
    X(PFNGLVERTEXATTRIB1FPROC, glVertexAttrib1f) \
    X(PFNGLVERTEXATTRIB1FVPROC, glVertexAttrib1fv) \
    X(PFNGLVERTEXATTRIB1SPROC, glVertexAttrib1s) \
    X(PFNGLVERTEXATTRIB1SVPROC, glVertexAttrib1sv) \
    X(PFNGLVERTEXATTRIB2DPROC, glVertexAttrib2d) \
    X(PFNGLVERTEXATTRIB2DVPROC, glVertexAttrib2dv) \
    X(PFNGLVERTEXATTRIB2FPROC, glVertexAttrib2f) \
    X(PFNGLVERTEXATTRIB2FVPROC, glVertexAttrib2fv) \
    X(PFNGLVERTEXATTRIB2SPROC, glVertexAttrib2s) \
    X(PFNGLVERTEXATTRIB2SVPROC, glVertexAttrib2sv) \
    X(PFNGLVERTEXATTRIB3DPROC, glVertexAttrib3d) \
    X(PFNGLVERTEXATTRIB3DVPROC, glVertexAttrib3dv) \
    X(PFNGLVERTEXATTRIB3FPROC, glVertexAttrib3f) \
    X(PFNGLVERTEXATTRIB3FVPROC, glVertexAttrib3fv) \
    X(PFNGLVERTEXATTRIB3SPROC, glVertexAttrib3s) \
    X(PFNGLVERTEXATTRIB3SVPROC, glVertexAttrib3sv) \
    X(PFNGLVERTEXATTRIB4NBVPROC, glVertexAttrib4Nbv) \
    X(PFNGLVERTEXATTRIB4NIVPROC, glVertexAttrib4Niv) \
    X(PFNGLVERTEXATTRIB4NSVPROC, glVertexAttrib4Nsv) \
    X(PFNGLVERTEXATTRIB4NUBPROC, glVertexAttrib4Nub) \
    X(PFNGLVERTEXATTRIB4NUBVPROC, glVertexAttrib4Nubv) \
    X(PFNGLVERTEXATTRIB4NUIVPROC, glVertexAttrib4Nuiv) \
    X(PFNGLVERTEXATTRIB4NUSVPROC, glVertexAttrib4Nusv) \
    X(PFNGLVERTEXATTRIB4BVPROC, glVertexAttrib4bv) \
    X(PFNGLVERTEXATTRIB4DPROC, glVertexAttrib4d) \
    X(PFNGLVERTEXATTRIB4DVPROC, glVertexAttrib4dv) \
    X(PFNGLVERTEXATTRIB4FPROC, glVertexAttrib4f) \
    X(PFNGLVERTEXATTRIB4FVPROC, glVertexAttrib4fv) \
    X(PFNGLVERTEXATTRIB4IVPROC, glVertexAttrib4iv) \
    X(PFNGLVERTEXATTRIB4SPROC, glVertexAttrib4s) \
    X(PFNGLVERTEXATTRIB4SVPROC, glVertexAttrib4sv) \
    X(PFNGLVERTEXATTRIB4UBVPROC, glVertexAttrib4ubv) \
    X(PFNGLVERTEXATTRIB4UIVPROC, glVertexAttrib4uiv) \
    X(PFNGLVERTEXATTRIB4USVPROC, glVertexAttrib4usv) \
    X(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer) \

#define GL_FUNCTIONS_2_1 \
    X(PFNGLUNIFORMMATRIX2X3FVPROC, glUniformMatrix2x3fv) \
    X(PFNGLUNIFORMMATRIX3X2FVPROC, glUniformMatrix3x2fv) \
    X(PFNGLUNIFORMMATRIX2X4FVPROC, glUniformMatrix2x4fv) \
    X(PFNGLUNIFORMMATRIX4X2FVPROC, glUniformMatrix4x2fv) \
    X(PFNGLUNIFORMMATRIX3X4FVPROC, glUniformMatrix3x4fv) \
    X(PFNGLUNIFORMMATRIX4X3FVPROC, glUniformMatrix4x3fv) \

#define GL_FUNCTIONS_3_0 \
    X(PFNGLCOLORMASKIPROC, glColorMaski) \
    X(PFNGLGETBOOLEANI_VPROC, glGetBooleani_v) \
    X(PFNGLGETINTEGERI_VPROC, glGetIntegeri_v) \
    X(PFNGLENABLEIPROC, glEnablei) \
    X(PFNGLDISABLEIPROC, glDisablei) \
    X(PFNGLISENABLEDIPROC, glIsEnabledi) \
    X(PFNGLBEGINTRANSFORMFEEDBACKPROC, glBeginTransformFeedback) \
    X(PFNGLENDTRANSFORMFEEDBACKPROC, glEndTransformFeedback) \
    X(PFNGLBINDBUFFERRANGEPROC, glBindBufferRange) \
    X(PFNGLBINDBUFFERBASEPROC, glBindBufferBase) \
    X(PFNGLTRANSFORMFEEDBACKVARYINGSPROC, glTransformFeedbackVaryings) \
    X(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC, glGetTransformFeedbackVarying) \
    X(PFNGLCLAMPCOLORPROC, glClampColor) \
    X(PFNGLBEGINCONDITIONALRENDERPROC, glBeginConditionalRender) \
    X(PFNGLENDCONDITIONALRENDERPROC, glEndConditionalRender) \
    X(PFNGLVERTEXATTRIBIPOINTERPROC, glVertexAttribIPointer) \
    X(PFNGLGETVERTEXATTRIBIIVPROC, glGetVertexAttribIiv) \
    X(PFNGLGETVERTEXATTRIBIUIVPROC, glGetVertexAttribIuiv) \
    X(PFNGLVERTEXATTRIBI1IPROC, glVertexAttribI1i) \
    X(PFNGLVERTEXATTRIBI2IPROC, glVertexAttribI2i) \
    X(PFNGLVERTEXATTRIBI3IPROC, glVertexAttribI3i) \
    X(PFNGLVERTEXATTRIBI4IPROC, glVertexAttribI4i) \
    X(PFNGLVERTEXATTRIBI1UIPROC, glVertexAttribI1ui) \
    X(PFNGLVERTEXATTRIBI2UIPROC, glVertexAttribI2ui) \
    X(PFNGLVERTEXATTRIBI3UIPROC, glVertexAttribI3ui) \
    X(PFNGLVERTEXATTRIBI4UIPROC, glVertexAttribI4ui) \
    X(PFNGLVERTEXATTRIBI1IVPROC, glVertexAttribI1iv) \
    X(PFNGLVERTEXATTRIBI2IVPROC, glVertexAttribI2iv) \
    X(PFNGLVERTEXATTRIBI3IVPROC, glVertexAttribI3iv) \
    X(PFNGLVERTEXATTRIBI4IVPROC, glVertexAttribI4iv) \
    X(PFNGLVERTEXATTRIBI1UIVPROC, glVertexAttribI1uiv) \
    X(PFNGLVERTEXATTRIBI2UIVPROC, glVertexAttribI2uiv) \
    X(PFNGLVERTEXATTRIBI3UIVPROC, glVertexAttribI3uiv) \
    X(PFNGLVERTEXATTRIBI4UIVPROC, glVertexAttribI4uiv) \
    X(PFNGLVERTEXATTRIBI4BVPROC, glVertexAttribI4bv) \
    X(PFNGLVERTEXATTRIBI4SVPROC, glVertexAttribI4sv) \
    X(PFNGLVERTEXATTRIBI4UBVPROC, glVertexAttribI4ubv) \
    X(PFNGLVERTEXATTRIBI4USVPROC, glVertexAttribI4usv) \
    X(PFNGLGETUNIFORMUIVPROC, glGetUniformuiv) \
    X(PFNGLBINDFRAGDATALOCATIONPROC, glBindFragDataLocation) \
    X(PFNGLGETFRAGDATALOCATIONPROC, glGetFragDataLocation) \
    X(PFNGLUNIFORM1UIPROC, glUniform1ui) \
    X(PFNGLUNIFORM2UIPROC, glUniform2ui) \
    X(PFNGLUNIFORM3UIPROC, glUniform3ui) \
    X(PFNGLUNIFORM4UIPROC, glUniform4ui) \
    X(PFNGLUNIFORM1UIVPROC, glUniform1uiv) \
    X(PFNGLUNIFORM2UIVPROC, glUniform2uiv) \
    X(PFNGLUNIFORM3UIVPROC, glUniform3uiv) \
    X(PFNGLUNIFORM4UIVPROC, glUniform4uiv) \
    X(PFNGLTEXPARAMETERIIVPROC, glTexParameterIiv) \
    X(PFNGLTEXPARAMETERIUIVPROC, glTexParameterIuiv) \
    X(PFNGLGETTEXPARAMETERIIVPROC, glGetTexParameterIiv) \
    X(PFNGLGETTEXPARAMETERIUIVPROC, glGetTexParameterIuiv) \
    X(PFNGLCLEARBUFFERIVPROC, glClearBufferiv) \
    X(PFNGLCLEARBUFFERUIVPROC, glClearBufferuiv) \
    X(PFNGLCLEARBUFFERFVPROC, glClearBufferfv) \
    X(PFNGLCLEARBUFFERFIPROC, glClearBufferfi) \
    X(PFNGLGETSTRINGIPROC, glGetStringi) \
    X(PFNGLISRENDERBUFFERPROC, glIsRenderbuffer) \
    X(PFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer) \
    X(PFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffers) \
    X(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers) \
    X(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage) \
    X(PFNGLGETRENDERBUFFERPARAMETERIVPROC, glGetRenderbufferParameteriv) \
    X(PFNGLISFRAMEBUFFERPROC, glIsFramebuffer) \
    X(PFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer) \
    X(PFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers) \
    X(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers) \
    X(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus) \
    X(PFNGLFRAMEBUFFERTEXTURE1DPROC, glFramebufferTexture1D) \
    X(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D) \
    X(PFNGLFRAMEBUFFERTEXTURE3DPROC, glFramebufferTexture3D) \
    X(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer) \
    X(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetFramebufferAttachmentParameteriv) \
    X(PFNGLGENERATEMIPMAPPROC, glGenerateMipmap) \
    X(PFNGLBLITFRAMEBUFFERPROC, glBlitFramebuffer) \
    X(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, glRenderbufferStorageMultisample) \
    X(PFNGLFRAMEBUFFERTEXTURELAYERPROC, glFramebufferTextureLayer) \
    X(PFNGLMAPBUFFERRANGEPROC, glMapBufferRange) \
    X(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, glFlushMappedBufferRange) \
    X(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray) \
    X(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays) \
    X(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays) \
    X(PFNGLISVERTEXARRAYPROC, glIsVertexArray) \

#define GL_FUNCTIONS_3_1 \
    X(PFNGLDRAWARRAYSINSTANCEDPROC, glDrawArraysInstanced) \
    X(PFNGLDRAWELEMENTSINSTANCEDPROC, glDrawElementsInstanced) \
    X(PFNGLTEXBUFFERPROC, glTexBuffer) \
    X(PFNGLPRIMITIVERESTARTINDEXPROC, glPrimitiveRestartIndex) \
    X(PFNGLCOPYBUFFERSUBDATAPROC, glCopyBufferSubData) \
    X(PFNGLGETUNIFORMINDICESPROC, glGetUniformIndices) \
    X(PFNGLGETACTIVEUNIFORMSIVPROC, glGetActiveUniformsiv) \
    X(PFNGLGETACTIVEUNIFORMNAMEPROC, glGetActiveUniformName) \
    X(PFNGLGETUNIFORMBLOCKINDEXPROC, glGetUniformBlockIndex) \
    X(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, glGetActiveUniformBlockiv) \
    X(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, glGetActiveUniformBlockName) \
    X(PFNGLUNIFORMBLOCKBINDINGPROC, glUniformBlockBinding) \

#define GL_FUNCTIONS_3_2 \
    X(PFNGLDRAWELEMENTSBASEVERTEXPROC, glDrawElementsBaseVertex) \
    X(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC, glDrawRangeElementsBaseVertex) \
    X(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, glDrawElementsInstancedBaseVertex) \
    X(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC, glMultiDrawElementsBaseVertex) \
    X(PFNGLPROVOKINGVERTEXPROC, glProvokingVertex) \
    X(PFNGLFENCESYNCPROC, glFenceSync) \
    X(PFNGLISSYNCPROC, glIsSync) \
    X(PFNGLDELETESYNCPROC, glDeleteSync) \
    X(PFNGLCLIENTWAITSYNCPROC, glClientWaitSync) \
    X(PFNGLWAITSYNCPROC, glWaitSync) \
    X(PFNGLGETINTEGER64VPROC, glGetInteger64v) \
    X(PFNGLGETSYNCIVPROC, glGetSynciv) \
    X(PFNGLGETINTEGER64I_VPROC, glGetInteger64i_v) \
    X(PFNGLGETBUFFERPARAMETERI64VPROC, glGetBufferParameteri64v) \
    X(PFNGLFRAMEBUFFERTEXTUREPROC, glFramebufferTexture) \
    X(PFNGLTEXIMAGE2DMULTISAMPLEPROC, glTexImage2DMultisample) \
    X(PFNGLTEXIMAGE3DMULTISAMPLEPROC, glTexImage3DMultisample) \
    X(PFNGLGETMULTISAMPLEFVPROC, glGetMultisamplefv) \
    X(PFNGLSAMPLEMASKIPROC, glSampleMaski) \

#define GL_FUNCTIONS_3_3 \
    X(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC, glBindFragDataLocationIndexed) \
    X(PFNGLGETFRAGDATAINDEXPROC, glGetFragDataIndex) \
    X(PFNGLGENSAMPLERSPROC, glGenSamplers) \
    X(PFNGLDELETESAMPLERSPROC, glDeleteSamplers) \
    X(PFNGLISSAMPLERPROC, glIsSampler) \
    X(PFNGLBINDSAMPLERPROC, glBindSampler) \
    X(PFNGLSAMPLERPARAMETERIPROC, glSamplerParameteri) \
    X(PFNGLSAMPLERPARAMETERIVPROC, glSamplerParameteriv) \
    X(PFNGLSAMPLERPARAMETERFPROC, glSamplerParameterf) \
    X(PFNGLSAMPLERPARAMETERFVPROC, glSamplerParameterfv) \
    X(PFNGLSAMPLERPARAMETERIIVPROC, glSamplerParameterIiv) \
    X(PFNGLSAMPLERPARAMETERIUIVPROC, glSamplerParameterIuiv) \
    X(PFNGLGETSAMPLERPARAMETERIVPROC, glGetSamplerParameteriv) \
    X(PFNGLGETSAMPLERPARAMETERIIVPROC, glGetSamplerParameterIiv) \
    X(PFNGLGETSAMPLERPARAMETERFVPROC, glGetSamplerParameterfv) \
    X(PFNGLGETSAMPLERPARAMETERIUIVPROC, glGetSamplerParameterIuiv) \
    X(PFNGLQUERYCOUNTERPROC, glQueryCounter) \
    X(PFNGLGETQUERYOBJECTI64VPROC, glGetQueryObjecti64v) \
    X(PFNGLGETQUERYOBJECTUI64VPROC, glGetQueryObjectui64v) \
    X(PFNGLVERTEXATTRIBDIVISORPROC, glVertexAttribDivisor) \
    X(PFNGLVERTEXATTRIBP1UIPROC, glVertexAttribP1ui) \
    X(PFNGLVERTEXATTRIBP1UIVPROC, glVertexAttribP1uiv) \
    X(PFNGLVERTEXATTRIBP2UIPROC, glVertexAttribP2ui) \
    X(PFNGLVERTEXATTRIBP2UIVPROC, glVertexAttribP2uiv) \
    X(PFNGLVERTEXATTRIBP3UIPROC, glVertexAttribP3ui) \
    X(PFNGLVERTEXATTRIBP3UIVPROC, glVertexAttribP3uiv) \
    X(PFNGLVERTEXATTRIBP4UIPROC, glVertexAttribP4ui) \
    X(PFNGLVERTEXATTRIBP4UIVPROC, glVertexAttribP4uiv) \
    X(PFNGLVERTEXP2UIPROC, glVertexP2ui) \
    X(PFNGLVERTEXP2UIVPROC, glVertexP2uiv) \
    X(PFNGLVERTEXP3UIPROC, glVertexP3ui) \
    X(PFNGLVERTEXP3UIVPROC, glVertexP3uiv) \
    X(PFNGLVERTEXP4UIPROC, glVertexP4ui) \
    X(PFNGLVERTEXP4UIVPROC, glVertexP4uiv) \
    X(PFNGLTEXCOORDP1UIPROC, glTexCoordP1ui) \
    X(PFNGLTEXCOORDP1UIVPROC, glTexCoordP1uiv) \
    X(PFNGLTEXCOORDP2UIPROC, glTexCoordP2ui) \
    X(PFNGLTEXCOORDP2UIVPROC, glTexCoordP2uiv) \
    X(PFNGLTEXCOORDP3UIPROC, glTexCoordP3ui) \
    X(PFNGLTEXCOORDP3UIVPROC, glTexCoordP3uiv) \
    X(PFNGLTEXCOORDP4UIPROC, glTexCoordP4ui) \
    X(PFNGLTEXCOORDP4UIVPROC, glTexCoordP4uiv) \
    X(PFNGLMULTITEXCOORDP1UIPROC, glMultiTexCoordP1ui) \
    X(PFNGLMULTITEXCOORDP1UIVPROC, glMultiTexCoordP1uiv) \
    X(PFNGLMULTITEXCOORDP2UIPROC, glMultiTexCoordP2ui) \
    X(PFNGLMULTITEXCOORDP2UIVPROC, glMultiTexCoordP2uiv) \
    X(PFNGLMULTITEXCOORDP3UIPROC, glMultiTexCoordP3ui) \
    X(PFNGLMULTITEXCOORDP3UIVPROC, glMultiTexCoordP3uiv) \
    X(PFNGLMULTITEXCOORDP4UIPROC, glMultiTexCoordP4ui) \
    X(PFNGLMULTITEXCOORDP4UIVPROC, glMultiTexCoordP4uiv) \
    X(PFNGLNORMALP3UIPROC, glNormalP3ui) \
    X(PFNGLNORMALP3UIVPROC, glNormalP3uiv) \
    X(PFNGLCOLORP3UIPROC, glColorP3ui) \
    X(PFNGLCOLORP3UIVPROC, glColorP3uiv) \
    X(PFNGLCOLORP4UIPROC, glColorP4ui) \
    X(PFNGLCOLORP4UIVPROC, glColorP4uiv) \
    X(PFNGLSECONDARYCOLORP3UIPROC, glSecondaryColorP3ui) \
    X(PFNGLSECONDARYCOLORP3UIVPROC, glSecondaryColorP3uiv) \

#define GL_FUNCTIONS_4_0 \
    X(PFNGLMINSAMPLESHADINGPROC, glMinSampleShading) \
    X(PFNGLBLENDEQUATIONIPROC, glBlendEquationi) \
    X(PFNGLBLENDEQUATIONSEPARATEIPROC, glBlendEquationSeparatei) \
    X(PFNGLBLENDFUNCIPROC, glBlendFunci) \
    X(PFNGLBLENDFUNCSEPARATEIPROC, glBlendFuncSeparatei) \
    X(PFNGLDRAWARRAYSINDIRECTPROC, glDrawArraysIndirect) \
    X(PFNGLDRAWELEMENTSINDIRECTPROC, glDrawElementsIndirect) \
    X(PFNGLUNIFORM1DPROC, glUniform1d) \
    X(PFNGLUNIFORM2DPROC, glUniform2d) \
    X(PFNGLUNIFORM3DPROC, glUniform3d) \
    X(PFNGLUNIFORM4DPROC, glUniform4d) \
    X(PFNGLUNIFORM1DVPROC, glUniform1dv) \
    X(PFNGLUNIFORM2DVPROC, glUniform2dv) \
    X(PFNGLUNIFORM3DVPROC, glUniform3dv) \
    X(PFNGLUNIFORM4DVPROC, glUniform4dv) \
    X(PFNGLUNIFORMMATRIX2DVPROC, glUniformMatrix2dv) \
    X(PFNGLUNIFORMMATRIX3DVPROC, glUniformMatrix3dv) \
    X(PFNGLUNIFORMMATRIX4DVPROC, glUniformMatrix4dv) \
    X(PFNGLUNIFORMMATRIX2X3DVPROC, glUniformMatrix2x3dv) \
    X(PFNGLUNIFORMMATRIX2X4DVPROC, glUniformMatrix2x4dv) \
    X(PFNGLUNIFORMMATRIX3X2DVPROC, glUniformMatrix3x2dv) \
    X(PFNGLUNIFORMMATRIX3X4DVPROC, glUniformMatrix3x4dv) \
    X(PFNGLUNIFORMMATRIX4X2DVPROC, glUniformMatrix4x2dv) \
    X(PFNGLUNIFORMMATRIX4X3DVPROC, glUniformMatrix4x3dv) \
    X(PFNGLGETUNIFORMDVPROC, glGetUniformdv) \
    X(PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC, glGetSubroutineUniformLocation) \
    X(PFNGLGETSUBROUTINEINDEXPROC, glGetSubroutineIndex) \
    X(PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC, glGetActiveSubroutineUniformiv) \
    X(PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC, glGetActiveSubroutineUniformName) \
    X(PFNGLGETACTIVESUBROUTINENAMEPROC, glGetActiveSubroutineName) \
    X(PFNGLUNIFORMSUBROUTINESUIVPROC, glUniformSubroutinesuiv) \
    X(PFNGLGETUNIFORMSUBROUTINEUIVPROC, glGetUniformSubroutineuiv) \
    X(PFNGLGETPROGRAMSTAGEIVPROC, glGetProgramStageiv) \
    X(PFNGLPATCHPARAMETERIPROC, glPatchParameteri) \
    X(PFNGLPATCHPARAMETERFVPROC, glPatchParameterfv) \
    X(PFNGLBINDTRANSFORMFEEDBACKPROC, glBindTransformFeedback) \
    X(PFNGLDELETETRANSFORMFEEDBACKSPROC, glDeleteTransformFeedbacks) \
    X(PFNGLGENTRANSFORMFEEDBACKSPROC, glGenTransformFeedbacks) \
    X(PFNGLISTRANSFORMFEEDBACKPROC, glIsTransformFeedback) \
    X(PFNGLPAUSETRANSFORMFEEDBACKPROC, glPauseTransformFeedback) \
    X(PFNGLRESUMETRANSFORMFEEDBACKPROC, glResumeTransformFeedback) \
    X(PFNGLDRAWTRANSFORMFEEDBACKPROC, glDrawTransformFeedback) \
    X(PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC, glDrawTransformFeedbackStream) \
    X(PFNGLBEGINQUERYINDEXEDPROC, glBeginQueryIndexed) \
    X(PFNGLENDQUERYINDEXEDPROC, glEndQueryIndexed) \
    X(PFNGLGETQUERYINDEXEDIVPROC, glGetQueryIndexediv) \

#define GL_FUNCTIONS_4_1 \
    X(PFNGLRELEASESHADERCOMPILERPROC, glReleaseShaderCompiler) \
    X(PFNGLSHADERBINARYPROC, glShaderBinary) \
    X(PFNGLGETSHADERPRECISIONFORMATPROC, glGetShaderPrecisionFormat) \
    X(PFNGLDEPTHRANGEFPROC, glDepthRangef) \
    X(PFNGLCLEARDEPTHFPROC, glClearDepthf) \
    X(PFNGLGETPROGRAMBINARYPROC, glGetProgramBinary) \
    X(PFNGLPROGRAMBINARYPROC, glProgramBinary) \
    X(PFNGLPROGRAMPARAMETERIPROC, glProgramParameteri) \
    X(PFNGLUSEPROGRAMSTAGESPROC, glUseProgramStages) \
    X(PFNGLACTIVESHADERPROGRAMPROC, glActiveShaderProgram) \
    X(PFNGLCREATESHADERPROGRAMVPROC, glCreateShaderProgramv) \
    X(PFNGLBINDPROGRAMPIPELINEPROC, glBindProgramPipeline) \
    X(PFNGLDELETEPROGRAMPIPELINESPROC, glDeleteProgramPipelines) \
    X(PFNGLGENPROGRAMPIPELINESPROC, glGenProgramPipelines) \
    X(PFNGLISPROGRAMPIPELINEPROC, glIsProgramPipeline) \
    X(PFNGLGETPROGRAMPIPELINEIVPROC, glGetProgramPipelineiv) \
    X(PFNGLPROGRAMUNIFORM1IPROC, glProgramUniform1i) \
    X(PFNGLPROGRAMUNIFORM1IVPROC, glProgramUniform1iv) \
    X(PFNGLPROGRAMUNIFORM1FPROC, glProgramUniform1f) \
    X(PFNGLPROGRAMUNIFORM1FVPROC, glProgramUniform1fv) \
    X(PFNGLPROGRAMUNIFORM1DPROC, glProgramUniform1d) \
    X(PFNGLPROGRAMUNIFORM1DVPROC, glProgramUniform1dv) \
    X(PFNGLPROGRAMUNIFORM1UIPROC, glProgramUniform1ui) \
    X(PFNGLPROGRAMUNIFORM1UIVPROC, glProgramUniform1uiv) \
    X(PFNGLPROGRAMUNIFORM2IPROC, glProgramUniform2i) \
    X(PFNGLPROGRAMUNIFORM2IVPROC, glProgramUniform2iv) \
    X(PFNGLPROGRAMUNIFORM2FPROC, glProgramUniform2f) \
    X(PFNGLPROGRAMUNIFORM2FVPROC, glProgramUniform2fv) \
    X(PFNGLPROGRAMUNIFORM2DPROC, glProgramUniform2d) \
    X(PFNGLPROGRAMUNIFORM2DVPROC, glProgramUniform2dv) \
    X(PFNGLPROGRAMUNIFORM2UIPROC, glProgramUniform2ui) \
    X(PFNGLPROGRAMUNIFORM2UIVPROC, glProgramUniform2uiv) \
    X(PFNGLPROGRAMUNIFORM3IPROC, glProgramUniform3i) \
    X(PFNGLPROGRAMUNIFORM3IVPROC, glProgramUniform3iv) \
    X(PFNGLPROGRAMUNIFORM3FPROC, glProgramUniform3f) \
    X(PFNGLPROGRAMUNIFORM3FVPROC, glProgramUniform3fv) \
    X(PFNGLPROGRAMUNIFORM3DPROC, glProgramUniform3d) \
    X(PFNGLPROGRAMUNIFORM3DVPROC, glProgramUniform3dv) \
    X(PFNGLPROGRAMUNIFORM3UIPROC, glProgramUniform3ui) \
    X(PFNGLPROGRAMUNIFORM3UIVPROC, glProgramUniform3uiv) \
    X(PFNGLPROGRAMUNIFORM4IPROC, glProgramUniform4i) \
    X(PFNGLPROGRAMUNIFORM4IVPROC, glProgramUniform4iv) \
    X(PFNGLPROGRAMUNIFORM4FPROC, glProgramUniform4f) \
    X(PFNGLPROGRAMUNIFORM4FVPROC, glProgramUniform4fv) \
    X(PFNGLPROGRAMUNIFORM4DPROC, glProgramUniform4d) \
    X(PFNGLPROGRAMUNIFORM4DVPROC, glProgramUniform4dv) \
    X(PFNGLPROGRAMUNIFORM4UIPROC, glProgramUniform4ui) \
    X(PFNGLPROGRAMUNIFORM4UIVPROC, glProgramUniform4uiv) \
    X(PFNGLPROGRAMUNIFORMMATRIX2FVPROC, glProgramUniformMatrix2fv) \
    X(PFNGLPROGRAMUNIFORMMATRIX3FVPROC, glProgramUniformMatrix3fv) \
    X(PFNGLPROGRAMUNIFORMMATRIX4FVPROC, glProgramUniformMatrix4fv) \
    X(PFNGLPROGRAMUNIFORMMATRIX2DVPROC, glProgramUniformMatrix2dv) \
    X(PFNGLPROGRAMUNIFORMMATRIX3DVPROC, glProgramUniformMatrix3dv) \
    X(PFNGLPROGRAMUNIFORMMATRIX4DVPROC, glProgramUniformMatrix4dv) \
    X(PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC, glProgramUniformMatrix2x3fv) \
    X(PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC, glProgramUniformMatrix3x2fv) \
    X(PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC, glProgramUniformMatrix2x4fv) \
    X(PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC, glProgramUniformMatrix4x2fv) \
    X(PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC, glProgramUniformMatrix3x4fv) \
    X(PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC, glProgramUniformMatrix4x3fv) \
    X(PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC, glProgramUniformMatrix2x3dv) \
    X(PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC, glProgramUniformMatrix3x2dv) \
    X(PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC, glProgramUniformMatrix2x4dv) \
    X(PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC, glProgramUniformMatrix4x2dv) \
    X(PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC, glProgramUniformMatrix3x4dv) \
    X(PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC, glProgramUniformMatrix4x3dv) \
    X(PFNGLVALIDATEPROGRAMPIPELINEPROC, glValidateProgramPipeline) \
    X(PFNGLGETPROGRAMPIPELINEINFOLOGPROC, glGetProgramPipelineInfoLog) \
    X(PFNGLVERTEXATTRIBL1DPROC, glVertexAttribL1d) \
    X(PFNGLVERTEXATTRIBL2DPROC, glVertexAttribL2d) \
    X(PFNGLVERTEXATTRIBL3DPROC, glVertexAttribL3d) \
    X(PFNGLVERTEXATTRIBL4DPROC, glVertexAttribL4d) \
    X(PFNGLVERTEXATTRIBL1DVPROC, glVertexAttribL1dv) \
    X(PFNGLVERTEXATTRIBL2DVPROC, glVertexAttribL2dv) \
    X(PFNGLVERTEXATTRIBL3DVPROC, glVertexAttribL3dv) \
    X(PFNGLVERTEXATTRIBL4DVPROC, glVertexAttribL4dv) \
    X(PFNGLVERTEXATTRIBLPOINTERPROC, glVertexAttribLPointer) \
    X(PFNGLGETVERTEXATTRIBLDVPROC, glGetVertexAttribLdv) \
    X(PFNGLVIEWPORTARRAYVPROC, glViewportArrayv) \
    X(PFNGLVIEWPORTINDEXEDFPROC, glViewportIndexedf) \
    X(PFNGLVIEWPORTINDEXEDFVPROC, glViewportIndexedfv) \
    X(PFNGLSCISSORARRAYVPROC, glScissorArrayv) \
    X(PFNGLSCISSORINDEXEDPROC, glScissorIndexed) \
    X(PFNGLSCISSORINDEXEDVPROC, glScissorIndexedv) \
    X(PFNGLDEPTHRANGEARRAYVPROC, glDepthRangeArrayv) \
    X(PFNGLDEPTHRANGEINDEXEDPROC, glDepthRangeIndexed) \
    X(PFNGLGETFLOATI_VPROC, glGetFloati_v) \
    X(PFNGLGETDOUBLEI_VPROC, glGetDoublei_v) \

#define GL_FUNCTIONS_4_2 \
    X(PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC, glDrawArraysInstancedBaseInstance) \
    X(PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC, glDrawElementsInstancedBaseInstance) \
    X(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC, glDrawElementsInstancedBaseVertexBaseInstance) \
    X(PFNGLGETINTERNALFORMATIVPROC, glGetInternalformativ) \
    X(PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC, glGetActiveAtomicCounterBufferiv) \
    X(PFNGLBINDIMAGETEXTUREPROC, glBindImageTexture) \
    X(PFNGLMEMORYBARRIERPROC, glMemoryBarrier) \
    X(PFNGLTEXSTORAGE1DPROC, glTexStorage1D) \
    X(PFNGLTEXSTORAGE2DPROC, glTexStorage2D) \
    X(PFNGLTEXSTORAGE3DPROC, glTexStorage3D) \
    X(PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC, glDrawTransformFeedbackInstanced) \
    X(PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC, glDrawTransformFeedbackStreamInstanced) \

#define GL_FUNCTIONS_4_3 \
    X(PFNGLCLEARBUFFERDATAPROC, glClearBufferData) \
    X(PFNGLCLEARBUFFERSUBDATAPROC, glClearBufferSubData) \
    X(PFNGLDISPATCHCOMPUTEPROC, glDispatchCompute) \
    X(PFNGLDISPATCHCOMPUTEINDIRECTPROC, glDispatchComputeIndirect) \
    X(PFNGLCOPYIMAGESUBDATAPROC, glCopyImageSubData) \
    X(PFNGLFRAMEBUFFERPARAMETERIPROC, glFramebufferParameteri) \
    X(PFNGLGETFRAMEBUFFERPARAMETERIVPROC, glGetFramebufferParameteriv) \
    X(PFNGLGETINTERNALFORMATI64VPROC, glGetInternalformati64v) \
    X(PFNGLINVALIDATETEXSUBIMAGEPROC, glInvalidateTexSubImage) \
    X(PFNGLINVALIDATETEXIMAGEPROC, glInvalidateTexImage) \
    X(PFNGLINVALIDATEBUFFERSUBDATAPROC, glInvalidateBufferSubData) \
    X(PFNGLINVALIDATEBUFFERDATAPROC, glInvalidateBufferData) \
    X(PFNGLINVALIDATEFRAMEBUFFERPROC, glInvalidateFramebuffer) \
    X(PFNGLINVALIDATESUBFRAMEBUFFERPROC, glInvalidateSubFramebuffer) \
    X(PFNGLMULTIDRAWARRAYSINDIRECTPROC, glMultiDrawArraysIndirect) \
    X(PFNGLMULTIDRAWELEMENTSINDIRECTPROC, glMultiDrawElementsIndirect) \
    X(PFNGLGETPROGRAMINTERFACEIVPROC, glGetProgramInterfaceiv) \
    X(PFNGLGETPROGRAMRESOURCEINDEXPROC, glGetProgramResourceIndex) \
    X(PFNGLGETPROGRAMRESOURCENAMEPROC, glGetProgramResourceName) \
    X(PFNGLGETPROGRAMRESOURCEIVPROC, glGetProgramResourceiv) \
    X(PFNGLGETPROGRAMRESOURCELOCATIONPROC, glGetProgramResourceLocation) \
    X(PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC, glGetProgramResourceLocationIndex) \
    X(PFNGLSHADERSTORAGEBLOCKBINDINGPROC, glShaderStorageBlockBinding) \
    X(PFNGLTEXBUFFERRANGEPROC, glTexBufferRange) \
    X(PFNGLTEXSTORAGE2DMULTISAMPLEPROC, glTexStorage2DMultisample) \
    X(PFNGLTEXSTORAGE3DMULTISAMPLEPROC, glTexStorage3DMultisample) \
    X(PFNGLTEXTUREVIEWPROC, glTextureView) \
    X(PFNGLBINDVERTEXBUFFERPROC, glBindVertexBuffer) \
    X(PFNGLVERTEXATTRIBFORMATPROC, glVertexAttribFormat) \
    X(PFNGLVERTEXATTRIBIFORMATPROC, glVertexAttribIFormat) \
    X(PFNGLVERTEXATTRIBLFORMATPROC, glVertexAttribLFormat) \
    X(PFNGLVERTEXATTRIBBINDINGPROC, glVertexAttribBinding) \
    X(PFNGLVERTEXBINDINGDIVISORPROC, glVertexBindingDivisor) \
    X(PFNGLDEBUGMESSAGECONTROLPROC, glDebugMessageControl) \
    X(PFNGLDEBUGMESSAGEINSERTPROC, glDebugMessageInsert) \
    X(PFNGLDEBUGMESSAGECALLBACKPROC, glDebugMessageCallback) \
    X(PFNGLGETDEBUGMESSAGELOGPROC, glGetDebugMessageLog) \
    X(PFNGLPUSHDEBUGGROUPPROC, glPushDebugGroup) \
    X(PFNGLPOPDEBUGGROUPPROC, glPopDebugGroup) \
    X(PFNGLOBJECTLABELPROC, glObjectLabel) \
    X(PFNGLGETOBJECTLABELPROC, glGetObjectLabel) \
    X(PFNGLOBJECTPTRLABELPROC, glObjectPtrLabel) \
    X(PFNGLGETOBJECTPTRLABELPROC, glGetObjectPtrLabel) \

#define GL_FUNCTIONS_4_4 \
    X(PFNGLBUFFERSTORAGEPROC, glBufferStorage) \
    X(PFNGLCLEARTEXIMAGEPROC, glClearTexImage) \
    X(PFNGLCLEARTEXSUBIMAGEPROC, glClearTexSubImage) \
    X(PFNGLBINDBUFFERSBASEPROC, glBindBuffersBase) \
    X(PFNGLBINDBUFFERSRANGEPROC, glBindBuffersRange) \
    X(PFNGLBINDTEXTURESPROC, glBindTextures) \
    X(PFNGLBINDSAMPLERSPROC, glBindSamplers) \
    X(PFNGLBINDIMAGETEXTURESPROC, glBindImageTextures) \
    X(PFNGLBINDVERTEXBUFFERSPROC, glBindVertexBuffers) \

#define GL_FUNCTIONS_4_5 \
    X(PFNGLCLIPCONTROLPROC, glClipControl) \
    X(PFNGLCREATETRANSFORMFEEDBACKSPROC, glCreateTransformFeedbacks) \
    X(PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC, glTransformFeedbackBufferBase) \
    X(PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC, glTransformFeedbackBufferRange) \
    X(PFNGLGETTRANSFORMFEEDBACKIVPROC, glGetTransformFeedbackiv) \
    X(PFNGLGETTRANSFORMFEEDBACKI_VPROC, glGetTransformFeedbacki_v) \
    X(PFNGLGETTRANSFORMFEEDBACKI64_VPROC, glGetTransformFeedbacki64_v) \
    X(PFNGLCREATEBUFFERSPROC, glCreateBuffers) \
    X(PFNGLNAMEDBUFFERSTORAGEPROC, glNamedBufferStorage) \
    X(PFNGLNAMEDBUFFERDATAPROC, glNamedBufferData) \
    X(PFNGLNAMEDBUFFERSUBDATAPROC, glNamedBufferSubData) \
    X(PFNGLCOPYNAMEDBUFFERSUBDATAPROC, glCopyNamedBufferSubData) \
    X(PFNGLCLEARNAMEDBUFFERDATAPROC, glClearNamedBufferData) \
    X(PFNGLCLEARNAMEDBUFFERSUBDATAPROC, glClearNamedBufferSubData) \
    X(PFNGLMAPNAMEDBUFFERPROC, glMapNamedBuffer) \
    X(PFNGLMAPNAMEDBUFFERRANGEPROC, glMapNamedBufferRange) \
    X(PFNGLUNMAPNAMEDBUFFERPROC, glUnmapNamedBuffer) \
    X(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC, glFlushMappedNamedBufferRange) \
    X(PFNGLGETNAMEDBUFFERPARAMETERIVPROC, glGetNamedBufferParameteriv) \
    X(PFNGLGETNAMEDBUFFERPARAMETERI64VPROC, glGetNamedBufferParameteri64v) \
    X(PFNGLGETNAMEDBUFFERPOINTERVPROC, glGetNamedBufferPointerv) \
    X(PFNGLGETNAMEDBUFFERSUBDATAPROC, glGetNamedBufferSubData) \
    X(PFNGLCREATEFRAMEBUFFERSPROC, glCreateFramebuffers) \
    X(PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC, glNamedFramebufferRenderbuffer) \
    X(PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC, glNamedFramebufferParameteri) \
    X(PFNGLNAMEDFRAMEBUFFERTEXTUREPROC, glNamedFramebufferTexture) \
    X(PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC, glNamedFramebufferTextureLayer) \
    X(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC, glNamedFramebufferDrawBuffer) \
    X(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC, glNamedFramebufferDrawBuffers) \
    X(PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC, glNamedFramebufferReadBuffer) \
    X(PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC, glInvalidateNamedFramebufferData) \
    X(PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC, glInvalidateNamedFramebufferSubData) \
    X(PFNGLCLEARNAMEDFRAMEBUFFERIVPROC, glClearNamedFramebufferiv) \
    X(PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC, glClearNamedFramebufferuiv) \
    X(PFNGLCLEARNAMEDFRAMEBUFFERFVPROC, glClearNamedFramebufferfv) \
    X(PFNGLCLEARNAMEDFRAMEBUFFERFIPROC, glClearNamedFramebufferfi) \
    X(PFNGLBLITNAMEDFRAMEBUFFERPROC, glBlitNamedFramebuffer) \
    X(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC, glCheckNamedFramebufferStatus) \
    X(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC, glGetNamedFramebufferParameteriv) \
    X(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetNamedFramebufferAttachmentParameteriv) \
    X(PFNGLCREATERENDERBUFFERSPROC, glCreateRenderbuffers) \
    X(PFNGLNAMEDRENDERBUFFERSTORAGEPROC, glNamedRenderbufferStorage) \
    X(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC, glNamedRenderbufferStorageMultisample) \
    X(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC, glGetNamedRenderbufferParameteriv) \
    X(PFNGLCREATETEXTURESPROC, glCreateTextures) \
    X(PFNGLTEXTUREBUFFERPROC, glTextureBuffer) \
    X(PFNGLTEXTUREBUFFERRANGEPROC, glTextureBufferRange) \
    X(PFNGLTEXTURESTORAGE1DPROC, glTextureStorage1D) \
    X(PFNGLTEXTURESTORAGE2DPROC, glTextureStorage2D) \
    X(PFNGLTEXTURESTORAGE3DPROC, glTextureStorage3D) \
    X(PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC, glTextureStorage2DMultisample) \
    X(PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC, glTextureStorage3DMultisample) \
    X(PFNGLTEXTURESUBIMAGE1DPROC, glTextureSubImage1D) \
    X(PFNGLTEXTURESUBIMAGE2DPROC, glTextureSubImage2D) \
    X(PFNGLTEXTURESUBIMAGE3DPROC, glTextureSubImage3D) \
    X(PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC, glCompressedTextureSubImage1D) \
    X(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC, glCompressedTextureSubImage2D) \
    X(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC, glCompressedTextureSubImage3D) \
    X(PFNGLCOPYTEXTURESUBIMAGE1DPROC, glCopyTextureSubImage1D) \
    X(PFNGLCOPYTEXTURESUBIMAGE2DPROC, glCopyTextureSubImage2D) \
    X(PFNGLCOPYTEXTURESUBIMAGE3DPROC, glCopyTextureSubImage3D) \
    X(PFNGLTEXTUREPARAMETERFPROC, glTextureParameterf) \
    X(PFNGLTEXTUREPARAMETERFVPROC, glTextureParameterfv) \
    X(PFNGLTEXTUREPARAMETERIPROC, glTextureParameteri) \
    X(PFNGLTEXTUREPARAMETERIIVPROC, glTextureParameterIiv) \
    X(PFNGLTEXTUREPARAMETERIUIVPROC, glTextureParameterIuiv) \
    X(PFNGLTEXTUREPARAMETERIVPROC, glTextureParameteriv) \
    X(PFNGLGENERATETEXTUREMIPMAPPROC, glGenerateTextureMipmap) \
    X(PFNGLBINDTEXTUREUNITPROC, glBindTextureUnit) \
    X(PFNGLGETTEXTUREIMAGEPROC, glGetTextureImage) \
    X(PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC, glGetCompressedTextureImage) \
    X(PFNGLGETTEXTURELEVELPARAMETERFVPROC, glGetTextureLevelParameterfv) \
    X(PFNGLGETTEXTURELEVELPARAMETERIVPROC, glGetTextureLevelParameteriv) \
    X(PFNGLGETTEXTUREPARAMETERFVPROC, glGetTextureParameterfv) \
    X(PFNGLGETTEXTUREPARAMETERIIVPROC, glGetTextureParameterIiv) \
    X(PFNGLGETTEXTUREPARAMETERIUIVPROC, glGetTextureParameterIuiv) \
    X(PFNGLGETTEXTUREPARAMETERIVPROC, glGetTextureParameteriv) \
    X(PFNGLCREATEVERTEXARRAYSPROC, glCreateVertexArrays) \
    X(PFNGLDISABLEVERTEXARRAYATTRIBPROC, glDisableVertexArrayAttrib) \
    X(PFNGLENABLEVERTEXARRAYATTRIBPROC, glEnableVertexArrayAttrib) \
    X(PFNGLVERTEXARRAYELEMENTBUFFERPROC, glVertexArrayElementBuffer) \
    X(PFNGLVERTEXARRAYVERTEXBUFFERPROC, glVertexArrayVertexBuffer) \
    X(PFNGLVERTEXARRAYVERTEXBUFFERSPROC, glVertexArrayVertexBuffers) \
    X(PFNGLVERTEXARRAYATTRIBBINDINGPROC, glVertexArrayAttribBinding) \
    X(PFNGLVERTEXARRAYATTRIBFORMATPROC, glVertexArrayAttribFormat) \
    X(PFNGLVERTEXARRAYATTRIBIFORMATPROC, glVertexArrayAttribIFormat) \
    X(PFNGLVERTEXARRAYATTRIBLFORMATPROC, glVertexArrayAttribLFormat) \
    X(PFNGLVERTEXARRAYBINDINGDIVISORPROC, glVertexArrayBindingDivisor) \
    X(PFNGLGETVERTEXARRAYIVPROC, glGetVertexArrayiv) \
    X(PFNGLGETVERTEXARRAYINDEXEDIVPROC, glGetVertexArrayIndexediv) \
    X(PFNGLGETVERTEXARRAYINDEXED64IVPROC, glGetVertexArrayIndexed64iv) \
    X(PFNGLCREATESAMPLERSPROC, glCreateSamplers) \
    X(PFNGLCREATEPROGRAMPIPELINESPROC, glCreateProgramPipelines) \
    X(PFNGLCREATEQUERIESPROC, glCreateQueries) \
    X(PFNGLGETQUERYBUFFEROBJECTI64VPROC, glGetQueryBufferObjecti64v) \
    X(PFNGLGETQUERYBUFFEROBJECTIVPROC, glGetQueryBufferObjectiv) \
    X(PFNGLGETQUERYBUFFEROBJECTUI64VPROC, glGetQueryBufferObjectui64v) \
    X(PFNGLGETQUERYBUFFEROBJECTUIVPROC, glGetQueryBufferObjectuiv) \
    X(PFNGLMEMORYBARRIERBYREGIONPROC, glMemoryBarrierByRegion) \
    X(PFNGLGETTEXTURESUBIMAGEPROC, glGetTextureSubImage) \
    X(PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC, glGetCompressedTextureSubImage) \
    X(PFNGLGETGRAPHICSRESETSTATUSPROC, glGetGraphicsResetStatus) \
    X(PFNGLGETNCOMPRESSEDTEXIMAGEPROC, glGetnCompressedTexImage) \
    X(PFNGLGETNTEXIMAGEPROC, glGetnTexImage) \
    X(PFNGLGETNUNIFORMDVPROC, glGetnUniformdv) \
    X(PFNGLGETNUNIFORMFVPROC, glGetnUniformfv) \
    X(PFNGLGETNUNIFORMIVPROC, glGetnUniformiv) \
    X(PFNGLGETNUNIFORMUIVPROC, glGetnUniformuiv) \
    X(PFNGLREADNPIXELSPROC, glReadnPixels) \
    X(PFNGLGETNMAPDVPROC, glGetnMapdv) \
    X(PFNGLGETNMAPFVPROC, glGetnMapfv) \
    X(PFNGLGETNMAPIVPROC, glGetnMapiv) \
    X(PFNGLGETNPIXELMAPFVPROC, glGetnPixelMapfv) \
    X(PFNGLGETNPIXELMAPUIVPROC, glGetnPixelMapuiv) \
    X(PFNGLGETNPIXELMAPUSVPROC, glGetnPixelMapusv) \
    X(PFNGLGETNPOLYGONSTIPPLEPROC, glGetnPolygonStipple) \
    X(PFNGLGETNCOLORTABLEPROC, glGetnColorTable) \
    X(PFNGLGETNCONVOLUTIONFILTERPROC, glGetnConvolutionFilter) \
    X(PFNGLGETNSEPARABLEFILTERPROC, glGetnSeparableFilter) \
    X(PFNGLGETNHISTOGRAMPROC, glGetnHistogram) \
    X(PFNGLGETNMINMAXPROC, glGetnMinmax) \
    X(PFNGLTEXTUREBARRIERPROC, glTextureBarrier) \

#define X(T, N) extern T cwcgl##N;
#if CWCGL_VERSION >= GL_VERSION_1_0
GL_FUNCTIONS_1_0
#endif
#if CWCGL_VERSION >= GL_VERSION_1_1
GL_FUNCTIONS_1_1
#endif
#if CWCGL_VERSION >= GL_VERSION_1_2
GL_FUNCTIONS_1_2
#endif
#if CWCGL_VERSION >= GL_VERSION_1_3
GL_FUNCTIONS_1_3
#endif
#if CWCGL_VERSION >= GL_VERSION_1_4
GL_FUNCTIONS_1_4
#endif
#if CWCGL_VERSION >= GL_VERSION_1_5
GL_FUNCTIONS_1_5
#endif
#if CWCGL_VERSION >= GL_VERSION_2_0
GL_FUNCTIONS_2_0
#endif
#if CWCGL_VERSION >= GL_VERSION_2_1
GL_FUNCTIONS_2_1
#endif
#if CWCGL_VERSION >= GL_VERSION_3_0
GL_FUNCTIONS_3_0
#endif
#if CWCGL_VERSION >= GL_VERSION_3_1
GL_FUNCTIONS_3_1
#endif
#if CWCGL_VERSION >= GL_VERSION_3_2
GL_FUNCTIONS_3_2
#endif
#if CWCGL_VERSION >= GL_VERSION_3_3
GL_FUNCTIONS_3_3
#endif
#if CWCGL_VERSION >= GL_VERSION_4_0
GL_FUNCTIONS_4_0
#endif
#if CWCGL_VERSION >= GL_VERSION_4_1
GL_FUNCTIONS_4_1
#endif
#if CWCGL_VERSION >= GL_VERSION_4_2
GL_FUNCTIONS_4_2
#endif
#if CWCGL_VERSION >= GL_VERSION_4_3
GL_FUNCTIONS_4_3
#endif
#if CWCGL_VERSION >= GL_VERSION_4_4
GL_FUNCTIONS_4_4
#endif
#if CWCGL_VERSION >= GL_VERSION_4_5
GL_FUNCTIONS_4_5
#endif
#undef X

/* display mode bit masks */
#define GLUT_RGB                        0
#define GLUT_RGBA                       GLUT_RGB
#define GLUT_INDEX                      1
#define GLUT_SINGLE                     0
#define GLUT_DOUBLE                     2
#define GLUT_ACCUM                      4
#define GLUT_ALPHA                      8
#define GLUT_DEPTH                      16
#define GLUT_STENCIL                    32
#define GLUT_MULTISAMPLE                128
#define GLUT_STEREO                     256
#define GLUT_LUMINANCE                  512

/* mouse buttons */
#define GLUT_LEFT_BUTTON                0
#define GLUT_MIDDLE_BUTTON              1
#define GLUT_RIGHT_BUTTON               2

/* mouse button callback state */
#define GLUT_DOWN                       0
#define GLUT_UP                         1

/* function keys */
#define GLUT_KEY_F1                     1
#define GLUT_KEY_F2                     2
#define GLUT_KEY_F3                     3
#define GLUT_KEY_F4                     4
#define GLUT_KEY_F5                     5
#define GLUT_KEY_F6                     6
#define GLUT_KEY_F7                     7
#define GLUT_KEY_F8                     8
#define GLUT_KEY_F9                     9
#define GLUT_KEY_F10                    10
#define GLUT_KEY_F11                    11
#define GLUT_KEY_F12                    12
/* directional keys */
#define GLUT_KEY_LEFT                   100
#define GLUT_KEY_UP                     101
#define GLUT_KEY_RIGHT                  102
#define GLUT_KEY_DOWN                   103
#define GLUT_KEY_PAGE_UP                104
#define GLUT_KEY_PAGE_DOWN              105
#define GLUT_KEY_HOME                   106
#define GLUT_KEY_END                    107
#define GLUT_KEY_INSERT                 108

/* entry/exit callback state */
#define GLUT_LEFT                       0
#define GLUT_ENTERED                    1

/* menu usage callback state */
#define GLUT_MENU_NOT_IN_USE            0
#define GLUT_MENU_IN_USE                1

/* visibility callback state */
#define GLUT_NOT_VISIBLE                0
#define GLUT_VISIBLE                    1

/* color index component selection values */
#define GLUT_RED                        0
#define GLUT_GREEN                      1
#define GLUT_BLUE                       2

/* layers for use */
#define GLUT_NORMAL                     0
#define GLUT_OVERLAY                    1

/* stroke font opaque addresses (use constants instead in source code) */
extern void *glutStrokeRoman;
extern void *glutStrokeMonoRoman;

/* stroke font constants (use these in GLUT program) */
#define GLUT_STROKE_ROMAN               (&glutStrokeRoman)
#define GLUT_STROKE_MONO_ROMAN          (&glutStrokeMonoRoman)

/* bitmap font opaque addresses (use constants instead in source code) */
extern void *glutBitmap9By15;
extern void *glutBitmap8By13;
extern void *glutBitmapTimesRoman10;
extern void *glutBitmapTimesRoman24;
extern void *glutBitmapHelvetica10;
extern void *glutBitmapHelvetica12;
extern void *glutBitmapHelvetica18;

/* bitmap font constants (use these in GLUT program) */
#define GLUT_BITMAP_9_BY_15             (&glutBitmap9By15)
#define GLUT_BITMAP_8_BY_13             (&glutBitmap8By13)
#define GLUT_BITMAP_TIMES_ROMAN_10      (&glutBitmapTimesRoman10)
#define GLUT_BITMAP_TIMES_ROMAN_24      (&glutBitmapTimesRoman24)
#define GLUT_BITMAP_HELVETICA_10        (&glutBitmapHelvetica10)
#define GLUT_BITMAP_HELVETICA_12        (&glutBitmapHelvetica12)
#define GLUT_BITMAP_HELVETICA_18        (&glutBitmapHelvetica18)

/* glutGet parameters */
#define GLUT_WINDOW_X                   100
#define GLUT_WINDOW_Y                   101
#define GLUT_WINDOW_WIDTH               102
#define GLUT_WINDOW_HEIGHT              103
#define GLUT_WINDOW_BUFFER_SIZE         104
#define GLUT_WINDOW_STENCIL_SIZE        105
#define GLUT_WINDOW_DEPTH_SIZE          106
#define GLUT_WINDOW_RED_SIZE            107
#define GLUT_WINDOW_GREEN_SIZE          108
#define GLUT_WINDOW_BLUE_SIZE           109
#define GLUT_WINDOW_ALPHA_SIZE          110
#define GLUT_WINDOW_ACCUM_RED_SIZE      111
#define GLUT_WINDOW_ACCUM_GREEN_SIZE    112
#define GLUT_WINDOW_ACCUM_BLUE_SIZE     113
#define GLUT_WINDOW_ACCUM_ALPHA_SIZE    114
#define GLUT_WINDOW_DOUBLEBUFFER        115
#define GLUT_WINDOW_RGBA                116
#define GLUT_WINDOW_PARENT              117
#define GLUT_WINDOW_NUM_CHILDREN        118
#define GLUT_WINDOW_COLORMAP_SIZE       119
#define GLUT_WINDOW_NUM_SAMPLES         120
#define GLUT_WINDOW_STEREO              121
#define GLUT_WINDOW_CURSOR              122
#define GLUT_SCREEN_WIDTH               200
#define GLUT_SCREEN_HEIGHT              201
#define GLUT_SCREEN_WIDTH_MM            202
#define GLUT_SCREEN_HEIGHT_MM           203
#define GLUT_MENU_NUM_ITEMS             300
#define GLUT_DISPLAY_MODE_POSSIBLE      400
#define GLUT_INIT_WINDOW_X              500
#define GLUT_INIT_WINDOW_Y              501
#define GLUT_INIT_WINDOW_WIDTH          502
#define GLUT_INIT_WINDOW_HEIGHT         503
#define GLUT_INIT_DISPLAY_MODE          504
#define GLUT_ELAPSED_TIME               700

/* glutDeviceGet parameters */
#define GLUT_HAS_KEYBOARD               600
#define GLUT_HAS_MOUSE                  601
#define GLUT_HAS_SPACEBALL              602
#define GLUT_HAS_DIAL_AND_BUTTON_BOX    603
#define GLUT_HAS_TABLET                 604
#define GLUT_NUM_MOUSE_BUTTONS          605
#define GLUT_NUM_SPACEBALL_BUTTONS      606
#define GLUT_NUM_BUTTON_BOX_BUTTONS     607
#define GLUT_NUM_DIALS                  608
#define GLUT_NUM_TABLET_BUTTONS         609

/* glutLayerGet parameters */
#define GLUT_OVERLAY_POSSIBLE           800
#define GLUT_LAYER_IN_USE               801
#define GLUT_HAS_OVERLAY                802
#define GLUT_TRANSPARENT_INDEX          803
#define GLUT_NORMAL_DAMAGED             804
#define GLUT_OVERLAY_DAMAGED            805

/* glutUseLayer parameters */
#define GLUT_NORMAL                     0
#define GLUT_OVERLAY                    1

/* glutGetModifiers return mask */
#define GLUT_ACTIVE_SHIFT               1
#define GLUT_ACTIVE_CTRL                2
#define GLUT_ACTIVE_ALT                 4

/* glutSetCursor parameters */
/* Basic arrows */
#define GLUT_CURSOR_RIGHT_ARROW         0
#define GLUT_CURSOR_LEFT_ARROW          1
/* Symbolic cursor shapees */
#define GLUT_CURSOR_INFO                2
#define GLUT_CURSOR_DESTROY             3
#define GLUT_CURSOR_HELP                4
#define GLUT_CURSOR_CYCLE               5
#define GLUT_CURSOR_SPRAY               6
#define GLUT_CURSOR_WAIT                7
#define GLUT_CURSOR_TEXT                8
#define GLUT_CURSOR_CROSSHAIR           9
/* Directional cursors */
#define GLUT_CURSOR_UP_DOWN             10
#define GLUT_CURSOR_LEFT_RIGHT          11
/* Sizing cursors */
#define GLUT_CURSOR_TOP_SIDE            12
#define GLUT_CURSOR_BOTTOM_SIDE         13
#define GLUT_CURSOR_LEFT_SIDE           14
#define GLUT_CURSOR_RIGHT_SIDE          15
#define GLUT_CURSOR_TOP_LEFT_CORNER     16
#define GLUT_CURSOR_TOP_RIGHT_CORNER    17
#define GLUT_CURSOR_BOTTOM_RIGHT_CORNER 18
#define GLUT_CURSOR_BOTTOM_LEFT_CORNER  19
/* Inherit from parent window */
#define GLUT_CURSOR_INHERIT             100
/* Blank cursor */
#define GLUT_CURSOR_NONE                101
/* Fullscreen crosshair (if available) */
#define GLUT_CURSOR_FULL_CROSSHAIR      102

/* GLUT initialization sub-API */
extern void glutInit(int *argcp, char **argv);
extern void glutInitDisplayMode(unsigned int mode);
extern void glutInitWindowPosition(int x, int y);
extern void glutInitWindowSize(int width, int height);
extern void glutMainLoop(void);

/* GLUT window sub-api */
extern int glutCreateWindow(char *title);
extern int glutCreateSubWindow(int win, int x, int y, int width, int height);
extern void glutDestroyWindow(int win);
extern void glutPostRedisplay(void);
extern void glutSwapBuffers(void);
extern int glutGetWindow(void);
extern void glutSetWindow(int win);
extern void glutSetWindowTitle(char *title);
extern void glutSetIconTitle(char *title);
extern void glutPositionWindow(int x, int y);
extern void glutReshapeWindow(int width, int height);
extern void glutPopWindow(void);
extern void glutPushWindow(void);
extern void glutIconifyWindow(void);
extern void glutShowWindow(void);
extern void glutHideWindow(void);
extern void glutFullScreen(void);
extern void glutSetCursor(int cursor);

/* GLUT overlay sub-API */
extern void glutEstablishOverlay(void);
extern void glutRemoveOverlay(void);
extern void glutUseLayer(GLenum layer);
extern void glutPostOverlayRedisplay(void);
extern void glutShowOverlay(void);
extern void glutHideOverlay(void);

/* GLUT menu sub-API */
extern int glutCreateMenu(void(*)(int));
extern void glutDestroyMenu(int menu);
extern int glutGetMenu(void);
extern void glutSetMenu(int menu);
extern void glutAddMenuEntry(char *label, int value);
extern void glutAddSubMenu(char *label, int submenu);
extern void glutChangeToMenuEntry(int item, char *label, int value);
extern void glutChangeToSubMenu(int item, char *label, int submenu);
extern void glutRemoveMenuItem(int item);
extern void glutAttachMenu(int button);
extern void glutDetachMenu(int button);

/* GLUT callback sub-api */
extern void glutDisplayFunc(void(*)(void));
extern void glutReshapeFunc(void(*)(int width, int height));
extern void glutKeyboardFunc(void(*)(unsigned char key, int x, int y));
extern void glutMouseFunc(void(*)(int button, int state, int x, int y));
extern void glutMotionFunc(void(*)(int x, int y));
extern void glutPassiveMotionFunc(void(*)(int x, int y));
extern void glutEntryFunc(void(*)(int state));
extern void glutVisibilityFunc(void(*)(int state));
extern void glutIdleFunc(void(*)(void));
extern void glutTimerFunc(unsigned int millis, void(*)(int value), int value);
extern void glutMenuStateFunc(void(*)(int state));
extern void glutSpecialFunc(void(*)(int key, int x, int y));
extern void glutSpaceballMotionFunc(void(*)(int x, int y, int z));
extern void glutSpaceballRotateFunc(void(*)(int x, int y, int z));
extern void glutSpaceballButtonFunc(void(*)(int button, int state));
extern void glutButtonBoxFunc(void(*)(int button, int state));
extern void glutDialsFunc(void(*)(int dial, int value));
extern void glutTabletMotionFunc(void(*)(int x, int y));
extern void glutTabletButtonFunc(void(*)(int button, int state, int x, int y));
extern void glutMenuStatusFunc(void(*)(int status, int x, int y));
extern void glutOverlayDisplayFunc(void(*)(void));

/* GLUT color index sub-api */
extern void glutSetColor(int cell, GLfloat red, GLfloat green, GLfloat blue);
extern GLfloat glutGetColor(int cell, int component);
extern void glutCopyColormap(int win);

/* GLUT state retrieval sub-api */
extern int glutGet(GLenum type);
extern int glutDeviceGet(GLenum type);
/* GLUT extension support sub-API */
extern int glutExtensionSupported(char *name);
extern int glutGetModifiers(void);
extern int glutLayerGet(GLenum type);

/* GLUT font sub-API */
extern void glutBitmapCharacter(void *font, int character);
extern int glutBitmapWidth(void *font, int character);
extern void glutStrokeCharacter(void *font, int character);
extern int glutStrokeWidth(void *font, int character);

/* GLUT pre-built models sub-API */
extern void glutWireSphere(GLdouble radius, GLint slices, GLint stacks);
extern void glutSolidSphere(GLdouble radius, GLint slices, GLint stacks);
extern void glutWireCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
extern void glutSolidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
extern void glutWireCube(GLdouble size);
extern void glutSolidCube(GLdouble size);
extern void glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
extern void glutSolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
extern void glutWireDodecahedron(void);
extern void glutSolidDodecahedron(void);
extern void glutWireTeapot(GLdouble size);
extern void glutSolidTeapot(GLdouble size);
extern void glutWireOctahedron(void);
extern void glutSolidOctahedron(void);
extern void glutWireTetrahedron(void);
extern void glutSolidTetrahedron(void);
extern void glutWireIcosahedron(void);
extern void glutSolidIcosahedron(void);

#ifdef __cplusplus
}
#endif
#endif /* __cwcgl_h__ */
