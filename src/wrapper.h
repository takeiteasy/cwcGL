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
#define glCullFace __glCullFace
typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
#define glFrontFace __glFrontFace
typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
#define glHint __glHint
typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
#define glLineWidth __glLineWidth
typedef void (APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
#define glPointSize __glPointSize
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
#define glPolygonMode __glPolygonMode
typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
#define glScissor __glScissor
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
#define glTexParameterf __glTexParameterf
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat * params);
#define glTexParameterfv __glTexParameterfv
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
#define glTexParameteri __glTexParameteri
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint * params);
#define glTexParameteriv __glTexParameteriv
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage1D __glTexImage1D
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage2D __glTexImage2D
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum buf);
#define glDrawBuffer __glDrawBuffer
typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
#define glClear __glClear
typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glClearColor __glClearColor
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
#define glClearStencil __glClearStencil
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble depth);
#define glClearDepth __glClearDepth
typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
#define glStencilMask __glStencilMask
typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
#define glColorMask __glColorMask
typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
#define glDepthMask __glDepthMask
typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
#define glDisable __glDisable
typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
#define glEnable __glEnable
typedef void (APIENTRYP PFNGLFINISHPROC)(void);
#define glFinish __glFinish
typedef void (APIENTRYP PFNGLFLUSHPROC)(void);
#define glFlush __glFlush
typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
#define glBlendFunc __glBlendFunc
typedef void (APIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
#define glLogicOp __glLogicOp
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
#define glStencilFunc __glStencilFunc
typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
#define glStencilOp __glStencilOp
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
#define glDepthFunc __glDepthFunc
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
#define glPixelStoref __glPixelStoref
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
#define glPixelStorei __glPixelStorei
typedef void (APIENTRYP PFNGLREADBUFFERPROC)(GLenum src);
#define glReadBuffer __glReadBuffer
typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
#define glReadPixels __glReadPixels
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean * data);
#define glGetBooleanv __glGetBooleanv
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble * data);
#define glGetDoublev __glGetDoublev
typedef GLenum (APIENTRYP PFNGLGETERRORPROC)(void);
#define glGetError __glGetError
typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat * data);
#define glGetFloatv __glGetFloatv
typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint * data);
#define glGetIntegerv __glGetIntegerv
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
#define glGetString __glGetString
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
#define glGetTexImage __glGetTexImage
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat * params);
#define glGetTexParameterfv __glGetTexParameterfv
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetTexParameteriv __glGetTexParameteriv
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat * params);
#define glGetTexLevelParameterfv __glGetTexLevelParameterfv
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint * params);
#define glGetTexLevelParameteriv __glGetTexLevelParameteriv
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
#define glIsEnabled __glIsEnabled
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble near, GLdouble far);
#define glDepthRange __glDepthRange
typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
#define glViewport __glViewport
typedef void (APIENTRYP PFNGLNEWLISTPROC)(GLuint list, GLenum mode);
#define glNewList __glNewList
typedef void (APIENTRYP PFNGLENDLISTPROC)(void);
#define glEndList __glEndList
typedef void (APIENTRYP PFNGLCALLLISTPROC)(GLuint list);
#define glCallList __glCallList
typedef void (APIENTRYP PFNGLCALLLISTSPROC)(GLsizei n, GLenum type, const void * lists);
#define glCallLists __glCallLists
typedef void (APIENTRYP PFNGLDELETELISTSPROC)(GLuint list, GLsizei range);
#define glDeleteLists __glDeleteLists
typedef GLuint (APIENTRYP PFNGLGENLISTSPROC)(GLsizei range);
#define glGenLists __glGenLists
typedef void (APIENTRYP PFNGLLISTBASEPROC)(GLuint base);
#define glListBase __glListBase
typedef void (APIENTRYP PFNGLBEGINPROC)(GLenum mode);
#define glBegin __glBegin
typedef void (APIENTRYP PFNGLBITMAPPROC)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap);
#define glBitmap __glBitmap
typedef void (APIENTRYP PFNGLCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
#define glColor3b __glColor3b
typedef void (APIENTRYP PFNGLCOLOR3BVPROC)(const GLbyte * v);
#define glColor3bv __glColor3bv
typedef void (APIENTRYP PFNGLCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
#define glColor3d __glColor3d
typedef void (APIENTRYP PFNGLCOLOR3DVPROC)(const GLdouble * v);
#define glColor3dv __glColor3dv
typedef void (APIENTRYP PFNGLCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
#define glColor3f __glColor3f
typedef void (APIENTRYP PFNGLCOLOR3FVPROC)(const GLfloat * v);
#define glColor3fv __glColor3fv
typedef void (APIENTRYP PFNGLCOLOR3IPROC)(GLint red, GLint green, GLint blue);
#define glColor3i __glColor3i
typedef void (APIENTRYP PFNGLCOLOR3IVPROC)(const GLint * v);
#define glColor3iv __glColor3iv
typedef void (APIENTRYP PFNGLCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
#define glColor3s __glColor3s
typedef void (APIENTRYP PFNGLCOLOR3SVPROC)(const GLshort * v);
#define glColor3sv __glColor3sv
typedef void (APIENTRYP PFNGLCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
#define glColor3ub __glColor3ub
typedef void (APIENTRYP PFNGLCOLOR3UBVPROC)(const GLubyte * v);
#define glColor3ubv __glColor3ubv
typedef void (APIENTRYP PFNGLCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
#define glColor3ui __glColor3ui
typedef void (APIENTRYP PFNGLCOLOR3UIVPROC)(const GLuint * v);
#define glColor3uiv __glColor3uiv
typedef void (APIENTRYP PFNGLCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
#define glColor3us __glColor3us
typedef void (APIENTRYP PFNGLCOLOR3USVPROC)(const GLushort * v);
#define glColor3usv __glColor3usv
typedef void (APIENTRYP PFNGLCOLOR4BPROC)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
#define glColor4b __glColor4b
typedef void (APIENTRYP PFNGLCOLOR4BVPROC)(const GLbyte * v);
#define glColor4bv __glColor4bv
typedef void (APIENTRYP PFNGLCOLOR4DPROC)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
#define glColor4d __glColor4d
typedef void (APIENTRYP PFNGLCOLOR4DVPROC)(const GLdouble * v);
#define glColor4dv __glColor4dv
typedef void (APIENTRYP PFNGLCOLOR4FPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glColor4f __glColor4f
typedef void (APIENTRYP PFNGLCOLOR4FVPROC)(const GLfloat * v);
#define glColor4fv __glColor4fv
typedef void (APIENTRYP PFNGLCOLOR4IPROC)(GLint red, GLint green, GLint blue, GLint alpha);
#define glColor4i __glColor4i
typedef void (APIENTRYP PFNGLCOLOR4IVPROC)(const GLint * v);
#define glColor4iv __glColor4iv
typedef void (APIENTRYP PFNGLCOLOR4SPROC)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
#define glColor4s __glColor4s
typedef void (APIENTRYP PFNGLCOLOR4SVPROC)(const GLshort * v);
#define glColor4sv __glColor4sv
typedef void (APIENTRYP PFNGLCOLOR4UBPROC)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
#define glColor4ub __glColor4ub
typedef void (APIENTRYP PFNGLCOLOR4UBVPROC)(const GLubyte * v);
#define glColor4ubv __glColor4ubv
typedef void (APIENTRYP PFNGLCOLOR4UIPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
#define glColor4ui __glColor4ui
typedef void (APIENTRYP PFNGLCOLOR4UIVPROC)(const GLuint * v);
#define glColor4uiv __glColor4uiv
typedef void (APIENTRYP PFNGLCOLOR4USPROC)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
#define glColor4us __glColor4us
typedef void (APIENTRYP PFNGLCOLOR4USVPROC)(const GLushort * v);
#define glColor4usv __glColor4usv
typedef void (APIENTRYP PFNGLEDGEFLAGPROC)(GLboolean flag);
#define glEdgeFlag __glEdgeFlag
typedef void (APIENTRYP PFNGLEDGEFLAGVPROC)(const GLboolean * flag);
#define glEdgeFlagv __glEdgeFlagv
typedef void (APIENTRYP PFNGLENDPROC)(void);
#define glEnd __glEnd
typedef void (APIENTRYP PFNGLINDEXDPROC)(GLdouble c);
#define glIndexd __glIndexd
typedef void (APIENTRYP PFNGLINDEXDVPROC)(const GLdouble * c);
#define glIndexdv __glIndexdv
typedef void (APIENTRYP PFNGLINDEXFPROC)(GLfloat c);
#define glIndexf __glIndexf
typedef void (APIENTRYP PFNGLINDEXFVPROC)(const GLfloat * c);
#define glIndexfv __glIndexfv
typedef void (APIENTRYP PFNGLINDEXIPROC)(GLint c);
#define glIndexi __glIndexi
typedef void (APIENTRYP PFNGLINDEXIVPROC)(const GLint * c);
#define glIndexiv __glIndexiv
typedef void (APIENTRYP PFNGLINDEXSPROC)(GLshort c);
#define glIndexs __glIndexs
typedef void (APIENTRYP PFNGLINDEXSVPROC)(const GLshort * c);
#define glIndexsv __glIndexsv
typedef void (APIENTRYP PFNGLNORMAL3BPROC)(GLbyte nx, GLbyte ny, GLbyte nz);
#define glNormal3b __glNormal3b
typedef void (APIENTRYP PFNGLNORMAL3BVPROC)(const GLbyte * v);
#define glNormal3bv __glNormal3bv
typedef void (APIENTRYP PFNGLNORMAL3DPROC)(GLdouble nx, GLdouble ny, GLdouble nz);
#define glNormal3d __glNormal3d
typedef void (APIENTRYP PFNGLNORMAL3DVPROC)(const GLdouble * v);
#define glNormal3dv __glNormal3dv
typedef void (APIENTRYP PFNGLNORMAL3FPROC)(GLfloat nx, GLfloat ny, GLfloat nz);
#define glNormal3f __glNormal3f
typedef void (APIENTRYP PFNGLNORMAL3FVPROC)(const GLfloat * v);
#define glNormal3fv __glNormal3fv
typedef void (APIENTRYP PFNGLNORMAL3IPROC)(GLint nx, GLint ny, GLint nz);
#define glNormal3i __glNormal3i
typedef void (APIENTRYP PFNGLNORMAL3IVPROC)(const GLint * v);
#define glNormal3iv __glNormal3iv
typedef void (APIENTRYP PFNGLNORMAL3SPROC)(GLshort nx, GLshort ny, GLshort nz);
#define glNormal3s __glNormal3s
typedef void (APIENTRYP PFNGLNORMAL3SVPROC)(const GLshort * v);
#define glNormal3sv __glNormal3sv
typedef void (APIENTRYP PFNGLRASTERPOS2DPROC)(GLdouble x, GLdouble y);
#define glRasterPos2d __glRasterPos2d
typedef void (APIENTRYP PFNGLRASTERPOS2DVPROC)(const GLdouble * v);
#define glRasterPos2dv __glRasterPos2dv
typedef void (APIENTRYP PFNGLRASTERPOS2FPROC)(GLfloat x, GLfloat y);
#define glRasterPos2f __glRasterPos2f
typedef void (APIENTRYP PFNGLRASTERPOS2FVPROC)(const GLfloat * v);
#define glRasterPos2fv __glRasterPos2fv
typedef void (APIENTRYP PFNGLRASTERPOS2IPROC)(GLint x, GLint y);
#define glRasterPos2i __glRasterPos2i
typedef void (APIENTRYP PFNGLRASTERPOS2IVPROC)(const GLint * v);
#define glRasterPos2iv __glRasterPos2iv
typedef void (APIENTRYP PFNGLRASTERPOS2SPROC)(GLshort x, GLshort y);
#define glRasterPos2s __glRasterPos2s
typedef void (APIENTRYP PFNGLRASTERPOS2SVPROC)(const GLshort * v);
#define glRasterPos2sv __glRasterPos2sv
typedef void (APIENTRYP PFNGLRASTERPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glRasterPos3d __glRasterPos3d
typedef void (APIENTRYP PFNGLRASTERPOS3DVPROC)(const GLdouble * v);
#define glRasterPos3dv __glRasterPos3dv
typedef void (APIENTRYP PFNGLRASTERPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glRasterPos3f __glRasterPos3f
typedef void (APIENTRYP PFNGLRASTERPOS3FVPROC)(const GLfloat * v);
#define glRasterPos3fv __glRasterPos3fv
typedef void (APIENTRYP PFNGLRASTERPOS3IPROC)(GLint x, GLint y, GLint z);
#define glRasterPos3i __glRasterPos3i
typedef void (APIENTRYP PFNGLRASTERPOS3IVPROC)(const GLint * v);
#define glRasterPos3iv __glRasterPos3iv
typedef void (APIENTRYP PFNGLRASTERPOS3SPROC)(GLshort x, GLshort y, GLshort z);
#define glRasterPos3s __glRasterPos3s
typedef void (APIENTRYP PFNGLRASTERPOS3SVPROC)(const GLshort * v);
#define glRasterPos3sv __glRasterPos3sv
typedef void (APIENTRYP PFNGLRASTERPOS4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glRasterPos4d __glRasterPos4d
typedef void (APIENTRYP PFNGLRASTERPOS4DVPROC)(const GLdouble * v);
#define glRasterPos4dv __glRasterPos4dv
typedef void (APIENTRYP PFNGLRASTERPOS4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glRasterPos4f __glRasterPos4f
typedef void (APIENTRYP PFNGLRASTERPOS4FVPROC)(const GLfloat * v);
#define glRasterPos4fv __glRasterPos4fv
typedef void (APIENTRYP PFNGLRASTERPOS4IPROC)(GLint x, GLint y, GLint z, GLint w);
#define glRasterPos4i __glRasterPos4i
typedef void (APIENTRYP PFNGLRASTERPOS4IVPROC)(const GLint * v);
#define glRasterPos4iv __glRasterPos4iv
typedef void (APIENTRYP PFNGLRASTERPOS4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
#define glRasterPos4s __glRasterPos4s
typedef void (APIENTRYP PFNGLRASTERPOS4SVPROC)(const GLshort * v);
#define glRasterPos4sv __glRasterPos4sv
typedef void (APIENTRYP PFNGLRECTDPROC)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
#define glRectd __glRectd
typedef void (APIENTRYP PFNGLRECTDVPROC)(const GLdouble * v1, const GLdouble * v2);
#define glRectdv __glRectdv
typedef void (APIENTRYP PFNGLRECTFPROC)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
#define glRectf __glRectf
typedef void (APIENTRYP PFNGLRECTFVPROC)(const GLfloat * v1, const GLfloat * v2);
#define glRectfv __glRectfv
typedef void (APIENTRYP PFNGLRECTIPROC)(GLint x1, GLint y1, GLint x2, GLint y2);
#define glRecti __glRecti
typedef void (APIENTRYP PFNGLRECTIVPROC)(const GLint * v1, const GLint * v2);
#define glRectiv __glRectiv
typedef void (APIENTRYP PFNGLRECTSPROC)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
#define glRects __glRects
typedef void (APIENTRYP PFNGLRECTSVPROC)(const GLshort * v1, const GLshort * v2);
#define glRectsv __glRectsv
typedef void (APIENTRYP PFNGLTEXCOORD1DPROC)(GLdouble s);
#define glTexCoord1d __glTexCoord1d
typedef void (APIENTRYP PFNGLTEXCOORD1DVPROC)(const GLdouble * v);
#define glTexCoord1dv __glTexCoord1dv
typedef void (APIENTRYP PFNGLTEXCOORD1FPROC)(GLfloat s);
#define glTexCoord1f __glTexCoord1f
typedef void (APIENTRYP PFNGLTEXCOORD1FVPROC)(const GLfloat * v);
#define glTexCoord1fv __glTexCoord1fv
typedef void (APIENTRYP PFNGLTEXCOORD1IPROC)(GLint s);
#define glTexCoord1i __glTexCoord1i
typedef void (APIENTRYP PFNGLTEXCOORD1IVPROC)(const GLint * v);
#define glTexCoord1iv __glTexCoord1iv
typedef void (APIENTRYP PFNGLTEXCOORD1SPROC)(GLshort s);
#define glTexCoord1s __glTexCoord1s
typedef void (APIENTRYP PFNGLTEXCOORD1SVPROC)(const GLshort * v);
#define glTexCoord1sv __glTexCoord1sv
typedef void (APIENTRYP PFNGLTEXCOORD2DPROC)(GLdouble s, GLdouble t);
#define glTexCoord2d __glTexCoord2d
typedef void (APIENTRYP PFNGLTEXCOORD2DVPROC)(const GLdouble * v);
#define glTexCoord2dv __glTexCoord2dv
typedef void (APIENTRYP PFNGLTEXCOORD2FPROC)(GLfloat s, GLfloat t);
#define glTexCoord2f __glTexCoord2f
typedef void (APIENTRYP PFNGLTEXCOORD2FVPROC)(const GLfloat * v);
#define glTexCoord2fv __glTexCoord2fv
typedef void (APIENTRYP PFNGLTEXCOORD2IPROC)(GLint s, GLint t);
#define glTexCoord2i __glTexCoord2i
typedef void (APIENTRYP PFNGLTEXCOORD2IVPROC)(const GLint * v);
#define glTexCoord2iv __glTexCoord2iv
typedef void (APIENTRYP PFNGLTEXCOORD2SPROC)(GLshort s, GLshort t);
#define glTexCoord2s __glTexCoord2s
typedef void (APIENTRYP PFNGLTEXCOORD2SVPROC)(const GLshort * v);
#define glTexCoord2sv __glTexCoord2sv
typedef void (APIENTRYP PFNGLTEXCOORD3DPROC)(GLdouble s, GLdouble t, GLdouble r);
#define glTexCoord3d __glTexCoord3d
typedef void (APIENTRYP PFNGLTEXCOORD3DVPROC)(const GLdouble * v);
#define glTexCoord3dv __glTexCoord3dv
typedef void (APIENTRYP PFNGLTEXCOORD3FPROC)(GLfloat s, GLfloat t, GLfloat r);
#define glTexCoord3f __glTexCoord3f
typedef void (APIENTRYP PFNGLTEXCOORD3FVPROC)(const GLfloat * v);
#define glTexCoord3fv __glTexCoord3fv
typedef void (APIENTRYP PFNGLTEXCOORD3IPROC)(GLint s, GLint t, GLint r);
#define glTexCoord3i __glTexCoord3i
typedef void (APIENTRYP PFNGLTEXCOORD3IVPROC)(const GLint * v);
#define glTexCoord3iv __glTexCoord3iv
typedef void (APIENTRYP PFNGLTEXCOORD3SPROC)(GLshort s, GLshort t, GLshort r);
#define glTexCoord3s __glTexCoord3s
typedef void (APIENTRYP PFNGLTEXCOORD3SVPROC)(const GLshort * v);
#define glTexCoord3sv __glTexCoord3sv
typedef void (APIENTRYP PFNGLTEXCOORD4DPROC)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#define glTexCoord4d __glTexCoord4d
typedef void (APIENTRYP PFNGLTEXCOORD4DVPROC)(const GLdouble * v);
#define glTexCoord4dv __glTexCoord4dv
typedef void (APIENTRYP PFNGLTEXCOORD4FPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#define glTexCoord4f __glTexCoord4f
typedef void (APIENTRYP PFNGLTEXCOORD4FVPROC)(const GLfloat * v);
#define glTexCoord4fv __glTexCoord4fv
typedef void (APIENTRYP PFNGLTEXCOORD4IPROC)(GLint s, GLint t, GLint r, GLint q);
#define glTexCoord4i __glTexCoord4i
typedef void (APIENTRYP PFNGLTEXCOORD4IVPROC)(const GLint * v);
#define glTexCoord4iv __glTexCoord4iv
typedef void (APIENTRYP PFNGLTEXCOORD4SPROC)(GLshort s, GLshort t, GLshort r, GLshort q);
#define glTexCoord4s __glTexCoord4s
typedef void (APIENTRYP PFNGLTEXCOORD4SVPROC)(const GLshort * v);
#define glTexCoord4sv __glTexCoord4sv
typedef void (APIENTRYP PFNGLVERTEX2DPROC)(GLdouble x, GLdouble y);
#define glVertex2d __glVertex2d
typedef void (APIENTRYP PFNGLVERTEX2DVPROC)(const GLdouble * v);
#define glVertex2dv __glVertex2dv
typedef void (APIENTRYP PFNGLVERTEX2FPROC)(GLfloat x, GLfloat y);
#define glVertex2f __glVertex2f
typedef void (APIENTRYP PFNGLVERTEX2FVPROC)(const GLfloat * v);
#define glVertex2fv __glVertex2fv
typedef void (APIENTRYP PFNGLVERTEX2IPROC)(GLint x, GLint y);
#define glVertex2i __glVertex2i
typedef void (APIENTRYP PFNGLVERTEX2IVPROC)(const GLint * v);
#define glVertex2iv __glVertex2iv
typedef void (APIENTRYP PFNGLVERTEX2SPROC)(GLshort x, GLshort y);
#define glVertex2s __glVertex2s
typedef void (APIENTRYP PFNGLVERTEX2SVPROC)(const GLshort * v);
#define glVertex2sv __glVertex2sv
typedef void (APIENTRYP PFNGLVERTEX3DPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glVertex3d __glVertex3d
typedef void (APIENTRYP PFNGLVERTEX3DVPROC)(const GLdouble * v);
#define glVertex3dv __glVertex3dv
typedef void (APIENTRYP PFNGLVERTEX3FPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glVertex3f __glVertex3f
typedef void (APIENTRYP PFNGLVERTEX3FVPROC)(const GLfloat * v);
#define glVertex3fv __glVertex3fv
typedef void (APIENTRYP PFNGLVERTEX3IPROC)(GLint x, GLint y, GLint z);
#define glVertex3i __glVertex3i
typedef void (APIENTRYP PFNGLVERTEX3IVPROC)(const GLint * v);
#define glVertex3iv __glVertex3iv
typedef void (APIENTRYP PFNGLVERTEX3SPROC)(GLshort x, GLshort y, GLshort z);
#define glVertex3s __glVertex3s
typedef void (APIENTRYP PFNGLVERTEX3SVPROC)(const GLshort * v);
#define glVertex3sv __glVertex3sv
typedef void (APIENTRYP PFNGLVERTEX4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertex4d __glVertex4d
typedef void (APIENTRYP PFNGLVERTEX4DVPROC)(const GLdouble * v);
#define glVertex4dv __glVertex4dv
typedef void (APIENTRYP PFNGLVERTEX4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertex4f __glVertex4f
typedef void (APIENTRYP PFNGLVERTEX4FVPROC)(const GLfloat * v);
#define glVertex4fv __glVertex4fv
typedef void (APIENTRYP PFNGLVERTEX4IPROC)(GLint x, GLint y, GLint z, GLint w);
#define glVertex4i __glVertex4i
typedef void (APIENTRYP PFNGLVERTEX4IVPROC)(const GLint * v);
#define glVertex4iv __glVertex4iv
typedef void (APIENTRYP PFNGLVERTEX4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertex4s __glVertex4s
typedef void (APIENTRYP PFNGLVERTEX4SVPROC)(const GLshort * v);
#define glVertex4sv __glVertex4sv
typedef void (APIENTRYP PFNGLCLIPPLANEPROC)(GLenum plane, const GLdouble * equation);
#define glClipPlane __glClipPlane
typedef void (APIENTRYP PFNGLCOLORMATERIALPROC)(GLenum face, GLenum mode);
#define glColorMaterial __glColorMaterial
typedef void (APIENTRYP PFNGLFOGFPROC)(GLenum pname, GLfloat param);
#define glFogf __glFogf
typedef void (APIENTRYP PFNGLFOGFVPROC)(GLenum pname, const GLfloat * params);
#define glFogfv __glFogfv
typedef void (APIENTRYP PFNGLFOGIPROC)(GLenum pname, GLint param);
#define glFogi __glFogi
typedef void (APIENTRYP PFNGLFOGIVPROC)(GLenum pname, const GLint * params);
#define glFogiv __glFogiv
typedef void (APIENTRYP PFNGLLIGHTFPROC)(GLenum light, GLenum pname, GLfloat param);
#define glLightf __glLightf
typedef void (APIENTRYP PFNGLLIGHTFVPROC)(GLenum light, GLenum pname, const GLfloat * params);
#define glLightfv __glLightfv
typedef void (APIENTRYP PFNGLLIGHTIPROC)(GLenum light, GLenum pname, GLint param);
#define glLighti __glLighti
typedef void (APIENTRYP PFNGLLIGHTIVPROC)(GLenum light, GLenum pname, const GLint * params);
#define glLightiv __glLightiv
typedef void (APIENTRYP PFNGLLIGHTMODELFPROC)(GLenum pname, GLfloat param);
#define glLightModelf __glLightModelf
typedef void (APIENTRYP PFNGLLIGHTMODELFVPROC)(GLenum pname, const GLfloat * params);
#define glLightModelfv __glLightModelfv
typedef void (APIENTRYP PFNGLLIGHTMODELIPROC)(GLenum pname, GLint param);
#define glLightModeli __glLightModeli
typedef void (APIENTRYP PFNGLLIGHTMODELIVPROC)(GLenum pname, const GLint * params);
#define glLightModeliv __glLightModeliv
typedef void (APIENTRYP PFNGLLINESTIPPLEPROC)(GLint factor, GLushort pattern);
#define glLineStipple __glLineStipple
typedef void (APIENTRYP PFNGLMATERIALFPROC)(GLenum face, GLenum pname, GLfloat param);
#define glMaterialf __glMaterialf
typedef void (APIENTRYP PFNGLMATERIALFVPROC)(GLenum face, GLenum pname, const GLfloat * params);
#define glMaterialfv __glMaterialfv
typedef void (APIENTRYP PFNGLMATERIALIPROC)(GLenum face, GLenum pname, GLint param);
#define glMateriali __glMateriali
typedef void (APIENTRYP PFNGLMATERIALIVPROC)(GLenum face, GLenum pname, const GLint * params);
#define glMaterialiv __glMaterialiv
typedef void (APIENTRYP PFNGLPOLYGONSTIPPLEPROC)(const GLubyte * mask);
#define glPolygonStipple __glPolygonStipple
typedef void (APIENTRYP PFNGLSHADEMODELPROC)(GLenum mode);
#define glShadeModel __glShadeModel
typedef void (APIENTRYP PFNGLTEXENVFPROC)(GLenum target, GLenum pname, GLfloat param);
#define glTexEnvf __glTexEnvf
typedef void (APIENTRYP PFNGLTEXENVFVPROC)(GLenum target, GLenum pname, const GLfloat * params);
#define glTexEnvfv __glTexEnvfv
typedef void (APIENTRYP PFNGLTEXENVIPROC)(GLenum target, GLenum pname, GLint param);
#define glTexEnvi __glTexEnvi
typedef void (APIENTRYP PFNGLTEXENVIVPROC)(GLenum target, GLenum pname, const GLint * params);
#define glTexEnviv __glTexEnviv
typedef void (APIENTRYP PFNGLTEXGENDPROC)(GLenum coord, GLenum pname, GLdouble param);
#define glTexGend __glTexGend
typedef void (APIENTRYP PFNGLTEXGENDVPROC)(GLenum coord, GLenum pname, const GLdouble * params);
#define glTexGendv __glTexGendv
typedef void (APIENTRYP PFNGLTEXGENFPROC)(GLenum coord, GLenum pname, GLfloat param);
#define glTexGenf __glTexGenf
typedef void (APIENTRYP PFNGLTEXGENFVPROC)(GLenum coord, GLenum pname, const GLfloat * params);
#define glTexGenfv __glTexGenfv
typedef void (APIENTRYP PFNGLTEXGENIPROC)(GLenum coord, GLenum pname, GLint param);
#define glTexGeni __glTexGeni
typedef void (APIENTRYP PFNGLTEXGENIVPROC)(GLenum coord, GLenum pname, const GLint * params);
#define glTexGeniv __glTexGeniv
typedef void (APIENTRYP PFNGLFEEDBACKBUFFERPROC)(GLsizei size, GLenum type, GLfloat * buffer);
#define glFeedbackBuffer __glFeedbackBuffer
typedef void (APIENTRYP PFNGLSELECTBUFFERPROC)(GLsizei size, GLuint * buffer);
#define glSelectBuffer __glSelectBuffer
typedef GLint (APIENTRYP PFNGLRENDERMODEPROC)(GLenum mode);
#define glRenderMode __glRenderMode
typedef void (APIENTRYP PFNGLINITNAMESPROC)(void);
#define glInitNames __glInitNames
typedef void (APIENTRYP PFNGLLOADNAMEPROC)(GLuint name);
#define glLoadName __glLoadName
typedef void (APIENTRYP PFNGLPASSTHROUGHPROC)(GLfloat token);
#define glPassThrough __glPassThrough
typedef void (APIENTRYP PFNGLPOPNAMEPROC)(void);
#define glPopName __glPopName
typedef void (APIENTRYP PFNGLPUSHNAMEPROC)(GLuint name);
#define glPushName __glPushName
typedef void (APIENTRYP PFNGLCLEARACCUMPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glClearAccum __glClearAccum
typedef void (APIENTRYP PFNGLCLEARINDEXPROC)(GLfloat c);
#define glClearIndex __glClearIndex
typedef void (APIENTRYP PFNGLINDEXMASKPROC)(GLuint mask);
#define glIndexMask __glIndexMask
typedef void (APIENTRYP PFNGLACCUMPROC)(GLenum op, GLfloat value);
#define glAccum __glAccum
typedef void (APIENTRYP PFNGLPOPATTRIBPROC)(void);
#define glPopAttrib __glPopAttrib
typedef void (APIENTRYP PFNGLPUSHATTRIBPROC)(GLbitfield mask);
#define glPushAttrib __glPushAttrib
typedef void (APIENTRYP PFNGLMAP1DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points);
#define glMap1d __glMap1d
typedef void (APIENTRYP PFNGLMAP1FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points);
#define glMap1f __glMap1f
typedef void (APIENTRYP PFNGLMAP2DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points);
#define glMap2d __glMap2d
typedef void (APIENTRYP PFNGLMAP2FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points);
#define glMap2f __glMap2f
typedef void (APIENTRYP PFNGLMAPGRID1DPROC)(GLint un, GLdouble u1, GLdouble u2);
#define glMapGrid1d __glMapGrid1d
typedef void (APIENTRYP PFNGLMAPGRID1FPROC)(GLint un, GLfloat u1, GLfloat u2);
#define glMapGrid1f __glMapGrid1f
typedef void (APIENTRYP PFNGLMAPGRID2DPROC)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
#define glMapGrid2d __glMapGrid2d
typedef void (APIENTRYP PFNGLMAPGRID2FPROC)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
#define glMapGrid2f __glMapGrid2f
typedef void (APIENTRYP PFNGLEVALCOORD1DPROC)(GLdouble u);
#define glEvalCoord1d __glEvalCoord1d
typedef void (APIENTRYP PFNGLEVALCOORD1DVPROC)(const GLdouble * u);
#define glEvalCoord1dv __glEvalCoord1dv
typedef void (APIENTRYP PFNGLEVALCOORD1FPROC)(GLfloat u);
#define glEvalCoord1f __glEvalCoord1f
typedef void (APIENTRYP PFNGLEVALCOORD1FVPROC)(const GLfloat * u);
#define glEvalCoord1fv __glEvalCoord1fv
typedef void (APIENTRYP PFNGLEVALCOORD2DPROC)(GLdouble u, GLdouble v);
#define glEvalCoord2d __glEvalCoord2d
typedef void (APIENTRYP PFNGLEVALCOORD2DVPROC)(const GLdouble * u);
#define glEvalCoord2dv __glEvalCoord2dv
typedef void (APIENTRYP PFNGLEVALCOORD2FPROC)(GLfloat u, GLfloat v);
#define glEvalCoord2f __glEvalCoord2f
typedef void (APIENTRYP PFNGLEVALCOORD2FVPROC)(const GLfloat * u);
#define glEvalCoord2fv __glEvalCoord2fv
typedef void (APIENTRYP PFNGLEVALMESH1PROC)(GLenum mode, GLint i1, GLint i2);
#define glEvalMesh1 __glEvalMesh1
typedef void (APIENTRYP PFNGLEVALPOINT1PROC)(GLint i);
#define glEvalPoint1 __glEvalPoint1
typedef void (APIENTRYP PFNGLEVALMESH2PROC)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
#define glEvalMesh2 __glEvalMesh2
typedef void (APIENTRYP PFNGLEVALPOINT2PROC)(GLint i, GLint j);
#define glEvalPoint2 __glEvalPoint2
typedef void (APIENTRYP PFNGLALPHAFUNCPROC)(GLenum func, GLfloat ref);
#define glAlphaFunc __glAlphaFunc
typedef void (APIENTRYP PFNGLPIXELZOOMPROC)(GLfloat xfactor, GLfloat yfactor);
#define glPixelZoom __glPixelZoom
typedef void (APIENTRYP PFNGLPIXELTRANSFERFPROC)(GLenum pname, GLfloat param);
#define glPixelTransferf __glPixelTransferf
typedef void (APIENTRYP PFNGLPIXELTRANSFERIPROC)(GLenum pname, GLint param);
#define glPixelTransferi __glPixelTransferi
typedef void (APIENTRYP PFNGLPIXELMAPFVPROC)(GLenum map, GLsizei mapsize, const GLfloat * values);
#define glPixelMapfv __glPixelMapfv
typedef void (APIENTRYP PFNGLPIXELMAPUIVPROC)(GLenum map, GLsizei mapsize, const GLuint * values);
#define glPixelMapuiv __glPixelMapuiv
typedef void (APIENTRYP PFNGLPIXELMAPUSVPROC)(GLenum map, GLsizei mapsize, const GLushort * values);
#define glPixelMapusv __glPixelMapusv
typedef void (APIENTRYP PFNGLCOPYPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
#define glCopyPixels __glCopyPixels
typedef void (APIENTRYP PFNGLDRAWPIXELSPROC)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glDrawPixels __glDrawPixels
typedef void (APIENTRYP PFNGLGETCLIPPLANEPROC)(GLenum plane, GLdouble * equation);
#define glGetClipPlane __glGetClipPlane
typedef void (APIENTRYP PFNGLGETLIGHTFVPROC)(GLenum light, GLenum pname, GLfloat * params);
#define glGetLightfv __glGetLightfv
typedef void (APIENTRYP PFNGLGETLIGHTIVPROC)(GLenum light, GLenum pname, GLint * params);
#define glGetLightiv __glGetLightiv
typedef void (APIENTRYP PFNGLGETMAPDVPROC)(GLenum target, GLenum query, GLdouble * v);
#define glGetMapdv __glGetMapdv
typedef void (APIENTRYP PFNGLGETMAPFVPROC)(GLenum target, GLenum query, GLfloat * v);
#define glGetMapfv __glGetMapfv
typedef void (APIENTRYP PFNGLGETMAPIVPROC)(GLenum target, GLenum query, GLint * v);
#define glGetMapiv __glGetMapiv
typedef void (APIENTRYP PFNGLGETMATERIALFVPROC)(GLenum face, GLenum pname, GLfloat * params);
#define glGetMaterialfv __glGetMaterialfv
typedef void (APIENTRYP PFNGLGETMATERIALIVPROC)(GLenum face, GLenum pname, GLint * params);
#define glGetMaterialiv __glGetMaterialiv
typedef void (APIENTRYP PFNGLGETPIXELMAPFVPROC)(GLenum map, GLfloat * values);
#define glGetPixelMapfv __glGetPixelMapfv
typedef void (APIENTRYP PFNGLGETPIXELMAPUIVPROC)(GLenum map, GLuint * values);
#define glGetPixelMapuiv __glGetPixelMapuiv
typedef void (APIENTRYP PFNGLGETPIXELMAPUSVPROC)(GLenum map, GLushort * values);
#define glGetPixelMapusv __glGetPixelMapusv
typedef void (APIENTRYP PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte * mask);
#define glGetPolygonStipple __glGetPolygonStipple
typedef void (APIENTRYP PFNGLGETTEXENVFVPROC)(GLenum target, GLenum pname, GLfloat * params);
#define glGetTexEnvfv __glGetTexEnvfv
typedef void (APIENTRYP PFNGLGETTEXENVIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetTexEnviv __glGetTexEnviv
typedef void (APIENTRYP PFNGLGETTEXGENDVPROC)(GLenum coord, GLenum pname, GLdouble * params);
#define glGetTexGendv __glGetTexGendv
typedef void (APIENTRYP PFNGLGETTEXGENFVPROC)(GLenum coord, GLenum pname, GLfloat * params);
#define glGetTexGenfv __glGetTexGenfv
typedef void (APIENTRYP PFNGLGETTEXGENIVPROC)(GLenum coord, GLenum pname, GLint * params);
#define glGetTexGeniv __glGetTexGeniv
typedef GLboolean (APIENTRYP PFNGLISLISTPROC)(GLuint list);
#define glIsList __glIsList
typedef void (APIENTRYP PFNGLFRUSTUMPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glFrustum __glFrustum
typedef void (APIENTRYP PFNGLLOADIDENTITYPROC)(void);
#define glLoadIdentity __glLoadIdentity
typedef void (APIENTRYP PFNGLLOADMATRIXFPROC)(const GLfloat * m);
#define glLoadMatrixf __glLoadMatrixf
typedef void (APIENTRYP PFNGLLOADMATRIXDPROC)(const GLdouble * m);
#define glLoadMatrixd __glLoadMatrixd
typedef void (APIENTRYP PFNGLMATRIXMODEPROC)(GLenum mode);
#define glMatrixMode __glMatrixMode
typedef void (APIENTRYP PFNGLMULTMATRIXFPROC)(const GLfloat * m);
#define glMultMatrixf __glMultMatrixf
typedef void (APIENTRYP PFNGLMULTMATRIXDPROC)(const GLdouble * m);
#define glMultMatrixd __glMultMatrixd
typedef void (APIENTRYP PFNGLORTHOPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glOrtho __glOrtho
typedef void (APIENTRYP PFNGLPOPMATRIXPROC)(void);
#define glPopMatrix __glPopMatrix
typedef void (APIENTRYP PFNGLPUSHMATRIXPROC)(void);
#define glPushMatrix __glPushMatrix
typedef void (APIENTRYP PFNGLROTATEDPROC)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
#define glRotated __glRotated
typedef void (APIENTRYP PFNGLROTATEFPROC)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
#define glRotatef __glRotatef
typedef void (APIENTRYP PFNGLSCALEDPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glScaled __glScaled
typedef void (APIENTRYP PFNGLSCALEFPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glScalef __glScalef
typedef void (APIENTRYP PFNGLTRANSLATEDPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glTranslated __glTranslated
typedef void (APIENTRYP PFNGLTRANSLATEFPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glTranslatef __glTranslatef
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
#define glDrawArrays __glDrawArrays
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices);
#define glDrawElements __glDrawElements
typedef void (APIENTRYP PFNGLGETPOINTERVPROC)(GLenum pname, void ** params);
#define glGetPointerv __glGetPointerv
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
#define glPolygonOffset __glPolygonOffset
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyTexImage1D __glCopyTexImage1D
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyTexImage2D __glCopyTexImage2D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTexSubImage1D __glCopyTexSubImage1D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage2D __glCopyTexSubImage2D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage1D __glTexSubImage1D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage2D __glTexSubImage2D
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
#define glBindTexture __glBindTexture
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint * textures);
#define glDeleteTextures __glDeleteTextures
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint * textures);
#define glGenTextures __glGenTextures
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
#define glIsTexture __glIsTexture
typedef void (APIENTRYP PFNGLARRAYELEMENTPROC)(GLint i);
#define glArrayElement __glArrayElement
typedef void (APIENTRYP PFNGLCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glColorPointer __glColorPointer
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEPROC)(GLenum array);
#define glDisableClientState __glDisableClientState
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTERPROC)(GLsizei stride, const void * pointer);
#define glEdgeFlagPointer __glEdgeFlagPointer
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEPROC)(GLenum array);
#define glEnableClientState __glEnableClientState
typedef void (APIENTRYP PFNGLINDEXPOINTERPROC)(GLenum type, GLsizei stride, const void * pointer);
#define glIndexPointer __glIndexPointer
typedef void (APIENTRYP PFNGLINTERLEAVEDARRAYSPROC)(GLenum format, GLsizei stride, const void * pointer);
#define glInterleavedArrays __glInterleavedArrays
typedef void (APIENTRYP PFNGLNORMALPOINTERPROC)(GLenum type, GLsizei stride, const void * pointer);
#define glNormalPointer __glNormalPointer
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glTexCoordPointer __glTexCoordPointer
typedef void (APIENTRYP PFNGLVERTEXPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexPointer __glVertexPointer
typedef GLboolean (APIENTRYP PFNGLARETEXTURESRESIDENTPROC)(GLsizei n, const GLuint * textures, GLboolean * residences);
#define glAreTexturesResident __glAreTexturesResident
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESPROC)(GLsizei n, const GLuint * textures, const GLfloat * priorities);
#define glPrioritizeTextures __glPrioritizeTextures
typedef void (APIENTRYP PFNGLINDEXUBPROC)(GLubyte c);
#define glIndexub __glIndexub
typedef void (APIENTRYP PFNGLINDEXUBVPROC)(const GLubyte * c);
#define glIndexubv __glIndexubv
typedef void (APIENTRYP PFNGLPOPCLIENTATTRIBPROC)(void);
#define glPopClientAttrib __glPopClientAttrib
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield mask);
#define glPushClientAttrib __glPushClientAttrib
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
#define glDrawRangeElements __glDrawRangeElements
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage3D __glTexImage3D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage3D __glTexSubImage3D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage3D __glCopyTexSubImage3D
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
#define glActiveTexture __glActiveTexture
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
#define glSampleCoverage __glSampleCoverage
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage3D __glCompressedTexImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage2D __glCompressedTexImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage1D __glCompressedTexImage1D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage3D __glCompressedTexSubImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage2D __glCompressedTexSubImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage1D __glCompressedTexSubImage1D
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint level, void * img);
#define glGetCompressedTexImage __glGetCompressedTexImage
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREPROC)(GLenum texture);
#define glClientActiveTexture __glClientActiveTexture
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DPROC)(GLenum target, GLdouble s);
#define glMultiTexCoord1d __glMultiTexCoord1d
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord1dv __glMultiTexCoord1dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FPROC)(GLenum target, GLfloat s);
#define glMultiTexCoord1f __glMultiTexCoord1f
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord1fv __glMultiTexCoord1fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IPROC)(GLenum target, GLint s);
#define glMultiTexCoord1i __glMultiTexCoord1i
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord1iv __glMultiTexCoord1iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SPROC)(GLenum target, GLshort s);
#define glMultiTexCoord1s __glMultiTexCoord1s
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord1sv __glMultiTexCoord1sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DPROC)(GLenum target, GLdouble s, GLdouble t);
#define glMultiTexCoord2d __glMultiTexCoord2d
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord2dv __glMultiTexCoord2dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FPROC)(GLenum target, GLfloat s, GLfloat t);
#define glMultiTexCoord2f __glMultiTexCoord2f
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord2fv __glMultiTexCoord2fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IPROC)(GLenum target, GLint s, GLint t);
#define glMultiTexCoord2i __glMultiTexCoord2i
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord2iv __glMultiTexCoord2iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SPROC)(GLenum target, GLshort s, GLshort t);
#define glMultiTexCoord2s __glMultiTexCoord2s
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord2sv __glMultiTexCoord2sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
#define glMultiTexCoord3d __glMultiTexCoord3d
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord3dv __glMultiTexCoord3dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
#define glMultiTexCoord3f __glMultiTexCoord3f
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord3fv __glMultiTexCoord3fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IPROC)(GLenum target, GLint s, GLint t, GLint r);
#define glMultiTexCoord3i __glMultiTexCoord3i
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord3iv __glMultiTexCoord3iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
#define glMultiTexCoord3s __glMultiTexCoord3s
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord3sv __glMultiTexCoord3sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#define glMultiTexCoord4d __glMultiTexCoord4d
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord4dv __glMultiTexCoord4dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#define glMultiTexCoord4f __glMultiTexCoord4f
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord4fv __glMultiTexCoord4fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
#define glMultiTexCoord4i __glMultiTexCoord4i
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord4iv __glMultiTexCoord4iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
#define glMultiTexCoord4s __glMultiTexCoord4s
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord4sv __glMultiTexCoord4sv
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat * m);
#define glLoadTransposeMatrixf __glLoadTransposeMatrixf
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble * m);
#define glLoadTransposeMatrixd __glLoadTransposeMatrixd
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat * m);
#define glMultTransposeMatrixf __glMultTransposeMatrixf
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble * m);
#define glMultTransposeMatrixd __glMultTransposeMatrixd
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
#define glBlendFuncSeparate __glBlendFuncSeparate
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
#define glMultiDrawArrays __glMultiDrawArrays
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount);
#define glMultiDrawElements __glMultiDrawElements
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
#define glPointParameterf __glPointParameterf
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat * params);
#define glPointParameterfv __glPointParameterfv
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
#define glPointParameteri __glPointParameteri
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC)(GLenum pname, const GLint * params);
#define glPointParameteriv __glPointParameteriv
typedef void (APIENTRYP PFNGLFOGCOORDFPROC)(GLfloat coord);
#define glFogCoordf __glFogCoordf
typedef void (APIENTRYP PFNGLFOGCOORDFVPROC)(const GLfloat * coord);
#define glFogCoordfv __glFogCoordfv
typedef void (APIENTRYP PFNGLFOGCOORDDPROC)(GLdouble coord);
#define glFogCoordd __glFogCoordd
typedef void (APIENTRYP PFNGLFOGCOORDDVPROC)(const GLdouble * coord);
#define glFogCoorddv __glFogCoorddv
typedef void (APIENTRYP PFNGLFOGCOORDPOINTERPROC)(GLenum type, GLsizei stride, const void * pointer);
#define glFogCoordPointer __glFogCoordPointer
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
#define glSecondaryColor3b __glSecondaryColor3b
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte * v);
#define glSecondaryColor3bv __glSecondaryColor3bv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
#define glSecondaryColor3d __glSecondaryColor3d
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble * v);
#define glSecondaryColor3dv __glSecondaryColor3dv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
#define glSecondaryColor3f __glSecondaryColor3f
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat * v);
#define glSecondaryColor3fv __glSecondaryColor3fv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IPROC)(GLint red, GLint green, GLint blue);
#define glSecondaryColor3i __glSecondaryColor3i
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IVPROC)(const GLint * v);
#define glSecondaryColor3iv __glSecondaryColor3iv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
#define glSecondaryColor3s __glSecondaryColor3s
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVPROC)(const GLshort * v);
#define glSecondaryColor3sv __glSecondaryColor3sv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
#define glSecondaryColor3ub __glSecondaryColor3ub
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte * v);
#define glSecondaryColor3ubv __glSecondaryColor3ubv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
#define glSecondaryColor3ui __glSecondaryColor3ui
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint * v);
#define glSecondaryColor3uiv __glSecondaryColor3uiv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
#define glSecondaryColor3us __glSecondaryColor3us
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USVPROC)(const GLushort * v);
#define glSecondaryColor3usv __glSecondaryColor3usv
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glSecondaryColorPointer __glSecondaryColorPointer
typedef void (APIENTRYP PFNGLWINDOWPOS2DPROC)(GLdouble x, GLdouble y);
#define glWindowPos2d __glWindowPos2d
typedef void (APIENTRYP PFNGLWINDOWPOS2DVPROC)(const GLdouble * v);
#define glWindowPos2dv __glWindowPos2dv
typedef void (APIENTRYP PFNGLWINDOWPOS2FPROC)(GLfloat x, GLfloat y);
#define glWindowPos2f __glWindowPos2f
typedef void (APIENTRYP PFNGLWINDOWPOS2FVPROC)(const GLfloat * v);
#define glWindowPos2fv __glWindowPos2fv
typedef void (APIENTRYP PFNGLWINDOWPOS2IPROC)(GLint x, GLint y);
#define glWindowPos2i __glWindowPos2i
typedef void (APIENTRYP PFNGLWINDOWPOS2IVPROC)(const GLint * v);
#define glWindowPos2iv __glWindowPos2iv
typedef void (APIENTRYP PFNGLWINDOWPOS2SPROC)(GLshort x, GLshort y);
#define glWindowPos2s __glWindowPos2s
typedef void (APIENTRYP PFNGLWINDOWPOS2SVPROC)(const GLshort * v);
#define glWindowPos2sv __glWindowPos2sv
typedef void (APIENTRYP PFNGLWINDOWPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glWindowPos3d __glWindowPos3d
typedef void (APIENTRYP PFNGLWINDOWPOS3DVPROC)(const GLdouble * v);
#define glWindowPos3dv __glWindowPos3dv
typedef void (APIENTRYP PFNGLWINDOWPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glWindowPos3f __glWindowPos3f
typedef void (APIENTRYP PFNGLWINDOWPOS3FVPROC)(const GLfloat * v);
#define glWindowPos3fv __glWindowPos3fv
typedef void (APIENTRYP PFNGLWINDOWPOS3IPROC)(GLint x, GLint y, GLint z);
#define glWindowPos3i __glWindowPos3i
typedef void (APIENTRYP PFNGLWINDOWPOS3IVPROC)(const GLint * v);
#define glWindowPos3iv __glWindowPos3iv
typedef void (APIENTRYP PFNGLWINDOWPOS3SPROC)(GLshort x, GLshort y, GLshort z);
#define glWindowPos3s __glWindowPos3s
typedef void (APIENTRYP PFNGLWINDOWPOS3SVPROC)(const GLshort * v);
#define glWindowPos3sv __glWindowPos3sv
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
#define glBlendColor __glBlendColor
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
#define glBlendEquation __glBlendEquation
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
#define glGenQueries __glGenQueries
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint * ids);
#define glDeleteQueries __glDeleteQueries
typedef GLboolean (APIENTRYP PFNGLISQUERYPROC)(GLuint id);
#define glIsQuery __glIsQuery
typedef void (APIENTRYP PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
#define glBeginQuery __glBeginQuery
typedef void (APIENTRYP PFNGLENDQUERYPROC)(GLenum target);
#define glEndQuery __glEndQuery
typedef void (APIENTRYP PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetQueryiv __glGetQueryiv
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC)(GLuint id, GLenum pname, GLint * params);
#define glGetQueryObjectiv __glGetQueryObjectiv
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint * params);
#define glGetQueryObjectuiv __glGetQueryObjectuiv
typedef void (APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
#define glBindBuffer __glBindBuffer
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint * buffers);
#define glDeleteBuffers __glDeleteBuffers
typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint * buffers);
#define glGenBuffers __glGenBuffers
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
#define glIsBuffer __glIsBuffer
typedef void (APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
#define glBufferData __glBufferData
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
#define glBufferSubData __glBufferSubData
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, void * data);
#define glGetBufferSubData __glGetBufferSubData
typedef void * (APIENTRYP PFNGLMAPBUFFERPROC)(GLenum target, GLenum access);
#define glMapBuffer __glMapBuffer
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum target);
#define glUnmapBuffer __glUnmapBuffer
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetBufferParameteriv __glGetBufferParameteriv
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void ** params);
#define glGetBufferPointerv __glGetBufferPointerv
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
#define glBlendEquationSeparate __glBlendEquationSeparate
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum * bufs);
#define glDrawBuffers __glDrawBuffers
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
#define glStencilOpSeparate __glStencilOpSeparate
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
#define glStencilFuncSeparate __glStencilFuncSeparate
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
#define glStencilMaskSeparate __glStencilMaskSeparate
typedef void (APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
#define glAttachShader __glAttachShader
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar * name);
#define glBindAttribLocation __glBindAttribLocation
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
#define glCompileShader __glCompileShader
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC)(void);
#define glCreateProgram __glCreateProgram
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
#define glCreateShader __glCreateShader
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
#define glDeleteProgram __glDeleteProgram
typedef void (APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
#define glDeleteShader __glDeleteShader
typedef void (APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
#define glDetachShader __glDetachShader
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
#define glDisableVertexAttribArray __glDisableVertexAttribArray
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
#define glEnableVertexAttribArray __glEnableVertexAttribArray
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
#define glGetActiveAttrib __glGetActiveAttrib
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
#define glGetActiveUniform __glGetActiveUniform
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
#define glGetAttachedShaders __glGetAttachedShaders
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar * name);
#define glGetAttribLocation __glGetAttribLocation
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint * params);
#define glGetProgramiv __glGetProgramiv
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetProgramInfoLog __glGetProgramInfoLog
typedef void (APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint * params);
#define glGetShaderiv __glGetShaderiv
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetShaderInfoLog __glGetShaderInfoLog
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
#define glGetShaderSource __glGetShaderSource
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar * name);
#define glGetUniformLocation __glGetUniformLocation
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat * params);
#define glGetUniformfv __glGetUniformfv
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint * params);
#define glGetUniformiv __glGetUniformiv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribdv __glGetVertexAttribdv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat * params);
#define glGetVertexAttribfv __glGetVertexAttribfv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint * params);
#define glGetVertexAttribiv __glGetVertexAttribiv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void ** pointer);
#define glGetVertexAttribPointerv __glGetVertexAttribPointerv
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
#define glIsProgram __glIsProgram
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC)(GLuint shader);
#define glIsShader __glIsShader
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
#define glLinkProgram __glLinkProgram
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length);
#define glShaderSource __glShaderSource
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
#define glUseProgram __glUseProgram
typedef void (APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
#define glUniform1f __glUniform1f
typedef void (APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
#define glUniform2f __glUniform2f
typedef void (APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glUniform3f __glUniform3f
typedef void (APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glUniform4f __glUniform4f
typedef void (APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
#define glUniform1i __glUniform1i
typedef void (APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
#define glUniform2i __glUniform2i
typedef void (APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
#define glUniform3i __glUniform3i
typedef void (APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glUniform4i __glUniform4i
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform1fv __glUniform1fv
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform2fv __glUniform2fv
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform3fv __glUniform3fv
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform4fv __glUniform4fv
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform1iv __glUniform1iv
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform2iv __glUniform2iv
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform3iv __glUniform3iv
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform4iv __glUniform4iv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix2fv __glUniformMatrix2fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3fv __glUniformMatrix3fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4fv __glUniformMatrix4fv
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
#define glValidateProgram __glValidateProgram
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC)(GLuint index, GLdouble x);
#define glVertexAttrib1d __glVertexAttrib1d
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib1dv __glVertexAttrib1dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
#define glVertexAttrib1f __glVertexAttrib1f
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib1fv __glVertexAttrib1fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC)(GLuint index, GLshort x);
#define glVertexAttrib1s __glVertexAttrib1s
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib1sv __glVertexAttrib1sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttrib2d __glVertexAttrib2d
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib2dv __glVertexAttrib2dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
#define glVertexAttrib2f __glVertexAttrib2f
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib2fv __glVertexAttrib2fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC)(GLuint index, GLshort x, GLshort y);
#define glVertexAttrib2s __glVertexAttrib2s
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib2sv __glVertexAttrib2sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttrib3d __glVertexAttrib3d
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib3dv __glVertexAttrib3dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
#define glVertexAttrib3f __glVertexAttrib3f
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib3fv __glVertexAttrib3fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
#define glVertexAttrib3s __glVertexAttrib3s
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib3sv __glVertexAttrib3sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC)(GLuint index, const GLbyte * v);
#define glVertexAttrib4Nbv __glVertexAttrib4Nbv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC)(GLuint index, const GLint * v);
#define glVertexAttrib4Niv __glVertexAttrib4Niv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib4Nsv __glVertexAttrib4Nsv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
#define glVertexAttrib4Nub __glVertexAttrib4Nub
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC)(GLuint index, const GLubyte * v);
#define glVertexAttrib4Nubv __glVertexAttrib4Nubv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttrib4Nuiv __glVertexAttrib4Nuiv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC)(GLuint index, const GLushort * v);
#define glVertexAttrib4Nusv __glVertexAttrib4Nusv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC)(GLuint index, const GLbyte * v);
#define glVertexAttrib4bv __glVertexAttrib4bv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttrib4d __glVertexAttrib4d
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib4dv __glVertexAttrib4dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertexAttrib4f __glVertexAttrib4f
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib4fv __glVertexAttrib4fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC)(GLuint index, const GLint * v);
#define glVertexAttrib4iv __glVertexAttrib4iv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertexAttrib4s __glVertexAttrib4s
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib4sv __glVertexAttrib4sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC)(GLuint index, const GLubyte * v);
#define glVertexAttrib4ubv __glVertexAttrib4ubv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttrib4uiv __glVertexAttrib4uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC)(GLuint index, const GLushort * v);
#define glVertexAttrib4usv __glVertexAttrib4usv
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
#define glVertexAttribPointer __glVertexAttribPointer
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
#define glUniformMatrix2x3fv __glUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3x2fv __glUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix2x4fv __glUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4x2fv __glUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3x4fv __glUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4x3fv __glUniformMatrix4x3fv
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
#define glColorMaski __glColorMaski
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum target, GLuint index, GLboolean * data);
#define glGetBooleani_v __glGetBooleani_v
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint * data);
#define glGetIntegeri_v __glGetIntegeri_v
typedef void (APIENTRYP PFNGLENABLEIPROC)(GLenum target, GLuint index);
#define glEnablei __glEnablei
typedef void (APIENTRYP PFNGLDISABLEIPROC)(GLenum target, GLuint index);
#define glDisablei __glDisablei
typedef GLboolean (APIENTRYP PFNGLISENABLEDIPROC)(GLenum target, GLuint index);
#define glIsEnabledi __glIsEnabledi
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
#define glBeginTransformFeedback __glBeginTransformFeedback
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)(void);
#define glEndTransformFeedback __glEndTransformFeedback
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glBindBufferRange __glBindBufferRange
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
#define glBindBufferBase __glBindBufferBase
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);
#define glTransformFeedbackVaryings __glTransformFeedbackVaryings
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
#define glGetTransformFeedbackVarying __glGetTransformFeedbackVarying
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC)(GLenum target, GLenum clamp);
#define glClampColor __glClampColor
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC)(GLuint id, GLenum mode);
#define glBeginConditionalRender __glBeginConditionalRender
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC)(void);
#define glEndConditionalRender __glEndConditionalRender
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribIPointer __glVertexAttribIPointer
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint * params);
#define glGetVertexAttribIiv __glGetVertexAttribIiv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint * params);
#define glGetVertexAttribIuiv __glGetVertexAttribIuiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC)(GLuint index, GLint x);
#define glVertexAttribI1i __glVertexAttribI1i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC)(GLuint index, GLint x, GLint y);
#define glVertexAttribI2i __glVertexAttribI2i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC)(GLuint index, GLint x, GLint y, GLint z);
#define glVertexAttribI3i __glVertexAttribI3i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
#define glVertexAttribI4i __glVertexAttribI4i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC)(GLuint index, GLuint x);
#define glVertexAttribI1ui __glVertexAttribI1ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC)(GLuint index, GLuint x, GLuint y);
#define glVertexAttribI2ui __glVertexAttribI2ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
#define glVertexAttribI3ui __glVertexAttribI3ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
#define glVertexAttribI4ui __glVertexAttribI4ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI1iv __glVertexAttribI1iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI2iv __glVertexAttribI2iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI3iv __glVertexAttribI3iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI4iv __glVertexAttribI4iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI1uiv __glVertexAttribI1uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI2uiv __glVertexAttribI2uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI3uiv __glVertexAttribI3uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI4uiv __glVertexAttribI4uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC)(GLuint index, const GLbyte * v);
#define glVertexAttribI4bv __glVertexAttribI4bv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttribI4sv __glVertexAttribI4sv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC)(GLuint index, const GLubyte * v);
#define glVertexAttribI4ubv __glVertexAttribI4ubv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC)(GLuint index, const GLushort * v);
#define glVertexAttribI4usv __glVertexAttribI4usv
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint * params);
#define glGetUniformuiv __glGetUniformuiv
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program, GLuint color, const GLchar * name);
#define glBindFragDataLocation __glBindFragDataLocation
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar * name);
#define glGetFragDataLocation __glGetFragDataLocation
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
#define glUniform1ui __glUniform1ui
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
#define glUniform2ui __glUniform2ui
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glUniform3ui __glUniform3ui
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glUniform4ui __glUniform4ui
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform1uiv __glUniform1uiv
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform2uiv __glUniform2uiv
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform3uiv __glUniform3uiv
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform4uiv __glUniform4uiv
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, const GLint * params);
#define glTexParameterIiv __glTexParameterIiv
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, const GLuint * params);
#define glTexParameterIuiv __glTexParameterIuiv
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetTexParameterIiv __glGetTexParameterIiv
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, GLuint * params);
#define glGetTexParameterIuiv __glGetTexParameterIuiv
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint * value);
#define glClearBufferiv __glClearBufferiv
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint * value);
#define glClearBufferuiv __glClearBufferuiv
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat * value);
#define glClearBufferfv __glClearBufferfv
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
#define glClearBufferfi __glClearBufferfi
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
#define glGetStringi __glGetStringi
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
#define glIsRenderbuffer __glIsRenderbuffer
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
#define glBindRenderbuffer __glBindRenderbuffer
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint * renderbuffers);
#define glDeleteRenderbuffers __glDeleteRenderbuffers
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint * renderbuffers);
#define glGenRenderbuffers __glGenRenderbuffers
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorage __glRenderbufferStorage
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetRenderbufferParameteriv __glGetRenderbufferParameteriv
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
#define glIsFramebuffer __glIsFramebuffer
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
#define glBindFramebuffer __glBindFramebuffer
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint * framebuffers);
#define glDeleteFramebuffers __glDeleteFramebuffers
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint * framebuffers);
#define glGenFramebuffers __glGenFramebuffers
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
#define glCheckFramebufferStatus __glCheckFramebufferStatus
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture1D __glFramebufferTexture1D
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture2D __glFramebufferTexture2D
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
#define glFramebufferTexture3D __glFramebufferTexture3D
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glFramebufferRenderbuffer __glFramebufferRenderbuffer
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
#define glGetFramebufferAttachmentParameteriv __glGetFramebufferAttachmentParameteriv
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
#define glGenerateMipmap __glGenerateMipmap
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitFramebuffer __glBlitFramebuffer
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisample __glRenderbufferStorageMultisample
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glFramebufferTextureLayer __glFramebufferTextureLayer
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
#define glMapBufferRange __glMapBufferRange
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
#define glFlushMappedBufferRange __glFlushMappedBufferRange
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
#define glBindVertexArray __glBindVertexArray
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint * arrays);
#define glDeleteVertexArrays __glDeleteVertexArrays
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint * arrays);
#define glGenVertexArrays __glGenVertexArrays
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
#define glIsVertexArray __glIsVertexArray
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
#define glDrawArraysInstanced __glDrawArraysInstanced
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount);
#define glDrawElementsInstanced __glDrawElementsInstanced
typedef void (APIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
#define glTexBuffer __glTexBuffer
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
#define glPrimitiveRestartIndex __glPrimitiveRestartIndex
#define GL_COPY_READ_BUFFER 0x8F36
#define GL_COPY_WRITE_BUFFER 0x8F37
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyBufferSubData __glCopyBufferSubData
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
#define glGetUniformIndices __glGetUniformIndices
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
#define glGetActiveUniformsiv __glGetActiveUniformsiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
#define glGetActiveUniformName __glGetActiveUniformName
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar * uniformBlockName);
#define glGetUniformBlockIndex __glGetUniformBlockIndex
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
#define glGetActiveUniformBlockiv __glGetActiveUniformBlockiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
#define glGetActiveUniformBlockName __glGetActiveUniformBlockName
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#define glUniformBlockBinding __glUniformBlockBinding
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
#define glDrawElementsBaseVertex __glDrawElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
#define glDrawRangeElementsBaseVertex __glDrawRangeElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
#define glDrawElementsInstancedBaseVertex __glDrawElementsInstancedBaseVertex
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex);
#define glMultiDrawElementsBaseVertex __glMultiDrawElementsBaseVertex
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
#define glProvokingVertex __glProvokingVertex
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
#define glFenceSync __glFenceSync
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
#define glIsSync __glIsSync
typedef void (APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
#define glDeleteSync __glDeleteSync
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glClientWaitSync __glClientWaitSync
typedef void (APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glWaitSync __glWaitSync
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64 * data);
#define glGetInteger64v __glGetInteger64v
typedef void (APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values);
#define glGetSynciv __glGetSynciv
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
#define glGetInteger64i_v __glGetInteger64i_v
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64 * params);
#define glGetBufferParameteri64v __glGetBufferParameteri64v
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
#define glFramebufferTexture __glFramebufferTexture
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexImage2DMultisample __glTexImage2DMultisample
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexImage3DMultisample __glTexImage3DMultisample
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat * val);
#define glGetMultisamplefv __glGetMultisamplefv
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
#define glSampleMaski __glSampleMaski
#endif

#if CWCGL_VERSION >= GL_VERSION_3_3
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#define GL_SRC1_COLOR 0x88F9
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name);
#define glBindFragDataLocationIndexed __glBindFragDataLocationIndexed
typedef GLint (APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar * name);
#define glGetFragDataIndex __glGetFragDataIndex
#define GL_ANY_SAMPLES_PASSED 0x8C2F
#define GL_SAMPLER_BINDING 0x8919
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint * samplers);
#define glGenSamplers __glGenSamplers
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint * samplers);
#define glDeleteSamplers __glDeleteSamplers
typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
#define glIsSampler __glIsSampler
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
#define glBindSampler __glBindSampler
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
#define glSamplerParameteri __glSamplerParameteri
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameteriv __glSamplerParameteriv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
#define glSamplerParameterf __glSamplerParameterf
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat * param);
#define glSamplerParameterfv __glSamplerParameterfv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameterIiv __glSamplerParameterIiv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint * param);
#define glSamplerParameterIuiv __glSamplerParameterIuiv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameteriv __glGetSamplerParameteriv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameterIiv __glGetSamplerParameterIiv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat * params);
#define glGetSamplerParameterfv __glGetSamplerParameterfv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint * params);
#define glGetSamplerParameterIuiv __glGetSamplerParameterIuiv
#define GL_RGB10_A2UI 0x906F
#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46
#define GL_TIME_ELAPSED 0x88BF
#define GL_TIMESTAMP 0x8E28
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
#define glQueryCounter __glQueryCounter
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64 * params);
#define glGetQueryObjecti64v __glGetQueryObjecti64v
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64 * params);
#define glGetQueryObjectui64v __glGetQueryObjectui64v
#define GL_INT_2_10_10_10_REV 0x8D9F
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
#define glVertexAttribDivisor __glVertexAttribDivisor
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP1ui __glVertexAttribP1ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP1uiv __glVertexAttribP1uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP2ui __glVertexAttribP2ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP2uiv __glVertexAttribP2uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP3ui __glVertexAttribP3ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP3uiv __glVertexAttribP3uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP4ui __glVertexAttribP4ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP4uiv __glVertexAttribP4uiv
typedef void (APIENTRYP PFNGLVERTEXP2UIPROC)(GLenum type, GLuint value);
#define glVertexP2ui __glVertexP2ui
typedef void (APIENTRYP PFNGLVERTEXP2UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP2uiv __glVertexP2uiv
typedef void (APIENTRYP PFNGLVERTEXP3UIPROC)(GLenum type, GLuint value);
#define glVertexP3ui __glVertexP3ui
typedef void (APIENTRYP PFNGLVERTEXP3UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP3uiv __glVertexP3uiv
typedef void (APIENTRYP PFNGLVERTEXP4UIPROC)(GLenum type, GLuint value);
#define glVertexP4ui __glVertexP4ui
typedef void (APIENTRYP PFNGLVERTEXP4UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP4uiv __glVertexP4uiv
typedef void (APIENTRYP PFNGLTEXCOORDP1UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP1ui __glTexCoordP1ui
typedef void (APIENTRYP PFNGLTEXCOORDP1UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP1uiv __glTexCoordP1uiv
typedef void (APIENTRYP PFNGLTEXCOORDP2UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP2ui __glTexCoordP2ui
typedef void (APIENTRYP PFNGLTEXCOORDP2UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP2uiv __glTexCoordP2uiv
typedef void (APIENTRYP PFNGLTEXCOORDP3UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP3ui __glTexCoordP3ui
typedef void (APIENTRYP PFNGLTEXCOORDP3UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP3uiv __glTexCoordP3uiv
typedef void (APIENTRYP PFNGLTEXCOORDP4UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP4ui __glTexCoordP4ui
typedef void (APIENTRYP PFNGLTEXCOORDP4UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP4uiv __glTexCoordP4uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP1ui __glMultiTexCoordP1ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP1uiv __glMultiTexCoordP1uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP2ui __glMultiTexCoordP2ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP2uiv __glMultiTexCoordP2uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP3ui __glMultiTexCoordP3ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP3uiv __glMultiTexCoordP3uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP4ui __glMultiTexCoordP4ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP4uiv __glMultiTexCoordP4uiv
typedef void (APIENTRYP PFNGLNORMALP3UIPROC)(GLenum type, GLuint coords);
#define glNormalP3ui __glNormalP3ui
typedef void (APIENTRYP PFNGLNORMALP3UIVPROC)(GLenum type, const GLuint * coords);
#define glNormalP3uiv __glNormalP3uiv
typedef void (APIENTRYP PFNGLCOLORP3UIPROC)(GLenum type, GLuint color);
#define glColorP3ui __glColorP3ui
typedef void (APIENTRYP PFNGLCOLORP3UIVPROC)(GLenum type, const GLuint * color);
#define glColorP3uiv __glColorP3uiv
typedef void (APIENTRYP PFNGLCOLORP4UIPROC)(GLenum type, GLuint color);
#define glColorP4ui __glColorP4ui
typedef void (APIENTRYP PFNGLCOLORP4UIVPROC)(GLenum type, const GLuint * color);
#define glColorP4uiv __glColorP4uiv
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIPROC)(GLenum type, GLuint color);
#define glSecondaryColorP3ui __glSecondaryColorP3ui
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC)(GLenum type, const GLuint * color);
#define glSecondaryColorP3uiv __glSecondaryColorP3uiv
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
#define glMinSampleShading __glMinSampleShading
typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC)(GLuint buf, GLenum mode);
#define glBlendEquationi __glBlendEquationi
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparatei __glBlendEquationSeparatei
typedef void (APIENTRYP PFNGLBLENDFUNCIPROC)(GLuint buf, GLenum src, GLenum dst);
#define glBlendFunci __glBlendFunci
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#define glBlendFuncSeparatei __glBlendFuncSeparatei
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const void * indirect);
#define glDrawArraysIndirect __glDrawArraysIndirect
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void * indirect);
#define glDrawElementsIndirect __glDrawElementsIndirect
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
#define glUniform1d __glUniform1d
typedef void (APIENTRYP PFNGLUNIFORM2DPROC)(GLint location, GLdouble x, GLdouble y);
#define glUniform2d __glUniform2d
typedef void (APIENTRYP PFNGLUNIFORM3DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z);
#define glUniform3d __glUniform3d
typedef void (APIENTRYP PFNGLUNIFORM4DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glUniform4d __glUniform4d
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform1dv __glUniform1dv
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform2dv __glUniform2dv
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform3dv __glUniform3dv
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform4dv __glUniform4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2dv __glUniformMatrix2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3dv __glUniformMatrix3dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4dv __glUniformMatrix4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x3dv __glUniformMatrix2x3dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x4dv __glUniformMatrix2x4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x2dv __glUniformMatrix3x2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x4dv __glUniformMatrix3x4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x2dv __glUniformMatrix4x2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x3dv __glUniformMatrix4x3dv
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint program, GLint location, GLdouble * params);
#define glGetUniformdv __glGetUniformdv
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
#define glGetSubroutineUniformLocation __glGetSubroutineUniformLocation
typedef GLuint (APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint program, GLenum shadertype, const GLchar * name);
#define glGetSubroutineIndex __glGetSubroutineIndex
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values);
#define glGetActiveSubroutineUniformiv __glGetActiveSubroutineUniformiv
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineUniformName __glGetActiveSubroutineUniformName
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineName __glGetActiveSubroutineName
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum shadertype, GLsizei count, const GLuint * indices);
#define glUniformSubroutinesuiv __glUniformSubroutinesuiv
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum shadertype, GLint location, GLuint * params);
#define glGetUniformSubroutineuiv __glGetUniformSubroutineuiv
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint program, GLenum shadertype, GLenum pname, GLint * values);
#define glGetProgramStageiv __glGetProgramStageiv
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
#define glPatchParameteri __glPatchParameteri
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum pname, const GLfloat * values);
#define glPatchParameterfv __glPatchParameterfv
#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
#define glBindTransformFeedback __glBindTransformFeedback
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint * ids);
#define glDeleteTransformFeedbacks __glDeleteTransformFeedbacks
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint * ids);
#define glGenTransformFeedbacks __glGenTransformFeedbacks
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
#define glIsTransformFeedback __glIsTransformFeedback
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);
#define glPauseTransformFeedback __glPauseTransformFeedback
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);
#define glResumeTransformFeedback __glResumeTransformFeedback
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum mode, GLuint id);
#define glDrawTransformFeedback __glDrawTransformFeedback
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum mode, GLuint id, GLuint stream);
#define glDrawTransformFeedbackStream __glDrawTransformFeedbackStream
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum target, GLuint index, GLuint id);
#define glBeginQueryIndexed __glBeginQueryIndexed
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum target, GLuint index);
#define glEndQueryIndexed __glEndQueryIndexed
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum target, GLuint index, GLenum pname, GLint * params);
#define glGetQueryIndexediv __glGetQueryIndexediv
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
#define glReleaseShaderCompiler __glReleaseShaderCompiler
typedef void (APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint * shaders, GLenum binaryformat, const void * binary, GLsizei length);
#define glShaderBinary __glShaderBinary
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
#define glGetShaderPrecisionFormat __glGetShaderPrecisionFormat
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
#define glDepthRangef __glDepthRangef
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
#define glClearDepthf __glClearDepthf
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
#define glGetProgramBinary __glGetProgramBinary
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
#define glProgramBinary __glProgramBinary
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
#define glProgramParameteri __glProgramParameteri
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
#define glUseProgramStages __glUseProgramStages
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint pipeline, GLuint program);
#define glActiveShaderProgram __glActiveShaderProgram
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum type, GLsizei count, const GLchar *const* strings);
#define glCreateShaderProgramv __glCreateShaderProgramv
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glBindProgramPipeline __glBindProgramPipeline
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei n, const GLuint * pipelines);
#define glDeleteProgramPipelines __glDeleteProgramPipelines
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei n, GLuint * pipelines);
#define glGenProgramPipelines __glGenProgramPipelines
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glIsProgramPipeline __glIsProgramPipeline
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint pipeline, GLenum pname, GLint * params);
#define glGetProgramPipelineiv __glGetProgramPipelineiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint program, GLint location, GLint v0);
#define glProgramUniform1i __glProgramUniform1i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform1iv __glProgramUniform1iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint program, GLint location, GLfloat v0);
#define glProgramUniform1f __glProgramUniform1f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform1fv __glProgramUniform1fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint program, GLint location, GLdouble v0);
#define glProgramUniform1d __glProgramUniform1d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform1dv __glProgramUniform1dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint program, GLint location, GLuint v0);
#define glProgramUniform1ui __glProgramUniform1ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform1uiv __glProgramUniform1uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint program, GLint location, GLint v0, GLint v1);
#define glProgramUniform2i __glProgramUniform2i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform2iv __glProgramUniform2iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
#define glProgramUniform2f __glProgramUniform2f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform2fv __glProgramUniform2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
#define glProgramUniform2d __glProgramUniform2d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform2dv __glProgramUniform2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
#define glProgramUniform2ui __glProgramUniform2ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform2uiv __glProgramUniform2uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
#define glProgramUniform3i __glProgramUniform3i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform3iv __glProgramUniform3iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glProgramUniform3f __glProgramUniform3f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform3fv __glProgramUniform3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
#define glProgramUniform3d __glProgramUniform3d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform3dv __glProgramUniform3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glProgramUniform3ui __glProgramUniform3ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform3uiv __glProgramUniform3uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glProgramUniform4i __glProgramUniform4i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform4iv __glProgramUniform4iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glProgramUniform4f __glProgramUniform4f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform4fv __glProgramUniform4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
#define glProgramUniform4d __glProgramUniform4d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform4dv __glProgramUniform4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glProgramUniform4ui __glProgramUniform4ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform4uiv __glProgramUniform4uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2fv __glProgramUniformMatrix2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3fv __glProgramUniformMatrix3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4fv __glProgramUniformMatrix4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2dv __glProgramUniformMatrix2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3dv __glProgramUniformMatrix3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4dv __glProgramUniformMatrix4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x3fv __glProgramUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x2fv __glProgramUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x4fv __glProgramUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x2fv __glProgramUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x4fv __glProgramUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x3fv __glProgramUniformMatrix4x3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x3dv __glProgramUniformMatrix2x3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x2dv __glProgramUniformMatrix3x2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x4dv __glProgramUniformMatrix2x4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x2dv __glProgramUniformMatrix4x2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x4dv __glProgramUniformMatrix3x4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x3dv __glProgramUniformMatrix4x3dv
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glValidateProgramPipeline __glValidateProgramPipeline
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetProgramPipelineInfoLog __glGetProgramPipelineInfoLog
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint index, GLdouble x);
#define glVertexAttribL1d __glVertexAttribL1d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttribL2d __glVertexAttribL2d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttribL3d __glVertexAttribL3d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttribL4d __glVertexAttribL4d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL1dv __glVertexAttribL1dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL2dv __glVertexAttribL2dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL3dv __glVertexAttribL3dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL4dv __glVertexAttribL4dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribLPointer __glVertexAttribLPointer
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribLdv __glGetVertexAttribLdv
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint first, GLsizei count, const GLfloat * v);
#define glViewportArrayv __glViewportArrayv
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
#define glViewportIndexedf __glViewportIndexedf
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint index, const GLfloat * v);
#define glViewportIndexedfv __glViewportIndexedfv
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint first, GLsizei count, const GLint * v);
#define glScissorArrayv __glScissorArrayv
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
#define glScissorIndexed __glScissorIndexed
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint index, const GLint * v);
#define glScissorIndexedv __glScissorIndexedv
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint first, GLsizei count, const GLdouble * v);
#define glDepthRangeArrayv __glDepthRangeArrayv
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint index, GLdouble n, GLdouble f);
#define glDepthRangeIndexed __glDepthRangeIndexed
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC)(GLenum target, GLuint index, GLfloat * data);
#define glGetFloati_v __glGetFloati_v
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum target, GLuint index, GLdouble * data);
#define glGetDoublei_v __glGetDoublei_v
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
#define glDrawArraysInstancedBaseInstance __glDrawArraysInstancedBaseInstance
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
#define glDrawElementsInstancedBaseInstance __glDrawElementsInstancedBaseInstance
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#define glDrawElementsInstancedBaseVertexBaseInstance __glDrawElementsInstancedBaseVertexBaseInstance
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint * params);
#define glGetInternalformativ __glGetInternalformativ
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params);
#define glGetActiveAtomicCounterBufferiv __glGetActiveAtomicCounterBufferiv
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
#define glBindImageTexture __glBindImageTexture
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC)(GLbitfield barriers);
#define glMemoryBarrier __glMemoryBarrier
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTexStorage1D __glTexStorage1D
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTexStorage2D __glTexStorage2D
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTexStorage3D __glTexStorage3D
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum mode, GLuint id, GLsizei instancecount);
#define glDrawTransformFeedbackInstanced __glDrawTransformFeedbackInstanced
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#define glDrawTransformFeedbackStreamInstanced __glDrawTransformFeedbackStreamInstanced
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
#define glClearBufferData __glClearBufferData
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearBufferSubData __glClearBufferSubData
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
#define glDispatchCompute __glDispatchCompute
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
#define glDispatchComputeIndirect __glDispatchComputeIndirect
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#define glCopyImageSubData __glCopyImageSubData
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
#define glFramebufferParameteri __glFramebufferParameteri
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetFramebufferParameteriv __glGetFramebufferParameteriv
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 * params);
#define glGetInternalformati64v __glGetInternalformati64v
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
#define glInvalidateTexSubImage __glInvalidateTexSubImage
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC)(GLuint texture, GLint level);
#define glInvalidateTexImage __glInvalidateTexImage
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glInvalidateBufferSubData __glInvalidateBufferSubData
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC)(GLuint buffer);
#define glInvalidateBufferData __glInvalidateBufferData
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateFramebuffer __glInvalidateFramebuffer
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateSubFramebuffer __glInvalidateSubFramebuffer
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawArraysIndirect __glMultiDrawArraysIndirect
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawElementsIndirect __glMultiDrawElementsIndirect
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program, GLenum programInterface, GLenum pname, GLint * params);
#define glGetProgramInterfaceiv __glGetProgramInterfaceiv
typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceIndex __glGetProgramResourceIndex
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
#define glGetProgramResourceName __glGetProgramResourceName
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params);
#define glGetProgramResourceiv __glGetProgramResourceiv
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocation __glGetProgramResourceLocation
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocationIndex __glGetProgramResourceLocationIndex
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
#define glShaderStorageBlockBinding __glShaderStorageBlockBinding
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTexBufferRange __glTexBufferRange
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexStorage2DMultisample __glTexStorage2DMultisample
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexStorage3DMultisample __glTexStorage3DMultisample
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#define glTextureView __glTextureView
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glBindVertexBuffer __glBindVertexBuffer
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexAttribFormat __glVertexAttribFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribIFormat __glVertexAttribIFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribLFormat __glVertexAttribLFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
#define glVertexAttribBinding __glVertexAttribBinding
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
#define glVertexBindingDivisor __glVertexBindingDivisor
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
#define glDebugMessageControl __glDebugMessageControl
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
#define glDebugMessageInsert __glDebugMessageInsert
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void * userParam);
#define glDebugMessageCallback __glDebugMessageCallback
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
#define glGetDebugMessageLog __glGetDebugMessageLog
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum source, GLuint id, GLsizei length, const GLchar * message);
#define glPushDebugGroup __glPushDebugGroup
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC)(void);
#define glPopDebugGroup __glPopDebugGroup
typedef void (APIENTRYP PFNGLOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
#define glObjectLabel __glObjectLabel
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectLabel __glGetObjectLabel
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC)(const void * ptr, GLsizei length, const GLchar * label);
#define glObjectPtrLabel __glObjectPtrLabel
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC)(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectPtrLabel __glGetObjectPtrLabel
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
#define glBufferStorage __glBufferStorage
#define GL_CLEAR_TEXTURE 0x9365
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
#define glClearTexImage __glClearTexImage
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
#define glClearTexSubImage __glClearTexSubImage
#define GL_LOCATION_COMPONENT 0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers);
#define glBindBuffersBase __glBindBuffersBase
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes);
#define glBindBuffersRange __glBindBuffersRange
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindTextures __glBindTextures
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint * samplers);
#define glBindSamplers __glBindSamplers
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindImageTextures __glBindImageTextures
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glBindVertexBuffers __glBindVertexBuffers
#define GL_QUERY_BUFFER 0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000
#define GL_QUERY_BUFFER_BINDING 0x9193
#define GL_QUERY_RESULT_NO_WAIT 0x9194
#define GL_MIRROR_CLAMP_TO_EDGE 0x8743
#endif

#if CWCGL_VERSION >= GL_VERSION_4_5
#define GL_CONTEXT_LOST 0x0507
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC)(GLenum origin, GLenum depth);
#define glClipControl __glClipControl
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
#define glCreateTransformFeedbacks __glCreateTransformFeedbacks
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint xfb, GLuint index, GLuint buffer);
#define glTransformFeedbackBufferBase __glTransformFeedbackBufferBase
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTransformFeedbackBufferRange __glTransformFeedbackBufferRange
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint xfb, GLenum pname, GLint * param);
#define glGetTransformFeedbackiv __glGetTransformFeedbackiv
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint * param);
#define glGetTransformFeedbacki_v __glGetTransformFeedbacki_v
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint64 * param);
#define glGetTransformFeedbacki64_v __glGetTransformFeedbacki64_v
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei n, GLuint * buffers);
#define glCreateBuffers __glCreateBuffers
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
#define glNamedBufferStorage __glNamedBufferStorage
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
#define glNamedBufferData __glNamedBufferData
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
#define glNamedBufferSubData __glNamedBufferSubData
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyNamedBufferSubData __glCopyNamedBufferSubData
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferData __glClearNamedBufferData
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferSubData __glClearNamedBufferSubData
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint buffer, GLenum access);
#define glMapNamedBuffer __glMapNamedBuffer
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapNamedBufferRange __glMapNamedBufferRange
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint buffer);
#define glUnmapNamedBuffer __glUnmapNamedBuffer
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glFlushMappedNamedBufferRange __glFlushMappedNamedBufferRange
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint buffer, GLenum pname, GLint * params);
#define glGetNamedBufferParameteriv __glGetNamedBufferParameteriv
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint buffer, GLenum pname, GLint64 * params);
#define glGetNamedBufferParameteri64v __glGetNamedBufferParameteri64v
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint buffer, GLenum pname, void ** params);
#define glGetNamedBufferPointerv __glGetNamedBufferPointerv
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
#define glGetNamedBufferSubData __glGetNamedBufferSubData
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei n, GLuint * framebuffers);
#define glCreateFramebuffers __glCreateFramebuffers
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glNamedFramebufferRenderbuffer __glNamedFramebufferRenderbuffer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint framebuffer, GLenum pname, GLint param);
#define glNamedFramebufferParameteri __glNamedFramebufferParameteri
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
#define glNamedFramebufferTexture __glNamedFramebufferTexture
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glNamedFramebufferTextureLayer __glNamedFramebufferTextureLayer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint framebuffer, GLenum buf);
#define glNamedFramebufferDrawBuffer __glNamedFramebufferDrawBuffer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint framebuffer, GLsizei n, const GLenum * bufs);
#define glNamedFramebufferDrawBuffers __glNamedFramebufferDrawBuffers
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint framebuffer, GLenum src);
#define glNamedFramebufferReadBuffer __glNamedFramebufferReadBuffer
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateNamedFramebufferData __glInvalidateNamedFramebufferData
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateNamedFramebufferSubData __glInvalidateNamedFramebufferSubData
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value);
#define glClearNamedFramebufferiv __glClearNamedFramebufferiv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value);
#define glClearNamedFramebufferuiv __glClearNamedFramebufferuiv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat * value);
#define glClearNamedFramebufferfv __glClearNamedFramebufferfv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
#define glClearNamedFramebufferfi __glClearNamedFramebufferfi
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitNamedFramebuffer __glBlitNamedFramebuffer
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint framebuffer, GLenum target);
#define glCheckNamedFramebufferStatus __glCheckNamedFramebufferStatus
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint framebuffer, GLenum pname, GLint * param);
#define glGetNamedFramebufferParameteriv __glGetNamedFramebufferParameteriv
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
#define glGetNamedFramebufferAttachmentParameteriv __glGetNamedFramebufferAttachmentParameteriv
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei n, GLuint * renderbuffers);
#define glCreateRenderbuffers __glCreateRenderbuffers
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorage __glNamedRenderbufferStorage
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisample __glNamedRenderbufferStorageMultisample
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint renderbuffer, GLenum pname, GLint * params);
#define glGetNamedRenderbufferParameteriv __glGetNamedRenderbufferParameteriv
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC)(GLenum target, GLsizei n, GLuint * textures);
#define glCreateTextures __glCreateTextures
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint texture, GLenum internalformat, GLuint buffer);
#define glTextureBuffer __glTextureBuffer
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTextureBufferRange __glTextureBufferRange
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTextureStorage1D __glTextureStorage1D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTextureStorage2D __glTextureStorage2D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTextureStorage3D __glTextureStorage3D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTextureStorage2DMultisample __glTextureStorage2DMultisample
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTextureStorage3DMultisample __glTextureStorage3DMultisample
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage1D __glTextureSubImage1D
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage2D __glTextureSubImage2D
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage3D __glTextureSubImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage1D __glCompressedTextureSubImage1D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage2D __glCompressedTextureSubImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage3D __glCompressedTextureSubImage3D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTextureSubImage1D __glCopyTextureSubImage1D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage2D __glCopyTextureSubImage2D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage3D __glCopyTextureSubImage3D
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint texture, GLenum pname, GLfloat param);
#define glTextureParameterf __glTextureParameterf
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, const GLfloat * param);
#define glTextureParameterfv __glTextureParameterfv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint texture, GLenum pname, GLint param);
#define glTextureParameteri __glTextureParameteri
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, const GLint * params);
#define glTextureParameterIiv __glTextureParameterIiv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, const GLuint * params);
#define glTextureParameterIuiv __glTextureParameterIuiv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, const GLint * param);
#define glTextureParameteriv __glTextureParameteriv
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint texture);
#define glGenerateTextureMipmap __glGenerateTextureMipmap
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint unit, GLuint texture);
#define glBindTextureUnit __glBindTextureUnit
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureImage __glGetTextureImage
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureImage __glGetCompressedTextureImage
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint texture, GLint level, GLenum pname, GLfloat * params);
#define glGetTextureLevelParameterfv __glGetTextureLevelParameterfv
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint texture, GLint level, GLenum pname, GLint * params);
#define glGetTextureLevelParameteriv __glGetTextureLevelParameteriv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, GLfloat * params);
#define glGetTextureParameterfv __glGetTextureParameterfv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameterIiv __glGetTextureParameterIiv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, GLuint * params);
#define glGetTextureParameterIuiv __glGetTextureParameterIuiv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameteriv __glGetTextureParameteriv
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei n, GLuint * arrays);
#define glCreateVertexArrays __glCreateVertexArrays
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
#define glDisableVertexArrayAttrib __glDisableVertexArrayAttrib
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
#define glEnableVertexArrayAttrib __glEnableVertexArrayAttrib
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint vaobj, GLuint buffer);
#define glVertexArrayElementBuffer __glVertexArrayElementBuffer
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glVertexArrayVertexBuffer __glVertexArrayVertexBuffer
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glVertexArrayVertexBuffers __glVertexArrayVertexBuffers
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
#define glVertexArrayAttribBinding __glVertexArrayAttribBinding
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexArrayAttribFormat __glVertexArrayAttribFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribIFormat __glVertexArrayAttribIFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribLFormat __glVertexArrayAttribLFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#define glVertexArrayBindingDivisor __glVertexArrayBindingDivisor
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint vaobj, GLenum pname, GLint * param);
#define glGetVertexArrayiv __glGetVertexArrayiv
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint * param);
#define glGetVertexArrayIndexediv __glGetVertexArrayIndexediv
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param);
#define glGetVertexArrayIndexed64iv __glGetVertexArrayIndexed64iv
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei n, GLuint * samplers);
#define glCreateSamplers __glCreateSamplers
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei n, GLuint * pipelines);
#define glCreateProgramPipelines __glCreateProgramPipelines
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC)(GLenum target, GLsizei n, GLuint * ids);
#define glCreateQueries __glCreateQueries
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjecti64v __glGetQueryBufferObjecti64v
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectiv __glGetQueryBufferObjectiv
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectui64v __glGetQueryBufferObjectui64v
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectuiv __glGetQueryBufferObjectuiv
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
#define glMemoryBarrierByRegion __glMemoryBarrierByRegion
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureSubImage __glGetTextureSubImage
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureSubImage __glGetCompressedTextureSubImage
#define GL_GUILTY_CONTEXT_RESET 0x8253
#define GL_INNOCENT_CONTEXT_RESET 0x8254
#define GL_UNKNOWN_CONTEXT_RESET 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY 0x8256
#define GL_LOSE_CONTEXT_ON_RESET 0x8252
#define GL_NO_RESET_NOTIFICATION 0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)(void);
#define glGetGraphicsResetStatus __glGetGraphicsResetStatus
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint lod, GLsizei bufSize, void * pixels);
#define glGetnCompressedTexImage __glGetnCompressedTexImage
typedef void (APIENTRYP PFNGLGETNTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetnTexImage __glGetnTexImage
typedef void (APIENTRYP PFNGLGETNUNIFORMDVPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble * params);
#define glGetnUniformdv __glGetnUniformdv
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
#define glGetnUniformfv __glGetnUniformfv
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint * params);
#define glGetnUniformiv __glGetnUniformiv
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint * params);
#define glGetnUniformuiv __glGetnUniformuiv
typedef void (APIENTRYP PFNGLREADNPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
#define glReadnPixels __glReadnPixels
typedef void (APIENTRYP PFNGLGETNMAPDVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v);
#define glGetnMapdv __glGetnMapdv
typedef void (APIENTRYP PFNGLGETNMAPFVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v);
#define glGetnMapfv __glGetnMapfv
typedef void (APIENTRYP PFNGLGETNMAPIVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint * v);
#define glGetnMapiv __glGetnMapiv
typedef void (APIENTRYP PFNGLGETNPIXELMAPFVPROC)(GLenum map, GLsizei bufSize, GLfloat * values);
#define glGetnPixelMapfv __glGetnPixelMapfv
typedef void (APIENTRYP PFNGLGETNPIXELMAPUIVPROC)(GLenum map, GLsizei bufSize, GLuint * values);
#define glGetnPixelMapuiv __glGetnPixelMapuiv
typedef void (APIENTRYP PFNGLGETNPIXELMAPUSVPROC)(GLenum map, GLsizei bufSize, GLushort * values);
#define glGetnPixelMapusv __glGetnPixelMapusv
typedef void (APIENTRYP PFNGLGETNPOLYGONSTIPPLEPROC)(GLsizei bufSize, GLubyte * pattern);
#define glGetnPolygonStipple __glGetnPolygonStipple
typedef void (APIENTRYP PFNGLGETNCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table);
#define glGetnColorTable __glGetnColorTable
typedef void (APIENTRYP PFNGLGETNCONVOLUTIONFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image);
#define glGetnConvolutionFilter __glGetnConvolutionFilter
typedef void (APIENTRYP PFNGLGETNSEPARABLEFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span);
#define glGetnSeparableFilter __glGetnSeparableFilter
typedef void (APIENTRYP PFNGLGETNHISTOGRAMPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
#define glGetnHistogram __glGetnHistogram
typedef void (APIENTRYP PFNGLGETNMINMAXPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
#define glGetnMinmax __glGetnMinmax
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC)(void);
#define glTextureBarrier __glTextureBarrier
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

#define X(T, N) extern T __##N;
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

EXPORT void cwcglAccum(GLcontext *context, GLenum op, GLfloat value);
EXPORT void cwcglAccumxOES(GLcontext *context, GLenum op, GLfixed value);
EXPORT void cwcglActiveProgramEXT(GLcontext *context, GLuint program);
EXPORT void cwcglActiveShaderProgram(GLcontext *context, GLuint pipeline, GLuint program);
EXPORT void cwcglActiveShaderProgramEXT(GLcontext *context, GLuint pipeline, GLuint program);
EXPORT void cwcglActiveStencilFaceEXT(GLcontext *context, GLenum face);
EXPORT void cwcglActiveTexture(GLcontext *context, GLenum texture);
EXPORT void cwcglActiveTextureARB(GLcontext *context, GLenum texture);
EXPORT void cwcglActiveVaryingNV(GLcontext *context, GLuint program, const GLchar * name);
EXPORT void cwcglAlphaFragmentOp1ATI(GLcontext *context, GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
EXPORT void cwcglAlphaFragmentOp2ATI(GLcontext *context, GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
EXPORT void cwcglAlphaFragmentOp3ATI(GLcontext *context, GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
EXPORT void cwcglAlphaFunc(GLcontext *context, GLenum func, GLfloat ref);
EXPORT void cwcglAlphaFuncQCOM(GLcontext *context, GLenum func, GLclampf ref);
EXPORT void cwcglAlphaFuncx(GLcontext *context, GLenum func, GLfixed ref);
EXPORT void cwcglAlphaFuncxOES(GLcontext *context, GLenum func, GLfixed ref);
EXPORT void cwcglApplyFramebufferAttachmentCMAAINTEL(GLcontext *context);
EXPORT void cwcglApplyTextureEXT(GLcontext *context, GLenum mode);
EXPORT void cwcglAreProgramsResidentNV(GLcontext *context, GLsizei n, const GLuint * programs, GLboolean * residences, GLboolean* return_value);
EXPORT void cwcglAreTexturesResident(GLcontext *context, GLsizei n, const GLuint * textures, GLboolean * residences, GLboolean* return_value);
EXPORT void cwcglAreTexturesResidentEXT(GLcontext *context, GLsizei n, const GLuint * textures, GLboolean * residences, GLboolean* return_value);
EXPORT void cwcglArrayElement(GLcontext *context, GLint i);
EXPORT void cwcglArrayElementEXT(GLcontext *context, GLint i);
EXPORT void cwcglArrayObjectATI(GLcontext *context, GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
EXPORT void cwcglAsyncMarkerSGIX(GLcontext *context, GLuint marker);
EXPORT void cwcglAttachObjectARB(GLcontext *context, GLhandleARB containerObj, GLhandleARB obj);
EXPORT void cwcglAttachShader(GLcontext *context, GLuint program, GLuint shader);
EXPORT void cwcglBegin(GLcontext *context, GLenum mode);
EXPORT void cwcglBeginConditionalRender(GLcontext *context, GLuint id, GLenum mode);
EXPORT void cwcglBeginConditionalRenderNV(GLcontext *context, GLuint id, GLenum mode);
EXPORT void cwcglBeginConditionalRenderNVX(GLcontext *context, GLuint id);
EXPORT void cwcglBeginFragmentShaderATI(GLcontext *context);
EXPORT void cwcglBeginOcclusionQueryNV(GLcontext *context, GLuint id);
EXPORT void cwcglBeginPerfMonitorAMD(GLcontext *context, GLuint monitor);
EXPORT void cwcglBeginPerfQueryINTEL(GLcontext *context, GLuint queryHandle);
EXPORT void cwcglBeginQuery(GLcontext *context, GLenum target, GLuint id);
EXPORT void cwcglBeginQueryARB(GLcontext *context, GLenum target, GLuint id);
EXPORT void cwcglBeginQueryEXT(GLcontext *context, GLenum target, GLuint id);
EXPORT void cwcglBeginQueryIndexed(GLcontext *context, GLenum target, GLuint index, GLuint id);
EXPORT void cwcglBeginTransformFeedback(GLcontext *context, GLenum primitiveMode);
EXPORT void cwcglBeginTransformFeedbackEXT(GLcontext *context, GLenum primitiveMode);
EXPORT void cwcglBeginTransformFeedbackNV(GLcontext *context, GLenum primitiveMode);
EXPORT void cwcglBeginVertexShaderEXT(GLcontext *context);
EXPORT void cwcglBeginVideoCaptureNV(GLcontext *context, GLuint video_capture_slot);
EXPORT void cwcglBindAttribLocation(GLcontext *context, GLuint program, GLuint index, const GLchar * name);
EXPORT void cwcglBindAttribLocationARB(GLcontext *context, GLhandleARB programObj, GLuint index, const GLcharARB * name);
EXPORT void cwcglBindBuffer(GLcontext *context, GLenum target, GLuint buffer);
EXPORT void cwcglBindBufferARB(GLcontext *context, GLenum target, GLuint buffer);
EXPORT void cwcglBindBufferBase(GLcontext *context, GLenum target, GLuint index, GLuint buffer);
EXPORT void cwcglBindBufferBaseEXT(GLcontext *context, GLenum target, GLuint index, GLuint buffer);
EXPORT void cwcglBindBufferBaseNV(GLcontext *context, GLenum target, GLuint index, GLuint buffer);
EXPORT void cwcglBindBufferOffsetEXT(GLcontext *context, GLenum target, GLuint index, GLuint buffer, GLintptr offset);
EXPORT void cwcglBindBufferOffsetNV(GLcontext *context, GLenum target, GLuint index, GLuint buffer, GLintptr offset);
EXPORT void cwcglBindBufferRange(GLcontext *context, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
EXPORT void cwcglBindBufferRangeEXT(GLcontext *context, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
EXPORT void cwcglBindBufferRangeNV(GLcontext *context, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
EXPORT void cwcglBindBuffersBase(GLcontext *context, GLenum target, GLuint first, GLsizei count, const GLuint * buffers);
EXPORT void cwcglBindBuffersRange(GLcontext *context, GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes);
EXPORT void cwcglBindFragDataLocation(GLcontext *context, GLuint program, GLuint color, const GLchar * name);
EXPORT void cwcglBindFragDataLocationEXT(GLcontext *context, GLuint program, GLuint color, const GLchar * name);
EXPORT void cwcglBindFragDataLocationIndexed(GLcontext *context, GLuint program, GLuint colorNumber, GLuint index, const GLchar * name);
EXPORT void cwcglBindFragDataLocationIndexedEXT(GLcontext *context, GLuint program, GLuint colorNumber, GLuint index, const GLchar * name);
EXPORT void cwcglBindFragmentShaderATI(GLcontext *context, GLuint id);
EXPORT void cwcglBindFramebuffer(GLcontext *context, GLenum target, GLuint framebuffer);
EXPORT void cwcglBindFramebufferEXT(GLcontext *context, GLenum target, GLuint framebuffer);
EXPORT void cwcglBindFramebufferOES(GLcontext *context, GLenum target, GLuint framebuffer);
EXPORT void cwcglBindImageTexture(GLcontext *context, GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
EXPORT void cwcglBindImageTextureEXT(GLcontext *context, GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
EXPORT void cwcglBindImageTextures(GLcontext *context, GLuint first, GLsizei count, const GLuint * textures);
EXPORT void cwcglBindLightParameterEXT(GLcontext *context, GLenum light, GLenum value, GLuint* return_value);
EXPORT void cwcglBindMaterialParameterEXT(GLcontext *context, GLenum face, GLenum value, GLuint* return_value);
EXPORT void cwcglBindMultiTextureEXT(GLcontext *context, GLenum texunit, GLenum target, GLuint texture);
EXPORT void cwcglBindParameterEXT(GLcontext *context, GLenum value, GLuint* return_value);
EXPORT void cwcglBindProgramARB(GLcontext *context, GLenum target, GLuint program);
EXPORT void cwcglBindProgramNV(GLcontext *context, GLenum target, GLuint id);
EXPORT void cwcglBindProgramPipeline(GLcontext *context, GLuint pipeline);
EXPORT void cwcglBindProgramPipelineEXT(GLcontext *context, GLuint pipeline);
EXPORT void cwcglBindRenderbuffer(GLcontext *context, GLenum target, GLuint renderbuffer);
EXPORT void cwcglBindRenderbufferEXT(GLcontext *context, GLenum target, GLuint renderbuffer);
EXPORT void cwcglBindRenderbufferOES(GLcontext *context, GLenum target, GLuint renderbuffer);
EXPORT void cwcglBindSampler(GLcontext *context, GLuint unit, GLuint sampler);
EXPORT void cwcglBindSamplers(GLcontext *context, GLuint first, GLsizei count, const GLuint * samplers);
EXPORT void cwcglBindTexGenParameterEXT(GLcontext *context, GLenum unit, GLenum coord, GLenum value, GLuint* return_value);
EXPORT void cwcglBindTexture(GLcontext *context, GLenum target, GLuint texture);
EXPORT void cwcglBindTextureEXT(GLcontext *context, GLenum target, GLuint texture);
EXPORT void cwcglBindTextureUnit(GLcontext *context, GLuint unit, GLuint texture);
EXPORT void cwcglBindTextureUnitParameterEXT(GLcontext *context, GLenum unit, GLenum value, GLuint* return_value);
EXPORT void cwcglBindTextures(GLcontext *context, GLuint first, GLsizei count, const GLuint * textures);
EXPORT void cwcglBindTransformFeedback(GLcontext *context, GLenum target, GLuint id);
EXPORT void cwcglBindTransformFeedbackNV(GLcontext *context, GLenum target, GLuint id);
EXPORT void cwcglBindVertexArray(GLcontext *context, GLuint array);
EXPORT void cwcglBindVertexArrayAPPLE(GLcontext *context, GLuint array);
EXPORT void cwcglBindVertexArrayOES(GLcontext *context, GLuint array);
EXPORT void cwcglBindVertexBuffer(GLcontext *context, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
EXPORT void cwcglBindVertexBuffers(GLcontext *context, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
EXPORT void cwcglBindVertexShaderEXT(GLcontext *context, GLuint id);
EXPORT void cwcglBindVideoCaptureStreamBufferNV(GLcontext *context, GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
EXPORT void cwcglBindVideoCaptureStreamTextureNV(GLcontext *context, GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
EXPORT void cwcglBinormal3bEXT(GLcontext *context, GLbyte bx, GLbyte by, GLbyte bz);
EXPORT void cwcglBinormal3bvEXT(GLcontext *context, const GLbyte * v);
EXPORT void cwcglBinormal3dEXT(GLcontext *context, GLdouble bx, GLdouble by, GLdouble bz);
EXPORT void cwcglBinormal3dvEXT(GLcontext *context, const GLdouble * v);
EXPORT void cwcglBinormal3fEXT(GLcontext *context, GLfloat bx, GLfloat by, GLfloat bz);
EXPORT void cwcglBinormal3fvEXT(GLcontext *context, const GLfloat * v);
EXPORT void cwcglBinormal3iEXT(GLcontext *context, GLint bx, GLint by, GLint bz);
EXPORT void cwcglBinormal3ivEXT(GLcontext *context, const GLint * v);
EXPORT void cwcglBinormal3sEXT(GLcontext *context, GLshort bx, GLshort by, GLshort bz);
EXPORT void cwcglBinormal3svEXT(GLcontext *context, const GLshort * v);
EXPORT void cwcglBinormalPointerEXT(GLcontext *context, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglBitmap(GLcontext *context, GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap);
EXPORT void cwcglBitmapxOES(GLcontext *context, GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, const GLubyte * bitmap);
EXPORT void cwcglBlendBarrier(GLcontext *context);
EXPORT void cwcglBlendBarrierKHR(GLcontext *context);
EXPORT void cwcglBlendBarrierNV(GLcontext *context);
EXPORT void cwcglBlendColor(GLcontext *context, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
EXPORT void cwcglBlendColorEXT(GLcontext *context, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
EXPORT void cwcglBlendColorxOES(GLcontext *context, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
EXPORT void cwcglBlendEquation(GLcontext *context, GLenum mode);
EXPORT void cwcglBlendEquationEXT(GLcontext *context, GLenum mode);
EXPORT void cwcglBlendEquationIndexedAMD(GLcontext *context, GLuint buf, GLenum mode);
EXPORT void cwcglBlendEquationOES(GLcontext *context, GLenum mode);
EXPORT void cwcglBlendEquationSeparate(GLcontext *context, GLenum modeRGB, GLenum modeAlpha);
EXPORT void cwcglBlendEquationSeparateEXT(GLcontext *context, GLenum modeRGB, GLenum modeAlpha);
EXPORT void cwcglBlendEquationSeparateIndexedAMD(GLcontext *context, GLuint buf, GLenum modeRGB, GLenum modeAlpha);
EXPORT void cwcglBlendEquationSeparateOES(GLcontext *context, GLenum modeRGB, GLenum modeAlpha);
EXPORT void cwcglBlendEquationSeparatei(GLcontext *context, GLuint buf, GLenum modeRGB, GLenum modeAlpha);
EXPORT void cwcglBlendEquationSeparateiARB(GLcontext *context, GLuint buf, GLenum modeRGB, GLenum modeAlpha);
EXPORT void cwcglBlendEquationSeparateiEXT(GLcontext *context, GLuint buf, GLenum modeRGB, GLenum modeAlpha);
EXPORT void cwcglBlendEquationSeparateiOES(GLcontext *context, GLuint buf, GLenum modeRGB, GLenum modeAlpha);
EXPORT void cwcglBlendEquationi(GLcontext *context, GLuint buf, GLenum mode);
EXPORT void cwcglBlendEquationiARB(GLcontext *context, GLuint buf, GLenum mode);
EXPORT void cwcglBlendEquationiEXT(GLcontext *context, GLuint buf, GLenum mode);
EXPORT void cwcglBlendEquationiOES(GLcontext *context, GLuint buf, GLenum mode);
EXPORT void cwcglBlendFunc(GLcontext *context, GLenum sfactor, GLenum dfactor);
EXPORT void cwcglBlendFuncIndexedAMD(GLcontext *context, GLuint buf, GLenum src, GLenum dst);
EXPORT void cwcglBlendFuncSeparate(GLcontext *context, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
EXPORT void cwcglBlendFuncSeparateEXT(GLcontext *context, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
EXPORT void cwcglBlendFuncSeparateINGR(GLcontext *context, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
EXPORT void cwcglBlendFuncSeparateIndexedAMD(GLcontext *context, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
EXPORT void cwcglBlendFuncSeparateOES(GLcontext *context, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
EXPORT void cwcglBlendFuncSeparatei(GLcontext *context, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
EXPORT void cwcglBlendFuncSeparateiARB(GLcontext *context, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
EXPORT void cwcglBlendFuncSeparateiEXT(GLcontext *context, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
EXPORT void cwcglBlendFuncSeparateiOES(GLcontext *context, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
EXPORT void cwcglBlendFunci(GLcontext *context, GLuint buf, GLenum src, GLenum dst);
EXPORT void cwcglBlendFunciARB(GLcontext *context, GLuint buf, GLenum src, GLenum dst);
EXPORT void cwcglBlendFunciEXT(GLcontext *context, GLuint buf, GLenum src, GLenum dst);
EXPORT void cwcglBlendFunciOES(GLcontext *context, GLuint buf, GLenum src, GLenum dst);
EXPORT void cwcglBlendParameteriNV(GLcontext *context, GLenum pname, GLint value);
EXPORT void cwcglBlitFramebuffer(GLcontext *context, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
EXPORT void cwcglBlitFramebufferANGLE(GLcontext *context, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
EXPORT void cwcglBlitFramebufferEXT(GLcontext *context, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
EXPORT void cwcglBlitFramebufferNV(GLcontext *context, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
EXPORT void cwcglBlitNamedFramebuffer(GLcontext *context, GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
EXPORT void cwcglBufferAddressRangeNV(GLcontext *context, GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
EXPORT void cwcglBufferData(GLcontext *context, GLenum target, GLsizeiptr size, const void * data, GLenum usage);
EXPORT void cwcglBufferDataARB(GLcontext *context, GLenum target, GLsizeiptrARB size, const void * data, GLenum usage);
EXPORT void cwcglBufferPageCommitmentARB(GLcontext *context, GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
EXPORT void cwcglBufferParameteriAPPLE(GLcontext *context, GLenum target, GLenum pname, GLint param);
EXPORT void cwcglBufferStorage(GLcontext *context, GLenum target, GLsizeiptr size, const void * data, GLbitfield flags);
EXPORT void cwcglBufferStorageEXT(GLcontext *context, GLenum target, GLsizeiptr size, const void * data, GLbitfield flags);
EXPORT void cwcglBufferSubData(GLcontext *context, GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
EXPORT void cwcglBufferSubDataARB(GLcontext *context, GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void * data);
EXPORT void cwcglCallCommandListNV(GLcontext *context, GLuint list);
EXPORT void cwcglCallList(GLcontext *context, GLuint list);
EXPORT void cwcglCallLists(GLcontext *context, GLsizei n, GLenum type, const void * lists);
EXPORT void cwcglCheckFramebufferStatus(GLcontext *context, GLenum target, GLenum* return_value);
EXPORT void cwcglCheckFramebufferStatusEXT(GLcontext *context, GLenum target, GLenum* return_value);
EXPORT void cwcglCheckFramebufferStatusOES(GLcontext *context, GLenum target, GLenum* return_value);
EXPORT void cwcglCheckNamedFramebufferStatus(GLcontext *context, GLuint framebuffer, GLenum target, GLenum* return_value);
EXPORT void cwcglCheckNamedFramebufferStatusEXT(GLcontext *context, GLuint framebuffer, GLenum target, GLenum* return_value);
EXPORT void cwcglClampColor(GLcontext *context, GLenum target, GLenum clamp);
EXPORT void cwcglClampColorARB(GLcontext *context, GLenum target, GLenum clamp);
EXPORT void cwcglClear(GLcontext *context, GLbitfield mask);
EXPORT void cwcglClearAccum(GLcontext *context, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
EXPORT void cwcglClearAccumxOES(GLcontext *context, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
EXPORT void cwcglClearBufferData(GLcontext *context, GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data);
EXPORT void cwcglClearBufferSubData(GLcontext *context, GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
EXPORT void cwcglClearBufferfi(GLcontext *context, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
EXPORT void cwcglClearBufferfv(GLcontext *context, GLenum buffer, GLint drawbuffer, const GLfloat * value);
EXPORT void cwcglClearBufferiv(GLcontext *context, GLenum buffer, GLint drawbuffer, const GLint * value);
EXPORT void cwcglClearBufferuiv(GLcontext *context, GLenum buffer, GLint drawbuffer, const GLuint * value);
EXPORT void cwcglClearColor(GLcontext *context, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
EXPORT void cwcglClearColorIiEXT(GLcontext *context, GLint red, GLint green, GLint blue, GLint alpha);
EXPORT void cwcglClearColorIuiEXT(GLcontext *context, GLuint red, GLuint green, GLuint blue, GLuint alpha);
EXPORT void cwcglClearColorx(GLcontext *context, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
EXPORT void cwcglClearColorxOES(GLcontext *context, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
EXPORT void cwcglClearDepth(GLcontext *context, GLdouble depth);
EXPORT void cwcglClearDepthdNV(GLcontext *context, GLdouble depth);
EXPORT void cwcglClearDepthf(GLcontext *context, GLfloat d);
EXPORT void cwcglClearDepthfOES(GLcontext *context, GLclampf depth);
EXPORT void cwcglClearDepthx(GLcontext *context, GLfixed depth);
EXPORT void cwcglClearDepthxOES(GLcontext *context, GLfixed depth);
EXPORT void cwcglClearIndex(GLcontext *context, GLfloat c);
EXPORT void cwcglClearNamedBufferData(GLcontext *context, GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
EXPORT void cwcglClearNamedBufferDataEXT(GLcontext *context, GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
EXPORT void cwcglClearNamedBufferSubData(GLcontext *context, GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
EXPORT void cwcglClearNamedBufferSubDataEXT(GLcontext *context, GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
EXPORT void cwcglClearNamedFramebufferfi(GLcontext *context, GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
EXPORT void cwcglClearNamedFramebufferfv(GLcontext *context, GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat * value);
EXPORT void cwcglClearNamedFramebufferiv(GLcontext *context, GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value);
EXPORT void cwcglClearNamedFramebufferuiv(GLcontext *context, GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value);
EXPORT void cwcglClearPixelLocalStorageuiEXT(GLcontext *context, GLsizei offset, GLsizei n, const GLuint * values);
EXPORT void cwcglClearStencil(GLcontext *context, GLint s);
EXPORT void cwcglClearTexImage(GLcontext *context, GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
EXPORT void cwcglClearTexImageEXT(GLcontext *context, GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
EXPORT void cwcglClearTexSubImage(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
EXPORT void cwcglClearTexSubImageEXT(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
EXPORT void cwcglClientActiveTexture(GLcontext *context, GLenum texture);
EXPORT void cwcglClientActiveTextureARB(GLcontext *context, GLenum texture);
EXPORT void cwcglClientActiveVertexStreamATI(GLcontext *context, GLenum stream);
EXPORT void cwcglClientAttribDefaultEXT(GLcontext *context, GLbitfield mask);
EXPORT void cwcglClientWaitSync(GLcontext *context, GLsync sync, GLbitfield flags, GLuint64 timeout, GLenum* return_value);
EXPORT void cwcglClientWaitSyncAPPLE(GLcontext *context, GLsync sync, GLbitfield flags, GLuint64 timeout, GLenum* return_value);
EXPORT void cwcglClipControl(GLcontext *context, GLenum origin, GLenum depth);
EXPORT void cwcglClipPlane(GLcontext *context, GLenum plane, const GLdouble * equation);
EXPORT void cwcglClipPlanef(GLcontext *context, GLenum p, const GLfloat * eqn);
EXPORT void cwcglClipPlanefIMG(GLcontext *context, GLenum p, const GLfloat * eqn);
EXPORT void cwcglClipPlanefOES(GLcontext *context, GLenum plane, const GLfloat * equation);
EXPORT void cwcglClipPlanex(GLcontext *context, GLenum plane, const GLfixed * equation);
EXPORT void cwcglClipPlanexIMG(GLcontext *context, GLenum p, const GLfixed * eqn);
EXPORT void cwcglClipPlanexOES(GLcontext *context, GLenum plane, const GLfixed * equation);
EXPORT void cwcglColor3b(GLcontext *context, GLbyte red, GLbyte green, GLbyte blue);
EXPORT void cwcglColor3bv(GLcontext *context, const GLbyte * v);
EXPORT void cwcglColor3d(GLcontext *context, GLdouble red, GLdouble green, GLdouble blue);
EXPORT void cwcglColor3dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglColor3f(GLcontext *context, GLfloat red, GLfloat green, GLfloat blue);
EXPORT void cwcglColor3fVertex3fSUN(GLcontext *context, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglColor3fVertex3fvSUN(GLcontext *context, const GLfloat * c, const GLfloat * v);
EXPORT void cwcglColor3fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglColor3hNV(GLcontext *context, GLhalfNV red, GLhalfNV green, GLhalfNV blue);
EXPORT void cwcglColor3hvNV(GLcontext *context, const GLhalfNV * v);
EXPORT void cwcglColor3i(GLcontext *context, GLint red, GLint green, GLint blue);
EXPORT void cwcglColor3iv(GLcontext *context, const GLint * v);
EXPORT void cwcglColor3s(GLcontext *context, GLshort red, GLshort green, GLshort blue);
EXPORT void cwcglColor3sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglColor3ub(GLcontext *context, GLubyte red, GLubyte green, GLubyte blue);
EXPORT void cwcglColor3ubv(GLcontext *context, const GLubyte * v);
EXPORT void cwcglColor3ui(GLcontext *context, GLuint red, GLuint green, GLuint blue);
EXPORT void cwcglColor3uiv(GLcontext *context, const GLuint * v);
EXPORT void cwcglColor3us(GLcontext *context, GLushort red, GLushort green, GLushort blue);
EXPORT void cwcglColor3usv(GLcontext *context, const GLushort * v);
EXPORT void cwcglColor3xOES(GLcontext *context, GLfixed red, GLfixed green, GLfixed blue);
EXPORT void cwcglColor3xvOES(GLcontext *context, const GLfixed * components);
EXPORT void cwcglColor4b(GLcontext *context, GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
EXPORT void cwcglColor4bv(GLcontext *context, const GLbyte * v);
EXPORT void cwcglColor4d(GLcontext *context, GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
EXPORT void cwcglColor4dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglColor4f(GLcontext *context, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
EXPORT void cwcglColor4fNormal3fVertex3fSUN(GLcontext *context, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglColor4fNormal3fVertex3fvSUN(GLcontext *context, const GLfloat * c, const GLfloat * n, const GLfloat * v);
EXPORT void cwcglColor4fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglColor4hNV(GLcontext *context, GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
EXPORT void cwcglColor4hvNV(GLcontext *context, const GLhalfNV * v);
EXPORT void cwcglColor4i(GLcontext *context, GLint red, GLint green, GLint blue, GLint alpha);
EXPORT void cwcglColor4iv(GLcontext *context, const GLint * v);
EXPORT void cwcglColor4s(GLcontext *context, GLshort red, GLshort green, GLshort blue, GLshort alpha);
EXPORT void cwcglColor4sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglColor4ub(GLcontext *context, GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
EXPORT void cwcglColor4ubVertex2fSUN(GLcontext *context, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
EXPORT void cwcglColor4ubVertex2fvSUN(GLcontext *context, const GLubyte * c, const GLfloat * v);
EXPORT void cwcglColor4ubVertex3fSUN(GLcontext *context, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglColor4ubVertex3fvSUN(GLcontext *context, const GLubyte * c, const GLfloat * v);
EXPORT void cwcglColor4ubv(GLcontext *context, const GLubyte * v);
EXPORT void cwcglColor4ui(GLcontext *context, GLuint red, GLuint green, GLuint blue, GLuint alpha);
EXPORT void cwcglColor4uiv(GLcontext *context, const GLuint * v);
EXPORT void cwcglColor4us(GLcontext *context, GLushort red, GLushort green, GLushort blue, GLushort alpha);
EXPORT void cwcglColor4usv(GLcontext *context, const GLushort * v);
EXPORT void cwcglColor4x(GLcontext *context, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
EXPORT void cwcglColor4xOES(GLcontext *context, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
EXPORT void cwcglColor4xvOES(GLcontext *context, const GLfixed * components);
EXPORT void cwcglColorFormatNV(GLcontext *context, GLint size, GLenum type, GLsizei stride);
EXPORT void cwcglColorFragmentOp1ATI(GLcontext *context, GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
EXPORT void cwcglColorFragmentOp2ATI(GLcontext *context, GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
EXPORT void cwcglColorFragmentOp3ATI(GLcontext *context, GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
EXPORT void cwcglColorMask(GLcontext *context, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
EXPORT void cwcglColorMaskIndexedEXT(GLcontext *context, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
EXPORT void cwcglColorMaski(GLcontext *context, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
EXPORT void cwcglColorMaskiEXT(GLcontext *context, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
EXPORT void cwcglColorMaskiOES(GLcontext *context, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
EXPORT void cwcglColorMaterial(GLcontext *context, GLenum face, GLenum mode);
EXPORT void cwcglColorP3ui(GLcontext *context, GLenum type, GLuint color);
EXPORT void cwcglColorP3uiv(GLcontext *context, GLenum type, const GLuint * color);
EXPORT void cwcglColorP4ui(GLcontext *context, GLenum type, GLuint color);
EXPORT void cwcglColorP4uiv(GLcontext *context, GLenum type, const GLuint * color);
EXPORT void cwcglColorPointer(GLcontext *context, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglColorPointerEXT(GLcontext *context, GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer);
EXPORT void cwcglColorPointerListIBM(GLcontext *context, GLint size, GLenum type, GLint stride, const void ** pointer, GLint ptrstride);
EXPORT void cwcglColorPointervINTEL(GLcontext *context, GLint size, GLenum type, const void ** pointer);
EXPORT void cwcglColorSubTable(GLcontext *context, GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void * data);
EXPORT void cwcglColorSubTableEXT(GLcontext *context, GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void * data);
EXPORT void cwcglColorTable(GLcontext *context, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * table);
EXPORT void cwcglColorTableEXT(GLcontext *context, GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void * table);
EXPORT void cwcglColorTableParameterfv(GLcontext *context, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglColorTableParameterfvSGI(GLcontext *context, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglColorTableParameteriv(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglColorTableParameterivSGI(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglColorTableSGI(GLcontext *context, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * table);
EXPORT void cwcglCombinerInputNV(GLcontext *context, GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
EXPORT void cwcglCombinerOutputNV(GLcontext *context, GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
EXPORT void cwcglCombinerParameterfNV(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglCombinerParameterfvNV(GLcontext *context, GLenum pname, const GLfloat * params);
EXPORT void cwcglCombinerParameteriNV(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglCombinerParameterivNV(GLcontext *context, GLenum pname, const GLint * params);
EXPORT void cwcglCombinerStageParameterfvNV(GLcontext *context, GLenum stage, GLenum pname, const GLfloat * params);
EXPORT void cwcglCommandListSegmentsNV(GLcontext *context, GLuint list, GLuint segments);
EXPORT void cwcglCompileCommandListNV(GLcontext *context, GLuint list);
EXPORT void cwcglCompileShader(GLcontext *context, GLuint shader);
EXPORT void cwcglCompileShaderARB(GLcontext *context, GLhandleARB shaderObj);
EXPORT void cwcglCompileShaderIncludeARB(GLcontext *context, GLuint shader, GLsizei count, const GLchar *const* path, const GLint * length);
EXPORT void cwcglCompressedMultiTexImage1DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits);
EXPORT void cwcglCompressedMultiTexImage2DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits);
EXPORT void cwcglCompressedMultiTexImage3DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits);
EXPORT void cwcglCompressedMultiTexSubImage1DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits);
EXPORT void cwcglCompressedMultiTexSubImage2DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits);
EXPORT void cwcglCompressedMultiTexSubImage3DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits);
EXPORT void cwcglCompressedTexImage1D(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexImage1DARB(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexImage2D(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexImage2DARB(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexImage3D(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexImage3DARB(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexImage3DOES(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexSubImage1D(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexSubImage1DARB(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexSubImage2D(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexSubImage2DARB(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexSubImage3D(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexSubImage3DARB(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTexSubImage3DOES(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTextureImage1DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits);
EXPORT void cwcglCompressedTextureImage2DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits);
EXPORT void cwcglCompressedTextureImage3DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits);
EXPORT void cwcglCompressedTextureSubImage1D(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTextureSubImage1DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits);
EXPORT void cwcglCompressedTextureSubImage2D(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTextureSubImage2DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits);
EXPORT void cwcglCompressedTextureSubImage3D(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
EXPORT void cwcglCompressedTextureSubImage3DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits);
EXPORT void cwcglConservativeRasterParameterfNV(GLcontext *context, GLenum pname, GLfloat value);
EXPORT void cwcglConservativeRasterParameteriNV(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglConvolutionFilter1D(GLcontext *context, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * image);
EXPORT void cwcglConvolutionFilter1DEXT(GLcontext *context, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * image);
EXPORT void cwcglConvolutionFilter2D(GLcontext *context, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * image);
EXPORT void cwcglConvolutionFilter2DEXT(GLcontext *context, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * image);
EXPORT void cwcglConvolutionParameterf(GLcontext *context, GLenum target, GLenum pname, GLfloat params);
EXPORT void cwcglConvolutionParameterfEXT(GLcontext *context, GLenum target, GLenum pname, GLfloat params);
EXPORT void cwcglConvolutionParameterfv(GLcontext *context, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglConvolutionParameterfvEXT(GLcontext *context, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglConvolutionParameteri(GLcontext *context, GLenum target, GLenum pname, GLint params);
EXPORT void cwcglConvolutionParameteriEXT(GLcontext *context, GLenum target, GLenum pname, GLint params);
EXPORT void cwcglConvolutionParameteriv(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglConvolutionParameterivEXT(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglConvolutionParameterxOES(GLcontext *context, GLenum target, GLenum pname, GLfixed param);
EXPORT void cwcglConvolutionParameterxvOES(GLcontext *context, GLenum target, GLenum pname, const GLfixed * params);
EXPORT void cwcglCopyBufferSubData(GLcontext *context, GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
EXPORT void cwcglCopyBufferSubDataNV(GLcontext *context, GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
EXPORT void cwcglCopyColorSubTable(GLcontext *context, GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
EXPORT void cwcglCopyColorSubTableEXT(GLcontext *context, GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
EXPORT void cwcglCopyColorTable(GLcontext *context, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
EXPORT void cwcglCopyColorTableSGI(GLcontext *context, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
EXPORT void cwcglCopyConvolutionFilter1D(GLcontext *context, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
EXPORT void cwcglCopyConvolutionFilter1DEXT(GLcontext *context, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
EXPORT void cwcglCopyConvolutionFilter2D(GLcontext *context, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyConvolutionFilter2DEXT(GLcontext *context, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyImageSubData(GLcontext *context, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
EXPORT void cwcglCopyImageSubDataEXT(GLcontext *context, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
EXPORT void cwcglCopyImageSubDataNV(GLcontext *context, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
EXPORT void cwcglCopyImageSubDataOES(GLcontext *context, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
EXPORT void cwcglCopyMultiTexImage1DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
EXPORT void cwcglCopyMultiTexImage2DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
EXPORT void cwcglCopyMultiTexSubImage1DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
EXPORT void cwcglCopyMultiTexSubImage2DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyMultiTexSubImage3DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyNamedBufferSubData(GLcontext *context, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
EXPORT void cwcglCopyPathNV(GLcontext *context, GLuint resultPath, GLuint srcPath);
EXPORT void cwcglCopyPixels(GLcontext *context, GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
EXPORT void cwcglCopyTexImage1D(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
EXPORT void cwcglCopyTexImage1DEXT(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
EXPORT void cwcglCopyTexImage2D(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
EXPORT void cwcglCopyTexImage2DEXT(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
EXPORT void cwcglCopyTexSubImage1D(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
EXPORT void cwcglCopyTexSubImage1DEXT(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
EXPORT void cwcglCopyTexSubImage2D(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyTexSubImage2DEXT(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyTexSubImage3D(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyTexSubImage3DEXT(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyTexSubImage3DOES(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyTextureImage1DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
EXPORT void cwcglCopyTextureImage2DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
EXPORT void cwcglCopyTextureLevelsAPPLE(GLcontext *context, GLuint destinationTexture, GLuint sourceTexture, GLint sourceBaseLevel, GLsizei sourceLevelCount);
EXPORT void cwcglCopyTextureSubImage1D(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
EXPORT void cwcglCopyTextureSubImage1DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
EXPORT void cwcglCopyTextureSubImage2D(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyTextureSubImage2DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyTextureSubImage3D(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCopyTextureSubImage3DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglCoverFillPathInstancedNV(GLcontext *context, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
EXPORT void cwcglCoverFillPathNV(GLcontext *context, GLuint path, GLenum coverMode);
EXPORT void cwcglCoverStrokePathInstancedNV(GLcontext *context, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
EXPORT void cwcglCoverStrokePathNV(GLcontext *context, GLuint path, GLenum coverMode);
EXPORT void cwcglCoverageMaskNV(GLcontext *context, GLboolean mask);
EXPORT void cwcglCoverageModulationNV(GLcontext *context, GLenum components);
EXPORT void cwcglCoverageModulationTableNV(GLcontext *context, GLsizei n, const GLfloat * v);
EXPORT void cwcglCoverageOperationNV(GLcontext *context, GLenum operation);
EXPORT void cwcglCreateBuffers(GLcontext *context, GLsizei n, GLuint * buffers);
EXPORT void cwcglCreateCommandListsNV(GLcontext *context, GLsizei n, GLuint * lists);
EXPORT void cwcglCreateFramebuffers(GLcontext *context, GLsizei n, GLuint * framebuffers);
EXPORT void cwcglCreatePerfQueryINTEL(GLcontext *context, GLuint queryId, GLuint * queryHandle);
EXPORT void cwcglCreateProgram(GLcontext *context, GLuint* return_value);
EXPORT void cwcglCreateProgramObjectARB(GLcontext *context, GLhandleARB* return_value);
EXPORT void cwcglCreateProgramPipelines(GLcontext *context, GLsizei n, GLuint * pipelines);
EXPORT void cwcglCreateQueries(GLcontext *context, GLenum target, GLsizei n, GLuint * ids);
EXPORT void cwcglCreateRenderbuffers(GLcontext *context, GLsizei n, GLuint * renderbuffers);
EXPORT void cwcglCreateSamplers(GLcontext *context, GLsizei n, GLuint * samplers);
EXPORT void cwcglCreateShader(GLcontext *context, GLenum type, GLuint* return_value);
EXPORT void cwcglCreateShaderObjectARB(GLcontext *context, GLenum shaderType, GLhandleARB* return_value);
EXPORT void cwcglCreateShaderProgramEXT(GLcontext *context, GLenum type, const GLchar * string, GLuint* return_value);
EXPORT void cwcglCreateShaderProgramv(GLcontext *context, GLenum type, GLsizei count, const GLchar *const* strings, GLuint* return_value);
EXPORT void cwcglCreateShaderProgramvEXT(GLcontext *context, GLenum type, GLsizei count, const GLchar ** strings, GLuint* return_value);
EXPORT void cwcglCreateStatesNV(GLcontext *context, GLsizei n, GLuint * states);
EXPORT void cwcglCreateSyncFromCLeventARB(GLcontext *context, struct _cl_context * context, struct _cl_event * event, GLbitfield flags, GLsync* return_value);
EXPORT void cwcglCreateTextures(GLcontext *context, GLenum target, GLsizei n, GLuint * textures);
EXPORT void cwcglCreateTransformFeedbacks(GLcontext *context, GLsizei n, GLuint * ids);
EXPORT void cwcglCreateVertexArrays(GLcontext *context, GLsizei n, GLuint * arrays);
EXPORT void cwcglCullFace(GLcontext *context, GLenum mode);
EXPORT void cwcglCullParameterdvEXT(GLcontext *context, GLenum pname, GLdouble * params);
EXPORT void cwcglCullParameterfvEXT(GLcontext *context, GLenum pname, GLfloat * params);
EXPORT void cwcglCurrentPaletteMatrixARB(GLcontext *context, GLint index);
EXPORT void cwcglCurrentPaletteMatrixOES(GLcontext *context, GLuint matrixpaletteindex);
EXPORT void cwcglDebugMessageCallback(GLcontext *context, GLDEBUGPROC callback, const void * userParam);
EXPORT void cwcglDebugMessageCallbackAMD(GLcontext *context, GLDEBUGPROCAMD callback, void * userParam);
EXPORT void cwcglDebugMessageCallbackARB(GLcontext *context, GLDEBUGPROCARB callback, const void * userParam);
EXPORT void cwcglDebugMessageCallbackKHR(GLcontext *context, GLDEBUGPROCKHR callback, const void * userParam);
EXPORT void cwcglDebugMessageControl(GLcontext *context, GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
EXPORT void cwcglDebugMessageControlARB(GLcontext *context, GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
EXPORT void cwcglDebugMessageControlKHR(GLcontext *context, GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
EXPORT void cwcglDebugMessageEnableAMD(GLcontext *context, GLenum category, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
EXPORT void cwcglDebugMessageInsert(GLcontext *context, GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
EXPORT void cwcglDebugMessageInsertAMD(GLcontext *context, GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar * buf);
EXPORT void cwcglDebugMessageInsertARB(GLcontext *context, GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
EXPORT void cwcglDebugMessageInsertKHR(GLcontext *context, GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
EXPORT void cwcglDeformSGIX(GLcontext *context, GLbitfield mask);
EXPORT void cwcglDeformationMap3dSGIX(GLcontext *context, GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble * points);
EXPORT void cwcglDeformationMap3fSGIX(GLcontext *context, GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat * points);
EXPORT void cwcglDeleteAsyncMarkersSGIX(GLcontext *context, GLuint marker, GLsizei range);
EXPORT void cwcglDeleteBuffers(GLcontext *context, GLsizei n, const GLuint * buffers);
EXPORT void cwcglDeleteBuffersARB(GLcontext *context, GLsizei n, const GLuint * buffers);
EXPORT void cwcglDeleteCommandListsNV(GLcontext *context, GLsizei n, const GLuint * lists);
EXPORT void cwcglDeleteFencesAPPLE(GLcontext *context, GLsizei n, const GLuint * fences);
EXPORT void cwcglDeleteFencesNV(GLcontext *context, GLsizei n, const GLuint * fences);
EXPORT void cwcglDeleteFragmentShaderATI(GLcontext *context, GLuint id);
EXPORT void cwcglDeleteFramebuffers(GLcontext *context, GLsizei n, const GLuint * framebuffers);
EXPORT void cwcglDeleteFramebuffersEXT(GLcontext *context, GLsizei n, const GLuint * framebuffers);
EXPORT void cwcglDeleteFramebuffersOES(GLcontext *context, GLsizei n, const GLuint * framebuffers);
EXPORT void cwcglDeleteLists(GLcontext *context, GLuint list, GLsizei range);
EXPORT void cwcglDeleteNamedStringARB(GLcontext *context, GLint namelen, const GLchar * name);
EXPORT void cwcglDeleteNamesAMD(GLcontext *context, GLenum identifier, GLuint num, const GLuint * names);
EXPORT void cwcglDeleteObjectARB(GLcontext *context, GLhandleARB obj);
EXPORT void cwcglDeleteOcclusionQueriesNV(GLcontext *context, GLsizei n, const GLuint * ids);
EXPORT void cwcglDeletePathsNV(GLcontext *context, GLuint path, GLsizei range);
EXPORT void cwcglDeletePerfMonitorsAMD(GLcontext *context, GLsizei n, GLuint * monitors);
EXPORT void cwcglDeletePerfQueryINTEL(GLcontext *context, GLuint queryHandle);
EXPORT void cwcglDeleteProgram(GLcontext *context, GLuint program);
EXPORT void cwcglDeleteProgramPipelines(GLcontext *context, GLsizei n, const GLuint * pipelines);
EXPORT void cwcglDeleteProgramPipelinesEXT(GLcontext *context, GLsizei n, const GLuint * pipelines);
EXPORT void cwcglDeleteProgramsARB(GLcontext *context, GLsizei n, const GLuint * programs);
EXPORT void cwcglDeleteProgramsNV(GLcontext *context, GLsizei n, const GLuint * programs);
EXPORT void cwcglDeleteQueries(GLcontext *context, GLsizei n, const GLuint * ids);
EXPORT void cwcglDeleteQueriesARB(GLcontext *context, GLsizei n, const GLuint * ids);
EXPORT void cwcglDeleteQueriesEXT(GLcontext *context, GLsizei n, const GLuint * ids);
EXPORT void cwcglDeleteRenderbuffers(GLcontext *context, GLsizei n, const GLuint * renderbuffers);
EXPORT void cwcglDeleteRenderbuffersEXT(GLcontext *context, GLsizei n, const GLuint * renderbuffers);
EXPORT void cwcglDeleteRenderbuffersOES(GLcontext *context, GLsizei n, const GLuint * renderbuffers);
EXPORT void cwcglDeleteSamplers(GLcontext *context, GLsizei count, const GLuint * samplers);
EXPORT void cwcglDeleteShader(GLcontext *context, GLuint shader);
EXPORT void cwcglDeleteStatesNV(GLcontext *context, GLsizei n, const GLuint * states);
EXPORT void cwcglDeleteSync(GLcontext *context, GLsync sync);
EXPORT void cwcglDeleteSyncAPPLE(GLcontext *context, GLsync sync);
EXPORT void cwcglDeleteTextures(GLcontext *context, GLsizei n, const GLuint * textures);
EXPORT void cwcglDeleteTexturesEXT(GLcontext *context, GLsizei n, const GLuint * textures);
EXPORT void cwcglDeleteTransformFeedbacks(GLcontext *context, GLsizei n, const GLuint * ids);
EXPORT void cwcglDeleteTransformFeedbacksNV(GLcontext *context, GLsizei n, const GLuint * ids);
EXPORT void cwcglDeleteVertexArrays(GLcontext *context, GLsizei n, const GLuint * arrays);
EXPORT void cwcglDeleteVertexArraysAPPLE(GLcontext *context, GLsizei n, const GLuint * arrays);
EXPORT void cwcglDeleteVertexArraysOES(GLcontext *context, GLsizei n, const GLuint * arrays);
EXPORT void cwcglDeleteVertexShaderEXT(GLcontext *context, GLuint id);
EXPORT void cwcglDepthBoundsEXT(GLcontext *context, GLclampd zmin, GLclampd zmax);
EXPORT void cwcglDepthBoundsdNV(GLcontext *context, GLdouble zmin, GLdouble zmax);
EXPORT void cwcglDepthFunc(GLcontext *context, GLenum func);
EXPORT void cwcglDepthMask(GLcontext *context, GLboolean flag);
EXPORT void cwcglDepthRange(GLcontext *context, GLdouble near, GLdouble far);
EXPORT void cwcglDepthRangeArrayfvNV(GLcontext *context, GLuint first, GLsizei count, const GLfloat * v);
EXPORT void cwcglDepthRangeArrayfvOES(GLcontext *context, GLuint first, GLsizei count, const GLfloat * v);
EXPORT void cwcglDepthRangeArrayv(GLcontext *context, GLuint first, GLsizei count, const GLdouble * v);
EXPORT void cwcglDepthRangeIndexed(GLcontext *context, GLuint index, GLdouble n, GLdouble f);
EXPORT void cwcglDepthRangeIndexedfNV(GLcontext *context, GLuint index, GLfloat n, GLfloat f);
EXPORT void cwcglDepthRangeIndexedfOES(GLcontext *context, GLuint index, GLfloat n, GLfloat f);
EXPORT void cwcglDepthRangedNV(GLcontext *context, GLdouble zNear, GLdouble zFar);
EXPORT void cwcglDepthRangef(GLcontext *context, GLfloat n, GLfloat f);
EXPORT void cwcglDepthRangefOES(GLcontext *context, GLclampf n, GLclampf f);
EXPORT void cwcglDepthRangex(GLcontext *context, GLfixed n, GLfixed f);
EXPORT void cwcglDepthRangexOES(GLcontext *context, GLfixed n, GLfixed f);
EXPORT void cwcglDetachObjectARB(GLcontext *context, GLhandleARB containerObj, GLhandleARB attachedObj);
EXPORT void cwcglDetachShader(GLcontext *context, GLuint program, GLuint shader);
EXPORT void cwcglDetailTexFuncSGIS(GLcontext *context, GLenum target, GLsizei n, const GLfloat * points);
EXPORT void cwcglDisable(GLcontext *context, GLenum cap);
EXPORT void cwcglDisableClientState(GLcontext *context, GLenum array);
EXPORT void cwcglDisableClientStateIndexedEXT(GLcontext *context, GLenum array, GLuint index);
EXPORT void cwcglDisableClientStateiEXT(GLcontext *context, GLenum array, GLuint index);
EXPORT void cwcglDisableDriverControlQCOM(GLcontext *context, GLuint driverControl);
EXPORT void cwcglDisableIndexedEXT(GLcontext *context, GLenum target, GLuint index);
EXPORT void cwcglDisableVariantClientStateEXT(GLcontext *context, GLuint id);
EXPORT void cwcglDisableVertexArrayAttrib(GLcontext *context, GLuint vaobj, GLuint index);
EXPORT void cwcglDisableVertexArrayAttribEXT(GLcontext *context, GLuint vaobj, GLuint index);
EXPORT void cwcglDisableVertexArrayEXT(GLcontext *context, GLuint vaobj, GLenum array);
EXPORT void cwcglDisableVertexAttribAPPLE(GLcontext *context, GLuint index, GLenum pname);
EXPORT void cwcglDisableVertexAttribArray(GLcontext *context, GLuint index);
EXPORT void cwcglDisableVertexAttribArrayARB(GLcontext *context, GLuint index);
EXPORT void cwcglDisablei(GLcontext *context, GLenum target, GLuint index);
EXPORT void cwcglDisableiEXT(GLcontext *context, GLenum target, GLuint index);
EXPORT void cwcglDisableiNV(GLcontext *context, GLenum target, GLuint index);
EXPORT void cwcglDisableiOES(GLcontext *context, GLenum target, GLuint index);
EXPORT void cwcglDiscardFramebufferEXT(GLcontext *context, GLenum target, GLsizei numAttachments, const GLenum * attachments);
EXPORT void cwcglDispatchCompute(GLcontext *context, GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
EXPORT void cwcglDispatchComputeGroupSizeARB(GLcontext *context, GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
EXPORT void cwcglDispatchComputeIndirect(GLcontext *context, GLintptr indirect);
EXPORT void cwcglDrawArrays(GLcontext *context, GLenum mode, GLint first, GLsizei count);
EXPORT void cwcglDrawArraysEXT(GLcontext *context, GLenum mode, GLint first, GLsizei count);
EXPORT void cwcglDrawArraysIndirect(GLcontext *context, GLenum mode, const void * indirect);
EXPORT void cwcglDrawArraysInstanced(GLcontext *context, GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
EXPORT void cwcglDrawArraysInstancedANGLE(GLcontext *context, GLenum mode, GLint first, GLsizei count, GLsizei primcount);
EXPORT void cwcglDrawArraysInstancedARB(GLcontext *context, GLenum mode, GLint first, GLsizei count, GLsizei primcount);
EXPORT void cwcglDrawArraysInstancedBaseInstance(GLcontext *context, GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
EXPORT void cwcglDrawArraysInstancedBaseInstanceEXT(GLcontext *context, GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
EXPORT void cwcglDrawArraysInstancedEXT(GLcontext *context, GLenum mode, GLint start, GLsizei count, GLsizei primcount);
EXPORT void cwcglDrawArraysInstancedNV(GLcontext *context, GLenum mode, GLint first, GLsizei count, GLsizei primcount);
EXPORT void cwcglDrawBuffer(GLcontext *context, GLenum buf);
EXPORT void cwcglDrawBuffers(GLcontext *context, GLsizei n, const GLenum * bufs);
EXPORT void cwcglDrawBuffersARB(GLcontext *context, GLsizei n, const GLenum * bufs);
EXPORT void cwcglDrawBuffersATI(GLcontext *context, GLsizei n, const GLenum * bufs);
EXPORT void cwcglDrawBuffersEXT(GLcontext *context, GLsizei n, const GLenum * bufs);
EXPORT void cwcglDrawBuffersIndexedEXT(GLcontext *context, GLint n, const GLenum * location, const GLint * indices);
EXPORT void cwcglDrawBuffersNV(GLcontext *context, GLsizei n, const GLenum * bufs);
EXPORT void cwcglDrawCommandsAddressNV(GLcontext *context, GLenum primitiveMode, const GLuint64 * indirects, const GLsizei * sizes, GLuint count);
EXPORT void cwcglDrawCommandsNV(GLcontext *context, GLenum primitiveMode, GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, GLuint count);
EXPORT void cwcglDrawCommandsStatesAddressNV(GLcontext *context, const GLuint64 * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count);
EXPORT void cwcglDrawCommandsStatesNV(GLcontext *context, GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count);
EXPORT void cwcglDrawElementArrayAPPLE(GLcontext *context, GLenum mode, GLint first, GLsizei count);
EXPORT void cwcglDrawElementArrayATI(GLcontext *context, GLenum mode, GLsizei count);
EXPORT void cwcglDrawElements(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices);
EXPORT void cwcglDrawElementsBaseVertex(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
EXPORT void cwcglDrawElementsBaseVertexEXT(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
EXPORT void cwcglDrawElementsBaseVertexOES(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
EXPORT void cwcglDrawElementsIndirect(GLcontext *context, GLenum mode, GLenum type, const void * indirect);
EXPORT void cwcglDrawElementsInstanced(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount);
EXPORT void cwcglDrawElementsInstancedANGLE(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
EXPORT void cwcglDrawElementsInstancedARB(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
EXPORT void cwcglDrawElementsInstancedBaseInstance(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
EXPORT void cwcglDrawElementsInstancedBaseInstanceEXT(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
EXPORT void cwcglDrawElementsInstancedBaseVertex(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
EXPORT void cwcglDrawElementsInstancedBaseVertexBaseInstance(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
EXPORT void cwcglDrawElementsInstancedBaseVertexBaseInstanceEXT(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
EXPORT void cwcglDrawElementsInstancedBaseVertexEXT(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
EXPORT void cwcglDrawElementsInstancedBaseVertexOES(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
EXPORT void cwcglDrawElementsInstancedEXT(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
EXPORT void cwcglDrawElementsInstancedNV(GLcontext *context, GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
EXPORT void cwcglDrawMeshArraysSUN(GLcontext *context, GLenum mode, GLint first, GLsizei count, GLsizei width);
EXPORT void cwcglDrawPixels(GLcontext *context, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglDrawRangeElementArrayAPPLE(GLcontext *context, GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
EXPORT void cwcglDrawRangeElementArrayATI(GLcontext *context, GLenum mode, GLuint start, GLuint end, GLsizei count);
EXPORT void cwcglDrawRangeElements(GLcontext *context, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
EXPORT void cwcglDrawRangeElementsBaseVertex(GLcontext *context, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
EXPORT void cwcglDrawRangeElementsBaseVertexEXT(GLcontext *context, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
EXPORT void cwcglDrawRangeElementsBaseVertexOES(GLcontext *context, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
EXPORT void cwcglDrawRangeElementsEXT(GLcontext *context, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
EXPORT void cwcglDrawTexfOES(GLcontext *context, GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height);
EXPORT void cwcglDrawTexfvOES(GLcontext *context, const GLfloat * coords);
EXPORT void cwcglDrawTexiOES(GLcontext *context, GLint x, GLint y, GLint z, GLint width, GLint height);
EXPORT void cwcglDrawTexivOES(GLcontext *context, const GLint * coords);
EXPORT void cwcglDrawTexsOES(GLcontext *context, GLshort x, GLshort y, GLshort z, GLshort width, GLshort height);
EXPORT void cwcglDrawTexsvOES(GLcontext *context, const GLshort * coords);
EXPORT void cwcglDrawTextureNV(GLcontext *context, GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
EXPORT void cwcglDrawTexxOES(GLcontext *context, GLfixed x, GLfixed y, GLfixed z, GLfixed width, GLfixed height);
EXPORT void cwcglDrawTexxvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglDrawTransformFeedback(GLcontext *context, GLenum mode, GLuint id);
EXPORT void cwcglDrawTransformFeedbackEXT(GLcontext *context, GLenum mode, GLuint id);
EXPORT void cwcglDrawTransformFeedbackInstanced(GLcontext *context, GLenum mode, GLuint id, GLsizei instancecount);
EXPORT void cwcglDrawTransformFeedbackInstancedEXT(GLcontext *context, GLenum mode, GLuint id, GLsizei instancecount);
EXPORT void cwcglDrawTransformFeedbackNV(GLcontext *context, GLenum mode, GLuint id);
EXPORT void cwcglDrawTransformFeedbackStream(GLcontext *context, GLenum mode, GLuint id, GLuint stream);
EXPORT void cwcglDrawTransformFeedbackStreamInstanced(GLcontext *context, GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
EXPORT void cwcglEGLImageTargetRenderbufferStorageOES(GLcontext *context, GLenum target, GLeglImageOES image);
EXPORT void cwcglEGLImageTargetTexture2DOES(GLcontext *context, GLenum target, GLeglImageOES image);
EXPORT void cwcglEdgeFlag(GLcontext *context, GLboolean flag);
EXPORT void cwcglEdgeFlagFormatNV(GLcontext *context, GLsizei stride);
EXPORT void cwcglEdgeFlagPointer(GLcontext *context, GLsizei stride, const void * pointer);
EXPORT void cwcglEdgeFlagPointerEXT(GLcontext *context, GLsizei stride, GLsizei count, const GLboolean * pointer);
EXPORT void cwcglEdgeFlagPointerListIBM(GLcontext *context, GLint stride, const GLboolean ** pointer, GLint ptrstride);
EXPORT void cwcglEdgeFlagv(GLcontext *context, const GLboolean * flag);
EXPORT void cwcglElementPointerAPPLE(GLcontext *context, GLenum type, const void * pointer);
EXPORT void cwcglElementPointerATI(GLcontext *context, GLenum type, const void * pointer);
EXPORT void cwcglEnable(GLcontext *context, GLenum cap);
EXPORT void cwcglEnableClientState(GLcontext *context, GLenum array);
EXPORT void cwcglEnableClientStateIndexedEXT(GLcontext *context, GLenum array, GLuint index);
EXPORT void cwcglEnableClientStateiEXT(GLcontext *context, GLenum array, GLuint index);
EXPORT void cwcglEnableDriverControlQCOM(GLcontext *context, GLuint driverControl);
EXPORT void cwcglEnableIndexedEXT(GLcontext *context, GLenum target, GLuint index);
EXPORT void cwcglEnableVariantClientStateEXT(GLcontext *context, GLuint id);
EXPORT void cwcglEnableVertexArrayAttrib(GLcontext *context, GLuint vaobj, GLuint index);
EXPORT void cwcglEnableVertexArrayAttribEXT(GLcontext *context, GLuint vaobj, GLuint index);
EXPORT void cwcglEnableVertexArrayEXT(GLcontext *context, GLuint vaobj, GLenum array);
EXPORT void cwcglEnableVertexAttribAPPLE(GLcontext *context, GLuint index, GLenum pname);
EXPORT void cwcglEnableVertexAttribArray(GLcontext *context, GLuint index);
EXPORT void cwcglEnableVertexAttribArrayARB(GLcontext *context, GLuint index);
EXPORT void cwcglEnablei(GLcontext *context, GLenum target, GLuint index);
EXPORT void cwcglEnableiEXT(GLcontext *context, GLenum target, GLuint index);
EXPORT void cwcglEnableiNV(GLcontext *context, GLenum target, GLuint index);
EXPORT void cwcglEnableiOES(GLcontext *context, GLenum target, GLuint index);
EXPORT void cwcglEnd(GLcontext *context);
EXPORT void cwcglEndConditionalRender(GLcontext *context);
EXPORT void cwcglEndConditionalRenderNV(GLcontext *context);
EXPORT void cwcglEndConditionalRenderNVX(GLcontext *context);
EXPORT void cwcglEndFragmentShaderATI(GLcontext *context);
EXPORT void cwcglEndList(GLcontext *context);
EXPORT void cwcglEndOcclusionQueryNV(GLcontext *context);
EXPORT void cwcglEndPerfMonitorAMD(GLcontext *context, GLuint monitor);
EXPORT void cwcglEndPerfQueryINTEL(GLcontext *context, GLuint queryHandle);
EXPORT void cwcglEndQuery(GLcontext *context, GLenum target);
EXPORT void cwcglEndQueryARB(GLcontext *context, GLenum target);
EXPORT void cwcglEndQueryEXT(GLcontext *context, GLenum target);
EXPORT void cwcglEndQueryIndexed(GLcontext *context, GLenum target, GLuint index);
EXPORT void cwcglEndTilingQCOM(GLcontext *context, GLbitfield preserveMask);
EXPORT void cwcglEndTransformFeedback(GLcontext *context);
EXPORT void cwcglEndTransformFeedbackEXT(GLcontext *context);
EXPORT void cwcglEndTransformFeedbackNV(GLcontext *context);
EXPORT void cwcglEndVertexShaderEXT(GLcontext *context);
EXPORT void cwcglEndVideoCaptureNV(GLcontext *context, GLuint video_capture_slot);
EXPORT void cwcglEvalCoord1d(GLcontext *context, GLdouble u);
EXPORT void cwcglEvalCoord1dv(GLcontext *context, const GLdouble * u);
EXPORT void cwcglEvalCoord1f(GLcontext *context, GLfloat u);
EXPORT void cwcglEvalCoord1fv(GLcontext *context, const GLfloat * u);
EXPORT void cwcglEvalCoord1xOES(GLcontext *context, GLfixed u);
EXPORT void cwcglEvalCoord1xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglEvalCoord2d(GLcontext *context, GLdouble u, GLdouble v);
EXPORT void cwcglEvalCoord2dv(GLcontext *context, const GLdouble * u);
EXPORT void cwcglEvalCoord2f(GLcontext *context, GLfloat u, GLfloat v);
EXPORT void cwcglEvalCoord2fv(GLcontext *context, const GLfloat * u);
EXPORT void cwcglEvalCoord2xOES(GLcontext *context, GLfixed u, GLfixed v);
EXPORT void cwcglEvalCoord2xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglEvalMapsNV(GLcontext *context, GLenum target, GLenum mode);
EXPORT void cwcglEvalMesh1(GLcontext *context, GLenum mode, GLint i1, GLint i2);
EXPORT void cwcglEvalMesh2(GLcontext *context, GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
EXPORT void cwcglEvalPoint1(GLcontext *context, GLint i);
EXPORT void cwcglEvalPoint2(GLcontext *context, GLint i, GLint j);
EXPORT void cwcglEvaluateDepthValuesARB(GLcontext *context);
EXPORT void cwcglExecuteProgramNV(GLcontext *context, GLenum target, GLuint id, const GLfloat * params);
EXPORT void cwcglExtGetBufferPointervQCOM(GLcontext *context, GLenum target, void ** params);
EXPORT void cwcglExtGetBuffersQCOM(GLcontext *context, GLuint * buffers, GLint maxBuffers, GLint * numBuffers);
EXPORT void cwcglExtGetFramebuffersQCOM(GLcontext *context, GLuint * framebuffers, GLint maxFramebuffers, GLint * numFramebuffers);
EXPORT void cwcglExtGetProgramBinarySourceQCOM(GLcontext *context, GLuint program, GLenum shadertype, GLchar * source, GLint * length);
EXPORT void cwcglExtGetProgramsQCOM(GLcontext *context, GLuint * programs, GLint maxPrograms, GLint * numPrograms);
EXPORT void cwcglExtGetRenderbuffersQCOM(GLcontext *context, GLuint * renderbuffers, GLint maxRenderbuffers, GLint * numRenderbuffers);
EXPORT void cwcglExtGetShadersQCOM(GLcontext *context, GLuint * shaders, GLint maxShaders, GLint * numShaders);
EXPORT void cwcglExtGetTexLevelParameterivQCOM(GLcontext *context, GLuint texture, GLenum face, GLint level, GLenum pname, GLint * params);
EXPORT void cwcglExtGetTexSubImageQCOM(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, void * texels);
EXPORT void cwcglExtGetTexturesQCOM(GLcontext *context, GLuint * textures, GLint maxTextures, GLint * numTextures);
EXPORT void cwcglExtIsProgramBinaryQCOM(GLcontext *context, GLuint program, GLboolean* return_value);
EXPORT void cwcglExtTexObjectStateOverrideiQCOM(GLcontext *context, GLenum target, GLenum pname, GLint param);
EXPORT void cwcglExtractComponentEXT(GLcontext *context, GLuint res, GLuint src, GLuint num);
EXPORT void cwcglFeedbackBuffer(GLcontext *context, GLsizei size, GLenum type, GLfloat * buffer);
EXPORT void cwcglFeedbackBufferxOES(GLcontext *context, GLsizei n, GLenum type, const GLfixed * buffer);
EXPORT void cwcglFenceSync(GLcontext *context, GLenum condition, GLbitfield flags, GLsync* return_value);
EXPORT void cwcglFenceSyncAPPLE(GLcontext *context, GLenum condition, GLbitfield flags, GLsync* return_value);
EXPORT void cwcglFinalCombinerInputNV(GLcontext *context, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
EXPORT void cwcglFinish(GLcontext *context);
EXPORT void cwcglFinishAsyncSGIX(GLcontext *context, GLuint * markerp, GLint* return_value);
EXPORT void cwcglFinishFenceAPPLE(GLcontext *context, GLuint fence);
EXPORT void cwcglFinishFenceNV(GLcontext *context, GLuint fence);
EXPORT void cwcglFinishObjectAPPLE(GLcontext *context, GLenum object, GLint name);
EXPORT void cwcglFinishTextureSUNX(GLcontext *context);
EXPORT void cwcglFlush(GLcontext *context);
EXPORT void cwcglFlushMappedBufferRange(GLcontext *context, GLenum target, GLintptr offset, GLsizeiptr length);
EXPORT void cwcglFlushMappedBufferRangeAPPLE(GLcontext *context, GLenum target, GLintptr offset, GLsizeiptr size);
EXPORT void cwcglFlushMappedBufferRangeEXT(GLcontext *context, GLenum target, GLintptr offset, GLsizeiptr length);
EXPORT void cwcglFlushMappedNamedBufferRange(GLcontext *context, GLuint buffer, GLintptr offset, GLsizeiptr length);
EXPORT void cwcglFlushMappedNamedBufferRangeEXT(GLcontext *context, GLuint buffer, GLintptr offset, GLsizeiptr length);
EXPORT void cwcglFlushPixelDataRangeNV(GLcontext *context, GLenum target);
EXPORT void cwcglFlushRasterSGIX(GLcontext *context);
EXPORT void cwcglFlushStaticDataIBM(GLcontext *context, GLenum target);
EXPORT void cwcglFlushVertexArrayRangeAPPLE(GLcontext *context, GLsizei length, void * pointer);
EXPORT void cwcglFlushVertexArrayRangeNV(GLcontext *context);
EXPORT void cwcglFogCoordFormatNV(GLcontext *context, GLenum type, GLsizei stride);
EXPORT void cwcglFogCoordPointer(GLcontext *context, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglFogCoordPointerEXT(GLcontext *context, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglFogCoordPointerListIBM(GLcontext *context, GLenum type, GLint stride, const void ** pointer, GLint ptrstride);
EXPORT void cwcglFogCoordd(GLcontext *context, GLdouble coord);
EXPORT void cwcglFogCoorddEXT(GLcontext *context, GLdouble coord);
EXPORT void cwcglFogCoorddv(GLcontext *context, const GLdouble * coord);
EXPORT void cwcglFogCoorddvEXT(GLcontext *context, const GLdouble * coord);
EXPORT void cwcglFogCoordf(GLcontext *context, GLfloat coord);
EXPORT void cwcglFogCoordfEXT(GLcontext *context, GLfloat coord);
EXPORT void cwcglFogCoordfv(GLcontext *context, const GLfloat * coord);
EXPORT void cwcglFogCoordfvEXT(GLcontext *context, const GLfloat * coord);
EXPORT void cwcglFogCoordhNV(GLcontext *context, GLhalfNV fog);
EXPORT void cwcglFogCoordhvNV(GLcontext *context, const GLhalfNV * fog);
EXPORT void cwcglFogFuncSGIS(GLcontext *context, GLsizei n, const GLfloat * points);
EXPORT void cwcglFogf(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglFogfv(GLcontext *context, GLenum pname, const GLfloat * params);
EXPORT void cwcglFogi(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglFogiv(GLcontext *context, GLenum pname, const GLint * params);
EXPORT void cwcglFogx(GLcontext *context, GLenum pname, GLfixed param);
EXPORT void cwcglFogxOES(GLcontext *context, GLenum pname, GLfixed param);
EXPORT void cwcglFogxv(GLcontext *context, GLenum pname, const GLfixed * param);
EXPORT void cwcglFogxvOES(GLcontext *context, GLenum pname, const GLfixed * param);
EXPORT void cwcglFragmentColorMaterialSGIX(GLcontext *context, GLenum face, GLenum mode);
EXPORT void cwcglFragmentCoverageColorNV(GLcontext *context, GLuint color);
EXPORT void cwcglFragmentLightModelfSGIX(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglFragmentLightModelfvSGIX(GLcontext *context, GLenum pname, const GLfloat * params);
EXPORT void cwcglFragmentLightModeliSGIX(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglFragmentLightModelivSGIX(GLcontext *context, GLenum pname, const GLint * params);
EXPORT void cwcglFragmentLightfSGIX(GLcontext *context, GLenum light, GLenum pname, GLfloat param);
EXPORT void cwcglFragmentLightfvSGIX(GLcontext *context, GLenum light, GLenum pname, const GLfloat * params);
EXPORT void cwcglFragmentLightiSGIX(GLcontext *context, GLenum light, GLenum pname, GLint param);
EXPORT void cwcglFragmentLightivSGIX(GLcontext *context, GLenum light, GLenum pname, const GLint * params);
EXPORT void cwcglFragmentMaterialfSGIX(GLcontext *context, GLenum face, GLenum pname, GLfloat param);
EXPORT void cwcglFragmentMaterialfvSGIX(GLcontext *context, GLenum face, GLenum pname, const GLfloat * params);
EXPORT void cwcglFragmentMaterialiSGIX(GLcontext *context, GLenum face, GLenum pname, GLint param);
EXPORT void cwcglFragmentMaterialivSGIX(GLcontext *context, GLenum face, GLenum pname, const GLint * params);
EXPORT void cwcglFrameTerminatorGREMEDY(GLcontext *context);
EXPORT void cwcglFrameZoomSGIX(GLcontext *context, GLint factor);
EXPORT void cwcglFramebufferDrawBufferEXT(GLcontext *context, GLuint framebuffer, GLenum mode);
EXPORT void cwcglFramebufferDrawBuffersEXT(GLcontext *context, GLuint framebuffer, GLsizei n, const GLenum * bufs);
EXPORT void cwcglFramebufferParameteri(GLcontext *context, GLenum target, GLenum pname, GLint param);
EXPORT void cwcglFramebufferPixelLocalStorageSizeEXT(GLcontext *context, GLuint target, GLsizei size);
EXPORT void cwcglFramebufferReadBufferEXT(GLcontext *context, GLuint framebuffer, GLenum mode);
EXPORT void cwcglFramebufferRenderbuffer(GLcontext *context, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
EXPORT void cwcglFramebufferRenderbufferEXT(GLcontext *context, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
EXPORT void cwcglFramebufferRenderbufferOES(GLcontext *context, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
EXPORT void cwcglFramebufferSampleLocationsfvARB(GLcontext *context, GLenum target, GLuint start, GLsizei count, const GLfloat * v);
EXPORT void cwcglFramebufferSampleLocationsfvNV(GLcontext *context, GLenum target, GLuint start, GLsizei count, const GLfloat * v);
EXPORT void cwcglFramebufferSamplePositionsfvAMD(GLcontext *context, GLenum target, GLuint numsamples, GLuint pixelindex, const GLfloat * values);
EXPORT void cwcglFramebufferTexture(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level);
EXPORT void cwcglFramebufferTexture1D(GLcontext *context, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
EXPORT void cwcglFramebufferTexture1DEXT(GLcontext *context, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
EXPORT void cwcglFramebufferTexture2D(GLcontext *context, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
EXPORT void cwcglFramebufferTexture2DEXT(GLcontext *context, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
EXPORT void cwcglFramebufferTexture2DDownsampleIMG(GLcontext *context, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint xscale, GLint yscale);
EXPORT void cwcglFramebufferTexture2DMultisampleEXT(GLcontext *context, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsizei samples);
EXPORT void cwcglFramebufferTexture2DMultisampleIMG(GLcontext *context, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLsizei samples);
EXPORT void cwcglFramebufferTexture2DOES(GLcontext *context, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
EXPORT void cwcglFramebufferTexture3D(GLcontext *context, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
EXPORT void cwcglFramebufferTexture3DEXT(GLcontext *context, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
EXPORT void cwcglFramebufferTexture3DOES(GLcontext *context, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
EXPORT void cwcglFramebufferTextureARB(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level);
EXPORT void cwcglFramebufferTextureEXT(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level);
EXPORT void cwcglFramebufferTextureFaceARB(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
EXPORT void cwcglFramebufferTextureFaceEXT(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
EXPORT void cwcglFramebufferTextureLayer(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
EXPORT void cwcglFramebufferTextureLayerARB(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
EXPORT void cwcglFramebufferTextureLayerEXT(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
EXPORT void cwcglFramebufferTextureLayerDownsampleIMG(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer, GLint xscale, GLint yscale);
EXPORT void cwcglFramebufferTextureMultisampleMultiviewOVR(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level, GLsizei samples, GLint baseViewIndex, GLsizei numViews);
EXPORT void cwcglFramebufferTextureMultiviewOVR(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
EXPORT void cwcglFramebufferTextureOES(GLcontext *context, GLenum target, GLenum attachment, GLuint texture, GLint level);
EXPORT void cwcglFreeObjectBufferATI(GLcontext *context, GLuint buffer);
EXPORT void cwcglFrontFace(GLcontext *context, GLenum mode);
EXPORT void cwcglFrustum(GLcontext *context, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
EXPORT void cwcglFrustumf(GLcontext *context, GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
EXPORT void cwcglFrustumfOES(GLcontext *context, GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
EXPORT void cwcglFrustumx(GLcontext *context, GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
EXPORT void cwcglFrustumxOES(GLcontext *context, GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
EXPORT void cwcglGenAsyncMarkersSGIX(GLcontext *context, GLsizei range, GLuint* return_value);
EXPORT void cwcglGenBuffers(GLcontext *context, GLsizei n, GLuint * buffers);
EXPORT void cwcglGenBuffersARB(GLcontext *context, GLsizei n, GLuint * buffers);
EXPORT void cwcglGenFencesAPPLE(GLcontext *context, GLsizei n, GLuint * fences);
EXPORT void cwcglGenFencesNV(GLcontext *context, GLsizei n, GLuint * fences);
EXPORT void cwcglGenFragmentShadersATI(GLcontext *context, GLuint range, GLuint* return_value);
EXPORT void cwcglGenFramebuffers(GLcontext *context, GLsizei n, GLuint * framebuffers);
EXPORT void cwcglGenFramebuffersEXT(GLcontext *context, GLsizei n, GLuint * framebuffers);
EXPORT void cwcglGenFramebuffersOES(GLcontext *context, GLsizei n, GLuint * framebuffers);
EXPORT void cwcglGenLists(GLcontext *context, GLsizei range, GLuint* return_value);
EXPORT void cwcglGenNamesAMD(GLcontext *context, GLenum identifier, GLuint num, GLuint * names);
EXPORT void cwcglGenOcclusionQueriesNV(GLcontext *context, GLsizei n, GLuint * ids);
EXPORT void cwcglGenPathsNV(GLcontext *context, GLsizei range, GLuint* return_value);
EXPORT void cwcglGenPerfMonitorsAMD(GLcontext *context, GLsizei n, GLuint * monitors);
EXPORT void cwcglGenProgramPipelines(GLcontext *context, GLsizei n, GLuint * pipelines);
EXPORT void cwcglGenProgramPipelinesEXT(GLcontext *context, GLsizei n, GLuint * pipelines);
EXPORT void cwcglGenProgramsARB(GLcontext *context, GLsizei n, GLuint * programs);
EXPORT void cwcglGenProgramsNV(GLcontext *context, GLsizei n, GLuint * programs);
EXPORT void cwcglGenQueries(GLcontext *context, GLsizei n, GLuint * ids);
EXPORT void cwcglGenQueriesARB(GLcontext *context, GLsizei n, GLuint * ids);
EXPORT void cwcglGenQueriesEXT(GLcontext *context, GLsizei n, GLuint * ids);
EXPORT void cwcglGenRenderbuffers(GLcontext *context, GLsizei n, GLuint * renderbuffers);
EXPORT void cwcglGenRenderbuffersEXT(GLcontext *context, GLsizei n, GLuint * renderbuffers);
EXPORT void cwcglGenRenderbuffersOES(GLcontext *context, GLsizei n, GLuint * renderbuffers);
EXPORT void cwcglGenSamplers(GLcontext *context, GLsizei count, GLuint * samplers);
EXPORT void cwcglGenSymbolsEXT(GLcontext *context, GLenum datatype, GLenum storagetype, GLenum range, GLuint components, GLuint* return_value);
EXPORT void cwcglGenTextures(GLcontext *context, GLsizei n, GLuint * textures);
EXPORT void cwcglGenTexturesEXT(GLcontext *context, GLsizei n, GLuint * textures);
EXPORT void cwcglGenTransformFeedbacks(GLcontext *context, GLsizei n, GLuint * ids);
EXPORT void cwcglGenTransformFeedbacksNV(GLcontext *context, GLsizei n, GLuint * ids);
EXPORT void cwcglGenVertexArrays(GLcontext *context, GLsizei n, GLuint * arrays);
EXPORT void cwcglGenVertexArraysAPPLE(GLcontext *context, GLsizei n, GLuint * arrays);
EXPORT void cwcglGenVertexArraysOES(GLcontext *context, GLsizei n, GLuint * arrays);
EXPORT void cwcglGenVertexShadersEXT(GLcontext *context, GLuint range, GLuint* return_value);
EXPORT void cwcglGenerateMipmap(GLcontext *context, GLenum target);
EXPORT void cwcglGenerateMipmapEXT(GLcontext *context, GLenum target);
EXPORT void cwcglGenerateMipmapOES(GLcontext *context, GLenum target);
EXPORT void cwcglGenerateMultiTexMipmapEXT(GLcontext *context, GLenum texunit, GLenum target);
EXPORT void cwcglGenerateTextureMipmap(GLcontext *context, GLuint texture);
EXPORT void cwcglGenerateTextureMipmapEXT(GLcontext *context, GLuint texture, GLenum target);
EXPORT void cwcglGetActiveAtomicCounterBufferiv(GLcontext *context, GLuint program, GLuint bufferIndex, GLenum pname, GLint * params);
EXPORT void cwcglGetActiveAttrib(GLcontext *context, GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
EXPORT void cwcglGetActiveAttribARB(GLcontext *context, GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name);
EXPORT void cwcglGetActiveSubroutineName(GLcontext *context, GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
EXPORT void cwcglGetActiveSubroutineUniformName(GLcontext *context, GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
EXPORT void cwcglGetActiveSubroutineUniformiv(GLcontext *context, GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values);
EXPORT void cwcglGetActiveUniform(GLcontext *context, GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
EXPORT void cwcglGetActiveUniformARB(GLcontext *context, GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name);
EXPORT void cwcglGetActiveUniformBlockName(GLcontext *context, GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
EXPORT void cwcglGetActiveUniformBlockiv(GLcontext *context, GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
EXPORT void cwcglGetActiveUniformName(GLcontext *context, GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
EXPORT void cwcglGetActiveUniformsiv(GLcontext *context, GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
EXPORT void cwcglGetActiveVaryingNV(GLcontext *context, GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
EXPORT void cwcglGetArrayObjectfvATI(GLcontext *context, GLenum array, GLenum pname, GLfloat * params);
EXPORT void cwcglGetArrayObjectivATI(GLcontext *context, GLenum array, GLenum pname, GLint * params);
EXPORT void cwcglGetAttachedObjectsARB(GLcontext *context, GLhandleARB containerObj, GLsizei maxCount, GLsizei * count, GLhandleARB * obj);
EXPORT void cwcglGetAttachedShaders(GLcontext *context, GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
EXPORT void cwcglGetAttribLocation(GLcontext *context, GLuint program, const GLchar * name, GLint* return_value);
EXPORT void cwcglGetAttribLocationARB(GLcontext *context, GLhandleARB programObj, const GLcharARB * name, GLint* return_value);
EXPORT void cwcglGetBooleanIndexedvEXT(GLcontext *context, GLenum target, GLuint index, GLboolean * data);
EXPORT void cwcglGetBooleani_v(GLcontext *context, GLenum target, GLuint index, GLboolean * data);
EXPORT void cwcglGetBooleanv(GLcontext *context, GLenum pname, GLboolean * data);
EXPORT void cwcglGetBufferParameteri64v(GLcontext *context, GLenum target, GLenum pname, GLint64 * params);
EXPORT void cwcglGetBufferParameteriv(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetBufferParameterivARB(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetBufferParameterui64vNV(GLcontext *context, GLenum target, GLenum pname, GLuint64EXT * params);
EXPORT void cwcglGetBufferPointerv(GLcontext *context, GLenum target, GLenum pname, void ** params);
EXPORT void cwcglGetBufferPointervARB(GLcontext *context, GLenum target, GLenum pname, void ** params);
EXPORT void cwcglGetBufferPointervOES(GLcontext *context, GLenum target, GLenum pname, void ** params);
EXPORT void cwcglGetBufferSubData(GLcontext *context, GLenum target, GLintptr offset, GLsizeiptr size, void * data);
EXPORT void cwcglGetBufferSubDataARB(GLcontext *context, GLenum target, GLintptrARB offset, GLsizeiptrARB size, void * data);
EXPORT void cwcglGetClipPlane(GLcontext *context, GLenum plane, GLdouble * equation);
EXPORT void cwcglGetClipPlanef(GLcontext *context, GLenum plane, GLfloat * equation);
EXPORT void cwcglGetClipPlanefOES(GLcontext *context, GLenum plane, GLfloat * equation);
EXPORT void cwcglGetClipPlanex(GLcontext *context, GLenum plane, GLfixed * equation);
EXPORT void cwcglGetClipPlanexOES(GLcontext *context, GLenum plane, GLfixed * equation);
EXPORT void cwcglGetColorTable(GLcontext *context, GLenum target, GLenum format, GLenum type, void * table);
EXPORT void cwcglGetColorTableEXT(GLcontext *context, GLenum target, GLenum format, GLenum type, void * data);
EXPORT void cwcglGetColorTableParameterfv(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetColorTableParameterfvEXT(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetColorTableParameterfvSGI(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetColorTableParameteriv(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetColorTableParameterivEXT(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetColorTableParameterivSGI(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetColorTableSGI(GLcontext *context, GLenum target, GLenum format, GLenum type, void * table);
EXPORT void cwcglGetCombinerInputParameterfvNV(GLcontext *context, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat * params);
EXPORT void cwcglGetCombinerInputParameterivNV(GLcontext *context, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint * params);
EXPORT void cwcglGetCombinerOutputParameterfvNV(GLcontext *context, GLenum stage, GLenum portion, GLenum pname, GLfloat * params);
EXPORT void cwcglGetCombinerOutputParameterivNV(GLcontext *context, GLenum stage, GLenum portion, GLenum pname, GLint * params);
EXPORT void cwcglGetCombinerStageParameterfvNV(GLcontext *context, GLenum stage, GLenum pname, GLfloat * params);
EXPORT void cwcglGetCommandHeaderNV(GLcontext *context, GLenum tokenID, GLuint size, GLuint* return_value);
EXPORT void cwcglGetCompressedMultiTexImageEXT(GLcontext *context, GLenum texunit, GLenum target, GLint lod, void * img);
EXPORT void cwcglGetCompressedTexImage(GLcontext *context, GLenum target, GLint level, void * img);
EXPORT void cwcglGetCompressedTexImageARB(GLcontext *context, GLenum target, GLint level, void * img);
EXPORT void cwcglGetCompressedTextureImage(GLcontext *context, GLuint texture, GLint level, GLsizei bufSize, void * pixels);
EXPORT void cwcglGetCompressedTextureImageEXT(GLcontext *context, GLuint texture, GLenum target, GLint lod, void * img);
EXPORT void cwcglGetCompressedTextureSubImage(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels);
EXPORT void cwcglGetConvolutionFilter(GLcontext *context, GLenum target, GLenum format, GLenum type, void * image);
EXPORT void cwcglGetConvolutionFilterEXT(GLcontext *context, GLenum target, GLenum format, GLenum type, void * image);
EXPORT void cwcglGetConvolutionParameterfv(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetConvolutionParameterfvEXT(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetConvolutionParameteriv(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetConvolutionParameterivEXT(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetConvolutionParameterxvOES(GLcontext *context, GLenum target, GLenum pname, GLfixed * params);
EXPORT void cwcglGetCoverageModulationTableNV(GLcontext *context, GLsizei bufsize, GLfloat * v);
EXPORT void cwcglGetDebugMessageLog(GLcontext *context, GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog, GLuint* return_value);
EXPORT void cwcglGetDebugMessageLogAMD(GLcontext *context, GLuint count, GLsizei bufsize, GLenum * categories, GLuint * severities, GLuint * ids, GLsizei * lengths, GLchar * message, GLuint* return_value);
EXPORT void cwcglGetDebugMessageLogARB(GLcontext *context, GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog, GLuint* return_value);
EXPORT void cwcglGetDebugMessageLogKHR(GLcontext *context, GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog, GLuint* return_value);
EXPORT void cwcglGetDetailTexFuncSGIS(GLcontext *context, GLenum target, GLfloat * points);
EXPORT void cwcglGetDoubleIndexedvEXT(GLcontext *context, GLenum target, GLuint index, GLdouble * data);
EXPORT void cwcglGetDoublei_v(GLcontext *context, GLenum target, GLuint index, GLdouble * data);
EXPORT void cwcglGetDoublei_vEXT(GLcontext *context, GLenum pname, GLuint index, GLdouble * params);
EXPORT void cwcglGetDoublev(GLcontext *context, GLenum pname, GLdouble * data);
EXPORT void cwcglGetDriverControlStringQCOM(GLcontext *context, GLuint driverControl, GLsizei bufSize, GLsizei * length, GLchar * driverControlString);
EXPORT void cwcglGetDriverControlsQCOM(GLcontext *context, GLint * num, GLsizei size, GLuint * driverControls);
EXPORT void cwcglGetError(GLcontext *context, GLenum* return_value);
EXPORT void cwcglGetFenceivNV(GLcontext *context, GLuint fence, GLenum pname, GLint * params);
EXPORT void cwcglGetFinalCombinerInputParameterfvNV(GLcontext *context, GLenum variable, GLenum pname, GLfloat * params);
EXPORT void cwcglGetFinalCombinerInputParameterivNV(GLcontext *context, GLenum variable, GLenum pname, GLint * params);
EXPORT void cwcglGetFirstPerfQueryIdINTEL(GLcontext *context, GLuint * queryId);
EXPORT void cwcglGetFixedv(GLcontext *context, GLenum pname, GLfixed * params);
EXPORT void cwcglGetFixedvOES(GLcontext *context, GLenum pname, GLfixed * params);
EXPORT void cwcglGetFloatIndexedvEXT(GLcontext *context, GLenum target, GLuint index, GLfloat * data);
EXPORT void cwcglGetFloati_v(GLcontext *context, GLenum target, GLuint index, GLfloat * data);
EXPORT void cwcglGetFloati_vEXT(GLcontext *context, GLenum pname, GLuint index, GLfloat * params);
EXPORT void cwcglGetFloati_vNV(GLcontext *context, GLenum target, GLuint index, GLfloat * data);
EXPORT void cwcglGetFloati_vOES(GLcontext *context, GLenum target, GLuint index, GLfloat * data);
EXPORT void cwcglGetFloatv(GLcontext *context, GLenum pname, GLfloat * data);
EXPORT void cwcglGetFogFuncSGIS(GLcontext *context, GLfloat * points);
EXPORT void cwcglGetFragDataIndex(GLcontext *context, GLuint program, const GLchar * name, GLint* return_value);
EXPORT void cwcglGetFragDataIndexEXT(GLcontext *context, GLuint program, const GLchar * name, GLint* return_value);
EXPORT void cwcglGetFragDataLocation(GLcontext *context, GLuint program, const GLchar * name, GLint* return_value);
EXPORT void cwcglGetFragDataLocationEXT(GLcontext *context, GLuint program, const GLchar * name, GLint* return_value);
EXPORT void cwcglGetFragmentLightfvSGIX(GLcontext *context, GLenum light, GLenum pname, GLfloat * params);
EXPORT void cwcglGetFragmentLightivSGIX(GLcontext *context, GLenum light, GLenum pname, GLint * params);
EXPORT void cwcglGetFragmentMaterialfvSGIX(GLcontext *context, GLenum face, GLenum pname, GLfloat * params);
EXPORT void cwcglGetFragmentMaterialivSGIX(GLcontext *context, GLenum face, GLenum pname, GLint * params);
EXPORT void cwcglGetFramebufferAttachmentParameteriv(GLcontext *context, GLenum target, GLenum attachment, GLenum pname, GLint * params);
EXPORT void cwcglGetFramebufferAttachmentParameterivEXT(GLcontext *context, GLenum target, GLenum attachment, GLenum pname, GLint * params);
EXPORT void cwcglGetFramebufferAttachmentParameterivOES(GLcontext *context, GLenum target, GLenum attachment, GLenum pname, GLint * params);
EXPORT void cwcglGetFramebufferParameterfvAMD(GLcontext *context, GLenum target, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat * values);
EXPORT void cwcglGetFramebufferParameteriv(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetFramebufferParameterivEXT(GLcontext *context, GLuint framebuffer, GLenum pname, GLint * params);
EXPORT void cwcglGetFramebufferPixelLocalStorageSizeEXT(GLcontext *context, GLuint target, GLsizei* return_value);
EXPORT void cwcglGetGraphicsResetStatus(GLcontext *context, GLenum* return_value);
EXPORT void cwcglGetGraphicsResetStatusARB(GLcontext *context, GLenum* return_value);
EXPORT void cwcglGetGraphicsResetStatusEXT(GLcontext *context, GLenum* return_value);
EXPORT void cwcglGetGraphicsResetStatusKHR(GLcontext *context, GLenum* return_value);
EXPORT void cwcglGetHandleARB(GLcontext *context, GLenum pname, GLhandleARB* return_value);
EXPORT void cwcglGetHistogram(GLcontext *context, GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
EXPORT void cwcglGetHistogramEXT(GLcontext *context, GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
EXPORT void cwcglGetHistogramParameterfv(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetHistogramParameterfvEXT(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetHistogramParameteriv(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetHistogramParameterivEXT(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetHistogramParameterxvOES(GLcontext *context, GLenum target, GLenum pname, GLfixed * params);
EXPORT void cwcglGetImageHandleARB(GLcontext *context, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format, GLuint64* return_value);
EXPORT void cwcglGetImageHandleNV(GLcontext *context, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format, GLuint64* return_value);
EXPORT void cwcglGetImageTransformParameterfvHP(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetImageTransformParameterivHP(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetInfoLogARB(GLcontext *context, GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * infoLog);
EXPORT void cwcglGetInstrumentsSGIX(GLcontext *context, GLint* return_value);
EXPORT void cwcglGetInteger64i_v(GLcontext *context, GLenum target, GLuint index, GLint64 * data);
EXPORT void cwcglGetInteger64v(GLcontext *context, GLenum pname, GLint64 * data);
EXPORT void cwcglGetInteger64vAPPLE(GLcontext *context, GLenum pname, GLint64 * params);
EXPORT void cwcglGetIntegerIndexedvEXT(GLcontext *context, GLenum target, GLuint index, GLint * data);
EXPORT void cwcglGetIntegeri_v(GLcontext *context, GLenum target, GLuint index, GLint * data);
EXPORT void cwcglGetIntegeri_vEXT(GLcontext *context, GLenum target, GLuint index, GLint * data);
EXPORT void cwcglGetIntegerui64i_vNV(GLcontext *context, GLenum value, GLuint index, GLuint64EXT * result);
EXPORT void cwcglGetIntegerui64vNV(GLcontext *context, GLenum value, GLuint64EXT * result);
EXPORT void cwcglGetIntegerv(GLcontext *context, GLenum pname, GLint * data);
EXPORT void cwcglGetInternalformatSampleivNV(GLcontext *context, GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei bufSize, GLint * params);
EXPORT void cwcglGetInternalformati64v(GLcontext *context, GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 * params);
EXPORT void cwcglGetInternalformativ(GLcontext *context, GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint * params);
EXPORT void cwcglGetInvariantBooleanvEXT(GLcontext *context, GLuint id, GLenum value, GLboolean * data);
EXPORT void cwcglGetInvariantFloatvEXT(GLcontext *context, GLuint id, GLenum value, GLfloat * data);
EXPORT void cwcglGetInvariantIntegervEXT(GLcontext *context, GLuint id, GLenum value, GLint * data);
EXPORT void cwcglGetLightfv(GLcontext *context, GLenum light, GLenum pname, GLfloat * params);
EXPORT void cwcglGetLightiv(GLcontext *context, GLenum light, GLenum pname, GLint * params);
EXPORT void cwcglGetLightxOES(GLcontext *context, GLenum light, GLenum pname, GLfixed * params);
EXPORT void cwcglGetLightxv(GLcontext *context, GLenum light, GLenum pname, GLfixed * params);
EXPORT void cwcglGetLightxvOES(GLcontext *context, GLenum light, GLenum pname, GLfixed * params);
EXPORT void cwcglGetListParameterfvSGIX(GLcontext *context, GLuint list, GLenum pname, GLfloat * params);
EXPORT void cwcglGetListParameterivSGIX(GLcontext *context, GLuint list, GLenum pname, GLint * params);
EXPORT void cwcglGetLocalConstantBooleanvEXT(GLcontext *context, GLuint id, GLenum value, GLboolean * data);
EXPORT void cwcglGetLocalConstantFloatvEXT(GLcontext *context, GLuint id, GLenum value, GLfloat * data);
EXPORT void cwcglGetLocalConstantIntegervEXT(GLcontext *context, GLuint id, GLenum value, GLint * data);
EXPORT void cwcglGetMapAttribParameterfvNV(GLcontext *context, GLenum target, GLuint index, GLenum pname, GLfloat * params);
EXPORT void cwcglGetMapAttribParameterivNV(GLcontext *context, GLenum target, GLuint index, GLenum pname, GLint * params);
EXPORT void cwcglGetMapControlPointsNV(GLcontext *context, GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, void * points);
EXPORT void cwcglGetMapParameterfvNV(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetMapParameterivNV(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetMapdv(GLcontext *context, GLenum target, GLenum query, GLdouble * v);
EXPORT void cwcglGetMapfv(GLcontext *context, GLenum target, GLenum query, GLfloat * v);
EXPORT void cwcglGetMapiv(GLcontext *context, GLenum target, GLenum query, GLint * v);
EXPORT void cwcglGetMapxvOES(GLcontext *context, GLenum target, GLenum query, GLfixed * v);
EXPORT void cwcglGetMaterialfv(GLcontext *context, GLenum face, GLenum pname, GLfloat * params);
EXPORT void cwcglGetMaterialiv(GLcontext *context, GLenum face, GLenum pname, GLint * params);
EXPORT void cwcglGetMaterialxOES(GLcontext *context, GLenum face, GLenum pname, GLfixed param);
EXPORT void cwcglGetMaterialxv(GLcontext *context, GLenum face, GLenum pname, GLfixed * params);
EXPORT void cwcglGetMaterialxvOES(GLcontext *context, GLenum face, GLenum pname, GLfixed * params);
EXPORT void cwcglGetMinmax(GLcontext *context, GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
EXPORT void cwcglGetMinmaxEXT(GLcontext *context, GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
EXPORT void cwcglGetMinmaxParameterfv(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetMinmaxParameterfvEXT(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetMinmaxParameteriv(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetMinmaxParameterivEXT(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetMultiTexEnvfvEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetMultiTexEnvivEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetMultiTexGendvEXT(GLcontext *context, GLenum texunit, GLenum coord, GLenum pname, GLdouble * params);
EXPORT void cwcglGetMultiTexGenfvEXT(GLcontext *context, GLenum texunit, GLenum coord, GLenum pname, GLfloat * params);
EXPORT void cwcglGetMultiTexGenivEXT(GLcontext *context, GLenum texunit, GLenum coord, GLenum pname, GLint * params);
EXPORT void cwcglGetMultiTexImageEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
EXPORT void cwcglGetMultiTexLevelParameterfvEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat * params);
EXPORT void cwcglGetMultiTexLevelParameterivEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLenum pname, GLint * params);
EXPORT void cwcglGetMultiTexParameterIivEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetMultiTexParameterIuivEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, GLuint * params);
EXPORT void cwcglGetMultiTexParameterfvEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetMultiTexParameterivEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetMultisamplefv(GLcontext *context, GLenum pname, GLuint index, GLfloat * val);
EXPORT void cwcglGetMultisamplefvNV(GLcontext *context, GLenum pname, GLuint index, GLfloat * val);
EXPORT void cwcglGetNamedBufferParameteri64v(GLcontext *context, GLuint buffer, GLenum pname, GLint64 * params);
EXPORT void cwcglGetNamedBufferParameteriv(GLcontext *context, GLuint buffer, GLenum pname, GLint * params);
EXPORT void cwcglGetNamedBufferParameterivEXT(GLcontext *context, GLuint buffer, GLenum pname, GLint * params);
EXPORT void cwcglGetNamedBufferParameterui64vNV(GLcontext *context, GLuint buffer, GLenum pname, GLuint64EXT * params);
EXPORT void cwcglGetNamedBufferPointerv(GLcontext *context, GLuint buffer, GLenum pname, void ** params);
EXPORT void cwcglGetNamedBufferPointervEXT(GLcontext *context, GLuint buffer, GLenum pname, void ** params);
EXPORT void cwcglGetNamedBufferSubData(GLcontext *context, GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
EXPORT void cwcglGetNamedBufferSubDataEXT(GLcontext *context, GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
EXPORT void cwcglGetNamedFramebufferParameterfvAMD(GLcontext *context, GLenum framebuffer, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat * values);
EXPORT void cwcglGetNamedFramebufferAttachmentParameteriv(GLcontext *context, GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
EXPORT void cwcglGetNamedFramebufferAttachmentParameterivEXT(GLcontext *context, GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
EXPORT void cwcglGetNamedFramebufferParameteriv(GLcontext *context, GLuint framebuffer, GLenum pname, GLint * param);
EXPORT void cwcglGetNamedFramebufferParameterivEXT(GLcontext *context, GLuint framebuffer, GLenum pname, GLint * params);
EXPORT void cwcglGetNamedProgramLocalParameterIivEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, GLint * params);
EXPORT void cwcglGetNamedProgramLocalParameterIuivEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, GLuint * params);
EXPORT void cwcglGetNamedProgramLocalParameterdvEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, GLdouble * params);
EXPORT void cwcglGetNamedProgramLocalParameterfvEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, GLfloat * params);
EXPORT void cwcglGetNamedProgramStringEXT(GLcontext *context, GLuint program, GLenum target, GLenum pname, void * string);
EXPORT void cwcglGetNamedProgramivEXT(GLcontext *context, GLuint program, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetNamedRenderbufferParameteriv(GLcontext *context, GLuint renderbuffer, GLenum pname, GLint * params);
EXPORT void cwcglGetNamedRenderbufferParameterivEXT(GLcontext *context, GLuint renderbuffer, GLenum pname, GLint * params);
EXPORT void cwcglGetNamedStringARB(GLcontext *context, GLint namelen, const GLchar * name, GLsizei bufSize, GLint * stringlen, GLchar * string);
EXPORT void cwcglGetNamedStringivARB(GLcontext *context, GLint namelen, const GLchar * name, GLenum pname, GLint * params);
EXPORT void cwcglGetNextPerfQueryIdINTEL(GLcontext *context, GLuint queryId, GLuint * nextQueryId);
EXPORT void cwcglGetObjectBufferfvATI(GLcontext *context, GLuint buffer, GLenum pname, GLfloat * params);
EXPORT void cwcglGetObjectBufferivATI(GLcontext *context, GLuint buffer, GLenum pname, GLint * params);
EXPORT void cwcglGetObjectLabel(GLcontext *context, GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label);
EXPORT void cwcglGetObjectLabelEXT(GLcontext *context, GLenum type, GLuint object, GLsizei bufSize, GLsizei * length, GLchar * label);
EXPORT void cwcglGetObjectLabelKHR(GLcontext *context, GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label);
EXPORT void cwcglGetObjectParameterfvARB(GLcontext *context, GLhandleARB obj, GLenum pname, GLfloat * params);
EXPORT void cwcglGetObjectParameterivAPPLE(GLcontext *context, GLenum objectType, GLuint name, GLenum pname, GLint * params);
EXPORT void cwcglGetObjectParameterivARB(GLcontext *context, GLhandleARB obj, GLenum pname, GLint * params);
EXPORT void cwcglGetObjectPtrLabel(GLcontext *context, const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label);
EXPORT void cwcglGetObjectPtrLabelKHR(GLcontext *context, const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label);
EXPORT void cwcglGetOcclusionQueryivNV(GLcontext *context, GLuint id, GLenum pname, GLint * params);
EXPORT void cwcglGetOcclusionQueryuivNV(GLcontext *context, GLuint id, GLenum pname, GLuint * params);
EXPORT void cwcglGetPathColorGenfvNV(GLcontext *context, GLenum color, GLenum pname, GLfloat * value);
EXPORT void cwcglGetPathColorGenivNV(GLcontext *context, GLenum color, GLenum pname, GLint * value);
EXPORT void cwcglGetPathCommandsNV(GLcontext *context, GLuint path, GLubyte * commands);
EXPORT void cwcglGetPathCoordsNV(GLcontext *context, GLuint path, GLfloat * coords);
EXPORT void cwcglGetPathDashArrayNV(GLcontext *context, GLuint path, GLfloat * dashArray);
EXPORT void cwcglGetPathLengthNV(GLcontext *context, GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat* return_value);
EXPORT void cwcglGetPathMetricRangeNV(GLcontext *context, GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat * metrics);
EXPORT void cwcglGetPathMetricsNV(GLcontext *context, GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLsizei stride, GLfloat * metrics);
EXPORT void cwcglGetPathParameterfvNV(GLcontext *context, GLuint path, GLenum pname, GLfloat * value);
EXPORT void cwcglGetPathParameterivNV(GLcontext *context, GLuint path, GLenum pname, GLint * value);
EXPORT void cwcglGetPathSpacingNV(GLcontext *context, GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat * returnedSpacing);
EXPORT void cwcglGetPathTexGenfvNV(GLcontext *context, GLenum texCoordSet, GLenum pname, GLfloat * value);
EXPORT void cwcglGetPathTexGenivNV(GLcontext *context, GLenum texCoordSet, GLenum pname, GLint * value);
EXPORT void cwcglGetPerfCounterInfoINTEL(GLcontext *context, GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar * counterName, GLuint counterDescLength, GLchar * counterDesc, GLuint * counterOffset, GLuint * counterDataSize, GLuint * counterTypeEnum, GLuint * counterDataTypeEnum, GLuint64 * rawCounterMaxValue);
EXPORT void cwcglGetPerfMonitorCounterDataAMD(GLcontext *context, GLuint monitor, GLenum pname, GLsizei dataSize, GLuint * data, GLint * bytesWritten);
EXPORT void cwcglGetPerfMonitorCounterInfoAMD(GLcontext *context, GLuint group, GLuint counter, GLenum pname, void * data);
EXPORT void cwcglGetPerfMonitorCounterStringAMD(GLcontext *context, GLuint group, GLuint counter, GLsizei bufSize, GLsizei * length, GLchar * counterString);
EXPORT void cwcglGetPerfMonitorCountersAMD(GLcontext *context, GLuint group, GLint * numCounters, GLint * maxActiveCounters, GLsizei counterSize, GLuint * counters);
EXPORT void cwcglGetPerfMonitorGroupStringAMD(GLcontext *context, GLuint group, GLsizei bufSize, GLsizei * length, GLchar * groupString);
EXPORT void cwcglGetPerfMonitorGroupsAMD(GLcontext *context, GLint * numGroups, GLsizei groupsSize, GLuint * groups);
EXPORT void cwcglGetPerfQueryDataINTEL(GLcontext *context, GLuint queryHandle, GLuint flags, GLsizei dataSize, GLvoid * data, GLuint * bytesWritten);
EXPORT void cwcglGetPerfQueryIdByNameINTEL(GLcontext *context, GLchar * queryName, GLuint * queryId);
EXPORT void cwcglGetPerfQueryInfoINTEL(GLcontext *context, GLuint queryId, GLuint queryNameLength, GLchar * queryName, GLuint * dataSize, GLuint * noCounters, GLuint * noInstances, GLuint * capsMask);
EXPORT void cwcglGetPixelMapfv(GLcontext *context, GLenum map, GLfloat * values);
EXPORT void cwcglGetPixelMapuiv(GLcontext *context, GLenum map, GLuint * values);
EXPORT void cwcglGetPixelMapusv(GLcontext *context, GLenum map, GLushort * values);
EXPORT void cwcglGetPixelMapxv(GLcontext *context, GLenum map, GLint size, GLfixed * values);
EXPORT void cwcglGetPixelTexGenParameterfvSGIS(GLcontext *context, GLenum pname, GLfloat * params);
EXPORT void cwcglGetPixelTexGenParameterivSGIS(GLcontext *context, GLenum pname, GLint * params);
EXPORT void cwcglGetPixelTransformParameterfvEXT(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetPixelTransformParameterivEXT(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetPointerIndexedvEXT(GLcontext *context, GLenum target, GLuint index, void ** data);
EXPORT void cwcglGetPointeri_vEXT(GLcontext *context, GLenum pname, GLuint index, void ** params);
EXPORT void cwcglGetPointerv(GLcontext *context, GLenum pname, void ** params);
EXPORT void cwcglGetPointervEXT(GLcontext *context, GLenum pname, void ** params);
EXPORT void cwcglGetPointervKHR(GLcontext *context, GLenum pname, void ** params);
EXPORT void cwcglGetPolygonStipple(GLcontext *context, GLubyte * mask);
EXPORT void cwcglGetProgramBinary(GLcontext *context, GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
EXPORT void cwcglGetProgramBinaryOES(GLcontext *context, GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
EXPORT void cwcglGetProgramEnvParameterIivNV(GLcontext *context, GLenum target, GLuint index, GLint * params);
EXPORT void cwcglGetProgramEnvParameterIuivNV(GLcontext *context, GLenum target, GLuint index, GLuint * params);
EXPORT void cwcglGetProgramEnvParameterdvARB(GLcontext *context, GLenum target, GLuint index, GLdouble * params);
EXPORT void cwcglGetProgramEnvParameterfvARB(GLcontext *context, GLenum target, GLuint index, GLfloat * params);
EXPORT void cwcglGetProgramInfoLog(GLcontext *context, GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
EXPORT void cwcglGetProgramInterfaceiv(GLcontext *context, GLuint program, GLenum programInterface, GLenum pname, GLint * params);
EXPORT void cwcglGetProgramLocalParameterIivNV(GLcontext *context, GLenum target, GLuint index, GLint * params);
EXPORT void cwcglGetProgramLocalParameterIuivNV(GLcontext *context, GLenum target, GLuint index, GLuint * params);
EXPORT void cwcglGetProgramLocalParameterdvARB(GLcontext *context, GLenum target, GLuint index, GLdouble * params);
EXPORT void cwcglGetProgramLocalParameterfvARB(GLcontext *context, GLenum target, GLuint index, GLfloat * params);
EXPORT void cwcglGetProgramNamedParameterdvNV(GLcontext *context, GLuint id, GLsizei len, const GLubyte * name, GLdouble * params);
EXPORT void cwcglGetProgramNamedParameterfvNV(GLcontext *context, GLuint id, GLsizei len, const GLubyte * name, GLfloat * params);
EXPORT void cwcglGetProgramParameterdvNV(GLcontext *context, GLenum target, GLuint index, GLenum pname, GLdouble * params);
EXPORT void cwcglGetProgramParameterfvNV(GLcontext *context, GLenum target, GLuint index, GLenum pname, GLfloat * params);
EXPORT void cwcglGetProgramPipelineInfoLog(GLcontext *context, GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
EXPORT void cwcglGetProgramPipelineInfoLogEXT(GLcontext *context, GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
EXPORT void cwcglGetProgramPipelineiv(GLcontext *context, GLuint pipeline, GLenum pname, GLint * params);
EXPORT void cwcglGetProgramPipelineivEXT(GLcontext *context, GLuint pipeline, GLenum pname, GLint * params);
EXPORT void cwcglGetProgramResourceIndex(GLcontext *context, GLuint program, GLenum programInterface, const GLchar * name, GLuint* return_value);
EXPORT void cwcglGetProgramResourceLocation(GLcontext *context, GLuint program, GLenum programInterface, const GLchar * name, GLint* return_value);
EXPORT void cwcglGetProgramResourceLocationIndex(GLcontext *context, GLuint program, GLenum programInterface, const GLchar * name, GLint* return_value);
EXPORT void cwcglGetProgramResourceLocationIndexEXT(GLcontext *context, GLuint program, GLenum programInterface, const GLchar * name, GLint* return_value);
EXPORT void cwcglGetProgramResourceName(GLcontext *context, GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
EXPORT void cwcglGetProgramResourcefvNV(GLcontext *context, GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLfloat * params);
EXPORT void cwcglGetProgramResourceiv(GLcontext *context, GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params);
EXPORT void cwcglGetProgramStageiv(GLcontext *context, GLuint program, GLenum shadertype, GLenum pname, GLint * values);
EXPORT void cwcglGetProgramStringARB(GLcontext *context, GLenum target, GLenum pname, void * string);
EXPORT void cwcglGetProgramStringNV(GLcontext *context, GLuint id, GLenum pname, GLubyte * program);
EXPORT void cwcglGetProgramSubroutineParameteruivNV(GLcontext *context, GLenum target, GLuint index, GLuint * param);
EXPORT void cwcglGetProgramiv(GLcontext *context, GLuint program, GLenum pname, GLint * params);
EXPORT void cwcglGetProgramivARB(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetProgramivNV(GLcontext *context, GLuint id, GLenum pname, GLint * params);
EXPORT void cwcglGetQueryBufferObjecti64v(GLcontext *context, GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
EXPORT void cwcglGetQueryBufferObjectiv(GLcontext *context, GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
EXPORT void cwcglGetQueryBufferObjectui64v(GLcontext *context, GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
EXPORT void cwcglGetQueryBufferObjectuiv(GLcontext *context, GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
EXPORT void cwcglGetQueryIndexediv(GLcontext *context, GLenum target, GLuint index, GLenum pname, GLint * params);
EXPORT void cwcglGetQueryObjecti64v(GLcontext *context, GLuint id, GLenum pname, GLint64 * params);
EXPORT void cwcglGetQueryObjecti64vEXT(GLcontext *context, GLuint id, GLenum pname, GLint64 * params);
EXPORT void cwcglGetQueryObjectiv(GLcontext *context, GLuint id, GLenum pname, GLint * params);
EXPORT void cwcglGetQueryObjectivARB(GLcontext *context, GLuint id, GLenum pname, GLint * params);
EXPORT void cwcglGetQueryObjectivEXT(GLcontext *context, GLuint id, GLenum pname, GLint * params);
EXPORT void cwcglGetQueryObjectui64v(GLcontext *context, GLuint id, GLenum pname, GLuint64 * params);
EXPORT void cwcglGetQueryObjectui64vEXT(GLcontext *context, GLuint id, GLenum pname, GLuint64 * params);
EXPORT void cwcglGetQueryObjectuiv(GLcontext *context, GLuint id, GLenum pname, GLuint * params);
EXPORT void cwcglGetQueryObjectuivARB(GLcontext *context, GLuint id, GLenum pname, GLuint * params);
EXPORT void cwcglGetQueryObjectuivEXT(GLcontext *context, GLuint id, GLenum pname, GLuint * params);
EXPORT void cwcglGetQueryiv(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetQueryivARB(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetQueryivEXT(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetRenderbufferParameteriv(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetRenderbufferParameterivEXT(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetRenderbufferParameterivOES(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetSamplerParameterIiv(GLcontext *context, GLuint sampler, GLenum pname, GLint * params);
EXPORT void cwcglGetSamplerParameterIivEXT(GLcontext *context, GLuint sampler, GLenum pname, GLint * params);
EXPORT void cwcglGetSamplerParameterIivOES(GLcontext *context, GLuint sampler, GLenum pname, GLint * params);
EXPORT void cwcglGetSamplerParameterIuiv(GLcontext *context, GLuint sampler, GLenum pname, GLuint * params);
EXPORT void cwcglGetSamplerParameterIuivEXT(GLcontext *context, GLuint sampler, GLenum pname, GLuint * params);
EXPORT void cwcglGetSamplerParameterIuivOES(GLcontext *context, GLuint sampler, GLenum pname, GLuint * params);
EXPORT void cwcglGetSamplerParameterfv(GLcontext *context, GLuint sampler, GLenum pname, GLfloat * params);
EXPORT void cwcglGetSamplerParameteriv(GLcontext *context, GLuint sampler, GLenum pname, GLint * params);
EXPORT void cwcglGetSeparableFilter(GLcontext *context, GLenum target, GLenum format, GLenum type, void * row, void * column, void * span);
EXPORT void cwcglGetSeparableFilterEXT(GLcontext *context, GLenum target, GLenum format, GLenum type, void * row, void * column, void * span);
EXPORT void cwcglGetShaderInfoLog(GLcontext *context, GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
EXPORT void cwcglGetShaderPrecisionFormat(GLcontext *context, GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
EXPORT void cwcglGetShaderSource(GLcontext *context, GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
EXPORT void cwcglGetShaderSourceARB(GLcontext *context, GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * source);
EXPORT void cwcglGetShaderiv(GLcontext *context, GLuint shader, GLenum pname, GLint * params);
EXPORT void cwcglGetSharpenTexFuncSGIS(GLcontext *context, GLenum target, GLfloat * points);
EXPORT void cwcglGetStageIndexNV(GLcontext *context, GLenum shadertype, GLushort* return_value);
EXPORT void cwcglGetString(GLcontext *context, GLenum name, const GLubyte ** return_value);
EXPORT void cwcglGetStringi(GLcontext *context, GLenum name, GLuint index, const GLubyte ** return_value);
EXPORT void cwcglGetSubroutineIndex(GLcontext *context, GLuint program, GLenum shadertype, const GLchar * name, GLuint* return_value);
EXPORT void cwcglGetSubroutineUniformLocation(GLcontext *context, GLuint program, GLenum shadertype, const GLchar * name, GLint* return_value);
EXPORT void cwcglGetSynciv(GLcontext *context, GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values);
EXPORT void cwcglGetSyncivAPPLE(GLcontext *context, GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values);
EXPORT void cwcglGetTexBumpParameterfvATI(GLcontext *context, GLenum pname, GLfloat * param);
EXPORT void cwcglGetTexBumpParameterivATI(GLcontext *context, GLenum pname, GLint * param);
EXPORT void cwcglGetTexEnvfv(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetTexEnviv(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetTexEnvxv(GLcontext *context, GLenum target, GLenum pname, GLfixed * params);
EXPORT void cwcglGetTexEnvxvOES(GLcontext *context, GLenum target, GLenum pname, GLfixed * params);
EXPORT void cwcglGetTexFilterFuncSGIS(GLcontext *context, GLenum target, GLenum filter, GLfloat * weights);
EXPORT void cwcglGetTexGendv(GLcontext *context, GLenum coord, GLenum pname, GLdouble * params);
EXPORT void cwcglGetTexGenfv(GLcontext *context, GLenum coord, GLenum pname, GLfloat * params);
EXPORT void cwcglGetTexGenfvOES(GLcontext *context, GLenum coord, GLenum pname, GLfloat * params);
EXPORT void cwcglGetTexGeniv(GLcontext *context, GLenum coord, GLenum pname, GLint * params);
EXPORT void cwcglGetTexGenivOES(GLcontext *context, GLenum coord, GLenum pname, GLint * params);
EXPORT void cwcglGetTexGenxvOES(GLcontext *context, GLenum coord, GLenum pname, GLfixed * params);
EXPORT void cwcglGetTexImage(GLcontext *context, GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
EXPORT void cwcglGetTexLevelParameterfv(GLcontext *context, GLenum target, GLint level, GLenum pname, GLfloat * params);
EXPORT void cwcglGetTexLevelParameteriv(GLcontext *context, GLenum target, GLint level, GLenum pname, GLint * params);
EXPORT void cwcglGetTexLevelParameterxvOES(GLcontext *context, GLenum target, GLint level, GLenum pname, GLfixed * params);
EXPORT void cwcglGetTexParameterIiv(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetTexParameterIivEXT(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetTexParameterIivOES(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetTexParameterIuiv(GLcontext *context, GLenum target, GLenum pname, GLuint * params);
EXPORT void cwcglGetTexParameterIuivEXT(GLcontext *context, GLenum target, GLenum pname, GLuint * params);
EXPORT void cwcglGetTexParameterIuivOES(GLcontext *context, GLenum target, GLenum pname, GLuint * params);
EXPORT void cwcglGetTexParameterPointervAPPLE(GLcontext *context, GLenum target, GLenum pname, void ** params);
EXPORT void cwcglGetTexParameterfv(GLcontext *context, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetTexParameteriv(GLcontext *context, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetTexParameterxv(GLcontext *context, GLenum target, GLenum pname, GLfixed * params);
EXPORT void cwcglGetTexParameterxvOES(GLcontext *context, GLenum target, GLenum pname, GLfixed * params);
EXPORT void cwcglGetTextureHandleARB(GLcontext *context, GLuint texture, GLuint64* return_value);
EXPORT void cwcglGetTextureHandleIMG(GLcontext *context, GLuint texture, GLuint64* return_value);
EXPORT void cwcglGetTextureHandleNV(GLcontext *context, GLuint texture, GLuint64* return_value);
EXPORT void cwcglGetTextureImage(GLcontext *context, GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
EXPORT void cwcglGetTextureImageEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
EXPORT void cwcglGetTextureLevelParameterfv(GLcontext *context, GLuint texture, GLint level, GLenum pname, GLfloat * params);
EXPORT void cwcglGetTextureLevelParameterfvEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat * params);
EXPORT void cwcglGetTextureLevelParameteriv(GLcontext *context, GLuint texture, GLint level, GLenum pname, GLint * params);
EXPORT void cwcglGetTextureLevelParameterivEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLenum pname, GLint * params);
EXPORT void cwcglGetTextureParameterIiv(GLcontext *context, GLuint texture, GLenum pname, GLint * params);
EXPORT void cwcglGetTextureParameterIivEXT(GLcontext *context, GLuint texture, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetTextureParameterIuiv(GLcontext *context, GLuint texture, GLenum pname, GLuint * params);
EXPORT void cwcglGetTextureParameterIuivEXT(GLcontext *context, GLuint texture, GLenum target, GLenum pname, GLuint * params);
EXPORT void cwcglGetTextureParameterfv(GLcontext *context, GLuint texture, GLenum pname, GLfloat * params);
EXPORT void cwcglGetTextureParameterfvEXT(GLcontext *context, GLuint texture, GLenum target, GLenum pname, GLfloat * params);
EXPORT void cwcglGetTextureParameteriv(GLcontext *context, GLuint texture, GLenum pname, GLint * params);
EXPORT void cwcglGetTextureParameterivEXT(GLcontext *context, GLuint texture, GLenum target, GLenum pname, GLint * params);
EXPORT void cwcglGetTextureSamplerHandleARB(GLcontext *context, GLuint texture, GLuint sampler, GLuint64* return_value);
EXPORT void cwcglGetTextureSamplerHandleIMG(GLcontext *context, GLuint texture, GLuint sampler, GLuint64* return_value);
EXPORT void cwcglGetTextureSamplerHandleNV(GLcontext *context, GLuint texture, GLuint sampler, GLuint64* return_value);
EXPORT void cwcglGetTextureSubImage(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
EXPORT void cwcglGetTrackMatrixivNV(GLcontext *context, GLenum target, GLuint address, GLenum pname, GLint * params);
EXPORT void cwcglGetTransformFeedbackVarying(GLcontext *context, GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
EXPORT void cwcglGetTransformFeedbackVaryingEXT(GLcontext *context, GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
EXPORT void cwcglGetTransformFeedbackVaryingNV(GLcontext *context, GLuint program, GLuint index, GLint * location);
EXPORT void cwcglGetTransformFeedbacki64_v(GLcontext *context, GLuint xfb, GLenum pname, GLuint index, GLint64 * param);
EXPORT void cwcglGetTransformFeedbacki_v(GLcontext *context, GLuint xfb, GLenum pname, GLuint index, GLint * param);
EXPORT void cwcglGetTransformFeedbackiv(GLcontext *context, GLuint xfb, GLenum pname, GLint * param);
EXPORT void cwcglGetTranslatedShaderSourceANGLE(GLcontext *context, GLuint shader, GLsizei bufsize, GLsizei * length, GLchar * source);
EXPORT void cwcglGetUniformBlockIndex(GLcontext *context, GLuint program, const GLchar * uniformBlockName, GLuint* return_value);
EXPORT void cwcglGetUniformBufferSizeEXT(GLcontext *context, GLuint program, GLint location, GLint* return_value);
EXPORT void cwcglGetUniformIndices(GLcontext *context, GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices);
EXPORT void cwcglGetUniformLocation(GLcontext *context, GLuint program, const GLchar * name, GLint* return_value);
EXPORT void cwcglGetUniformLocationARB(GLcontext *context, GLhandleARB programObj, const GLcharARB * name, GLint* return_value);
EXPORT void cwcglGetUniformOffsetEXT(GLcontext *context, GLuint program, GLint location, GLintptr* return_value);
EXPORT void cwcglGetUniformSubroutineuiv(GLcontext *context, GLenum shadertype, GLint location, GLuint * params);
EXPORT void cwcglGetUniformdv(GLcontext *context, GLuint program, GLint location, GLdouble * params);
EXPORT void cwcglGetUniformfv(GLcontext *context, GLuint program, GLint location, GLfloat * params);
EXPORT void cwcglGetUniformfvARB(GLcontext *context, GLhandleARB programObj, GLint location, GLfloat * params);
EXPORT void cwcglGetUniformi64vARB(GLcontext *context, GLuint program, GLint location, GLint64 * params);
EXPORT void cwcglGetUniformi64vNV(GLcontext *context, GLuint program, GLint location, GLint64EXT * params);
EXPORT void cwcglGetUniformiv(GLcontext *context, GLuint program, GLint location, GLint * params);
EXPORT void cwcglGetUniformivARB(GLcontext *context, GLhandleARB programObj, GLint location, GLint * params);
EXPORT void cwcglGetUniformui64vARB(GLcontext *context, GLuint program, GLint location, GLuint64 * params);
EXPORT void cwcglGetUniformui64vNV(GLcontext *context, GLuint program, GLint location, GLuint64EXT * params);
EXPORT void cwcglGetUniformuiv(GLcontext *context, GLuint program, GLint location, GLuint * params);
EXPORT void cwcglGetUniformuivEXT(GLcontext *context, GLuint program, GLint location, GLuint * params);
EXPORT void cwcglGetVariantArrayObjectfvATI(GLcontext *context, GLuint id, GLenum pname, GLfloat * params);
EXPORT void cwcglGetVariantArrayObjectivATI(GLcontext *context, GLuint id, GLenum pname, GLint * params);
EXPORT void cwcglGetVariantBooleanvEXT(GLcontext *context, GLuint id, GLenum value, GLboolean * data);
EXPORT void cwcglGetVariantFloatvEXT(GLcontext *context, GLuint id, GLenum value, GLfloat * data);
EXPORT void cwcglGetVariantIntegervEXT(GLcontext *context, GLuint id, GLenum value, GLint * data);
EXPORT void cwcglGetVariantPointervEXT(GLcontext *context, GLuint id, GLenum value, void ** data);
EXPORT void cwcglGetVaryingLocationNV(GLcontext *context, GLuint program, const GLchar * name, GLint* return_value);
EXPORT void cwcglGetVertexArrayIndexed64iv(GLcontext *context, GLuint vaobj, GLuint index, GLenum pname, GLint64 * param);
EXPORT void cwcglGetVertexArrayIndexediv(GLcontext *context, GLuint vaobj, GLuint index, GLenum pname, GLint * param);
EXPORT void cwcglGetVertexArrayIntegeri_vEXT(GLcontext *context, GLuint vaobj, GLuint index, GLenum pname, GLint * param);
EXPORT void cwcglGetVertexArrayIntegervEXT(GLcontext *context, GLuint vaobj, GLenum pname, GLint * param);
EXPORT void cwcglGetVertexArrayPointeri_vEXT(GLcontext *context, GLuint vaobj, GLuint index, GLenum pname, void ** param);
EXPORT void cwcglGetVertexArrayPointervEXT(GLcontext *context, GLuint vaobj, GLenum pname, void ** param);
EXPORT void cwcglGetVertexArrayiv(GLcontext *context, GLuint vaobj, GLenum pname, GLint * param);
EXPORT void cwcglGetVertexAttribArrayObjectfvATI(GLcontext *context, GLuint index, GLenum pname, GLfloat * params);
EXPORT void cwcglGetVertexAttribArrayObjectivATI(GLcontext *context, GLuint index, GLenum pname, GLint * params);
EXPORT void cwcglGetVertexAttribIiv(GLcontext *context, GLuint index, GLenum pname, GLint * params);
EXPORT void cwcglGetVertexAttribIivEXT(GLcontext *context, GLuint index, GLenum pname, GLint * params);
EXPORT void cwcglGetVertexAttribIuiv(GLcontext *context, GLuint index, GLenum pname, GLuint * params);
EXPORT void cwcglGetVertexAttribIuivEXT(GLcontext *context, GLuint index, GLenum pname, GLuint * params);
EXPORT void cwcglGetVertexAttribLdv(GLcontext *context, GLuint index, GLenum pname, GLdouble * params);
EXPORT void cwcglGetVertexAttribLdvEXT(GLcontext *context, GLuint index, GLenum pname, GLdouble * params);
EXPORT void cwcglGetVertexAttribLi64vNV(GLcontext *context, GLuint index, GLenum pname, GLint64EXT * params);
EXPORT void cwcglGetVertexAttribLui64vARB(GLcontext *context, GLuint index, GLenum pname, GLuint64EXT * params);
EXPORT void cwcglGetVertexAttribLui64vNV(GLcontext *context, GLuint index, GLenum pname, GLuint64EXT * params);
EXPORT void cwcglGetVertexAttribPointerv(GLcontext *context, GLuint index, GLenum pname, void ** pointer);
EXPORT void cwcglGetVertexAttribPointervARB(GLcontext *context, GLuint index, GLenum pname, void ** pointer);
EXPORT void cwcglGetVertexAttribPointervNV(GLcontext *context, GLuint index, GLenum pname, void ** pointer);
EXPORT void cwcglGetVertexAttribdv(GLcontext *context, GLuint index, GLenum pname, GLdouble * params);
EXPORT void cwcglGetVertexAttribdvARB(GLcontext *context, GLuint index, GLenum pname, GLdouble * params);
EXPORT void cwcglGetVertexAttribdvNV(GLcontext *context, GLuint index, GLenum pname, GLdouble * params);
EXPORT void cwcglGetVertexAttribfv(GLcontext *context, GLuint index, GLenum pname, GLfloat * params);
EXPORT void cwcglGetVertexAttribfvARB(GLcontext *context, GLuint index, GLenum pname, GLfloat * params);
EXPORT void cwcglGetVertexAttribfvNV(GLcontext *context, GLuint index, GLenum pname, GLfloat * params);
EXPORT void cwcglGetVertexAttribiv(GLcontext *context, GLuint index, GLenum pname, GLint * params);
EXPORT void cwcglGetVertexAttribivARB(GLcontext *context, GLuint index, GLenum pname, GLint * params);
EXPORT void cwcglGetVertexAttribivNV(GLcontext *context, GLuint index, GLenum pname, GLint * params);
EXPORT void cwcglGetVideoCaptureStreamdvNV(GLcontext *context, GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble * params);
EXPORT void cwcglGetVideoCaptureStreamfvNV(GLcontext *context, GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat * params);
EXPORT void cwcglGetVideoCaptureStreamivNV(GLcontext *context, GLuint video_capture_slot, GLuint stream, GLenum pname, GLint * params);
EXPORT void cwcglGetVideoCaptureivNV(GLcontext *context, GLuint video_capture_slot, GLenum pname, GLint * params);
EXPORT void cwcglGetVideoi64vNV(GLcontext *context, GLuint video_slot, GLenum pname, GLint64EXT * params);
EXPORT void cwcglGetVideoivNV(GLcontext *context, GLuint video_slot, GLenum pname, GLint * params);
EXPORT void cwcglGetVideoui64vNV(GLcontext *context, GLuint video_slot, GLenum pname, GLuint64EXT * params);
EXPORT void cwcglGetVideouivNV(GLcontext *context, GLuint video_slot, GLenum pname, GLuint * params);
EXPORT void cwcglGetnColorTable(GLcontext *context, GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table);
EXPORT void cwcglGetnColorTableARB(GLcontext *context, GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table);
EXPORT void cwcglGetnCompressedTexImage(GLcontext *context, GLenum target, GLint lod, GLsizei bufSize, void * pixels);
EXPORT void cwcglGetnCompressedTexImageARB(GLcontext *context, GLenum target, GLint lod, GLsizei bufSize, void * img);
EXPORT void cwcglGetnConvolutionFilter(GLcontext *context, GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image);
EXPORT void cwcglGetnConvolutionFilterARB(GLcontext *context, GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image);
EXPORT void cwcglGetnHistogram(GLcontext *context, GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
EXPORT void cwcglGetnHistogramARB(GLcontext *context, GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
EXPORT void cwcglGetnMapdv(GLcontext *context, GLenum target, GLenum query, GLsizei bufSize, GLdouble * v);
EXPORT void cwcglGetnMapdvARB(GLcontext *context, GLenum target, GLenum query, GLsizei bufSize, GLdouble * v);
EXPORT void cwcglGetnMapfv(GLcontext *context, GLenum target, GLenum query, GLsizei bufSize, GLfloat * v);
EXPORT void cwcglGetnMapfvARB(GLcontext *context, GLenum target, GLenum query, GLsizei bufSize, GLfloat * v);
EXPORT void cwcglGetnMapiv(GLcontext *context, GLenum target, GLenum query, GLsizei bufSize, GLint * v);
EXPORT void cwcglGetnMapivARB(GLcontext *context, GLenum target, GLenum query, GLsizei bufSize, GLint * v);
EXPORT void cwcglGetnMinmax(GLcontext *context, GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
EXPORT void cwcglGetnMinmaxARB(GLcontext *context, GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
EXPORT void cwcglGetnPixelMapfv(GLcontext *context, GLenum map, GLsizei bufSize, GLfloat * values);
EXPORT void cwcglGetnPixelMapfvARB(GLcontext *context, GLenum map, GLsizei bufSize, GLfloat * values);
EXPORT void cwcglGetnPixelMapuiv(GLcontext *context, GLenum map, GLsizei bufSize, GLuint * values);
EXPORT void cwcglGetnPixelMapuivARB(GLcontext *context, GLenum map, GLsizei bufSize, GLuint * values);
EXPORT void cwcglGetnPixelMapusv(GLcontext *context, GLenum map, GLsizei bufSize, GLushort * values);
EXPORT void cwcglGetnPixelMapusvARB(GLcontext *context, GLenum map, GLsizei bufSize, GLushort * values);
EXPORT void cwcglGetnPolygonStipple(GLcontext *context, GLsizei bufSize, GLubyte * pattern);
EXPORT void cwcglGetnPolygonStippleARB(GLcontext *context, GLsizei bufSize, GLubyte * pattern);
EXPORT void cwcglGetnSeparableFilter(GLcontext *context, GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span);
EXPORT void cwcglGetnSeparableFilterARB(GLcontext *context, GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span);
EXPORT void cwcglGetnTexImage(GLcontext *context, GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
EXPORT void cwcglGetnTexImageARB(GLcontext *context, GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * img);
EXPORT void cwcglGetnUniformdv(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLdouble * params);
EXPORT void cwcglGetnUniformdvARB(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLdouble * params);
EXPORT void cwcglGetnUniformfv(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
EXPORT void cwcglGetnUniformfvARB(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
EXPORT void cwcglGetnUniformfvEXT(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
EXPORT void cwcglGetnUniformfvKHR(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
EXPORT void cwcglGetnUniformi64vARB(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLint64 * params);
EXPORT void cwcglGetnUniformiv(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLint * params);
EXPORT void cwcglGetnUniformivARB(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLint * params);
EXPORT void cwcglGetnUniformivEXT(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLint * params);
EXPORT void cwcglGetnUniformivKHR(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLint * params);
EXPORT void cwcglGetnUniformui64vARB(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLuint64 * params);
EXPORT void cwcglGetnUniformuiv(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLuint * params);
EXPORT void cwcglGetnUniformuivARB(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLuint * params);
EXPORT void cwcglGetnUniformuivKHR(GLcontext *context, GLuint program, GLint location, GLsizei bufSize, GLuint * params);
EXPORT void cwcglGlobalAlphaFactorbSUN(GLcontext *context, GLbyte factor);
EXPORT void cwcglGlobalAlphaFactordSUN(GLcontext *context, GLdouble factor);
EXPORT void cwcglGlobalAlphaFactorfSUN(GLcontext *context, GLfloat factor);
EXPORT void cwcglGlobalAlphaFactoriSUN(GLcontext *context, GLint factor);
EXPORT void cwcglGlobalAlphaFactorsSUN(GLcontext *context, GLshort factor);
EXPORT void cwcglGlobalAlphaFactorubSUN(GLcontext *context, GLubyte factor);
EXPORT void cwcglGlobalAlphaFactoruiSUN(GLcontext *context, GLuint factor);
EXPORT void cwcglGlobalAlphaFactorusSUN(GLcontext *context, GLushort factor);
EXPORT void cwcglHint(GLcontext *context, GLenum target, GLenum mode);
EXPORT void cwcglHintPGI(GLcontext *context, GLenum target, GLint mode);
EXPORT void cwcglHistogram(GLcontext *context, GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
EXPORT void cwcglHistogramEXT(GLcontext *context, GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
EXPORT void cwcglIglooInterfaceSGIX(GLcontext *context, GLenum pname, const void * params);
EXPORT void cwcglImageTransformParameterfHP(GLcontext *context, GLenum target, GLenum pname, GLfloat param);
EXPORT void cwcglImageTransformParameterfvHP(GLcontext *context, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglImageTransformParameteriHP(GLcontext *context, GLenum target, GLenum pname, GLint param);
EXPORT void cwcglImageTransformParameterivHP(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglImportSyncEXT(GLcontext *context, GLenum external_sync_type, GLintptr external_sync, GLbitfield flags, GLsync* return_value);
EXPORT void cwcglIndexFormatNV(GLcontext *context, GLenum type, GLsizei stride);
EXPORT void cwcglIndexFuncEXT(GLcontext *context, GLenum func, GLclampf ref);
EXPORT void cwcglIndexMask(GLcontext *context, GLuint mask);
EXPORT void cwcglIndexMaterialEXT(GLcontext *context, GLenum face, GLenum mode);
EXPORT void cwcglIndexPointer(GLcontext *context, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglIndexPointerEXT(GLcontext *context, GLenum type, GLsizei stride, GLsizei count, const void * pointer);
EXPORT void cwcglIndexPointerListIBM(GLcontext *context, GLenum type, GLint stride, const void ** pointer, GLint ptrstride);
EXPORT void cwcglIndexd(GLcontext *context, GLdouble c);
EXPORT void cwcglIndexdv(GLcontext *context, const GLdouble * c);
EXPORT void cwcglIndexf(GLcontext *context, GLfloat c);
EXPORT void cwcglIndexfv(GLcontext *context, const GLfloat * c);
EXPORT void cwcglIndexi(GLcontext *context, GLint c);
EXPORT void cwcglIndexiv(GLcontext *context, const GLint * c);
EXPORT void cwcglIndexs(GLcontext *context, GLshort c);
EXPORT void cwcglIndexsv(GLcontext *context, const GLshort * c);
EXPORT void cwcglIndexub(GLcontext *context, GLubyte c);
EXPORT void cwcglIndexubv(GLcontext *context, const GLubyte * c);
EXPORT void cwcglIndexxOES(GLcontext *context, GLfixed component);
EXPORT void cwcglIndexxvOES(GLcontext *context, const GLfixed * component);
EXPORT void cwcglInitNames(GLcontext *context);
EXPORT void cwcglInsertComponentEXT(GLcontext *context, GLuint res, GLuint src, GLuint num);
EXPORT void cwcglInsertEventMarkerEXT(GLcontext *context, GLsizei length, const GLchar * marker);
EXPORT void cwcglInstrumentsBufferSGIX(GLcontext *context, GLsizei size, GLint * buffer);
EXPORT void cwcglInterleavedArrays(GLcontext *context, GLenum format, GLsizei stride, const void * pointer);
EXPORT void cwcglInterpolatePathsNV(GLcontext *context, GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
EXPORT void cwcglInvalidateBufferData(GLcontext *context, GLuint buffer);
EXPORT void cwcglInvalidateBufferSubData(GLcontext *context, GLuint buffer, GLintptr offset, GLsizeiptr length);
EXPORT void cwcglInvalidateFramebuffer(GLcontext *context, GLenum target, GLsizei numAttachments, const GLenum * attachments);
EXPORT void cwcglInvalidateNamedFramebufferData(GLcontext *context, GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments);
EXPORT void cwcglInvalidateNamedFramebufferSubData(GLcontext *context, GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglInvalidateSubFramebuffer(GLcontext *context, GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglInvalidateTexImage(GLcontext *context, GLuint texture, GLint level);
EXPORT void cwcglInvalidateTexSubImage(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
EXPORT void cwcglIsAsyncMarkerSGIX(GLcontext *context, GLuint marker, GLboolean* return_value);
EXPORT void cwcglIsBuffer(GLcontext *context, GLuint buffer, GLboolean* return_value);
EXPORT void cwcglIsBufferARB(GLcontext *context, GLuint buffer, GLboolean* return_value);
EXPORT void cwcglIsBufferResidentNV(GLcontext *context, GLenum target, GLboolean* return_value);
EXPORT void cwcglIsCommandListNV(GLcontext *context, GLuint list, GLboolean* return_value);
EXPORT void cwcglIsEnabled(GLcontext *context, GLenum cap, GLboolean* return_value);
EXPORT void cwcglIsEnabledIndexedEXT(GLcontext *context, GLenum target, GLuint index, GLboolean* return_value);
EXPORT void cwcglIsEnabledi(GLcontext *context, GLenum target, GLuint index, GLboolean* return_value);
EXPORT void cwcglIsEnablediEXT(GLcontext *context, GLenum target, GLuint index, GLboolean* return_value);
EXPORT void cwcglIsEnablediNV(GLcontext *context, GLenum target, GLuint index, GLboolean* return_value);
EXPORT void cwcglIsEnablediOES(GLcontext *context, GLenum target, GLuint index, GLboolean* return_value);
EXPORT void cwcglIsFenceAPPLE(GLcontext *context, GLuint fence, GLboolean* return_value);
EXPORT void cwcglIsFenceNV(GLcontext *context, GLuint fence, GLboolean* return_value);
EXPORT void cwcglIsFramebuffer(GLcontext *context, GLuint framebuffer, GLboolean* return_value);
EXPORT void cwcglIsFramebufferEXT(GLcontext *context, GLuint framebuffer, GLboolean* return_value);
EXPORT void cwcglIsFramebufferOES(GLcontext *context, GLuint framebuffer, GLboolean* return_value);
EXPORT void cwcglIsImageHandleResidentARB(GLcontext *context, GLuint64 handle, GLboolean* return_value);
EXPORT void cwcglIsImageHandleResidentNV(GLcontext *context, GLuint64 handle, GLboolean* return_value);
EXPORT void cwcglIsList(GLcontext *context, GLuint list, GLboolean* return_value);
EXPORT void cwcglIsNameAMD(GLcontext *context, GLenum identifier, GLuint name, GLboolean* return_value);
EXPORT void cwcglIsNamedBufferResidentNV(GLcontext *context, GLuint buffer, GLboolean* return_value);
EXPORT void cwcglIsNamedStringARB(GLcontext *context, GLint namelen, const GLchar * name, GLboolean* return_value);
EXPORT void cwcglIsObjectBufferATI(GLcontext *context, GLuint buffer, GLboolean* return_value);
EXPORT void cwcglIsOcclusionQueryNV(GLcontext *context, GLuint id, GLboolean* return_value);
EXPORT void cwcglIsPathNV(GLcontext *context, GLuint path, GLboolean* return_value);
EXPORT void cwcglIsPointInFillPathNV(GLcontext *context, GLuint path, GLuint mask, GLfloat x, GLfloat y, GLboolean* return_value);
EXPORT void cwcglIsPointInStrokePathNV(GLcontext *context, GLuint path, GLfloat x, GLfloat y, GLboolean* return_value);
EXPORT void cwcglIsProgram(GLcontext *context, GLuint program, GLboolean* return_value);
EXPORT void cwcglIsProgramARB(GLcontext *context, GLuint program, GLboolean* return_value);
EXPORT void cwcglIsProgramNV(GLcontext *context, GLuint id, GLboolean* return_value);
EXPORT void cwcglIsProgramPipeline(GLcontext *context, GLuint pipeline, GLboolean* return_value);
EXPORT void cwcglIsProgramPipelineEXT(GLcontext *context, GLuint pipeline, GLboolean* return_value);
EXPORT void cwcglIsQuery(GLcontext *context, GLuint id, GLboolean* return_value);
EXPORT void cwcglIsQueryARB(GLcontext *context, GLuint id, GLboolean* return_value);
EXPORT void cwcglIsQueryEXT(GLcontext *context, GLuint id, GLboolean* return_value);
EXPORT void cwcglIsRenderbuffer(GLcontext *context, GLuint renderbuffer, GLboolean* return_value);
EXPORT void cwcglIsRenderbufferEXT(GLcontext *context, GLuint renderbuffer, GLboolean* return_value);
EXPORT void cwcglIsRenderbufferOES(GLcontext *context, GLuint renderbuffer, GLboolean* return_value);
EXPORT void cwcglIsSampler(GLcontext *context, GLuint sampler, GLboolean* return_value);
EXPORT void cwcglIsShader(GLcontext *context, GLuint shader, GLboolean* return_value);
EXPORT void cwcglIsStateNV(GLcontext *context, GLuint state, GLboolean* return_value);
EXPORT void cwcglIsSync(GLcontext *context, GLsync sync, GLboolean* return_value);
EXPORT void cwcglIsSyncAPPLE(GLcontext *context, GLsync sync, GLboolean* return_value);
EXPORT void cwcglIsTexture(GLcontext *context, GLuint texture, GLboolean* return_value);
EXPORT void cwcglIsTextureEXT(GLcontext *context, GLuint texture, GLboolean* return_value);
EXPORT void cwcglIsTextureHandleResidentARB(GLcontext *context, GLuint64 handle, GLboolean* return_value);
EXPORT void cwcglIsTextureHandleResidentNV(GLcontext *context, GLuint64 handle, GLboolean* return_value);
EXPORT void cwcglIsTransformFeedback(GLcontext *context, GLuint id, GLboolean* return_value);
EXPORT void cwcglIsTransformFeedbackNV(GLcontext *context, GLuint id, GLboolean* return_value);
EXPORT void cwcglIsVariantEnabledEXT(GLcontext *context, GLuint id, GLenum cap, GLboolean* return_value);
EXPORT void cwcglIsVertexArray(GLcontext *context, GLuint array, GLboolean* return_value);
EXPORT void cwcglIsVertexArrayAPPLE(GLcontext *context, GLuint array, GLboolean* return_value);
EXPORT void cwcglIsVertexArrayOES(GLcontext *context, GLuint array, GLboolean* return_value);
EXPORT void cwcglIsVertexAttribEnabledAPPLE(GLcontext *context, GLuint index, GLenum pname, GLboolean* return_value);
EXPORT void cwcglLabelObjectEXT(GLcontext *context, GLenum type, GLuint object, GLsizei length, const GLchar * label);
EXPORT void cwcglLightEnviSGIX(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglLightModelf(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglLightModelfv(GLcontext *context, GLenum pname, const GLfloat * params);
EXPORT void cwcglLightModeli(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglLightModeliv(GLcontext *context, GLenum pname, const GLint * params);
EXPORT void cwcglLightModelx(GLcontext *context, GLenum pname, GLfixed param);
EXPORT void cwcglLightModelxOES(GLcontext *context, GLenum pname, GLfixed param);
EXPORT void cwcglLightModelxv(GLcontext *context, GLenum pname, const GLfixed * param);
EXPORT void cwcglLightModelxvOES(GLcontext *context, GLenum pname, const GLfixed * param);
EXPORT void cwcglLightf(GLcontext *context, GLenum light, GLenum pname, GLfloat param);
EXPORT void cwcglLightfv(GLcontext *context, GLenum light, GLenum pname, const GLfloat * params);
EXPORT void cwcglLighti(GLcontext *context, GLenum light, GLenum pname, GLint param);
EXPORT void cwcglLightiv(GLcontext *context, GLenum light, GLenum pname, const GLint * params);
EXPORT void cwcglLightx(GLcontext *context, GLenum light, GLenum pname, GLfixed param);
EXPORT void cwcglLightxOES(GLcontext *context, GLenum light, GLenum pname, GLfixed param);
EXPORT void cwcglLightxv(GLcontext *context, GLenum light, GLenum pname, const GLfixed * params);
EXPORT void cwcglLightxvOES(GLcontext *context, GLenum light, GLenum pname, const GLfixed * params);
EXPORT void cwcglLineStipple(GLcontext *context, GLint factor, GLushort pattern);
EXPORT void cwcglLineWidth(GLcontext *context, GLfloat width);
EXPORT void cwcglLineWidthx(GLcontext *context, GLfixed width);
EXPORT void cwcglLineWidthxOES(GLcontext *context, GLfixed width);
EXPORT void cwcglLinkProgram(GLcontext *context, GLuint program);
EXPORT void cwcglLinkProgramARB(GLcontext *context, GLhandleARB programObj);
EXPORT void cwcglListBase(GLcontext *context, GLuint base);
EXPORT void cwcglListDrawCommandsStatesClientNV(GLcontext *context, GLuint list, GLuint segment, const void ** indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count);
EXPORT void cwcglListParameterfSGIX(GLcontext *context, GLuint list, GLenum pname, GLfloat param);
EXPORT void cwcglListParameterfvSGIX(GLcontext *context, GLuint list, GLenum pname, const GLfloat * params);
EXPORT void cwcglListParameteriSGIX(GLcontext *context, GLuint list, GLenum pname, GLint param);
EXPORT void cwcglListParameterivSGIX(GLcontext *context, GLuint list, GLenum pname, const GLint * params);
EXPORT void cwcglLoadIdentity(GLcontext *context);
EXPORT void cwcglLoadIdentityDeformationMapSGIX(GLcontext *context, GLbitfield mask);
EXPORT void cwcglLoadMatrixd(GLcontext *context, const GLdouble * m);
EXPORT void cwcglLoadMatrixf(GLcontext *context, const GLfloat * m);
EXPORT void cwcglLoadMatrixx(GLcontext *context, const GLfixed * m);
EXPORT void cwcglLoadMatrixxOES(GLcontext *context, const GLfixed * m);
EXPORT void cwcglLoadName(GLcontext *context, GLuint name);
EXPORT void cwcglLoadPaletteFromModelViewMatrixOES(GLcontext *context);
EXPORT void cwcglLoadProgramNV(GLcontext *context, GLenum target, GLuint id, GLsizei len, const GLubyte * program);
EXPORT void cwcglLoadTransposeMatrixd(GLcontext *context, const GLdouble * m);
EXPORT void cwcglLoadTransposeMatrixdARB(GLcontext *context, const GLdouble * m);
EXPORT void cwcglLoadTransposeMatrixf(GLcontext *context, const GLfloat * m);
EXPORT void cwcglLoadTransposeMatrixfARB(GLcontext *context, const GLfloat * m);
EXPORT void cwcglLoadTransposeMatrixxOES(GLcontext *context, const GLfixed * m);
EXPORT void cwcglLockArraysEXT(GLcontext *context, GLint first, GLsizei count);
EXPORT void cwcglLogicOp(GLcontext *context, GLenum opcode);
EXPORT void cwcglMakeBufferNonResidentNV(GLcontext *context, GLenum target);
EXPORT void cwcglMakeBufferResidentNV(GLcontext *context, GLenum target, GLenum access);
EXPORT void cwcglMakeImageHandleNonResidentARB(GLcontext *context, GLuint64 handle);
EXPORT void cwcglMakeImageHandleNonResidentNV(GLcontext *context, GLuint64 handle);
EXPORT void cwcglMakeImageHandleResidentARB(GLcontext *context, GLuint64 handle, GLenum access);
EXPORT void cwcglMakeImageHandleResidentNV(GLcontext *context, GLuint64 handle, GLenum access);
EXPORT void cwcglMakeNamedBufferNonResidentNV(GLcontext *context, GLuint buffer);
EXPORT void cwcglMakeNamedBufferResidentNV(GLcontext *context, GLuint buffer, GLenum access);
EXPORT void cwcglMakeTextureHandleNonResidentARB(GLcontext *context, GLuint64 handle);
EXPORT void cwcglMakeTextureHandleNonResidentNV(GLcontext *context, GLuint64 handle);
EXPORT void cwcglMakeTextureHandleResidentARB(GLcontext *context, GLuint64 handle);
EXPORT void cwcglMakeTextureHandleResidentNV(GLcontext *context, GLuint64 handle);
EXPORT void cwcglMap1d(GLcontext *context, GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points);
EXPORT void cwcglMap1f(GLcontext *context, GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points);
EXPORT void cwcglMap1xOES(GLcontext *context, GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points);
EXPORT void cwcglMap2d(GLcontext *context, GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points);
EXPORT void cwcglMap2f(GLcontext *context, GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points);
EXPORT void cwcglMap2xOES(GLcontext *context, GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points);
EXPORT void cwcglMapBuffer(GLcontext *context, GLenum target, GLenum access, void ** return_value);
EXPORT void cwcglMapBufferARB(GLcontext *context, GLenum target, GLenum access, void ** return_value);
EXPORT void cwcglMapBufferOES(GLcontext *context, GLenum target, GLenum access, void ** return_value);
EXPORT void cwcglMapBufferRange(GLcontext *context, GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access, void ** return_value);
EXPORT void cwcglMapBufferRangeEXT(GLcontext *context, GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access, void ** return_value);
EXPORT void cwcglMapControlPointsNV(GLcontext *context, GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const void * points);
EXPORT void cwcglMapGrid1d(GLcontext *context, GLint un, GLdouble u1, GLdouble u2);
EXPORT void cwcglMapGrid1f(GLcontext *context, GLint un, GLfloat u1, GLfloat u2);
EXPORT void cwcglMapGrid1xOES(GLcontext *context, GLint n, GLfixed u1, GLfixed u2);
EXPORT void cwcglMapGrid2d(GLcontext *context, GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
EXPORT void cwcglMapGrid2f(GLcontext *context, GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
EXPORT void cwcglMapGrid2xOES(GLcontext *context, GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2);
EXPORT void cwcglMapNamedBuffer(GLcontext *context, GLuint buffer, GLenum access, void ** return_value);
EXPORT void cwcglMapNamedBufferEXT(GLcontext *context, GLuint buffer, GLenum access, void ** return_value);
EXPORT void cwcglMapNamedBufferRange(GLcontext *context, GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access, void ** return_value);
EXPORT void cwcglMapNamedBufferRangeEXT(GLcontext *context, GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access, void ** return_value);
EXPORT void cwcglMapObjectBufferATI(GLcontext *context, GLuint buffer, void ** return_value);
EXPORT void cwcglMapParameterfvNV(GLcontext *context, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglMapParameterivNV(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglMapTexture2DINTEL(GLcontext *context, GLuint texture, GLint level, GLbitfield access, GLint * stride, GLenum * layout, void ** return_value);
EXPORT void cwcglMapVertexAttrib1dAPPLE(GLcontext *context, GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points);
EXPORT void cwcglMapVertexAttrib1fAPPLE(GLcontext *context, GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points);
EXPORT void cwcglMapVertexAttrib2dAPPLE(GLcontext *context, GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points);
EXPORT void cwcglMapVertexAttrib2fAPPLE(GLcontext *context, GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points);
EXPORT void cwcglMaterialf(GLcontext *context, GLenum face, GLenum pname, GLfloat param);
EXPORT void cwcglMaterialfv(GLcontext *context, GLenum face, GLenum pname, const GLfloat * params);
EXPORT void cwcglMateriali(GLcontext *context, GLenum face, GLenum pname, GLint param);
EXPORT void cwcglMaterialiv(GLcontext *context, GLenum face, GLenum pname, const GLint * params);
EXPORT void cwcglMaterialx(GLcontext *context, GLenum face, GLenum pname, GLfixed param);
EXPORT void cwcglMaterialxOES(GLcontext *context, GLenum face, GLenum pname, GLfixed param);
EXPORT void cwcglMaterialxv(GLcontext *context, GLenum face, GLenum pname, const GLfixed * param);
EXPORT void cwcglMaterialxvOES(GLcontext *context, GLenum face, GLenum pname, const GLfixed * param);
EXPORT void cwcglMatrixFrustumEXT(GLcontext *context, GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
EXPORT void cwcglMatrixIndexPointerARB(GLcontext *context, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglMatrixIndexPointerOES(GLcontext *context, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglMatrixIndexubvARB(GLcontext *context, GLint size, const GLubyte * indices);
EXPORT void cwcglMatrixIndexuivARB(GLcontext *context, GLint size, const GLuint * indices);
EXPORT void cwcglMatrixIndexusvARB(GLcontext *context, GLint size, const GLushort * indices);
EXPORT void cwcglMatrixLoad3x2fNV(GLcontext *context, GLenum matrixMode, const GLfloat * m);
EXPORT void cwcglMatrixLoad3x3fNV(GLcontext *context, GLenum matrixMode, const GLfloat * m);
EXPORT void cwcglMatrixLoadIdentityEXT(GLcontext *context, GLenum mode);
EXPORT void cwcglMatrixLoadTranspose3x3fNV(GLcontext *context, GLenum matrixMode, const GLfloat * m);
EXPORT void cwcglMatrixLoadTransposedEXT(GLcontext *context, GLenum mode, const GLdouble * m);
EXPORT void cwcglMatrixLoadTransposefEXT(GLcontext *context, GLenum mode, const GLfloat * m);
EXPORT void cwcglMatrixLoaddEXT(GLcontext *context, GLenum mode, const GLdouble * m);
EXPORT void cwcglMatrixLoadfEXT(GLcontext *context, GLenum mode, const GLfloat * m);
EXPORT void cwcglMatrixMode(GLcontext *context, GLenum mode);
EXPORT void cwcglMatrixMult3x2fNV(GLcontext *context, GLenum matrixMode, const GLfloat * m);
EXPORT void cwcglMatrixMult3x3fNV(GLcontext *context, GLenum matrixMode, const GLfloat * m);
EXPORT void cwcglMatrixMultTranspose3x3fNV(GLcontext *context, GLenum matrixMode, const GLfloat * m);
EXPORT void cwcglMatrixMultTransposedEXT(GLcontext *context, GLenum mode, const GLdouble * m);
EXPORT void cwcglMatrixMultTransposefEXT(GLcontext *context, GLenum mode, const GLfloat * m);
EXPORT void cwcglMatrixMultdEXT(GLcontext *context, GLenum mode, const GLdouble * m);
EXPORT void cwcglMatrixMultfEXT(GLcontext *context, GLenum mode, const GLfloat * m);
EXPORT void cwcglMatrixOrthoEXT(GLcontext *context, GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
EXPORT void cwcglMatrixPopEXT(GLcontext *context, GLenum mode);
EXPORT void cwcglMatrixPushEXT(GLcontext *context, GLenum mode);
EXPORT void cwcglMatrixRotatedEXT(GLcontext *context, GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglMatrixRotatefEXT(GLcontext *context, GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglMatrixScaledEXT(GLcontext *context, GLenum mode, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglMatrixScalefEXT(GLcontext *context, GLenum mode, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglMatrixTranslatedEXT(GLcontext *context, GLenum mode, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglMatrixTranslatefEXT(GLcontext *context, GLenum mode, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglMaxShaderCompilerThreadsARB(GLcontext *context, GLuint count);
EXPORT void cwcglMemoryBarrier(GLcontext *context, GLbitfield barriers);
EXPORT void cwcglMemoryBarrierByRegion(GLcontext *context, GLbitfield barriers);
EXPORT void cwcglMemoryBarrierEXT(GLcontext *context, GLbitfield barriers);
EXPORT void cwcglMinSampleShading(GLcontext *context, GLfloat value);
EXPORT void cwcglMinSampleShadingARB(GLcontext *context, GLfloat value);
EXPORT void cwcglMinSampleShadingOES(GLcontext *context, GLfloat value);
EXPORT void cwcglMinmax(GLcontext *context, GLenum target, GLenum internalformat, GLboolean sink);
EXPORT void cwcglMinmaxEXT(GLcontext *context, GLenum target, GLenum internalformat, GLboolean sink);
EXPORT void cwcglMultMatrixd(GLcontext *context, const GLdouble * m);
EXPORT void cwcglMultMatrixf(GLcontext *context, const GLfloat * m);
EXPORT void cwcglMultMatrixx(GLcontext *context, const GLfixed * m);
EXPORT void cwcglMultMatrixxOES(GLcontext *context, const GLfixed * m);
EXPORT void cwcglMultTransposeMatrixd(GLcontext *context, const GLdouble * m);
EXPORT void cwcglMultTransposeMatrixdARB(GLcontext *context, const GLdouble * m);
EXPORT void cwcglMultTransposeMatrixf(GLcontext *context, const GLfloat * m);
EXPORT void cwcglMultTransposeMatrixfARB(GLcontext *context, const GLfloat * m);
EXPORT void cwcglMultTransposeMatrixxOES(GLcontext *context, const GLfixed * m);
EXPORT void cwcglMultiDrawArrays(GLcontext *context, GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
EXPORT void cwcglMultiDrawArraysEXT(GLcontext *context, GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount);
EXPORT void cwcglMultiDrawArraysIndirect(GLcontext *context, GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
EXPORT void cwcglMultiDrawArraysIndirectAMD(GLcontext *context, GLenum mode, const void * indirect, GLsizei primcount, GLsizei stride);
EXPORT void cwcglMultiDrawArraysIndirectBindlessCountNV(GLcontext *context, GLenum mode, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
EXPORT void cwcglMultiDrawArraysIndirectBindlessNV(GLcontext *context, GLenum mode, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
EXPORT void cwcglMultiDrawArraysIndirectCountARB(GLcontext *context, GLenum mode, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
EXPORT void cwcglMultiDrawArraysIndirectEXT(GLcontext *context, GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
EXPORT void cwcglMultiDrawElementArrayAPPLE(GLcontext *context, GLenum mode, const GLint * first, const GLsizei * count, GLsizei primcount);
EXPORT void cwcglMultiDrawElements(GLcontext *context, GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount);
EXPORT void cwcglMultiDrawElementsBaseVertex(GLcontext *context, GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex);
EXPORT void cwcglMultiDrawElementsBaseVertexEXT(GLcontext *context, GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei primcount, const GLint * basevertex);
EXPORT void cwcglMultiDrawElementsBaseVertexOES(GLcontext *context, GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei primcount, const GLint * basevertex);
EXPORT void cwcglMultiDrawElementsEXT(GLcontext *context, GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei primcount);
EXPORT void cwcglMultiDrawElementsIndirect(GLcontext *context, GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
EXPORT void cwcglMultiDrawElementsIndirectAMD(GLcontext *context, GLenum mode, GLenum type, const void * indirect, GLsizei primcount, GLsizei stride);
EXPORT void cwcglMultiDrawElementsIndirectBindlessCountNV(GLcontext *context, GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
EXPORT void cwcglMultiDrawElementsIndirectBindlessNV(GLcontext *context, GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
EXPORT void cwcglMultiDrawElementsIndirectCountARB(GLcontext *context, GLenum mode, GLenum type, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
EXPORT void cwcglMultiDrawElementsIndirectEXT(GLcontext *context, GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
EXPORT void cwcglMultiDrawRangeElementArrayAPPLE(GLcontext *context, GLenum mode, GLuint start, GLuint end, const GLint * first, const GLsizei * count, GLsizei primcount);
EXPORT void cwcglMultiModeDrawArraysIBM(GLcontext *context, const GLenum * mode, const GLint * first, const GLsizei * count, GLsizei primcount, GLint modestride);
EXPORT void cwcglMultiModeDrawElementsIBM(GLcontext *context, const GLenum * mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei primcount, GLint modestride);
EXPORT void cwcglMultiTexBufferEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
EXPORT void cwcglMultiTexCoord1bOES(GLcontext *context, GLenum texture, GLbyte s);
EXPORT void cwcglMultiTexCoord1bvOES(GLcontext *context, GLenum texture, const GLbyte * coords);
EXPORT void cwcglMultiTexCoord1d(GLcontext *context, GLenum target, GLdouble s);
EXPORT void cwcglMultiTexCoord1dARB(GLcontext *context, GLenum target, GLdouble s);
EXPORT void cwcglMultiTexCoord1dv(GLcontext *context, GLenum target, const GLdouble * v);
EXPORT void cwcglMultiTexCoord1dvARB(GLcontext *context, GLenum target, const GLdouble * v);
EXPORT void cwcglMultiTexCoord1f(GLcontext *context, GLenum target, GLfloat s);
EXPORT void cwcglMultiTexCoord1fARB(GLcontext *context, GLenum target, GLfloat s);
EXPORT void cwcglMultiTexCoord1fv(GLcontext *context, GLenum target, const GLfloat * v);
EXPORT void cwcglMultiTexCoord1fvARB(GLcontext *context, GLenum target, const GLfloat * v);
EXPORT void cwcglMultiTexCoord1hNV(GLcontext *context, GLenum target, GLhalfNV s);
EXPORT void cwcglMultiTexCoord1hvNV(GLcontext *context, GLenum target, const GLhalfNV * v);
EXPORT void cwcglMultiTexCoord1i(GLcontext *context, GLenum target, GLint s);
EXPORT void cwcglMultiTexCoord1iARB(GLcontext *context, GLenum target, GLint s);
EXPORT void cwcglMultiTexCoord1iv(GLcontext *context, GLenum target, const GLint * v);
EXPORT void cwcglMultiTexCoord1ivARB(GLcontext *context, GLenum target, const GLint * v);
EXPORT void cwcglMultiTexCoord1s(GLcontext *context, GLenum target, GLshort s);
EXPORT void cwcglMultiTexCoord1sARB(GLcontext *context, GLenum target, GLshort s);
EXPORT void cwcglMultiTexCoord1sv(GLcontext *context, GLenum target, const GLshort * v);
EXPORT void cwcglMultiTexCoord1svARB(GLcontext *context, GLenum target, const GLshort * v);
EXPORT void cwcglMultiTexCoord1xOES(GLcontext *context, GLenum texture, GLfixed s);
EXPORT void cwcglMultiTexCoord1xvOES(GLcontext *context, GLenum texture, const GLfixed * coords);
EXPORT void cwcglMultiTexCoord2bOES(GLcontext *context, GLenum texture, GLbyte s, GLbyte t);
EXPORT void cwcglMultiTexCoord2bvOES(GLcontext *context, GLenum texture, const GLbyte * coords);
EXPORT void cwcglMultiTexCoord2d(GLcontext *context, GLenum target, GLdouble s, GLdouble t);
EXPORT void cwcglMultiTexCoord2dARB(GLcontext *context, GLenum target, GLdouble s, GLdouble t);
EXPORT void cwcglMultiTexCoord2dv(GLcontext *context, GLenum target, const GLdouble * v);
EXPORT void cwcglMultiTexCoord2dvARB(GLcontext *context, GLenum target, const GLdouble * v);
EXPORT void cwcglMultiTexCoord2f(GLcontext *context, GLenum target, GLfloat s, GLfloat t);
EXPORT void cwcglMultiTexCoord2fARB(GLcontext *context, GLenum target, GLfloat s, GLfloat t);
EXPORT void cwcglMultiTexCoord2fv(GLcontext *context, GLenum target, const GLfloat * v);
EXPORT void cwcglMultiTexCoord2fvARB(GLcontext *context, GLenum target, const GLfloat * v);
EXPORT void cwcglMultiTexCoord2hNV(GLcontext *context, GLenum target, GLhalfNV s, GLhalfNV t);
EXPORT void cwcglMultiTexCoord2hvNV(GLcontext *context, GLenum target, const GLhalfNV * v);
EXPORT void cwcglMultiTexCoord2i(GLcontext *context, GLenum target, GLint s, GLint t);
EXPORT void cwcglMultiTexCoord2iARB(GLcontext *context, GLenum target, GLint s, GLint t);
EXPORT void cwcglMultiTexCoord2iv(GLcontext *context, GLenum target, const GLint * v);
EXPORT void cwcglMultiTexCoord2ivARB(GLcontext *context, GLenum target, const GLint * v);
EXPORT void cwcglMultiTexCoord2s(GLcontext *context, GLenum target, GLshort s, GLshort t);
EXPORT void cwcglMultiTexCoord2sARB(GLcontext *context, GLenum target, GLshort s, GLshort t);
EXPORT void cwcglMultiTexCoord2sv(GLcontext *context, GLenum target, const GLshort * v);
EXPORT void cwcglMultiTexCoord2svARB(GLcontext *context, GLenum target, const GLshort * v);
EXPORT void cwcglMultiTexCoord2xOES(GLcontext *context, GLenum texture, GLfixed s, GLfixed t);
EXPORT void cwcglMultiTexCoord2xvOES(GLcontext *context, GLenum texture, const GLfixed * coords);
EXPORT void cwcglMultiTexCoord3bOES(GLcontext *context, GLenum texture, GLbyte s, GLbyte t, GLbyte r);
EXPORT void cwcglMultiTexCoord3bvOES(GLcontext *context, GLenum texture, const GLbyte * coords);
EXPORT void cwcglMultiTexCoord3d(GLcontext *context, GLenum target, GLdouble s, GLdouble t, GLdouble r);
EXPORT void cwcglMultiTexCoord3dARB(GLcontext *context, GLenum target, GLdouble s, GLdouble t, GLdouble r);
EXPORT void cwcglMultiTexCoord3dv(GLcontext *context, GLenum target, const GLdouble * v);
EXPORT void cwcglMultiTexCoord3dvARB(GLcontext *context, GLenum target, const GLdouble * v);
EXPORT void cwcglMultiTexCoord3f(GLcontext *context, GLenum target, GLfloat s, GLfloat t, GLfloat r);
EXPORT void cwcglMultiTexCoord3fARB(GLcontext *context, GLenum target, GLfloat s, GLfloat t, GLfloat r);
EXPORT void cwcglMultiTexCoord3fv(GLcontext *context, GLenum target, const GLfloat * v);
EXPORT void cwcglMultiTexCoord3fvARB(GLcontext *context, GLenum target, const GLfloat * v);
EXPORT void cwcglMultiTexCoord3hNV(GLcontext *context, GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
EXPORT void cwcglMultiTexCoord3hvNV(GLcontext *context, GLenum target, const GLhalfNV * v);
EXPORT void cwcglMultiTexCoord3i(GLcontext *context, GLenum target, GLint s, GLint t, GLint r);
EXPORT void cwcglMultiTexCoord3iARB(GLcontext *context, GLenum target, GLint s, GLint t, GLint r);
EXPORT void cwcglMultiTexCoord3iv(GLcontext *context, GLenum target, const GLint * v);
EXPORT void cwcglMultiTexCoord3ivARB(GLcontext *context, GLenum target, const GLint * v);
EXPORT void cwcglMultiTexCoord3s(GLcontext *context, GLenum target, GLshort s, GLshort t, GLshort r);
EXPORT void cwcglMultiTexCoord3sARB(GLcontext *context, GLenum target, GLshort s, GLshort t, GLshort r);
EXPORT void cwcglMultiTexCoord3sv(GLcontext *context, GLenum target, const GLshort * v);
EXPORT void cwcglMultiTexCoord3svARB(GLcontext *context, GLenum target, const GLshort * v);
EXPORT void cwcglMultiTexCoord3xOES(GLcontext *context, GLenum texture, GLfixed s, GLfixed t, GLfixed r);
EXPORT void cwcglMultiTexCoord3xvOES(GLcontext *context, GLenum texture, const GLfixed * coords);
EXPORT void cwcglMultiTexCoord4bOES(GLcontext *context, GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q);
EXPORT void cwcglMultiTexCoord4bvOES(GLcontext *context, GLenum texture, const GLbyte * coords);
EXPORT void cwcglMultiTexCoord4d(GLcontext *context, GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
EXPORT void cwcglMultiTexCoord4dARB(GLcontext *context, GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
EXPORT void cwcglMultiTexCoord4dv(GLcontext *context, GLenum target, const GLdouble * v);
EXPORT void cwcglMultiTexCoord4dvARB(GLcontext *context, GLenum target, const GLdouble * v);
EXPORT void cwcglMultiTexCoord4f(GLcontext *context, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
EXPORT void cwcglMultiTexCoord4fARB(GLcontext *context, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
EXPORT void cwcglMultiTexCoord4fv(GLcontext *context, GLenum target, const GLfloat * v);
EXPORT void cwcglMultiTexCoord4fvARB(GLcontext *context, GLenum target, const GLfloat * v);
EXPORT void cwcglMultiTexCoord4hNV(GLcontext *context, GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
EXPORT void cwcglMultiTexCoord4hvNV(GLcontext *context, GLenum target, const GLhalfNV * v);
EXPORT void cwcglMultiTexCoord4i(GLcontext *context, GLenum target, GLint s, GLint t, GLint r, GLint q);
EXPORT void cwcglMultiTexCoord4iARB(GLcontext *context, GLenum target, GLint s, GLint t, GLint r, GLint q);
EXPORT void cwcglMultiTexCoord4iv(GLcontext *context, GLenum target, const GLint * v);
EXPORT void cwcglMultiTexCoord4ivARB(GLcontext *context, GLenum target, const GLint * v);
EXPORT void cwcglMultiTexCoord4s(GLcontext *context, GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
EXPORT void cwcglMultiTexCoord4sARB(GLcontext *context, GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
EXPORT void cwcglMultiTexCoord4sv(GLcontext *context, GLenum target, const GLshort * v);
EXPORT void cwcglMultiTexCoord4svARB(GLcontext *context, GLenum target, const GLshort * v);
EXPORT void cwcglMultiTexCoord4x(GLcontext *context, GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
EXPORT void cwcglMultiTexCoord4xOES(GLcontext *context, GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
EXPORT void cwcglMultiTexCoord4xvOES(GLcontext *context, GLenum texture, const GLfixed * coords);
EXPORT void cwcglMultiTexCoordP1ui(GLcontext *context, GLenum texture, GLenum type, GLuint coords);
EXPORT void cwcglMultiTexCoordP1uiv(GLcontext *context, GLenum texture, GLenum type, const GLuint * coords);
EXPORT void cwcglMultiTexCoordP2ui(GLcontext *context, GLenum texture, GLenum type, GLuint coords);
EXPORT void cwcglMultiTexCoordP2uiv(GLcontext *context, GLenum texture, GLenum type, const GLuint * coords);
EXPORT void cwcglMultiTexCoordP3ui(GLcontext *context, GLenum texture, GLenum type, GLuint coords);
EXPORT void cwcglMultiTexCoordP3uiv(GLcontext *context, GLenum texture, GLenum type, const GLuint * coords);
EXPORT void cwcglMultiTexCoordP4ui(GLcontext *context, GLenum texture, GLenum type, GLuint coords);
EXPORT void cwcglMultiTexCoordP4uiv(GLcontext *context, GLenum texture, GLenum type, const GLuint * coords);
EXPORT void cwcglMultiTexCoordPointerEXT(GLcontext *context, GLenum texunit, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglMultiTexEnvfEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, GLfloat param);
EXPORT void cwcglMultiTexEnvfvEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglMultiTexEnviEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, GLint param);
EXPORT void cwcglMultiTexEnvivEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglMultiTexGendEXT(GLcontext *context, GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
EXPORT void cwcglMultiTexGendvEXT(GLcontext *context, GLenum texunit, GLenum coord, GLenum pname, const GLdouble * params);
EXPORT void cwcglMultiTexGenfEXT(GLcontext *context, GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
EXPORT void cwcglMultiTexGenfvEXT(GLcontext *context, GLenum texunit, GLenum coord, GLenum pname, const GLfloat * params);
EXPORT void cwcglMultiTexGeniEXT(GLcontext *context, GLenum texunit, GLenum coord, GLenum pname, GLint param);
EXPORT void cwcglMultiTexGenivEXT(GLcontext *context, GLenum texunit, GLenum coord, GLenum pname, const GLint * params);
EXPORT void cwcglMultiTexImage1DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglMultiTexImage2DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglMultiTexImage3DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglMultiTexParameterIivEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglMultiTexParameterIuivEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, const GLuint * params);
EXPORT void cwcglMultiTexParameterfEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, GLfloat param);
EXPORT void cwcglMultiTexParameterfvEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglMultiTexParameteriEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, GLint param);
EXPORT void cwcglMultiTexParameterivEXT(GLcontext *context, GLenum texunit, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglMultiTexRenderbufferEXT(GLcontext *context, GLenum texunit, GLenum target, GLuint renderbuffer);
EXPORT void cwcglMultiTexSubImage1DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglMultiTexSubImage2DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglMultiTexSubImage3DEXT(GLcontext *context, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglNamedBufferData(GLcontext *context, GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
EXPORT void cwcglNamedBufferDataEXT(GLcontext *context, GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
EXPORT void cwcglNamedBufferPageCommitmentARB(GLcontext *context, GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
EXPORT void cwcglNamedBufferPageCommitmentEXT(GLcontext *context, GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
EXPORT void cwcglNamedBufferStorage(GLcontext *context, GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
EXPORT void cwcglNamedBufferStorageEXT(GLcontext *context, GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
EXPORT void cwcglNamedBufferSubData(GLcontext *context, GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
EXPORT void cwcglNamedBufferSubDataEXT(GLcontext *context, GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
EXPORT void cwcglNamedCopyBufferSubDataEXT(GLcontext *context, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
EXPORT void cwcglNamedFramebufferDrawBuffer(GLcontext *context, GLuint framebuffer, GLenum buf);
EXPORT void cwcglNamedFramebufferDrawBuffers(GLcontext *context, GLuint framebuffer, GLsizei n, const GLenum * bufs);
EXPORT void cwcglNamedFramebufferParameteri(GLcontext *context, GLuint framebuffer, GLenum pname, GLint param);
EXPORT void cwcglNamedFramebufferParameteriEXT(GLcontext *context, GLuint framebuffer, GLenum pname, GLint param);
EXPORT void cwcglNamedFramebufferReadBuffer(GLcontext *context, GLuint framebuffer, GLenum src);
EXPORT void cwcglNamedFramebufferRenderbuffer(GLcontext *context, GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
EXPORT void cwcglNamedFramebufferRenderbufferEXT(GLcontext *context, GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
EXPORT void cwcglNamedFramebufferSampleLocationsfvARB(GLcontext *context, GLuint framebuffer, GLuint start, GLsizei count, const GLfloat * v);
EXPORT void cwcglNamedFramebufferSampleLocationsfvNV(GLcontext *context, GLuint framebuffer, GLuint start, GLsizei count, const GLfloat * v);
EXPORT void cwcglNamedFramebufferTexture(GLcontext *context, GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
EXPORT void cwcglNamedFramebufferSamplePositionsfvAMD(GLcontext *context, GLuint framebuffer, GLuint numsamples, GLuint pixelindex, const GLfloat * values);
EXPORT void cwcglNamedFramebufferTexture1DEXT(GLcontext *context, GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
EXPORT void cwcglNamedFramebufferTexture2DEXT(GLcontext *context, GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
EXPORT void cwcglNamedFramebufferTexture3DEXT(GLcontext *context, GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
EXPORT void cwcglNamedFramebufferTextureEXT(GLcontext *context, GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
EXPORT void cwcglNamedFramebufferTextureFaceEXT(GLcontext *context, GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
EXPORT void cwcglNamedFramebufferTextureLayer(GLcontext *context, GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
EXPORT void cwcglNamedFramebufferTextureLayerEXT(GLcontext *context, GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
EXPORT void cwcglNamedProgramLocalParameter4dEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglNamedProgramLocalParameter4dvEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, const GLdouble * params);
EXPORT void cwcglNamedProgramLocalParameter4fEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglNamedProgramLocalParameter4fvEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, const GLfloat * params);
EXPORT void cwcglNamedProgramLocalParameterI4iEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
EXPORT void cwcglNamedProgramLocalParameterI4ivEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, const GLint * params);
EXPORT void cwcglNamedProgramLocalParameterI4uiEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
EXPORT void cwcglNamedProgramLocalParameterI4uivEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, const GLuint * params);
EXPORT void cwcglNamedProgramLocalParameters4fvEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat * params);
EXPORT void cwcglNamedProgramLocalParametersI4ivEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, GLsizei count, const GLint * params);
EXPORT void cwcglNamedProgramLocalParametersI4uivEXT(GLcontext *context, GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint * params);
EXPORT void cwcglNamedProgramStringEXT(GLcontext *context, GLuint program, GLenum target, GLenum format, GLsizei len, const void * string);
EXPORT void cwcglNamedRenderbufferStorage(GLcontext *context, GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglNamedRenderbufferStorageEXT(GLcontext *context, GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglNamedRenderbufferStorageMultisample(GLcontext *context, GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglNamedRenderbufferStorageMultisampleCoverageEXT(GLcontext *context, GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglNamedRenderbufferStorageMultisampleEXT(GLcontext *context, GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglNamedStringARB(GLcontext *context, GLenum type, GLint namelen, const GLchar * name, GLint stringlen, const GLchar * string);
EXPORT void cwcglNewList(GLcontext *context, GLuint list, GLenum mode);
EXPORT void cwcglNewObjectBufferATI(GLcontext *context, GLsizei size, const void * pointer, GLenum usage, GLuint* return_value);
EXPORT void cwcglNormal3b(GLcontext *context, GLbyte nx, GLbyte ny, GLbyte nz);
EXPORT void cwcglNormal3bv(GLcontext *context, const GLbyte * v);
EXPORT void cwcglNormal3d(GLcontext *context, GLdouble nx, GLdouble ny, GLdouble nz);
EXPORT void cwcglNormal3dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglNormal3f(GLcontext *context, GLfloat nx, GLfloat ny, GLfloat nz);
EXPORT void cwcglNormal3fVertex3fSUN(GLcontext *context, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglNormal3fVertex3fvSUN(GLcontext *context, const GLfloat * n, const GLfloat * v);
EXPORT void cwcglNormal3fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglNormal3hNV(GLcontext *context, GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
EXPORT void cwcglNormal3hvNV(GLcontext *context, const GLhalfNV * v);
EXPORT void cwcglNormal3i(GLcontext *context, GLint nx, GLint ny, GLint nz);
EXPORT void cwcglNormal3iv(GLcontext *context, const GLint * v);
EXPORT void cwcglNormal3s(GLcontext *context, GLshort nx, GLshort ny, GLshort nz);
EXPORT void cwcglNormal3sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglNormal3x(GLcontext *context, GLfixed nx, GLfixed ny, GLfixed nz);
EXPORT void cwcglNormal3xOES(GLcontext *context, GLfixed nx, GLfixed ny, GLfixed nz);
EXPORT void cwcglNormal3xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglNormalFormatNV(GLcontext *context, GLenum type, GLsizei stride);
EXPORT void cwcglNormalP3ui(GLcontext *context, GLenum type, GLuint coords);
EXPORT void cwcglNormalP3uiv(GLcontext *context, GLenum type, const GLuint * coords);
EXPORT void cwcglNormalPointer(GLcontext *context, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglNormalPointerEXT(GLcontext *context, GLenum type, GLsizei stride, GLsizei count, const void * pointer);
EXPORT void cwcglNormalPointerListIBM(GLcontext *context, GLenum type, GLint stride, const void ** pointer, GLint ptrstride);
EXPORT void cwcglNormalPointervINTEL(GLcontext *context, GLenum type, const void ** pointer);
EXPORT void cwcglNormalStream3bATI(GLcontext *context, GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
EXPORT void cwcglNormalStream3bvATI(GLcontext *context, GLenum stream, const GLbyte * coords);
EXPORT void cwcglNormalStream3dATI(GLcontext *context, GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
EXPORT void cwcglNormalStream3dvATI(GLcontext *context, GLenum stream, const GLdouble * coords);
EXPORT void cwcglNormalStream3fATI(GLcontext *context, GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
EXPORT void cwcglNormalStream3fvATI(GLcontext *context, GLenum stream, const GLfloat * coords);
EXPORT void cwcglNormalStream3iATI(GLcontext *context, GLenum stream, GLint nx, GLint ny, GLint nz);
EXPORT void cwcglNormalStream3ivATI(GLcontext *context, GLenum stream, const GLint * coords);
EXPORT void cwcglNormalStream3sATI(GLcontext *context, GLenum stream, GLshort nx, GLshort ny, GLshort nz);
EXPORT void cwcglNormalStream3svATI(GLcontext *context, GLenum stream, const GLshort * coords);
EXPORT void cwcglObjectLabel(GLcontext *context, GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
EXPORT void cwcglObjectLabelKHR(GLcontext *context, GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
EXPORT void cwcglObjectPtrLabel(GLcontext *context, const void * ptr, GLsizei length, const GLchar * label);
EXPORT void cwcglObjectPtrLabelKHR(GLcontext *context, const void * ptr, GLsizei length, const GLchar * label);
EXPORT void cwcglObjectPurgeableAPPLE(GLcontext *context, GLenum objectType, GLuint name, GLenum option, GLenum* return_value);
EXPORT void cwcglObjectUnpurgeableAPPLE(GLcontext *context, GLenum objectType, GLuint name, GLenum option, GLenum* return_value);
EXPORT void cwcglOrtho(GLcontext *context, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
EXPORT void cwcglOrthof(GLcontext *context, GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
EXPORT void cwcglOrthofOES(GLcontext *context, GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
EXPORT void cwcglOrthox(GLcontext *context, GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
EXPORT void cwcglOrthoxOES(GLcontext *context, GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
EXPORT void cwcglPNTrianglesfATI(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglPNTrianglesiATI(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglPassTexCoordATI(GLcontext *context, GLuint dst, GLuint coord, GLenum swizzle);
EXPORT void cwcglPassThrough(GLcontext *context, GLfloat token);
EXPORT void cwcglPassThroughxOES(GLcontext *context, GLfixed token);
EXPORT void cwcglPatchParameterfv(GLcontext *context, GLenum pname, const GLfloat * values);
EXPORT void cwcglPatchParameteri(GLcontext *context, GLenum pname, GLint value);
EXPORT void cwcglPatchParameteriEXT(GLcontext *context, GLenum pname, GLint value);
EXPORT void cwcglPatchParameteriOES(GLcontext *context, GLenum pname, GLint value);
EXPORT void cwcglPathColorGenNV(GLcontext *context, GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat * coeffs);
EXPORT void cwcglPathCommandsNV(GLcontext *context, GLuint path, GLsizei numCommands, const GLubyte * commands, GLsizei numCoords, GLenum coordType, const void * coords);
EXPORT void cwcglPathCoordsNV(GLcontext *context, GLuint path, GLsizei numCoords, GLenum coordType, const void * coords);
EXPORT void cwcglPathCoverDepthFuncNV(GLcontext *context, GLenum func);
EXPORT void cwcglPathDashArrayNV(GLcontext *context, GLuint path, GLsizei dashCount, const GLfloat * dashArray);
EXPORT void cwcglPathFogGenNV(GLcontext *context, GLenum genMode);
EXPORT void cwcglPathGlyphIndexArrayNV(GLcontext *context, GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale, GLenum* return_value);
EXPORT void cwcglPathGlyphIndexRangeNV(GLcontext *context, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount [2], GLenum* return_value);
EXPORT void cwcglPathGlyphRangeNV(GLcontext *context, GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
EXPORT void cwcglPathGlyphsNV(GLcontext *context, GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void * charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
EXPORT void cwcglPathMemoryGlyphIndexArrayNV(GLcontext *context, GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void * fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale, GLenum* return_value);
EXPORT void cwcglPathParameterfNV(GLcontext *context, GLuint path, GLenum pname, GLfloat value);
EXPORT void cwcglPathParameterfvNV(GLcontext *context, GLuint path, GLenum pname, const GLfloat * value);
EXPORT void cwcglPathParameteriNV(GLcontext *context, GLuint path, GLenum pname, GLint value);
EXPORT void cwcglPathParameterivNV(GLcontext *context, GLuint path, GLenum pname, const GLint * value);
EXPORT void cwcglPathStencilDepthOffsetNV(GLcontext *context, GLfloat factor, GLfloat units);
EXPORT void cwcglPathStencilFuncNV(GLcontext *context, GLenum func, GLint ref, GLuint mask);
EXPORT void cwcglPathStringNV(GLcontext *context, GLuint path, GLenum format, GLsizei length, const void * pathString);
EXPORT void cwcglPathSubCommandsNV(GLcontext *context, GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte * commands, GLsizei numCoords, GLenum coordType, const void * coords);
EXPORT void cwcglPathSubCoordsNV(GLcontext *context, GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void * coords);
EXPORT void cwcglPathTexGenNV(GLcontext *context, GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat * coeffs);
EXPORT void cwcglPauseTransformFeedback(GLcontext *context);
EXPORT void cwcglPauseTransformFeedbackNV(GLcontext *context);
EXPORT void cwcglPixelDataRangeNV(GLcontext *context, GLenum target, GLsizei length, const void * pointer);
EXPORT void cwcglPixelMapfv(GLcontext *context, GLenum map, GLsizei mapsize, const GLfloat * values);
EXPORT void cwcglPixelMapuiv(GLcontext *context, GLenum map, GLsizei mapsize, const GLuint * values);
EXPORT void cwcglPixelMapusv(GLcontext *context, GLenum map, GLsizei mapsize, const GLushort * values);
EXPORT void cwcglPixelMapx(GLcontext *context, GLenum map, GLint size, const GLfixed * values);
EXPORT void cwcglPixelStoref(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglPixelStorei(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglPixelStorex(GLcontext *context, GLenum pname, GLfixed param);
EXPORT void cwcglPixelTexGenParameterfSGIS(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglPixelTexGenParameterfvSGIS(GLcontext *context, GLenum pname, const GLfloat * params);
EXPORT void cwcglPixelTexGenParameteriSGIS(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglPixelTexGenParameterivSGIS(GLcontext *context, GLenum pname, const GLint * params);
EXPORT void cwcglPixelTexGenSGIX(GLcontext *context, GLenum mode);
EXPORT void cwcglPixelTransferf(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglPixelTransferi(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglPixelTransferxOES(GLcontext *context, GLenum pname, GLfixed param);
EXPORT void cwcglPixelTransformParameterfEXT(GLcontext *context, GLenum target, GLenum pname, GLfloat param);
EXPORT void cwcglPixelTransformParameterfvEXT(GLcontext *context, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglPixelTransformParameteriEXT(GLcontext *context, GLenum target, GLenum pname, GLint param);
EXPORT void cwcglPixelTransformParameterivEXT(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglPixelZoom(GLcontext *context, GLfloat xfactor, GLfloat yfactor);
EXPORT void cwcglPixelZoomxOES(GLcontext *context, GLfixed xfactor, GLfixed yfactor);
EXPORT void cwcglPointAlongPathNV(GLcontext *context, GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat * x, GLfloat * y, GLfloat * tangentX, GLfloat * tangentY, GLboolean* return_value);
EXPORT void cwcglPointParameterf(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglPointParameterfARB(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglPointParameterfEXT(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglPointParameterfSGIS(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglPointParameterfv(GLcontext *context, GLenum pname, const GLfloat * params);
EXPORT void cwcglPointParameterfvARB(GLcontext *context, GLenum pname, const GLfloat * params);
EXPORT void cwcglPointParameterfvEXT(GLcontext *context, GLenum pname, const GLfloat * params);
EXPORT void cwcglPointParameterfvSGIS(GLcontext *context, GLenum pname, const GLfloat * params);
EXPORT void cwcglPointParameteri(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglPointParameteriNV(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglPointParameteriv(GLcontext *context, GLenum pname, const GLint * params);
EXPORT void cwcglPointParameterivNV(GLcontext *context, GLenum pname, const GLint * params);
EXPORT void cwcglPointParameterx(GLcontext *context, GLenum pname, GLfixed param);
EXPORT void cwcglPointParameterxOES(GLcontext *context, GLenum pname, GLfixed param);
EXPORT void cwcglPointParameterxv(GLcontext *context, GLenum pname, const GLfixed * params);
EXPORT void cwcglPointParameterxvOES(GLcontext *context, GLenum pname, const GLfixed * params);
EXPORT void cwcglPointSize(GLcontext *context, GLfloat size);
EXPORT void cwcglPointSizePointerOES(GLcontext *context, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglPointSizex(GLcontext *context, GLfixed size);
EXPORT void cwcglPointSizexOES(GLcontext *context, GLfixed size);
EXPORT void cwcglPollAsyncSGIX(GLcontext *context, GLuint * markerp, GLint* return_value);
EXPORT void cwcglPollInstrumentsSGIX(GLcontext *context, GLint * marker_p, GLint* return_value);
EXPORT void cwcglPolygonMode(GLcontext *context, GLenum face, GLenum mode);
EXPORT void cwcglPolygonModeNV(GLcontext *context, GLenum face, GLenum mode);
EXPORT void cwcglPolygonOffset(GLcontext *context, GLfloat factor, GLfloat units);
EXPORT void cwcglPolygonOffsetClampEXT(GLcontext *context, GLfloat factor, GLfloat units, GLfloat clamp);
EXPORT void cwcglPolygonOffsetEXT(GLcontext *context, GLfloat factor, GLfloat bias);
EXPORT void cwcglPolygonOffsetx(GLcontext *context, GLfixed factor, GLfixed units);
EXPORT void cwcglPolygonOffsetxOES(GLcontext *context, GLfixed factor, GLfixed units);
EXPORT void cwcglPolygonStipple(GLcontext *context, const GLubyte * mask);
EXPORT void cwcglPopAttrib(GLcontext *context);
EXPORT void cwcglPopClientAttrib(GLcontext *context);
EXPORT void cwcglPopDebugGroup(GLcontext *context);
EXPORT void cwcglPopDebugGroupKHR(GLcontext *context);
EXPORT void cwcglPopGroupMarkerEXT(GLcontext *context);
EXPORT void cwcglPopMatrix(GLcontext *context);
EXPORT void cwcglPopName(GLcontext *context);
EXPORT void cwcglPresentFrameDualFillNV(GLcontext *context, GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
EXPORT void cwcglPresentFrameKeyedNV(GLcontext *context, GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
EXPORT void cwcglPrimitiveBoundingBox(GLcontext *context, GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
EXPORT void cwcglPrimitiveBoundingBoxARB(GLcontext *context, GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
EXPORT void cwcglPrimitiveBoundingBoxEXT(GLcontext *context, GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
EXPORT void cwcglPrimitiveBoundingBoxOES(GLcontext *context, GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
EXPORT void cwcglPrimitiveRestartIndex(GLcontext *context, GLuint index);
EXPORT void cwcglPrimitiveRestartIndexNV(GLcontext *context, GLuint index);
EXPORT void cwcglPrimitiveRestartNV(GLcontext *context);
EXPORT void cwcglPrioritizeTextures(GLcontext *context, GLsizei n, const GLuint * textures, const GLfloat * priorities);
EXPORT void cwcglPrioritizeTexturesEXT(GLcontext *context, GLsizei n, const GLuint * textures, const GLclampf * priorities);
EXPORT void cwcglPrioritizeTexturesxOES(GLcontext *context, GLsizei n, const GLuint * textures, const GLfixed * priorities);
EXPORT void cwcglProgramBinary(GLcontext *context, GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
EXPORT void cwcglProgramBinaryOES(GLcontext *context, GLuint program, GLenum binaryFormat, const void * binary, GLint length);
EXPORT void cwcglProgramBufferParametersIivNV(GLcontext *context, GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLint * params);
EXPORT void cwcglProgramBufferParametersIuivNV(GLcontext *context, GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLuint * params);
EXPORT void cwcglProgramBufferParametersfvNV(GLcontext *context, GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLfloat * params);
EXPORT void cwcglProgramEnvParameter4dARB(GLcontext *context, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglProgramEnvParameter4dvARB(GLcontext *context, GLenum target, GLuint index, const GLdouble * params);
EXPORT void cwcglProgramEnvParameter4fARB(GLcontext *context, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglProgramEnvParameter4fvARB(GLcontext *context, GLenum target, GLuint index, const GLfloat * params);
EXPORT void cwcglProgramEnvParameterI4iNV(GLcontext *context, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
EXPORT void cwcglProgramEnvParameterI4ivNV(GLcontext *context, GLenum target, GLuint index, const GLint * params);
EXPORT void cwcglProgramEnvParameterI4uiNV(GLcontext *context, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
EXPORT void cwcglProgramEnvParameterI4uivNV(GLcontext *context, GLenum target, GLuint index, const GLuint * params);
EXPORT void cwcglProgramEnvParameters4fvEXT(GLcontext *context, GLenum target, GLuint index, GLsizei count, const GLfloat * params);
EXPORT void cwcglProgramEnvParametersI4ivNV(GLcontext *context, GLenum target, GLuint index, GLsizei count, const GLint * params);
EXPORT void cwcglProgramEnvParametersI4uivNV(GLcontext *context, GLenum target, GLuint index, GLsizei count, const GLuint * params);
EXPORT void cwcglProgramLocalParameter4dARB(GLcontext *context, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglProgramLocalParameter4dvARB(GLcontext *context, GLenum target, GLuint index, const GLdouble * params);
EXPORT void cwcglProgramLocalParameter4fARB(GLcontext *context, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglProgramLocalParameter4fvARB(GLcontext *context, GLenum target, GLuint index, const GLfloat * params);
EXPORT void cwcglProgramLocalParameterI4iNV(GLcontext *context, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
EXPORT void cwcglProgramLocalParameterI4ivNV(GLcontext *context, GLenum target, GLuint index, const GLint * params);
EXPORT void cwcglProgramLocalParameterI4uiNV(GLcontext *context, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
EXPORT void cwcglProgramLocalParameterI4uivNV(GLcontext *context, GLenum target, GLuint index, const GLuint * params);
EXPORT void cwcglProgramLocalParameters4fvEXT(GLcontext *context, GLenum target, GLuint index, GLsizei count, const GLfloat * params);
EXPORT void cwcglProgramLocalParametersI4ivNV(GLcontext *context, GLenum target, GLuint index, GLsizei count, const GLint * params);
EXPORT void cwcglProgramLocalParametersI4uivNV(GLcontext *context, GLenum target, GLuint index, GLsizei count, const GLuint * params);
EXPORT void cwcglProgramNamedParameter4dNV(GLcontext *context, GLuint id, GLsizei len, const GLubyte * name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglProgramNamedParameter4dvNV(GLcontext *context, GLuint id, GLsizei len, const GLubyte * name, const GLdouble * v);
EXPORT void cwcglProgramNamedParameter4fNV(GLcontext *context, GLuint id, GLsizei len, const GLubyte * name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglProgramNamedParameter4fvNV(GLcontext *context, GLuint id, GLsizei len, const GLubyte * name, const GLfloat * v);
EXPORT void cwcglProgramParameter4dNV(GLcontext *context, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglProgramParameter4dvNV(GLcontext *context, GLenum target, GLuint index, const GLdouble * v);
EXPORT void cwcglProgramParameter4fNV(GLcontext *context, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglProgramParameter4fvNV(GLcontext *context, GLenum target, GLuint index, const GLfloat * v);
EXPORT void cwcglProgramParameteri(GLcontext *context, GLuint program, GLenum pname, GLint value);
EXPORT void cwcglProgramParameteriARB(GLcontext *context, GLuint program, GLenum pname, GLint value);
EXPORT void cwcglProgramParameteriEXT(GLcontext *context, GLuint program, GLenum pname, GLint value);
EXPORT void cwcglProgramParameters4dvNV(GLcontext *context, GLenum target, GLuint index, GLsizei count, const GLdouble * v);
EXPORT void cwcglProgramParameters4fvNV(GLcontext *context, GLenum target, GLuint index, GLsizei count, const GLfloat * v);
EXPORT void cwcglProgramPathFragmentInputGenNV(GLcontext *context, GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat * coeffs);
EXPORT void cwcglProgramStringARB(GLcontext *context, GLenum target, GLenum format, GLsizei len, const void * string);
EXPORT void cwcglProgramSubroutineParametersuivNV(GLcontext *context, GLenum target, GLsizei count, const GLuint * params);
EXPORT void cwcglProgramUniform1d(GLcontext *context, GLuint program, GLint location, GLdouble v0);
EXPORT void cwcglProgramUniform1dEXT(GLcontext *context, GLuint program, GLint location, GLdouble x);
EXPORT void cwcglProgramUniform1dv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglProgramUniform1dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglProgramUniform1f(GLcontext *context, GLuint program, GLint location, GLfloat v0);
EXPORT void cwcglProgramUniform1fEXT(GLcontext *context, GLuint program, GLint location, GLfloat v0);
EXPORT void cwcglProgramUniform1fv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglProgramUniform1fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglProgramUniform1i(GLcontext *context, GLuint program, GLint location, GLint v0);
EXPORT void cwcglProgramUniform1i64ARB(GLcontext *context, GLuint program, GLint location, GLint64 x);
EXPORT void cwcglProgramUniform1i64NV(GLcontext *context, GLuint program, GLint location, GLint64EXT x);
EXPORT void cwcglProgramUniform1i64vARB(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint64 * value);
EXPORT void cwcglProgramUniform1i64vNV(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
EXPORT void cwcglProgramUniform1iEXT(GLcontext *context, GLuint program, GLint location, GLint v0);
EXPORT void cwcglProgramUniform1iv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglProgramUniform1ivEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglProgramUniform1ui(GLcontext *context, GLuint program, GLint location, GLuint v0);
EXPORT void cwcglProgramUniform1ui64ARB(GLcontext *context, GLuint program, GLint location, GLuint64 x);
EXPORT void cwcglProgramUniform1ui64NV(GLcontext *context, GLuint program, GLint location, GLuint64EXT x);
EXPORT void cwcglProgramUniform1ui64vARB(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64 * value);
EXPORT void cwcglProgramUniform1ui64vNV(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
EXPORT void cwcglProgramUniform1uiEXT(GLcontext *context, GLuint program, GLint location, GLuint v0);
EXPORT void cwcglProgramUniform1uiv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglProgramUniform1uivEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglProgramUniform2d(GLcontext *context, GLuint program, GLint location, GLdouble v0, GLdouble v1);
EXPORT void cwcglProgramUniform2dEXT(GLcontext *context, GLuint program, GLint location, GLdouble x, GLdouble y);
EXPORT void cwcglProgramUniform2dv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglProgramUniform2dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglProgramUniform2f(GLcontext *context, GLuint program, GLint location, GLfloat v0, GLfloat v1);
EXPORT void cwcglProgramUniform2fEXT(GLcontext *context, GLuint program, GLint location, GLfloat v0, GLfloat v1);
EXPORT void cwcglProgramUniform2fv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglProgramUniform2fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglProgramUniform2i(GLcontext *context, GLuint program, GLint location, GLint v0, GLint v1);
EXPORT void cwcglProgramUniform2i64ARB(GLcontext *context, GLuint program, GLint location, GLint64 x, GLint64 y);
EXPORT void cwcglProgramUniform2i64NV(GLcontext *context, GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
EXPORT void cwcglProgramUniform2i64vARB(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint64 * value);
EXPORT void cwcglProgramUniform2i64vNV(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
EXPORT void cwcglProgramUniform2iEXT(GLcontext *context, GLuint program, GLint location, GLint v0, GLint v1);
EXPORT void cwcglProgramUniform2iv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglProgramUniform2ivEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglProgramUniform2ui(GLcontext *context, GLuint program, GLint location, GLuint v0, GLuint v1);
EXPORT void cwcglProgramUniform2ui64ARB(GLcontext *context, GLuint program, GLint location, GLuint64 x, GLuint64 y);
EXPORT void cwcglProgramUniform2ui64NV(GLcontext *context, GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
EXPORT void cwcglProgramUniform2ui64vARB(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64 * value);
EXPORT void cwcglProgramUniform2ui64vNV(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
EXPORT void cwcglProgramUniform2uiEXT(GLcontext *context, GLuint program, GLint location, GLuint v0, GLuint v1);
EXPORT void cwcglProgramUniform2uiv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglProgramUniform2uivEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglProgramUniform3d(GLcontext *context, GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
EXPORT void cwcglProgramUniform3dEXT(GLcontext *context, GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglProgramUniform3dv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglProgramUniform3dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglProgramUniform3f(GLcontext *context, GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
EXPORT void cwcglProgramUniform3fEXT(GLcontext *context, GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
EXPORT void cwcglProgramUniform3fv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglProgramUniform3fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglProgramUniform3i(GLcontext *context, GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
EXPORT void cwcglProgramUniform3i64ARB(GLcontext *context, GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
EXPORT void cwcglProgramUniform3i64NV(GLcontext *context, GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
EXPORT void cwcglProgramUniform3i64vARB(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint64 * value);
EXPORT void cwcglProgramUniform3i64vNV(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
EXPORT void cwcglProgramUniform3iEXT(GLcontext *context, GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
EXPORT void cwcglProgramUniform3iv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglProgramUniform3ivEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglProgramUniform3ui(GLcontext *context, GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
EXPORT void cwcglProgramUniform3ui64ARB(GLcontext *context, GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
EXPORT void cwcglProgramUniform3ui64NV(GLcontext *context, GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
EXPORT void cwcglProgramUniform3ui64vARB(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64 * value);
EXPORT void cwcglProgramUniform3ui64vNV(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
EXPORT void cwcglProgramUniform3uiEXT(GLcontext *context, GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
EXPORT void cwcglProgramUniform3uiv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglProgramUniform3uivEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglProgramUniform4d(GLcontext *context, GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
EXPORT void cwcglProgramUniform4dEXT(GLcontext *context, GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglProgramUniform4dv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglProgramUniform4dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglProgramUniform4f(GLcontext *context, GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
EXPORT void cwcglProgramUniform4fEXT(GLcontext *context, GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
EXPORT void cwcglProgramUniform4fv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglProgramUniform4fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglProgramUniform4i(GLcontext *context, GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
EXPORT void cwcglProgramUniform4i64ARB(GLcontext *context, GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
EXPORT void cwcglProgramUniform4i64NV(GLcontext *context, GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
EXPORT void cwcglProgramUniform4i64vARB(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint64 * value);
EXPORT void cwcglProgramUniform4i64vNV(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
EXPORT void cwcglProgramUniform4iEXT(GLcontext *context, GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
EXPORT void cwcglProgramUniform4iv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglProgramUniform4ivEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglProgramUniform4ui(GLcontext *context, GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
EXPORT void cwcglProgramUniform4ui64ARB(GLcontext *context, GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
EXPORT void cwcglProgramUniform4ui64NV(GLcontext *context, GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
EXPORT void cwcglProgramUniform4ui64vARB(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64 * value);
EXPORT void cwcglProgramUniform4ui64vNV(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
EXPORT void cwcglProgramUniform4uiEXT(GLcontext *context, GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
EXPORT void cwcglProgramUniform4uiv(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglProgramUniform4uivEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglProgramUniformHandleui64ARB(GLcontext *context, GLuint program, GLint location, GLuint64 value);
EXPORT void cwcglProgramUniformHandleui64IMG(GLcontext *context, GLuint program, GLint location, GLuint64 value);
EXPORT void cwcglProgramUniformHandleui64NV(GLcontext *context, GLuint program, GLint location, GLuint64 value);
EXPORT void cwcglProgramUniformHandleui64vARB(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64 * values);
EXPORT void cwcglProgramUniformHandleui64vIMG(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64 * values);
EXPORT void cwcglProgramUniformHandleui64vNV(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64 * values);
EXPORT void cwcglProgramUniformMatrix2dv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix2dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix2fv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix2fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix2x3dv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix2x3dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix2x3fv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix2x3fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix2x4dv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix2x4dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix2x4fv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix2x4fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix3dv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix3dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix3fv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix3fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix3x2dv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix3x2dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix3x2fv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix3x2fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix3x4dv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix3x4dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix3x4fv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix3x4fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix4dv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix4dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix4fv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix4fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix4x2dv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix4x2dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix4x2fv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix4x2fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix4x3dv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix4x3dvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglProgramUniformMatrix4x3fv(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformMatrix4x3fvEXT(GLcontext *context, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglProgramUniformui64NV(GLcontext *context, GLuint program, GLint location, GLuint64EXT value);
EXPORT void cwcglProgramUniformui64vNV(GLcontext *context, GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
EXPORT void cwcglProgramVertexLimitNV(GLcontext *context, GLenum target, GLint limit);
EXPORT void cwcglProvokingVertex(GLcontext *context, GLenum mode);
EXPORT void cwcglProvokingVertexEXT(GLcontext *context, GLenum mode);
EXPORT void cwcglPushAttrib(GLcontext *context, GLbitfield mask);
EXPORT void cwcglPushClientAttrib(GLcontext *context, GLbitfield mask);
EXPORT void cwcglPushClientAttribDefaultEXT(GLcontext *context, GLbitfield mask);
EXPORT void cwcglPushDebugGroup(GLcontext *context, GLenum source, GLuint id, GLsizei length, const GLchar * message);
EXPORT void cwcglPushDebugGroupKHR(GLcontext *context, GLenum source, GLuint id, GLsizei length, const GLchar * message);
EXPORT void cwcglPushGroupMarkerEXT(GLcontext *context, GLsizei length, const GLchar * marker);
EXPORT void cwcglPushMatrix(GLcontext *context);
EXPORT void cwcglPushName(GLcontext *context, GLuint name);
EXPORT void cwcglQueryCounter(GLcontext *context, GLuint id, GLenum target);
EXPORT void cwcglQueryCounterEXT(GLcontext *context, GLuint id, GLenum target);
EXPORT void cwcglQueryMatrixxOES(GLcontext *context, GLfixed * mantissa, GLint * exponent, GLbitfield* return_value);
EXPORT void cwcglQueryObjectParameteruiAMD(GLcontext *context, GLenum target, GLuint id, GLenum pname, GLuint param);
EXPORT void cwcglRasterPos2d(GLcontext *context, GLdouble x, GLdouble y);
EXPORT void cwcglRasterPos2dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglRasterPos2f(GLcontext *context, GLfloat x, GLfloat y);
EXPORT void cwcglRasterPos2fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglRasterPos2i(GLcontext *context, GLint x, GLint y);
EXPORT void cwcglRasterPos2iv(GLcontext *context, const GLint * v);
EXPORT void cwcglRasterPos2s(GLcontext *context, GLshort x, GLshort y);
EXPORT void cwcglRasterPos2sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglRasterPos2xOES(GLcontext *context, GLfixed x, GLfixed y);
EXPORT void cwcglRasterPos2xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglRasterPos3d(GLcontext *context, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglRasterPos3dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglRasterPos3f(GLcontext *context, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglRasterPos3fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglRasterPos3i(GLcontext *context, GLint x, GLint y, GLint z);
EXPORT void cwcglRasterPos3iv(GLcontext *context, const GLint * v);
EXPORT void cwcglRasterPos3s(GLcontext *context, GLshort x, GLshort y, GLshort z);
EXPORT void cwcglRasterPos3sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglRasterPos3xOES(GLcontext *context, GLfixed x, GLfixed y, GLfixed z);
EXPORT void cwcglRasterPos3xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglRasterPos4d(GLcontext *context, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglRasterPos4dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglRasterPos4f(GLcontext *context, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglRasterPos4fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglRasterPos4i(GLcontext *context, GLint x, GLint y, GLint z, GLint w);
EXPORT void cwcglRasterPos4iv(GLcontext *context, const GLint * v);
EXPORT void cwcglRasterPos4s(GLcontext *context, GLshort x, GLshort y, GLshort z, GLshort w);
EXPORT void cwcglRasterPos4sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglRasterPos4xOES(GLcontext *context, GLfixed x, GLfixed y, GLfixed z, GLfixed w);
EXPORT void cwcglRasterPos4xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglRasterSamplesEXT(GLcontext *context, GLuint samples, GLboolean fixedsamplelocations);
EXPORT void cwcglReadBuffer(GLcontext *context, GLenum src);
EXPORT void cwcglReadBufferIndexedEXT(GLcontext *context, GLenum src, GLint index);
EXPORT void cwcglReadBufferNV(GLcontext *context, GLenum mode);
EXPORT void cwcglReadInstrumentsSGIX(GLcontext *context, GLint marker);
EXPORT void cwcglReadPixels(GLcontext *context, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
EXPORT void cwcglReadnPixels(GLcontext *context, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
EXPORT void cwcglReadnPixelsARB(GLcontext *context, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
EXPORT void cwcglReadnPixelsEXT(GLcontext *context, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
EXPORT void cwcglReadnPixelsKHR(GLcontext *context, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
EXPORT void cwcglRectd(GLcontext *context, GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
EXPORT void cwcglRectdv(GLcontext *context, const GLdouble * v1, const GLdouble * v2);
EXPORT void cwcglRectf(GLcontext *context, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
EXPORT void cwcglRectfv(GLcontext *context, const GLfloat * v1, const GLfloat * v2);
EXPORT void cwcglRecti(GLcontext *context, GLint x1, GLint y1, GLint x2, GLint y2);
EXPORT void cwcglRectiv(GLcontext *context, const GLint * v1, const GLint * v2);
EXPORT void cwcglRects(GLcontext *context, GLshort x1, GLshort y1, GLshort x2, GLshort y2);
EXPORT void cwcglRectsv(GLcontext *context, const GLshort * v1, const GLshort * v2);
EXPORT void cwcglRectxOES(GLcontext *context, GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2);
EXPORT void cwcglRectxvOES(GLcontext *context, const GLfixed * v1, const GLfixed * v2);
EXPORT void cwcglReferencePlaneSGIX(GLcontext *context, const GLdouble * equation);
EXPORT void cwcglReleaseShaderCompiler(GLcontext *context);
EXPORT void cwcglRenderMode(GLcontext *context, GLenum mode, GLint* return_value);
EXPORT void cwcglRenderbufferStorage(GLcontext *context, GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglRenderbufferStorageEXT(GLcontext *context, GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglRenderbufferStorageMultisample(GLcontext *context, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglRenderbufferStorageMultisampleANGLE(GLcontext *context, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglRenderbufferStorageMultisampleAPPLE(GLcontext *context, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglRenderbufferStorageMultisampleCoverageNV(GLcontext *context, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglRenderbufferStorageMultisampleEXT(GLcontext *context, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglRenderbufferStorageMultisampleIMG(GLcontext *context, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglRenderbufferStorageMultisampleNV(GLcontext *context, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglRenderbufferStorageOES(GLcontext *context, GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglReplacementCodePointerSUN(GLcontext *context, GLenum type, GLsizei stride, const void ** pointer);
EXPORT void cwcglReplacementCodeubSUN(GLcontext *context, GLubyte code);
EXPORT void cwcglReplacementCodeubvSUN(GLcontext *context, const GLubyte * code);
EXPORT void cwcglReplacementCodeuiColor3fVertex3fSUN(GLcontext *context, GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglReplacementCodeuiColor3fVertex3fvSUN(GLcontext *context, const GLuint * rc, const GLfloat * c, const GLfloat * v);
EXPORT void cwcglReplacementCodeuiColor4fNormal3fVertex3fSUN(GLcontext *context, GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglReplacementCodeuiColor4fNormal3fVertex3fvSUN(GLcontext *context, const GLuint * rc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
EXPORT void cwcglReplacementCodeuiColor4ubVertex3fSUN(GLcontext *context, GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglReplacementCodeuiColor4ubVertex3fvSUN(GLcontext *context, const GLuint * rc, const GLubyte * c, const GLfloat * v);
EXPORT void cwcglReplacementCodeuiNormal3fVertex3fSUN(GLcontext *context, GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglReplacementCodeuiNormal3fVertex3fvSUN(GLcontext *context, const GLuint * rc, const GLfloat * n, const GLfloat * v);
EXPORT void cwcglReplacementCodeuiSUN(GLcontext *context, GLuint code);
EXPORT void cwcglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLcontext *context, GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(GLcontext *context, const GLuint * rc, const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
EXPORT void cwcglReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLcontext *context, GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(GLcontext *context, const GLuint * rc, const GLfloat * tc, const GLfloat * n, const GLfloat * v);
EXPORT void cwcglReplacementCodeuiTexCoord2fVertex3fSUN(GLcontext *context, GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglReplacementCodeuiTexCoord2fVertex3fvSUN(GLcontext *context, const GLuint * rc, const GLfloat * tc, const GLfloat * v);
EXPORT void cwcglReplacementCodeuiVertex3fSUN(GLcontext *context, GLuint rc, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglReplacementCodeuiVertex3fvSUN(GLcontext *context, const GLuint * rc, const GLfloat * v);
EXPORT void cwcglReplacementCodeuivSUN(GLcontext *context, const GLuint * code);
EXPORT void cwcglReplacementCodeusSUN(GLcontext *context, GLushort code);
EXPORT void cwcglReplacementCodeusvSUN(GLcontext *context, const GLushort * code);
EXPORT void cwcglRequestResidentProgramsNV(GLcontext *context, GLsizei n, const GLuint * programs);
EXPORT void cwcglResetHistogram(GLcontext *context, GLenum target);
EXPORT void cwcglResetHistogramEXT(GLcontext *context, GLenum target);
EXPORT void cwcglResetMinmax(GLcontext *context, GLenum target);
EXPORT void cwcglResetMinmaxEXT(GLcontext *context, GLenum target);
EXPORT void cwcglResizeBuffersMESA(GLcontext *context);
EXPORT void cwcglResolveDepthValuesNV(GLcontext *context);
EXPORT void cwcglResolveMultisampleFramebufferAPPLE(GLcontext *context);
EXPORT void cwcglResumeTransformFeedback(GLcontext *context);
EXPORT void cwcglResumeTransformFeedbackNV(GLcontext *context);
EXPORT void cwcglRotated(GLcontext *context, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglRotatef(GLcontext *context, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglRotatex(GLcontext *context, GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
EXPORT void cwcglRotatexOES(GLcontext *context, GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
EXPORT void cwcglSampleCoverage(GLcontext *context, GLfloat value, GLboolean invert);
EXPORT void cwcglSampleCoverageARB(GLcontext *context, GLfloat value, GLboolean invert);
EXPORT void cwcglSampleCoveragex(GLcontext *context, GLclampx value, GLboolean invert);
EXPORT void cwcglSampleCoveragexOES(GLcontext *context, GLclampx value, GLboolean invert);
EXPORT void cwcglSampleMapATI(GLcontext *context, GLuint dst, GLuint interp, GLenum swizzle);
EXPORT void cwcglSampleMaskEXT(GLcontext *context, GLclampf value, GLboolean invert);
EXPORT void cwcglSampleMaskIndexedNV(GLcontext *context, GLuint index, GLbitfield mask);
EXPORT void cwcglSampleMaskSGIS(GLcontext *context, GLclampf value, GLboolean invert);
EXPORT void cwcglSampleMaski(GLcontext *context, GLuint maskNumber, GLbitfield mask);
EXPORT void cwcglSamplePatternEXT(GLcontext *context, GLenum pattern);
EXPORT void cwcglSamplePatternSGIS(GLcontext *context, GLenum pattern);
EXPORT void cwcglSamplerParameterIiv(GLcontext *context, GLuint sampler, GLenum pname, const GLint * param);
EXPORT void cwcglSamplerParameterIivEXT(GLcontext *context, GLuint sampler, GLenum pname, const GLint * param);
EXPORT void cwcglSamplerParameterIivOES(GLcontext *context, GLuint sampler, GLenum pname, const GLint * param);
EXPORT void cwcglSamplerParameterIuiv(GLcontext *context, GLuint sampler, GLenum pname, const GLuint * param);
EXPORT void cwcglSamplerParameterIuivEXT(GLcontext *context, GLuint sampler, GLenum pname, const GLuint * param);
EXPORT void cwcglSamplerParameterIuivOES(GLcontext *context, GLuint sampler, GLenum pname, const GLuint * param);
EXPORT void cwcglSamplerParameterf(GLcontext *context, GLuint sampler, GLenum pname, GLfloat param);
EXPORT void cwcglSamplerParameterfv(GLcontext *context, GLuint sampler, GLenum pname, const GLfloat * param);
EXPORT void cwcglSamplerParameteri(GLcontext *context, GLuint sampler, GLenum pname, GLint param);
EXPORT void cwcglSamplerParameteriv(GLcontext *context, GLuint sampler, GLenum pname, const GLint * param);
EXPORT void cwcglScaled(GLcontext *context, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglScalef(GLcontext *context, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglScalex(GLcontext *context, GLfixed x, GLfixed y, GLfixed z);
EXPORT void cwcglScalexOES(GLcontext *context, GLfixed x, GLfixed y, GLfixed z);
EXPORT void cwcglScissor(GLcontext *context, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglScissorArrayv(GLcontext *context, GLuint first, GLsizei count, const GLint * v);
EXPORT void cwcglScissorArrayvNV(GLcontext *context, GLuint first, GLsizei count, const GLint * v);
EXPORT void cwcglScissorArrayvOES(GLcontext *context, GLuint first, GLsizei count, const GLint * v);
EXPORT void cwcglScissorIndexed(GLcontext *context, GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
EXPORT void cwcglScissorIndexedNV(GLcontext *context, GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
EXPORT void cwcglScissorIndexedOES(GLcontext *context, GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
EXPORT void cwcglScissorIndexedv(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglScissorIndexedvNV(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglScissorIndexedvOES(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglSecondaryColor3b(GLcontext *context, GLbyte red, GLbyte green, GLbyte blue);
EXPORT void cwcglSecondaryColor3bEXT(GLcontext *context, GLbyte red, GLbyte green, GLbyte blue);
EXPORT void cwcglSecondaryColor3bv(GLcontext *context, const GLbyte * v);
EXPORT void cwcglSecondaryColor3bvEXT(GLcontext *context, const GLbyte * v);
EXPORT void cwcglSecondaryColor3d(GLcontext *context, GLdouble red, GLdouble green, GLdouble blue);
EXPORT void cwcglSecondaryColor3dEXT(GLcontext *context, GLdouble red, GLdouble green, GLdouble blue);
EXPORT void cwcglSecondaryColor3dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglSecondaryColor3dvEXT(GLcontext *context, const GLdouble * v);
EXPORT void cwcglSecondaryColor3f(GLcontext *context, GLfloat red, GLfloat green, GLfloat blue);
EXPORT void cwcglSecondaryColor3fEXT(GLcontext *context, GLfloat red, GLfloat green, GLfloat blue);
EXPORT void cwcglSecondaryColor3fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglSecondaryColor3fvEXT(GLcontext *context, const GLfloat * v);
EXPORT void cwcglSecondaryColor3hNV(GLcontext *context, GLhalfNV red, GLhalfNV green, GLhalfNV blue);
EXPORT void cwcglSecondaryColor3hvNV(GLcontext *context, const GLhalfNV * v);
EXPORT void cwcglSecondaryColor3i(GLcontext *context, GLint red, GLint green, GLint blue);
EXPORT void cwcglSecondaryColor3iEXT(GLcontext *context, GLint red, GLint green, GLint blue);
EXPORT void cwcglSecondaryColor3iv(GLcontext *context, const GLint * v);
EXPORT void cwcglSecondaryColor3ivEXT(GLcontext *context, const GLint * v);
EXPORT void cwcglSecondaryColor3s(GLcontext *context, GLshort red, GLshort green, GLshort blue);
EXPORT void cwcglSecondaryColor3sEXT(GLcontext *context, GLshort red, GLshort green, GLshort blue);
EXPORT void cwcglSecondaryColor3sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglSecondaryColor3svEXT(GLcontext *context, const GLshort * v);
EXPORT void cwcglSecondaryColor3ub(GLcontext *context, GLubyte red, GLubyte green, GLubyte blue);
EXPORT void cwcglSecondaryColor3ubEXT(GLcontext *context, GLubyte red, GLubyte green, GLubyte blue);
EXPORT void cwcglSecondaryColor3ubv(GLcontext *context, const GLubyte * v);
EXPORT void cwcglSecondaryColor3ubvEXT(GLcontext *context, const GLubyte * v);
EXPORT void cwcglSecondaryColor3ui(GLcontext *context, GLuint red, GLuint green, GLuint blue);
EXPORT void cwcglSecondaryColor3uiEXT(GLcontext *context, GLuint red, GLuint green, GLuint blue);
EXPORT void cwcglSecondaryColor3uiv(GLcontext *context, const GLuint * v);
EXPORT void cwcglSecondaryColor3uivEXT(GLcontext *context, const GLuint * v);
EXPORT void cwcglSecondaryColor3us(GLcontext *context, GLushort red, GLushort green, GLushort blue);
EXPORT void cwcglSecondaryColor3usEXT(GLcontext *context, GLushort red, GLushort green, GLushort blue);
EXPORT void cwcglSecondaryColor3usv(GLcontext *context, const GLushort * v);
EXPORT void cwcglSecondaryColor3usvEXT(GLcontext *context, const GLushort * v);
EXPORT void cwcglSecondaryColorFormatNV(GLcontext *context, GLint size, GLenum type, GLsizei stride);
EXPORT void cwcglSecondaryColorP3ui(GLcontext *context, GLenum type, GLuint color);
EXPORT void cwcglSecondaryColorP3uiv(GLcontext *context, GLenum type, const GLuint * color);
EXPORT void cwcglSecondaryColorPointer(GLcontext *context, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglSecondaryColorPointerEXT(GLcontext *context, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglSecondaryColorPointerListIBM(GLcontext *context, GLint size, GLenum type, GLint stride, const void ** pointer, GLint ptrstride);
EXPORT void cwcglSelectBuffer(GLcontext *context, GLsizei size, GLuint * buffer);
EXPORT void cwcglSelectPerfMonitorCountersAMD(GLcontext *context, GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint * counterList);
EXPORT void cwcglSeparableFilter2D(GLcontext *context, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column);
EXPORT void cwcglSeparableFilter2DEXT(GLcontext *context, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column);
EXPORT void cwcglSetFenceAPPLE(GLcontext *context, GLuint fence);
EXPORT void cwcglSetFenceNV(GLcontext *context, GLuint fence, GLenum condition);
EXPORT void cwcglSetFragmentShaderConstantATI(GLcontext *context, GLuint dst, const GLfloat * value);
EXPORT void cwcglSetInvariantEXT(GLcontext *context, GLuint id, GLenum type, const void * addr);
EXPORT void cwcglSetLocalConstantEXT(GLcontext *context, GLuint id, GLenum type, const void * addr);
EXPORT void cwcglSetMultisamplefvAMD(GLcontext *context, GLenum pname, GLuint index, const GLfloat * val);
EXPORT void cwcglShadeModel(GLcontext *context, GLenum mode);
EXPORT void cwcglShaderBinary(GLcontext *context, GLsizei count, const GLuint * shaders, GLenum binaryformat, const void * binary, GLsizei length);
EXPORT void cwcglShaderOp1EXT(GLcontext *context, GLenum op, GLuint res, GLuint arg1);
EXPORT void cwcglShaderOp2EXT(GLcontext *context, GLenum op, GLuint res, GLuint arg1, GLuint arg2);
EXPORT void cwcglShaderOp3EXT(GLcontext *context, GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
EXPORT void cwcglShaderSource(GLcontext *context, GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length);
EXPORT void cwcglShaderSourceARB(GLcontext *context, GLhandleARB shaderObj, GLsizei count, const GLcharARB ** string, const GLint * length);
EXPORT void cwcglShaderStorageBlockBinding(GLcontext *context, GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
EXPORT void cwcglSharpenTexFuncSGIS(GLcontext *context, GLenum target, GLsizei n, const GLfloat * points);
EXPORT void cwcglSpriteParameterfSGIX(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglSpriteParameterfvSGIX(GLcontext *context, GLenum pname, const GLfloat * params);
EXPORT void cwcglSpriteParameteriSGIX(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglSpriteParameterivSGIX(GLcontext *context, GLenum pname, const GLint * params);
EXPORT void cwcglStartInstrumentsSGIX(GLcontext *context);
EXPORT void cwcglStartTilingQCOM(GLcontext *context, GLuint x, GLuint y, GLuint width, GLuint height, GLbitfield preserveMask);
EXPORT void cwcglStateCaptureNV(GLcontext *context, GLuint state, GLenum mode);
EXPORT void cwcglStencilClearTagEXT(GLcontext *context, GLsizei stencilTagBits, GLuint stencilClearTag);
EXPORT void cwcglStencilFillPathInstancedNV(GLcontext *context, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat * transformValues);
EXPORT void cwcglStencilFillPathNV(GLcontext *context, GLuint path, GLenum fillMode, GLuint mask);
EXPORT void cwcglStencilFunc(GLcontext *context, GLenum func, GLint ref, GLuint mask);
EXPORT void cwcglStencilFuncSeparate(GLcontext *context, GLenum face, GLenum func, GLint ref, GLuint mask);
EXPORT void cwcglStencilFuncSeparateATI(GLcontext *context, GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
EXPORT void cwcglStencilMask(GLcontext *context, GLuint mask);
EXPORT void cwcglStencilMaskSeparate(GLcontext *context, GLenum face, GLuint mask);
EXPORT void cwcglStencilOp(GLcontext *context, GLenum fail, GLenum zfail, GLenum zpass);
EXPORT void cwcglStencilOpSeparate(GLcontext *context, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
EXPORT void cwcglStencilOpSeparateATI(GLcontext *context, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
EXPORT void cwcglStencilOpValueAMD(GLcontext *context, GLenum face, GLuint value);
EXPORT void cwcglStencilStrokePathInstancedNV(GLcontext *context, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat * transformValues);
EXPORT void cwcglStencilStrokePathNV(GLcontext *context, GLuint path, GLint reference, GLuint mask);
EXPORT void cwcglStencilThenCoverFillPathInstancedNV(GLcontext *context, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
EXPORT void cwcglStencilThenCoverFillPathNV(GLcontext *context, GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
EXPORT void cwcglStencilThenCoverStrokePathInstancedNV(GLcontext *context, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
EXPORT void cwcglStencilThenCoverStrokePathNV(GLcontext *context, GLuint path, GLint reference, GLuint mask, GLenum coverMode);
EXPORT void cwcglStopInstrumentsSGIX(GLcontext *context, GLint marker);
EXPORT void cwcglStringMarkerGREMEDY(GLcontext *context, GLsizei len, const void * string);
EXPORT void cwcglSubpixelPrecisionBiasNV(GLcontext *context, GLuint xbits, GLuint ybits);
EXPORT void cwcglSwizzleEXT(GLcontext *context, GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
EXPORT void cwcglSyncTextureINTEL(GLcontext *context, GLuint texture);
EXPORT void cwcglTagSampleBufferSGIX(GLcontext *context);
EXPORT void cwcglTangent3bEXT(GLcontext *context, GLbyte tx, GLbyte ty, GLbyte tz);
EXPORT void cwcglTangent3bvEXT(GLcontext *context, const GLbyte * v);
EXPORT void cwcglTangent3dEXT(GLcontext *context, GLdouble tx, GLdouble ty, GLdouble tz);
EXPORT void cwcglTangent3dvEXT(GLcontext *context, const GLdouble * v);
EXPORT void cwcglTangent3fEXT(GLcontext *context, GLfloat tx, GLfloat ty, GLfloat tz);
EXPORT void cwcglTangent3fvEXT(GLcontext *context, const GLfloat * v);
EXPORT void cwcglTangent3iEXT(GLcontext *context, GLint tx, GLint ty, GLint tz);
EXPORT void cwcglTangent3ivEXT(GLcontext *context, const GLint * v);
EXPORT void cwcglTangent3sEXT(GLcontext *context, GLshort tx, GLshort ty, GLshort tz);
EXPORT void cwcglTangent3svEXT(GLcontext *context, const GLshort * v);
EXPORT void cwcglTangentPointerEXT(GLcontext *context, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglTbufferMask3DFX(GLcontext *context, GLuint mask);
EXPORT void cwcglTessellationFactorAMD(GLcontext *context, GLfloat factor);
EXPORT void cwcglTessellationModeAMD(GLcontext *context, GLenum mode);
EXPORT void cwcglTestFenceAPPLE(GLcontext *context, GLuint fence, GLboolean* return_value);
EXPORT void cwcglTestFenceNV(GLcontext *context, GLuint fence, GLboolean* return_value);
EXPORT void cwcglTestObjectAPPLE(GLcontext *context, GLenum object, GLuint name, GLboolean* return_value);
EXPORT void cwcglTexBuffer(GLcontext *context, GLenum target, GLenum internalformat, GLuint buffer);
EXPORT void cwcglTexBufferARB(GLcontext *context, GLenum target, GLenum internalformat, GLuint buffer);
EXPORT void cwcglTexBufferEXT(GLcontext *context, GLenum target, GLenum internalformat, GLuint buffer);
EXPORT void cwcglTexBufferOES(GLcontext *context, GLenum target, GLenum internalformat, GLuint buffer);
EXPORT void cwcglTexBufferRange(GLcontext *context, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
EXPORT void cwcglTexBufferRangeEXT(GLcontext *context, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
EXPORT void cwcglTexBufferRangeOES(GLcontext *context, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
EXPORT void cwcglTexBumpParameterfvATI(GLcontext *context, GLenum pname, const GLfloat * param);
EXPORT void cwcglTexBumpParameterivATI(GLcontext *context, GLenum pname, const GLint * param);
EXPORT void cwcglTexCoord1bOES(GLcontext *context, GLbyte s);
EXPORT void cwcglTexCoord1bvOES(GLcontext *context, const GLbyte * coords);
EXPORT void cwcglTexCoord1d(GLcontext *context, GLdouble s);
EXPORT void cwcglTexCoord1dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglTexCoord1f(GLcontext *context, GLfloat s);
EXPORT void cwcglTexCoord1fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglTexCoord1hNV(GLcontext *context, GLhalfNV s);
EXPORT void cwcglTexCoord1hvNV(GLcontext *context, const GLhalfNV * v);
EXPORT void cwcglTexCoord1i(GLcontext *context, GLint s);
EXPORT void cwcglTexCoord1iv(GLcontext *context, const GLint * v);
EXPORT void cwcglTexCoord1s(GLcontext *context, GLshort s);
EXPORT void cwcglTexCoord1sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglTexCoord1xOES(GLcontext *context, GLfixed s);
EXPORT void cwcglTexCoord1xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglTexCoord2bOES(GLcontext *context, GLbyte s, GLbyte t);
EXPORT void cwcglTexCoord2bvOES(GLcontext *context, const GLbyte * coords);
EXPORT void cwcglTexCoord2d(GLcontext *context, GLdouble s, GLdouble t);
EXPORT void cwcglTexCoord2dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglTexCoord2f(GLcontext *context, GLfloat s, GLfloat t);
EXPORT void cwcglTexCoord2fColor3fVertex3fSUN(GLcontext *context, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglTexCoord2fColor3fVertex3fvSUN(GLcontext *context, const GLfloat * tc, const GLfloat * c, const GLfloat * v);
EXPORT void cwcglTexCoord2fColor4fNormal3fVertex3fSUN(GLcontext *context, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglTexCoord2fColor4fNormal3fVertex3fvSUN(GLcontext *context, const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
EXPORT void cwcglTexCoord2fColor4ubVertex3fSUN(GLcontext *context, GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglTexCoord2fColor4ubVertex3fvSUN(GLcontext *context, const GLfloat * tc, const GLubyte * c, const GLfloat * v);
EXPORT void cwcglTexCoord2fNormal3fVertex3fSUN(GLcontext *context, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglTexCoord2fNormal3fVertex3fvSUN(GLcontext *context, const GLfloat * tc, const GLfloat * n, const GLfloat * v);
EXPORT void cwcglTexCoord2fVertex3fSUN(GLcontext *context, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglTexCoord2fVertex3fvSUN(GLcontext *context, const GLfloat * tc, const GLfloat * v);
EXPORT void cwcglTexCoord2fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglTexCoord2hNV(GLcontext *context, GLhalfNV s, GLhalfNV t);
EXPORT void cwcglTexCoord2hvNV(GLcontext *context, const GLhalfNV * v);
EXPORT void cwcglTexCoord2i(GLcontext *context, GLint s, GLint t);
EXPORT void cwcglTexCoord2iv(GLcontext *context, const GLint * v);
EXPORT void cwcglTexCoord2s(GLcontext *context, GLshort s, GLshort t);
EXPORT void cwcglTexCoord2sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglTexCoord2xOES(GLcontext *context, GLfixed s, GLfixed t);
EXPORT void cwcglTexCoord2xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglTexCoord3bOES(GLcontext *context, GLbyte s, GLbyte t, GLbyte r);
EXPORT void cwcglTexCoord3bvOES(GLcontext *context, const GLbyte * coords);
EXPORT void cwcglTexCoord3d(GLcontext *context, GLdouble s, GLdouble t, GLdouble r);
EXPORT void cwcglTexCoord3dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglTexCoord3f(GLcontext *context, GLfloat s, GLfloat t, GLfloat r);
EXPORT void cwcglTexCoord3fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglTexCoord3hNV(GLcontext *context, GLhalfNV s, GLhalfNV t, GLhalfNV r);
EXPORT void cwcglTexCoord3hvNV(GLcontext *context, const GLhalfNV * v);
EXPORT void cwcglTexCoord3i(GLcontext *context, GLint s, GLint t, GLint r);
EXPORT void cwcglTexCoord3iv(GLcontext *context, const GLint * v);
EXPORT void cwcglTexCoord3s(GLcontext *context, GLshort s, GLshort t, GLshort r);
EXPORT void cwcglTexCoord3sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglTexCoord3xOES(GLcontext *context, GLfixed s, GLfixed t, GLfixed r);
EXPORT void cwcglTexCoord3xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglTexCoord4bOES(GLcontext *context, GLbyte s, GLbyte t, GLbyte r, GLbyte q);
EXPORT void cwcglTexCoord4bvOES(GLcontext *context, const GLbyte * coords);
EXPORT void cwcglTexCoord4d(GLcontext *context, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
EXPORT void cwcglTexCoord4dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglTexCoord4f(GLcontext *context, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
EXPORT void cwcglTexCoord4fColor4fNormal3fVertex4fSUN(GLcontext *context, GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglTexCoord4fColor4fNormal3fVertex4fvSUN(GLcontext *context, const GLfloat * tc, const GLfloat * c, const GLfloat * n, const GLfloat * v);
EXPORT void cwcglTexCoord4fVertex4fSUN(GLcontext *context, GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglTexCoord4fVertex4fvSUN(GLcontext *context, const GLfloat * tc, const GLfloat * v);
EXPORT void cwcglTexCoord4fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglTexCoord4hNV(GLcontext *context, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
EXPORT void cwcglTexCoord4hvNV(GLcontext *context, const GLhalfNV * v);
EXPORT void cwcglTexCoord4i(GLcontext *context, GLint s, GLint t, GLint r, GLint q);
EXPORT void cwcglTexCoord4iv(GLcontext *context, const GLint * v);
EXPORT void cwcglTexCoord4s(GLcontext *context, GLshort s, GLshort t, GLshort r, GLshort q);
EXPORT void cwcglTexCoord4sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglTexCoord4xOES(GLcontext *context, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
EXPORT void cwcglTexCoord4xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglTexCoordFormatNV(GLcontext *context, GLint size, GLenum type, GLsizei stride);
EXPORT void cwcglTexCoordP1ui(GLcontext *context, GLenum type, GLuint coords);
EXPORT void cwcglTexCoordP1uiv(GLcontext *context, GLenum type, const GLuint * coords);
EXPORT void cwcglTexCoordP2ui(GLcontext *context, GLenum type, GLuint coords);
EXPORT void cwcglTexCoordP2uiv(GLcontext *context, GLenum type, const GLuint * coords);
EXPORT void cwcglTexCoordP3ui(GLcontext *context, GLenum type, GLuint coords);
EXPORT void cwcglTexCoordP3uiv(GLcontext *context, GLenum type, const GLuint * coords);
EXPORT void cwcglTexCoordP4ui(GLcontext *context, GLenum type, GLuint coords);
EXPORT void cwcglTexCoordP4uiv(GLcontext *context, GLenum type, const GLuint * coords);
EXPORT void cwcglTexCoordPointer(GLcontext *context, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglTexCoordPointerEXT(GLcontext *context, GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer);
EXPORT void cwcglTexCoordPointerListIBM(GLcontext *context, GLint size, GLenum type, GLint stride, const void ** pointer, GLint ptrstride);
EXPORT void cwcglTexCoordPointervINTEL(GLcontext *context, GLint size, GLenum type, const void ** pointer);
EXPORT void cwcglTexEnvf(GLcontext *context, GLenum target, GLenum pname, GLfloat param);
EXPORT void cwcglTexEnvfv(GLcontext *context, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglTexEnvi(GLcontext *context, GLenum target, GLenum pname, GLint param);
EXPORT void cwcglTexEnviv(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglTexEnvx(GLcontext *context, GLenum target, GLenum pname, GLfixed param);
EXPORT void cwcglTexEnvxOES(GLcontext *context, GLenum target, GLenum pname, GLfixed param);
EXPORT void cwcglTexEnvxv(GLcontext *context, GLenum target, GLenum pname, const GLfixed * params);
EXPORT void cwcglTexEnvxvOES(GLcontext *context, GLenum target, GLenum pname, const GLfixed * params);
EXPORT void cwcglTexFilterFuncSGIS(GLcontext *context, GLenum target, GLenum filter, GLsizei n, const GLfloat * weights);
EXPORT void cwcglTexGend(GLcontext *context, GLenum coord, GLenum pname, GLdouble param);
EXPORT void cwcglTexGendv(GLcontext *context, GLenum coord, GLenum pname, const GLdouble * params);
EXPORT void cwcglTexGenf(GLcontext *context, GLenum coord, GLenum pname, GLfloat param);
EXPORT void cwcglTexGenfOES(GLcontext *context, GLenum coord, GLenum pname, GLfloat param);
EXPORT void cwcglTexGenfv(GLcontext *context, GLenum coord, GLenum pname, const GLfloat * params);
EXPORT void cwcglTexGenfvOES(GLcontext *context, GLenum coord, GLenum pname, const GLfloat * params);
EXPORT void cwcglTexGeni(GLcontext *context, GLenum coord, GLenum pname, GLint param);
EXPORT void cwcglTexGeniOES(GLcontext *context, GLenum coord, GLenum pname, GLint param);
EXPORT void cwcglTexGeniv(GLcontext *context, GLenum coord, GLenum pname, const GLint * params);
EXPORT void cwcglTexGenivOES(GLcontext *context, GLenum coord, GLenum pname, const GLint * params);
EXPORT void cwcglTexGenxOES(GLcontext *context, GLenum coord, GLenum pname, GLfixed param);
EXPORT void cwcglTexGenxvOES(GLcontext *context, GLenum coord, GLenum pname, const GLfixed * params);
EXPORT void cwcglTexImage1D(GLcontext *context, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexImage2D(GLcontext *context, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexImage2DMultisample(GLcontext *context, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
EXPORT void cwcglTexImage2DMultisampleCoverageNV(GLcontext *context, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
EXPORT void cwcglTexImage3D(GLcontext *context, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexImage3DEXT(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexImage3DMultisample(GLcontext *context, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
EXPORT void cwcglTexImage3DMultisampleCoverageNV(GLcontext *context, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
EXPORT void cwcglTexImage3DOES(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexImage4DSGIS(GLcontext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexPageCommitmentARB(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
EXPORT void cwcglTexPageCommitmentEXT(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
EXPORT void cwcglTexParameterIiv(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglTexParameterIivEXT(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglTexParameterIivOES(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglTexParameterIuiv(GLcontext *context, GLenum target, GLenum pname, const GLuint * params);
EXPORT void cwcglTexParameterIuivEXT(GLcontext *context, GLenum target, GLenum pname, const GLuint * params);
EXPORT void cwcglTexParameterIuivOES(GLcontext *context, GLenum target, GLenum pname, const GLuint * params);
EXPORT void cwcglTexParameterf(GLcontext *context, GLenum target, GLenum pname, GLfloat param);
EXPORT void cwcglTexParameterfv(GLcontext *context, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglTexParameteri(GLcontext *context, GLenum target, GLenum pname, GLint param);
EXPORT void cwcglTexParameteriv(GLcontext *context, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglTexParameterx(GLcontext *context, GLenum target, GLenum pname, GLfixed param);
EXPORT void cwcglTexParameterxOES(GLcontext *context, GLenum target, GLenum pname, GLfixed param);
EXPORT void cwcglTexParameterxv(GLcontext *context, GLenum target, GLenum pname, const GLfixed * params);
EXPORT void cwcglTexParameterxvOES(GLcontext *context, GLenum target, GLenum pname, const GLfixed * params);
EXPORT void cwcglTexRenderbufferNV(GLcontext *context, GLenum target, GLuint renderbuffer);
EXPORT void cwcglTexStorage1D(GLcontext *context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
EXPORT void cwcglTexStorage1DEXT(GLcontext *context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
EXPORT void cwcglTexStorage2D(GLcontext *context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglTexStorage2DEXT(GLcontext *context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglTexStorage2DMultisample(GLcontext *context, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
EXPORT void cwcglTexStorage3D(GLcontext *context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
EXPORT void cwcglTexStorage3DEXT(GLcontext *context, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
EXPORT void cwcglTexStorage3DMultisample(GLcontext *context, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
EXPORT void cwcglTexStorage3DMultisampleOES(GLcontext *context, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
EXPORT void cwcglTexStorageSparseAMD(GLcontext *context, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
EXPORT void cwcglTexSubImage1D(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexSubImage1DEXT(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexSubImage2D(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexSubImage2DEXT(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexSubImage3D(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexSubImage3DEXT(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexSubImage3DOES(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTexSubImage4DSGIS(GLcontext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTextureBarrier(GLcontext *context);
EXPORT void cwcglTextureBarrierNV(GLcontext *context);
EXPORT void cwcglTextureBuffer(GLcontext *context, GLuint texture, GLenum internalformat, GLuint buffer);
EXPORT void cwcglTextureBufferEXT(GLcontext *context, GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
EXPORT void cwcglTextureBufferRange(GLcontext *context, GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
EXPORT void cwcglTextureBufferRangeEXT(GLcontext *context, GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
EXPORT void cwcglTextureColorMaskSGIS(GLcontext *context, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
EXPORT void cwcglTextureImage1DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTextureImage2DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTextureImage2DMultisampleCoverageNV(GLcontext *context, GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
EXPORT void cwcglTextureImage2DMultisampleNV(GLcontext *context, GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
EXPORT void cwcglTextureImage3DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTextureImage3DMultisampleCoverageNV(GLcontext *context, GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
EXPORT void cwcglTextureImage3DMultisampleNV(GLcontext *context, GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
EXPORT void cwcglTextureLightEXT(GLcontext *context, GLenum pname);
EXPORT void cwcglTextureMaterialEXT(GLcontext *context, GLenum face, GLenum mode);
EXPORT void cwcglTextureNormalEXT(GLcontext *context, GLenum mode);
EXPORT void cwcglTexturePageCommitmentEXT(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
EXPORT void cwcglTextureParameterIiv(GLcontext *context, GLuint texture, GLenum pname, const GLint * params);
EXPORT void cwcglTextureParameterIivEXT(GLcontext *context, GLuint texture, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglTextureParameterIuiv(GLcontext *context, GLuint texture, GLenum pname, const GLuint * params);
EXPORT void cwcglTextureParameterIuivEXT(GLcontext *context, GLuint texture, GLenum target, GLenum pname, const GLuint * params);
EXPORT void cwcglTextureParameterf(GLcontext *context, GLuint texture, GLenum pname, GLfloat param);
EXPORT void cwcglTextureParameterfEXT(GLcontext *context, GLuint texture, GLenum target, GLenum pname, GLfloat param);
EXPORT void cwcglTextureParameterfv(GLcontext *context, GLuint texture, GLenum pname, const GLfloat * param);
EXPORT void cwcglTextureParameterfvEXT(GLcontext *context, GLuint texture, GLenum target, GLenum pname, const GLfloat * params);
EXPORT void cwcglTextureParameteri(GLcontext *context, GLuint texture, GLenum pname, GLint param);
EXPORT void cwcglTextureParameteriEXT(GLcontext *context, GLuint texture, GLenum target, GLenum pname, GLint param);
EXPORT void cwcglTextureParameteriv(GLcontext *context, GLuint texture, GLenum pname, const GLint * param);
EXPORT void cwcglTextureParameterivEXT(GLcontext *context, GLuint texture, GLenum target, GLenum pname, const GLint * params);
EXPORT void cwcglTextureRangeAPPLE(GLcontext *context, GLenum target, GLsizei length, const void * pointer);
EXPORT void cwcglTextureRenderbufferEXT(GLcontext *context, GLuint texture, GLenum target, GLuint renderbuffer);
EXPORT void cwcglTextureStorage1D(GLcontext *context, GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
EXPORT void cwcglTextureStorage1DEXT(GLcontext *context, GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
EXPORT void cwcglTextureStorage2D(GLcontext *context, GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglTextureStorage2DEXT(GLcontext *context, GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
EXPORT void cwcglTextureStorage2DMultisample(GLcontext *context, GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
EXPORT void cwcglTextureStorage2DMultisampleEXT(GLcontext *context, GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
EXPORT void cwcglTextureStorage3D(GLcontext *context, GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
EXPORT void cwcglTextureStorage3DEXT(GLcontext *context, GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
EXPORT void cwcglTextureStorage3DMultisample(GLcontext *context, GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
EXPORT void cwcglTextureStorage3DMultisampleEXT(GLcontext *context, GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
EXPORT void cwcglTextureStorageSparseAMD(GLcontext *context, GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
EXPORT void cwcglTextureSubImage1D(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTextureSubImage1DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTextureSubImage2D(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTextureSubImage2DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTextureSubImage3D(GLcontext *context, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTextureSubImage3DEXT(GLcontext *context, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
EXPORT void cwcglTextureView(GLcontext *context, GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
EXPORT void cwcglTextureViewEXT(GLcontext *context, GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
EXPORT void cwcglTextureViewOES(GLcontext *context, GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
EXPORT void cwcglTrackMatrixNV(GLcontext *context, GLenum target, GLuint address, GLenum matrix, GLenum transform);
EXPORT void cwcglTransformFeedbackAttribsNV(GLcontext *context, GLsizei count, const GLint * attribs, GLenum bufferMode);
EXPORT void cwcglTransformFeedbackBufferBase(GLcontext *context, GLuint xfb, GLuint index, GLuint buffer);
EXPORT void cwcglTransformFeedbackBufferRange(GLcontext *context, GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
EXPORT void cwcglTransformFeedbackStreamAttribsNV(GLcontext *context, GLsizei count, const GLint * attribs, GLsizei nbuffers, const GLint * bufstreams, GLenum bufferMode);
EXPORT void cwcglTransformFeedbackVaryings(GLcontext *context, GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);
EXPORT void cwcglTransformFeedbackVaryingsEXT(GLcontext *context, GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);
EXPORT void cwcglTransformFeedbackVaryingsNV(GLcontext *context, GLuint program, GLsizei count, const GLint * locations, GLenum bufferMode);
EXPORT void cwcglTransformPathNV(GLcontext *context, GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat * transformValues);
EXPORT void cwcglTranslated(GLcontext *context, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglTranslatef(GLcontext *context, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglTranslatex(GLcontext *context, GLfixed x, GLfixed y, GLfixed z);
EXPORT void cwcglTranslatexOES(GLcontext *context, GLfixed x, GLfixed y, GLfixed z);
EXPORT void cwcglUniform1d(GLcontext *context, GLint location, GLdouble x);
EXPORT void cwcglUniform1dv(GLcontext *context, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglUniform1f(GLcontext *context, GLint location, GLfloat v0);
EXPORT void cwcglUniform1fARB(GLcontext *context, GLint location, GLfloat v0);
EXPORT void cwcglUniform1fv(GLcontext *context, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglUniform1fvARB(GLcontext *context, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglUniform1i(GLcontext *context, GLint location, GLint v0);
EXPORT void cwcglUniform1i64ARB(GLcontext *context, GLint location, GLint64 x);
EXPORT void cwcglUniform1i64NV(GLcontext *context, GLint location, GLint64EXT x);
EXPORT void cwcglUniform1i64vARB(GLcontext *context, GLint location, GLsizei count, const GLint64 * value);
EXPORT void cwcglUniform1i64vNV(GLcontext *context, GLint location, GLsizei count, const GLint64EXT * value);
EXPORT void cwcglUniform1iARB(GLcontext *context, GLint location, GLint v0);
EXPORT void cwcglUniform1iv(GLcontext *context, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglUniform1ivARB(GLcontext *context, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglUniform1ui(GLcontext *context, GLint location, GLuint v0);
EXPORT void cwcglUniform1ui64ARB(GLcontext *context, GLint location, GLuint64 x);
EXPORT void cwcglUniform1ui64NV(GLcontext *context, GLint location, GLuint64EXT x);
EXPORT void cwcglUniform1ui64vARB(GLcontext *context, GLint location, GLsizei count, const GLuint64 * value);
EXPORT void cwcglUniform1ui64vNV(GLcontext *context, GLint location, GLsizei count, const GLuint64EXT * value);
EXPORT void cwcglUniform1uiEXT(GLcontext *context, GLint location, GLuint v0);
EXPORT void cwcglUniform1uiv(GLcontext *context, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglUniform1uivEXT(GLcontext *context, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglUniform2d(GLcontext *context, GLint location, GLdouble x, GLdouble y);
EXPORT void cwcglUniform2dv(GLcontext *context, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglUniform2f(GLcontext *context, GLint location, GLfloat v0, GLfloat v1);
EXPORT void cwcglUniform2fARB(GLcontext *context, GLint location, GLfloat v0, GLfloat v1);
EXPORT void cwcglUniform2fv(GLcontext *context, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglUniform2fvARB(GLcontext *context, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglUniform2i(GLcontext *context, GLint location, GLint v0, GLint v1);
EXPORT void cwcglUniform2i64ARB(GLcontext *context, GLint location, GLint64 x, GLint64 y);
EXPORT void cwcglUniform2i64NV(GLcontext *context, GLint location, GLint64EXT x, GLint64EXT y);
EXPORT void cwcglUniform2i64vARB(GLcontext *context, GLint location, GLsizei count, const GLint64 * value);
EXPORT void cwcglUniform2i64vNV(GLcontext *context, GLint location, GLsizei count, const GLint64EXT * value);
EXPORT void cwcglUniform2iARB(GLcontext *context, GLint location, GLint v0, GLint v1);
EXPORT void cwcglUniform2iv(GLcontext *context, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglUniform2ivARB(GLcontext *context, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglUniform2ui(GLcontext *context, GLint location, GLuint v0, GLuint v1);
EXPORT void cwcglUniform2ui64ARB(GLcontext *context, GLint location, GLuint64 x, GLuint64 y);
EXPORT void cwcglUniform2ui64NV(GLcontext *context, GLint location, GLuint64EXT x, GLuint64EXT y);
EXPORT void cwcglUniform2ui64vARB(GLcontext *context, GLint location, GLsizei count, const GLuint64 * value);
EXPORT void cwcglUniform2ui64vNV(GLcontext *context, GLint location, GLsizei count, const GLuint64EXT * value);
EXPORT void cwcglUniform2uiEXT(GLcontext *context, GLint location, GLuint v0, GLuint v1);
EXPORT void cwcglUniform2uiv(GLcontext *context, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglUniform2uivEXT(GLcontext *context, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglUniform3d(GLcontext *context, GLint location, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglUniform3dv(GLcontext *context, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglUniform3f(GLcontext *context, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
EXPORT void cwcglUniform3fARB(GLcontext *context, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
EXPORT void cwcglUniform3fv(GLcontext *context, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglUniform3fvARB(GLcontext *context, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglUniform3i(GLcontext *context, GLint location, GLint v0, GLint v1, GLint v2);
EXPORT void cwcglUniform3i64ARB(GLcontext *context, GLint location, GLint64 x, GLint64 y, GLint64 z);
EXPORT void cwcglUniform3i64NV(GLcontext *context, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
EXPORT void cwcglUniform3i64vARB(GLcontext *context, GLint location, GLsizei count, const GLint64 * value);
EXPORT void cwcglUniform3i64vNV(GLcontext *context, GLint location, GLsizei count, const GLint64EXT * value);
EXPORT void cwcglUniform3iARB(GLcontext *context, GLint location, GLint v0, GLint v1, GLint v2);
EXPORT void cwcglUniform3iv(GLcontext *context, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglUniform3ivARB(GLcontext *context, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglUniform3ui(GLcontext *context, GLint location, GLuint v0, GLuint v1, GLuint v2);
EXPORT void cwcglUniform3ui64ARB(GLcontext *context, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
EXPORT void cwcglUniform3ui64NV(GLcontext *context, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
EXPORT void cwcglUniform3ui64vARB(GLcontext *context, GLint location, GLsizei count, const GLuint64 * value);
EXPORT void cwcglUniform3ui64vNV(GLcontext *context, GLint location, GLsizei count, const GLuint64EXT * value);
EXPORT void cwcglUniform3uiEXT(GLcontext *context, GLint location, GLuint v0, GLuint v1, GLuint v2);
EXPORT void cwcglUniform3uiv(GLcontext *context, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglUniform3uivEXT(GLcontext *context, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglUniform4d(GLcontext *context, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglUniform4dv(GLcontext *context, GLint location, GLsizei count, const GLdouble * value);
EXPORT void cwcglUniform4f(GLcontext *context, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
EXPORT void cwcglUniform4fARB(GLcontext *context, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
EXPORT void cwcglUniform4fv(GLcontext *context, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglUniform4fvARB(GLcontext *context, GLint location, GLsizei count, const GLfloat * value);
EXPORT void cwcglUniform4i(GLcontext *context, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
EXPORT void cwcglUniform4i64ARB(GLcontext *context, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
EXPORT void cwcglUniform4i64NV(GLcontext *context, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
EXPORT void cwcglUniform4i64vARB(GLcontext *context, GLint location, GLsizei count, const GLint64 * value);
EXPORT void cwcglUniform4i64vNV(GLcontext *context, GLint location, GLsizei count, const GLint64EXT * value);
EXPORT void cwcglUniform4iARB(GLcontext *context, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
EXPORT void cwcglUniform4iv(GLcontext *context, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglUniform4ivARB(GLcontext *context, GLint location, GLsizei count, const GLint * value);
EXPORT void cwcglUniform4ui(GLcontext *context, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
EXPORT void cwcglUniform4ui64ARB(GLcontext *context, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
EXPORT void cwcglUniform4ui64NV(GLcontext *context, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
EXPORT void cwcglUniform4ui64vARB(GLcontext *context, GLint location, GLsizei count, const GLuint64 * value);
EXPORT void cwcglUniform4ui64vNV(GLcontext *context, GLint location, GLsizei count, const GLuint64EXT * value);
EXPORT void cwcglUniform4uiEXT(GLcontext *context, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
EXPORT void cwcglUniform4uiv(GLcontext *context, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglUniform4uivEXT(GLcontext *context, GLint location, GLsizei count, const GLuint * value);
EXPORT void cwcglUniformBlockBinding(GLcontext *context, GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
EXPORT void cwcglUniformBufferEXT(GLcontext *context, GLuint program, GLint location, GLuint buffer);
EXPORT void cwcglUniformHandleui64ARB(GLcontext *context, GLint location, GLuint64 value);
EXPORT void cwcglUniformHandleui64IMG(GLcontext *context, GLint location, GLuint64 value);
EXPORT void cwcglUniformHandleui64NV(GLcontext *context, GLint location, GLuint64 value);
EXPORT void cwcglUniformHandleui64vARB(GLcontext *context, GLint location, GLsizei count, const GLuint64 * value);
EXPORT void cwcglUniformHandleui64vIMG(GLcontext *context, GLint location, GLsizei count, const GLuint64 * value);
EXPORT void cwcglUniformHandleui64vNV(GLcontext *context, GLint location, GLsizei count, const GLuint64 * value);
EXPORT void cwcglUniformMatrix2dv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglUniformMatrix2fv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix2fvARB(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix2x3dv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglUniformMatrix2x3fv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix2x3fvNV(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix2x4dv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglUniformMatrix2x4fv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix2x4fvNV(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix3dv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglUniformMatrix3fv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix3fvARB(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix3x2dv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglUniformMatrix3x2fv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix3x2fvNV(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix3x4dv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglUniformMatrix3x4fv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix3x4fvNV(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix4dv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglUniformMatrix4fv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix4fvARB(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix4x2dv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglUniformMatrix4x2fv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix4x2fvNV(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix4x3dv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
EXPORT void cwcglUniformMatrix4x3fv(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformMatrix4x3fvNV(GLcontext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
EXPORT void cwcglUniformSubroutinesuiv(GLcontext *context, GLenum shadertype, GLsizei count, const GLuint * indices);
EXPORT void cwcglUniformui64NV(GLcontext *context, GLint location, GLuint64EXT value);
EXPORT void cwcglUniformui64vNV(GLcontext *context, GLint location, GLsizei count, const GLuint64EXT * value);
EXPORT void cwcglUnlockArraysEXT(GLcontext *context);
EXPORT void cwcglUnmapBuffer(GLcontext *context, GLenum target, GLboolean* return_value);
EXPORT void cwcglUnmapBufferARB(GLcontext *context, GLenum target, GLboolean* return_value);
EXPORT void cwcglUnmapBufferOES(GLcontext *context, GLenum target, GLboolean* return_value);
EXPORT void cwcglUnmapNamedBuffer(GLcontext *context, GLuint buffer, GLboolean* return_value);
EXPORT void cwcglUnmapNamedBufferEXT(GLcontext *context, GLuint buffer, GLboolean* return_value);
EXPORT void cwcglUnmapObjectBufferATI(GLcontext *context, GLuint buffer);
EXPORT void cwcglUnmapTexture2DINTEL(GLcontext *context, GLuint texture, GLint level);
EXPORT void cwcglUpdateObjectBufferATI(GLcontext *context, GLuint buffer, GLuint offset, GLsizei size, const void * pointer, GLenum preserve);
EXPORT void cwcglUseProgram(GLcontext *context, GLuint program);
EXPORT void cwcglUseProgramObjectARB(GLcontext *context, GLhandleARB programObj);
EXPORT void cwcglUseProgramStages(GLcontext *context, GLuint pipeline, GLbitfield stages, GLuint program);
EXPORT void cwcglUseProgramStagesEXT(GLcontext *context, GLuint pipeline, GLbitfield stages, GLuint program);
EXPORT void cwcglUseShaderProgramEXT(GLcontext *context, GLenum type, GLuint program);
EXPORT void cwcglVDPAUFiniNV(GLcontext *context);
EXPORT void cwcglVDPAUGetSurfaceivNV(GLcontext *context, GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values);
EXPORT void cwcglVDPAUInitNV(GLcontext *context, const void * vdpDevice, const void * getProcAddress);
EXPORT void cwcglVDPAUIsSurfaceNV(GLcontext *context, GLvdpauSurfaceNV surface, GLboolean* return_value);
EXPORT void cwcglVDPAUMapSurfacesNV(GLcontext *context, GLsizei numSurfaces, const GLvdpauSurfaceNV * surfaces);
EXPORT void cwcglVDPAURegisterOutputSurfaceNV(GLcontext *context, const void * vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint * textureNames, GLvdpauSurfaceNV* return_value);
EXPORT void cwcglVDPAURegisterVideoSurfaceNV(GLcontext *context, const void * vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint * textureNames, GLvdpauSurfaceNV* return_value);
EXPORT void cwcglVDPAUSurfaceAccessNV(GLcontext *context, GLvdpauSurfaceNV surface, GLenum access);
EXPORT void cwcglVDPAUUnmapSurfacesNV(GLcontext *context, GLsizei numSurface, const GLvdpauSurfaceNV * surfaces);
EXPORT void cwcglVDPAUUnregisterSurfaceNV(GLcontext *context, GLvdpauSurfaceNV surface);
EXPORT void cwcglValidateProgram(GLcontext *context, GLuint program);
EXPORT void cwcglValidateProgramARB(GLcontext *context, GLhandleARB programObj);
EXPORT void cwcglValidateProgramPipeline(GLcontext *context, GLuint pipeline);
EXPORT void cwcglValidateProgramPipelineEXT(GLcontext *context, GLuint pipeline);
EXPORT void cwcglVariantArrayObjectATI(GLcontext *context, GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
EXPORT void cwcglVariantPointerEXT(GLcontext *context, GLuint id, GLenum type, GLuint stride, const void * addr);
EXPORT void cwcglVariantbvEXT(GLcontext *context, GLuint id, const GLbyte * addr);
EXPORT void cwcglVariantdvEXT(GLcontext *context, GLuint id, const GLdouble * addr);
EXPORT void cwcglVariantfvEXT(GLcontext *context, GLuint id, const GLfloat * addr);
EXPORT void cwcglVariantivEXT(GLcontext *context, GLuint id, const GLint * addr);
EXPORT void cwcglVariantsvEXT(GLcontext *context, GLuint id, const GLshort * addr);
EXPORT void cwcglVariantubvEXT(GLcontext *context, GLuint id, const GLubyte * addr);
EXPORT void cwcglVariantuivEXT(GLcontext *context, GLuint id, const GLuint * addr);
EXPORT void cwcglVariantusvEXT(GLcontext *context, GLuint id, const GLushort * addr);
EXPORT void cwcglVertex2bOES(GLcontext *context, GLbyte x, GLbyte y);
EXPORT void cwcglVertex2bvOES(GLcontext *context, const GLbyte * coords);
EXPORT void cwcglVertex2d(GLcontext *context, GLdouble x, GLdouble y);
EXPORT void cwcglVertex2dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglVertex2f(GLcontext *context, GLfloat x, GLfloat y);
EXPORT void cwcglVertex2fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglVertex2hNV(GLcontext *context, GLhalfNV x, GLhalfNV y);
EXPORT void cwcglVertex2hvNV(GLcontext *context, const GLhalfNV * v);
EXPORT void cwcglVertex2i(GLcontext *context, GLint x, GLint y);
EXPORT void cwcglVertex2iv(GLcontext *context, const GLint * v);
EXPORT void cwcglVertex2s(GLcontext *context, GLshort x, GLshort y);
EXPORT void cwcglVertex2sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglVertex2xOES(GLcontext *context, GLfixed x);
EXPORT void cwcglVertex2xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglVertex3bOES(GLcontext *context, GLbyte x, GLbyte y, GLbyte z);
EXPORT void cwcglVertex3bvOES(GLcontext *context, const GLbyte * coords);
EXPORT void cwcglVertex3d(GLcontext *context, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglVertex3dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglVertex3f(GLcontext *context, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglVertex3fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglVertex3hNV(GLcontext *context, GLhalfNV x, GLhalfNV y, GLhalfNV z);
EXPORT void cwcglVertex3hvNV(GLcontext *context, const GLhalfNV * v);
EXPORT void cwcglVertex3i(GLcontext *context, GLint x, GLint y, GLint z);
EXPORT void cwcglVertex3iv(GLcontext *context, const GLint * v);
EXPORT void cwcglVertex3s(GLcontext *context, GLshort x, GLshort y, GLshort z);
EXPORT void cwcglVertex3sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglVertex3xOES(GLcontext *context, GLfixed x, GLfixed y);
EXPORT void cwcglVertex3xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglVertex4bOES(GLcontext *context, GLbyte x, GLbyte y, GLbyte z, GLbyte w);
EXPORT void cwcglVertex4bvOES(GLcontext *context, const GLbyte * coords);
EXPORT void cwcglVertex4d(GLcontext *context, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglVertex4dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglVertex4f(GLcontext *context, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglVertex4fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglVertex4hNV(GLcontext *context, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
EXPORT void cwcglVertex4hvNV(GLcontext *context, const GLhalfNV * v);
EXPORT void cwcglVertex4i(GLcontext *context, GLint x, GLint y, GLint z, GLint w);
EXPORT void cwcglVertex4iv(GLcontext *context, const GLint * v);
EXPORT void cwcglVertex4s(GLcontext *context, GLshort x, GLshort y, GLshort z, GLshort w);
EXPORT void cwcglVertex4sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglVertex4xOES(GLcontext *context, GLfixed x, GLfixed y, GLfixed z);
EXPORT void cwcglVertex4xvOES(GLcontext *context, const GLfixed * coords);
EXPORT void cwcglVertexArrayAttribBinding(GLcontext *context, GLuint vaobj, GLuint attribindex, GLuint bindingindex);
EXPORT void cwcglVertexArrayAttribFormat(GLcontext *context, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
EXPORT void cwcglVertexArrayAttribIFormat(GLcontext *context, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
EXPORT void cwcglVertexArrayAttribLFormat(GLcontext *context, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
EXPORT void cwcglVertexArrayBindVertexBufferEXT(GLcontext *context, GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
EXPORT void cwcglVertexArrayBindingDivisor(GLcontext *context, GLuint vaobj, GLuint bindingindex, GLuint divisor);
EXPORT void cwcglVertexArrayColorOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexArrayEdgeFlagOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexArrayElementBuffer(GLcontext *context, GLuint vaobj, GLuint buffer);
EXPORT void cwcglVertexArrayFogCoordOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexArrayIndexOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexArrayMultiTexCoordOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexArrayNormalOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexArrayParameteriAPPLE(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglVertexArrayRangeAPPLE(GLcontext *context, GLsizei length, void * pointer);
EXPORT void cwcglVertexArrayRangeNV(GLcontext *context, GLsizei length, const void * pointer);
EXPORT void cwcglVertexArraySecondaryColorOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexArrayTexCoordOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexArrayVertexAttribBindingEXT(GLcontext *context, GLuint vaobj, GLuint attribindex, GLuint bindingindex);
EXPORT void cwcglVertexArrayVertexAttribDivisorEXT(GLcontext *context, GLuint vaobj, GLuint index, GLuint divisor);
EXPORT void cwcglVertexArrayVertexAttribFormatEXT(GLcontext *context, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
EXPORT void cwcglVertexArrayVertexAttribIFormatEXT(GLcontext *context, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
EXPORT void cwcglVertexArrayVertexAttribIOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexArrayVertexAttribLFormatEXT(GLcontext *context, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
EXPORT void cwcglVertexArrayVertexAttribLOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexArrayVertexAttribOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexArrayVertexBindingDivisorEXT(GLcontext *context, GLuint vaobj, GLuint bindingindex, GLuint divisor);
EXPORT void cwcglVertexArrayVertexBuffer(GLcontext *context, GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
EXPORT void cwcglVertexArrayVertexBuffers(GLcontext *context, GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
EXPORT void cwcglVertexArrayVertexOffsetEXT(GLcontext *context, GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
EXPORT void cwcglVertexAttrib1d(GLcontext *context, GLuint index, GLdouble x);
EXPORT void cwcglVertexAttrib1dARB(GLcontext *context, GLuint index, GLdouble x);
EXPORT void cwcglVertexAttrib1dNV(GLcontext *context, GLuint index, GLdouble x);
EXPORT void cwcglVertexAttrib1dv(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib1dvARB(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib1dvNV(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib1f(GLcontext *context, GLuint index, GLfloat x);
EXPORT void cwcglVertexAttrib1fARB(GLcontext *context, GLuint index, GLfloat x);
EXPORT void cwcglVertexAttrib1fNV(GLcontext *context, GLuint index, GLfloat x);
EXPORT void cwcglVertexAttrib1fv(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib1fvARB(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib1fvNV(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib1hNV(GLcontext *context, GLuint index, GLhalfNV x);
EXPORT void cwcglVertexAttrib1hvNV(GLcontext *context, GLuint index, const GLhalfNV * v);
EXPORT void cwcglVertexAttrib1s(GLcontext *context, GLuint index, GLshort x);
EXPORT void cwcglVertexAttrib1sARB(GLcontext *context, GLuint index, GLshort x);
EXPORT void cwcglVertexAttrib1sNV(GLcontext *context, GLuint index, GLshort x);
EXPORT void cwcglVertexAttrib1sv(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib1svARB(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib1svNV(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib2d(GLcontext *context, GLuint index, GLdouble x, GLdouble y);
EXPORT void cwcglVertexAttrib2dARB(GLcontext *context, GLuint index, GLdouble x, GLdouble y);
EXPORT void cwcglVertexAttrib2dNV(GLcontext *context, GLuint index, GLdouble x, GLdouble y);
EXPORT void cwcglVertexAttrib2dv(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib2dvARB(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib2dvNV(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib2f(GLcontext *context, GLuint index, GLfloat x, GLfloat y);
EXPORT void cwcglVertexAttrib2fARB(GLcontext *context, GLuint index, GLfloat x, GLfloat y);
EXPORT void cwcglVertexAttrib2fNV(GLcontext *context, GLuint index, GLfloat x, GLfloat y);
EXPORT void cwcglVertexAttrib2fv(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib2fvARB(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib2fvNV(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib2hNV(GLcontext *context, GLuint index, GLhalfNV x, GLhalfNV y);
EXPORT void cwcglVertexAttrib2hvNV(GLcontext *context, GLuint index, const GLhalfNV * v);
EXPORT void cwcglVertexAttrib2s(GLcontext *context, GLuint index, GLshort x, GLshort y);
EXPORT void cwcglVertexAttrib2sARB(GLcontext *context, GLuint index, GLshort x, GLshort y);
EXPORT void cwcglVertexAttrib2sNV(GLcontext *context, GLuint index, GLshort x, GLshort y);
EXPORT void cwcglVertexAttrib2sv(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib2svARB(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib2svNV(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib3d(GLcontext *context, GLuint index, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglVertexAttrib3dARB(GLcontext *context, GLuint index, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglVertexAttrib3dNV(GLcontext *context, GLuint index, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglVertexAttrib3dv(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib3dvARB(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib3dvNV(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib3f(GLcontext *context, GLuint index, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglVertexAttrib3fARB(GLcontext *context, GLuint index, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglVertexAttrib3fNV(GLcontext *context, GLuint index, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglVertexAttrib3fv(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib3fvARB(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib3fvNV(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib3hNV(GLcontext *context, GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
EXPORT void cwcglVertexAttrib3hvNV(GLcontext *context, GLuint index, const GLhalfNV * v);
EXPORT void cwcglVertexAttrib3s(GLcontext *context, GLuint index, GLshort x, GLshort y, GLshort z);
EXPORT void cwcglVertexAttrib3sARB(GLcontext *context, GLuint index, GLshort x, GLshort y, GLshort z);
EXPORT void cwcglVertexAttrib3sNV(GLcontext *context, GLuint index, GLshort x, GLshort y, GLshort z);
EXPORT void cwcglVertexAttrib3sv(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib3svARB(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib3svNV(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib4Nbv(GLcontext *context, GLuint index, const GLbyte * v);
EXPORT void cwcglVertexAttrib4NbvARB(GLcontext *context, GLuint index, const GLbyte * v);
EXPORT void cwcglVertexAttrib4Niv(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttrib4NivARB(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttrib4Nsv(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib4NsvARB(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib4Nub(GLcontext *context, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
EXPORT void cwcglVertexAttrib4NubARB(GLcontext *context, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
EXPORT void cwcglVertexAttrib4Nubv(GLcontext *context, GLuint index, const GLubyte * v);
EXPORT void cwcglVertexAttrib4NubvARB(GLcontext *context, GLuint index, const GLubyte * v);
EXPORT void cwcglVertexAttrib4Nuiv(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttrib4NuivARB(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttrib4Nusv(GLcontext *context, GLuint index, const GLushort * v);
EXPORT void cwcglVertexAttrib4NusvARB(GLcontext *context, GLuint index, const GLushort * v);
EXPORT void cwcglVertexAttrib4bv(GLcontext *context, GLuint index, const GLbyte * v);
EXPORT void cwcglVertexAttrib4bvARB(GLcontext *context, GLuint index, const GLbyte * v);
EXPORT void cwcglVertexAttrib4d(GLcontext *context, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglVertexAttrib4dARB(GLcontext *context, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglVertexAttrib4dNV(GLcontext *context, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglVertexAttrib4dv(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib4dvARB(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib4dvNV(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttrib4f(GLcontext *context, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglVertexAttrib4fARB(GLcontext *context, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglVertexAttrib4fNV(GLcontext *context, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglVertexAttrib4fv(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib4fvARB(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib4fvNV(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglVertexAttrib4hNV(GLcontext *context, GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
EXPORT void cwcglVertexAttrib4hvNV(GLcontext *context, GLuint index, const GLhalfNV * v);
EXPORT void cwcglVertexAttrib4iv(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttrib4ivARB(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttrib4s(GLcontext *context, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
EXPORT void cwcglVertexAttrib4sARB(GLcontext *context, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
EXPORT void cwcglVertexAttrib4sNV(GLcontext *context, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
EXPORT void cwcglVertexAttrib4sv(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib4svARB(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib4svNV(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttrib4ubNV(GLcontext *context, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
EXPORT void cwcglVertexAttrib4ubv(GLcontext *context, GLuint index, const GLubyte * v);
EXPORT void cwcglVertexAttrib4ubvARB(GLcontext *context, GLuint index, const GLubyte * v);
EXPORT void cwcglVertexAttrib4ubvNV(GLcontext *context, GLuint index, const GLubyte * v);
EXPORT void cwcglVertexAttrib4uiv(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttrib4uivARB(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttrib4usv(GLcontext *context, GLuint index, const GLushort * v);
EXPORT void cwcglVertexAttrib4usvARB(GLcontext *context, GLuint index, const GLushort * v);
EXPORT void cwcglVertexAttribArrayObjectATI(GLcontext *context, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
EXPORT void cwcglVertexAttribBinding(GLcontext *context, GLuint attribindex, GLuint bindingindex);
EXPORT void cwcglVertexAttribDivisor(GLcontext *context, GLuint index, GLuint divisor);
EXPORT void cwcglVertexAttribDivisorANGLE(GLcontext *context, GLuint index, GLuint divisor);
EXPORT void cwcglVertexAttribDivisorARB(GLcontext *context, GLuint index, GLuint divisor);
EXPORT void cwcglVertexAttribDivisorEXT(GLcontext *context, GLuint index, GLuint divisor);
EXPORT void cwcglVertexAttribDivisorNV(GLcontext *context, GLuint index, GLuint divisor);
EXPORT void cwcglVertexAttribFormat(GLcontext *context, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
EXPORT void cwcglVertexAttribFormatNV(GLcontext *context, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
EXPORT void cwcglVertexAttribI1i(GLcontext *context, GLuint index, GLint x);
EXPORT void cwcglVertexAttribI1iEXT(GLcontext *context, GLuint index, GLint x);
EXPORT void cwcglVertexAttribI1iv(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttribI1ivEXT(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttribI1ui(GLcontext *context, GLuint index, GLuint x);
EXPORT void cwcglVertexAttribI1uiEXT(GLcontext *context, GLuint index, GLuint x);
EXPORT void cwcglVertexAttribI1uiv(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttribI1uivEXT(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttribI2i(GLcontext *context, GLuint index, GLint x, GLint y);
EXPORT void cwcglVertexAttribI2iEXT(GLcontext *context, GLuint index, GLint x, GLint y);
EXPORT void cwcglVertexAttribI2iv(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttribI2ivEXT(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttribI2ui(GLcontext *context, GLuint index, GLuint x, GLuint y);
EXPORT void cwcglVertexAttribI2uiEXT(GLcontext *context, GLuint index, GLuint x, GLuint y);
EXPORT void cwcglVertexAttribI2uiv(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttribI2uivEXT(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttribI3i(GLcontext *context, GLuint index, GLint x, GLint y, GLint z);
EXPORT void cwcglVertexAttribI3iEXT(GLcontext *context, GLuint index, GLint x, GLint y, GLint z);
EXPORT void cwcglVertexAttribI3iv(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttribI3ivEXT(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttribI3ui(GLcontext *context, GLuint index, GLuint x, GLuint y, GLuint z);
EXPORT void cwcglVertexAttribI3uiEXT(GLcontext *context, GLuint index, GLuint x, GLuint y, GLuint z);
EXPORT void cwcglVertexAttribI3uiv(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttribI3uivEXT(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttribI4bv(GLcontext *context, GLuint index, const GLbyte * v);
EXPORT void cwcglVertexAttribI4bvEXT(GLcontext *context, GLuint index, const GLbyte * v);
EXPORT void cwcglVertexAttribI4i(GLcontext *context, GLuint index, GLint x, GLint y, GLint z, GLint w);
EXPORT void cwcglVertexAttribI4iEXT(GLcontext *context, GLuint index, GLint x, GLint y, GLint z, GLint w);
EXPORT void cwcglVertexAttribI4iv(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttribI4ivEXT(GLcontext *context, GLuint index, const GLint * v);
EXPORT void cwcglVertexAttribI4sv(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttribI4svEXT(GLcontext *context, GLuint index, const GLshort * v);
EXPORT void cwcglVertexAttribI4ubv(GLcontext *context, GLuint index, const GLubyte * v);
EXPORT void cwcglVertexAttribI4ubvEXT(GLcontext *context, GLuint index, const GLubyte * v);
EXPORT void cwcglVertexAttribI4ui(GLcontext *context, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
EXPORT void cwcglVertexAttribI4uiEXT(GLcontext *context, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
EXPORT void cwcglVertexAttribI4uiv(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttribI4uivEXT(GLcontext *context, GLuint index, const GLuint * v);
EXPORT void cwcglVertexAttribI4usv(GLcontext *context, GLuint index, const GLushort * v);
EXPORT void cwcglVertexAttribI4usvEXT(GLcontext *context, GLuint index, const GLushort * v);
EXPORT void cwcglVertexAttribIFormat(GLcontext *context, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
EXPORT void cwcglVertexAttribIFormatNV(GLcontext *context, GLuint index, GLint size, GLenum type, GLsizei stride);
EXPORT void cwcglVertexAttribIPointer(GLcontext *context, GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglVertexAttribIPointerEXT(GLcontext *context, GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglVertexAttribL1d(GLcontext *context, GLuint index, GLdouble x);
EXPORT void cwcglVertexAttribL1dEXT(GLcontext *context, GLuint index, GLdouble x);
EXPORT void cwcglVertexAttribL1dv(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttribL1dvEXT(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttribL1i64NV(GLcontext *context, GLuint index, GLint64EXT x);
EXPORT void cwcglVertexAttribL1i64vNV(GLcontext *context, GLuint index, const GLint64EXT * v);
EXPORT void cwcglVertexAttribL1ui64ARB(GLcontext *context, GLuint index, GLuint64EXT x);
EXPORT void cwcglVertexAttribL1ui64NV(GLcontext *context, GLuint index, GLuint64EXT x);
EXPORT void cwcglVertexAttribL1ui64vARB(GLcontext *context, GLuint index, const GLuint64EXT * v);
EXPORT void cwcglVertexAttribL1ui64vNV(GLcontext *context, GLuint index, const GLuint64EXT * v);
EXPORT void cwcglVertexAttribL2d(GLcontext *context, GLuint index, GLdouble x, GLdouble y);
EXPORT void cwcglVertexAttribL2dEXT(GLcontext *context, GLuint index, GLdouble x, GLdouble y);
EXPORT void cwcglVertexAttribL2dv(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttribL2dvEXT(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttribL2i64NV(GLcontext *context, GLuint index, GLint64EXT x, GLint64EXT y);
EXPORT void cwcglVertexAttribL2i64vNV(GLcontext *context, GLuint index, const GLint64EXT * v);
EXPORT void cwcglVertexAttribL2ui64NV(GLcontext *context, GLuint index, GLuint64EXT x, GLuint64EXT y);
EXPORT void cwcglVertexAttribL2ui64vNV(GLcontext *context, GLuint index, const GLuint64EXT * v);
EXPORT void cwcglVertexAttribL3d(GLcontext *context, GLuint index, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglVertexAttribL3dEXT(GLcontext *context, GLuint index, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglVertexAttribL3dv(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttribL3dvEXT(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttribL3i64NV(GLcontext *context, GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
EXPORT void cwcglVertexAttribL3i64vNV(GLcontext *context, GLuint index, const GLint64EXT * v);
EXPORT void cwcglVertexAttribL3ui64NV(GLcontext *context, GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
EXPORT void cwcglVertexAttribL3ui64vNV(GLcontext *context, GLuint index, const GLuint64EXT * v);
EXPORT void cwcglVertexAttribL4d(GLcontext *context, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglVertexAttribL4dEXT(GLcontext *context, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglVertexAttribL4dv(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttribL4dvEXT(GLcontext *context, GLuint index, const GLdouble * v);
EXPORT void cwcglVertexAttribL4i64NV(GLcontext *context, GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
EXPORT void cwcglVertexAttribL4i64vNV(GLcontext *context, GLuint index, const GLint64EXT * v);
EXPORT void cwcglVertexAttribL4ui64NV(GLcontext *context, GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
EXPORT void cwcglVertexAttribL4ui64vNV(GLcontext *context, GLuint index, const GLuint64EXT * v);
EXPORT void cwcglVertexAttribLFormat(GLcontext *context, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
EXPORT void cwcglVertexAttribLFormatNV(GLcontext *context, GLuint index, GLint size, GLenum type, GLsizei stride);
EXPORT void cwcglVertexAttribLPointer(GLcontext *context, GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglVertexAttribLPointerEXT(GLcontext *context, GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglVertexAttribP1ui(GLcontext *context, GLuint index, GLenum type, GLboolean normalized, GLuint value);
EXPORT void cwcglVertexAttribP1uiv(GLcontext *context, GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
EXPORT void cwcglVertexAttribP2ui(GLcontext *context, GLuint index, GLenum type, GLboolean normalized, GLuint value);
EXPORT void cwcglVertexAttribP2uiv(GLcontext *context, GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
EXPORT void cwcglVertexAttribP3ui(GLcontext *context, GLuint index, GLenum type, GLboolean normalized, GLuint value);
EXPORT void cwcglVertexAttribP3uiv(GLcontext *context, GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
EXPORT void cwcglVertexAttribP4ui(GLcontext *context, GLuint index, GLenum type, GLboolean normalized, GLuint value);
EXPORT void cwcglVertexAttribP4uiv(GLcontext *context, GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
EXPORT void cwcglVertexAttribParameteriAMD(GLcontext *context, GLuint index, GLenum pname, GLint param);
EXPORT void cwcglVertexAttribPointer(GLcontext *context, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
EXPORT void cwcglVertexAttribPointerARB(GLcontext *context, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
EXPORT void cwcglVertexAttribPointerNV(GLcontext *context, GLuint index, GLint fsize, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglVertexAttribs1dvNV(GLcontext *context, GLuint index, GLsizei count, const GLdouble * v);
EXPORT void cwcglVertexAttribs1fvNV(GLcontext *context, GLuint index, GLsizei count, const GLfloat * v);
EXPORT void cwcglVertexAttribs1hvNV(GLcontext *context, GLuint index, GLsizei n, const GLhalfNV * v);
EXPORT void cwcglVertexAttribs1svNV(GLcontext *context, GLuint index, GLsizei count, const GLshort * v);
EXPORT void cwcglVertexAttribs2dvNV(GLcontext *context, GLuint index, GLsizei count, const GLdouble * v);
EXPORT void cwcglVertexAttribs2fvNV(GLcontext *context, GLuint index, GLsizei count, const GLfloat * v);
EXPORT void cwcglVertexAttribs2hvNV(GLcontext *context, GLuint index, GLsizei n, const GLhalfNV * v);
EXPORT void cwcglVertexAttribs2svNV(GLcontext *context, GLuint index, GLsizei count, const GLshort * v);
EXPORT void cwcglVertexAttribs3dvNV(GLcontext *context, GLuint index, GLsizei count, const GLdouble * v);
EXPORT void cwcglVertexAttribs3fvNV(GLcontext *context, GLuint index, GLsizei count, const GLfloat * v);
EXPORT void cwcglVertexAttribs3hvNV(GLcontext *context, GLuint index, GLsizei n, const GLhalfNV * v);
EXPORT void cwcglVertexAttribs3svNV(GLcontext *context, GLuint index, GLsizei count, const GLshort * v);
EXPORT void cwcglVertexAttribs4dvNV(GLcontext *context, GLuint index, GLsizei count, const GLdouble * v);
EXPORT void cwcglVertexAttribs4fvNV(GLcontext *context, GLuint index, GLsizei count, const GLfloat * v);
EXPORT void cwcglVertexAttribs4hvNV(GLcontext *context, GLuint index, GLsizei n, const GLhalfNV * v);
EXPORT void cwcglVertexAttribs4svNV(GLcontext *context, GLuint index, GLsizei count, const GLshort * v);
EXPORT void cwcglVertexAttribs4ubvNV(GLcontext *context, GLuint index, GLsizei count, const GLubyte * v);
EXPORT void cwcglVertexBindingDivisor(GLcontext *context, GLuint bindingindex, GLuint divisor);
EXPORT void cwcglVertexBlendARB(GLcontext *context, GLint count);
EXPORT void cwcglVertexBlendEnvfATI(GLcontext *context, GLenum pname, GLfloat param);
EXPORT void cwcglVertexBlendEnviATI(GLcontext *context, GLenum pname, GLint param);
EXPORT void cwcglVertexFormatNV(GLcontext *context, GLint size, GLenum type, GLsizei stride);
EXPORT void cwcglVertexP2ui(GLcontext *context, GLenum type, GLuint value);
EXPORT void cwcglVertexP2uiv(GLcontext *context, GLenum type, const GLuint * value);
EXPORT void cwcglVertexP3ui(GLcontext *context, GLenum type, GLuint value);
EXPORT void cwcglVertexP3uiv(GLcontext *context, GLenum type, const GLuint * value);
EXPORT void cwcglVertexP4ui(GLcontext *context, GLenum type, GLuint value);
EXPORT void cwcglVertexP4uiv(GLcontext *context, GLenum type, const GLuint * value);
EXPORT void cwcglVertexPointer(GLcontext *context, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglVertexPointerEXT(GLcontext *context, GLint size, GLenum type, GLsizei stride, GLsizei count, const void * pointer);
EXPORT void cwcglVertexPointerListIBM(GLcontext *context, GLint size, GLenum type, GLint stride, const void ** pointer, GLint ptrstride);
EXPORT void cwcglVertexPointervINTEL(GLcontext *context, GLint size, GLenum type, const void ** pointer);
EXPORT void cwcglVertexStream1dATI(GLcontext *context, GLenum stream, GLdouble x);
EXPORT void cwcglVertexStream1dvATI(GLcontext *context, GLenum stream, const GLdouble * coords);
EXPORT void cwcglVertexStream1fATI(GLcontext *context, GLenum stream, GLfloat x);
EXPORT void cwcglVertexStream1fvATI(GLcontext *context, GLenum stream, const GLfloat * coords);
EXPORT void cwcglVertexStream1iATI(GLcontext *context, GLenum stream, GLint x);
EXPORT void cwcglVertexStream1ivATI(GLcontext *context, GLenum stream, const GLint * coords);
EXPORT void cwcglVertexStream1sATI(GLcontext *context, GLenum stream, GLshort x);
EXPORT void cwcglVertexStream1svATI(GLcontext *context, GLenum stream, const GLshort * coords);
EXPORT void cwcglVertexStream2dATI(GLcontext *context, GLenum stream, GLdouble x, GLdouble y);
EXPORT void cwcglVertexStream2dvATI(GLcontext *context, GLenum stream, const GLdouble * coords);
EXPORT void cwcglVertexStream2fATI(GLcontext *context, GLenum stream, GLfloat x, GLfloat y);
EXPORT void cwcglVertexStream2fvATI(GLcontext *context, GLenum stream, const GLfloat * coords);
EXPORT void cwcglVertexStream2iATI(GLcontext *context, GLenum stream, GLint x, GLint y);
EXPORT void cwcglVertexStream2ivATI(GLcontext *context, GLenum stream, const GLint * coords);
EXPORT void cwcglVertexStream2sATI(GLcontext *context, GLenum stream, GLshort x, GLshort y);
EXPORT void cwcglVertexStream2svATI(GLcontext *context, GLenum stream, const GLshort * coords);
EXPORT void cwcglVertexStream3dATI(GLcontext *context, GLenum stream, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglVertexStream3dvATI(GLcontext *context, GLenum stream, const GLdouble * coords);
EXPORT void cwcglVertexStream3fATI(GLcontext *context, GLenum stream, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglVertexStream3fvATI(GLcontext *context, GLenum stream, const GLfloat * coords);
EXPORT void cwcglVertexStream3iATI(GLcontext *context, GLenum stream, GLint x, GLint y, GLint z);
EXPORT void cwcglVertexStream3ivATI(GLcontext *context, GLenum stream, const GLint * coords);
EXPORT void cwcglVertexStream3sATI(GLcontext *context, GLenum stream, GLshort x, GLshort y, GLshort z);
EXPORT void cwcglVertexStream3svATI(GLcontext *context, GLenum stream, const GLshort * coords);
EXPORT void cwcglVertexStream4dATI(GLcontext *context, GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglVertexStream4dvATI(GLcontext *context, GLenum stream, const GLdouble * coords);
EXPORT void cwcglVertexStream4fATI(GLcontext *context, GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglVertexStream4fvATI(GLcontext *context, GLenum stream, const GLfloat * coords);
EXPORT void cwcglVertexStream4iATI(GLcontext *context, GLenum stream, GLint x, GLint y, GLint z, GLint w);
EXPORT void cwcglVertexStream4ivATI(GLcontext *context, GLenum stream, const GLint * coords);
EXPORT void cwcglVertexStream4sATI(GLcontext *context, GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
EXPORT void cwcglVertexStream4svATI(GLcontext *context, GLenum stream, const GLshort * coords);
EXPORT void cwcglVertexWeightPointerEXT(GLcontext *context, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglVertexWeightfEXT(GLcontext *context, GLfloat weight);
EXPORT void cwcglVertexWeightfvEXT(GLcontext *context, const GLfloat * weight);
EXPORT void cwcglVertexWeighthNV(GLcontext *context, GLhalfNV weight);
EXPORT void cwcglVertexWeighthvNV(GLcontext *context, const GLhalfNV * weight);
EXPORT void cwcglVideoCaptureNV(GLcontext *context, GLuint video_capture_slot, GLuint * sequence_num, GLuint64EXT * capture_time, GLenum* return_value);
EXPORT void cwcglVideoCaptureStreamParameterdvNV(GLcontext *context, GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble * params);
EXPORT void cwcglVideoCaptureStreamParameterfvNV(GLcontext *context, GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat * params);
EXPORT void cwcglVideoCaptureStreamParameterivNV(GLcontext *context, GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint * params);
EXPORT void cwcglViewport(GLcontext *context, GLint x, GLint y, GLsizei width, GLsizei height);
EXPORT void cwcglViewportArrayv(GLcontext *context, GLuint first, GLsizei count, const GLfloat * v);
EXPORT void cwcglViewportArrayvNV(GLcontext *context, GLuint first, GLsizei count, const GLfloat * v);
EXPORT void cwcglViewportArrayvOES(GLcontext *context, GLuint first, GLsizei count, const GLfloat * v);
EXPORT void cwcglViewportIndexedf(GLcontext *context, GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
EXPORT void cwcglViewportIndexedfOES(GLcontext *context, GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
EXPORT void cwcglViewportIndexedfNV(GLcontext *context, GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
EXPORT void cwcglViewportIndexedfv(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglViewportIndexedfvOES(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglViewportIndexedfvNV(GLcontext *context, GLuint index, const GLfloat * v);
EXPORT void cwcglViewportPositionWScaleNV(GLcontext *context, GLuint index, GLfloat xcoeff, GLfloat ycoeff);
EXPORT void cwcglViewportSwizzleNV(GLcontext *context, GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
EXPORT void cwcglWaitSync(GLcontext *context, GLsync sync, GLbitfield flags, GLuint64 timeout);
EXPORT void cwcglWaitSyncAPPLE(GLcontext *context, GLsync sync, GLbitfield flags, GLuint64 timeout);
EXPORT void cwcglWeightPathsNV(GLcontext *context, GLuint resultPath, GLsizei numPaths, const GLuint * paths, const GLfloat * weights);
EXPORT void cwcglWeightPointerARB(GLcontext *context, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglWeightPointerOES(GLcontext *context, GLint size, GLenum type, GLsizei stride, const void * pointer);
EXPORT void cwcglWeightbvARB(GLcontext *context, GLint size, const GLbyte * weights);
EXPORT void cwcglWeightdvARB(GLcontext *context, GLint size, const GLdouble * weights);
EXPORT void cwcglWeightfvARB(GLcontext *context, GLint size, const GLfloat * weights);
EXPORT void cwcglWeightivARB(GLcontext *context, GLint size, const GLint * weights);
EXPORT void cwcglWeightsvARB(GLcontext *context, GLint size, const GLshort * weights);
EXPORT void cwcglWeightubvARB(GLcontext *context, GLint size, const GLubyte * weights);
EXPORT void cwcglWeightuivARB(GLcontext *context, GLint size, const GLuint * weights);
EXPORT void cwcglWeightusvARB(GLcontext *context, GLint size, const GLushort * weights);
EXPORT void cwcglWindowPos2d(GLcontext *context, GLdouble x, GLdouble y);
EXPORT void cwcglWindowPos2dARB(GLcontext *context, GLdouble x, GLdouble y);
EXPORT void cwcglWindowPos2dMESA(GLcontext *context, GLdouble x, GLdouble y);
EXPORT void cwcglWindowPos2dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglWindowPos2dvARB(GLcontext *context, const GLdouble * v);
EXPORT void cwcglWindowPos2dvMESA(GLcontext *context, const GLdouble * v);
EXPORT void cwcglWindowPos2f(GLcontext *context, GLfloat x, GLfloat y);
EXPORT void cwcglWindowPos2fARB(GLcontext *context, GLfloat x, GLfloat y);
EXPORT void cwcglWindowPos2fMESA(GLcontext *context, GLfloat x, GLfloat y);
EXPORT void cwcglWindowPos2fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglWindowPos2fvARB(GLcontext *context, const GLfloat * v);
EXPORT void cwcglWindowPos2fvMESA(GLcontext *context, const GLfloat * v);
EXPORT void cwcglWindowPos2i(GLcontext *context, GLint x, GLint y);
EXPORT void cwcglWindowPos2iARB(GLcontext *context, GLint x, GLint y);
EXPORT void cwcglWindowPos2iMESA(GLcontext *context, GLint x, GLint y);
EXPORT void cwcglWindowPos2iv(GLcontext *context, const GLint * v);
EXPORT void cwcglWindowPos2ivARB(GLcontext *context, const GLint * v);
EXPORT void cwcglWindowPos2ivMESA(GLcontext *context, const GLint * v);
EXPORT void cwcglWindowPos2s(GLcontext *context, GLshort x, GLshort y);
EXPORT void cwcglWindowPos2sARB(GLcontext *context, GLshort x, GLshort y);
EXPORT void cwcglWindowPos2sMESA(GLcontext *context, GLshort x, GLshort y);
EXPORT void cwcglWindowPos2sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglWindowPos2svARB(GLcontext *context, const GLshort * v);
EXPORT void cwcglWindowPos2svMESA(GLcontext *context, const GLshort * v);
EXPORT void cwcglWindowPos3d(GLcontext *context, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglWindowPos3dARB(GLcontext *context, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglWindowPos3dMESA(GLcontext *context, GLdouble x, GLdouble y, GLdouble z);
EXPORT void cwcglWindowPos3dv(GLcontext *context, const GLdouble * v);
EXPORT void cwcglWindowPos3dvARB(GLcontext *context, const GLdouble * v);
EXPORT void cwcglWindowPos3dvMESA(GLcontext *context, const GLdouble * v);
EXPORT void cwcglWindowPos3f(GLcontext *context, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglWindowPos3fARB(GLcontext *context, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglWindowPos3fMESA(GLcontext *context, GLfloat x, GLfloat y, GLfloat z);
EXPORT void cwcglWindowPos3fv(GLcontext *context, const GLfloat * v);
EXPORT void cwcglWindowPos3fvARB(GLcontext *context, const GLfloat * v);
EXPORT void cwcglWindowPos3fvMESA(GLcontext *context, const GLfloat * v);
EXPORT void cwcglWindowPos3i(GLcontext *context, GLint x, GLint y, GLint z);
EXPORT void cwcglWindowPos3iARB(GLcontext *context, GLint x, GLint y, GLint z);
EXPORT void cwcglWindowPos3iMESA(GLcontext *context, GLint x, GLint y, GLint z);
EXPORT void cwcglWindowPos3iv(GLcontext *context, const GLint * v);
EXPORT void cwcglWindowPos3ivARB(GLcontext *context, const GLint * v);
EXPORT void cwcglWindowPos3ivMESA(GLcontext *context, const GLint * v);
EXPORT void cwcglWindowPos3s(GLcontext *context, GLshort x, GLshort y, GLshort z);
EXPORT void cwcglWindowPos3sARB(GLcontext *context, GLshort x, GLshort y, GLshort z);
EXPORT void cwcglWindowPos3sMESA(GLcontext *context, GLshort x, GLshort y, GLshort z);
EXPORT void cwcglWindowPos3sv(GLcontext *context, const GLshort * v);
EXPORT void cwcglWindowPos3svARB(GLcontext *context, const GLshort * v);
EXPORT void cwcglWindowPos3svMESA(GLcontext *context, const GLshort * v);
EXPORT void cwcglWindowPos4dMESA(GLcontext *context, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
EXPORT void cwcglWindowPos4dvMESA(GLcontext *context, const GLdouble * v);
EXPORT void cwcglWindowPos4fMESA(GLcontext *context, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
EXPORT void cwcglWindowPos4fvMESA(GLcontext *context, const GLfloat * v);
EXPORT void cwcglWindowPos4iMESA(GLcontext *context, GLint x, GLint y, GLint z, GLint w);
EXPORT void cwcglWindowPos4ivMESA(GLcontext *context, const GLint * v);
EXPORT void cwcglWindowPos4sMESA(GLcontext *context, GLshort x, GLshort y, GLshort z, GLshort w);
EXPORT void cwcglWindowPos4svMESA(GLcontext *context, const GLshort * v);
EXPORT void cwcglWindowRectanglesEXT(GLcontext *context, GLenum mode, GLsizei count, const GLint * box);
EXPORT void cwcglWriteMaskEXT(GLcontext *context, GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
