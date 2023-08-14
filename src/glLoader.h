/* glLoader.h -- https://github.com/takeiteasy/fungl

 Inspired by https://github.com/tsherif/simple-opengl-loader + Dav1dde/glad
 Function address loading functions taken from https://github.com/Dav1dde/glad
 
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

#ifndef opengl_loader_h
#define opengl_loader_h
#ifdef __cplusplus
extern "C" {
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

typedef void* (*glLoadProc)(const char *name);
GLAPI int glLoadFunctions(void);
GLAPI int glLoadGLLoader(glLoadProc);

#if !defined(GL_LOAD_VERSION)
#define GL_LOAD_VERSION 1000
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
#define GL_VERSION_4_6 4060

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

#if defined(GL_ALL_EXTENSIONS)
#define GL_EXT_AMD_framebuffer_multisample_advanced
#define GL_EXT_AMD_performance_monitor
#define GL_EXT_APPLE_rgb_422
#define GL_EXT_ARB_ES2_compatibility
#define GL_EXT_ARB_ES3_1_compatibility
#define GL_EXT_ARB_ES3_2_compatibility
#define GL_EXT_ARB_ES3_compatibility
#define GL_EXT_ARB_base_instance
#define GL_EXT_ARB_bindless_texture
#define GL_EXT_ARB_blend_func_extended
#define GL_EXT_ARB_buffer_storage
#define GL_EXT_ARB_cl_event
#define GL_EXT_ARB_clear_buffer_object
#define GL_EXT_ARB_clear_texture
#define GL_EXT_ARB_clip_control
#define GL_EXT_ARB_compressed_texture_pixel_storage
#define GL_EXT_ARB_compute_shader
#define GL_EXT_ARB_compute_variable_group_size
#define GL_EXT_ARB_conditional_render_inverted
#define GL_EXT_ARB_copy_buffer
#define GL_EXT_ARB_copy_image
#define GL_EXT_ARB_cull_distance
#define GL_EXT_ARB_debug_output
#define GL_EXT_ARB_depth_buffer_float
#define GL_EXT_ARB_depth_clamp
#define GL_EXT_ARB_direct_state_access
#define GL_EXT_ARB_draw_buffers_blend
#define GL_EXT_ARB_draw_elements_base_vertex
#define GL_EXT_ARB_draw_indirect
#define GL_EXT_ARB_draw_instanced
#define GL_EXT_ARB_enhanced_layouts
#define GL_EXT_ARB_explicit_uniform_location
#define GL_EXT_ARB_framebuffer_no_attachments
#define GL_EXT_ARB_framebuffer_object
#define GL_EXT_ARB_framebuffer_sRGB
#define GL_EXT_ARB_geometry_shader4
#define GL_EXT_ARB_get_program_binary
#define GL_EXT_ARB_get_texture_sub_image
#define GL_EXT_ARB_gl_spirv
#define GL_EXT_ARB_gpu_shader5
#define GL_EXT_ARB_gpu_shader_fp64
#define GL_EXT_ARB_gpu_shader_int64
#define GL_EXT_ARB_half_float_vertex
#define GL_EXT_ARB_imaging
#define GL_EXT_ARB_indirect_parameters
#define GL_EXT_ARB_instanced_arrays
#define GL_EXT_ARB_internalformat_query
#define GL_EXT_ARB_internalformat_query2
#define GL_EXT_ARB_invalidate_subdata
#define GL_EXT_ARB_map_buffer_alignment
#define GL_EXT_ARB_map_buffer_range
#define GL_EXT_ARB_multi_bind
#define GL_EXT_ARB_multi_draw_indirect
#define GL_EXT_ARB_occlusion_query2
#define GL_EXT_ARB_parallel_shader_compile
#define GL_EXT_ARB_pipeline_statistics_query
#define GL_EXT_ARB_pixel_buffer_object
#define GL_EXT_ARB_polygon_offset_clamp
#define GL_EXT_ARB_program_interface_query
#define GL_EXT_ARB_provoking_vertex
#define GL_EXT_ARB_query_buffer_object
#define GL_EXT_ARB_robustness
#define GL_EXT_ARB_sample_locations
#define GL_EXT_ARB_sample_shading
#define GL_EXT_ARB_sampler_objects
#define GL_EXT_ARB_seamless_cube_map
#define GL_EXT_ARB_seamless_cubemap_per_texture
#define GL_EXT_ARB_separate_shader_objects
#define GL_EXT_ARB_shader_atomic_counters
#define GL_EXT_ARB_shader_image_load_store
#define GL_EXT_ARB_shader_storage_buffer_object
#define GL_EXT_ARB_shader_subroutine
#define GL_EXT_ARB_shading_language_include
#define GL_EXT_ARB_sparse_buffer
#define GL_EXT_ARB_sparse_texture
#define GL_EXT_ARB_spirv_extensions
#define GL_EXT_ARB_stencil_texturing
#define GL_EXT_ARB_sync
#define GL_EXT_ARB_tessellation_shader
#define GL_EXT_ARB_texture_barrier
#define GL_EXT_ARB_texture_border_clamp
#define GL_EXT_ARB_texture_buffer_object
#define GL_EXT_ARB_texture_buffer_object_rgb32
#define GL_EXT_ARB_texture_buffer_range
#define GL_EXT_ARB_texture_compression_bptc
#define GL_EXT_ARB_texture_compression_rgtc
#define GL_EXT_ARB_texture_cube_map_array
#define GL_EXT_ARB_texture_filter_anisotropic
#define GL_EXT_ARB_texture_filter_minmax
#define GL_EXT_ARB_texture_gather
#define GL_EXT_ARB_texture_mirror_clamp_to_edge
#define GL_EXT_ARB_texture_mirrored_repeat
#define GL_EXT_ARB_texture_multisample
#define GL_EXT_ARB_texture_rg
#define GL_EXT_ARB_texture_rgb10_a2ui
#define GL_EXT_ARB_texture_stencil8
#define GL_EXT_ARB_texture_storage
#define GL_EXT_ARB_texture_storage_multisample
#define GL_EXT_ARB_texture_swizzle
#define GL_EXT_ARB_texture_view
#define GL_EXT_ARB_timer_query
#define GL_EXT_ARB_transform_feedback2
#define GL_EXT_ARB_transform_feedback3
#define GL_EXT_ARB_transform_feedback_instanced
#define GL_EXT_ARB_transform_feedback_overflow_query
#define GL_EXT_ARB_uniform_buffer_object
#define GL_EXT_ARB_vertex_array_bgra
#define GL_EXT_ARB_vertex_array_object
#define GL_EXT_ARB_vertex_attrib_64bit
#define GL_EXT_ARB_vertex_attrib_binding
#define GL_EXT_ARB_vertex_type_10f_11f_11f_rev
#define GL_EXT_ARB_vertex_type_2_10_10_10_rev
#define GL_EXT_ARB_viewport_array
#define GL_EXT_EXT_EGL_image_storage
#define GL_EXT_EXT_debug_label
#define GL_EXT_EXT_debug_marker
#define GL_EXT_EXT_direct_state_access
#define GL_EXT_EXT_draw_instanced
#define GL_EXT_EXT_polygon_offset_clamp
#define GL_EXT_EXT_raster_multisample
#define GL_EXT_EXT_separate_shader_objects
#define GL_EXT_EXT_shader_framebuffer_fetch
#define GL_EXT_EXT_shader_framebuffer_fetch_non_coherent
#define GL_EXT_EXT_texture_compression_s3tc
#define GL_EXT_EXT_texture_filter_minmax
#define GL_EXT_EXT_texture_sRGB_R8
#define GL_EXT_EXT_texture_sRGB_RG8
#define GL_EXT_EXT_texture_sRGB_decode
#define GL_EXT_EXT_texture_storage
#define GL_EXT_EXT_window_rectangles
#define GL_EXT_INTEL_conservative_rasterization
#define GL_EXT_INTEL_framebuffer_CMAA
#define GL_EXT_INTEL_blackhole_render
#define GL_EXT_INTEL_performance_query
#define GL_EXT_KHR_blend_equation_advanced
#define GL_EXT_KHR_blend_equation_advanced_coherent
#define GL_EXT_KHR_context_flush_control
#define GL_EXT_KHR_debug
#define GL_EXT_KHR_no_error
#define GL_EXT_KHR_robustness
#define GL_EXT_KHR_shader_subgroup
#define GL_EXT_KHR_texture_compression_astc_hdr
#define GL_EXT_KHR_texture_compression_astc_ldr
#define GL_EXT_KHR_parallel_shader_compile
#define GL_EXT_MESA_framebuffer_flip_x
#define GL_EXT_MESA_framebuffer_flip_y
#define GL_EXT_MESA_framebuffer_swap_xy
#define GL_EXT_NV_bindless_multi_draw_indirect
#define GL_EXT_NV_bindless_multi_draw_indirect_count
#define GL_EXT_NV_bindless_texture
#define GL_EXT_NV_blend_equation_advanced
#define GL_EXT_NV_blend_equation_advanced_coherent
#define GL_EXT_NV_blend_minmax_factor
#define GL_EXT_NV_clip_space_w_scaling
#define GL_EXT_NV_command_list
#define GL_EXT_NV_conditional_render
#define GL_EXT_NV_conservative_raster
#define GL_EXT_NV_conservative_raster_dilate
#define GL_EXT_NV_conservative_raster_pre_snap
#define GL_EXT_NV_conservative_raster_pre_snap_triangles
#define GL_EXT_NV_depth_buffer_float
#define GL_EXT_NV_draw_vulkan_image
#define GL_EXT_NV_fill_rectangle
#define GL_EXT_NV_fragment_coverage_to_color
#define GL_EXT_NV_framebuffer_mixed_samples
#define GL_EXT_NV_framebuffer_multisample_coverage
#define GL_EXT_NV_gpu_shader5
#define GL_EXT_NV_internalformat_sample_query
#define GL_EXT_NV_memory_attachment
#define GL_EXT_NV_memory_object_sparse
#define GL_EXT_NV_mesh_shader
#define GL_EXT_NV_path_rendering
#define GL_EXT_NV_path_rendering_shared_edge
#define GL_EXT_NV_primitive_shading_rate
#define GL_EXT_NV_representative_fragment_test
#define GL_EXT_NV_sample_locations
#define GL_EXT_NV_scissor_exclusive
#define GL_EXT_NV_shader_buffer_load
#define GL_EXT_NV_shader_buffer_store
#define GL_EXT_NV_shader_subgroup_partitioned
#define GL_EXT_NV_shader_thread_group
#define GL_EXT_NV_shading_rate_image
#define GL_EXT_NV_texture_barrier
#define GL_EXT_NV_uniform_buffer_unified_memory
#define GL_EXT_NV_vertex_attrib_integer_64bit
#define GL_EXT_NV_vertex_buffer_unified_memory
#define GL_EXT_NV_viewport_swizzle
#define GL_EXT_OVR_multiview
#endif // GL_ALL_EXTENSIONS

#if GL_LOAD_VERSION >= GL_VERSION_1_0
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
typedef khronos_int16_t GLshort;
typedef khronos_uint16_t GLushort;
typedef void GLvoid;
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
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_BORDER_COLOR 0x1004
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
#define GL_REPEAT 0x2901
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
#define GL_ALPHA_TEST 0x0BC0
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_ALPHA_TEST_REF 0x0BC2
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
#define GL_TEXTURE_COMPONENTS 0x1003
#define GL_TEXTURE_BORDER 0x1005
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
typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
#define glCullFace gll_glCullFace
typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
#define glFrontFace gll_glFrontFace
typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
#define glHint gll_glHint
typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
#define glLineWidth gll_glLineWidth
typedef void (APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
#define glPointSize gll_glPointSize
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
#define glPolygonMode gll_glPolygonMode
typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
#define glScissor gll_glScissor
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
#define glTexParameterf gll_glTexParameterf
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat * params);
#define glTexParameterfv gll_glTexParameterfv
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
#define glTexParameteri gll_glTexParameteri
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint * params);
#define glTexParameteriv gll_glTexParameteriv
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage1D gll_glTexImage1D
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage2D gll_glTexImage2D
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum buf);
#define glDrawBuffer gll_glDrawBuffer
typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
#define glClear gll_glClear
typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glClearColor gll_glClearColor
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
#define glClearStencil gll_glClearStencil
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble depth);
#define glClearDepth gll_glClearDepth
typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
#define glStencilMask gll_glStencilMask
typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
#define glColorMask gll_glColorMask
typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
#define glDepthMask gll_glDepthMask
typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
#define glDisable gll_glDisable
typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
#define glEnable gll_glEnable
typedef void (APIENTRYP PFNGLFINISHPROC)(void);
#define glFinish gll_glFinish
typedef void (APIENTRYP PFNGLFLUSHPROC)(void);
#define glFlush gll_glFlush
typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
#define glBlendFunc gll_glBlendFunc
typedef void (APIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
#define glLogicOp gll_glLogicOp
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
#define glStencilFunc gll_glStencilFunc
typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
#define glStencilOp gll_glStencilOp
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
#define glDepthFunc gll_glDepthFunc
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
#define glPixelStoref gll_glPixelStoref
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
#define glPixelStorei gll_glPixelStorei
typedef void (APIENTRYP PFNGLREADBUFFERPROC)(GLenum src);
#define glReadBuffer gll_glReadBuffer
typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
#define glReadPixels gll_glReadPixels
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean * data);
#define glGetBooleanv gll_glGetBooleanv
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble * data);
#define glGetDoublev gll_glGetDoublev
typedef GLenum (APIENTRYP PFNGLGETERRORPROC)(void);
#define glGetError gll_glGetError
typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat * data);
#define glGetFloatv gll_glGetFloatv
typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint * data);
#define glGetIntegerv gll_glGetIntegerv
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
#define glGetString gll_glGetString
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
#define glGetTexImage gll_glGetTexImage
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat * params);
#define glGetTexParameterfv gll_glGetTexParameterfv
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetTexParameteriv gll_glGetTexParameteriv
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat * params);
#define glGetTexLevelParameterfv gll_glGetTexLevelParameterfv
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint * params);
#define glGetTexLevelParameteriv gll_glGetTexLevelParameteriv
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
#define glIsEnabled gll_glIsEnabled
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble n, GLdouble f);
#define glDepthRange gll_glDepthRange
typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
#define glViewport gll_glViewport
typedef void (APIENTRYP PFNGLNEWLISTPROC)(GLuint list, GLenum mode);
#define glNewList gll_glNewList
typedef void (APIENTRYP PFNGLENDLISTPROC)(void);
#define glEndList gll_glEndList
typedef void (APIENTRYP PFNGLCALLLISTPROC)(GLuint list);
#define glCallList gll_glCallList
typedef void (APIENTRYP PFNGLCALLLISTSPROC)(GLsizei n, GLenum type, const void * lists);
#define glCallLists gll_glCallLists
typedef void (APIENTRYP PFNGLDELETELISTSPROC)(GLuint list, GLsizei range);
#define glDeleteLists gll_glDeleteLists
typedef GLuint (APIENTRYP PFNGLGENLISTSPROC)(GLsizei range);
#define glGenLists gll_glGenLists
typedef void (APIENTRYP PFNGLLISTBASEPROC)(GLuint base);
#define glListBase gll_glListBase
typedef void (APIENTRYP PFNGLBEGINPROC)(GLenum mode);
#define glBegin gll_glBegin
typedef void (APIENTRYP PFNGLBITMAPPROC)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap);
#define glBitmap gll_glBitmap
typedef void (APIENTRYP PFNGLCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
#define glColor3b gll_glColor3b
typedef void (APIENTRYP PFNGLCOLOR3BVPROC)(const GLbyte * v);
#define glColor3bv gll_glColor3bv
typedef void (APIENTRYP PFNGLCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
#define glColor3d gll_glColor3d
typedef void (APIENTRYP PFNGLCOLOR3DVPROC)(const GLdouble * v);
#define glColor3dv gll_glColor3dv
typedef void (APIENTRYP PFNGLCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
#define glColor3f gll_glColor3f
typedef void (APIENTRYP PFNGLCOLOR3FVPROC)(const GLfloat * v);
#define glColor3fv gll_glColor3fv
typedef void (APIENTRYP PFNGLCOLOR3IPROC)(GLint red, GLint green, GLint blue);
#define glColor3i gll_glColor3i
typedef void (APIENTRYP PFNGLCOLOR3IVPROC)(const GLint * v);
#define glColor3iv gll_glColor3iv
typedef void (APIENTRYP PFNGLCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
#define glColor3s gll_glColor3s
typedef void (APIENTRYP PFNGLCOLOR3SVPROC)(const GLshort * v);
#define glColor3sv gll_glColor3sv
typedef void (APIENTRYP PFNGLCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
#define glColor3ub gll_glColor3ub
typedef void (APIENTRYP PFNGLCOLOR3UBVPROC)(const GLubyte * v);
#define glColor3ubv gll_glColor3ubv
typedef void (APIENTRYP PFNGLCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
#define glColor3ui gll_glColor3ui
typedef void (APIENTRYP PFNGLCOLOR3UIVPROC)(const GLuint * v);
#define glColor3uiv gll_glColor3uiv
typedef void (APIENTRYP PFNGLCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
#define glColor3us gll_glColor3us
typedef void (APIENTRYP PFNGLCOLOR3USVPROC)(const GLushort * v);
#define glColor3usv gll_glColor3usv
typedef void (APIENTRYP PFNGLCOLOR4BPROC)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
#define glColor4b gll_glColor4b
typedef void (APIENTRYP PFNGLCOLOR4BVPROC)(const GLbyte * v);
#define glColor4bv gll_glColor4bv
typedef void (APIENTRYP PFNGLCOLOR4DPROC)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
#define glColor4d gll_glColor4d
typedef void (APIENTRYP PFNGLCOLOR4DVPROC)(const GLdouble * v);
#define glColor4dv gll_glColor4dv
typedef void (APIENTRYP PFNGLCOLOR4FPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glColor4f gll_glColor4f
typedef void (APIENTRYP PFNGLCOLOR4FVPROC)(const GLfloat * v);
#define glColor4fv gll_glColor4fv
typedef void (APIENTRYP PFNGLCOLOR4IPROC)(GLint red, GLint green, GLint blue, GLint alpha);
#define glColor4i gll_glColor4i
typedef void (APIENTRYP PFNGLCOLOR4IVPROC)(const GLint * v);
#define glColor4iv gll_glColor4iv
typedef void (APIENTRYP PFNGLCOLOR4SPROC)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
#define glColor4s gll_glColor4s
typedef void (APIENTRYP PFNGLCOLOR4SVPROC)(const GLshort * v);
#define glColor4sv gll_glColor4sv
typedef void (APIENTRYP PFNGLCOLOR4UBPROC)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
#define glColor4ub gll_glColor4ub
typedef void (APIENTRYP PFNGLCOLOR4UBVPROC)(const GLubyte * v);
#define glColor4ubv gll_glColor4ubv
typedef void (APIENTRYP PFNGLCOLOR4UIPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
#define glColor4ui gll_glColor4ui
typedef void (APIENTRYP PFNGLCOLOR4UIVPROC)(const GLuint * v);
#define glColor4uiv gll_glColor4uiv
typedef void (APIENTRYP PFNGLCOLOR4USPROC)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
#define glColor4us gll_glColor4us
typedef void (APIENTRYP PFNGLCOLOR4USVPROC)(const GLushort * v);
#define glColor4usv gll_glColor4usv
typedef void (APIENTRYP PFNGLEDGEFLAGPROC)(GLboolean flag);
#define glEdgeFlag gll_glEdgeFlag
typedef void (APIENTRYP PFNGLEDGEFLAGVPROC)(const GLboolean * flag);
#define glEdgeFlagv gll_glEdgeFlagv
typedef void (APIENTRYP PFNGLENDPROC)(void);
#define glEnd gll_glEnd
typedef void (APIENTRYP PFNGLINDEXDPROC)(GLdouble c);
#define glIndexd gll_glIndexd
typedef void (APIENTRYP PFNGLINDEXDVPROC)(const GLdouble * c);
#define glIndexdv gll_glIndexdv
typedef void (APIENTRYP PFNGLINDEXFPROC)(GLfloat c);
#define glIndexf gll_glIndexf
typedef void (APIENTRYP PFNGLINDEXFVPROC)(const GLfloat * c);
#define glIndexfv gll_glIndexfv
typedef void (APIENTRYP PFNGLINDEXIPROC)(GLint c);
#define glIndexi gll_glIndexi
typedef void (APIENTRYP PFNGLINDEXIVPROC)(const GLint * c);
#define glIndexiv gll_glIndexiv
typedef void (APIENTRYP PFNGLINDEXSPROC)(GLshort c);
#define glIndexs gll_glIndexs
typedef void (APIENTRYP PFNGLINDEXSVPROC)(const GLshort * c);
#define glIndexsv gll_glIndexsv
typedef void (APIENTRYP PFNGLNORMAL3BPROC)(GLbyte nx, GLbyte ny, GLbyte nz);
#define glNormal3b gll_glNormal3b
typedef void (APIENTRYP PFNGLNORMAL3BVPROC)(const GLbyte * v);
#define glNormal3bv gll_glNormal3bv
typedef void (APIENTRYP PFNGLNORMAL3DPROC)(GLdouble nx, GLdouble ny, GLdouble nz);
#define glNormal3d gll_glNormal3d
typedef void (APIENTRYP PFNGLNORMAL3DVPROC)(const GLdouble * v);
#define glNormal3dv gll_glNormal3dv
typedef void (APIENTRYP PFNGLNORMAL3FPROC)(GLfloat nx, GLfloat ny, GLfloat nz);
#define glNormal3f gll_glNormal3f
typedef void (APIENTRYP PFNGLNORMAL3FVPROC)(const GLfloat * v);
#define glNormal3fv gll_glNormal3fv
typedef void (APIENTRYP PFNGLNORMAL3IPROC)(GLint nx, GLint ny, GLint nz);
#define glNormal3i gll_glNormal3i
typedef void (APIENTRYP PFNGLNORMAL3IVPROC)(const GLint * v);
#define glNormal3iv gll_glNormal3iv
typedef void (APIENTRYP PFNGLNORMAL3SPROC)(GLshort nx, GLshort ny, GLshort nz);
#define glNormal3s gll_glNormal3s
typedef void (APIENTRYP PFNGLNORMAL3SVPROC)(const GLshort * v);
#define glNormal3sv gll_glNormal3sv
typedef void (APIENTRYP PFNGLRASTERPOS2DPROC)(GLdouble x, GLdouble y);
#define glRasterPos2d gll_glRasterPos2d
typedef void (APIENTRYP PFNGLRASTERPOS2DVPROC)(const GLdouble * v);
#define glRasterPos2dv gll_glRasterPos2dv
typedef void (APIENTRYP PFNGLRASTERPOS2FPROC)(GLfloat x, GLfloat y);
#define glRasterPos2f gll_glRasterPos2f
typedef void (APIENTRYP PFNGLRASTERPOS2FVPROC)(const GLfloat * v);
#define glRasterPos2fv gll_glRasterPos2fv
typedef void (APIENTRYP PFNGLRASTERPOS2IPROC)(GLint x, GLint y);
#define glRasterPos2i gll_glRasterPos2i
typedef void (APIENTRYP PFNGLRASTERPOS2IVPROC)(const GLint * v);
#define glRasterPos2iv gll_glRasterPos2iv
typedef void (APIENTRYP PFNGLRASTERPOS2SPROC)(GLshort x, GLshort y);
#define glRasterPos2s gll_glRasterPos2s
typedef void (APIENTRYP PFNGLRASTERPOS2SVPROC)(const GLshort * v);
#define glRasterPos2sv gll_glRasterPos2sv
typedef void (APIENTRYP PFNGLRASTERPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glRasterPos3d gll_glRasterPos3d
typedef void (APIENTRYP PFNGLRASTERPOS3DVPROC)(const GLdouble * v);
#define glRasterPos3dv gll_glRasterPos3dv
typedef void (APIENTRYP PFNGLRASTERPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glRasterPos3f gll_glRasterPos3f
typedef void (APIENTRYP PFNGLRASTERPOS3FVPROC)(const GLfloat * v);
#define glRasterPos3fv gll_glRasterPos3fv
typedef void (APIENTRYP PFNGLRASTERPOS3IPROC)(GLint x, GLint y, GLint z);
#define glRasterPos3i gll_glRasterPos3i
typedef void (APIENTRYP PFNGLRASTERPOS3IVPROC)(const GLint * v);
#define glRasterPos3iv gll_glRasterPos3iv
typedef void (APIENTRYP PFNGLRASTERPOS3SPROC)(GLshort x, GLshort y, GLshort z);
#define glRasterPos3s gll_glRasterPos3s
typedef void (APIENTRYP PFNGLRASTERPOS3SVPROC)(const GLshort * v);
#define glRasterPos3sv gll_glRasterPos3sv
typedef void (APIENTRYP PFNGLRASTERPOS4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glRasterPos4d gll_glRasterPos4d
typedef void (APIENTRYP PFNGLRASTERPOS4DVPROC)(const GLdouble * v);
#define glRasterPos4dv gll_glRasterPos4dv
typedef void (APIENTRYP PFNGLRASTERPOS4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glRasterPos4f gll_glRasterPos4f
typedef void (APIENTRYP PFNGLRASTERPOS4FVPROC)(const GLfloat * v);
#define glRasterPos4fv gll_glRasterPos4fv
typedef void (APIENTRYP PFNGLRASTERPOS4IPROC)(GLint x, GLint y, GLint z, GLint w);
#define glRasterPos4i gll_glRasterPos4i
typedef void (APIENTRYP PFNGLRASTERPOS4IVPROC)(const GLint * v);
#define glRasterPos4iv gll_glRasterPos4iv
typedef void (APIENTRYP PFNGLRASTERPOS4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
#define glRasterPos4s gll_glRasterPos4s
typedef void (APIENTRYP PFNGLRASTERPOS4SVPROC)(const GLshort * v);
#define glRasterPos4sv gll_glRasterPos4sv
typedef void (APIENTRYP PFNGLRECTDPROC)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
#define glRectd gll_glRectd
typedef void (APIENTRYP PFNGLRECTDVPROC)(const GLdouble * v1, const GLdouble * v2);
#define glRectdv gll_glRectdv
typedef void (APIENTRYP PFNGLRECTFPROC)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
#define glRectf gll_glRectf
typedef void (APIENTRYP PFNGLRECTFVPROC)(const GLfloat * v1, const GLfloat * v2);
#define glRectfv gll_glRectfv
typedef void (APIENTRYP PFNGLRECTIPROC)(GLint x1, GLint y1, GLint x2, GLint y2);
#define glRecti gll_glRecti
typedef void (APIENTRYP PFNGLRECTIVPROC)(const GLint * v1, const GLint * v2);
#define glRectiv gll_glRectiv
typedef void (APIENTRYP PFNGLRECTSPROC)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
#define glRects gll_glRects
typedef void (APIENTRYP PFNGLRECTSVPROC)(const GLshort * v1, const GLshort * v2);
#define glRectsv gll_glRectsv
typedef void (APIENTRYP PFNGLTEXCOORD1DPROC)(GLdouble s);
#define glTexCoord1d gll_glTexCoord1d
typedef void (APIENTRYP PFNGLTEXCOORD1DVPROC)(const GLdouble * v);
#define glTexCoord1dv gll_glTexCoord1dv
typedef void (APIENTRYP PFNGLTEXCOORD1FPROC)(GLfloat s);
#define glTexCoord1f gll_glTexCoord1f
typedef void (APIENTRYP PFNGLTEXCOORD1FVPROC)(const GLfloat * v);
#define glTexCoord1fv gll_glTexCoord1fv
typedef void (APIENTRYP PFNGLTEXCOORD1IPROC)(GLint s);
#define glTexCoord1i gll_glTexCoord1i
typedef void (APIENTRYP PFNGLTEXCOORD1IVPROC)(const GLint * v);
#define glTexCoord1iv gll_glTexCoord1iv
typedef void (APIENTRYP PFNGLTEXCOORD1SPROC)(GLshort s);
#define glTexCoord1s gll_glTexCoord1s
typedef void (APIENTRYP PFNGLTEXCOORD1SVPROC)(const GLshort * v);
#define glTexCoord1sv gll_glTexCoord1sv
typedef void (APIENTRYP PFNGLTEXCOORD2DPROC)(GLdouble s, GLdouble t);
#define glTexCoord2d gll_glTexCoord2d
typedef void (APIENTRYP PFNGLTEXCOORD2DVPROC)(const GLdouble * v);
#define glTexCoord2dv gll_glTexCoord2dv
typedef void (APIENTRYP PFNGLTEXCOORD2FPROC)(GLfloat s, GLfloat t);
#define glTexCoord2f gll_glTexCoord2f
typedef void (APIENTRYP PFNGLTEXCOORD2FVPROC)(const GLfloat * v);
#define glTexCoord2fv gll_glTexCoord2fv
typedef void (APIENTRYP PFNGLTEXCOORD2IPROC)(GLint s, GLint t);
#define glTexCoord2i gll_glTexCoord2i
typedef void (APIENTRYP PFNGLTEXCOORD2IVPROC)(const GLint * v);
#define glTexCoord2iv gll_glTexCoord2iv
typedef void (APIENTRYP PFNGLTEXCOORD2SPROC)(GLshort s, GLshort t);
#define glTexCoord2s gll_glTexCoord2s
typedef void (APIENTRYP PFNGLTEXCOORD2SVPROC)(const GLshort * v);
#define glTexCoord2sv gll_glTexCoord2sv
typedef void (APIENTRYP PFNGLTEXCOORD3DPROC)(GLdouble s, GLdouble t, GLdouble r);
#define glTexCoord3d gll_glTexCoord3d
typedef void (APIENTRYP PFNGLTEXCOORD3DVPROC)(const GLdouble * v);
#define glTexCoord3dv gll_glTexCoord3dv
typedef void (APIENTRYP PFNGLTEXCOORD3FPROC)(GLfloat s, GLfloat t, GLfloat r);
#define glTexCoord3f gll_glTexCoord3f
typedef void (APIENTRYP PFNGLTEXCOORD3FVPROC)(const GLfloat * v);
#define glTexCoord3fv gll_glTexCoord3fv
typedef void (APIENTRYP PFNGLTEXCOORD3IPROC)(GLint s, GLint t, GLint r);
#define glTexCoord3i gll_glTexCoord3i
typedef void (APIENTRYP PFNGLTEXCOORD3IVPROC)(const GLint * v);
#define glTexCoord3iv gll_glTexCoord3iv
typedef void (APIENTRYP PFNGLTEXCOORD3SPROC)(GLshort s, GLshort t, GLshort r);
#define glTexCoord3s gll_glTexCoord3s
typedef void (APIENTRYP PFNGLTEXCOORD3SVPROC)(const GLshort * v);
#define glTexCoord3sv gll_glTexCoord3sv
typedef void (APIENTRYP PFNGLTEXCOORD4DPROC)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#define glTexCoord4d gll_glTexCoord4d
typedef void (APIENTRYP PFNGLTEXCOORD4DVPROC)(const GLdouble * v);
#define glTexCoord4dv gll_glTexCoord4dv
typedef void (APIENTRYP PFNGLTEXCOORD4FPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#define glTexCoord4f gll_glTexCoord4f
typedef void (APIENTRYP PFNGLTEXCOORD4FVPROC)(const GLfloat * v);
#define glTexCoord4fv gll_glTexCoord4fv
typedef void (APIENTRYP PFNGLTEXCOORD4IPROC)(GLint s, GLint t, GLint r, GLint q);
#define glTexCoord4i gll_glTexCoord4i
typedef void (APIENTRYP PFNGLTEXCOORD4IVPROC)(const GLint * v);
#define glTexCoord4iv gll_glTexCoord4iv
typedef void (APIENTRYP PFNGLTEXCOORD4SPROC)(GLshort s, GLshort t, GLshort r, GLshort q);
#define glTexCoord4s gll_glTexCoord4s
typedef void (APIENTRYP PFNGLTEXCOORD4SVPROC)(const GLshort * v);
#define glTexCoord4sv gll_glTexCoord4sv
typedef void (APIENTRYP PFNGLVERTEX2DPROC)(GLdouble x, GLdouble y);
#define glVertex2d gll_glVertex2d
typedef void (APIENTRYP PFNGLVERTEX2DVPROC)(const GLdouble * v);
#define glVertex2dv gll_glVertex2dv
typedef void (APIENTRYP PFNGLVERTEX2FPROC)(GLfloat x, GLfloat y);
#define glVertex2f gll_glVertex2f
typedef void (APIENTRYP PFNGLVERTEX2FVPROC)(const GLfloat * v);
#define glVertex2fv gll_glVertex2fv
typedef void (APIENTRYP PFNGLVERTEX2IPROC)(GLint x, GLint y);
#define glVertex2i gll_glVertex2i
typedef void (APIENTRYP PFNGLVERTEX2IVPROC)(const GLint * v);
#define glVertex2iv gll_glVertex2iv
typedef void (APIENTRYP PFNGLVERTEX2SPROC)(GLshort x, GLshort y);
#define glVertex2s gll_glVertex2s
typedef void (APIENTRYP PFNGLVERTEX2SVPROC)(const GLshort * v);
#define glVertex2sv gll_glVertex2sv
typedef void (APIENTRYP PFNGLVERTEX3DPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glVertex3d gll_glVertex3d
typedef void (APIENTRYP PFNGLVERTEX3DVPROC)(const GLdouble * v);
#define glVertex3dv gll_glVertex3dv
typedef void (APIENTRYP PFNGLVERTEX3FPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glVertex3f gll_glVertex3f
typedef void (APIENTRYP PFNGLVERTEX3FVPROC)(const GLfloat * v);
#define glVertex3fv gll_glVertex3fv
typedef void (APIENTRYP PFNGLVERTEX3IPROC)(GLint x, GLint y, GLint z);
#define glVertex3i gll_glVertex3i
typedef void (APIENTRYP PFNGLVERTEX3IVPROC)(const GLint * v);
#define glVertex3iv gll_glVertex3iv
typedef void (APIENTRYP PFNGLVERTEX3SPROC)(GLshort x, GLshort y, GLshort z);
#define glVertex3s gll_glVertex3s
typedef void (APIENTRYP PFNGLVERTEX3SVPROC)(const GLshort * v);
#define glVertex3sv gll_glVertex3sv
typedef void (APIENTRYP PFNGLVERTEX4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertex4d gll_glVertex4d
typedef void (APIENTRYP PFNGLVERTEX4DVPROC)(const GLdouble * v);
#define glVertex4dv gll_glVertex4dv
typedef void (APIENTRYP PFNGLVERTEX4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertex4f gll_glVertex4f
typedef void (APIENTRYP PFNGLVERTEX4FVPROC)(const GLfloat * v);
#define glVertex4fv gll_glVertex4fv
typedef void (APIENTRYP PFNGLVERTEX4IPROC)(GLint x, GLint y, GLint z, GLint w);
#define glVertex4i gll_glVertex4i
typedef void (APIENTRYP PFNGLVERTEX4IVPROC)(const GLint * v);
#define glVertex4iv gll_glVertex4iv
typedef void (APIENTRYP PFNGLVERTEX4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertex4s gll_glVertex4s
typedef void (APIENTRYP PFNGLVERTEX4SVPROC)(const GLshort * v);
#define glVertex4sv gll_glVertex4sv
typedef void (APIENTRYP PFNGLCLIPPLANEPROC)(GLenum plane, const GLdouble * equation);
#define glClipPlane gll_glClipPlane
typedef void (APIENTRYP PFNGLCOLORMATERIALPROC)(GLenum face, GLenum mode);
#define glColorMaterial gll_glColorMaterial
typedef void (APIENTRYP PFNGLFOGFPROC)(GLenum pname, GLfloat param);
#define glFogf gll_glFogf
typedef void (APIENTRYP PFNGLFOGFVPROC)(GLenum pname, const GLfloat * params);
#define glFogfv gll_glFogfv
typedef void (APIENTRYP PFNGLFOGIPROC)(GLenum pname, GLint param);
#define glFogi gll_glFogi
typedef void (APIENTRYP PFNGLFOGIVPROC)(GLenum pname, const GLint * params);
#define glFogiv gll_glFogiv
typedef void (APIENTRYP PFNGLLIGHTFPROC)(GLenum light, GLenum pname, GLfloat param);
#define glLightf gll_glLightf
typedef void (APIENTRYP PFNGLLIGHTFVPROC)(GLenum light, GLenum pname, const GLfloat * params);
#define glLightfv gll_glLightfv
typedef void (APIENTRYP PFNGLLIGHTIPROC)(GLenum light, GLenum pname, GLint param);
#define glLighti gll_glLighti
typedef void (APIENTRYP PFNGLLIGHTIVPROC)(GLenum light, GLenum pname, const GLint * params);
#define glLightiv gll_glLightiv
typedef void (APIENTRYP PFNGLLIGHTMODELFPROC)(GLenum pname, GLfloat param);
#define glLightModelf gll_glLightModelf
typedef void (APIENTRYP PFNGLLIGHTMODELFVPROC)(GLenum pname, const GLfloat * params);
#define glLightModelfv gll_glLightModelfv
typedef void (APIENTRYP PFNGLLIGHTMODELIPROC)(GLenum pname, GLint param);
#define glLightModeli gll_glLightModeli
typedef void (APIENTRYP PFNGLLIGHTMODELIVPROC)(GLenum pname, const GLint * params);
#define glLightModeliv gll_glLightModeliv
typedef void (APIENTRYP PFNGLLINESTIPPLEPROC)(GLint factor, GLushort pattern);
#define glLineStipple gll_glLineStipple
typedef void (APIENTRYP PFNGLMATERIALFPROC)(GLenum face, GLenum pname, GLfloat param);
#define glMaterialf gll_glMaterialf
typedef void (APIENTRYP PFNGLMATERIALFVPROC)(GLenum face, GLenum pname, const GLfloat * params);
#define glMaterialfv gll_glMaterialfv
typedef void (APIENTRYP PFNGLMATERIALIPROC)(GLenum face, GLenum pname, GLint param);
#define glMateriali gll_glMateriali
typedef void (APIENTRYP PFNGLMATERIALIVPROC)(GLenum face, GLenum pname, const GLint * params);
#define glMaterialiv gll_glMaterialiv
typedef void (APIENTRYP PFNGLPOLYGONSTIPPLEPROC)(const GLubyte * mask);
#define glPolygonStipple gll_glPolygonStipple
typedef void (APIENTRYP PFNGLSHADEMODELPROC)(GLenum mode);
#define glShadeModel gll_glShadeModel
typedef void (APIENTRYP PFNGLTEXENVFPROC)(GLenum target, GLenum pname, GLfloat param);
#define glTexEnvf gll_glTexEnvf
typedef void (APIENTRYP PFNGLTEXENVFVPROC)(GLenum target, GLenum pname, const GLfloat * params);
#define glTexEnvfv gll_glTexEnvfv
typedef void (APIENTRYP PFNGLTEXENVIPROC)(GLenum target, GLenum pname, GLint param);
#define glTexEnvi gll_glTexEnvi
typedef void (APIENTRYP PFNGLTEXENVIVPROC)(GLenum target, GLenum pname, const GLint * params);
#define glTexEnviv gll_glTexEnviv
typedef void (APIENTRYP PFNGLTEXGENDPROC)(GLenum coord, GLenum pname, GLdouble param);
#define glTexGend gll_glTexGend
typedef void (APIENTRYP PFNGLTEXGENDVPROC)(GLenum coord, GLenum pname, const GLdouble * params);
#define glTexGendv gll_glTexGendv
typedef void (APIENTRYP PFNGLTEXGENFPROC)(GLenum coord, GLenum pname, GLfloat param);
#define glTexGenf gll_glTexGenf
typedef void (APIENTRYP PFNGLTEXGENFVPROC)(GLenum coord, GLenum pname, const GLfloat * params);
#define glTexGenfv gll_glTexGenfv
typedef void (APIENTRYP PFNGLTEXGENIPROC)(GLenum coord, GLenum pname, GLint param);
#define glTexGeni gll_glTexGeni
typedef void (APIENTRYP PFNGLTEXGENIVPROC)(GLenum coord, GLenum pname, const GLint * params);
#define glTexGeniv gll_glTexGeniv
typedef void (APIENTRYP PFNGLFEEDBACKBUFFERPROC)(GLsizei size, GLenum type, GLfloat * buffer);
#define glFeedbackBuffer gll_glFeedbackBuffer
typedef void (APIENTRYP PFNGLSELECTBUFFERPROC)(GLsizei size, GLuint * buffer);
#define glSelectBuffer gll_glSelectBuffer
typedef GLint (APIENTRYP PFNGLRENDERMODEPROC)(GLenum mode);
#define glRenderMode gll_glRenderMode
typedef void (APIENTRYP PFNGLINITNAMESPROC)(void);
#define glInitNames gll_glInitNames
typedef void (APIENTRYP PFNGLLOADNAMEPROC)(GLuint name);
#define glLoadName gll_glLoadName
typedef void (APIENTRYP PFNGLPASSTHROUGHPROC)(GLfloat token);
#define glPassThrough gll_glPassThrough
typedef void (APIENTRYP PFNGLPOPNAMEPROC)(void);
#define glPopName gll_glPopName
typedef void (APIENTRYP PFNGLPUSHNAMEPROC)(GLuint name);
#define glPushName gll_glPushName
typedef void (APIENTRYP PFNGLCLEARACCUMPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glClearAccum gll_glClearAccum
typedef void (APIENTRYP PFNGLCLEARINDEXPROC)(GLfloat c);
#define glClearIndex gll_glClearIndex
typedef void (APIENTRYP PFNGLINDEXMASKPROC)(GLuint mask);
#define glIndexMask gll_glIndexMask
typedef void (APIENTRYP PFNGLACCUMPROC)(GLenum op, GLfloat value);
#define glAccum gll_glAccum
typedef void (APIENTRYP PFNGLPOPATTRIBPROC)(void);
#define glPopAttrib gll_glPopAttrib
typedef void (APIENTRYP PFNGLPUSHATTRIBPROC)(GLbitfield mask);
#define glPushAttrib gll_glPushAttrib
typedef void (APIENTRYP PFNGLMAP1DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points);
#define glMap1d gll_glMap1d
typedef void (APIENTRYP PFNGLMAP1FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points);
#define glMap1f gll_glMap1f
typedef void (APIENTRYP PFNGLMAP2DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points);
#define glMap2d gll_glMap2d
typedef void (APIENTRYP PFNGLMAP2FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points);
#define glMap2f gll_glMap2f
typedef void (APIENTRYP PFNGLMAPGRID1DPROC)(GLint un, GLdouble u1, GLdouble u2);
#define glMapGrid1d gll_glMapGrid1d
typedef void (APIENTRYP PFNGLMAPGRID1FPROC)(GLint un, GLfloat u1, GLfloat u2);
#define glMapGrid1f gll_glMapGrid1f
typedef void (APIENTRYP PFNGLMAPGRID2DPROC)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
#define glMapGrid2d gll_glMapGrid2d
typedef void (APIENTRYP PFNGLMAPGRID2FPROC)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
#define glMapGrid2f gll_glMapGrid2f
typedef void (APIENTRYP PFNGLEVALCOORD1DPROC)(GLdouble u);
#define glEvalCoord1d gll_glEvalCoord1d
typedef void (APIENTRYP PFNGLEVALCOORD1DVPROC)(const GLdouble * u);
#define glEvalCoord1dv gll_glEvalCoord1dv
typedef void (APIENTRYP PFNGLEVALCOORD1FPROC)(GLfloat u);
#define glEvalCoord1f gll_glEvalCoord1f
typedef void (APIENTRYP PFNGLEVALCOORD1FVPROC)(const GLfloat * u);
#define glEvalCoord1fv gll_glEvalCoord1fv
typedef void (APIENTRYP PFNGLEVALCOORD2DPROC)(GLdouble u, GLdouble v);
#define glEvalCoord2d gll_glEvalCoord2d
typedef void (APIENTRYP PFNGLEVALCOORD2DVPROC)(const GLdouble * u);
#define glEvalCoord2dv gll_glEvalCoord2dv
typedef void (APIENTRYP PFNGLEVALCOORD2FPROC)(GLfloat u, GLfloat v);
#define glEvalCoord2f gll_glEvalCoord2f
typedef void (APIENTRYP PFNGLEVALCOORD2FVPROC)(const GLfloat * u);
#define glEvalCoord2fv gll_glEvalCoord2fv
typedef void (APIENTRYP PFNGLEVALMESH1PROC)(GLenum mode, GLint i1, GLint i2);
#define glEvalMesh1 gll_glEvalMesh1
typedef void (APIENTRYP PFNGLEVALPOINT1PROC)(GLint i);
#define glEvalPoint1 gll_glEvalPoint1
typedef void (APIENTRYP PFNGLEVALMESH2PROC)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
#define glEvalMesh2 gll_glEvalMesh2
typedef void (APIENTRYP PFNGLEVALPOINT2PROC)(GLint i, GLint j);
#define glEvalPoint2 gll_glEvalPoint2
typedef void (APIENTRYP PFNGLALPHAFUNCPROC)(GLenum func, GLfloat ref);
#define glAlphaFunc gll_glAlphaFunc
typedef void (APIENTRYP PFNGLPIXELZOOMPROC)(GLfloat xfactor, GLfloat yfactor);
#define glPixelZoom gll_glPixelZoom
typedef void (APIENTRYP PFNGLPIXELTRANSFERFPROC)(GLenum pname, GLfloat param);
#define glPixelTransferf gll_glPixelTransferf
typedef void (APIENTRYP PFNGLPIXELTRANSFERIPROC)(GLenum pname, GLint param);
#define glPixelTransferi gll_glPixelTransferi
typedef void (APIENTRYP PFNGLPIXELMAPFVPROC)(GLenum map, GLsizei mapsize, const GLfloat * values);
#define glPixelMapfv gll_glPixelMapfv
typedef void (APIENTRYP PFNGLPIXELMAPUIVPROC)(GLenum map, GLsizei mapsize, const GLuint * values);
#define glPixelMapuiv gll_glPixelMapuiv
typedef void (APIENTRYP PFNGLPIXELMAPUSVPROC)(GLenum map, GLsizei mapsize, const GLushort * values);
#define glPixelMapusv gll_glPixelMapusv
typedef void (APIENTRYP PFNGLCOPYPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
#define glCopyPixels gll_glCopyPixels
typedef void (APIENTRYP PFNGLDRAWPIXELSPROC)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glDrawPixels gll_glDrawPixels
typedef void (APIENTRYP PFNGLGETCLIPPLANEPROC)(GLenum plane, GLdouble * equation);
#define glGetClipPlane gll_glGetClipPlane
typedef void (APIENTRYP PFNGLGETLIGHTFVPROC)(GLenum light, GLenum pname, GLfloat * params);
#define glGetLightfv gll_glGetLightfv
typedef void (APIENTRYP PFNGLGETLIGHTIVPROC)(GLenum light, GLenum pname, GLint * params);
#define glGetLightiv gll_glGetLightiv
typedef void (APIENTRYP PFNGLGETMAPDVPROC)(GLenum target, GLenum query, GLdouble * v);
#define glGetMapdv gll_glGetMapdv
typedef void (APIENTRYP PFNGLGETMAPFVPROC)(GLenum target, GLenum query, GLfloat * v);
#define glGetMapfv gll_glGetMapfv
typedef void (APIENTRYP PFNGLGETMAPIVPROC)(GLenum target, GLenum query, GLint * v);
#define glGetMapiv gll_glGetMapiv
typedef void (APIENTRYP PFNGLGETMATERIALFVPROC)(GLenum face, GLenum pname, GLfloat * params);
#define glGetMaterialfv gll_glGetMaterialfv
typedef void (APIENTRYP PFNGLGETMATERIALIVPROC)(GLenum face, GLenum pname, GLint * params);
#define glGetMaterialiv gll_glGetMaterialiv
typedef void (APIENTRYP PFNGLGETPIXELMAPFVPROC)(GLenum map, GLfloat * values);
#define glGetPixelMapfv gll_glGetPixelMapfv
typedef void (APIENTRYP PFNGLGETPIXELMAPUIVPROC)(GLenum map, GLuint * values);
#define glGetPixelMapuiv gll_glGetPixelMapuiv
typedef void (APIENTRYP PFNGLGETPIXELMAPUSVPROC)(GLenum map, GLushort * values);
#define glGetPixelMapusv gll_glGetPixelMapusv
typedef void (APIENTRYP PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte * mask);
#define glGetPolygonStipple gll_glGetPolygonStipple
typedef void (APIENTRYP PFNGLGETTEXENVFVPROC)(GLenum target, GLenum pname, GLfloat * params);
#define glGetTexEnvfv gll_glGetTexEnvfv
typedef void (APIENTRYP PFNGLGETTEXENVIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetTexEnviv gll_glGetTexEnviv
typedef void (APIENTRYP PFNGLGETTEXGENDVPROC)(GLenum coord, GLenum pname, GLdouble * params);
#define glGetTexGendv gll_glGetTexGendv
typedef void (APIENTRYP PFNGLGETTEXGENFVPROC)(GLenum coord, GLenum pname, GLfloat * params);
#define glGetTexGenfv gll_glGetTexGenfv
typedef void (APIENTRYP PFNGLGETTEXGENIVPROC)(GLenum coord, GLenum pname, GLint * params);
#define glGetTexGeniv gll_glGetTexGeniv
typedef GLboolean (APIENTRYP PFNGLISLISTPROC)(GLuint list);
#define glIsList gll_glIsList
typedef void (APIENTRYP PFNGLFRUSTUMPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glFrustum gll_glFrustum
typedef void (APIENTRYP PFNGLLOADIDENTITYPROC)(void);
#define glLoadIdentity gll_glLoadIdentity
typedef void (APIENTRYP PFNGLLOADMATRIXFPROC)(const GLfloat * m);
#define glLoadMatrixf gll_glLoadMatrixf
typedef void (APIENTRYP PFNGLLOADMATRIXDPROC)(const GLdouble * m);
#define glLoadMatrixd gll_glLoadMatrixd
typedef void (APIENTRYP PFNGLMATRIXMODEPROC)(GLenum mode);
#define glMatrixMode gll_glMatrixMode
typedef void (APIENTRYP PFNGLMULTMATRIXFPROC)(const GLfloat * m);
#define glMultMatrixf gll_glMultMatrixf
typedef void (APIENTRYP PFNGLMULTMATRIXDPROC)(const GLdouble * m);
#define glMultMatrixd gll_glMultMatrixd
typedef void (APIENTRYP PFNGLORTHOPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glOrtho gll_glOrtho
typedef void (APIENTRYP PFNGLPOPMATRIXPROC)(void);
#define glPopMatrix gll_glPopMatrix
typedef void (APIENTRYP PFNGLPUSHMATRIXPROC)(void);
#define glPushMatrix gll_glPushMatrix
typedef void (APIENTRYP PFNGLROTATEDPROC)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
#define glRotated gll_glRotated
typedef void (APIENTRYP PFNGLROTATEFPROC)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
#define glRotatef gll_glRotatef
typedef void (APIENTRYP PFNGLSCALEDPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glScaled gll_glScaled
typedef void (APIENTRYP PFNGLSCALEFPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glScalef gll_glScalef
typedef void (APIENTRYP PFNGLTRANSLATEDPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glTranslated gll_glTranslated
typedef void (APIENTRYP PFNGLTRANSLATEFPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glTranslatef gll_glTranslatef
#endif

#if GL_LOAD_VERSION >= GL_VERSION_1_1
typedef khronos_float_t GLclampf;
typedef double GLclampd;
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_DOUBLE 0x140A
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
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
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_COLOR_ARRAY_POINTER 0x8090
#define GL_INDEX_ARRAY_POINTER 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#define GL_SELECTION_BUFFER_POINTER 0x0DF3
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define GL_INDEX_LOGIC_OP 0x0BF1
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
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
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_TEXTURE_INTENSITY_SIZE 0x8061
#define GL_TEXTURE_PRIORITY 0x8066
#define GL_TEXTURE_RESIDENT 0x8067
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
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
#define glDrawArrays gll_glDrawArrays
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices);
#define glDrawElements gll_glDrawElements
typedef void (APIENTRYP PFNGLGETPOINTERVPROC)(GLenum pname, void ** params);
#define glGetPointerv gll_glGetPointerv
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
#define glPolygonOffset gll_glPolygonOffset
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyTexImage1D gll_glCopyTexImage1D
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyTexImage2D gll_glCopyTexImage2D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTexSubImage1D gll_glCopyTexSubImage1D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage2D gll_glCopyTexSubImage2D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage1D gll_glTexSubImage1D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage2D gll_glTexSubImage2D
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
#define glBindTexture gll_glBindTexture
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint * textures);
#define glDeleteTextures gll_glDeleteTextures
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint * textures);
#define glGenTextures gll_glGenTextures
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
#define glIsTexture gll_glIsTexture
typedef void (APIENTRYP PFNGLARRAYELEMENTPROC)(GLint i);
#define glArrayElement gll_glArrayElement
typedef void (APIENTRYP PFNGLCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glColorPointer gll_glColorPointer
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEPROC)(GLenum array);
#define glDisableClientState gll_glDisableClientState
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTERPROC)(GLsizei stride, const void * pointer);
#define glEdgeFlagPointer gll_glEdgeFlagPointer
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEPROC)(GLenum array);
#define glEnableClientState gll_glEnableClientState
typedef void (APIENTRYP PFNGLINDEXPOINTERPROC)(GLenum type, GLsizei stride, const void * pointer);
#define glIndexPointer gll_glIndexPointer
typedef void (APIENTRYP PFNGLINTERLEAVEDARRAYSPROC)(GLenum format, GLsizei stride, const void * pointer);
#define glInterleavedArrays gll_glInterleavedArrays
typedef void (APIENTRYP PFNGLNORMALPOINTERPROC)(GLenum type, GLsizei stride, const void * pointer);
#define glNormalPointer gll_glNormalPointer
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glTexCoordPointer gll_glTexCoordPointer
typedef void (APIENTRYP PFNGLVERTEXPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexPointer gll_glVertexPointer
typedef GLboolean (APIENTRYP PFNGLARETEXTURESRESIDENTPROC)(GLsizei n, const GLuint * textures, GLboolean * residences);
#define glAreTexturesResident gll_glAreTexturesResident
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESPROC)(GLsizei n, const GLuint * textures, const GLfloat * priorities);
#define glPrioritizeTextures gll_glPrioritizeTextures
typedef void (APIENTRYP PFNGLINDEXUBPROC)(GLubyte c);
#define glIndexub gll_glIndexub
typedef void (APIENTRYP PFNGLINDEXUBVPROC)(const GLubyte * c);
#define glIndexubv gll_glIndexubv
typedef void (APIENTRYP PFNGLPOPCLIENTATTRIBPROC)(void);
#define glPopClientAttrib gll_glPopClientAttrib
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield mask);
#define glPushClientAttrib gll_glPushClientAttrib
#endif

#if GL_LOAD_VERSION >= GL_VERSION_1_2
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
#define glDrawRangeElements gll_glDrawRangeElements
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTexImage3D gll_glTexImage3D
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTexSubImage3D gll_glTexSubImage3D
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage3D gll_glCopyTexSubImage3D
#endif

#if GL_LOAD_VERSION >= GL_VERSION_1_3
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
#define glActiveTexture gll_glActiveTexture
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
#define glSampleCoverage gll_glSampleCoverage
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage3D gll_glCompressedTexImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage2D gll_glCompressedTexImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
#define glCompressedTexImage1D gll_glCompressedTexImage1D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage3D gll_glCompressedTexSubImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage2D gll_glCompressedTexSubImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTexSubImage1D gll_glCompressedTexSubImage1D
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint level, void * img);
#define glGetCompressedTexImage gll_glGetCompressedTexImage
typedef void (APIENTRYP PFNGLCLIENTACTIVETEXTUREPROC)(GLenum texture);
#define glClientActiveTexture gll_glClientActiveTexture
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DPROC)(GLenum target, GLdouble s);
#define glMultiTexCoord1d gll_glMultiTexCoord1d
typedef void (APIENTRYP PFNGLMULTITEXCOORD1DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord1dv gll_glMultiTexCoord1dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FPROC)(GLenum target, GLfloat s);
#define glMultiTexCoord1f gll_glMultiTexCoord1f
typedef void (APIENTRYP PFNGLMULTITEXCOORD1FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord1fv gll_glMultiTexCoord1fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IPROC)(GLenum target, GLint s);
#define glMultiTexCoord1i gll_glMultiTexCoord1i
typedef void (APIENTRYP PFNGLMULTITEXCOORD1IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord1iv gll_glMultiTexCoord1iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SPROC)(GLenum target, GLshort s);
#define glMultiTexCoord1s gll_glMultiTexCoord1s
typedef void (APIENTRYP PFNGLMULTITEXCOORD1SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord1sv gll_glMultiTexCoord1sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DPROC)(GLenum target, GLdouble s, GLdouble t);
#define glMultiTexCoord2d gll_glMultiTexCoord2d
typedef void (APIENTRYP PFNGLMULTITEXCOORD2DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord2dv gll_glMultiTexCoord2dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FPROC)(GLenum target, GLfloat s, GLfloat t);
#define glMultiTexCoord2f gll_glMultiTexCoord2f
typedef void (APIENTRYP PFNGLMULTITEXCOORD2FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord2fv gll_glMultiTexCoord2fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IPROC)(GLenum target, GLint s, GLint t);
#define glMultiTexCoord2i gll_glMultiTexCoord2i
typedef void (APIENTRYP PFNGLMULTITEXCOORD2IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord2iv gll_glMultiTexCoord2iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SPROC)(GLenum target, GLshort s, GLshort t);
#define glMultiTexCoord2s gll_glMultiTexCoord2s
typedef void (APIENTRYP PFNGLMULTITEXCOORD2SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord2sv gll_glMultiTexCoord2sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
#define glMultiTexCoord3d gll_glMultiTexCoord3d
typedef void (APIENTRYP PFNGLMULTITEXCOORD3DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord3dv gll_glMultiTexCoord3dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
#define glMultiTexCoord3f gll_glMultiTexCoord3f
typedef void (APIENTRYP PFNGLMULTITEXCOORD3FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord3fv gll_glMultiTexCoord3fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IPROC)(GLenum target, GLint s, GLint t, GLint r);
#define glMultiTexCoord3i gll_glMultiTexCoord3i
typedef void (APIENTRYP PFNGLMULTITEXCOORD3IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord3iv gll_glMultiTexCoord3iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SPROC)(GLenum target, GLshort s, GLshort t, GLshort r);
#define glMultiTexCoord3s gll_glMultiTexCoord3s
typedef void (APIENTRYP PFNGLMULTITEXCOORD3SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord3sv gll_glMultiTexCoord3sv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DPROC)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#define glMultiTexCoord4d gll_glMultiTexCoord4d
typedef void (APIENTRYP PFNGLMULTITEXCOORD4DVPROC)(GLenum target, const GLdouble * v);
#define glMultiTexCoord4dv gll_glMultiTexCoord4dv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#define glMultiTexCoord4f gll_glMultiTexCoord4f
typedef void (APIENTRYP PFNGLMULTITEXCOORD4FVPROC)(GLenum target, const GLfloat * v);
#define glMultiTexCoord4fv gll_glMultiTexCoord4fv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IPROC)(GLenum target, GLint s, GLint t, GLint r, GLint q);
#define glMultiTexCoord4i gll_glMultiTexCoord4i
typedef void (APIENTRYP PFNGLMULTITEXCOORD4IVPROC)(GLenum target, const GLint * v);
#define glMultiTexCoord4iv gll_glMultiTexCoord4iv
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SPROC)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
#define glMultiTexCoord4s gll_glMultiTexCoord4s
typedef void (APIENTRYP PFNGLMULTITEXCOORD4SVPROC)(GLenum target, const GLshort * v);
#define glMultiTexCoord4sv gll_glMultiTexCoord4sv
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat * m);
#define glLoadTransposeMatrixf gll_glLoadTransposeMatrixf
typedef void (APIENTRYP PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble * m);
#define glLoadTransposeMatrixd gll_glLoadTransposeMatrixd
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat * m);
#define glMultTransposeMatrixf gll_glMultTransposeMatrixf
typedef void (APIENTRYP PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble * m);
#define glMultTransposeMatrixd gll_glMultTransposeMatrixd
#endif

#if GL_LOAD_VERSION >= GL_VERSION_1_4
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
#define glBlendFuncSeparate gll_glBlendFuncSeparate
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
#define glMultiDrawArrays gll_glMultiDrawArrays
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount);
#define glMultiDrawElements gll_glMultiDrawElements
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
#define glPointParameterf gll_glPointParameterf
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat * params);
#define glPointParameterfv gll_glPointParameterfv
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
#define glPointParameteri gll_glPointParameteri
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC)(GLenum pname, const GLint * params);
#define glPointParameteriv gll_glPointParameteriv
typedef void (APIENTRYP PFNGLFOGCOORDFPROC)(GLfloat coord);
#define glFogCoordf gll_glFogCoordf
typedef void (APIENTRYP PFNGLFOGCOORDFVPROC)(const GLfloat * coord);
#define glFogCoordfv gll_glFogCoordfv
typedef void (APIENTRYP PFNGLFOGCOORDDPROC)(GLdouble coord);
#define glFogCoordd gll_glFogCoordd
typedef void (APIENTRYP PFNGLFOGCOORDDVPROC)(const GLdouble * coord);
#define glFogCoorddv gll_glFogCoorddv
typedef void (APIENTRYP PFNGLFOGCOORDPOINTERPROC)(GLenum type, GLsizei stride, const void * pointer);
#define glFogCoordPointer gll_glFogCoordPointer
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
#define glSecondaryColor3b gll_glSecondaryColor3b
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte * v);
#define glSecondaryColor3bv gll_glSecondaryColor3bv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
#define glSecondaryColor3d gll_glSecondaryColor3d
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble * v);
#define glSecondaryColor3dv gll_glSecondaryColor3dv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
#define glSecondaryColor3f gll_glSecondaryColor3f
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat * v);
#define glSecondaryColor3fv gll_glSecondaryColor3fv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IPROC)(GLint red, GLint green, GLint blue);
#define glSecondaryColor3i gll_glSecondaryColor3i
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3IVPROC)(const GLint * v);
#define glSecondaryColor3iv gll_glSecondaryColor3iv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
#define glSecondaryColor3s gll_glSecondaryColor3s
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3SVPROC)(const GLshort * v);
#define glSecondaryColor3sv gll_glSecondaryColor3sv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
#define glSecondaryColor3ub gll_glSecondaryColor3ub
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte * v);
#define glSecondaryColor3ubv gll_glSecondaryColor3ubv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
#define glSecondaryColor3ui gll_glSecondaryColor3ui
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint * v);
#define glSecondaryColor3uiv gll_glSecondaryColor3uiv
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
#define glSecondaryColor3us gll_glSecondaryColor3us
typedef void (APIENTRYP PFNGLSECONDARYCOLOR3USVPROC)(const GLushort * v);
#define glSecondaryColor3usv gll_glSecondaryColor3usv
typedef void (APIENTRYP PFNGLSECONDARYCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glSecondaryColorPointer gll_glSecondaryColorPointer
typedef void (APIENTRYP PFNGLWINDOWPOS2DPROC)(GLdouble x, GLdouble y);
#define glWindowPos2d gll_glWindowPos2d
typedef void (APIENTRYP PFNGLWINDOWPOS2DVPROC)(const GLdouble * v);
#define glWindowPos2dv gll_glWindowPos2dv
typedef void (APIENTRYP PFNGLWINDOWPOS2FPROC)(GLfloat x, GLfloat y);
#define glWindowPos2f gll_glWindowPos2f
typedef void (APIENTRYP PFNGLWINDOWPOS2FVPROC)(const GLfloat * v);
#define glWindowPos2fv gll_glWindowPos2fv
typedef void (APIENTRYP PFNGLWINDOWPOS2IPROC)(GLint x, GLint y);
#define glWindowPos2i gll_glWindowPos2i
typedef void (APIENTRYP PFNGLWINDOWPOS2IVPROC)(const GLint * v);
#define glWindowPos2iv gll_glWindowPos2iv
typedef void (APIENTRYP PFNGLWINDOWPOS2SPROC)(GLshort x, GLshort y);
#define glWindowPos2s gll_glWindowPos2s
typedef void (APIENTRYP PFNGLWINDOWPOS2SVPROC)(const GLshort * v);
#define glWindowPos2sv gll_glWindowPos2sv
typedef void (APIENTRYP PFNGLWINDOWPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
#define glWindowPos3d gll_glWindowPos3d
typedef void (APIENTRYP PFNGLWINDOWPOS3DVPROC)(const GLdouble * v);
#define glWindowPos3dv gll_glWindowPos3dv
typedef void (APIENTRYP PFNGLWINDOWPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
#define glWindowPos3f gll_glWindowPos3f
typedef void (APIENTRYP PFNGLWINDOWPOS3FVPROC)(const GLfloat * v);
#define glWindowPos3fv gll_glWindowPos3fv
typedef void (APIENTRYP PFNGLWINDOWPOS3IPROC)(GLint x, GLint y, GLint z);
#define glWindowPos3i gll_glWindowPos3i
typedef void (APIENTRYP PFNGLWINDOWPOS3IVPROC)(const GLint * v);
#define glWindowPos3iv gll_glWindowPos3iv
typedef void (APIENTRYP PFNGLWINDOWPOS3SPROC)(GLshort x, GLshort y, GLshort z);
#define glWindowPos3s gll_glWindowPos3s
typedef void (APIENTRYP PFNGLWINDOWPOS3SVPROC)(const GLshort * v);
#define glWindowPos3sv gll_glWindowPos3sv
#define GL_BLEND_COLOR 0x8005
#define GL_BLEND_EQUATION 0x8009
#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_FUNC_ADD 0x8006
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_FUNC_SUBTRACT 0x800A
#define GL_MIN 0x8007
#define GL_MAX 0x8008
typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glBlendColor gll_glBlendColor
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
#define glBlendEquation gll_glBlendEquation
#endif

#if GL_LOAD_VERSION >= GL_VERSION_1_5
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
#define glGenQueries gll_glGenQueries
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint * ids);
#define glDeleteQueries gll_glDeleteQueries
typedef GLboolean (APIENTRYP PFNGLISQUERYPROC)(GLuint id);
#define glIsQuery gll_glIsQuery
typedef void (APIENTRYP PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
#define glBeginQuery gll_glBeginQuery
typedef void (APIENTRYP PFNGLENDQUERYPROC)(GLenum target);
#define glEndQuery gll_glEndQuery
typedef void (APIENTRYP PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetQueryiv gll_glGetQueryiv
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC)(GLuint id, GLenum pname, GLint * params);
#define glGetQueryObjectiv gll_glGetQueryObjectiv
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint * params);
#define glGetQueryObjectuiv gll_glGetQueryObjectuiv
typedef void (APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
#define glBindBuffer gll_glBindBuffer
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint * buffers);
#define glDeleteBuffers gll_glDeleteBuffers
typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint * buffers);
#define glGenBuffers gll_glGenBuffers
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
#define glIsBuffer gll_glIsBuffer
typedef void (APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
#define glBufferData gll_glBufferData
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
#define glBufferSubData gll_glBufferSubData
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, void * data);
#define glGetBufferSubData gll_glGetBufferSubData
typedef void * (APIENTRYP PFNGLMAPBUFFERPROC)(GLenum target, GLenum access);
#define glMapBuffer gll_glMapBuffer
typedef GLboolean (APIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum target);
#define glUnmapBuffer gll_glUnmapBuffer
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetBufferParameteriv gll_glGetBufferParameteriv
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void ** params);
#define glGetBufferPointerv gll_glGetBufferPointerv
#endif

#if GL_LOAD_VERSION >= GL_VERSION_2_0
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
#define glBlendEquationSeparate gll_glBlendEquationSeparate
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum * bufs);
#define glDrawBuffers gll_glDrawBuffers
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
#define glStencilOpSeparate gll_glStencilOpSeparate
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
#define glStencilFuncSeparate gll_glStencilFuncSeparate
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
#define glStencilMaskSeparate gll_glStencilMaskSeparate
typedef void (APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
#define glAttachShader gll_glAttachShader
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar * name);
#define glBindAttribLocation gll_glBindAttribLocation
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
#define glCompileShader gll_glCompileShader
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC)(void);
#define glCreateProgram gll_glCreateProgram
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
#define glCreateShader gll_glCreateShader
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
#define glDeleteProgram gll_glDeleteProgram
typedef void (APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
#define glDeleteShader gll_glDeleteShader
typedef void (APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
#define glDetachShader gll_glDetachShader
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
#define glDisableVertexAttribArray gll_glDisableVertexAttribArray
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
#define glEnableVertexAttribArray gll_glEnableVertexAttribArray
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
#define glGetActiveAttrib gll_glGetActiveAttrib
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
#define glGetActiveUniform gll_glGetActiveUniform
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
#define glGetAttachedShaders gll_glGetAttachedShaders
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar * name);
#define glGetAttribLocation gll_glGetAttribLocation
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint * params);
#define glGetProgramiv gll_glGetProgramiv
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetProgramInfoLog gll_glGetProgramInfoLog
typedef void (APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint * params);
#define glGetShaderiv gll_glGetShaderiv
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetShaderInfoLog gll_glGetShaderInfoLog
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
#define glGetShaderSource gll_glGetShaderSource
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar * name);
#define glGetUniformLocation gll_glGetUniformLocation
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat * params);
#define glGetUniformfv gll_glGetUniformfv
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint * params);
#define glGetUniformiv gll_glGetUniformiv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribdv gll_glGetVertexAttribdv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat * params);
#define glGetVertexAttribfv gll_glGetVertexAttribfv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint * params);
#define glGetVertexAttribiv gll_glGetVertexAttribiv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void ** pointer);
#define glGetVertexAttribPointerv gll_glGetVertexAttribPointerv
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
#define glIsProgram gll_glIsProgram
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC)(GLuint shader);
#define glIsShader gll_glIsShader
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
#define glLinkProgram gll_glLinkProgram
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length);
#define glShaderSource gll_glShaderSource
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
#define glUseProgram gll_glUseProgram
typedef void (APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
#define glUniform1f gll_glUniform1f
typedef void (APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
#define glUniform2f gll_glUniform2f
typedef void (APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glUniform3f gll_glUniform3f
typedef void (APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glUniform4f gll_glUniform4f
typedef void (APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
#define glUniform1i gll_glUniform1i
typedef void (APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
#define glUniform2i gll_glUniform2i
typedef void (APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
#define glUniform3i gll_glUniform3i
typedef void (APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glUniform4i gll_glUniform4i
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform1fv gll_glUniform1fv
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform2fv gll_glUniform2fv
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform3fv gll_glUniform3fv
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat * value);
#define glUniform4fv gll_glUniform4fv
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform1iv gll_glUniform1iv
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform2iv gll_glUniform2iv
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform3iv gll_glUniform3iv
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint * value);
#define glUniform4iv gll_glUniform4iv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix2fv gll_glUniformMatrix2fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3fv gll_glUniformMatrix3fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4fv gll_glUniformMatrix4fv
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
#define glValidateProgram gll_glValidateProgram
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC)(GLuint index, GLdouble x);
#define glVertexAttrib1d gll_glVertexAttrib1d
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib1dv gll_glVertexAttrib1dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
#define glVertexAttrib1f gll_glVertexAttrib1f
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib1fv gll_glVertexAttrib1fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC)(GLuint index, GLshort x);
#define glVertexAttrib1s gll_glVertexAttrib1s
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib1sv gll_glVertexAttrib1sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttrib2d gll_glVertexAttrib2d
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib2dv gll_glVertexAttrib2dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
#define glVertexAttrib2f gll_glVertexAttrib2f
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib2fv gll_glVertexAttrib2fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC)(GLuint index, GLshort x, GLshort y);
#define glVertexAttrib2s gll_glVertexAttrib2s
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib2sv gll_glVertexAttrib2sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttrib3d gll_glVertexAttrib3d
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib3dv gll_glVertexAttrib3dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
#define glVertexAttrib3f gll_glVertexAttrib3f
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib3fv gll_glVertexAttrib3fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC)(GLuint index, GLshort x, GLshort y, GLshort z);
#define glVertexAttrib3s gll_glVertexAttrib3s
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib3sv gll_glVertexAttrib3sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC)(GLuint index, const GLbyte * v);
#define glVertexAttrib4Nbv gll_glVertexAttrib4Nbv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC)(GLuint index, const GLint * v);
#define glVertexAttrib4Niv gll_glVertexAttrib4Niv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib4Nsv gll_glVertexAttrib4Nsv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
#define glVertexAttrib4Nub gll_glVertexAttrib4Nub
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC)(GLuint index, const GLubyte * v);
#define glVertexAttrib4Nubv gll_glVertexAttrib4Nubv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttrib4Nuiv gll_glVertexAttrib4Nuiv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC)(GLuint index, const GLushort * v);
#define glVertexAttrib4Nusv gll_glVertexAttrib4Nusv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC)(GLuint index, const GLbyte * v);
#define glVertexAttrib4bv gll_glVertexAttrib4bv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttrib4d gll_glVertexAttrib4d
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttrib4dv gll_glVertexAttrib4dv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertexAttrib4f gll_glVertexAttrib4f
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat * v);
#define glVertexAttrib4fv gll_glVertexAttrib4fv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC)(GLuint index, const GLint * v);
#define glVertexAttrib4iv gll_glVertexAttrib4iv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertexAttrib4s gll_glVertexAttrib4s
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttrib4sv gll_glVertexAttrib4sv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC)(GLuint index, const GLubyte * v);
#define glVertexAttrib4ubv gll_glVertexAttrib4ubv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttrib4uiv gll_glVertexAttrib4uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC)(GLuint index, const GLushort * v);
#define glVertexAttrib4usv gll_glVertexAttrib4usv
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
#define glVertexAttribPointer gll_glVertexAttribPointer
#endif

#if GL_LOAD_VERSION >= GL_VERSION_2_1
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
#define glUniformMatrix2x3fv gll_glUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3x2fv gll_glUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix2x4fv gll_glUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4x2fv gll_glUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix3x4fv gll_glUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glUniformMatrix4x3fv gll_glUniformMatrix4x3fv
#endif

#if GL_LOAD_VERSION >= GL_VERSION_3_0
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
#define glColorMaski gll_glColorMaski
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC)(GLenum target, GLuint index, GLboolean * data);
#define glGetBooleani_v gll_glGetBooleani_v
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint * data);
#define glGetIntegeri_v gll_glGetIntegeri_v
typedef void (APIENTRYP PFNGLENABLEIPROC)(GLenum target, GLuint index);
#define glEnablei gll_glEnablei
typedef void (APIENTRYP PFNGLDISABLEIPROC)(GLenum target, GLuint index);
#define glDisablei gll_glDisablei
typedef GLboolean (APIENTRYP PFNGLISENABLEDIPROC)(GLenum target, GLuint index);
#define glIsEnabledi gll_glIsEnabledi
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
#define glBeginTransformFeedback gll_glBeginTransformFeedback
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC)(void);
#define glEndTransformFeedback gll_glEndTransformFeedback
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glBindBufferRange gll_glBindBufferRange
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
#define glBindBufferBase gll_glBindBufferBase
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);
#define glTransformFeedbackVaryings gll_glTransformFeedbackVaryings
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
#define glGetTransformFeedbackVarying gll_glGetTransformFeedbackVarying
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC)(GLenum target, GLenum clamp);
#define glClampColor gll_glClampColor
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC)(GLuint id, GLenum mode);
#define glBeginConditionalRender gll_glBeginConditionalRender
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC)(void);
#define glEndConditionalRender gll_glEndConditionalRender
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribIPointer gll_glVertexAttribIPointer
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint * params);
#define glGetVertexAttribIiv gll_glGetVertexAttribIiv
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint * params);
#define glGetVertexAttribIuiv gll_glGetVertexAttribIuiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC)(GLuint index, GLint x);
#define glVertexAttribI1i gll_glVertexAttribI1i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC)(GLuint index, GLint x, GLint y);
#define glVertexAttribI2i gll_glVertexAttribI2i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC)(GLuint index, GLint x, GLint y, GLint z);
#define glVertexAttribI3i gll_glVertexAttribI3i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
#define glVertexAttribI4i gll_glVertexAttribI4i
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC)(GLuint index, GLuint x);
#define glVertexAttribI1ui gll_glVertexAttribI1ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC)(GLuint index, GLuint x, GLuint y);
#define glVertexAttribI2ui gll_glVertexAttribI2ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z);
#define glVertexAttribI3ui gll_glVertexAttribI3ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
#define glVertexAttribI4ui gll_glVertexAttribI4ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI1iv gll_glVertexAttribI1iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI2iv gll_glVertexAttribI2iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI3iv gll_glVertexAttribI3iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint * v);
#define glVertexAttribI4iv gll_glVertexAttribI4iv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI1uiv gll_glVertexAttribI1uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI2uiv gll_glVertexAttribI2uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI3uiv gll_glVertexAttribI3uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint * v);
#define glVertexAttribI4uiv gll_glVertexAttribI4uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC)(GLuint index, const GLbyte * v);
#define glVertexAttribI4bv gll_glVertexAttribI4bv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC)(GLuint index, const GLshort * v);
#define glVertexAttribI4sv gll_glVertexAttribI4sv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC)(GLuint index, const GLubyte * v);
#define glVertexAttribI4ubv gll_glVertexAttribI4ubv
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC)(GLuint index, const GLushort * v);
#define glVertexAttribI4usv gll_glVertexAttribI4usv
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint * params);
#define glGetUniformuiv gll_glGetUniformuiv
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program, GLuint color, const GLchar * name);
#define glBindFragDataLocation gll_glBindFragDataLocation
typedef GLint (APIENTRYP PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar * name);
#define glGetFragDataLocation gll_glGetFragDataLocation
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
#define glUniform1ui gll_glUniform1ui
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
#define glUniform2ui gll_glUniform2ui
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glUniform3ui gll_glUniform3ui
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glUniform4ui gll_glUniform4ui
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform1uiv gll_glUniform1uiv
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform2uiv gll_glUniform2uiv
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform3uiv gll_glUniform3uiv
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint * value);
#define glUniform4uiv gll_glUniform4uiv
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, const GLint * params);
#define glTexParameterIiv gll_glTexParameterIiv
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, const GLuint * params);
#define glTexParameterIuiv gll_glTexParameterIuiv
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetTexParameterIiv gll_glGetTexParameterIiv
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC)(GLenum target, GLenum pname, GLuint * params);
#define glGetTexParameterIuiv gll_glGetTexParameterIuiv
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint * value);
#define glClearBufferiv gll_glClearBufferiv
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint * value);
#define glClearBufferuiv gll_glClearBufferuiv
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat * value);
#define glClearBufferfv gll_glClearBufferfv
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
#define glClearBufferfi gll_glClearBufferfi
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
#define glGetStringi gll_glGetStringi
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
#define GL_INDEX 0x8222
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
#define glIsRenderbuffer gll_glIsRenderbuffer
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
#define glBindRenderbuffer gll_glBindRenderbuffer
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint * renderbuffers);
#define glDeleteRenderbuffers gll_glDeleteRenderbuffers
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint * renderbuffers);
#define glGenRenderbuffers gll_glGenRenderbuffers
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorage gll_glRenderbufferStorage
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetRenderbufferParameteriv gll_glGetRenderbufferParameteriv
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
#define glIsFramebuffer gll_glIsFramebuffer
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
#define glBindFramebuffer gll_glBindFramebuffer
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint * framebuffers);
#define glDeleteFramebuffers gll_glDeleteFramebuffers
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint * framebuffers);
#define glGenFramebuffers gll_glGenFramebuffers
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
#define glCheckFramebufferStatus gll_glCheckFramebufferStatus
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture1D gll_glFramebufferTexture1D
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture2D gll_glFramebufferTexture2D
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
#define glFramebufferTexture3D gll_glFramebufferTexture3D
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glFramebufferRenderbuffer gll_glFramebufferRenderbuffer
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
#define glGetFramebufferAttachmentParameteriv gll_glGetFramebufferAttachmentParameteriv
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
#define glGenerateMipmap gll_glGenerateMipmap
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitFramebuffer gll_glBlitFramebuffer
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisample gll_glRenderbufferStorageMultisample
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glFramebufferTextureLayer gll_glFramebufferTextureLayer
#define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE 0x8C15
#define GL_FRAMEBUFFER_SRGB 0x8DB9
typedef khronos_uint16_t GLhalf;
#define GL_HALF_FLOAT 0x140B
#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
typedef void * (APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapBufferRange gll_glMapBufferRange
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
#define glFlushMappedBufferRange gll_glFlushMappedBufferRange
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
#define glBindVertexArray gll_glBindVertexArray
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint * arrays);
#define glDeleteVertexArrays gll_glDeleteVertexArrays
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint * arrays);
#define glGenVertexArrays gll_glGenVertexArrays
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
#define glIsVertexArray gll_glIsVertexArray
#endif

#if GL_LOAD_VERSION >= GL_VERSION_3_1
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
#define glDrawArraysInstanced gll_glDrawArraysInstanced
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount);
#define glDrawElementsInstanced gll_glDrawElementsInstanced
typedef void (APIENTRYP PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
#define glTexBuffer gll_glTexBuffer
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);
#define glPrimitiveRestartIndex gll_glPrimitiveRestartIndex
#define GL_COPY_READ_BUFFER 0x8F36
#define GL_COPY_WRITE_BUFFER 0x8F37
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyBufferSubData gll_glCopyBufferSubData
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
#define glGetUniformIndices gll_glGetUniformIndices
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
#define glGetActiveUniformsiv gll_glGetActiveUniformsiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
#define glGetActiveUniformName gll_glGetActiveUniformName
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar * uniformBlockName);
#define glGetUniformBlockIndex gll_glGetUniformBlockIndex
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
#define glGetActiveUniformBlockiv gll_glGetActiveUniformBlockiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
#define glGetActiveUniformBlockName gll_glGetActiveUniformBlockName
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#define glUniformBlockBinding gll_glUniformBlockBinding
#endif

#if GL_LOAD_VERSION >= GL_VERSION_3_2
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
#define glDrawElementsBaseVertex gll_glDrawElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
#define glDrawRangeElementsBaseVertex gll_glDrawRangeElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
#define glDrawElementsInstancedBaseVertex gll_glDrawElementsInstancedBaseVertex
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex);
#define glMultiDrawElementsBaseVertex gll_glMultiDrawElementsBaseVertex
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
#define glProvokingVertex gll_glProvokingVertex
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
#define glFenceSync gll_glFenceSync
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
#define glIsSync gll_glIsSync
typedef void (APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
#define glDeleteSync gll_glDeleteSync
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glClientWaitSync gll_glClientWaitSync
typedef void (APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glWaitSync gll_glWaitSync
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64 * data);
#define glGetInteger64v gll_glGetInteger64v
typedef void (APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values);
#define glGetSynciv gll_glGetSynciv
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
#define glGetInteger64i_v gll_glGetInteger64i_v
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64 * params);
#define glGetBufferParameteri64v gll_glGetBufferParameteri64v
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
#define glFramebufferTexture gll_glFramebufferTexture
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexImage2DMultisample gll_glTexImage2DMultisample
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexImage3DMultisample gll_glTexImage3DMultisample
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat * val);
#define glGetMultisamplefv gll_glGetMultisamplefv
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
#define glSampleMaski gll_glSampleMaski
#endif

#if GL_LOAD_VERSION >= GL_VERSION_3_3
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#define GL_SRC1_COLOR 0x88F9
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name);
#define glBindFragDataLocationIndexed gll_glBindFragDataLocationIndexed
typedef GLint (APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar * name);
#define glGetFragDataIndex gll_glGetFragDataIndex
#define GL_ANY_SAMPLES_PASSED 0x8C2F
#define GL_SAMPLER_BINDING 0x8919
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint * samplers);
#define glGenSamplers gll_glGenSamplers
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint * samplers);
#define glDeleteSamplers gll_glDeleteSamplers
typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
#define glIsSampler gll_glIsSampler
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
#define glBindSampler gll_glBindSampler
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
#define glSamplerParameteri gll_glSamplerParameteri
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameteriv gll_glSamplerParameteriv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
#define glSamplerParameterf gll_glSamplerParameterf
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat * param);
#define glSamplerParameterfv gll_glSamplerParameterfv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameterIiv gll_glSamplerParameterIiv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint * param);
#define glSamplerParameterIuiv gll_glSamplerParameterIuiv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameteriv gll_glGetSamplerParameteriv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameterIiv gll_glGetSamplerParameterIiv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat * params);
#define glGetSamplerParameterfv gll_glGetSamplerParameterfv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint * params);
#define glGetSamplerParameterIuiv gll_glGetSamplerParameterIuiv
#define GL_RGB10_A2UI 0x906F
#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46
#define GL_TIME_ELAPSED 0x88BF
#define GL_TIMESTAMP 0x8E28
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
#define glQueryCounter gll_glQueryCounter
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64 * params);
#define glGetQueryObjecti64v gll_glGetQueryObjecti64v
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64 * params);
#define glGetQueryObjectui64v gll_glGetQueryObjectui64v
#define GL_INT_2_10_10_10_REV 0x8D9F
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
#define glVertexAttribDivisor gll_glVertexAttribDivisor
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP1ui gll_glVertexAttribP1ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP1uiv gll_glVertexAttribP1uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP2ui gll_glVertexAttribP2ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP2uiv gll_glVertexAttribP2uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP3ui gll_glVertexAttribP3ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP3uiv gll_glVertexAttribP3uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP4ui gll_glVertexAttribP4ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP4uiv gll_glVertexAttribP4uiv
typedef void (APIENTRYP PFNGLVERTEXP2UIPROC)(GLenum type, GLuint value);
#define glVertexP2ui gll_glVertexP2ui
typedef void (APIENTRYP PFNGLVERTEXP2UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP2uiv gll_glVertexP2uiv
typedef void (APIENTRYP PFNGLVERTEXP3UIPROC)(GLenum type, GLuint value);
#define glVertexP3ui gll_glVertexP3ui
typedef void (APIENTRYP PFNGLVERTEXP3UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP3uiv gll_glVertexP3uiv
typedef void (APIENTRYP PFNGLVERTEXP4UIPROC)(GLenum type, GLuint value);
#define glVertexP4ui gll_glVertexP4ui
typedef void (APIENTRYP PFNGLVERTEXP4UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP4uiv gll_glVertexP4uiv
typedef void (APIENTRYP PFNGLTEXCOORDP1UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP1ui gll_glTexCoordP1ui
typedef void (APIENTRYP PFNGLTEXCOORDP1UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP1uiv gll_glTexCoordP1uiv
typedef void (APIENTRYP PFNGLTEXCOORDP2UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP2ui gll_glTexCoordP2ui
typedef void (APIENTRYP PFNGLTEXCOORDP2UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP2uiv gll_glTexCoordP2uiv
typedef void (APIENTRYP PFNGLTEXCOORDP3UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP3ui gll_glTexCoordP3ui
typedef void (APIENTRYP PFNGLTEXCOORDP3UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP3uiv gll_glTexCoordP3uiv
typedef void (APIENTRYP PFNGLTEXCOORDP4UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP4ui gll_glTexCoordP4ui
typedef void (APIENTRYP PFNGLTEXCOORDP4UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP4uiv gll_glTexCoordP4uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP1ui gll_glMultiTexCoordP1ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP1uiv gll_glMultiTexCoordP1uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP2ui gll_glMultiTexCoordP2ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP2uiv gll_glMultiTexCoordP2uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP3ui gll_glMultiTexCoordP3ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP3uiv gll_glMultiTexCoordP3uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP4ui gll_glMultiTexCoordP4ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP4uiv gll_glMultiTexCoordP4uiv
typedef void (APIENTRYP PFNGLNORMALP3UIPROC)(GLenum type, GLuint coords);
#define glNormalP3ui gll_glNormalP3ui
typedef void (APIENTRYP PFNGLNORMALP3UIVPROC)(GLenum type, const GLuint * coords);
#define glNormalP3uiv gll_glNormalP3uiv
typedef void (APIENTRYP PFNGLCOLORP3UIPROC)(GLenum type, GLuint color);
#define glColorP3ui gll_glColorP3ui
typedef void (APIENTRYP PFNGLCOLORP3UIVPROC)(GLenum type, const GLuint * color);
#define glColorP3uiv gll_glColorP3uiv
typedef void (APIENTRYP PFNGLCOLORP4UIPROC)(GLenum type, GLuint color);
#define glColorP4ui gll_glColorP4ui
typedef void (APIENTRYP PFNGLCOLORP4UIVPROC)(GLenum type, const GLuint * color);
#define glColorP4uiv gll_glColorP4uiv
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIPROC)(GLenum type, GLuint color);
#define glSecondaryColorP3ui gll_glSecondaryColorP3ui
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC)(GLenum type, const GLuint * color);
#define glSecondaryColorP3uiv gll_glSecondaryColorP3uiv
#endif

#if GL_LOAD_VERSION >= GL_VERSION_4_0
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
#define glMinSampleShading gll_glMinSampleShading
typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC)(GLuint buf, GLenum mode);
#define glBlendEquationi gll_glBlendEquationi
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparatei gll_glBlendEquationSeparatei
typedef void (APIENTRYP PFNGLBLENDFUNCIPROC)(GLuint buf, GLenum src, GLenum dst);
#define glBlendFunci gll_glBlendFunci
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#define glBlendFuncSeparatei gll_glBlendFuncSeparatei
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const void * indirect);
#define glDrawArraysIndirect gll_glDrawArraysIndirect
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void * indirect);
#define glDrawElementsIndirect gll_glDrawElementsIndirect
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
#define glUniform1d gll_glUniform1d
typedef void (APIENTRYP PFNGLUNIFORM2DPROC)(GLint location, GLdouble x, GLdouble y);
#define glUniform2d gll_glUniform2d
typedef void (APIENTRYP PFNGLUNIFORM3DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z);
#define glUniform3d gll_glUniform3d
typedef void (APIENTRYP PFNGLUNIFORM4DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glUniform4d gll_glUniform4d
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform1dv gll_glUniform1dv
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform2dv gll_glUniform2dv
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform3dv gll_glUniform3dv
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform4dv gll_glUniform4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2dv gll_glUniformMatrix2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3dv gll_glUniformMatrix3dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4dv gll_glUniformMatrix4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x3dv gll_glUniformMatrix2x3dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x4dv gll_glUniformMatrix2x4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x2dv gll_glUniformMatrix3x2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x4dv gll_glUniformMatrix3x4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x2dv gll_glUniformMatrix4x2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x3dv gll_glUniformMatrix4x3dv
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint program, GLint location, GLdouble * params);
#define glGetUniformdv gll_glGetUniformdv
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
#define glGetSubroutineUniformLocation gll_glGetSubroutineUniformLocation
typedef GLuint (APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint program, GLenum shadertype, const GLchar * name);
#define glGetSubroutineIndex gll_glGetSubroutineIndex
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values);
#define glGetActiveSubroutineUniformiv gll_glGetActiveSubroutineUniformiv
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineUniformName gll_glGetActiveSubroutineUniformName
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineName gll_glGetActiveSubroutineName
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum shadertype, GLsizei count, const GLuint * indices);
#define glUniformSubroutinesuiv gll_glUniformSubroutinesuiv
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum shadertype, GLint location, GLuint * params);
#define glGetUniformSubroutineuiv gll_glGetUniformSubroutineuiv
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint program, GLenum shadertype, GLenum pname, GLint * values);
#define glGetProgramStageiv gll_glGetProgramStageiv
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
#define glPatchParameteri gll_glPatchParameteri
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum pname, const GLfloat * values);
#define glPatchParameterfv gll_glPatchParameterfv
#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
#define glBindTransformFeedback gll_glBindTransformFeedback
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint * ids);
#define glDeleteTransformFeedbacks gll_glDeleteTransformFeedbacks
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint * ids);
#define glGenTransformFeedbacks gll_glGenTransformFeedbacks
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
#define glIsTransformFeedback gll_glIsTransformFeedback
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);
#define glPauseTransformFeedback gll_glPauseTransformFeedback
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);
#define glResumeTransformFeedback gll_glResumeTransformFeedback
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum mode, GLuint id);
#define glDrawTransformFeedback gll_glDrawTransformFeedback
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum mode, GLuint id, GLuint stream);
#define glDrawTransformFeedbackStream gll_glDrawTransformFeedbackStream
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum target, GLuint index, GLuint id);
#define glBeginQueryIndexed gll_glBeginQueryIndexed
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum target, GLuint index);
#define glEndQueryIndexed gll_glEndQueryIndexed
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum target, GLuint index, GLenum pname, GLint * params);
#define glGetQueryIndexediv gll_glGetQueryIndexediv
#endif

#if GL_LOAD_VERSION >= GL_VERSION_4_1
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
#define glReleaseShaderCompiler gll_glReleaseShaderCompiler
typedef void (APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint * shaders, GLenum binaryFormat, const void * binary, GLsizei length);
#define glShaderBinary gll_glShaderBinary
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
#define glGetShaderPrecisionFormat gll_glGetShaderPrecisionFormat
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
#define glDepthRangef gll_glDepthRangef
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
#define glClearDepthf gll_glClearDepthf
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
#define glGetProgramBinary gll_glGetProgramBinary
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
#define glProgramBinary gll_glProgramBinary
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
#define glProgramParameteri gll_glProgramParameteri
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
#define glUseProgramStages gll_glUseProgramStages
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint pipeline, GLuint program);
#define glActiveShaderProgram gll_glActiveShaderProgram
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum type, GLsizei count, const GLchar *const* strings);
#define glCreateShaderProgramv gll_glCreateShaderProgramv
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glBindProgramPipeline gll_glBindProgramPipeline
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei n, const GLuint * pipelines);
#define glDeleteProgramPipelines gll_glDeleteProgramPipelines
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei n, GLuint * pipelines);
#define glGenProgramPipelines gll_glGenProgramPipelines
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glIsProgramPipeline gll_glIsProgramPipeline
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint pipeline, GLenum pname, GLint * params);
#define glGetProgramPipelineiv gll_glGetProgramPipelineiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint program, GLint location, GLint v0);
#define glProgramUniform1i gll_glProgramUniform1i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform1iv gll_glProgramUniform1iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint program, GLint location, GLfloat v0);
#define glProgramUniform1f gll_glProgramUniform1f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform1fv gll_glProgramUniform1fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint program, GLint location, GLdouble v0);
#define glProgramUniform1d gll_glProgramUniform1d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform1dv gll_glProgramUniform1dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint program, GLint location, GLuint v0);
#define glProgramUniform1ui gll_glProgramUniform1ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform1uiv gll_glProgramUniform1uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint program, GLint location, GLint v0, GLint v1);
#define glProgramUniform2i gll_glProgramUniform2i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform2iv gll_glProgramUniform2iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
#define glProgramUniform2f gll_glProgramUniform2f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform2fv gll_glProgramUniform2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
#define glProgramUniform2d gll_glProgramUniform2d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform2dv gll_glProgramUniform2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
#define glProgramUniform2ui gll_glProgramUniform2ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform2uiv gll_glProgramUniform2uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
#define glProgramUniform3i gll_glProgramUniform3i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform3iv gll_glProgramUniform3iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glProgramUniform3f gll_glProgramUniform3f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform3fv gll_glProgramUniform3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
#define glProgramUniform3d gll_glProgramUniform3d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform3dv gll_glProgramUniform3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glProgramUniform3ui gll_glProgramUniform3ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform3uiv gll_glProgramUniform3uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glProgramUniform4i gll_glProgramUniform4i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform4iv gll_glProgramUniform4iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glProgramUniform4f gll_glProgramUniform4f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform4fv gll_glProgramUniform4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
#define glProgramUniform4d gll_glProgramUniform4d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform4dv gll_glProgramUniform4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glProgramUniform4ui gll_glProgramUniform4ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform4uiv gll_glProgramUniform4uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2fv gll_glProgramUniformMatrix2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3fv gll_glProgramUniformMatrix3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4fv gll_glProgramUniformMatrix4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2dv gll_glProgramUniformMatrix2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3dv gll_glProgramUniformMatrix3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4dv gll_glProgramUniformMatrix4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x3fv gll_glProgramUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x2fv gll_glProgramUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x4fv gll_glProgramUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x2fv gll_glProgramUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x4fv gll_glProgramUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x3fv gll_glProgramUniformMatrix4x3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x3dv gll_glProgramUniformMatrix2x3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x2dv gll_glProgramUniformMatrix3x2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x4dv gll_glProgramUniformMatrix2x4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x2dv gll_glProgramUniformMatrix4x2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x4dv gll_glProgramUniformMatrix3x4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x3dv gll_glProgramUniformMatrix4x3dv
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glValidateProgramPipeline gll_glValidateProgramPipeline
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetProgramPipelineInfoLog gll_glGetProgramPipelineInfoLog
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint index, GLdouble x);
#define glVertexAttribL1d gll_glVertexAttribL1d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttribL2d gll_glVertexAttribL2d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttribL3d gll_glVertexAttribL3d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttribL4d gll_glVertexAttribL4d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL1dv gll_glVertexAttribL1dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL2dv gll_glVertexAttribL2dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL3dv gll_glVertexAttribL3dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL4dv gll_glVertexAttribL4dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribLPointer gll_glVertexAttribLPointer
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribLdv gll_glGetVertexAttribLdv
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint first, GLsizei count, const GLfloat * v);
#define glViewportArrayv gll_glViewportArrayv
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
#define glViewportIndexedf gll_glViewportIndexedf
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint index, const GLfloat * v);
#define glViewportIndexedfv gll_glViewportIndexedfv
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint first, GLsizei count, const GLint * v);
#define glScissorArrayv gll_glScissorArrayv
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
#define glScissorIndexed gll_glScissorIndexed
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint index, const GLint * v);
#define glScissorIndexedv gll_glScissorIndexedv
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint first, GLsizei count, const GLdouble * v);
#define glDepthRangeArrayv gll_glDepthRangeArrayv
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint index, GLdouble n, GLdouble f);
#define glDepthRangeIndexed gll_glDepthRangeIndexed
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC)(GLenum target, GLuint index, GLfloat * data);
#define glGetFloati_v gll_glGetFloati_v
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum target, GLuint index, GLdouble * data);
#define glGetDoublei_v gll_glGetDoublei_v
#endif

#if GL_LOAD_VERSION >= GL_VERSION_4_2
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
#define glDrawArraysInstancedBaseInstance gll_glDrawArraysInstancedBaseInstance
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
#define glDrawElementsInstancedBaseInstance gll_glDrawElementsInstancedBaseInstance
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#define glDrawElementsInstancedBaseVertexBaseInstance gll_glDrawElementsInstancedBaseVertexBaseInstance
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params);
#define glGetInternalformativ gll_glGetInternalformativ
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params);
#define glGetActiveAtomicCounterBufferiv gll_glGetActiveAtomicCounterBufferiv
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
#define glBindImageTexture gll_glBindImageTexture
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC)(GLbitfield barriers);
#define glMemoryBarrier gll_glMemoryBarrier
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTexStorage1D gll_glTexStorage1D
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTexStorage2D gll_glTexStorage2D
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTexStorage3D gll_glTexStorage3D
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum mode, GLuint id, GLsizei instancecount);
#define glDrawTransformFeedbackInstanced gll_glDrawTransformFeedbackInstanced
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#define glDrawTransformFeedbackStreamInstanced gll_glDrawTransformFeedbackStreamInstanced
#endif

#if GL_LOAD_VERSION >= GL_VERSION_4_3
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
#define glClearBufferData gll_glClearBufferData
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearBufferSubData gll_glClearBufferSubData
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
#define glDispatchCompute gll_glDispatchCompute
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
#define glDispatchComputeIndirect gll_glDispatchComputeIndirect
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#define glCopyImageSubData gll_glCopyImageSubData
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
#define glFramebufferParameteri gll_glFramebufferParameteri
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetFramebufferParameteriv gll_glGetFramebufferParameteriv
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 * params);
#define glGetInternalformati64v gll_glGetInternalformati64v
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
#define glInvalidateTexSubImage gll_glInvalidateTexSubImage
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC)(GLuint texture, GLint level);
#define glInvalidateTexImage gll_glInvalidateTexImage
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glInvalidateBufferSubData gll_glInvalidateBufferSubData
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC)(GLuint buffer);
#define glInvalidateBufferData gll_glInvalidateBufferData
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateFramebuffer gll_glInvalidateFramebuffer
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateSubFramebuffer gll_glInvalidateSubFramebuffer
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawArraysIndirect gll_glMultiDrawArraysIndirect
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawElementsIndirect gll_glMultiDrawElementsIndirect
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program, GLenum programInterface, GLenum pname, GLint * params);
#define glGetProgramInterfaceiv gll_glGetProgramInterfaceiv
typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceIndex gll_glGetProgramResourceIndex
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
#define glGetProgramResourceName gll_glGetProgramResourceName
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLint * params);
#define glGetProgramResourceiv gll_glGetProgramResourceiv
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocation gll_glGetProgramResourceLocation
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocationIndex gll_glGetProgramResourceLocationIndex
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
#define glShaderStorageBlockBinding gll_glShaderStorageBlockBinding
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTexBufferRange gll_glTexBufferRange
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexStorage2DMultisample gll_glTexStorage2DMultisample
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexStorage3DMultisample gll_glTexStorage3DMultisample
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#define glTextureView gll_glTextureView
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glBindVertexBuffer gll_glBindVertexBuffer
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexAttribFormat gll_glVertexAttribFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribIFormat gll_glVertexAttribIFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribLFormat gll_glVertexAttribLFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
#define glVertexAttribBinding gll_glVertexAttribBinding
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
#define glVertexBindingDivisor gll_glVertexBindingDivisor
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
#define glDebugMessageControl gll_glDebugMessageControl
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
#define glDebugMessageInsert gll_glDebugMessageInsert
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void * userParam);
#define glDebugMessageCallback gll_glDebugMessageCallback
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
#define glGetDebugMessageLog gll_glGetDebugMessageLog
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum source, GLuint id, GLsizei length, const GLchar * message);
#define glPushDebugGroup gll_glPushDebugGroup
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC)(void);
#define glPopDebugGroup gll_glPopDebugGroup
typedef void (APIENTRYP PFNGLOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
#define glObjectLabel gll_glObjectLabel
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectLabel gll_glGetObjectLabel
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC)(const void * ptr, GLsizei length, const GLchar * label);
#define glObjectPtrLabel gll_glObjectPtrLabel
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC)(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectPtrLabel gll_glGetObjectPtrLabel
#define GL_DISPLAY_LIST 0x82E7
#endif

#if GL_LOAD_VERSION >= GL_VERSION_4_4
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
#define glBufferStorage gll_glBufferStorage
#define GL_CLEAR_TEXTURE 0x9365
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
#define glClearTexImage gll_glClearTexImage
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
#define glClearTexSubImage gll_glClearTexSubImage
#define GL_LOCATION_COMPONENT 0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers);
#define glBindBuffersBase gll_glBindBuffersBase
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes);
#define glBindBuffersRange gll_glBindBuffersRange
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindTextures gll_glBindTextures
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint * samplers);
#define glBindSamplers gll_glBindSamplers
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindImageTextures gll_glBindImageTextures
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glBindVertexBuffers gll_glBindVertexBuffers
#define GL_QUERY_BUFFER 0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000
#define GL_QUERY_BUFFER_BINDING 0x9193
#define GL_QUERY_RESULT_NO_WAIT 0x9194
#define GL_MIRROR_CLAMP_TO_EDGE 0x8743
#endif

#if GL_LOAD_VERSION >= GL_VERSION_4_5
#define GL_CONTEXT_LOST 0x0507
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC)(GLenum origin, GLenum depth);
#define glClipControl gll_glClipControl
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
#define glCreateTransformFeedbacks gll_glCreateTransformFeedbacks
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint xfb, GLuint index, GLuint buffer);
#define glTransformFeedbackBufferBase gll_glTransformFeedbackBufferBase
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTransformFeedbackBufferRange gll_glTransformFeedbackBufferRange
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint xfb, GLenum pname, GLint * param);
#define glGetTransformFeedbackiv gll_glGetTransformFeedbackiv
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint * param);
#define glGetTransformFeedbacki_v gll_glGetTransformFeedbacki_v
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint64 * param);
#define glGetTransformFeedbacki64_v gll_glGetTransformFeedbacki64_v
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei n, GLuint * buffers);
#define glCreateBuffers gll_glCreateBuffers
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
#define glNamedBufferStorage gll_glNamedBufferStorage
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
#define glNamedBufferData gll_glNamedBufferData
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
#define glNamedBufferSubData gll_glNamedBufferSubData
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyNamedBufferSubData gll_glCopyNamedBufferSubData
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferData gll_glClearNamedBufferData
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferSubData gll_glClearNamedBufferSubData
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint buffer, GLenum access);
#define glMapNamedBuffer gll_glMapNamedBuffer
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapNamedBufferRange gll_glMapNamedBufferRange
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint buffer);
#define glUnmapNamedBuffer gll_glUnmapNamedBuffer
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glFlushMappedNamedBufferRange gll_glFlushMappedNamedBufferRange
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint buffer, GLenum pname, GLint * params);
#define glGetNamedBufferParameteriv gll_glGetNamedBufferParameteriv
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint buffer, GLenum pname, GLint64 * params);
#define glGetNamedBufferParameteri64v gll_glGetNamedBufferParameteri64v
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint buffer, GLenum pname, void ** params);
#define glGetNamedBufferPointerv gll_glGetNamedBufferPointerv
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
#define glGetNamedBufferSubData gll_glGetNamedBufferSubData
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei n, GLuint * framebuffers);
#define glCreateFramebuffers gll_glCreateFramebuffers
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glNamedFramebufferRenderbuffer gll_glNamedFramebufferRenderbuffer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint framebuffer, GLenum pname, GLint param);
#define glNamedFramebufferParameteri gll_glNamedFramebufferParameteri
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
#define glNamedFramebufferTexture gll_glNamedFramebufferTexture
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glNamedFramebufferTextureLayer gll_glNamedFramebufferTextureLayer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint framebuffer, GLenum buf);
#define glNamedFramebufferDrawBuffer gll_glNamedFramebufferDrawBuffer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint framebuffer, GLsizei n, const GLenum * bufs);
#define glNamedFramebufferDrawBuffers gll_glNamedFramebufferDrawBuffers
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint framebuffer, GLenum src);
#define glNamedFramebufferReadBuffer gll_glNamedFramebufferReadBuffer
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateNamedFramebufferData gll_glInvalidateNamedFramebufferData
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateNamedFramebufferSubData gll_glInvalidateNamedFramebufferSubData
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value);
#define glClearNamedFramebufferiv gll_glClearNamedFramebufferiv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value);
#define glClearNamedFramebufferuiv gll_glClearNamedFramebufferuiv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat * value);
#define glClearNamedFramebufferfv gll_glClearNamedFramebufferfv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
#define glClearNamedFramebufferfi gll_glClearNamedFramebufferfi
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitNamedFramebuffer gll_glBlitNamedFramebuffer
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint framebuffer, GLenum target);
#define glCheckNamedFramebufferStatus gll_glCheckNamedFramebufferStatus
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint framebuffer, GLenum pname, GLint * param);
#define glGetNamedFramebufferParameteriv gll_glGetNamedFramebufferParameteriv
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
#define glGetNamedFramebufferAttachmentParameteriv gll_glGetNamedFramebufferAttachmentParameteriv
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei n, GLuint * renderbuffers);
#define glCreateRenderbuffers gll_glCreateRenderbuffers
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorage gll_glNamedRenderbufferStorage
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisample gll_glNamedRenderbufferStorageMultisample
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint renderbuffer, GLenum pname, GLint * params);
#define glGetNamedRenderbufferParameteriv gll_glGetNamedRenderbufferParameteriv
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC)(GLenum target, GLsizei n, GLuint * textures);
#define glCreateTextures gll_glCreateTextures
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint texture, GLenum internalformat, GLuint buffer);
#define glTextureBuffer gll_glTextureBuffer
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTextureBufferRange gll_glTextureBufferRange
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTextureStorage1D gll_glTextureStorage1D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTextureStorage2D gll_glTextureStorage2D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTextureStorage3D gll_glTextureStorage3D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTextureStorage2DMultisample gll_glTextureStorage2DMultisample
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTextureStorage3DMultisample gll_glTextureStorage3DMultisample
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage1D gll_glTextureSubImage1D
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage2D gll_glTextureSubImage2D
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage3D gll_glTextureSubImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage1D gll_glCompressedTextureSubImage1D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage2D gll_glCompressedTextureSubImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage3D gll_glCompressedTextureSubImage3D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTextureSubImage1D gll_glCopyTextureSubImage1D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage2D gll_glCopyTextureSubImage2D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage3D gll_glCopyTextureSubImage3D
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint texture, GLenum pname, GLfloat param);
#define glTextureParameterf gll_glTextureParameterf
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, const GLfloat * param);
#define glTextureParameterfv gll_glTextureParameterfv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint texture, GLenum pname, GLint param);
#define glTextureParameteri gll_glTextureParameteri
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, const GLint * params);
#define glTextureParameterIiv gll_glTextureParameterIiv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, const GLuint * params);
#define glTextureParameterIuiv gll_glTextureParameterIuiv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, const GLint * param);
#define glTextureParameteriv gll_glTextureParameteriv
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint texture);
#define glGenerateTextureMipmap gll_glGenerateTextureMipmap
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint unit, GLuint texture);
#define glBindTextureUnit gll_glBindTextureUnit
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureImage gll_glGetTextureImage
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureImage gll_glGetCompressedTextureImage
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint texture, GLint level, GLenum pname, GLfloat * params);
#define glGetTextureLevelParameterfv gll_glGetTextureLevelParameterfv
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint texture, GLint level, GLenum pname, GLint * params);
#define glGetTextureLevelParameteriv gll_glGetTextureLevelParameteriv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, GLfloat * params);
#define glGetTextureParameterfv gll_glGetTextureParameterfv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameterIiv gll_glGetTextureParameterIiv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, GLuint * params);
#define glGetTextureParameterIuiv gll_glGetTextureParameterIuiv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameteriv gll_glGetTextureParameteriv
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei n, GLuint * arrays);
#define glCreateVertexArrays gll_glCreateVertexArrays
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
#define glDisableVertexArrayAttrib gll_glDisableVertexArrayAttrib
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
#define glEnableVertexArrayAttrib gll_glEnableVertexArrayAttrib
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint vaobj, GLuint buffer);
#define glVertexArrayElementBuffer gll_glVertexArrayElementBuffer
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glVertexArrayVertexBuffer gll_glVertexArrayVertexBuffer
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glVertexArrayVertexBuffers gll_glVertexArrayVertexBuffers
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
#define glVertexArrayAttribBinding gll_glVertexArrayAttribBinding
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexArrayAttribFormat gll_glVertexArrayAttribFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribIFormat gll_glVertexArrayAttribIFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribLFormat gll_glVertexArrayAttribLFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#define glVertexArrayBindingDivisor gll_glVertexArrayBindingDivisor
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint vaobj, GLenum pname, GLint * param);
#define glGetVertexArrayiv gll_glGetVertexArrayiv
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint * param);
#define glGetVertexArrayIndexediv gll_glGetVertexArrayIndexediv
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param);
#define glGetVertexArrayIndexed64iv gll_glGetVertexArrayIndexed64iv
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei n, GLuint * samplers);
#define glCreateSamplers gll_glCreateSamplers
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei n, GLuint * pipelines);
#define glCreateProgramPipelines gll_glCreateProgramPipelines
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC)(GLenum target, GLsizei n, GLuint * ids);
#define glCreateQueries gll_glCreateQueries
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjecti64v gll_glGetQueryBufferObjecti64v
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectiv gll_glGetQueryBufferObjectiv
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectui64v gll_glGetQueryBufferObjectui64v
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectuiv gll_glGetQueryBufferObjectuiv
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
#define glMemoryBarrierByRegion gll_glMemoryBarrierByRegion
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureSubImage gll_glGetTextureSubImage
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureSubImage gll_glGetCompressedTextureSubImage
#define GL_GUILTY_CONTEXT_RESET 0x8253
#define GL_INNOCENT_CONTEXT_RESET 0x8254
#define GL_UNKNOWN_CONTEXT_RESET 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY 0x8256
#define GL_LOSE_CONTEXT_ON_RESET 0x8252
#define GL_NO_RESET_NOTIFICATION 0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)(void);
#define glGetGraphicsResetStatus gll_glGetGraphicsResetStatus
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC)(GLenum target, GLint lod, GLsizei bufSize, void * pixels);
#define glGetnCompressedTexImage gll_glGetnCompressedTexImage
typedef void (APIENTRYP PFNGLGETNTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetnTexImage gll_glGetnTexImage
typedef void (APIENTRYP PFNGLGETNUNIFORMDVPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble * params);
#define glGetnUniformdv gll_glGetnUniformdv
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
#define glGetnUniformfv gll_glGetnUniformfv
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint * params);
#define glGetnUniformiv gll_glGetnUniformiv
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint * params);
#define glGetnUniformuiv gll_glGetnUniformuiv
typedef void (APIENTRYP PFNGLREADNPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
#define glReadnPixels gll_glReadnPixels
typedef void (APIENTRYP PFNGLGETNMAPDVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v);
#define glGetnMapdv gll_glGetnMapdv
typedef void (APIENTRYP PFNGLGETNMAPFVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v);
#define glGetnMapfv gll_glGetnMapfv
typedef void (APIENTRYP PFNGLGETNMAPIVPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint * v);
#define glGetnMapiv gll_glGetnMapiv
typedef void (APIENTRYP PFNGLGETNPIXELMAPFVPROC)(GLenum map, GLsizei bufSize, GLfloat * values);
#define glGetnPixelMapfv gll_glGetnPixelMapfv
typedef void (APIENTRYP PFNGLGETNPIXELMAPUIVPROC)(GLenum map, GLsizei bufSize, GLuint * values);
#define glGetnPixelMapuiv gll_glGetnPixelMapuiv
typedef void (APIENTRYP PFNGLGETNPIXELMAPUSVPROC)(GLenum map, GLsizei bufSize, GLushort * values);
#define glGetnPixelMapusv gll_glGetnPixelMapusv
typedef void (APIENTRYP PFNGLGETNPOLYGONSTIPPLEPROC)(GLsizei bufSize, GLubyte * pattern);
#define glGetnPolygonStipple gll_glGetnPolygonStipple
typedef void (APIENTRYP PFNGLGETNCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table);
#define glGetnColorTable gll_glGetnColorTable
typedef void (APIENTRYP PFNGLGETNCONVOLUTIONFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image);
#define glGetnConvolutionFilter gll_glGetnConvolutionFilter
typedef void (APIENTRYP PFNGLGETNSEPARABLEFILTERPROC)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span);
#define glGetnSeparableFilter gll_glGetnSeparableFilter
typedef void (APIENTRYP PFNGLGETNHISTOGRAMPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
#define glGetnHistogram gll_glGetnHistogram
typedef void (APIENTRYP PFNGLGETNMINMAXPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
#define glGetnMinmax gll_glGetnMinmax
#define GL_COLOR_TABLE 0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE 0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE 0x80D2
#define GL_PROXY_COLOR_TABLE 0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_CONVOLUTION_1D 0x8010
#define GL_CONVOLUTION_2D 0x8011
#define GL_SEPARABLE_2D 0x8012
#define GL_HISTOGRAM 0x8024
#define GL_PROXY_HISTOGRAM 0x8025
#define GL_MINMAX 0x802E
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC)(void);
#define glTextureBarrier gll_glTextureBarrier
#define GL_CONTEXT_RELEASE_BEHAVIOR 0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
#endif

#if GL_LOAD_VERSION >= GL_VERSION_4_6
#define GL_SHADER_BINARY_FORMAT_SPIR_V 0x9551
#define GL_SPIR_V_BINARY 0x9552
typedef void (APIENTRYP PFNGLSPECIALIZESHADERPROC)(GLuint shader, const GLchar * pEntryPoint, GLuint numSpecializationConstants, const GLuint * pConstantIndex, const GLuint * pConstantValue);
#define glSpecializeShader gll_glSpecializeShader
#define GL_PARAMETER_BUFFER 0x80EE
#define GL_PARAMETER_BUFFER_BINDING 0x80EF
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#define glMultiDrawArraysIndirectCount gll_glMultiDrawArraysIndirectCount
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#define glMultiDrawElementsIndirectCount gll_glMultiDrawElementsIndirectCount
#define GL_CONTEXT_FLAG_NO_ERROR_BIT 0x00000008
#define GL_VERTICES_SUBMITTED 0x82EE
#define GL_PRIMITIVES_SUBMITTED 0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS 0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES 0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES 0x82F7
#define GL_POLYGON_OFFSET_CLAMP 0x8E1B
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPPROC)(GLfloat factor, GLfloat units, GLfloat clamp);
#define glPolygonOffsetClamp gll_glPolygonOffsetClamp
#define GL_SPIR_V_EXTENSIONS 0x9553
#define GL_NUM_SPIR_V_EXTENSIONS 0x9554
#define GL_TEXTURE_MAX_ANISOTROPY 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY 0x84FF
#define GL_TRANSFORM_FEEDBACK_OVERFLOW 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW 0x82ED
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

#define GL_FUNCTIONS_4_6 \
	X(PFNGLSPECIALIZESHADERPROC, glSpecializeShader) \
	X(PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC, glMultiDrawArraysIndirectCount) \
	X(PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC, glMultiDrawElementsIndirectCount) \
	X(PFNGLPOLYGONOFFSETCLAMPPROC, glPolygonOffsetClamp) \

#define X(T, N) extern T gll_##N;
#if GL_LOAD_VERSION >= GL_VERSION_1_0
GL_FUNCTIONS_1_0
#endif
#if GL_LOAD_VERSION >= GL_VERSION_1_1
GL_FUNCTIONS_1_1
#endif
#if GL_LOAD_VERSION >= GL_VERSION_1_2
GL_FUNCTIONS_1_2
#endif
#if GL_LOAD_VERSION >= GL_VERSION_1_3
GL_FUNCTIONS_1_3
#endif
#if GL_LOAD_VERSION >= GL_VERSION_1_4
GL_FUNCTIONS_1_4
#endif
#if GL_LOAD_VERSION >= GL_VERSION_1_5
GL_FUNCTIONS_1_5
#endif
#if GL_LOAD_VERSION >= GL_VERSION_2_0
GL_FUNCTIONS_2_0
#endif
#if GL_LOAD_VERSION >= GL_VERSION_2_1
GL_FUNCTIONS_2_1
#endif
#if GL_LOAD_VERSION >= GL_VERSION_3_0
GL_FUNCTIONS_3_0
#endif
#if GL_LOAD_VERSION >= GL_VERSION_3_1
GL_FUNCTIONS_3_1
#endif
#if GL_LOAD_VERSION >= GL_VERSION_3_2
GL_FUNCTIONS_3_2
#endif
#if GL_LOAD_VERSION >= GL_VERSION_3_3
GL_FUNCTIONS_3_3
#endif
#if GL_LOAD_VERSION >= GL_VERSION_4_0
GL_FUNCTIONS_4_0
#endif
#if GL_LOAD_VERSION >= GL_VERSION_4_1
GL_FUNCTIONS_4_1
#endif
#if GL_LOAD_VERSION >= GL_VERSION_4_2
GL_FUNCTIONS_4_2
#endif
#if GL_LOAD_VERSION >= GL_VERSION_4_3
GL_FUNCTIONS_4_3
#endif
#if GL_LOAD_VERSION >= GL_VERSION_4_4
GL_FUNCTIONS_4_4
#endif
#if GL_LOAD_VERSION >= GL_VERSION_4_5
GL_FUNCTIONS_4_5
#endif
#if GL_LOAD_VERSION >= GL_VERSION_4_6
GL_FUNCTIONS_4_6
#endif
#undef X

#if defined(GL_EXT_AMD_framebuffer_multisample_advanced)
#define GL_RENDERBUFFER_STORAGE_SAMPLES_AMD 0x91B2
#define GL_MAX_COLOR_FRAMEBUFFER_SAMPLES_AMD 0x91B3
#define GL_MAX_COLOR_FRAMEBUFFER_STORAGE_SAMPLES_AMD 0x91B4
#define GL_MAX_DEPTH_STENCIL_FRAMEBUFFER_SAMPLES_AMD 0x91B5
#define GL_NUM_SUPPORTED_MULTISAMPLE_MODES_AMD 0x91B6
#define GL_SUPPORTED_MULTISAMPLE_MODES_AMD 0x91B7
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC)(GLenum target, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisampleAdvancedAMD gll_glRenderbufferStorageMultisampleAdvancedAMD
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC)(GLuint renderbuffer, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisampleAdvancedAMD gll_glNamedRenderbufferStorageMultisampleAdvancedAMD
#endif // GL_EXT_AMD_framebuffer_multisample_advanced

#if defined(GL_EXT_AMD_performance_monitor)
#define GL_COUNTER_TYPE_AMD 0x8BC0
#define GL_COUNTER_RANGE_AMD 0x8BC1
#define GL_UNSIGNED_INT64_AMD 0x8BC2
#define GL_PERCENTAGE_AMD 0x8BC3
#define GL_PERFMON_RESULT_AVAILABLE_AMD 0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD 0x8BC5
#define GL_PERFMON_RESULT_AMD 0x8BC6
typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSAMDPROC)(GLint * numGroups, GLsizei groupsSize, GLuint * groups);
#define glGetPerfMonitorGroupsAMD gll_glGetPerfMonitorGroupsAMD
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSAMDPROC)(GLuint group, GLint * numCounters, GLint * maxActiveCounters, GLsizei counterSize, GLuint * counters);
#define glGetPerfMonitorCountersAMD gll_glGetPerfMonitorCountersAMD
typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSTRINGAMDPROC)(GLuint group, GLsizei bufSize, GLsizei * length, GLchar * groupString);
#define glGetPerfMonitorGroupStringAMD gll_glGetPerfMonitorGroupStringAMD
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC)(GLuint group, GLuint counter, GLsizei bufSize, GLsizei * length, GLchar * counterString);
#define glGetPerfMonitorCounterStringAMD gll_glGetPerfMonitorCounterStringAMD
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERINFOAMDPROC)(GLuint group, GLuint counter, GLenum pname, void * data);
#define glGetPerfMonitorCounterInfoAMD gll_glGetPerfMonitorCounterInfoAMD
typedef void (APIENTRYP PFNGLGENPERFMONITORSAMDPROC)(GLsizei n, GLuint * monitors);
#define glGenPerfMonitorsAMD gll_glGenPerfMonitorsAMD
typedef void (APIENTRYP PFNGLDELETEPERFMONITORSAMDPROC)(GLsizei n, GLuint * monitors);
#define glDeletePerfMonitorsAMD gll_glDeletePerfMonitorsAMD
typedef void (APIENTRYP PFNGLSELECTPERFMONITORCOUNTERSAMDPROC)(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint * counterList);
#define glSelectPerfMonitorCountersAMD gll_glSelectPerfMonitorCountersAMD
typedef void (APIENTRYP PFNGLBEGINPERFMONITORAMDPROC)(GLuint monitor);
#define glBeginPerfMonitorAMD gll_glBeginPerfMonitorAMD
typedef void (APIENTRYP PFNGLENDPERFMONITORAMDPROC)(GLuint monitor);
#define glEndPerfMonitorAMD gll_glEndPerfMonitorAMD
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERDATAAMDPROC)(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint * data, GLint * bytesWritten);
#define glGetPerfMonitorCounterDataAMD gll_glGetPerfMonitorCounterDataAMD
#endif // GL_EXT_AMD_performance_monitor

#if defined(GL_EXT_APPLE_rgb_422)
#define GL_RGB_422_APPLE 0x8A1F
#define GL_UNSIGNED_SHORT_8_8_APPLE 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE 0x85BB
#define GL_RGB_RAW_422_APPLE 0x8A51
#endif // GL_EXT_APPLE_rgb_422

#if defined(GL_EXT_ARB_ES2_compatibility)
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC)(void);
#define glReleaseShaderCompiler gll_glReleaseShaderCompiler
typedef void (APIENTRYP PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint * shaders, GLenum binaryFormat, const void * binary, GLsizei length);
#define glShaderBinary gll_glShaderBinary
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
#define glGetShaderPrecisionFormat gll_glGetShaderPrecisionFormat
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
#define glDepthRangef gll_glDepthRangef
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC)(GLfloat d);
#define glClearDepthf gll_glClearDepthf
#endif // GL_EXT_ARB_ES2_compatibility

#if defined(GL_EXT_ARB_ES3_1_compatibility)
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield barriers);
#define glMemoryBarrierByRegion gll_glMemoryBarrierByRegion
#endif // GL_EXT_ARB_ES3_1_compatibility

#if defined(GL_EXT_ARB_ES3_2_compatibility)
#define GL_PRIMITIVE_BOUNDING_BOX_ARB 0x92BE
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB 0x9381
#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB 0x9382
typedef void (APIENTRYP PFNGLPRIMITIVEBOUNDINGBOXARBPROC)(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#define glPrimitiveBoundingBoxARB gll_glPrimitiveBoundingBoxARB
#endif // GL_EXT_ARB_ES3_2_compatibility

#if defined(GL_EXT_ARB_ES3_compatibility)
#endif // GL_EXT_ARB_ES3_compatibility

#if defined(GL_EXT_ARB_base_instance)
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
#define glDrawArraysInstancedBaseInstance gll_glDrawArraysInstancedBaseInstance
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
#define glDrawElementsInstancedBaseInstance gll_glDrawElementsInstancedBaseInstance
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
#define glDrawElementsInstancedBaseVertexBaseInstance gll_glDrawElementsInstancedBaseVertexBaseInstance
#endif // GL_EXT_ARB_base_instance

#if defined(GL_EXT_ARB_bindless_texture)
#define GL_UNSIGNED_INT64_ARB 0x140F
typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC)(GLuint texture);
#define glGetTextureHandleARB gll_glGetTextureHandleARB
typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC)(GLuint texture, GLuint sampler);
#define glGetTextureSamplerHandleARB gll_glGetTextureSamplerHandleARB
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
#define glMakeTextureHandleResidentARB gll_glMakeTextureHandleResidentARB
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)(GLuint64 handle);
#define glMakeTextureHandleNonResidentARB gll_glMakeTextureHandleNonResidentARB
typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLEARBPROC)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
#define glGetImageHandleARB gll_glGetImageHandleARB
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle, GLenum access);
#define glMakeImageHandleResidentARB gll_glMakeImageHandleResidentARB
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)(GLuint64 handle);
#define glMakeImageHandleNonResidentARB gll_glMakeImageHandleNonResidentARB
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC)(GLint location, GLuint64 value);
#define glUniformHandleui64ARB gll_glUniformHandleui64ARB
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC)(GLint location, GLsizei count, const GLuint64 * value);
#define glUniformHandleui64vARB gll_glUniformHandleui64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)(GLuint program, GLint location, GLuint64 value);
#define glProgramUniformHandleui64ARB gll_glProgramUniformHandleui64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 * values);
#define glProgramUniformHandleui64vARB gll_glProgramUniformHandleui64vARB
typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
#define glIsTextureHandleResidentARB gll_glIsTextureHandleResidentARB
typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle);
#define glIsImageHandleResidentARB gll_glIsImageHandleResidentARB
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC)(GLuint index, GLuint64EXT x);
#define glVertexAttribL1ui64ARB gll_glVertexAttribL1ui64ARB
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC)(GLuint index, const GLuint64EXT * v);
#define glVertexAttribL1ui64vARB gll_glVertexAttribL1ui64vARB
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC)(GLuint index, GLenum pname, GLuint64EXT * params);
#define glGetVertexAttribLui64vARB gll_glGetVertexAttribLui64vARB
#endif // GL_EXT_ARB_bindless_texture

#if defined(GL_EXT_ARB_blend_func_extended)
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name);
#define glBindFragDataLocationIndexed gll_glBindFragDataLocationIndexed
typedef GLint (APIENTRYP PFNGLGETFRAGDATAINDEXPROC)(GLuint program, const GLchar * name);
#define glGetFragDataIndex gll_glGetFragDataIndex
#endif // GL_EXT_ARB_blend_func_extended

#if defined(GL_EXT_ARB_buffer_storage)
typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC)(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags);
#define glBufferStorage gll_glBufferStorage
#endif // GL_EXT_ARB_buffer_storage

#if defined(GL_EXT_ARB_cl_event)
#define GL_SYNC_CL_EVENT_ARB 0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB 0x8241
typedef GLsync (APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC)(struct _cl_context * context, struct _cl_event * event, GLbitfield flags);
#define glCreateSyncFromCLeventARB gll_glCreateSyncFromCLeventARB
#endif // GL_EXT_ARB_cl_event

#if defined(GL_EXT_ARB_clear_buffer_object)
typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC)(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearBufferData gll_glClearBufferData
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearBufferSubData gll_glClearBufferSubData
#endif // GL_EXT_ARB_clear_buffer_object

#if defined(GL_EXT_ARB_clear_texture)
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
#define glClearTexImage gll_glClearTexImage
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
#define glClearTexSubImage gll_glClearTexSubImage
#endif // GL_EXT_ARB_clear_texture

#if defined(GL_EXT_ARB_clip_control)
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC)(GLenum origin, GLenum depth);
#define glClipControl gll_glClipControl
#endif // GL_EXT_ARB_clip_control

#if defined(GL_EXT_ARB_compressed_texture_pixel_storage)
#endif // GL_EXT_ARB_compressed_texture_pixel_storage

#if defined(GL_EXT_ARB_compute_shader)
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
#define glDispatchCompute gll_glDispatchCompute
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr indirect);
#define glDispatchComputeIndirect gll_glDispatchComputeIndirect
#endif // GL_EXT_ARB_compute_shader

#if defined(GL_EXT_ARB_compute_variable_group_size)
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#define glDispatchComputeGroupSizeARB gll_glDispatchComputeGroupSizeARB
#endif // GL_EXT_ARB_compute_variable_group_size

#if defined(GL_EXT_ARB_conditional_render_inverted)
#endif // GL_EXT_ARB_conditional_render_inverted

#if defined(GL_EXT_ARB_copy_buffer)
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyBufferSubData gll_glCopyBufferSubData
#endif // GL_EXT_ARB_copy_buffer

#if defined(GL_EXT_ARB_copy_image)
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
#define glCopyImageSubData gll_glCopyImageSubData
#endif // GL_EXT_ARB_copy_image

#if defined(GL_EXT_ARB_cull_distance)
#endif // GL_EXT_ARB_cull_distance

#if defined(GL_EXT_ARB_debug_output)
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB 0x8245
#define GL_DEBUG_SOURCE_API_ARB 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB 0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB 0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB 0x824B
#define GL_DEBUG_TYPE_ERROR_ARB 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB 0x8250
#define GL_DEBUG_TYPE_OTHER_ARB 0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB 0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB 0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB 0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB 0x9148
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
#define glDebugMessageControlARB gll_glDebugMessageControlARB
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
#define glDebugMessageInsertARB gll_glDebugMessageInsertARB
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC)(GLDEBUGPROCARB callback, const void * userParam);
#define glDebugMessageCallbackARB gll_glDebugMessageCallbackARB
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
#define glGetDebugMessageLogARB gll_glGetDebugMessageLogARB
#endif // GL_EXT_ARB_debug_output

#if defined(GL_EXT_ARB_depth_buffer_float)
#endif // GL_EXT_ARB_depth_buffer_float

#if defined(GL_EXT_ARB_depth_clamp)
#endif // GL_EXT_ARB_depth_clamp

#if defined(GL_EXT_ARB_direct_state_access)
typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint * ids);
#define glCreateTransformFeedbacks gll_glCreateTransformFeedbacks
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)(GLuint xfb, GLuint index, GLuint buffer);
#define glTransformFeedbackBufferBase gll_glTransformFeedbackBufferBase
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTransformFeedbackBufferRange gll_glTransformFeedbackBufferRange
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC)(GLuint xfb, GLenum pname, GLint * param);
#define glGetTransformFeedbackiv gll_glGetTransformFeedbackiv
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint * param);
#define glGetTransformFeedbacki_v gll_glGetTransformFeedbacki_v
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC)(GLuint xfb, GLenum pname, GLuint index, GLint64 * param);
#define glGetTransformFeedbacki64_v gll_glGetTransformFeedbacki64_v
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC)(GLsizei n, GLuint * buffers);
#define glCreateBuffers gll_glCreateBuffers
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
#define glNamedBufferStorage gll_glNamedBufferStorage
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
#define glNamedBufferData gll_glNamedBufferData
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
#define glNamedBufferSubData gll_glNamedBufferSubData
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glCopyNamedBufferSubData gll_glCopyNamedBufferSubData
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferData gll_glClearNamedBufferData
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferSubData gll_glClearNamedBufferSubData
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERPROC)(GLuint buffer, GLenum access);
#define glMapNamedBuffer gll_glMapNamedBuffer
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapNamedBufferRange gll_glMapNamedBufferRange
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC)(GLuint buffer);
#define glUnmapNamedBuffer gll_glUnmapNamedBuffer
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glFlushMappedNamedBufferRange gll_glFlushMappedNamedBufferRange
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC)(GLuint buffer, GLenum pname, GLint * params);
#define glGetNamedBufferParameteriv gll_glGetNamedBufferParameteriv
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)(GLuint buffer, GLenum pname, GLint64 * params);
#define glGetNamedBufferParameteri64v gll_glGetNamedBufferParameteri64v
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC)(GLuint buffer, GLenum pname, void ** params);
#define glGetNamedBufferPointerv gll_glGetNamedBufferPointerv
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
#define glGetNamedBufferSubData gll_glGetNamedBufferSubData
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC)(GLsizei n, GLuint * framebuffers);
#define glCreateFramebuffers gll_glCreateFramebuffers
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glNamedFramebufferRenderbuffer gll_glNamedFramebufferRenderbuffer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)(GLuint framebuffer, GLenum pname, GLint param);
#define glNamedFramebufferParameteri gll_glNamedFramebufferParameteri
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
#define glNamedFramebufferTexture gll_glNamedFramebufferTexture
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glNamedFramebufferTextureLayer gll_glNamedFramebufferTextureLayer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)(GLuint framebuffer, GLenum buf);
#define glNamedFramebufferDrawBuffer gll_glNamedFramebufferDrawBuffer
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)(GLuint framebuffer, GLsizei n, const GLenum * bufs);
#define glNamedFramebufferDrawBuffers gll_glNamedFramebufferDrawBuffers
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)(GLuint framebuffer, GLenum src);
#define glNamedFramebufferReadBuffer gll_glNamedFramebufferReadBuffer
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateNamedFramebufferData gll_glInvalidateNamedFramebufferData
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)(GLuint framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateNamedFramebufferSubData gll_glInvalidateNamedFramebufferSubData
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint * value);
#define glClearNamedFramebufferiv gll_glClearNamedFramebufferiv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint * value);
#define glClearNamedFramebufferuiv gll_glClearNamedFramebufferuiv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat * value);
#define glClearNamedFramebufferfv gll_glClearNamedFramebufferfv
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
#define glClearNamedFramebufferfi gll_glClearNamedFramebufferfi
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC)(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitNamedFramebuffer gll_glBlitNamedFramebuffer
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)(GLuint framebuffer, GLenum target);
#define glCheckNamedFramebufferStatus gll_glCheckNamedFramebufferStatus
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)(GLuint framebuffer, GLenum pname, GLint * param);
#define glGetNamedFramebufferParameteriv gll_glGetNamedFramebufferParameteriv
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
#define glGetNamedFramebufferAttachmentParameteriv gll_glGetNamedFramebufferAttachmentParameteriv
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC)(GLsizei n, GLuint * renderbuffers);
#define glCreateRenderbuffers gll_glCreateRenderbuffers
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorage gll_glNamedRenderbufferStorage
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisample gll_glNamedRenderbufferStorageMultisample
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)(GLuint renderbuffer, GLenum pname, GLint * params);
#define glGetNamedRenderbufferParameteriv gll_glGetNamedRenderbufferParameteriv
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC)(GLenum target, GLsizei n, GLuint * textures);
#define glCreateTextures gll_glCreateTextures
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC)(GLuint texture, GLenum internalformat, GLuint buffer);
#define glTextureBuffer gll_glTextureBuffer
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC)(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTextureBufferRange gll_glTextureBufferRange
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTextureStorage1D gll_glTextureStorage1D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTextureStorage2D gll_glTextureStorage2D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC)(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTextureStorage3D gll_glTextureStorage3D
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTextureStorage2DMultisample gll_glTextureStorage2DMultisample
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTextureStorage3DMultisample gll_glTextureStorage3DMultisample
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage1D gll_glTextureSubImage1D
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage2D gll_glTextureSubImage2D
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage3D gll_glTextureSubImage3D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage1D gll_glCompressedTextureSubImage1D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage2D gll_glCompressedTextureSubImage2D
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
#define glCompressedTextureSubImage3D gll_glCompressedTextureSubImage3D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC)(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTextureSubImage1D gll_glCopyTextureSubImage1D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage2D gll_glCopyTextureSubImage2D
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage3D gll_glCopyTextureSubImage3D
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC)(GLuint texture, GLenum pname, GLfloat param);
#define glTextureParameterf gll_glTextureParameterf
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, const GLfloat * param);
#define glTextureParameterfv gll_glTextureParameterfv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC)(GLuint texture, GLenum pname, GLint param);
#define glTextureParameteri gll_glTextureParameteri
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, const GLint * params);
#define glTextureParameterIiv gll_glTextureParameterIiv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, const GLuint * params);
#define glTextureParameterIuiv gll_glTextureParameterIuiv
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, const GLint * param);
#define glTextureParameteriv gll_glTextureParameteriv
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC)(GLuint texture);
#define glGenerateTextureMipmap gll_glGenerateTextureMipmap
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC)(GLuint unit, GLuint texture);
#define glBindTextureUnit gll_glBindTextureUnit
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureImage gll_glGetTextureImage
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)(GLuint texture, GLint level, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureImage gll_glGetCompressedTextureImage
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC)(GLuint texture, GLint level, GLenum pname, GLfloat * params);
#define glGetTextureLevelParameterfv gll_glGetTextureLevelParameterfv
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC)(GLuint texture, GLint level, GLenum pname, GLint * params);
#define glGetTextureLevelParameteriv gll_glGetTextureLevelParameteriv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC)(GLuint texture, GLenum pname, GLfloat * params);
#define glGetTextureParameterfv gll_glGetTextureParameterfv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameterIiv gll_glGetTextureParameterIiv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC)(GLuint texture, GLenum pname, GLuint * params);
#define glGetTextureParameterIuiv gll_glGetTextureParameterIuiv
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC)(GLuint texture, GLenum pname, GLint * params);
#define glGetTextureParameteriv gll_glGetTextureParameteriv
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC)(GLsizei n, GLuint * arrays);
#define glCreateVertexArrays gll_glCreateVertexArrays
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
#define glDisableVertexArrayAttrib gll_glDisableVertexArrayAttrib
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC)(GLuint vaobj, GLuint index);
#define glEnableVertexArrayAttrib gll_glEnableVertexArrayAttrib
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC)(GLuint vaobj, GLuint buffer);
#define glVertexArrayElementBuffer gll_glVertexArrayElementBuffer
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glVertexArrayVertexBuffer gll_glVertexArrayVertexBuffer
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC)(GLuint vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glVertexArrayVertexBuffers gll_glVertexArrayVertexBuffers
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
#define glVertexArrayAttribBinding gll_glVertexArrayAttribBinding
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexArrayAttribFormat gll_glVertexArrayAttribFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribIFormat gll_glVertexArrayAttribIFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayAttribLFormat gll_glVertexArrayAttribLFormat
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#define glVertexArrayBindingDivisor gll_glVertexArrayBindingDivisor
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC)(GLuint vaobj, GLenum pname, GLint * param);
#define glGetVertexArrayiv gll_glGetVertexArrayiv
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint * param);
#define glGetVertexArrayIndexediv gll_glGetVertexArrayIndexediv
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param);
#define glGetVertexArrayIndexed64iv gll_glGetVertexArrayIndexed64iv
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC)(GLsizei n, GLuint * samplers);
#define glCreateSamplers gll_glCreateSamplers
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC)(GLsizei n, GLuint * pipelines);
#define glCreateProgramPipelines gll_glCreateProgramPipelines
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC)(GLenum target, GLsizei n, GLuint * ids);
#define glCreateQueries gll_glCreateQueries
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjecti64v gll_glGetQueryBufferObjecti64v
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectiv gll_glGetQueryBufferObjectiv
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectui64v gll_glGetQueryBufferObjectui64v
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC)(GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
#define glGetQueryBufferObjectuiv gll_glGetQueryBufferObjectuiv
#endif // GL_EXT_ARB_direct_state_access

#if defined(GL_EXT_ARB_draw_buffers_blend)
typedef void (APIENTRYP PFNGLBLENDEQUATIONIARBPROC)(GLuint buf, GLenum mode);
#define glBlendEquationiARB gll_glBlendEquationiARB
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparateiARB gll_glBlendEquationSeparateiARB
typedef void (APIENTRYP PFNGLBLENDFUNCIARBPROC)(GLuint buf, GLenum src, GLenum dst);
#define glBlendFunciARB gll_glBlendFunciARB
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#define glBlendFuncSeparateiARB gll_glBlendFuncSeparateiARB
#endif // GL_EXT_ARB_draw_buffers_blend

#if defined(GL_EXT_ARB_draw_elements_base_vertex)
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
#define glDrawElementsBaseVertex gll_glDrawElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
#define glDrawRangeElementsBaseVertex gll_glDrawRangeElementsBaseVertex
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
#define glDrawElementsInstancedBaseVertex gll_glDrawElementsInstancedBaseVertex
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex);
#define glMultiDrawElementsBaseVertex gll_glMultiDrawElementsBaseVertex
#endif // GL_EXT_ARB_draw_elements_base_vertex

#if defined(GL_EXT_ARB_draw_indirect)
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC)(GLenum mode, const void * indirect);
#define glDrawArraysIndirect gll_glDrawArraysIndirect
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void * indirect);
#define glDrawElementsIndirect gll_glDrawElementsIndirect
#endif // GL_EXT_ARB_draw_indirect

#if defined(GL_EXT_ARB_draw_instanced)
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDARBPROC)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
#define glDrawArraysInstancedARB gll_glDrawArraysInstancedARB
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDARBPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
#define glDrawElementsInstancedARB gll_glDrawElementsInstancedARB
#endif // GL_EXT_ARB_draw_instanced

#if defined(GL_EXT_ARB_enhanced_layouts)
#endif // GL_EXT_ARB_enhanced_layouts

#if defined(GL_EXT_ARB_explicit_uniform_location)
#endif // GL_EXT_ARB_explicit_uniform_location

#if defined(GL_EXT_ARB_framebuffer_no_attachments)
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
#define glFramebufferParameteri gll_glFramebufferParameteri
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetFramebufferParameteriv gll_glGetFramebufferParameteriv
#endif // GL_EXT_ARB_framebuffer_no_attachments

#if defined(GL_EXT_ARB_framebuffer_object)
typedef GLboolean (APIENTRYP PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
#define glIsRenderbuffer gll_glIsRenderbuffer
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
#define glBindRenderbuffer gll_glBindRenderbuffer
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint * renderbuffers);
#define glDeleteRenderbuffers gll_glDeleteRenderbuffers
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint * renderbuffers);
#define glGenRenderbuffers gll_glGenRenderbuffers
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorage gll_glRenderbufferStorage
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetRenderbufferParameteriv gll_glGetRenderbufferParameteriv
typedef GLboolean (APIENTRYP PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
#define glIsFramebuffer gll_glIsFramebuffer
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
#define glBindFramebuffer gll_glBindFramebuffer
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint * framebuffers);
#define glDeleteFramebuffers gll_glDeleteFramebuffers
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint * framebuffers);
#define glGenFramebuffers gll_glGenFramebuffers
typedef GLenum (APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
#define glCheckFramebufferStatus gll_glCheckFramebufferStatus
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture1D gll_glFramebufferTexture1D
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glFramebufferTexture2D gll_glFramebufferTexture2D
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
#define glFramebufferTexture3D gll_glFramebufferTexture3D
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glFramebufferRenderbuffer gll_glFramebufferRenderbuffer
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
#define glGetFramebufferAttachmentParameteriv gll_glGetFramebufferAttachmentParameteriv
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC)(GLenum target);
#define glGenerateMipmap gll_glGenerateMipmap
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitFramebuffer gll_glBlitFramebuffer
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisample gll_glRenderbufferStorageMultisample
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glFramebufferTextureLayer gll_glFramebufferTextureLayer
#endif // GL_EXT_ARB_framebuffer_object

#if defined(GL_EXT_ARB_framebuffer_sRGB)
#endif // GL_EXT_ARB_framebuffer_sRGB

#if defined(GL_EXT_ARB_geometry_shader4)
#define GL_LINES_ADJACENCY_ARB 0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB 0x000B
#define GL_TRIANGLES_ADJACENCY_ARB 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB 0x000D
#define GL_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_GEOMETRY_SHADER_ARB 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB 0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIARBPROC)(GLuint program, GLenum pname, GLint value);
#define glProgramParameteriARB gll_glProgramParameteriARB
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level);
#define glFramebufferTextureARB gll_glFramebufferTextureARB
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glFramebufferTextureLayerARB gll_glFramebufferTextureLayerARB
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#define glFramebufferTextureFaceARB gll_glFramebufferTextureFaceARB
#endif // GL_EXT_ARB_geometry_shader4

#if defined(GL_EXT_ARB_get_program_binary)
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
#define glGetProgramBinary gll_glGetProgramBinary
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
#define glProgramBinary gll_glProgramBinary
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
#define glProgramParameteri gll_glProgramParameteri
#endif // GL_EXT_ARB_get_program_binary

#if defined(GL_EXT_ARB_get_texture_sub_image)
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
#define glGetTextureSubImage gll_glGetTextureSubImage
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels);
#define glGetCompressedTextureSubImage gll_glGetCompressedTextureSubImage
#endif // GL_EXT_ARB_get_texture_sub_image

#if defined(GL_EXT_ARB_gl_spirv)
#define GL_SHADER_BINARY_FORMAT_SPIR_V_ARB 0x9551
#define GL_SPIR_V_BINARY_ARB 0x9552
typedef void (APIENTRYP PFNGLSPECIALIZESHADERARBPROC)(GLuint shader, const GLchar * pEntryPoint, GLuint numSpecializationConstants, const GLuint * pConstantIndex, const GLuint * pConstantValue);
#define glSpecializeShaderARB gll_glSpecializeShaderARB
#endif // GL_EXT_ARB_gl_spirv

#if defined(GL_EXT_ARB_gpu_shader5)
#endif // GL_EXT_ARB_gpu_shader5

#if defined(GL_EXT_ARB_gpu_shader_fp64)
typedef void (APIENTRYP PFNGLUNIFORM1DPROC)(GLint location, GLdouble x);
#define glUniform1d gll_glUniform1d
typedef void (APIENTRYP PFNGLUNIFORM2DPROC)(GLint location, GLdouble x, GLdouble y);
#define glUniform2d gll_glUniform2d
typedef void (APIENTRYP PFNGLUNIFORM3DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z);
#define glUniform3d gll_glUniform3d
typedef void (APIENTRYP PFNGLUNIFORM4DPROC)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glUniform4d gll_glUniform4d
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform1dv gll_glUniform1dv
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform2dv gll_glUniform2dv
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform3dv gll_glUniform3dv
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC)(GLint location, GLsizei count, const GLdouble * value);
#define glUniform4dv gll_glUniform4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2dv gll_glUniformMatrix2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3dv gll_glUniformMatrix3dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4dv gll_glUniformMatrix4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x3dv gll_glUniformMatrix2x3dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix2x4dv gll_glUniformMatrix2x4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x2dv gll_glUniformMatrix3x2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix3x4dv gll_glUniformMatrix3x4dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x2dv gll_glUniformMatrix4x2dv
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glUniformMatrix4x3dv gll_glUniformMatrix4x3dv
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC)(GLuint program, GLint location, GLdouble * params);
#define glGetUniformdv gll_glGetUniformdv
#endif // GL_EXT_ARB_gpu_shader_fp64

#if defined(GL_EXT_ARB_gpu_shader_int64)
#define GL_INT64_ARB 0x140E
#define GL_INT64_VEC2_ARB 0x8FE9
#define GL_INT64_VEC3_ARB 0x8FEA
#define GL_INT64_VEC4_ARB 0x8FEB
#define GL_UNSIGNED_INT64_VEC2_ARB 0x8FF5
#define GL_UNSIGNED_INT64_VEC3_ARB 0x8FF6
#define GL_UNSIGNED_INT64_VEC4_ARB 0x8FF7
typedef void (APIENTRYP PFNGLUNIFORM1I64ARBPROC)(GLint location, GLint64 x);
#define glUniform1i64ARB gll_glUniform1i64ARB
typedef void (APIENTRYP PFNGLUNIFORM2I64ARBPROC)(GLint location, GLint64 x, GLint64 y);
#define glUniform2i64ARB gll_glUniform2i64ARB
typedef void (APIENTRYP PFNGLUNIFORM3I64ARBPROC)(GLint location, GLint64 x, GLint64 y, GLint64 z);
#define glUniform3i64ARB gll_glUniform3i64ARB
typedef void (APIENTRYP PFNGLUNIFORM4I64ARBPROC)(GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
#define glUniform4i64ARB gll_glUniform4i64ARB
typedef void (APIENTRYP PFNGLUNIFORM1I64VARBPROC)(GLint location, GLsizei count, const GLint64 * value);
#define glUniform1i64vARB gll_glUniform1i64vARB
typedef void (APIENTRYP PFNGLUNIFORM2I64VARBPROC)(GLint location, GLsizei count, const GLint64 * value);
#define glUniform2i64vARB gll_glUniform2i64vARB
typedef void (APIENTRYP PFNGLUNIFORM3I64VARBPROC)(GLint location, GLsizei count, const GLint64 * value);
#define glUniform3i64vARB gll_glUniform3i64vARB
typedef void (APIENTRYP PFNGLUNIFORM4I64VARBPROC)(GLint location, GLsizei count, const GLint64 * value);
#define glUniform4i64vARB gll_glUniform4i64vARB
typedef void (APIENTRYP PFNGLUNIFORM1UI64ARBPROC)(GLint location, GLuint64 x);
#define glUniform1ui64ARB gll_glUniform1ui64ARB
typedef void (APIENTRYP PFNGLUNIFORM2UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y);
#define glUniform2ui64ARB gll_glUniform2ui64ARB
typedef void (APIENTRYP PFNGLUNIFORM3UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
#define glUniform3ui64ARB gll_glUniform3ui64ARB
typedef void (APIENTRYP PFNGLUNIFORM4UI64ARBPROC)(GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
#define glUniform4ui64ARB gll_glUniform4ui64ARB
typedef void (APIENTRYP PFNGLUNIFORM1UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 * value);
#define glUniform1ui64vARB gll_glUniform1ui64vARB
typedef void (APIENTRYP PFNGLUNIFORM2UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 * value);
#define glUniform2ui64vARB gll_glUniform2ui64vARB
typedef void (APIENTRYP PFNGLUNIFORM3UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 * value);
#define glUniform3ui64vARB gll_glUniform3ui64vARB
typedef void (APIENTRYP PFNGLUNIFORM4UI64VARBPROC)(GLint location, GLsizei count, const GLuint64 * value);
#define glUniform4ui64vARB gll_glUniform4ui64vARB
typedef void (APIENTRYP PFNGLGETUNIFORMI64VARBPROC)(GLuint program, GLint location, GLint64 * params);
#define glGetUniformi64vARB gll_glGetUniformi64vARB
typedef void (APIENTRYP PFNGLGETUNIFORMUI64VARBPROC)(GLuint program, GLint location, GLuint64 * params);
#define glGetUniformui64vARB gll_glGetUniformui64vARB
typedef void (APIENTRYP PFNGLGETNUNIFORMI64VARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLint64 * params);
#define glGetnUniformi64vARB gll_glGetnUniformi64vARB
typedef void (APIENTRYP PFNGLGETNUNIFORMUI64VARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint64 * params);
#define glGetnUniformui64vARB gll_glGetnUniformui64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64ARBPROC)(GLuint program, GLint location, GLint64 x);
#define glProgramUniform1i64ARB gll_glProgramUniform1i64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y);
#define glProgramUniform2i64ARB gll_glProgramUniform2i64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
#define glProgramUniform3i64ARB gll_glProgramUniform3i64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64ARBPROC)(GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
#define glProgramUniform4i64ARB gll_glProgramUniform4i64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 * value);
#define glProgramUniform1i64vARB gll_glProgramUniform1i64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 * value);
#define glProgramUniform2i64vARB gll_glProgramUniform2i64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 * value);
#define glProgramUniform3i64vARB gll_glProgramUniform3i64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLint64 * value);
#define glProgramUniform4i64vARB gll_glProgramUniform4i64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64ARBPROC)(GLuint program, GLint location, GLuint64 x);
#define glProgramUniform1ui64ARB gll_glProgramUniform1ui64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64ARBPROC)(GLuint program, GLint location, GLuint64 x, GLuint64 y);
#define glProgramUniform2ui64ARB gll_glProgramUniform2ui64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64ARBPROC)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
#define glProgramUniform3ui64ARB gll_glProgramUniform3ui64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64ARBPROC)(GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
#define glProgramUniform4ui64ARB gll_glProgramUniform4ui64ARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 * value);
#define glProgramUniform1ui64vARB gll_glProgramUniform1ui64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 * value);
#define glProgramUniform2ui64vARB gll_glProgramUniform2ui64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 * value);
#define glProgramUniform3ui64vARB gll_glProgramUniform3ui64vARB
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 * value);
#define glProgramUniform4ui64vARB gll_glProgramUniform4ui64vARB
#endif // GL_EXT_ARB_gpu_shader_int64

#if defined(GL_EXT_ARB_half_float_vertex)
typedef khronos_uint16_t GLhalf;
#endif // GL_EXT_ARB_half_float_vertex

#if defined(GL_EXT_ARB_imaging)
typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glBlendColor gll_glBlendColor
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
#define glBlendEquation gll_glBlendEquation
#define GL_CONVOLUTION_BORDER_MODE 0x8013
#define GL_CONVOLUTION_FILTER_SCALE 0x8014
#define GL_CONVOLUTION_FILTER_BIAS 0x8015
#define GL_REDUCE 0x8016
#define GL_CONVOLUTION_FORMAT 0x8017
#define GL_CONVOLUTION_WIDTH 0x8018
#define GL_CONVOLUTION_HEIGHT 0x8019
#define GL_MAX_CONVOLUTION_WIDTH 0x801A
#define GL_MAX_CONVOLUTION_HEIGHT 0x801B
#define GL_POST_CONVOLUTION_RED_SCALE 0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS 0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS 0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS 0x8023
#define GL_HISTOGRAM_WIDTH 0x8026
#define GL_HISTOGRAM_FORMAT 0x8027
#define GL_HISTOGRAM_RED_SIZE 0x8028
#define GL_HISTOGRAM_GREEN_SIZE 0x8029
#define GL_HISTOGRAM_BLUE_SIZE 0x802A
#define GL_HISTOGRAM_ALPHA_SIZE 0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE 0x802C
#define GL_HISTOGRAM_SINK 0x802D
#define GL_MINMAX_FORMAT 0x802F
#define GL_MINMAX_SINK 0x8030
#define GL_TABLE_TOO_LARGE 0x8031
#define GL_COLOR_MATRIX 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH 0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH 0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE 0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE 0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE 0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE 0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS 0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS 0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS 0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS 0x80BB
#define GL_COLOR_TABLE_SCALE 0x80D6
#define GL_COLOR_TABLE_BIAS 0x80D7
#define GL_COLOR_TABLE_FORMAT 0x80D8
#define GL_COLOR_TABLE_WIDTH 0x80D9
#define GL_COLOR_TABLE_RED_SIZE 0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE 0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE 0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE 0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE 0x80DF
#define GL_CONSTANT_BORDER 0x8151
#define GL_REPLICATE_BORDER 0x8153
#define GL_CONVOLUTION_BORDER_COLOR 0x8154
typedef void (APIENTRYP PFNGLCOLORTABLEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * table);
#define glColorTable gll_glColorTable
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat * params);
#define glColorTableParameterfv gll_glColorTableParameterfv
typedef void (APIENTRYP PFNGLCOLORTABLEPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint * params);
#define glColorTableParameteriv gll_glColorTableParameteriv
typedef void (APIENTRYP PFNGLCOPYCOLORTABLEPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
#define glCopyColorTable gll_glCopyColorTable
typedef void (APIENTRYP PFNGLGETCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, void * table);
#define glGetColorTable gll_glGetColorTable
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat * params);
#define glGetColorTableParameterfv gll_glGetColorTableParameterfv
typedef void (APIENTRYP PFNGLGETCOLORTABLEPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetColorTableParameteriv gll_glGetColorTableParameteriv
typedef void (APIENTRYP PFNGLCOLORSUBTABLEPROC)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void * data);
#define glColorSubTable gll_glColorSubTable
typedef void (APIENTRYP PFNGLCOPYCOLORSUBTABLEPROC)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
#define glCopyColorSubTable gll_glCopyColorSubTable
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER1DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void * image);
#define glConvolutionFilter1D gll_glConvolutionFilter1D
typedef void (APIENTRYP PFNGLCONVOLUTIONFILTER2DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * image);
#define glConvolutionFilter2D gll_glConvolutionFilter2D
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat params);
#define glConvolutionParameterf gll_glConvolutionParameterf
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat * params);
#define glConvolutionParameterfv gll_glConvolutionParameterfv
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIPROC)(GLenum target, GLenum pname, GLint params);
#define glConvolutionParameteri gll_glConvolutionParameteri
typedef void (APIENTRYP PFNGLCONVOLUTIONPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint * params);
#define glConvolutionParameteriv gll_glConvolutionParameteriv
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER1DPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
#define glCopyConvolutionFilter1D gll_glCopyConvolutionFilter1D
typedef void (APIENTRYP PFNGLCOPYCONVOLUTIONFILTER2DPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyConvolutionFilter2D gll_glCopyConvolutionFilter2D
typedef void (APIENTRYP PFNGLGETCONVOLUTIONFILTERPROC)(GLenum target, GLenum format, GLenum type, void * image);
#define glGetConvolutionFilter gll_glGetConvolutionFilter
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat * params);
#define glGetConvolutionParameterfv gll_glGetConvolutionParameterfv
typedef void (APIENTRYP PFNGLGETCONVOLUTIONPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetConvolutionParameteriv gll_glGetConvolutionParameteriv
typedef void (APIENTRYP PFNGLGETSEPARABLEFILTERPROC)(GLenum target, GLenum format, GLenum type, void * row, void * column, void * span);
#define glGetSeparableFilter gll_glGetSeparableFilter
typedef void (APIENTRYP PFNGLSEPARABLEFILTER2DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * row, const void * column);
#define glSeparableFilter2D gll_glSeparableFilter2D
typedef void (APIENTRYP PFNGLGETHISTOGRAMPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
#define glGetHistogram gll_glGetHistogram
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat * params);
#define glGetHistogramParameterfv gll_glGetHistogramParameterfv
typedef void (APIENTRYP PFNGLGETHISTOGRAMPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetHistogramParameteriv gll_glGetHistogramParameteriv
typedef void (APIENTRYP PFNGLGETMINMAXPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values);
#define glGetMinmax gll_glGetMinmax
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat * params);
#define glGetMinmaxParameterfv gll_glGetMinmaxParameterfv
typedef void (APIENTRYP PFNGLGETMINMAXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetMinmaxParameteriv gll_glGetMinmaxParameteriv
typedef void (APIENTRYP PFNGLHISTOGRAMPROC)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
#define glHistogram gll_glHistogram
typedef void (APIENTRYP PFNGLMINMAXPROC)(GLenum target, GLenum internalformat, GLboolean sink);
#define glMinmax gll_glMinmax
typedef void (APIENTRYP PFNGLRESETHISTOGRAMPROC)(GLenum target);
#define glResetHistogram gll_glResetHistogram
typedef void (APIENTRYP PFNGLRESETMINMAXPROC)(GLenum target);
#define glResetMinmax gll_glResetMinmax
#endif // GL_EXT_ARB_imaging

#if defined(GL_EXT_ARB_indirect_parameters)
#define GL_PARAMETER_BUFFER_ARB 0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB 0x80EF
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC)(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#define glMultiDrawArraysIndirectCountARB gll_glMultiDrawArraysIndirectCountARB
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC)(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#define glMultiDrawElementsIndirectCountARB gll_glMultiDrawElementsIndirectCountARB
#endif // GL_EXT_ARB_indirect_parameters

#if defined(GL_EXT_ARB_instanced_arrays)
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORARBPROC)(GLuint index, GLuint divisor);
#define glVertexAttribDivisorARB gll_glVertexAttribDivisorARB
#endif // GL_EXT_ARB_instanced_arrays

#if defined(GL_EXT_ARB_internalformat_query)
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params);
#define glGetInternalformativ gll_glGetInternalformativ
#endif // GL_EXT_ARB_internalformat_query

#if defined(GL_EXT_ARB_internalformat_query2)
#define GL_SRGB_DECODE_ARB 0x8299
#define GL_VIEW_CLASS_EAC_R11 0x9383
#define GL_VIEW_CLASS_EAC_RG11 0x9384
#define GL_VIEW_CLASS_ETC2_RGB 0x9385
#define GL_VIEW_CLASS_ETC2_RGBA 0x9386
#define GL_VIEW_CLASS_ETC2_EAC_RGBA 0x9387
#define GL_VIEW_CLASS_ASTC_4x4_RGBA 0x9388
#define GL_VIEW_CLASS_ASTC_5x4_RGBA 0x9389
#define GL_VIEW_CLASS_ASTC_5x5_RGBA 0x938A
#define GL_VIEW_CLASS_ASTC_6x5_RGBA 0x938B
#define GL_VIEW_CLASS_ASTC_6x6_RGBA 0x938C
#define GL_VIEW_CLASS_ASTC_8x5_RGBA 0x938D
#define GL_VIEW_CLASS_ASTC_8x6_RGBA 0x938E
#define GL_VIEW_CLASS_ASTC_8x8_RGBA 0x938F
#define GL_VIEW_CLASS_ASTC_10x5_RGBA 0x9390
#define GL_VIEW_CLASS_ASTC_10x6_RGBA 0x9391
#define GL_VIEW_CLASS_ASTC_10x8_RGBA 0x9392
#define GL_VIEW_CLASS_ASTC_10x10_RGBA 0x9393
#define GL_VIEW_CLASS_ASTC_12x10_RGBA 0x9394
#define GL_VIEW_CLASS_ASTC_12x12_RGBA 0x9395
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 * params);
#define glGetInternalformati64v gll_glGetInternalformati64v
#endif // GL_EXT_ARB_internalformat_query2

#if defined(GL_EXT_ARB_invalidate_subdata)
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
#define glInvalidateTexSubImage gll_glInvalidateTexSubImage
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC)(GLuint texture, GLint level);
#define glInvalidateTexImage gll_glInvalidateTexImage
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glInvalidateBufferSubData gll_glInvalidateBufferSubData
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC)(GLuint buffer);
#define glInvalidateBufferData gll_glInvalidateBufferData
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments);
#define glInvalidateFramebuffer gll_glInvalidateFramebuffer
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
#define glInvalidateSubFramebuffer gll_glInvalidateSubFramebuffer
#endif // GL_EXT_ARB_invalidate_subdata

#if defined(GL_EXT_ARB_map_buffer_alignment)
#endif // GL_EXT_ARB_map_buffer_alignment

#if defined(GL_EXT_ARB_map_buffer_range)
typedef void * (APIENTRYP PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapBufferRange gll_glMapBufferRange
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
#define glFlushMappedBufferRange gll_glFlushMappedBufferRange
#endif // GL_EXT_ARB_map_buffer_range

#if defined(GL_EXT_ARB_multi_bind)
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers);
#define glBindBuffersBase gll_glBindBuffersBase
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC)(GLenum target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes);
#define glBindBuffersRange gll_glBindBuffersRange
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindTextures gll_glBindTextures
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC)(GLuint first, GLsizei count, const GLuint * samplers);
#define glBindSamplers gll_glBindSamplers
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC)(GLuint first, GLsizei count, const GLuint * textures);
#define glBindImageTextures gll_glBindImageTextures
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC)(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides);
#define glBindVertexBuffers gll_glBindVertexBuffers
#endif // GL_EXT_ARB_multi_bind

#if defined(GL_EXT_ARB_multi_draw_indirect)
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawArraysIndirect gll_glMultiDrawArraysIndirect
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawElementsIndirect gll_glMultiDrawElementsIndirect
#endif // GL_EXT_ARB_multi_draw_indirect

#if defined(GL_EXT_ARB_occlusion_query2)
#endif // GL_EXT_ARB_occlusion_query2

#if defined(GL_EXT_ARB_parallel_shader_compile)
#define GL_MAX_SHADER_COMPILER_THREADS_ARB 0x91B0
#define GL_COMPLETION_STATUS_ARB 0x91B1
typedef void (APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSARBPROC)(GLuint count);
#define glMaxShaderCompilerThreadsARB gll_glMaxShaderCompilerThreadsARB
#endif // GL_EXT_ARB_parallel_shader_compile

#if defined(GL_EXT_ARB_pipeline_statistics_query)
#define GL_VERTICES_SUBMITTED_ARB 0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB 0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB 0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB 0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#endif // GL_EXT_ARB_pipeline_statistics_query

#if defined(GL_EXT_ARB_pixel_buffer_object)
#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF
#endif // GL_EXT_ARB_pixel_buffer_object

#if defined(GL_EXT_ARB_polygon_offset_clamp)
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPPROC)(GLfloat factor, GLfloat units, GLfloat clamp);
#define glPolygonOffsetClamp gll_glPolygonOffsetClamp
#endif // GL_EXT_ARB_polygon_offset_clamp

#if defined(GL_EXT_ARB_program_interface_query)
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint program, GLenum programInterface, GLenum pname, GLint * params);
#define glGetProgramInterfaceiv gll_glGetProgramInterfaceiv
typedef GLuint (APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceIndex gll_glGetProgramResourceIndex
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
#define glGetProgramResourceName gll_glGetProgramResourceName
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLint * params);
#define glGetProgramResourceiv gll_glGetProgramResourceiv
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocation gll_glGetProgramResourceLocation
typedef GLint (APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint program, GLenum programInterface, const GLchar * name);
#define glGetProgramResourceLocationIndex gll_glGetProgramResourceLocationIndex
#endif // GL_EXT_ARB_program_interface_query

#if defined(GL_EXT_ARB_provoking_vertex)
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC)(GLenum mode);
#define glProvokingVertex gll_glProvokingVertex
#endif // GL_EXT_ARB_provoking_vertex

#if defined(GL_EXT_ARB_query_buffer_object)
#endif // GL_EXT_ARB_query_buffer_object

#if defined(GL_EXT_ARB_robustness)
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB 0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB 0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB 0x8261
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC)(void);
#define glGetGraphicsResetStatusARB gll_glGetGraphicsResetStatusARB
typedef void (APIENTRYP PFNGLGETNTEXIMAGEARBPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * img);
#define glGetnTexImageARB gll_glGetnTexImageARB
typedef void (APIENTRYP PFNGLREADNPIXELSARBPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
#define glReadnPixelsARB gll_glReadnPixelsARB
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint lod, GLsizei bufSize, void * img);
#define glGetnCompressedTexImageARB gll_glGetnCompressedTexImageARB
typedef void (APIENTRYP PFNGLGETNUNIFORMFVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
#define glGetnUniformfvARB gll_glGetnUniformfvARB
typedef void (APIENTRYP PFNGLGETNUNIFORMIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLint * params);
#define glGetnUniformivARB gll_glGetnUniformivARB
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint * params);
#define glGetnUniformuivARB gll_glGetnUniformuivARB
typedef void (APIENTRYP PFNGLGETNUNIFORMDVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble * params);
#define glGetnUniformdvARB gll_glGetnUniformdvARB
typedef void (APIENTRYP PFNGLGETNMAPDVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v);
#define glGetnMapdvARB gll_glGetnMapdvARB
typedef void (APIENTRYP PFNGLGETNMAPFVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v);
#define glGetnMapfvARB gll_glGetnMapfvARB
typedef void (APIENTRYP PFNGLGETNMAPIVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint * v);
#define glGetnMapivARB gll_glGetnMapivARB
typedef void (APIENTRYP PFNGLGETNPIXELMAPFVARBPROC)(GLenum map, GLsizei bufSize, GLfloat * values);
#define glGetnPixelMapfvARB gll_glGetnPixelMapfvARB
typedef void (APIENTRYP PFNGLGETNPIXELMAPUIVARBPROC)(GLenum map, GLsizei bufSize, GLuint * values);
#define glGetnPixelMapuivARB gll_glGetnPixelMapuivARB
typedef void (APIENTRYP PFNGLGETNPIXELMAPUSVARBPROC)(GLenum map, GLsizei bufSize, GLushort * values);
#define glGetnPixelMapusvARB gll_glGetnPixelMapusvARB
typedef void (APIENTRYP PFNGLGETNPOLYGONSTIPPLEARBPROC)(GLsizei bufSize, GLubyte * pattern);
#define glGetnPolygonStippleARB gll_glGetnPolygonStippleARB
typedef void (APIENTRYP PFNGLGETNCOLORTABLEARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table);
#define glGetnColorTableARB gll_glGetnColorTableARB
typedef void (APIENTRYP PFNGLGETNCONVOLUTIONFILTERARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image);
#define glGetnConvolutionFilterARB gll_glGetnConvolutionFilterARB
typedef void (APIENTRYP PFNGLGETNSEPARABLEFILTERARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span);
#define glGetnSeparableFilterARB gll_glGetnSeparableFilterARB
typedef void (APIENTRYP PFNGLGETNHISTOGRAMARBPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
#define glGetnHistogramARB gll_glGetnHistogramARB
typedef void (APIENTRYP PFNGLGETNMINMAXARBPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
#define glGetnMinmaxARB gll_glGetnMinmaxARB
#endif // GL_EXT_ARB_robustness

#if defined(GL_EXT_ARB_sample_locations)
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_ARB 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_ARB 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_ARB 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_ARB 0x9340
#define GL_SAMPLE_LOCATION_ARB 0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_ARB 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_ARB 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_ARB 0x9343
typedef void (APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLenum target, GLuint start, GLsizei count, const GLfloat * v);
#define glFramebufferSampleLocationsfvARB gll_glFramebufferSampleLocationsfvARB
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat * v);
#define glNamedFramebufferSampleLocationsfvARB gll_glNamedFramebufferSampleLocationsfvARB
typedef void (APIENTRYP PFNGLEVALUATEDEPTHVALUESARBPROC)(void);
#define glEvaluateDepthValuesARB gll_glEvaluateDepthValuesARB
#endif // GL_EXT_ARB_sample_locations

#if defined(GL_EXT_ARB_sample_shading)
#define GL_SAMPLE_SHADING_ARB 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB 0x8C37
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGARBPROC)(GLfloat value);
#define glMinSampleShadingARB gll_glMinSampleShadingARB
#endif // GL_EXT_ARB_sample_shading

#if defined(GL_EXT_ARB_sampler_objects)
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint * samplers);
#define glGenSamplers gll_glGenSamplers
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint * samplers);
#define glDeleteSamplers gll_glDeleteSamplers
typedef GLboolean (APIENTRYP PFNGLISSAMPLERPROC)(GLuint sampler);
#define glIsSampler gll_glIsSampler
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
#define glBindSampler gll_glBindSampler
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
#define glSamplerParameteri gll_glSamplerParameteri
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameteriv gll_glSamplerParameteriv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
#define glSamplerParameterf gll_glSamplerParameterf
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat * param);
#define glSamplerParameterfv gll_glSamplerParameterfv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, const GLint * param);
#define glSamplerParameterIiv gll_glSamplerParameterIiv
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, const GLuint * param);
#define glSamplerParameterIuiv gll_glSamplerParameterIuiv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameteriv gll_glGetSamplerParameteriv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint sampler, GLenum pname, GLint * params);
#define glGetSamplerParameterIiv gll_glGetSamplerParameterIiv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat * params);
#define glGetSamplerParameterfv gll_glGetSamplerParameterfv
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint sampler, GLenum pname, GLuint * params);
#define glGetSamplerParameterIuiv gll_glGetSamplerParameterIuiv
#endif // GL_EXT_ARB_sampler_objects

#if defined(GL_EXT_ARB_seamless_cube_map)
#endif // GL_EXT_ARB_seamless_cube_map

#if defined(GL_EXT_ARB_seamless_cubemap_per_texture)
#endif // GL_EXT_ARB_seamless_cubemap_per_texture

#if defined(GL_EXT_ARB_separate_shader_objects)
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
#define glUseProgramStages gll_glUseProgramStages
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC)(GLuint pipeline, GLuint program);
#define glActiveShaderProgram gll_glActiveShaderProgram
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVPROC)(GLenum type, GLsizei count, const GLchar *const* strings);
#define glCreateShaderProgramv gll_glCreateShaderProgramv
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glBindProgramPipeline gll_glBindProgramPipeline
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei n, const GLuint * pipelines);
#define glDeleteProgramPipelines gll_glDeleteProgramPipelines
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC)(GLsizei n, GLuint * pipelines);
#define glGenProgramPipelines gll_glGenProgramPipelines
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glIsProgramPipeline gll_glIsProgramPipeline
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint pipeline, GLenum pname, GLint * params);
#define glGetProgramPipelineiv gll_glGetProgramPipelineiv
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
#define glProgramParameteri gll_glProgramParameteri
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC)(GLuint program, GLint location, GLint v0);
#define glProgramUniform1i gll_glProgramUniform1i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform1iv gll_glProgramUniform1iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC)(GLuint program, GLint location, GLfloat v0);
#define glProgramUniform1f gll_glProgramUniform1f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform1fv gll_glProgramUniform1fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC)(GLuint program, GLint location, GLdouble v0);
#define glProgramUniform1d gll_glProgramUniform1d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform1dv gll_glProgramUniform1dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC)(GLuint program, GLint location, GLuint v0);
#define glProgramUniform1ui gll_glProgramUniform1ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform1uiv gll_glProgramUniform1uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC)(GLuint program, GLint location, GLint v0, GLint v1);
#define glProgramUniform2i gll_glProgramUniform2i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform2iv gll_glProgramUniform2iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
#define glProgramUniform2f gll_glProgramUniform2f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform2fv gll_glProgramUniform2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
#define glProgramUniform2d gll_glProgramUniform2d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform2dv gll_glProgramUniform2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
#define glProgramUniform2ui gll_glProgramUniform2ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform2uiv gll_glProgramUniform2uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
#define glProgramUniform3i gll_glProgramUniform3i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform3iv gll_glProgramUniform3iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glProgramUniform3f gll_glProgramUniform3f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform3fv gll_glProgramUniform3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
#define glProgramUniform3d gll_glProgramUniform3d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform3dv gll_glProgramUniform3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glProgramUniform3ui gll_glProgramUniform3ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform3uiv gll_glProgramUniform3uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glProgramUniform4i gll_glProgramUniform4i
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform4iv gll_glProgramUniform4iv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glProgramUniform4f gll_glProgramUniform4f
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform4fv gll_glProgramUniform4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
#define glProgramUniform4d gll_glProgramUniform4d
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform4dv gll_glProgramUniform4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glProgramUniform4ui gll_glProgramUniform4ui
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform4uiv gll_glProgramUniform4uiv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2fv gll_glProgramUniformMatrix2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3fv gll_glProgramUniformMatrix3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4fv gll_glProgramUniformMatrix4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2dv gll_glProgramUniformMatrix2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3dv gll_glProgramUniformMatrix3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4dv gll_glProgramUniformMatrix4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x3fv gll_glProgramUniformMatrix2x3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x2fv gll_glProgramUniformMatrix3x2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x4fv gll_glProgramUniformMatrix2x4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x2fv gll_glProgramUniformMatrix4x2fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x4fv gll_glProgramUniformMatrix3x4fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x3fv gll_glProgramUniformMatrix4x3fv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x3dv gll_glProgramUniformMatrix2x3dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x2dv gll_glProgramUniformMatrix3x2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x4dv gll_glProgramUniformMatrix2x4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x2dv gll_glProgramUniformMatrix4x2dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x4dv gll_glProgramUniformMatrix3x4dv
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x3dv gll_glProgramUniformMatrix4x3dv
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint pipeline);
#define glValidateProgramPipeline gll_glValidateProgramPipeline
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetProgramPipelineInfoLog gll_glGetProgramPipelineInfoLog
#endif // GL_EXT_ARB_separate_shader_objects

#if defined(GL_EXT_ARB_shader_atomic_counters)
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params);
#define glGetActiveAtomicCounterBufferiv gll_glGetActiveAtomicCounterBufferiv
#endif // GL_EXT_ARB_shader_atomic_counters

#if defined(GL_EXT_ARB_shader_image_load_store)
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
#define glBindImageTexture gll_glBindImageTexture
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC)(GLbitfield barriers);
#define glMemoryBarrier gll_glMemoryBarrier
#endif // GL_EXT_ARB_shader_image_load_store

#if defined(GL_EXT_ARB_shader_storage_buffer_object)
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
#define glShaderStorageBlockBinding gll_glShaderStorageBlockBinding
#endif // GL_EXT_ARB_shader_storage_buffer_object

#if defined(GL_EXT_ARB_shader_subroutine)
typedef GLint (APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint program, GLenum shadertype, const GLchar * name);
#define glGetSubroutineUniformLocation gll_glGetSubroutineUniformLocation
typedef GLuint (APIENTRYP PFNGLGETSUBROUTINEINDEXPROC)(GLuint program, GLenum shadertype, const GLchar * name);
#define glGetSubroutineIndex gll_glGetSubroutineIndex
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values);
#define glGetActiveSubroutineUniformiv gll_glGetActiveSubroutineUniformiv
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineUniformName gll_glGetActiveSubroutineUniformName
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
#define glGetActiveSubroutineName gll_glGetActiveSubroutineName
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum shadertype, GLsizei count, const GLuint * indices);
#define glUniformSubroutinesuiv gll_glUniformSubroutinesuiv
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum shadertype, GLint location, GLuint * params);
#define glGetUniformSubroutineuiv gll_glGetUniformSubroutineuiv
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC)(GLuint program, GLenum shadertype, GLenum pname, GLint * values);
#define glGetProgramStageiv gll_glGetProgramStageiv
#endif // GL_EXT_ARB_shader_subroutine

#if defined(GL_EXT_ARB_shading_language_include)
#define GL_SHADER_INCLUDE_ARB 0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB 0x8DE9
#define GL_NAMED_STRING_TYPE_ARB 0x8DEA
typedef void (APIENTRYP PFNGLNAMEDSTRINGARBPROC)(GLenum type, GLint namelen, const GLchar * name, GLint stringlen, const GLchar * string);
#define glNamedStringARB gll_glNamedStringARB
typedef void (APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC)(GLint namelen, const GLchar * name);
#define glDeleteNamedStringARB gll_glDeleteNamedStringARB
typedef void (APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC)(GLuint shader, GLsizei count, const GLchar *const* path, const GLint * length);
#define glCompileShaderIncludeARB gll_glCompileShaderIncludeARB
typedef GLboolean (APIENTRYP PFNGLISNAMEDSTRINGARBPROC)(GLint namelen, const GLchar * name);
#define glIsNamedStringARB gll_glIsNamedStringARB
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGARBPROC)(GLint namelen, const GLchar * name, GLsizei bufSize, GLint * stringlen, GLchar * string);
#define glGetNamedStringARB gll_glGetNamedStringARB
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC)(GLint namelen, const GLchar * name, GLenum pname, GLint * params);
#define glGetNamedStringivARB gll_glGetNamedStringivARB
#endif // GL_EXT_ARB_shading_language_include

#if defined(GL_EXT_ARB_sparse_buffer)
#define GL_SPARSE_STORAGE_BIT_ARB 0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB 0x82F8
typedef void (APIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC)(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
#define glBufferPageCommitmentARB gll_glBufferPageCommitmentARB
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#define glNamedBufferPageCommitmentEXT gll_glNamedBufferPageCommitmentEXT
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#define glNamedBufferPageCommitmentARB gll_glNamedBufferPageCommitmentARB
#endif // GL_EXT_ARB_sparse_buffer

#if defined(GL_EXT_ARB_sparse_texture)
#define GL_TEXTURE_SPARSE_ARB 0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB 0x91A7
#define GL_NUM_SPARSE_LEVELS_ARB 0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB 0x91A8
#define GL_VIRTUAL_PAGE_SIZE_X_ARB 0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB 0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB 0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB 0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
typedef void (APIENTRYP PFNGLTEXPAGECOMMITMENTARBPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#define glTexPageCommitmentARB gll_glTexPageCommitmentARB
#endif // GL_EXT_ARB_sparse_texture

#if defined(GL_EXT_ARB_spirv_extensions)
#endif // GL_EXT_ARB_spirv_extensions

#if defined(GL_EXT_ARB_stencil_texturing)
#endif // GL_EXT_ARB_stencil_texturing

#if defined(GL_EXT_ARB_sync)
typedef GLsync (APIENTRYP PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
#define glFenceSync gll_glFenceSync
typedef GLboolean (APIENTRYP PFNGLISSYNCPROC)(GLsync sync);
#define glIsSync gll_glIsSync
typedef void (APIENTRYP PFNGLDELETESYNCPROC)(GLsync sync);
#define glDeleteSync gll_glDeleteSync
typedef GLenum (APIENTRYP PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glClientWaitSync gll_glClientWaitSync
typedef void (APIENTRYP PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
#define glWaitSync gll_glWaitSync
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64 * data);
#define glGetInteger64v gll_glGetInteger64v
typedef void (APIENTRYP PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values);
#define glGetSynciv gll_glGetSynciv
#endif // GL_EXT_ARB_sync

#if defined(GL_EXT_ARB_tessellation_shader)
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC)(GLenum pname, GLint value);
#define glPatchParameteri gll_glPatchParameteri
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC)(GLenum pname, const GLfloat * values);
#define glPatchParameterfv gll_glPatchParameterfv
#endif // GL_EXT_ARB_tessellation_shader

#if defined(GL_EXT_ARB_texture_barrier)
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC)(void);
#define glTextureBarrier gll_glTextureBarrier
#endif // GL_EXT_ARB_texture_barrier

#if defined(GL_EXT_ARB_texture_border_clamp)
#define GL_CLAMP_TO_BORDER_ARB 0x812D
#endif // GL_EXT_ARB_texture_border_clamp

#if defined(GL_EXT_ARB_texture_buffer_object)
#define GL_TEXTURE_BUFFER_ARB 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB 0x8C2E
typedef void (APIENTRYP PFNGLTEXBUFFERARBPROC)(GLenum target, GLenum internalformat, GLuint buffer);
#define glTexBufferARB gll_glTexBufferARB
#endif // GL_EXT_ARB_texture_buffer_object

#if defined(GL_EXT_ARB_texture_buffer_object_rgb32)
#endif // GL_EXT_ARB_texture_buffer_object_rgb32

#if defined(GL_EXT_ARB_texture_buffer_range)
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTexBufferRange gll_glTexBufferRange
#endif // GL_EXT_ARB_texture_buffer_range

#if defined(GL_EXT_ARB_texture_compression_bptc)
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#endif // GL_EXT_ARB_texture_compression_bptc

#if defined(GL_EXT_ARB_texture_compression_rgtc)
#endif // GL_EXT_ARB_texture_compression_rgtc

#if defined(GL_EXT_ARB_texture_cube_map_array)
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
#endif // GL_EXT_ARB_texture_cube_map_array

#if defined(GL_EXT_ARB_texture_filter_anisotropic)
#endif // GL_EXT_ARB_texture_filter_anisotropic

#if defined(GL_EXT_ARB_texture_filter_minmax)
#define GL_TEXTURE_REDUCTION_MODE_ARB 0x9366
#define GL_WEIGHTED_AVERAGE_ARB 0x9367
#endif // GL_EXT_ARB_texture_filter_minmax

#if defined(GL_EXT_ARB_texture_gather)
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#endif // GL_EXT_ARB_texture_gather

#if defined(GL_EXT_ARB_texture_mirror_clamp_to_edge)
#endif // GL_EXT_ARB_texture_mirror_clamp_to_edge

#if defined(GL_EXT_ARB_texture_mirrored_repeat)
#define GL_MIRRORED_REPEAT_ARB 0x8370
#endif // GL_EXT_ARB_texture_mirrored_repeat

#if defined(GL_EXT_ARB_texture_multisample)
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexImage2DMultisample gll_glTexImage2DMultisample
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexImage3DMultisample gll_glTexImage3DMultisample
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC)(GLenum pname, GLuint index, GLfloat * val);
#define glGetMultisamplefv gll_glGetMultisamplefv
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC)(GLuint maskNumber, GLbitfield mask);
#define glSampleMaski gll_glSampleMaski
#endif // GL_EXT_ARB_texture_multisample

#if defined(GL_EXT_ARB_texture_rg)
#endif // GL_EXT_ARB_texture_rg

#if defined(GL_EXT_ARB_texture_rgb10_a2ui)
#endif // GL_EXT_ARB_texture_rgb10_a2ui

#if defined(GL_EXT_ARB_texture_stencil8)
#endif // GL_EXT_ARB_texture_stencil8

#if defined(GL_EXT_ARB_texture_storage)
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTexStorage1D gll_glTexStorage1D
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTexStorage2D gll_glTexStorage2D
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTexStorage3D gll_glTexStorage3D
#endif // GL_EXT_ARB_texture_storage

#if defined(GL_EXT_ARB_texture_storage_multisample)
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTexStorage2DMultisample gll_glTexStorage2DMultisample
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTexStorage3DMultisample gll_glTexStorage3DMultisample
#endif // GL_EXT_ARB_texture_storage_multisample

#if defined(GL_EXT_ARB_texture_swizzle)
#endif // GL_EXT_ARB_texture_swizzle

#if defined(GL_EXT_ARB_texture_view)
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
#define glTextureView gll_glTextureView
#endif // GL_EXT_ARB_texture_view

#if defined(GL_EXT_ARB_timer_query)
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC)(GLuint id, GLenum target);
#define glQueryCounter gll_glQueryCounter
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC)(GLuint id, GLenum pname, GLint64 * params);
#define glGetQueryObjecti64v gll_glGetQueryObjecti64v
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC)(GLuint id, GLenum pname, GLuint64 * params);
#define glGetQueryObjectui64v gll_glGetQueryObjectui64v
#endif // GL_EXT_ARB_timer_query

#if defined(GL_EXT_ARB_transform_feedback2)
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
#define glBindTransformFeedback gll_glBindTransformFeedback
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint * ids);
#define glDeleteTransformFeedbacks gll_glDeleteTransformFeedbacks
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint * ids);
#define glGenTransformFeedbacks gll_glGenTransformFeedbacks
typedef GLboolean (APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
#define glIsTransformFeedback gll_glIsTransformFeedback
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);
#define glPauseTransformFeedback gll_glPauseTransformFeedback
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);
#define glResumeTransformFeedback gll_glResumeTransformFeedback
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum mode, GLuint id);
#define glDrawTransformFeedback gll_glDrawTransformFeedback
#endif // GL_EXT_ARB_transform_feedback2

#if defined(GL_EXT_ARB_transform_feedback3)
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum mode, GLuint id, GLuint stream);
#define glDrawTransformFeedbackStream gll_glDrawTransformFeedbackStream
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC)(GLenum target, GLuint index, GLuint id);
#define glBeginQueryIndexed gll_glBeginQueryIndexed
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC)(GLenum target, GLuint index);
#define glEndQueryIndexed gll_glEndQueryIndexed
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC)(GLenum target, GLuint index, GLenum pname, GLint * params);
#define glGetQueryIndexediv gll_glGetQueryIndexediv
#endif // GL_EXT_ARB_transform_feedback3

#if defined(GL_EXT_ARB_transform_feedback_instanced)
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum mode, GLuint id, GLsizei instancecount);
#define glDrawTransformFeedbackInstanced gll_glDrawTransformFeedbackInstanced
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#define glDrawTransformFeedbackStreamInstanced gll_glDrawTransformFeedbackStreamInstanced
#endif // GL_EXT_ARB_transform_feedback_instanced

#if defined(GL_EXT_ARB_transform_feedback_overflow_query)
#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED
#endif // GL_EXT_ARB_transform_feedback_overflow_query

#if defined(GL_EXT_ARB_uniform_buffer_object)
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices);
#define glGetUniformIndices gll_glGetUniformIndices
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
#define glGetActiveUniformsiv gll_glGetActiveUniformsiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
#define glGetActiveUniformName gll_glGetActiveUniformName
typedef GLuint (APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar * uniformBlockName);
#define glGetUniformBlockIndex gll_glGetUniformBlockIndex
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
#define glGetActiveUniformBlockiv gll_glGetActiveUniformBlockiv
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
#define glGetActiveUniformBlockName gll_glGetActiveUniformBlockName
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#define glUniformBlockBinding gll_glUniformBlockBinding
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glBindBufferRange gll_glBindBufferRange
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
#define glBindBufferBase gll_glBindBufferBase
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint * data);
#define glGetIntegeri_v gll_glGetIntegeri_v
#endif // GL_EXT_ARB_uniform_buffer_object

#if defined(GL_EXT_ARB_vertex_array_bgra)
#endif // GL_EXT_ARB_vertex_array_bgra

#if defined(GL_EXT_ARB_vertex_array_object)
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC)(GLuint array);
#define glBindVertexArray gll_glBindVertexArray
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint * arrays);
#define glDeleteVertexArrays gll_glDeleteVertexArrays
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint * arrays);
#define glGenVertexArrays gll_glGenVertexArrays
typedef GLboolean (APIENTRYP PFNGLISVERTEXARRAYPROC)(GLuint array);
#define glIsVertexArray gll_glIsVertexArray
#endif // GL_EXT_ARB_vertex_array_object

#if defined(GL_EXT_ARB_vertex_attrib_64bit)
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC)(GLuint index, GLdouble x);
#define glVertexAttribL1d gll_glVertexAttribL1d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC)(GLuint index, GLdouble x, GLdouble y);
#define glVertexAttribL2d gll_glVertexAttribL2d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
#define glVertexAttribL3d gll_glVertexAttribL3d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertexAttribL4d gll_glVertexAttribL4d
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL1dv gll_glVertexAttribL1dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL2dv gll_glVertexAttribL2dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL3dv gll_glVertexAttribL3dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC)(GLuint index, const GLdouble * v);
#define glVertexAttribL4dv gll_glVertexAttribL4dv
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glVertexAttribLPointer gll_glVertexAttribLPointer
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC)(GLuint index, GLenum pname, GLdouble * params);
#define glGetVertexAttribLdv gll_glGetVertexAttribLdv
#endif // GL_EXT_ARB_vertex_attrib_64bit

#if defined(GL_EXT_ARB_vertex_attrib_binding)
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glBindVertexBuffer gll_glBindVertexBuffer
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexAttribFormat gll_glVertexAttribFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribIFormat gll_glVertexAttribIFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexAttribLFormat gll_glVertexAttribLFormat
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC)(GLuint attribindex, GLuint bindingindex);
#define glVertexAttribBinding gll_glVertexAttribBinding
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC)(GLuint bindingindex, GLuint divisor);
#define glVertexBindingDivisor gll_glVertexBindingDivisor
#endif // GL_EXT_ARB_vertex_attrib_binding

#if defined(GL_EXT_ARB_vertex_type_10f_11f_11f_rev)
#endif // GL_EXT_ARB_vertex_type_10f_11f_11f_rev

#if defined(GL_EXT_ARB_vertex_type_2_10_10_10_rev)
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP1ui gll_glVertexAttribP1ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP1uiv gll_glVertexAttribP1uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP2ui gll_glVertexAttribP2ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP2uiv gll_glVertexAttribP2uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP3ui gll_glVertexAttribP3ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP3uiv gll_glVertexAttribP3uiv
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
#define glVertexAttribP4ui gll_glVertexAttribP4ui
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
#define glVertexAttribP4uiv gll_glVertexAttribP4uiv
typedef void (APIENTRYP PFNGLVERTEXP2UIPROC)(GLenum type, GLuint value);
#define glVertexP2ui gll_glVertexP2ui
typedef void (APIENTRYP PFNGLVERTEXP2UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP2uiv gll_glVertexP2uiv
typedef void (APIENTRYP PFNGLVERTEXP3UIPROC)(GLenum type, GLuint value);
#define glVertexP3ui gll_glVertexP3ui
typedef void (APIENTRYP PFNGLVERTEXP3UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP3uiv gll_glVertexP3uiv
typedef void (APIENTRYP PFNGLVERTEXP4UIPROC)(GLenum type, GLuint value);
#define glVertexP4ui gll_glVertexP4ui
typedef void (APIENTRYP PFNGLVERTEXP4UIVPROC)(GLenum type, const GLuint * value);
#define glVertexP4uiv gll_glVertexP4uiv
typedef void (APIENTRYP PFNGLTEXCOORDP1UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP1ui gll_glTexCoordP1ui
typedef void (APIENTRYP PFNGLTEXCOORDP1UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP1uiv gll_glTexCoordP1uiv
typedef void (APIENTRYP PFNGLTEXCOORDP2UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP2ui gll_glTexCoordP2ui
typedef void (APIENTRYP PFNGLTEXCOORDP2UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP2uiv gll_glTexCoordP2uiv
typedef void (APIENTRYP PFNGLTEXCOORDP3UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP3ui gll_glTexCoordP3ui
typedef void (APIENTRYP PFNGLTEXCOORDP3UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP3uiv gll_glTexCoordP3uiv
typedef void (APIENTRYP PFNGLTEXCOORDP4UIPROC)(GLenum type, GLuint coords);
#define glTexCoordP4ui gll_glTexCoordP4ui
typedef void (APIENTRYP PFNGLTEXCOORDP4UIVPROC)(GLenum type, const GLuint * coords);
#define glTexCoordP4uiv gll_glTexCoordP4uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP1ui gll_glMultiTexCoordP1ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP1UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP1uiv gll_glMultiTexCoordP1uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP2ui gll_glMultiTexCoordP2ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP2UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP2uiv gll_glMultiTexCoordP2uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP3ui gll_glMultiTexCoordP3ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP3UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP3uiv gll_glMultiTexCoordP3uiv
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIPROC)(GLenum texture, GLenum type, GLuint coords);
#define glMultiTexCoordP4ui gll_glMultiTexCoordP4ui
typedef void (APIENTRYP PFNGLMULTITEXCOORDP4UIVPROC)(GLenum texture, GLenum type, const GLuint * coords);
#define glMultiTexCoordP4uiv gll_glMultiTexCoordP4uiv
typedef void (APIENTRYP PFNGLNORMALP3UIPROC)(GLenum type, GLuint coords);
#define glNormalP3ui gll_glNormalP3ui
typedef void (APIENTRYP PFNGLNORMALP3UIVPROC)(GLenum type, const GLuint * coords);
#define glNormalP3uiv gll_glNormalP3uiv
typedef void (APIENTRYP PFNGLCOLORP3UIPROC)(GLenum type, GLuint color);
#define glColorP3ui gll_glColorP3ui
typedef void (APIENTRYP PFNGLCOLORP3UIVPROC)(GLenum type, const GLuint * color);
#define glColorP3uiv gll_glColorP3uiv
typedef void (APIENTRYP PFNGLCOLORP4UIPROC)(GLenum type, GLuint color);
#define glColorP4ui gll_glColorP4ui
typedef void (APIENTRYP PFNGLCOLORP4UIVPROC)(GLenum type, const GLuint * color);
#define glColorP4uiv gll_glColorP4uiv
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIPROC)(GLenum type, GLuint color);
#define glSecondaryColorP3ui gll_glSecondaryColorP3ui
typedef void (APIENTRYP PFNGLSECONDARYCOLORP3UIVPROC)(GLenum type, const GLuint * color);
#define glSecondaryColorP3uiv gll_glSecondaryColorP3uiv
#endif // GL_EXT_ARB_vertex_type_2_10_10_10_rev

#if defined(GL_EXT_ARB_viewport_array)
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC)(GLuint first, GLsizei count, const GLfloat * v);
#define glViewportArrayv gll_glViewportArrayv
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
#define glViewportIndexedf gll_glViewportIndexedf
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC)(GLuint index, const GLfloat * v);
#define glViewportIndexedfv gll_glViewportIndexedfv
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC)(GLuint first, GLsizei count, const GLint * v);
#define glScissorArrayv gll_glScissorArrayv
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
#define glScissorIndexed gll_glScissorIndexed
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC)(GLuint index, const GLint * v);
#define glScissorIndexedv gll_glScissorIndexedv
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC)(GLuint first, GLsizei count, const GLdouble * v);
#define glDepthRangeArrayv gll_glDepthRangeArrayv
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC)(GLuint index, GLdouble n, GLdouble f);
#define glDepthRangeIndexed gll_glDepthRangeIndexed
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC)(GLenum target, GLuint index, GLfloat * data);
#define glGetFloati_v gll_glGetFloati_v
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC)(GLenum target, GLuint index, GLdouble * data);
#define glGetDoublei_v gll_glGetDoublei_v
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYDVNVPROC)(GLuint first, GLsizei count, const GLdouble * v);
#define glDepthRangeArraydvNV gll_glDepthRangeArraydvNV
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDDNVPROC)(GLuint index, GLdouble n, GLdouble f);
#define glDepthRangeIndexeddNV gll_glDepthRangeIndexeddNV
#endif // GL_EXT_ARB_viewport_array

#if defined(GL_EXT_EXT_EGL_image_storage)
typedef void *GLeglImageOES;
typedef void (APIENTRYP PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC)(GLenum target, GLeglImageOES image, const GLint * attrib_list);
#define glEGLImageTargetTexStorageEXT gll_glEGLImageTargetTexStorageEXT
typedef void (APIENTRYP PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC)(GLuint texture, GLeglImageOES image, const GLint * attrib_list);
#define glEGLImageTargetTextureStorageEXT gll_glEGLImageTargetTextureStorageEXT
#endif // GL_EXT_EXT_EGL_image_storage

#if defined(GL_EXT_EXT_debug_label)
#define GL_PROGRAM_PIPELINE_OBJECT_EXT 0x8A4F
#define GL_PROGRAM_OBJECT_EXT 0x8B40
#define GL_SHADER_OBJECT_EXT 0x8B48
#define GL_BUFFER_OBJECT_EXT 0x9151
#define GL_QUERY_OBJECT_EXT 0x9153
#define GL_VERTEX_ARRAY_OBJECT_EXT 0x9154
typedef void (APIENTRYP PFNGLLABELOBJECTEXTPROC)(GLenum type, GLuint object, GLsizei length, const GLchar * label);
#define glLabelObjectEXT gll_glLabelObjectEXT
typedef void (APIENTRYP PFNGLGETOBJECTLABELEXTPROC)(GLenum type, GLuint object, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectLabelEXT gll_glGetObjectLabelEXT
#endif // GL_EXT_EXT_debug_label

#if defined(GL_EXT_EXT_debug_marker)
typedef void (APIENTRYP PFNGLINSERTEVENTMARKEREXTPROC)(GLsizei length, const GLchar * marker);
#define glInsertEventMarkerEXT gll_glInsertEventMarkerEXT
typedef void (APIENTRYP PFNGLPUSHGROUPMARKEREXTPROC)(GLsizei length, const GLchar * marker);
#define glPushGroupMarkerEXT gll_glPushGroupMarkerEXT
typedef void (APIENTRYP PFNGLPOPGROUPMARKEREXTPROC)(void);
#define glPopGroupMarkerEXT gll_glPopGroupMarkerEXT
#endif // GL_EXT_EXT_debug_marker

#if defined(GL_EXT_EXT_direct_state_access)
#define GL_PROGRAM_MATRIX_EXT 0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT 0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F
typedef void (APIENTRYP PFNGLMATRIXLOADFEXTPROC)(GLenum mode, const GLfloat * m);
#define glMatrixLoadfEXT gll_glMatrixLoadfEXT
typedef void (APIENTRYP PFNGLMATRIXLOADDEXTPROC)(GLenum mode, const GLdouble * m);
#define glMatrixLoaddEXT gll_glMatrixLoaddEXT
typedef void (APIENTRYP PFNGLMATRIXMULTFEXTPROC)(GLenum mode, const GLfloat * m);
#define glMatrixMultfEXT gll_glMatrixMultfEXT
typedef void (APIENTRYP PFNGLMATRIXMULTDEXTPROC)(GLenum mode, const GLdouble * m);
#define glMatrixMultdEXT gll_glMatrixMultdEXT
typedef void (APIENTRYP PFNGLMATRIXLOADIDENTITYEXTPROC)(GLenum mode);
#define glMatrixLoadIdentityEXT gll_glMatrixLoadIdentityEXT
typedef void (APIENTRYP PFNGLMATRIXROTATEFEXTPROC)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
#define glMatrixRotatefEXT gll_glMatrixRotatefEXT
typedef void (APIENTRYP PFNGLMATRIXROTATEDEXTPROC)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
#define glMatrixRotatedEXT gll_glMatrixRotatedEXT
typedef void (APIENTRYP PFNGLMATRIXSCALEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
#define glMatrixScalefEXT gll_glMatrixScalefEXT
typedef void (APIENTRYP PFNGLMATRIXSCALEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
#define glMatrixScaledEXT gll_glMatrixScaledEXT
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
#define glMatrixTranslatefEXT gll_glMatrixTranslatefEXT
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
#define glMatrixTranslatedEXT gll_glMatrixTranslatedEXT
typedef void (APIENTRYP PFNGLMATRIXFRUSTUMEXTPROC)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glMatrixFrustumEXT gll_glMatrixFrustumEXT
typedef void (APIENTRYP PFNGLMATRIXORTHOEXTPROC)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glMatrixOrthoEXT gll_glMatrixOrthoEXT
typedef void (APIENTRYP PFNGLMATRIXPOPEXTPROC)(GLenum mode);
#define glMatrixPopEXT gll_glMatrixPopEXT
typedef void (APIENTRYP PFNGLMATRIXPUSHEXTPROC)(GLenum mode);
#define glMatrixPushEXT gll_glMatrixPushEXT
typedef void (APIENTRYP PFNGLCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield mask);
#define glClientAttribDefaultEXT gll_glClientAttribDefaultEXT
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield mask);
#define glPushClientAttribDefaultEXT gll_glPushClientAttribDefaultEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLfloat param);
#define glTextureParameterfEXT gll_glTextureParameterfEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLfloat * params);
#define glTextureParameterfvEXT gll_glTextureParameterfvEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint param);
#define glTextureParameteriEXT gll_glTextureParameteriEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLint * params);
#define glTextureParameterivEXT gll_glTextureParameterivEXT
typedef void (APIENTRYP PFNGLTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTextureImage1DEXT gll_glTextureImage1DEXT
typedef void (APIENTRYP PFNGLTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTextureImage2DEXT gll_glTextureImage2DEXT
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage1DEXT gll_glTextureSubImage1DEXT
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage2DEXT gll_glTextureSubImage2DEXT
typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyTextureImage1DEXT gll_glCopyTextureImage1DEXT
typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyTextureImage2DEXT gll_glCopyTextureImage2DEXT
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTextureSubImage1DEXT gll_glCopyTextureSubImage1DEXT
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage2DEXT gll_glCopyTextureSubImage2DEXT
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
#define glGetTextureImageEXT gll_glGetTextureImageEXT
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLfloat * params);
#define glGetTextureParameterfvEXT gll_glGetTextureParameterfvEXT
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint * params);
#define glGetTextureParameterivEXT gll_glGetTextureParameterivEXT
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat * params);
#define glGetTextureLevelParameterfvEXT gll_glGetTextureLevelParameterfvEXT
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum pname, GLint * params);
#define glGetTextureLevelParameterivEXT gll_glGetTextureLevelParameterivEXT
typedef void (APIENTRYP PFNGLTEXTUREIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
#define glTextureImage3DEXT gll_glTextureImage3DEXT
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glTextureSubImage3DEXT gll_glTextureSubImage3DEXT
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTextureSubImage3DEXT gll_glCopyTextureSubImage3DEXT
typedef void (APIENTRYP PFNGLBINDMULTITEXTUREEXTPROC)(GLenum texunit, GLenum target, GLuint texture);
#define glBindMultiTextureEXT gll_glBindMultiTextureEXT
typedef void (APIENTRYP PFNGLMULTITEXCOORDPOINTEREXTPROC)(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void * pointer);
#define glMultiTexCoordPointerEXT gll_glMultiTexCoordPointerEXT
typedef void (APIENTRYP PFNGLMULTITEXENVFEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
#define glMultiTexEnvfEXT gll_glMultiTexEnvfEXT
typedef void (APIENTRYP PFNGLMULTITEXENVFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLfloat * params);
#define glMultiTexEnvfvEXT gll_glMultiTexEnvfvEXT
typedef void (APIENTRYP PFNGLMULTITEXENVIEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint param);
#define glMultiTexEnviEXT gll_glMultiTexEnviEXT
typedef void (APIENTRYP PFNGLMULTITEXENVIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint * params);
#define glMultiTexEnvivEXT gll_glMultiTexEnvivEXT
typedef void (APIENTRYP PFNGLMULTITEXGENDEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
#define glMultiTexGendEXT gll_glMultiTexGendEXT
typedef void (APIENTRYP PFNGLMULTITEXGENDVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLdouble * params);
#define glMultiTexGendvEXT gll_glMultiTexGendvEXT
typedef void (APIENTRYP PFNGLMULTITEXGENFEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
#define glMultiTexGenfEXT gll_glMultiTexGenfEXT
typedef void (APIENTRYP PFNGLMULTITEXGENFVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLfloat * params);
#define glMultiTexGenfvEXT gll_glMultiTexGenfvEXT
typedef void (APIENTRYP PFNGLMULTITEXGENIEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLint param);
#define glMultiTexGeniEXT gll_glMultiTexGeniEXT
typedef void (APIENTRYP PFNGLMULTITEXGENIVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, const GLint * params);
#define glMultiTexGenivEXT gll_glMultiTexGenivEXT
typedef void (APIENTRYP PFNGLGETMULTITEXENVFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat * params);
#define glGetMultiTexEnvfvEXT gll_glGetMultiTexEnvfvEXT
typedef void (APIENTRYP PFNGLGETMULTITEXENVIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint * params);
#define glGetMultiTexEnvivEXT gll_glGetMultiTexEnvivEXT
typedef void (APIENTRYP PFNGLGETMULTITEXGENDVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLdouble * params);
#define glGetMultiTexGendvEXT gll_glGetMultiTexGendvEXT
typedef void (APIENTRYP PFNGLGETMULTITEXGENFVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLfloat * params);
#define glGetMultiTexGenfvEXT gll_glGetMultiTexGenfvEXT
typedef void (APIENTRYP PFNGLGETMULTITEXGENIVEXTPROC)(GLenum texunit, GLenum coord, GLenum pname, GLint * params);
#define glGetMultiTexGenivEXT gll_glGetMultiTexGenivEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint param);
#define glMultiTexParameteriEXT gll_glMultiTexParameteriEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint * params);
#define glMultiTexParameterivEXT gll_glMultiTexParameterivEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
#define glMultiTexParameterfEXT gll_glMultiTexParameterfEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLfloat * params);
#define glMultiTexParameterfvEXT gll_glMultiTexParameterfvEXT
typedef void (APIENTRYP PFNGLMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
#define glMultiTexImage1DEXT gll_glMultiTexImage1DEXT
typedef void (APIENTRYP PFNGLMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
#define glMultiTexImage2DEXT gll_glMultiTexImage2DEXT
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
#define glMultiTexSubImage1DEXT gll_glMultiTexSubImage1DEXT
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
#define glMultiTexSubImage2DEXT gll_glMultiTexSubImage2DEXT
typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyMultiTexImage1DEXT gll_glCopyMultiTexImage1DEXT
typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyMultiTexImage2DEXT gll_glCopyMultiTexImage2DEXT
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyMultiTexSubImage1DEXT gll_glCopyMultiTexSubImage1DEXT
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyMultiTexSubImage2DEXT gll_glCopyMultiTexSubImage2DEXT
typedef void (APIENTRYP PFNGLGETMULTITEXIMAGEEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
#define glGetMultiTexImageEXT gll_glGetMultiTexImageEXT
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLfloat * params);
#define glGetMultiTexParameterfvEXT gll_glGetMultiTexParameterfvEXT
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint * params);
#define glGetMultiTexParameterivEXT gll_glGetMultiTexParameterivEXT
typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat * params);
#define glGetMultiTexLevelParameterfvEXT gll_glGetMultiTexLevelParameterfvEXT
typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint * params);
#define glGetMultiTexLevelParameterivEXT gll_glGetMultiTexLevelParameterivEXT
typedef void (APIENTRYP PFNGLMULTITEXIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
#define glMultiTexImage3DEXT gll_glMultiTexImage3DEXT
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
#define glMultiTexSubImage3DEXT gll_glMultiTexSubImage3DEXT
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyMultiTexSubImage3DEXT gll_glCopyMultiTexSubImage3DEXT
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)(GLenum array, GLuint index);
#define glEnableClientStateIndexedEXT gll_glEnableClientStateIndexedEXT
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)(GLenum array, GLuint index);
#define glDisableClientStateIndexedEXT gll_glDisableClientStateIndexedEXT
typedef void (APIENTRYP PFNGLGETFLOATINDEXEDVEXTPROC)(GLenum target, GLuint index, GLfloat * data);
#define glGetFloatIndexedvEXT gll_glGetFloatIndexedvEXT
typedef void (APIENTRYP PFNGLGETDOUBLEINDEXEDVEXTPROC)(GLenum target, GLuint index, GLdouble * data);
#define glGetDoubleIndexedvEXT gll_glGetDoubleIndexedvEXT
typedef void (APIENTRYP PFNGLGETPOINTERINDEXEDVEXTPROC)(GLenum target, GLuint index, void ** data);
#define glGetPointerIndexedvEXT gll_glGetPointerIndexedvEXT
typedef void (APIENTRYP PFNGLENABLEINDEXEDEXTPROC)(GLenum target, GLuint index);
#define glEnableIndexedEXT gll_glEnableIndexedEXT
typedef void (APIENTRYP PFNGLDISABLEINDEXEDEXTPROC)(GLenum target, GLuint index);
#define glDisableIndexedEXT gll_glDisableIndexedEXT
typedef GLboolean (APIENTRYP PFNGLISENABLEDINDEXEDEXTPROC)(GLenum target, GLuint index);
#define glIsEnabledIndexedEXT gll_glIsEnabledIndexedEXT
typedef void (APIENTRYP PFNGLGETINTEGERINDEXEDVEXTPROC)(GLenum target, GLuint index, GLint * data);
#define glGetIntegerIndexedvEXT gll_glGetIntegerIndexedvEXT
typedef void (APIENTRYP PFNGLGETBOOLEANINDEXEDVEXTPROC)(GLenum target, GLuint index, GLboolean * data);
#define glGetBooleanIndexedvEXT gll_glGetBooleanIndexedvEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedTextureImage3DEXT gll_glCompressedTextureImage3DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedTextureImage2DEXT gll_glCompressedTextureImage2DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedTextureImage1DEXT gll_glCompressedTextureImage1DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedTextureSubImage3DEXT gll_glCompressedTextureSubImage3DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedTextureSubImage2DEXT gll_glCompressedTextureSubImage2DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedTextureSubImage1DEXT gll_glCompressedTextureSubImage1DEXT
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)(GLuint texture, GLenum target, GLint lod, void * img);
#define glGetCompressedTextureImageEXT gll_glGetCompressedTextureImageEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexImage3DEXT gll_glCompressedMultiTexImage3DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexImage2DEXT gll_glCompressedMultiTexImage2DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexImage1DEXT gll_glCompressedMultiTexImage1DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexSubImage3DEXT gll_glCompressedMultiTexSubImage3DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexSubImage2DEXT gll_glCompressedMultiTexSubImage2DEXT
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * bits);
#define glCompressedMultiTexSubImage1DEXT gll_glCompressedMultiTexSubImage1DEXT
typedef void (APIENTRYP PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)(GLenum texunit, GLenum target, GLint lod, void * img);
#define glGetCompressedMultiTexImageEXT gll_glGetCompressedMultiTexImageEXT
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat * m);
#define glMatrixLoadTransposefEXT gll_glMatrixLoadTransposefEXT
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble * m);
#define glMatrixLoadTransposedEXT gll_glMatrixLoadTransposedEXT
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat * m);
#define glMatrixMultTransposefEXT gll_glMatrixMultTransposefEXT
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble * m);
#define glMatrixMultTransposedEXT gll_glMatrixMultTransposedEXT
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAEXTPROC)(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
#define glNamedBufferDataEXT gll_glNamedBufferDataEXT
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
#define glNamedBufferSubDataEXT gll_glNamedBufferSubDataEXT
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFEREXTPROC)(GLuint buffer, GLenum access);
#define glMapNamedBufferEXT gll_glMapNamedBufferEXT
typedef GLboolean (APIENTRYP PFNGLUNMAPNAMEDBUFFEREXTPROC)(GLuint buffer);
#define glUnmapNamedBufferEXT gll_glUnmapNamedBufferEXT
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)(GLuint buffer, GLenum pname, GLint * params);
#define glGetNamedBufferParameterivEXT gll_glGetNamedBufferParameterivEXT
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)(GLuint buffer, GLenum pname, void ** params);
#define glGetNamedBufferPointervEXT gll_glGetNamedBufferPointervEXT
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
#define glGetNamedBufferSubDataEXT gll_glGetNamedBufferSubDataEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FEXTPROC)(GLuint program, GLint location, GLfloat v0);
#define glProgramUniform1fEXT gll_glProgramUniform1fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
#define glProgramUniform2fEXT gll_glProgramUniform2fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glProgramUniform3fEXT gll_glProgramUniform3fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glProgramUniform4fEXT gll_glProgramUniform4fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IEXTPROC)(GLuint program, GLint location, GLint v0);
#define glProgramUniform1iEXT gll_glProgramUniform1iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1);
#define glProgramUniform2iEXT gll_glProgramUniform2iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
#define glProgramUniform3iEXT gll_glProgramUniform3iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glProgramUniform4iEXT gll_glProgramUniform4iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform1fvEXT gll_glProgramUniform1fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform2fvEXT gll_glProgramUniform2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform3fvEXT gll_glProgramUniform3fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform4fvEXT gll_glProgramUniform4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform1ivEXT gll_glProgramUniform1ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform2ivEXT gll_glProgramUniform2ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform3ivEXT gll_glProgramUniform3ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform4ivEXT gll_glProgramUniform4ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2fvEXT gll_glProgramUniformMatrix2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3fvEXT gll_glProgramUniformMatrix3fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4fvEXT gll_glProgramUniformMatrix4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x3fvEXT gll_glProgramUniformMatrix2x3fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x2fvEXT gll_glProgramUniformMatrix3x2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x4fvEXT gll_glProgramUniformMatrix2x4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x2fvEXT gll_glProgramUniformMatrix4x2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x4fvEXT gll_glProgramUniformMatrix3x4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x3fvEXT gll_glProgramUniformMatrix4x3fvEXT
typedef void (APIENTRYP PFNGLTEXTUREBUFFEREXTPROC)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
#define glTextureBufferEXT gll_glTextureBufferEXT
typedef void (APIENTRYP PFNGLMULTITEXBUFFEREXTPROC)(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
#define glMultiTexBufferEXT gll_glMultiTexBufferEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLint * params);
#define glTextureParameterIivEXT gll_glTextureParameterIivEXT
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, const GLuint * params);
#define glTextureParameterIuivEXT gll_glTextureParameterIuivEXT
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLint * params);
#define glGetTextureParameterIivEXT gll_glGetTextureParameterIivEXT
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)(GLuint texture, GLenum target, GLenum pname, GLuint * params);
#define glGetTextureParameterIuivEXT gll_glGetTextureParameterIuivEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLint * params);
#define glMultiTexParameterIivEXT gll_glMultiTexParameterIivEXT
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIUIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, const GLuint * params);
#define glMultiTexParameterIuivEXT gll_glMultiTexParameterIuivEXT
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLint * params);
#define glGetMultiTexParameterIivEXT gll_glGetMultiTexParameterIivEXT
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)(GLenum texunit, GLenum target, GLenum pname, GLuint * params);
#define glGetMultiTexParameterIuivEXT gll_glGetMultiTexParameterIuivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIEXTPROC)(GLuint program, GLint location, GLuint v0);
#define glProgramUniform1uiEXT gll_glProgramUniform1uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
#define glProgramUniform2uiEXT gll_glProgramUniform2uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glProgramUniform3uiEXT gll_glProgramUniform3uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glProgramUniform4uiEXT gll_glProgramUniform4uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform1uivEXT gll_glProgramUniform1uivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform2uivEXT gll_glProgramUniform2uivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform3uivEXT gll_glProgramUniform3uivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform4uivEXT gll_glProgramUniform4uivEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat * params);
#define glNamedProgramLocalParameters4fvEXT gll_glNamedProgramLocalParameters4fvEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
#define glNamedProgramLocalParameterI4iEXT gll_glNamedProgramLocalParameterI4iEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLint * params);
#define glNamedProgramLocalParameterI4ivEXT gll_glNamedProgramLocalParameterI4ivEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint * params);
#define glNamedProgramLocalParametersI4ivEXT gll_glNamedProgramLocalParametersI4ivEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
#define glNamedProgramLocalParameterI4uiEXT gll_glNamedProgramLocalParameterI4uiEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLuint * params);
#define glNamedProgramLocalParameterI4uivEXT gll_glNamedProgramLocalParameterI4uivEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint * params);
#define glNamedProgramLocalParametersI4uivEXT gll_glNamedProgramLocalParametersI4uivEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLint * params);
#define glGetNamedProgramLocalParameterIivEXT gll_glGetNamedProgramLocalParameterIivEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)(GLuint program, GLenum target, GLuint index, GLuint * params);
#define glGetNamedProgramLocalParameterIuivEXT gll_glGetNamedProgramLocalParameterIuivEXT
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEIEXTPROC)(GLenum array, GLuint index);
#define glEnableClientStateiEXT gll_glEnableClientStateiEXT
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEIEXTPROC)(GLenum array, GLuint index);
#define glDisableClientStateiEXT gll_glDisableClientStateiEXT
typedef void (APIENTRYP PFNGLGETFLOATI_VEXTPROC)(GLenum pname, GLuint index, GLfloat * params);
#define glGetFloati_vEXT gll_glGetFloati_vEXT
typedef void (APIENTRYP PFNGLGETDOUBLEI_VEXTPROC)(GLenum pname, GLuint index, GLdouble * params);
#define glGetDoublei_vEXT gll_glGetDoublei_vEXT
typedef void (APIENTRYP PFNGLGETPOINTERI_VEXTPROC)(GLenum pname, GLuint index, void ** params);
#define glGetPointeri_vEXT gll_glGetPointeri_vEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMSTRINGEXTPROC)(GLuint program, GLenum target, GLenum format, GLsizei len, const void * string);
#define glNamedProgramStringEXT gll_glNamedProgramStringEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glNamedProgramLocalParameter4dEXT gll_glNamedProgramLocalParameter4dEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLdouble * params);
#define glNamedProgramLocalParameter4dvEXT gll_glNamedProgramLocalParameter4dvEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glNamedProgramLocalParameter4fEXT gll_glNamedProgramLocalParameter4fEXT
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)(GLuint program, GLenum target, GLuint index, const GLfloat * params);
#define glNamedProgramLocalParameter4fvEXT gll_glNamedProgramLocalParameter4fvEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)(GLuint program, GLenum target, GLuint index, GLdouble * params);
#define glGetNamedProgramLocalParameterdvEXT gll_glGetNamedProgramLocalParameterdvEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)(GLuint program, GLenum target, GLuint index, GLfloat * params);
#define glGetNamedProgramLocalParameterfvEXT gll_glGetNamedProgramLocalParameterfvEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMIVEXTPROC)(GLuint program, GLenum target, GLenum pname, GLint * params);
#define glGetNamedProgramivEXT gll_glGetNamedProgramivEXT
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)(GLuint program, GLenum target, GLenum pname, void * string);
#define glGetNamedProgramStringEXT gll_glGetNamedProgramStringEXT
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageEXT gll_glNamedRenderbufferStorageEXT
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)(GLuint renderbuffer, GLenum pname, GLint * params);
#define glGetNamedRenderbufferParameterivEXT gll_glGetNamedRenderbufferParameterivEXT
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisampleEXT gll_glNamedRenderbufferStorageMultisampleEXT
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#define glNamedRenderbufferStorageMultisampleCoverageEXT gll_glNamedRenderbufferStorageMultisampleCoverageEXT
typedef GLenum (APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)(GLuint framebuffer, GLenum target);
#define glCheckNamedFramebufferStatusEXT gll_glCheckNamedFramebufferStatusEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glNamedFramebufferTexture1DEXT gll_glNamedFramebufferTexture1DEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#define glNamedFramebufferTexture2DEXT gll_glNamedFramebufferTexture2DEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
#define glNamedFramebufferTexture3DEXT gll_glNamedFramebufferTexture3DEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#define glNamedFramebufferRenderbufferEXT gll_glNamedFramebufferRenderbufferEXT
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
#define glGetNamedFramebufferAttachmentParameterivEXT gll_glGetNamedFramebufferAttachmentParameterivEXT
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPEXTPROC)(GLuint texture, GLenum target);
#define glGenerateTextureMipmapEXT gll_glGenerateTextureMipmapEXT
typedef void (APIENTRYP PFNGLGENERATEMULTITEXMIPMAPEXTPROC)(GLenum texunit, GLenum target);
#define glGenerateMultiTexMipmapEXT gll_glGenerateMultiTexMipmapEXT
typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)(GLuint framebuffer, GLenum mode);
#define glFramebufferDrawBufferEXT gll_glFramebufferDrawBufferEXT
typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)(GLuint framebuffer, GLsizei n, const GLenum * bufs);
#define glFramebufferDrawBuffersEXT gll_glFramebufferDrawBuffersEXT
typedef void (APIENTRYP PFNGLFRAMEBUFFERREADBUFFEREXTPROC)(GLuint framebuffer, GLenum mode);
#define glFramebufferReadBufferEXT gll_glFramebufferReadBufferEXT
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum pname, GLint * params);
#define glGetFramebufferParameterivEXT gll_glGetFramebufferParameterivEXT
typedef void (APIENTRYP PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
#define glNamedCopyBufferSubDataEXT gll_glNamedCopyBufferSubDataEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
#define glNamedFramebufferTextureEXT gll_glNamedFramebufferTextureEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glNamedFramebufferTextureLayerEXT gll_glNamedFramebufferTextureLayerEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
#define glNamedFramebufferTextureFaceEXT gll_glNamedFramebufferTextureFaceEXT
typedef void (APIENTRYP PFNGLTEXTURERENDERBUFFEREXTPROC)(GLuint texture, GLenum target, GLuint renderbuffer);
#define glTextureRenderbufferEXT gll_glTextureRenderbufferEXT
typedef void (APIENTRYP PFNGLMULTITEXRENDERBUFFEREXTPROC)(GLenum texunit, GLenum target, GLuint renderbuffer);
#define glMultiTexRenderbufferEXT gll_glMultiTexRenderbufferEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayVertexOffsetEXT gll_glVertexArrayVertexOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYCOLOROFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayColorOffsetEXT gll_glVertexArrayColorOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
#define glVertexArrayEdgeFlagOffsetEXT gll_glVertexArrayEdgeFlagOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYINDEXOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayIndexOffsetEXT gll_glVertexArrayIndexOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYNORMALOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayNormalOffsetEXT gll_glVertexArrayNormalOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayTexCoordOffsetEXT gll_glVertexArrayTexCoordOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayMultiTexCoordOffsetEXT gll_glVertexArrayMultiTexCoordOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayFogCoordOffsetEXT gll_glVertexArrayFogCoordOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArraySecondaryColorOffsetEXT gll_glVertexArraySecondaryColorOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
#define glVertexArrayVertexAttribOffsetEXT gll_glVertexArrayVertexAttribOffsetEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayVertexAttribIOffsetEXT gll_glVertexArrayVertexAttribIOffsetEXT
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYEXTPROC)(GLuint vaobj, GLenum array);
#define glEnableVertexArrayEXT gll_glEnableVertexArrayEXT
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYEXTPROC)(GLuint vaobj, GLenum array);
#define glDisableVertexArrayEXT gll_glDisableVertexArrayEXT
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)(GLuint vaobj, GLuint index);
#define glEnableVertexArrayAttribEXT gll_glEnableVertexArrayAttribEXT
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)(GLuint vaobj, GLuint index);
#define glDisableVertexArrayAttribEXT gll_glDisableVertexArrayAttribEXT
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERVEXTPROC)(GLuint vaobj, GLenum pname, GLint * param);
#define glGetVertexArrayIntegervEXT gll_glGetVertexArrayIntegervEXT
typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERVEXTPROC)(GLuint vaobj, GLenum pname, void ** param);
#define glGetVertexArrayPointervEXT gll_glGetVertexArrayPointervEXT
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)(GLuint vaobj, GLuint index, GLenum pname, GLint * param);
#define glGetVertexArrayIntegeri_vEXT gll_glGetVertexArrayIntegeri_vEXT
typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)(GLuint vaobj, GLuint index, GLenum pname, void ** param);
#define glGetVertexArrayPointeri_vEXT gll_glGetVertexArrayPointeri_vEXT
typedef void * (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
#define glMapNamedBufferRangeEXT gll_glMapNamedBufferRangeEXT
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr length);
#define glFlushMappedNamedBufferRangeEXT gll_glFlushMappedNamedBufferRangeEXT
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEEXTPROC)(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
#define glNamedBufferStorageEXT gll_glNamedBufferStorageEXT
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAEXTPROC)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferDataEXT gll_glClearNamedBufferDataEXT
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)(GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
#define glClearNamedBufferSubDataEXT gll_glClearNamedBufferSubDataEXT
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)(GLuint framebuffer, GLenum pname, GLint param);
#define glNamedFramebufferParameteriEXT gll_glNamedFramebufferParameteriEXT
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint framebuffer, GLenum pname, GLint * params);
#define glGetNamedFramebufferParameterivEXT gll_glGetNamedFramebufferParameterivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DEXTPROC)(GLuint program, GLint location, GLdouble x);
#define glProgramUniform1dEXT gll_glProgramUniform1dEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y);
#define glProgramUniform2dEXT gll_glProgramUniform2dEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
#define glProgramUniform3dEXT gll_glProgramUniform3dEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DEXTPROC)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glProgramUniform4dEXT gll_glProgramUniform4dEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform1dvEXT gll_glProgramUniform1dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform2dvEXT gll_glProgramUniform2dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform3dvEXT gll_glProgramUniform3dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLdouble * value);
#define glProgramUniform4dvEXT gll_glProgramUniform4dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2dvEXT gll_glProgramUniformMatrix2dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3dvEXT gll_glProgramUniformMatrix3dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4dvEXT gll_glProgramUniformMatrix4dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x3dvEXT gll_glProgramUniformMatrix2x3dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix2x4dvEXT gll_glProgramUniformMatrix2x4dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x2dvEXT gll_glProgramUniformMatrix3x2dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix3x4dvEXT gll_glProgramUniformMatrix3x4dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x2dvEXT gll_glProgramUniformMatrix4x2dvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value);
#define glProgramUniformMatrix4x3dvEXT gll_glProgramUniformMatrix4x3dvEXT
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEEXTPROC)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
#define glTextureBufferRangeEXT gll_glTextureBufferRangeEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTextureStorage1DEXT gll_glTextureStorage1DEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTextureStorage2DEXT gll_glTextureStorage2DEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTextureStorage3DEXT gll_glTextureStorage3DEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
#define glTextureStorage2DMultisampleEXT gll_glTextureStorage2DMultisampleEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
#define glTextureStorage3DMultisampleEXT gll_glTextureStorage3DMultisampleEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
#define glVertexArrayBindVertexBufferEXT gll_glVertexArrayBindVertexBufferEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
#define glVertexArrayVertexAttribFormatEXT gll_glVertexArrayVertexAttribFormatEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayVertexAttribIFormatEXT gll_glVertexArrayVertexAttribIFormatEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
#define glVertexArrayVertexAttribLFormatEXT gll_glVertexArrayVertexAttribLFormatEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
#define glVertexArrayVertexAttribBindingEXT gll_glVertexArrayVertexAttribBindingEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)(GLuint vaobj, GLuint bindingindex, GLuint divisor);
#define glVertexArrayVertexBindingDivisorEXT gll_glVertexArrayVertexBindingDivisorEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
#define glVertexArrayVertexAttribLOffsetEXT gll_glVertexArrayVertexAttribLOffsetEXT
typedef void (APIENTRYP PFNGLTEXTUREPAGECOMMITMENTEXTPROC)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#define glTexturePageCommitmentEXT gll_glTexturePageCommitmentEXT
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC)(GLuint vaobj, GLuint index, GLuint divisor);
#define glVertexArrayVertexAttribDivisorEXT gll_glVertexArrayVertexAttribDivisorEXT
#endif // GL_EXT_EXT_direct_state_access

#if defined(GL_EXT_EXT_draw_instanced)
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDEXTPROC)(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
#define glDrawArraysInstancedEXT gll_glDrawArraysInstancedEXT
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDEXTPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount);
#define glDrawElementsInstancedEXT gll_glDrawElementsInstancedEXT
#endif // GL_EXT_EXT_draw_instanced

#if defined(GL_EXT_EXT_polygon_offset_clamp)
#define GL_POLYGON_OFFSET_CLAMP_EXT 0x8E1B
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPEXTPROC)(GLfloat factor, GLfloat units, GLfloat clamp);
#define glPolygonOffsetClampEXT gll_glPolygonOffsetClampEXT
#endif // GL_EXT_EXT_polygon_offset_clamp

#if defined(GL_EXT_EXT_raster_multisample)
#define GL_RASTER_MULTISAMPLE_EXT 0x9327
#define GL_RASTER_SAMPLES_EXT 0x9328
#define GL_MAX_RASTER_SAMPLES_EXT 0x9329
#define GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT 0x932A
#define GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT 0x932B
#define GL_EFFECTIVE_RASTER_SAMPLES_EXT 0x932C
typedef void (APIENTRYP PFNGLRASTERSAMPLESEXTPROC)(GLuint samples, GLboolean fixedsamplelocations);
#define glRasterSamplesEXT gll_glRasterSamplesEXT
#endif // GL_EXT_EXT_raster_multisample

#if defined(GL_EXT_EXT_separate_shader_objects)
#define GL_ACTIVE_PROGRAM_EXT 0x8B8D
typedef void (APIENTRYP PFNGLUSESHADERPROGRAMEXTPROC)(GLenum type, GLuint program);
#define glUseShaderProgramEXT gll_glUseShaderProgramEXT
typedef void (APIENTRYP PFNGLACTIVEPROGRAMEXTPROC)(GLuint program);
#define glActiveProgramEXT gll_glActiveProgramEXT
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMEXTPROC)(GLenum type, const GLchar * string);
#define glCreateShaderProgramEXT gll_glCreateShaderProgramEXT
#define GL_VERTEX_SHADER_BIT_EXT 0x00000001
#define GL_FRAGMENT_SHADER_BIT_EXT 0x00000002
#define GL_ALL_SHADER_BITS_EXT 0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE_EXT 0x8258
#define GL_PROGRAM_PIPELINE_BINDING_EXT 0x825A
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMEXTPROC)(GLuint pipeline, GLuint program);
#define glActiveShaderProgramEXT gll_glActiveShaderProgramEXT
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEEXTPROC)(GLuint pipeline);
#define glBindProgramPipelineEXT gll_glBindProgramPipelineEXT
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROGRAMVEXTPROC)(GLenum type, GLsizei count, const GLchar ** strings);
#define glCreateShaderProgramvEXT gll_glCreateShaderProgramvEXT
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESEXTPROC)(GLsizei n, const GLuint * pipelines);
#define glDeleteProgramPipelinesEXT gll_glDeleteProgramPipelinesEXT
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESEXTPROC)(GLsizei n, GLuint * pipelines);
#define glGenProgramPipelinesEXT gll_glGenProgramPipelinesEXT
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGEXTPROC)(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#define glGetProgramPipelineInfoLogEXT gll_glGetProgramPipelineInfoLogEXT
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVEXTPROC)(GLuint pipeline, GLenum pname, GLint * params);
#define glGetProgramPipelineivEXT gll_glGetProgramPipelineivEXT
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEEXTPROC)(GLuint pipeline);
#define glIsProgramPipelineEXT gll_glIsProgramPipelineEXT
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIEXTPROC)(GLuint program, GLenum pname, GLint value);
#define glProgramParameteriEXT gll_glProgramParameteriEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FEXTPROC)(GLuint program, GLint location, GLfloat v0);
#define glProgramUniform1fEXT gll_glProgramUniform1fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform1fvEXT gll_glProgramUniform1fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IEXTPROC)(GLuint program, GLint location, GLint v0);
#define glProgramUniform1iEXT gll_glProgramUniform1iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform1ivEXT gll_glProgramUniform1ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
#define glProgramUniform2fEXT gll_glProgramUniform2fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform2fvEXT gll_glProgramUniform2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1);
#define glProgramUniform2iEXT gll_glProgramUniform2iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform2ivEXT gll_glProgramUniform2ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#define glProgramUniform3fEXT gll_glProgramUniform3fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform3fvEXT gll_glProgramUniform3fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
#define glProgramUniform3iEXT gll_glProgramUniform3iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform3ivEXT gll_glProgramUniform3ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FEXTPROC)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#define glProgramUniform4fEXT gll_glProgramUniform4fEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLfloat * value);
#define glProgramUniform4fvEXT gll_glProgramUniform4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IEXTPROC)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#define glProgramUniform4iEXT gll_glProgramUniform4iEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLint * value);
#define glProgramUniform4ivEXT gll_glProgramUniform4ivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2fvEXT gll_glProgramUniformMatrix2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3fvEXT gll_glProgramUniformMatrix3fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4fvEXT gll_glProgramUniformMatrix4fvEXT
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESEXTPROC)(GLuint pipeline, GLbitfield stages, GLuint program);
#define glUseProgramStagesEXT gll_glUseProgramStagesEXT
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEEXTPROC)(GLuint pipeline);
#define glValidateProgramPipelineEXT gll_glValidateProgramPipelineEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIEXTPROC)(GLuint program, GLint location, GLuint v0);
#define glProgramUniform1uiEXT gll_glProgramUniform1uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1);
#define glProgramUniform2uiEXT gll_glProgramUniform2uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
#define glProgramUniform3uiEXT gll_glProgramUniform3uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIEXTPROC)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
#define glProgramUniform4uiEXT gll_glProgramUniform4uiEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform1uivEXT gll_glProgramUniform1uivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform2uivEXT gll_glProgramUniform2uivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform3uivEXT gll_glProgramUniform3uivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVEXTPROC)(GLuint program, GLint location, GLsizei count, const GLuint * value);
#define glProgramUniform4uivEXT gll_glProgramUniform4uivEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x3fvEXT gll_glProgramUniformMatrix2x3fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x2fvEXT gll_glProgramUniformMatrix3x2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix2x4fvEXT gll_glProgramUniformMatrix2x4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x2fvEXT gll_glProgramUniformMatrix4x2fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix3x4fvEXT gll_glProgramUniformMatrix3x4fvEXT
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#define glProgramUniformMatrix4x3fvEXT gll_glProgramUniformMatrix4x3fvEXT
#endif // GL_EXT_EXT_separate_shader_objects

#if defined(GL_EXT_EXT_shader_framebuffer_fetch)
#define GL_FRAGMENT_SHADER_DISCARDS_SAMPLES_EXT 0x8A52
#endif // GL_EXT_EXT_shader_framebuffer_fetch

#if defined(GL_EXT_EXT_shader_framebuffer_fetch_non_coherent)
typedef void (APIENTRYP PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC)(void);
#define glFramebufferFetchBarrierEXT gll_glFramebufferFetchBarrierEXT
#endif // GL_EXT_EXT_shader_framebuffer_fetch_non_coherent

#if defined(GL_EXT_EXT_texture_compression_s3tc)
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3
#endif // GL_EXT_EXT_texture_compression_s3tc

#if defined(GL_EXT_EXT_texture_filter_minmax)
#define GL_TEXTURE_REDUCTION_MODE_EXT 0x9366
#define GL_WEIGHTED_AVERAGE_EXT 0x9367
#endif // GL_EXT_EXT_texture_filter_minmax

#if defined(GL_EXT_EXT_texture_sRGB_R8)
#define GL_SR8_EXT 0x8FBD
#endif // GL_EXT_EXT_texture_sRGB_R8

#if defined(GL_EXT_EXT_texture_sRGB_RG8)
#define GL_SRG8_EXT 0x8FBE
#endif // GL_EXT_EXT_texture_sRGB_RG8

#if defined(GL_EXT_EXT_texture_sRGB_decode)
#define GL_TEXTURE_SRGB_DECODE_EXT 0x8A48
#define GL_DECODE_EXT 0x8A49
#define GL_SKIP_DECODE_EXT 0x8A4A
#endif // GL_EXT_EXT_texture_sRGB_decode

#if defined(GL_EXT_EXT_texture_storage)
#define GL_TEXTURE_IMMUTABLE_FORMAT_EXT 0x912F
#define GL_ALPHA8_EXT 0x803C
#define GL_LUMINANCE8_EXT 0x8040
#define GL_LUMINANCE8_ALPHA8_EXT 0x8045
#define GL_RGBA32F_EXT 0x8814
#define GL_RGB32F_EXT 0x8815
#define GL_ALPHA32F_EXT 0x8816
#define GL_LUMINANCE32F_EXT 0x8818
#define GL_LUMINANCE_ALPHA32F_EXT 0x8819
#define GL_RGBA16F_EXT 0x881A
#define GL_RGB16F_EXT 0x881B
#define GL_ALPHA16F_EXT 0x881C
#define GL_LUMINANCE16F_EXT 0x881E
#define GL_LUMINANCE_ALPHA16F_EXT 0x881F
#define GL_RGB10_A2_EXT 0x8059
#define GL_RGB10_EXT 0x8052
#define GL_BGRA8_EXT 0x93A1
#define GL_R8_EXT 0x8229
#define GL_RG8_EXT 0x822B
#define GL_R32F_EXT 0x822E
#define GL_RG32F_EXT 0x8230
#define GL_R16F_EXT 0x822D
#define GL_RG16F_EXT 0x822F
typedef void (APIENTRYP PFNGLTEXSTORAGE1DEXTPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTexStorage1DEXT gll_glTexStorage1DEXT
typedef void (APIENTRYP PFNGLTEXSTORAGE2DEXTPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTexStorage2DEXT gll_glTexStorage2DEXT
typedef void (APIENTRYP PFNGLTEXSTORAGE3DEXTPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTexStorage3DEXT gll_glTexStorage3DEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
#define glTextureStorage1DEXT gll_glTextureStorage1DEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
#define glTextureStorage2DEXT gll_glTextureStorage2DEXT
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DEXTPROC)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#define glTextureStorage3DEXT gll_glTextureStorage3DEXT
#endif // GL_EXT_EXT_texture_storage

#if defined(GL_EXT_EXT_window_rectangles)
#define GL_INCLUSIVE_EXT 0x8F10
#define GL_EXCLUSIVE_EXT 0x8F11
#define GL_WINDOW_RECTANGLE_EXT 0x8F12
#define GL_WINDOW_RECTANGLE_MODE_EXT 0x8F13
#define GL_MAX_WINDOW_RECTANGLES_EXT 0x8F14
#define GL_NUM_WINDOW_RECTANGLES_EXT 0x8F15
typedef void (APIENTRYP PFNGLWINDOWRECTANGLESEXTPROC)(GLenum mode, GLsizei count, const GLint * box);
#define glWindowRectanglesEXT gll_glWindowRectanglesEXT
#endif // GL_EXT_EXT_window_rectangles

#if defined(GL_EXT_INTEL_conservative_rasterization)
#define GL_CONSERVATIVE_RASTERIZATION_INTEL 0x83FE
#endif // GL_EXT_INTEL_conservative_rasterization

#if defined(GL_EXT_INTEL_framebuffer_CMAA)
typedef void (APIENTRYP PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC)(void);
#define glApplyFramebufferAttachmentCMAAINTEL gll_glApplyFramebufferAttachmentCMAAINTEL
#endif // GL_EXT_INTEL_framebuffer_CMAA

#if defined(GL_EXT_INTEL_blackhole_render)
#define GL_BLACKHOLE_RENDER_INTEL 0x83FC
#endif // GL_EXT_INTEL_blackhole_render

#if defined(GL_EXT_INTEL_performance_query)
#define GL_PERFQUERY_SINGLE_CONTEXT_INTEL 0x00000000
#define GL_PERFQUERY_GLOBAL_CONTEXT_INTEL 0x00000001
#define GL_PERFQUERY_WAIT_INTEL 0x83FB
#define GL_PERFQUERY_FLUSH_INTEL 0x83FA
#define GL_PERFQUERY_DONOT_FLUSH_INTEL 0x83F9
#define GL_PERFQUERY_COUNTER_EVENT_INTEL 0x94F0
#define GL_PERFQUERY_COUNTER_DURATION_NORM_INTEL 0x94F1
#define GL_PERFQUERY_COUNTER_DURATION_RAW_INTEL 0x94F2
#define GL_PERFQUERY_COUNTER_THROUGHPUT_INTEL 0x94F3
#define GL_PERFQUERY_COUNTER_RAW_INTEL 0x94F4
#define GL_PERFQUERY_COUNTER_TIMESTAMP_INTEL 0x94F5
#define GL_PERFQUERY_COUNTER_DATA_UINT32_INTEL 0x94F8
#define GL_PERFQUERY_COUNTER_DATA_UINT64_INTEL 0x94F9
#define GL_PERFQUERY_COUNTER_DATA_FLOAT_INTEL 0x94FA
#define GL_PERFQUERY_COUNTER_DATA_DOUBLE_INTEL 0x94FB
#define GL_PERFQUERY_COUNTER_DATA_BOOL32_INTEL 0x94FC
#define GL_PERFQUERY_QUERY_NAME_LENGTH_MAX_INTEL 0x94FD
#define GL_PERFQUERY_COUNTER_NAME_LENGTH_MAX_INTEL 0x94FE
#define GL_PERFQUERY_COUNTER_DESC_LENGTH_MAX_INTEL 0x94FF
#define GL_PERFQUERY_GPA_EXTENDED_COUNTERS_INTEL 0x9500
typedef void (APIENTRYP PFNGLBEGINPERFQUERYINTELPROC)(GLuint queryHandle);
#define glBeginPerfQueryINTEL gll_glBeginPerfQueryINTEL
typedef void (APIENTRYP PFNGLCREATEPERFQUERYINTELPROC)(GLuint queryId, GLuint * queryHandle);
#define glCreatePerfQueryINTEL gll_glCreatePerfQueryINTEL
typedef void (APIENTRYP PFNGLDELETEPERFQUERYINTELPROC)(GLuint queryHandle);
#define glDeletePerfQueryINTEL gll_glDeletePerfQueryINTEL
typedef void (APIENTRYP PFNGLENDPERFQUERYINTELPROC)(GLuint queryHandle);
#define glEndPerfQueryINTEL gll_glEndPerfQueryINTEL
typedef void (APIENTRYP PFNGLGETFIRSTPERFQUERYIDINTELPROC)(GLuint * queryId);
#define glGetFirstPerfQueryIdINTEL gll_glGetFirstPerfQueryIdINTEL
typedef void (APIENTRYP PFNGLGETNEXTPERFQUERYIDINTELPROC)(GLuint queryId, GLuint * nextQueryId);
#define glGetNextPerfQueryIdINTEL gll_glGetNextPerfQueryIdINTEL
typedef void (APIENTRYP PFNGLGETPERFCOUNTERINFOINTELPROC)(GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar * counterName, GLuint counterDescLength, GLchar * counterDesc, GLuint * counterOffset, GLuint * counterDataSize, GLuint * counterTypeEnum, GLuint * counterDataTypeEnum, GLuint64 * rawCounterMaxValue);
#define glGetPerfCounterInfoINTEL gll_glGetPerfCounterInfoINTEL
typedef void (APIENTRYP PFNGLGETPERFQUERYDATAINTELPROC)(GLuint queryHandle, GLuint flags, GLsizei dataSize, void * data, GLuint * bytesWritten);
#define glGetPerfQueryDataINTEL gll_glGetPerfQueryDataINTEL
typedef void (APIENTRYP PFNGLGETPERFQUERYIDBYNAMEINTELPROC)(GLchar * queryName, GLuint * queryId);
#define glGetPerfQueryIdByNameINTEL gll_glGetPerfQueryIdByNameINTEL
typedef void (APIENTRYP PFNGLGETPERFQUERYINFOINTELPROC)(GLuint queryId, GLuint queryNameLength, GLchar * queryName, GLuint * dataSize, GLuint * noCounters, GLuint * noInstances, GLuint * capsMask);
#define glGetPerfQueryInfoINTEL gll_glGetPerfQueryInfoINTEL
#endif // GL_EXT_INTEL_performance_query

#if defined(GL_EXT_KHR_blend_equation_advanced)
#define GL_MULTIPLY_KHR 0x9294
#define GL_SCREEN_KHR 0x9295
#define GL_OVERLAY_KHR 0x9296
#define GL_DARKEN_KHR 0x9297
#define GL_LIGHTEN_KHR 0x9298
#define GL_COLORDODGE_KHR 0x9299
#define GL_COLORBURN_KHR 0x929A
#define GL_HARDLIGHT_KHR 0x929B
#define GL_SOFTLIGHT_KHR 0x929C
#define GL_DIFFERENCE_KHR 0x929E
#define GL_EXCLUSION_KHR 0x92A0
#define GL_HSL_HUE_KHR 0x92AD
#define GL_HSL_SATURATION_KHR 0x92AE
#define GL_HSL_COLOR_KHR 0x92AF
#define GL_HSL_LUMINOSITY_KHR 0x92B0
typedef void (APIENTRYP PFNGLBLENDBARRIERKHRPROC)(void);
#define glBlendBarrierKHR gll_glBlendBarrierKHR
#endif // GL_EXT_KHR_blend_equation_advanced

#if defined(GL_EXT_KHR_blend_equation_advanced_coherent)
#define GL_BLEND_ADVANCED_COHERENT_KHR 0x9285
#endif // GL_EXT_KHR_blend_equation_advanced_coherent

#if defined(GL_EXT_KHR_context_flush_control)
#define GL_CONTEXT_RELEASE_BEHAVIOR_KHR 0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_KHR 0x82FC
#endif // GL_EXT_KHR_context_flush_control

#if defined(GL_EXT_KHR_debug)
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
#define glDebugMessageControl gll_glDebugMessageControl
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
#define glDebugMessageInsert gll_glDebugMessageInsert
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC callback, const void * userParam);
#define glDebugMessageCallback gll_glDebugMessageCallback
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
#define glGetDebugMessageLog gll_glGetDebugMessageLog
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC)(GLenum source, GLuint id, GLsizei length, const GLchar * message);
#define glPushDebugGroup gll_glPushDebugGroup
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC)(void);
#define glPopDebugGroup gll_glPopDebugGroup
typedef void (APIENTRYP PFNGLOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
#define glObjectLabel gll_glObjectLabel
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectLabel gll_glGetObjectLabel
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC)(const void * ptr, GLsizei length, const GLchar * label);
#define glObjectPtrLabel gll_glObjectPtrLabel
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC)(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectPtrLabel gll_glGetObjectPtrLabel
typedef void (APIENTRYP PFNGLGETPOINTERVPROC)(GLenum pname, void ** params);
#define glGetPointerv gll_glGetPointerv
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_KHR 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_KHR 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_KHR 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_KHR 0x8245
#define GL_DEBUG_SOURCE_API_KHR 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_KHR 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_KHR 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_KHR 0x8249
#define GL_DEBUG_SOURCE_APPLICATION_KHR 0x824A
#define GL_DEBUG_SOURCE_OTHER_KHR 0x824B
#define GL_DEBUG_TYPE_ERROR_KHR 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_KHR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_KHR 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_KHR 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_KHR 0x8250
#define GL_DEBUG_TYPE_OTHER_KHR 0x8251
#define GL_DEBUG_TYPE_MARKER_KHR 0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP_KHR 0x8269
#define GL_DEBUG_TYPE_POP_GROUP_KHR 0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION_KHR 0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH_KHR 0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH_KHR 0x826D
#define GL_BUFFER_KHR 0x82E0
#define GL_SHADER_KHR 0x82E1
#define GL_PROGRAM_KHR 0x82E2
#define GL_VERTEX_ARRAY_KHR 0x8074
#define GL_QUERY_KHR 0x82E3
#define GL_PROGRAM_PIPELINE_KHR 0x82E4
#define GL_SAMPLER_KHR 0x82E6
#define GL_MAX_LABEL_LENGTH_KHR 0x82E8
#define GL_MAX_DEBUG_MESSAGE_LENGTH_KHR 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_KHR 0x9144
#define GL_DEBUG_LOGGED_MESSAGES_KHR 0x9145
#define GL_DEBUG_SEVERITY_HIGH_KHR 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_KHR 0x9147
#define GL_DEBUG_SEVERITY_LOW_KHR 0x9148
#define GL_DEBUG_OUTPUT_KHR 0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT_KHR 0x00000002
#define GL_STACK_OVERFLOW_KHR 0x0503
#define GL_STACK_UNDERFLOW_KHR 0x0504
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLKHRPROC)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled);
#define glDebugMessageControlKHR gll_glDebugMessageControlKHR
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTKHRPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf);
#define glDebugMessageInsertKHR gll_glDebugMessageInsertKHR
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKKHRPROC)(GLDEBUGPROCKHR callback, const void * userParam);
#define glDebugMessageCallbackKHR gll_glDebugMessageCallbackKHR
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGKHRPROC)(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
#define glGetDebugMessageLogKHR gll_glGetDebugMessageLogKHR
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPKHRPROC)(GLenum source, GLuint id, GLsizei length, const GLchar * message);
#define glPushDebugGroupKHR gll_glPushDebugGroupKHR
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPKHRPROC)(void);
#define glPopDebugGroupKHR gll_glPopDebugGroupKHR
typedef void (APIENTRYP PFNGLOBJECTLABELKHRPROC)(GLenum identifier, GLuint name, GLsizei length, const GLchar * label);
#define glObjectLabelKHR gll_glObjectLabelKHR
typedef void (APIENTRYP PFNGLGETOBJECTLABELKHRPROC)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectLabelKHR gll_glGetObjectLabelKHR
typedef void (APIENTRYP PFNGLOBJECTPTRLABELKHRPROC)(const void * ptr, GLsizei length, const GLchar * label);
#define glObjectPtrLabelKHR gll_glObjectPtrLabelKHR
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELKHRPROC)(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label);
#define glGetObjectPtrLabelKHR gll_glGetObjectPtrLabelKHR
typedef void (APIENTRYP PFNGLGETPOINTERVKHRPROC)(GLenum pname, void ** params);
#define glGetPointervKHR gll_glGetPointervKHR
#endif // GL_EXT_KHR_debug

#if defined(GL_EXT_KHR_no_error)
#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR 0x00000008
#endif // GL_EXT_KHR_no_error

#if defined(GL_EXT_KHR_robustness)
#define GL_CONTEXT_ROBUST_ACCESS 0x90F3
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC)(void);
#define glGetGraphicsResetStatus gll_glGetGraphicsResetStatus
typedef void (APIENTRYP PFNGLREADNPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
#define glReadnPixels gll_glReadnPixels
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
#define glGetnUniformfv gll_glGetnUniformfv
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLint * params);
#define glGetnUniformiv gll_glGetnUniformiv
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint * params);
#define glGetnUniformuiv gll_glGetnUniformuiv
#define GL_CONTEXT_ROBUST_ACCESS_KHR 0x90F3
#define GL_LOSE_CONTEXT_ON_RESET_KHR 0x8252
#define GL_GUILTY_CONTEXT_RESET_KHR 0x8253
#define GL_INNOCENT_CONTEXT_RESET_KHR 0x8254
#define GL_UNKNOWN_CONTEXT_RESET_KHR 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_KHR 0x8256
#define GL_NO_RESET_NOTIFICATION_KHR 0x8261
#define GL_CONTEXT_LOST_KHR 0x0507
typedef GLenum (APIENTRYP PFNGLGETGRAPHICSRESETSTATUSKHRPROC)(void);
#define glGetGraphicsResetStatusKHR gll_glGetGraphicsResetStatusKHR
typedef void (APIENTRYP PFNGLREADNPIXELSKHRPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
#define glReadnPixelsKHR gll_glReadnPixelsKHR
typedef void (APIENTRYP PFNGLGETNUNIFORMFVKHRPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
#define glGetnUniformfvKHR gll_glGetnUniformfvKHR
typedef void (APIENTRYP PFNGLGETNUNIFORMIVKHRPROC)(GLuint program, GLint location, GLsizei bufSize, GLint * params);
#define glGetnUniformivKHR gll_glGetnUniformivKHR
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVKHRPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint * params);
#define glGetnUniformuivKHR gll_glGetnUniformuivKHR
#endif // GL_EXT_KHR_robustness

#if defined(GL_EXT_KHR_shader_subgroup)
#define GL_SUBGROUP_SIZE_KHR 0x9532
#define GL_SUBGROUP_SUPPORTED_STAGES_KHR 0x9533
#define GL_SUBGROUP_SUPPORTED_FEATURES_KHR 0x9534
#define GL_SUBGROUP_QUAD_ALL_STAGES_KHR 0x9535
#define GL_SUBGROUP_FEATURE_BASIC_BIT_KHR 0x00000001
#define GL_SUBGROUP_FEATURE_VOTE_BIT_KHR 0x00000002
#define GL_SUBGROUP_FEATURE_ARITHMETIC_BIT_KHR 0x00000004
#define GL_SUBGROUP_FEATURE_BALLOT_BIT_KHR 0x00000008
#define GL_SUBGROUP_FEATURE_SHUFFLE_BIT_KHR 0x00000010
#define GL_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT_KHR 0x00000020
#define GL_SUBGROUP_FEATURE_CLUSTERED_BIT_KHR 0x00000040
#define GL_SUBGROUP_FEATURE_QUAD_BIT_KHR 0x00000080
#endif // GL_EXT_KHR_shader_subgroup

#if defined(GL_EXT_KHR_texture_compression_astc_hdr)
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR 0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR 0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR 0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR 0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR 0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR 0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR 0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR 0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR 0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR 0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR 0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD
#endif // GL_EXT_KHR_texture_compression_astc_hdr

#if defined(GL_EXT_KHR_texture_compression_astc_ldr)
#endif // GL_EXT_KHR_texture_compression_astc_ldr

#if defined(GL_EXT_KHR_parallel_shader_compile)
#define GL_MAX_SHADER_COMPILER_THREADS_KHR 0x91B0
#define GL_COMPLETION_STATUS_KHR 0x91B1
typedef void (APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSKHRPROC)(GLuint count);
#define glMaxShaderCompilerThreadsKHR gll_glMaxShaderCompilerThreadsKHR
#endif // GL_EXT_KHR_parallel_shader_compile

#if defined(GL_EXT_MESA_framebuffer_flip_x)
#define GL_FRAMEBUFFER_FLIP_X_MESA 0x8BBC
#endif // GL_EXT_MESA_framebuffer_flip_x

#if defined(GL_EXT_MESA_framebuffer_flip_y)
#define GL_FRAMEBUFFER_FLIP_Y_MESA 0x8BBB
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIMESAPROC)(GLenum target, GLenum pname, GLint param);
#define glFramebufferParameteriMESA gll_glFramebufferParameteriMESA
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC)(GLenum target, GLenum pname, GLint * params);
#define glGetFramebufferParameterivMESA gll_glGetFramebufferParameterivMESA
#endif // GL_EXT_MESA_framebuffer_flip_y

#if defined(GL_EXT_MESA_framebuffer_swap_xy)
#define GL_FRAMEBUFFER_SWAP_XY_MESA 0x8BBD
#endif // GL_EXT_MESA_framebuffer_swap_xy

#if defined(GL_EXT_NV_bindless_multi_draw_indirect)
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC)(GLenum mode, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
#define glMultiDrawArraysIndirectBindlessNV gll_glMultiDrawArraysIndirectBindlessNV
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC)(GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
#define glMultiDrawElementsIndirectBindlessNV gll_glMultiDrawElementsIndirectBindlessNV
#endif // GL_EXT_NV_bindless_multi_draw_indirect

#if defined(GL_EXT_NV_bindless_multi_draw_indirect_count)
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC)(GLenum mode, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
#define glMultiDrawArraysIndirectBindlessCountNV gll_glMultiDrawArraysIndirectBindlessCountNV
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC)(GLenum mode, GLenum type, const void * indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
#define glMultiDrawElementsIndirectBindlessCountNV gll_glMultiDrawElementsIndirectBindlessCountNV
#endif // GL_EXT_NV_bindless_multi_draw_indirect_count

#if defined(GL_EXT_NV_bindless_texture)
typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLENVPROC)(GLuint texture);
#define glGetTextureHandleNV gll_glGetTextureHandleNV
typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLENVPROC)(GLuint texture, GLuint sampler);
#define glGetTextureSamplerHandleNV gll_glGetTextureSamplerHandleNV
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)(GLuint64 handle);
#define glMakeTextureHandleResidentNV gll_glMakeTextureHandleResidentNV
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)(GLuint64 handle);
#define glMakeTextureHandleNonResidentNV gll_glMakeTextureHandleNonResidentNV
typedef GLuint64 (APIENTRYP PFNGLGETIMAGEHANDLENVPROC)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
#define glGetImageHandleNV gll_glGetImageHandleNV
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)(GLuint64 handle, GLenum access);
#define glMakeImageHandleResidentNV gll_glMakeImageHandleResidentNV
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)(GLuint64 handle);
#define glMakeImageHandleNonResidentNV gll_glMakeImageHandleNonResidentNV
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64NVPROC)(GLint location, GLuint64 value);
#define glUniformHandleui64NV gll_glUniformHandleui64NV
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VNVPROC)(GLint location, GLsizei count, const GLuint64 * value);
#define glUniformHandleui64vNV gll_glUniformHandleui64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)(GLuint program, GLint location, GLuint64 value);
#define glProgramUniformHandleui64NV gll_glProgramUniformHandleui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64 * values);
#define glProgramUniformHandleui64vNV gll_glProgramUniformHandleui64vNV
typedef GLboolean (APIENTRYP PFNGLISTEXTUREHANDLERESIDENTNVPROC)(GLuint64 handle);
#define glIsTextureHandleResidentNV gll_glIsTextureHandleResidentNV
typedef GLboolean (APIENTRYP PFNGLISIMAGEHANDLERESIDENTNVPROC)(GLuint64 handle);
#define glIsImageHandleResidentNV gll_glIsImageHandleResidentNV
#endif // GL_EXT_NV_bindless_texture

#if defined(GL_EXT_NV_blend_equation_advanced)
#define GL_BLEND_OVERLAP_NV 0x9281
#define GL_BLEND_PREMULTIPLIED_SRC_NV 0x9280
#define GL_BLUE_NV 0x1905
#define GL_COLORBURN_NV 0x929A
#define GL_COLORDODGE_NV 0x9299
#define GL_CONJOINT_NV 0x9284
#define GL_CONTRAST_NV 0x92A1
#define GL_DARKEN_NV 0x9297
#define GL_DIFFERENCE_NV 0x929E
#define GL_DISJOINT_NV 0x9283
#define GL_DST_ATOP_NV 0x928F
#define GL_DST_IN_NV 0x928B
#define GL_DST_NV 0x9287
#define GL_DST_OUT_NV 0x928D
#define GL_DST_OVER_NV 0x9289
#define GL_EXCLUSION_NV 0x92A0
#define GL_GREEN_NV 0x1904
#define GL_HARDLIGHT_NV 0x929B
#define GL_HARDMIX_NV 0x92A9
#define GL_HSL_COLOR_NV 0x92AF
#define GL_HSL_HUE_NV 0x92AD
#define GL_HSL_LUMINOSITY_NV 0x92B0
#define GL_HSL_SATURATION_NV 0x92AE
#define GL_INVERT_OVG_NV 0x92B4
#define GL_INVERT_RGB_NV 0x92A3
#define GL_LIGHTEN_NV 0x9298
#define GL_LINEARBURN_NV 0x92A5
#define GL_LINEARDODGE_NV 0x92A4
#define GL_LINEARLIGHT_NV 0x92A7
#define GL_MINUS_CLAMPED_NV 0x92B3
#define GL_MINUS_NV 0x929F
#define GL_MULTIPLY_NV 0x9294
#define GL_OVERLAY_NV 0x9296
#define GL_PINLIGHT_NV 0x92A8
#define GL_PLUS_CLAMPED_ALPHA_NV 0x92B2
#define GL_PLUS_CLAMPED_NV 0x92B1
#define GL_PLUS_DARKER_NV 0x9292
#define GL_PLUS_NV 0x9291
#define GL_RED_NV 0x1903
#define GL_SCREEN_NV 0x9295
#define GL_SOFTLIGHT_NV 0x929C
#define GL_SRC_ATOP_NV 0x928E
#define GL_SRC_IN_NV 0x928A
#define GL_SRC_NV 0x9286
#define GL_SRC_OUT_NV 0x928C
#define GL_SRC_OVER_NV 0x9288
#define GL_UNCORRELATED_NV 0x9282
#define GL_VIVIDLIGHT_NV 0x92A6
#define GL_XOR_NV 0x1506
typedef void (APIENTRYP PFNGLBLENDPARAMETERINVPROC)(GLenum pname, GLint value);
#define glBlendParameteriNV gll_glBlendParameteriNV
typedef void (APIENTRYP PFNGLBLENDBARRIERNVPROC)(void);
#define glBlendBarrierNV gll_glBlendBarrierNV
#endif // GL_EXT_NV_blend_equation_advanced

#if defined(GL_EXT_NV_blend_equation_advanced_coherent)
#define GL_BLEND_ADVANCED_COHERENT_NV 0x9285
#endif // GL_EXT_NV_blend_equation_advanced_coherent

#if defined(GL_EXT_NV_blend_minmax_factor)
#define GL_FACTOR_MIN_AMD 0x901C
#define GL_FACTOR_MAX_AMD 0x901D
#endif // GL_EXT_NV_blend_minmax_factor

#if defined(GL_EXT_NV_clip_space_w_scaling)
#define GL_VIEWPORT_POSITION_W_SCALE_NV 0x937C
#define GL_VIEWPORT_POSITION_W_SCALE_X_COEFF_NV 0x937D
#define GL_VIEWPORT_POSITION_W_SCALE_Y_COEFF_NV 0x937E
typedef void (APIENTRYP PFNGLVIEWPORTPOSITIONWSCALENVPROC)(GLuint index, GLfloat xcoeff, GLfloat ycoeff);
#define glViewportPositionWScaleNV gll_glViewportPositionWScaleNV
#endif // GL_EXT_NV_clip_space_w_scaling

#if defined(GL_EXT_NV_command_list)
#define GL_TERMINATE_SEQUENCE_COMMAND_NV 0x0000
#define GL_NOP_COMMAND_NV 0x0001
#define GL_DRAW_ELEMENTS_COMMAND_NV 0x0002
#define GL_DRAW_ARRAYS_COMMAND_NV 0x0003
#define GL_DRAW_ELEMENTS_STRIP_COMMAND_NV 0x0004
#define GL_DRAW_ARRAYS_STRIP_COMMAND_NV 0x0005
#define GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV 0x0006
#define GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV 0x0007
#define GL_ELEMENT_ADDRESS_COMMAND_NV 0x0008
#define GL_ATTRIBUTE_ADDRESS_COMMAND_NV 0x0009
#define GL_UNIFORM_ADDRESS_COMMAND_NV 0x000A
#define GL_BLEND_COLOR_COMMAND_NV 0x000B
#define GL_STENCIL_REF_COMMAND_NV 0x000C
#define GL_LINE_WIDTH_COMMAND_NV 0x000D
#define GL_POLYGON_OFFSET_COMMAND_NV 0x000E
#define GL_ALPHA_REF_COMMAND_NV 0x000F
#define GL_VIEWPORT_COMMAND_NV 0x0010
#define GL_SCISSOR_COMMAND_NV 0x0011
#define GL_FRONT_FACE_COMMAND_NV 0x0012
typedef void (APIENTRYP PFNGLCREATESTATESNVPROC)(GLsizei n, GLuint * states);
#define glCreateStatesNV gll_glCreateStatesNV
typedef void (APIENTRYP PFNGLDELETESTATESNVPROC)(GLsizei n, const GLuint * states);
#define glDeleteStatesNV gll_glDeleteStatesNV
typedef GLboolean (APIENTRYP PFNGLISSTATENVPROC)(GLuint state);
#define glIsStateNV gll_glIsStateNV
typedef void (APIENTRYP PFNGLSTATECAPTURENVPROC)(GLuint state, GLenum mode);
#define glStateCaptureNV gll_glStateCaptureNV
typedef GLuint (APIENTRYP PFNGLGETCOMMANDHEADERNVPROC)(GLenum tokenID, GLuint size);
#define glGetCommandHeaderNV gll_glGetCommandHeaderNV
typedef GLushort (APIENTRYP PFNGLGETSTAGEINDEXNVPROC)(GLenum shadertype);
#define glGetStageIndexNV gll_glGetStageIndexNV
typedef void (APIENTRYP PFNGLDRAWCOMMANDSNVPROC)(GLenum primitiveMode, GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, GLuint count);
#define glDrawCommandsNV gll_glDrawCommandsNV
typedef void (APIENTRYP PFNGLDRAWCOMMANDSADDRESSNVPROC)(GLenum primitiveMode, const GLuint64 * indirects, const GLsizei * sizes, GLuint count);
#define glDrawCommandsAddressNV gll_glDrawCommandsAddressNV
typedef void (APIENTRYP PFNGLDRAWCOMMANDSSTATESNVPROC)(GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count);
#define glDrawCommandsStatesNV gll_glDrawCommandsStatesNV
typedef void (APIENTRYP PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC)(const GLuint64 * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count);
#define glDrawCommandsStatesAddressNV gll_glDrawCommandsStatesAddressNV
typedef void (APIENTRYP PFNGLCREATECOMMANDLISTSNVPROC)(GLsizei n, GLuint * lists);
#define glCreateCommandListsNV gll_glCreateCommandListsNV
typedef void (APIENTRYP PFNGLDELETECOMMANDLISTSNVPROC)(GLsizei n, const GLuint * lists);
#define glDeleteCommandListsNV gll_glDeleteCommandListsNV
typedef GLboolean (APIENTRYP PFNGLISCOMMANDLISTNVPROC)(GLuint list);
#define glIsCommandListNV gll_glIsCommandListNV
typedef void (APIENTRYP PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC)(GLuint list, GLuint segment, const void ** indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count);
#define glListDrawCommandsStatesClientNV gll_glListDrawCommandsStatesClientNV
typedef void (APIENTRYP PFNGLCOMMANDLISTSEGMENTSNVPROC)(GLuint list, GLuint segments);
#define glCommandListSegmentsNV gll_glCommandListSegmentsNV
typedef void (APIENTRYP PFNGLCOMPILECOMMANDLISTNVPROC)(GLuint list);
#define glCompileCommandListNV gll_glCompileCommandListNV
typedef void (APIENTRYP PFNGLCALLCOMMANDLISTNVPROC)(GLuint list);
#define glCallCommandListNV gll_glCallCommandListNV
#endif // GL_EXT_NV_command_list

#if defined(GL_EXT_NV_conditional_render)
#define GL_QUERY_WAIT_NV 0x8E13
#define GL_QUERY_NO_WAIT_NV 0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV 0x8E16
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERNVPROC)(GLuint id, GLenum mode);
#define glBeginConditionalRenderNV gll_glBeginConditionalRenderNV
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERNVPROC)(void);
#define glEndConditionalRenderNV gll_glEndConditionalRenderNV
#endif // GL_EXT_NV_conditional_render

#if defined(GL_EXT_NV_conservative_raster)
#define GL_CONSERVATIVE_RASTERIZATION_NV 0x9346
#define GL_SUBPIXEL_PRECISION_BIAS_X_BITS_NV 0x9347
#define GL_SUBPIXEL_PRECISION_BIAS_Y_BITS_NV 0x9348
#define GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV 0x9349
typedef void (APIENTRYP PFNGLSUBPIXELPRECISIONBIASNVPROC)(GLuint xbits, GLuint ybits);
#define glSubpixelPrecisionBiasNV gll_glSubpixelPrecisionBiasNV
#endif // GL_EXT_NV_conservative_raster

#if defined(GL_EXT_NV_conservative_raster_dilate)
#define GL_CONSERVATIVE_RASTER_DILATE_NV 0x9379
#define GL_CONSERVATIVE_RASTER_DILATE_RANGE_NV 0x937A
#define GL_CONSERVATIVE_RASTER_DILATE_GRANULARITY_NV 0x937B
typedef void (APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERFNVPROC)(GLenum pname, GLfloat value);
#define glConservativeRasterParameterfNV gll_glConservativeRasterParameterfNV
#endif // GL_EXT_NV_conservative_raster_dilate

#if defined(GL_EXT_NV_conservative_raster_pre_snap)
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_NV 0x9550
#endif // GL_EXT_NV_conservative_raster_pre_snap

#if defined(GL_EXT_NV_conservative_raster_pre_snap_triangles)
#define GL_CONSERVATIVE_RASTER_MODE_NV 0x954D
#define GL_CONSERVATIVE_RASTER_MODE_POST_SNAP_NV 0x954E
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_TRIANGLES_NV 0x954F
typedef void (APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERINVPROC)(GLenum pname, GLint param);
#define glConservativeRasterParameteriNV gll_glConservativeRasterParameteriNV
#endif // GL_EXT_NV_conservative_raster_pre_snap_triangles

#if defined(GL_EXT_NV_depth_buffer_float)
#define GL_DEPTH_COMPONENT32F_NV 0x8DAB
#define GL_DEPTH32F_STENCIL8_NV 0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV 0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV 0x8DAF
typedef void (APIENTRYP PFNGLDEPTHRANGEDNVPROC)(GLdouble zNear, GLdouble zFar);
#define glDepthRangedNV gll_glDepthRangedNV
typedef void (APIENTRYP PFNGLCLEARDEPTHDNVPROC)(GLdouble depth);
#define glClearDepthdNV gll_glClearDepthdNV
typedef void (APIENTRYP PFNGLDEPTHBOUNDSDNVPROC)(GLdouble zmin, GLdouble zmax);
#define glDepthBoundsdNV gll_glDepthBoundsdNV
#endif // GL_EXT_NV_depth_buffer_float

#if defined(GL_EXT_NV_draw_vulkan_image)
typedef void (APIENTRYP PFNGLDRAWVKIMAGENVPROC)(GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
#define glDrawVkImageNV gll_glDrawVkImageNV
typedef GLVULKANPROCNV (APIENTRYP PFNGLGETVKPROCADDRNVPROC)(const GLchar * name);
#define glGetVkProcAddrNV gll_glGetVkProcAddrNV
typedef void (APIENTRYP PFNGLWAITVKSEMAPHORENVPROC)(GLuint64 vkSemaphore);
#define glWaitVkSemaphoreNV gll_glWaitVkSemaphoreNV
typedef void (APIENTRYP PFNGLSIGNALVKSEMAPHORENVPROC)(GLuint64 vkSemaphore);
#define glSignalVkSemaphoreNV gll_glSignalVkSemaphoreNV
typedef void (APIENTRYP PFNGLSIGNALVKFENCENVPROC)(GLuint64 vkFence);
#define glSignalVkFenceNV gll_glSignalVkFenceNV
#endif // GL_EXT_NV_draw_vulkan_image

#if defined(GL_EXT_NV_fill_rectangle)
#define GL_FILL_RECTANGLE_NV 0x933C
#endif // GL_EXT_NV_fill_rectangle

#if defined(GL_EXT_NV_fragment_coverage_to_color)
#define GL_FRAGMENT_COVERAGE_TO_COLOR_NV 0x92DD
#define GL_FRAGMENT_COVERAGE_COLOR_NV 0x92DE
typedef void (APIENTRYP PFNGLFRAGMENTCOVERAGECOLORNVPROC)(GLuint color);
#define glFragmentCoverageColorNV gll_glFragmentCoverageColorNV
#endif // GL_EXT_NV_fragment_coverage_to_color

#if defined(GL_EXT_NV_framebuffer_mixed_samples)
#define GL_COVERAGE_MODULATION_TABLE_NV 0x9331
#define GL_COLOR_SAMPLES_NV 0x8E20
#define GL_DEPTH_SAMPLES_NV 0x932D
#define GL_STENCIL_SAMPLES_NV 0x932E
#define GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV 0x932F
#define GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV 0x9330
#define GL_COVERAGE_MODULATION_NV 0x9332
#define GL_COVERAGE_MODULATION_TABLE_SIZE_NV 0x9333
typedef void (APIENTRYP PFNGLRASTERSAMPLESEXTPROC)(GLuint samples, GLboolean fixedsamplelocations);
#define glRasterSamplesEXT gll_glRasterSamplesEXT
typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONTABLENVPROC)(GLsizei n, const GLfloat * v);
#define glCoverageModulationTableNV gll_glCoverageModulationTableNV
typedef void (APIENTRYP PFNGLGETCOVERAGEMODULATIONTABLENVPROC)(GLsizei bufSize, GLfloat * v);
#define glGetCoverageModulationTableNV gll_glGetCoverageModulationTableNV
typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONNVPROC)(GLenum components);
#define glCoverageModulationNV gll_glCoverageModulationNV
#endif // GL_EXT_NV_framebuffer_mixed_samples

#if defined(GL_EXT_NV_framebuffer_multisample_coverage)
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV 0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV 0x8E12
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisampleCoverageNV gll_glRenderbufferStorageMultisampleCoverageNV
#endif // GL_EXT_NV_framebuffer_multisample_coverage

#if defined(GL_EXT_NV_gpu_shader5)
#define GL_INT64_NV 0x140E
#define GL_UNSIGNED_INT64_NV 0x140F
#define GL_INT8_NV 0x8FE0
#define GL_INT8_VEC2_NV 0x8FE1
#define GL_INT8_VEC3_NV 0x8FE2
#define GL_INT8_VEC4_NV 0x8FE3
#define GL_INT16_NV 0x8FE4
#define GL_INT16_VEC2_NV 0x8FE5
#define GL_INT16_VEC3_NV 0x8FE6
#define GL_INT16_VEC4_NV 0x8FE7
#define GL_INT64_VEC2_NV 0x8FE9
#define GL_INT64_VEC3_NV 0x8FEA
#define GL_INT64_VEC4_NV 0x8FEB
#define GL_UNSIGNED_INT8_NV 0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV 0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV 0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV 0x8FEF
#define GL_UNSIGNED_INT16_NV 0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV 0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV 0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV 0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV 0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV 0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV 0x8FF7
#define GL_FLOAT16_NV 0x8FF8
#define GL_FLOAT16_VEC2_NV 0x8FF9
#define GL_FLOAT16_VEC3_NV 0x8FFA
#define GL_FLOAT16_VEC4_NV 0x8FFB
typedef void (APIENTRYP PFNGLUNIFORM1I64NVPROC)(GLint location, GLint64EXT x);
#define glUniform1i64NV gll_glUniform1i64NV
typedef void (APIENTRYP PFNGLUNIFORM2I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y);
#define glUniform2i64NV gll_glUniform2i64NV
typedef void (APIENTRYP PFNGLUNIFORM3I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
#define glUniform3i64NV gll_glUniform3i64NV
typedef void (APIENTRYP PFNGLUNIFORM4I64NVPROC)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
#define glUniform4i64NV gll_glUniform4i64NV
typedef void (APIENTRYP PFNGLUNIFORM1I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT * value);
#define glUniform1i64vNV gll_glUniform1i64vNV
typedef void (APIENTRYP PFNGLUNIFORM2I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT * value);
#define glUniform2i64vNV gll_glUniform2i64vNV
typedef void (APIENTRYP PFNGLUNIFORM3I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT * value);
#define glUniform3i64vNV gll_glUniform3i64vNV
typedef void (APIENTRYP PFNGLUNIFORM4I64VNVPROC)(GLint location, GLsizei count, const GLint64EXT * value);
#define glUniform4i64vNV gll_glUniform4i64vNV
typedef void (APIENTRYP PFNGLUNIFORM1UI64NVPROC)(GLint location, GLuint64EXT x);
#define glUniform1ui64NV gll_glUniform1ui64NV
typedef void (APIENTRYP PFNGLUNIFORM2UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y);
#define glUniform2ui64NV gll_glUniform2ui64NV
typedef void (APIENTRYP PFNGLUNIFORM3UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
#define glUniform3ui64NV gll_glUniform3ui64NV
typedef void (APIENTRYP PFNGLUNIFORM4UI64NVPROC)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
#define glUniform4ui64NV gll_glUniform4ui64NV
typedef void (APIENTRYP PFNGLUNIFORM1UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT * value);
#define glUniform1ui64vNV gll_glUniform1ui64vNV
typedef void (APIENTRYP PFNGLUNIFORM2UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT * value);
#define glUniform2ui64vNV gll_glUniform2ui64vNV
typedef void (APIENTRYP PFNGLUNIFORM3UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT * value);
#define glUniform3ui64vNV gll_glUniform3ui64vNV
typedef void (APIENTRYP PFNGLUNIFORM4UI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT * value);
#define glUniform4ui64vNV gll_glUniform4ui64vNV
typedef void (APIENTRYP PFNGLGETUNIFORMI64VNVPROC)(GLuint program, GLint location, GLint64EXT * params);
#define glGetUniformi64vNV gll_glGetUniformi64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64NVPROC)(GLuint program, GLint location, GLint64EXT x);
#define glProgramUniform1i64NV gll_glProgramUniform1i64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
#define glProgramUniform2i64NV gll_glProgramUniform2i64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
#define glProgramUniform3i64NV gll_glProgramUniform3i64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64NVPROC)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
#define glProgramUniform4i64NV gll_glProgramUniform4i64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
#define glProgramUniform1i64vNV gll_glProgramUniform1i64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
#define glProgramUniform2i64vNV gll_glProgramUniform2i64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
#define glProgramUniform3i64vNV gll_glProgramUniform3i64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLint64EXT * value);
#define glProgramUniform4i64vNV gll_glProgramUniform4i64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x);
#define glProgramUniform1ui64NV gll_glProgramUniform1ui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
#define glProgramUniform2ui64NV gll_glProgramUniform2ui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
#define glProgramUniform3ui64NV gll_glProgramUniform3ui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64NVPROC)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
#define glProgramUniform4ui64NV gll_glProgramUniform4ui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
#define glProgramUniform1ui64vNV gll_glProgramUniform1ui64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
#define glProgramUniform2ui64vNV gll_glProgramUniform2ui64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
#define glProgramUniform3ui64vNV gll_glProgramUniform3ui64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
#define glProgramUniform4ui64vNV gll_glProgramUniform4ui64vNV
#endif // GL_EXT_NV_gpu_shader5

#if defined(GL_EXT_NV_internalformat_sample_query)
#define GL_MULTISAMPLES_NV 0x9371
#define GL_SUPERSAMPLE_SCALE_X_NV 0x9372
#define GL_SUPERSAMPLE_SCALE_Y_NV 0x9373
#define GL_CONFORMANT_NV 0x9374
typedef void (APIENTRYP PFNGLGETINTERNALFORMATSAMPLEIVNVPROC)(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei count, GLint * params);
#define glGetInternalformatSampleivNV gll_glGetInternalformatSampleivNV
#endif // GL_EXT_NV_internalformat_sample_query

#if defined(GL_EXT_NV_memory_attachment)
#define GL_ATTACHED_MEMORY_OBJECT_NV 0x95A4
#define GL_ATTACHED_MEMORY_OFFSET_NV 0x95A5
#define GL_MEMORY_ATTACHABLE_ALIGNMENT_NV 0x95A6
#define GL_MEMORY_ATTACHABLE_SIZE_NV 0x95A7
#define GL_MEMORY_ATTACHABLE_NV 0x95A8
#define GL_DETACHED_MEMORY_INCARNATION_NV 0x95A9
#define GL_DETACHED_TEXTURES_NV 0x95AA
#define GL_DETACHED_BUFFERS_NV 0x95AB
#define GL_MAX_DETACHED_TEXTURES_NV 0x95AC
#define GL_MAX_DETACHED_BUFFERS_NV 0x95AD
typedef void (APIENTRYP PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC)(GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint * params);
#define glGetMemoryObjectDetachedResourcesuivNV gll_glGetMemoryObjectDetachedResourcesuivNV
typedef void (APIENTRYP PFNGLRESETMEMORYOBJECTPARAMETERNVPROC)(GLuint memory, GLenum pname);
#define glResetMemoryObjectParameterNV gll_glResetMemoryObjectParameterNV
typedef void (APIENTRYP PFNGLTEXATTACHMEMORYNVPROC)(GLenum target, GLuint memory, GLuint64 offset);
#define glTexAttachMemoryNV gll_glTexAttachMemoryNV
typedef void (APIENTRYP PFNGLBUFFERATTACHMEMORYNVPROC)(GLenum target, GLuint memory, GLuint64 offset);
#define glBufferAttachMemoryNV gll_glBufferAttachMemoryNV
typedef void (APIENTRYP PFNGLTEXTUREATTACHMEMORYNVPROC)(GLuint texture, GLuint memory, GLuint64 offset);
#define glTextureAttachMemoryNV gll_glTextureAttachMemoryNV
typedef void (APIENTRYP PFNGLNAMEDBUFFERATTACHMEMORYNVPROC)(GLuint buffer, GLuint memory, GLuint64 offset);
#define glNamedBufferAttachMemoryNV gll_glNamedBufferAttachMemoryNV
#endif // GL_EXT_NV_memory_attachment

#if defined(GL_EXT_NV_memory_object_sparse)
typedef void (APIENTRYP PFNGLBUFFERPAGECOMMITMENTMEMNVPROC)(GLenum target, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit);
#define glBufferPageCommitmentMemNV gll_glBufferPageCommitmentMemNV
typedef void (APIENTRYP PFNGLTEXPAGECOMMITMENTMEMNVPROC)(GLenum target, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit);
#define glTexPageCommitmentMemNV gll_glTexPageCommitmentMemNV
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit);
#define glNamedBufferPageCommitmentMemNV gll_glNamedBufferPageCommitmentMemNV
typedef void (APIENTRYP PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC)(GLuint texture, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit);
#define glTexturePageCommitmentMemNV gll_glTexturePageCommitmentMemNV
#endif // GL_EXT_NV_memory_object_sparse

#if defined(GL_EXT_NV_mesh_shader)
#define GL_MESH_SHADER_NV 0x9559
#define GL_TASK_SHADER_NV 0x955A
#define GL_MAX_MESH_UNIFORM_BLOCKS_NV 0x8E60
#define GL_MAX_MESH_TEXTURE_IMAGE_UNITS_NV 0x8E61
#define GL_MAX_MESH_IMAGE_UNIFORMS_NV 0x8E62
#define GL_MAX_MESH_UNIFORM_COMPONENTS_NV 0x8E63
#define GL_MAX_MESH_ATOMIC_COUNTER_BUFFERS_NV 0x8E64
#define GL_MAX_MESH_ATOMIC_COUNTERS_NV 0x8E65
#define GL_MAX_MESH_SHADER_STORAGE_BLOCKS_NV 0x8E66
#define GL_MAX_COMBINED_MESH_UNIFORM_COMPONENTS_NV 0x8E67
#define GL_MAX_TASK_UNIFORM_BLOCKS_NV 0x8E68
#define GL_MAX_TASK_TEXTURE_IMAGE_UNITS_NV 0x8E69
#define GL_MAX_TASK_IMAGE_UNIFORMS_NV 0x8E6A
#define GL_MAX_TASK_UNIFORM_COMPONENTS_NV 0x8E6B
#define GL_MAX_TASK_ATOMIC_COUNTER_BUFFERS_NV 0x8E6C
#define GL_MAX_TASK_ATOMIC_COUNTERS_NV 0x8E6D
#define GL_MAX_TASK_SHADER_STORAGE_BLOCKS_NV 0x8E6E
#define GL_MAX_COMBINED_TASK_UNIFORM_COMPONENTS_NV 0x8E6F
#define GL_MAX_MESH_WORK_GROUP_INVOCATIONS_NV 0x95A2
#define GL_MAX_TASK_WORK_GROUP_INVOCATIONS_NV 0x95A3
#define GL_MAX_MESH_TOTAL_MEMORY_SIZE_NV 0x9536
#define GL_MAX_TASK_TOTAL_MEMORY_SIZE_NV 0x9537
#define GL_MAX_MESH_OUTPUT_VERTICES_NV 0x9538
#define GL_MAX_MESH_OUTPUT_PRIMITIVES_NV 0x9539
#define GL_MAX_TASK_OUTPUT_COUNT_NV 0x953A
#define GL_MAX_DRAW_MESH_TASKS_COUNT_NV 0x953D
#define GL_MAX_MESH_VIEWS_NV 0x9557
#define GL_MESH_OUTPUT_PER_VERTEX_GRANULARITY_NV 0x92DF
#define GL_MESH_OUTPUT_PER_PRIMITIVE_GRANULARITY_NV 0x9543
#define GL_MAX_MESH_WORK_GROUP_SIZE_NV 0x953B
#define GL_MAX_TASK_WORK_GROUP_SIZE_NV 0x953C
#define GL_MESH_WORK_GROUP_SIZE_NV 0x953E
#define GL_TASK_WORK_GROUP_SIZE_NV 0x953F
#define GL_MESH_VERTICES_OUT_NV 0x9579
#define GL_MESH_PRIMITIVES_OUT_NV 0x957A
#define GL_MESH_OUTPUT_TYPE_NV 0x957B
#define GL_UNIFORM_BLOCK_REFERENCED_BY_MESH_SHADER_NV 0x959C
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TASK_SHADER_NV 0x959D
#define GL_REFERENCED_BY_MESH_SHADER_NV 0x95A0
#define GL_REFERENCED_BY_TASK_SHADER_NV 0x95A1
#define GL_MESH_SHADER_BIT_NV 0x00000040
#define GL_TASK_SHADER_BIT_NV 0x00000080
typedef void (APIENTRYP PFNGLDRAWMESHTASKSNVPROC)(GLuint first, GLuint count);
#define glDrawMeshTasksNV gll_glDrawMeshTasksNV
typedef void (APIENTRYP PFNGLDRAWMESHTASKSINDIRECTNVPROC)(GLintptr indirect);
#define glDrawMeshTasksIndirectNV gll_glDrawMeshTasksIndirectNV
typedef void (APIENTRYP PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC)(GLintptr indirect, GLsizei drawcount, GLsizei stride);
#define glMultiDrawMeshTasksIndirectNV gll_glMultiDrawMeshTasksIndirectNV
typedef void (APIENTRYP PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC)(GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#define glMultiDrawMeshTasksIndirectCountNV gll_glMultiDrawMeshTasksIndirectCountNV
#define GL_MESH_SUBROUTINE_NV 0x957C
#define GL_TASK_SUBROUTINE_NV 0x957D
#define GL_MESH_SUBROUTINE_UNIFORM_NV 0x957E
#define GL_TASK_SUBROUTINE_UNIFORM_NV 0x957F
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_MESH_SHADER_NV 0x959E
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TASK_SHADER_NV 0x959F
#endif // GL_EXT_NV_mesh_shader

#if defined(GL_EXT_NV_path_rendering)
#define GL_PATH_FORMAT_SVG_NV 0x9070
#define GL_PATH_FORMAT_PS_NV 0x9071
#define GL_STANDARD_FONT_NAME_NV 0x9072
#define GL_SYSTEM_FONT_NAME_NV 0x9073
#define GL_FILE_NAME_NV 0x9074
#define GL_PATH_STROKE_WIDTH_NV 0x9075
#define GL_PATH_END_CAPS_NV 0x9076
#define GL_PATH_INITIAL_END_CAP_NV 0x9077
#define GL_PATH_TERMINAL_END_CAP_NV 0x9078
#define GL_PATH_JOIN_STYLE_NV 0x9079
#define GL_PATH_MITER_LIMIT_NV 0x907A
#define GL_PATH_DASH_CAPS_NV 0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV 0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV 0x907D
#define GL_PATH_DASH_OFFSET_NV 0x907E
#define GL_PATH_CLIENT_LENGTH_NV 0x907F
#define GL_PATH_FILL_MODE_NV 0x9080
#define GL_PATH_FILL_MASK_NV 0x9081
#define GL_PATH_FILL_COVER_MODE_NV 0x9082
#define GL_PATH_STROKE_COVER_MODE_NV 0x9083
#define GL_PATH_STROKE_MASK_NV 0x9084
#define GL_COUNT_UP_NV 0x9088
#define GL_COUNT_DOWN_NV 0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV 0x908A
#define GL_CONVEX_HULL_NV 0x908B
#define GL_BOUNDING_BOX_NV 0x908D
#define GL_TRANSLATE_X_NV 0x908E
#define GL_TRANSLATE_Y_NV 0x908F
#define GL_TRANSLATE_2D_NV 0x9090
#define GL_TRANSLATE_3D_NV 0x9091
#define GL_AFFINE_2D_NV 0x9092
#define GL_AFFINE_3D_NV 0x9094
#define GL_TRANSPOSE_AFFINE_2D_NV 0x9096
#define GL_TRANSPOSE_AFFINE_3D_NV 0x9098
#define GL_UTF8_NV 0x909A
#define GL_UTF16_NV 0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_PATH_COMMAND_COUNT_NV 0x909D
#define GL_PATH_COORD_COUNT_NV 0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV 0x909F
#define GL_PATH_COMPUTED_LENGTH_NV 0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV 0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV 0x90A2
#define GL_SQUARE_NV 0x90A3
#define GL_ROUND_NV 0x90A4
#define GL_TRIANGULAR_NV 0x90A5
#define GL_BEVEL_NV 0x90A6
#define GL_MITER_REVERT_NV 0x90A7
#define GL_MITER_TRUNCATE_NV 0x90A8
#define GL_SKIP_MISSING_GLYPH_NV 0x90A9
#define GL_USE_MISSING_GLYPH_NV 0x90AA
#define GL_PATH_ERROR_POSITION_NV 0x90AB
#define GL_ACCUM_ADJACENT_PAIRS_NV 0x90AD
#define GL_ADJACENT_PAIRS_NV 0x90AE
#define GL_FIRST_TO_REST_NV 0x90AF
#define GL_PATH_GEN_MODE_NV 0x90B0
#define GL_PATH_GEN_COEFF_NV 0x90B1
#define GL_PATH_GEN_COMPONENTS_NV 0x90B3
#define GL_PATH_STENCIL_FUNC_NV 0x90B7
#define GL_PATH_STENCIL_REF_NV 0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV 0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV 0x90BF
#define GL_PATH_DASH_OFFSET_RESET_NV 0x90B4
#define GL_MOVE_TO_RESETS_NV 0x90B5
#define GL_MOVE_TO_CONTINUES_NV 0x90B6
#define GL_CLOSE_PATH_NV 0x00
#define GL_MOVE_TO_NV 0x02
#define GL_RELATIVE_MOVE_TO_NV 0x03
#define GL_LINE_TO_NV 0x04
#define GL_RELATIVE_LINE_TO_NV 0x05
#define GL_HORIZONTAL_LINE_TO_NV 0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_VERTICAL_LINE_TO_NV 0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV 0x09
#define GL_QUADRATIC_CURVE_TO_NV 0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_CUBIC_CURVE_TO_NV 0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV 0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV 0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_SMALL_CCW_ARC_TO_NV 0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV 0x13
#define GL_SMALL_CW_ARC_TO_NV 0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV 0x15
#define GL_LARGE_CCW_ARC_TO_NV 0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV 0x17
#define GL_LARGE_CW_ARC_TO_NV 0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV 0x19
#define GL_RESTART_PATH_NV 0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV 0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV 0xF4
#define GL_RECT_NV 0xF6
#define GL_CIRCULAR_CCW_ARC_TO_NV 0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV 0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV 0xFC
#define GL_ARC_TO_NV 0xFE
#define GL_RELATIVE_ARC_TO_NV 0xFF
#define GL_BOLD_BIT_NV 0x01
#define GL_ITALIC_BIT_NV 0x02
#define GL_GLYPH_WIDTH_BIT_NV 0x01
#define GL_GLYPH_HEIGHT_BIT_NV 0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_GLYPH_HAS_KERNING_BIT_NV 0x100
#define GL_FONT_X_MIN_BOUNDS_BIT_NV 0x00010000
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV 0x00020000
#define GL_FONT_X_MAX_BOUNDS_BIT_NV 0x00040000
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV 0x00080000
#define GL_FONT_UNITS_PER_EM_BIT_NV 0x00100000
#define GL_FONT_ASCENDER_BIT_NV 0x00200000
#define GL_FONT_DESCENDER_BIT_NV 0x00400000
#define GL_FONT_HEIGHT_BIT_NV 0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV 0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV 0x02000000
#define GL_FONT_UNDERLINE_POSITION_BIT_NV 0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV 0x08000000
#define GL_FONT_HAS_KERNING_BIT_NV 0x10000000
typedef GLuint (APIENTRYP PFNGLGENPATHSNVPROC)(GLsizei range);
#define glGenPathsNV gll_glGenPathsNV
typedef void (APIENTRYP PFNGLDELETEPATHSNVPROC)(GLuint path, GLsizei range);
#define glDeletePathsNV gll_glDeletePathsNV
typedef GLboolean (APIENTRYP PFNGLISPATHNVPROC)(GLuint path);
#define glIsPathNV gll_glIsPathNV
typedef void (APIENTRYP PFNGLPATHCOMMANDSNVPROC)(GLuint path, GLsizei numCommands, const GLubyte * commands, GLsizei numCoords, GLenum coordType, const void * coords);
#define glPathCommandsNV gll_glPathCommandsNV
typedef void (APIENTRYP PFNGLPATHCOORDSNVPROC)(GLuint path, GLsizei numCoords, GLenum coordType, const void * coords);
#define glPathCoordsNV gll_glPathCoordsNV
typedef void (APIENTRYP PFNGLPATHSUBCOMMANDSNVPROC)(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte * commands, GLsizei numCoords, GLenum coordType, const void * coords);
#define glPathSubCommandsNV gll_glPathSubCommandsNV
typedef void (APIENTRYP PFNGLPATHSUBCOORDSNVPROC)(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void * coords);
#define glPathSubCoordsNV gll_glPathSubCoordsNV
typedef void (APIENTRYP PFNGLPATHSTRINGNVPROC)(GLuint path, GLenum format, GLsizei length, const void * pathString);
#define glPathStringNV gll_glPathStringNV
typedef void (APIENTRYP PFNGLPATHGLYPHSNVPROC)(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void * charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
#define glPathGlyphsNV gll_glPathGlyphsNV
typedef void (APIENTRYP PFNGLPATHGLYPHRANGENVPROC)(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
#define glPathGlyphRangeNV gll_glPathGlyphRangeNV
typedef void (APIENTRYP PFNGLWEIGHTPATHSNVPROC)(GLuint resultPath, GLsizei numPaths, const GLuint * paths, const GLfloat * weights);
#define glWeightPathsNV gll_glWeightPathsNV
typedef void (APIENTRYP PFNGLCOPYPATHNVPROC)(GLuint resultPath, GLuint srcPath);
#define glCopyPathNV gll_glCopyPathNV
typedef void (APIENTRYP PFNGLINTERPOLATEPATHSNVPROC)(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
#define glInterpolatePathsNV gll_glInterpolatePathsNV
typedef void (APIENTRYP PFNGLTRANSFORMPATHNVPROC)(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat * transformValues);
#define glTransformPathNV gll_glTransformPathNV
typedef void (APIENTRYP PFNGLPATHPARAMETERIVNVPROC)(GLuint path, GLenum pname, const GLint * value);
#define glPathParameterivNV gll_glPathParameterivNV
typedef void (APIENTRYP PFNGLPATHPARAMETERINVPROC)(GLuint path, GLenum pname, GLint value);
#define glPathParameteriNV gll_glPathParameteriNV
typedef void (APIENTRYP PFNGLPATHPARAMETERFVNVPROC)(GLuint path, GLenum pname, const GLfloat * value);
#define glPathParameterfvNV gll_glPathParameterfvNV
typedef void (APIENTRYP PFNGLPATHPARAMETERFNVPROC)(GLuint path, GLenum pname, GLfloat value);
#define glPathParameterfNV gll_glPathParameterfNV
typedef void (APIENTRYP PFNGLPATHDASHARRAYNVPROC)(GLuint path, GLsizei dashCount, const GLfloat * dashArray);
#define glPathDashArrayNV gll_glPathDashArrayNV
typedef void (APIENTRYP PFNGLPATHSTENCILFUNCNVPROC)(GLenum func, GLint ref, GLuint mask);
#define glPathStencilFuncNV gll_glPathStencilFuncNV
typedef void (APIENTRYP PFNGLPATHSTENCILDEPTHOFFSETNVPROC)(GLfloat factor, GLfloat units);
#define glPathStencilDepthOffsetNV gll_glPathStencilDepthOffsetNV
typedef void (APIENTRYP PFNGLSTENCILFILLPATHNVPROC)(GLuint path, GLenum fillMode, GLuint mask);
#define glStencilFillPathNV gll_glStencilFillPathNV
typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHNVPROC)(GLuint path, GLint reference, GLuint mask);
#define glStencilStrokePathNV gll_glStencilStrokePathNV
typedef void (APIENTRYP PFNGLSTENCILFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat * transformValues);
#define glStencilFillPathInstancedNV gll_glStencilFillPathInstancedNV
typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat * transformValues);
#define glStencilStrokePathInstancedNV gll_glStencilStrokePathInstancedNV
typedef void (APIENTRYP PFNGLPATHCOVERDEPTHFUNCNVPROC)(GLenum func);
#define glPathCoverDepthFuncNV gll_glPathCoverDepthFuncNV
typedef void (APIENTRYP PFNGLCOVERFILLPATHNVPROC)(GLuint path, GLenum coverMode);
#define glCoverFillPathNV gll_glCoverFillPathNV
typedef void (APIENTRYP PFNGLCOVERSTROKEPATHNVPROC)(GLuint path, GLenum coverMode);
#define glCoverStrokePathNV gll_glCoverStrokePathNV
typedef void (APIENTRYP PFNGLCOVERFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
#define glCoverFillPathInstancedNV gll_glCoverFillPathInstancedNV
typedef void (APIENTRYP PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
#define glCoverStrokePathInstancedNV gll_glCoverStrokePathInstancedNV
typedef void (APIENTRYP PFNGLGETPATHPARAMETERIVNVPROC)(GLuint path, GLenum pname, GLint * value);
#define glGetPathParameterivNV gll_glGetPathParameterivNV
typedef void (APIENTRYP PFNGLGETPATHPARAMETERFVNVPROC)(GLuint path, GLenum pname, GLfloat * value);
#define glGetPathParameterfvNV gll_glGetPathParameterfvNV
typedef void (APIENTRYP PFNGLGETPATHCOMMANDSNVPROC)(GLuint path, GLubyte * commands);
#define glGetPathCommandsNV gll_glGetPathCommandsNV
typedef void (APIENTRYP PFNGLGETPATHCOORDSNVPROC)(GLuint path, GLfloat * coords);
#define glGetPathCoordsNV gll_glGetPathCoordsNV
typedef void (APIENTRYP PFNGLGETPATHDASHARRAYNVPROC)(GLuint path, GLfloat * dashArray);
#define glGetPathDashArrayNV gll_glGetPathDashArrayNV
typedef void (APIENTRYP PFNGLGETPATHMETRICSNVPROC)(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLsizei stride, GLfloat * metrics);
#define glGetPathMetricsNV gll_glGetPathMetricsNV
typedef void (APIENTRYP PFNGLGETPATHMETRICRANGENVPROC)(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat * metrics);
#define glGetPathMetricRangeNV gll_glGetPathMetricRangeNV
typedef void (APIENTRYP PFNGLGETPATHSPACINGNVPROC)(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat * returnedSpacing);
#define glGetPathSpacingNV gll_glGetPathSpacingNV
typedef GLboolean (APIENTRYP PFNGLISPOINTINFILLPATHNVPROC)(GLuint path, GLuint mask, GLfloat x, GLfloat y);
#define glIsPointInFillPathNV gll_glIsPointInFillPathNV
typedef GLboolean (APIENTRYP PFNGLISPOINTINSTROKEPATHNVPROC)(GLuint path, GLfloat x, GLfloat y);
#define glIsPointInStrokePathNV gll_glIsPointInStrokePathNV
typedef GLfloat (APIENTRYP PFNGLGETPATHLENGTHNVPROC)(GLuint path, GLsizei startSegment, GLsizei numSegments);
#define glGetPathLengthNV gll_glGetPathLengthNV
typedef GLboolean (APIENTRYP PFNGLPOINTALONGPATHNVPROC)(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat * x, GLfloat * y, GLfloat * tangentX, GLfloat * tangentY);
#define glPointAlongPathNV gll_glPointAlongPathNV
#define GL_ROUNDED_RECT_NV 0xE8
#define GL_RELATIVE_ROUNDED_RECT_NV 0xE9
#define GL_ROUNDED_RECT2_NV 0xEA
#define GL_RELATIVE_ROUNDED_RECT2_NV 0xEB
#define GL_ROUNDED_RECT4_NV 0xEC
#define GL_RELATIVE_ROUNDED_RECT4_NV 0xED
#define GL_ROUNDED_RECT8_NV 0xEE
#define GL_RELATIVE_ROUNDED_RECT8_NV 0xEF
#define GL_RELATIVE_RECT_NV 0xF7
#define GL_FONT_GLYPHS_AVAILABLE_NV 0x9368
#define GL_FONT_TARGET_UNAVAILABLE_NV 0x9369
#define GL_FONT_UNAVAILABLE_NV 0x936A
#define GL_FONT_UNINTELLIGIBLE_NV 0x936B
typedef void (APIENTRYP PFNGLMATRIXLOAD3X2FNVPROC)(GLenum matrixMode, const GLfloat * m);
#define glMatrixLoad3x2fNV gll_glMatrixLoad3x2fNV
typedef void (APIENTRYP PFNGLMATRIXLOAD3X3FNVPROC)(GLenum matrixMode, const GLfloat * m);
#define glMatrixLoad3x3fNV gll_glMatrixLoad3x3fNV
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC)(GLenum matrixMode, const GLfloat * m);
#define glMatrixLoadTranspose3x3fNV gll_glMatrixLoadTranspose3x3fNV
typedef void (APIENTRYP PFNGLMATRIXMULT3X2FNVPROC)(GLenum matrixMode, const GLfloat * m);
#define glMatrixMult3x2fNV gll_glMatrixMult3x2fNV
typedef void (APIENTRYP PFNGLMATRIXMULT3X3FNVPROC)(GLenum matrixMode, const GLfloat * m);
#define glMatrixMult3x3fNV gll_glMatrixMult3x3fNV
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC)(GLenum matrixMode, const GLfloat * m);
#define glMatrixMultTranspose3x3fNV gll_glMatrixMultTranspose3x3fNV
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHNVPROC)(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
#define glStencilThenCoverFillPathNV gll_glStencilThenCoverFillPathNV
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC)(GLuint path, GLint reference, GLuint mask, GLenum coverMode);
#define glStencilThenCoverStrokePathNV gll_glStencilThenCoverStrokePathNV
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
#define glStencilThenCoverFillPathInstancedNV gll_glStencilThenCoverFillPathInstancedNV
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC)(GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat * transformValues);
#define glStencilThenCoverStrokePathInstancedNV gll_glStencilThenCoverStrokePathInstancedNV
typedef GLenum (APIENTRYP PFNGLPATHGLYPHINDEXRANGENVPROC)(GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint * baseAndCount);
#define glPathGlyphIndexRangeNV gll_glPathGlyphIndexRangeNV
#define GL_CONIC_CURVE_TO_NV 0x1A
#define GL_RELATIVE_CONIC_CURVE_TO_NV 0x1B
#define GL_FONT_NUM_GLYPH_INDICES_BIT_NV 0x20000000
#define GL_STANDARD_FONT_FORMAT_NV 0x936C
typedef GLenum (APIENTRYP PFNGLPATHGLYPHINDEXARRAYNVPROC)(GLuint firstPathName, GLenum fontTarget, const void * fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
#define glPathGlyphIndexArrayNV gll_glPathGlyphIndexArrayNV
typedef GLenum (APIENTRYP PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC)(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void * fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
#define glPathMemoryGlyphIndexArrayNV gll_glPathMemoryGlyphIndexArrayNV
typedef void (APIENTRYP PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC)(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat * coeffs);
#define glProgramPathFragmentInputGenNV gll_glProgramPathFragmentInputGenNV
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEFVNVPROC)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLfloat * params);
#define glGetProgramResourcefvNV gll_glGetProgramResourcefvNV
#define GL_2_BYTES_NV 0x1407
#define GL_3_BYTES_NV 0x1408
#define GL_4_BYTES_NV 0x1409
#define GL_EYE_LINEAR_NV 0x2400
#define GL_OBJECT_LINEAR_NV 0x2401
#define GL_CONSTANT_NV 0x8576
#define GL_PATH_FOG_GEN_MODE_NV 0x90AC
#define GL_PRIMARY_COLOR_NV 0x852C
#define GL_SECONDARY_COLOR_NV 0x852D
#define GL_PATH_GEN_COLOR_FORMAT_NV 0x90B2
typedef void (APIENTRYP PFNGLPATHCOLORGENNVPROC)(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat * coeffs);
#define glPathColorGenNV gll_glPathColorGenNV
typedef void (APIENTRYP PFNGLPATHTEXGENNVPROC)(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat * coeffs);
#define glPathTexGenNV gll_glPathTexGenNV
typedef void (APIENTRYP PFNGLPATHFOGGENNVPROC)(GLenum genMode);
#define glPathFogGenNV gll_glPathFogGenNV
typedef void (APIENTRYP PFNGLGETPATHCOLORGENIVNVPROC)(GLenum color, GLenum pname, GLint * value);
#define glGetPathColorGenivNV gll_glGetPathColorGenivNV
typedef void (APIENTRYP PFNGLGETPATHCOLORGENFVNVPROC)(GLenum color, GLenum pname, GLfloat * value);
#define glGetPathColorGenfvNV gll_glGetPathColorGenfvNV
typedef void (APIENTRYP PFNGLGETPATHTEXGENIVNVPROC)(GLenum texCoordSet, GLenum pname, GLint * value);
#define glGetPathTexGenivNV gll_glGetPathTexGenivNV
typedef void (APIENTRYP PFNGLGETPATHTEXGENFVNVPROC)(GLenum texCoordSet, GLenum pname, GLfloat * value);
#define glGetPathTexGenfvNV gll_glGetPathTexGenfvNV
#define GL_PATH_PROJECTION_NV 0x1701
#define GL_PATH_MODELVIEW_NV 0x1700
#define GL_PATH_MODELVIEW_STACK_DEPTH_NV 0x0BA3
#define GL_PATH_MODELVIEW_MATRIX_NV 0x0BA6
#define GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV 0x0D36
#define GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV 0x84E3
#define GL_PATH_PROJECTION_STACK_DEPTH_NV 0x0BA4
#define GL_PATH_PROJECTION_MATRIX_NV 0x0BA7
#define GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV 0x0D38
#define GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV 0x84E4
#define GL_FRAGMENT_INPUT_NV 0x936D
typedef void (APIENTRYP PFNGLMATRIXFRUSTUMEXTPROC)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glMatrixFrustumEXT gll_glMatrixFrustumEXT
typedef void (APIENTRYP PFNGLMATRIXLOADIDENTITYEXTPROC)(GLenum mode);
#define glMatrixLoadIdentityEXT gll_glMatrixLoadIdentityEXT
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat * m);
#define glMatrixLoadTransposefEXT gll_glMatrixLoadTransposefEXT
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble * m);
#define glMatrixLoadTransposedEXT gll_glMatrixLoadTransposedEXT
typedef void (APIENTRYP PFNGLMATRIXLOADFEXTPROC)(GLenum mode, const GLfloat * m);
#define glMatrixLoadfEXT gll_glMatrixLoadfEXT
typedef void (APIENTRYP PFNGLMATRIXLOADDEXTPROC)(GLenum mode, const GLdouble * m);
#define glMatrixLoaddEXT gll_glMatrixLoaddEXT
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEFEXTPROC)(GLenum mode, const GLfloat * m);
#define glMatrixMultTransposefEXT gll_glMatrixMultTransposefEXT
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEDEXTPROC)(GLenum mode, const GLdouble * m);
#define glMatrixMultTransposedEXT gll_glMatrixMultTransposedEXT
typedef void (APIENTRYP PFNGLMATRIXMULTFEXTPROC)(GLenum mode, const GLfloat * m);
#define glMatrixMultfEXT gll_glMatrixMultfEXT
typedef void (APIENTRYP PFNGLMATRIXMULTDEXTPROC)(GLenum mode, const GLdouble * m);
#define glMatrixMultdEXT gll_glMatrixMultdEXT
typedef void (APIENTRYP PFNGLMATRIXORTHOEXTPROC)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glMatrixOrthoEXT gll_glMatrixOrthoEXT
typedef void (APIENTRYP PFNGLMATRIXPOPEXTPROC)(GLenum mode);
#define glMatrixPopEXT gll_glMatrixPopEXT
typedef void (APIENTRYP PFNGLMATRIXPUSHEXTPROC)(GLenum mode);
#define glMatrixPushEXT gll_glMatrixPushEXT
typedef void (APIENTRYP PFNGLMATRIXROTATEFEXTPROC)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
#define glMatrixRotatefEXT gll_glMatrixRotatefEXT
typedef void (APIENTRYP PFNGLMATRIXROTATEDEXTPROC)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
#define glMatrixRotatedEXT gll_glMatrixRotatedEXT
typedef void (APIENTRYP PFNGLMATRIXSCALEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
#define glMatrixScalefEXT gll_glMatrixScalefEXT
typedef void (APIENTRYP PFNGLMATRIXSCALEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
#define glMatrixScaledEXT gll_glMatrixScaledEXT
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEFEXTPROC)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
#define glMatrixTranslatefEXT gll_glMatrixTranslatefEXT
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEDEXTPROC)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
#define glMatrixTranslatedEXT gll_glMatrixTranslatedEXT
#endif // GL_EXT_NV_path_rendering

#if defined(GL_EXT_NV_path_rendering_shared_edge)
#define GL_SHARED_EDGE_NV 0xC0
#endif // GL_EXT_NV_path_rendering_shared_edge

#if defined(GL_EXT_NV_primitive_shading_rate)
#define GL_SHADING_RATE_IMAGE_PER_PRIMITIVE_NV 0x95B1
#define GL_SHADING_RATE_IMAGE_PALETTE_COUNT_NV 0x95B2
#endif // GL_EXT_NV_primitive_shading_rate

#if defined(GL_EXT_NV_representative_fragment_test)
#define GL_REPRESENTATIVE_FRAGMENT_TEST_NV 0x937F
#endif // GL_EXT_NV_representative_fragment_test

#if defined(GL_EXT_NV_sample_locations)
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_NV 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_NV 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_NV 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_NV 0x9340
#define GL_SAMPLE_LOCATION_NV 0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_NV 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_NV 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_NV 0x9343
typedef void (APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)(GLenum target, GLuint start, GLsizei count, const GLfloat * v);
#define glFramebufferSampleLocationsfvNV gll_glFramebufferSampleLocationsfvNV
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat * v);
#define glNamedFramebufferSampleLocationsfvNV gll_glNamedFramebufferSampleLocationsfvNV
typedef void (APIENTRYP PFNGLRESOLVEDEPTHVALUESNVPROC)(void);
#define glResolveDepthValuesNV gll_glResolveDepthValuesNV
#endif // GL_EXT_NV_sample_locations

#if defined(GL_EXT_NV_scissor_exclusive)
#define GL_SCISSOR_TEST_EXCLUSIVE_NV 0x9555
#define GL_SCISSOR_BOX_EXCLUSIVE_NV 0x9556
typedef void (APIENTRYP PFNGLSCISSOREXCLUSIVENVPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
#define glScissorExclusiveNV gll_glScissorExclusiveNV
typedef void (APIENTRYP PFNGLSCISSOREXCLUSIVEARRAYVNVPROC)(GLuint first, GLsizei count, const GLint * v);
#define glScissorExclusiveArrayvNV gll_glScissorExclusiveArrayvNV
#endif // GL_EXT_NV_scissor_exclusive

#if defined(GL_EXT_NV_shader_buffer_load)
#define GL_BUFFER_GPU_ADDRESS_NV 0x8F1D
#define GL_GPU_ADDRESS_NV 0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV 0x8F35
typedef void (APIENTRYP PFNGLMAKEBUFFERRESIDENTNVPROC)(GLenum target, GLenum access);
#define glMakeBufferResidentNV gll_glMakeBufferResidentNV
typedef void (APIENTRYP PFNGLMAKEBUFFERNONRESIDENTNVPROC)(GLenum target);
#define glMakeBufferNonResidentNV gll_glMakeBufferNonResidentNV
typedef GLboolean (APIENTRYP PFNGLISBUFFERRESIDENTNVPROC)(GLenum target);
#define glIsBufferResidentNV gll_glIsBufferResidentNV
typedef void (APIENTRYP PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)(GLuint buffer, GLenum access);
#define glMakeNamedBufferResidentNV gll_glMakeNamedBufferResidentNV
typedef void (APIENTRYP PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)(GLuint buffer);
#define glMakeNamedBufferNonResidentNV gll_glMakeNamedBufferNonResidentNV
typedef GLboolean (APIENTRYP PFNGLISNAMEDBUFFERRESIDENTNVPROC)(GLuint buffer);
#define glIsNamedBufferResidentNV gll_glIsNamedBufferResidentNV
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERUI64VNVPROC)(GLenum target, GLenum pname, GLuint64EXT * params);
#define glGetBufferParameterui64vNV gll_glGetBufferParameterui64vNV
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)(GLuint buffer, GLenum pname, GLuint64EXT * params);
#define glGetNamedBufferParameterui64vNV gll_glGetNamedBufferParameterui64vNV
typedef void (APIENTRYP PFNGLGETINTEGERUI64VNVPROC)(GLenum value, GLuint64EXT * result);
#define glGetIntegerui64vNV gll_glGetIntegerui64vNV
typedef void (APIENTRYP PFNGLUNIFORMUI64NVPROC)(GLint location, GLuint64EXT value);
#define glUniformui64NV gll_glUniformui64NV
typedef void (APIENTRYP PFNGLUNIFORMUI64VNVPROC)(GLint location, GLsizei count, const GLuint64EXT * value);
#define glUniformui64vNV gll_glUniformui64vNV
typedef void (APIENTRYP PFNGLGETUNIFORMUI64VNVPROC)(GLuint program, GLint location, GLuint64EXT * params);
#define glGetUniformui64vNV gll_glGetUniformui64vNV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMUI64NVPROC)(GLuint program, GLint location, GLuint64EXT value);
#define glProgramUniformui64NV gll_glProgramUniformui64NV
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMUI64VNVPROC)(GLuint program, GLint location, GLsizei count, const GLuint64EXT * value);
#define glProgramUniformui64vNV gll_glProgramUniformui64vNV
#endif // GL_EXT_NV_shader_buffer_load

#if defined(GL_EXT_NV_shader_buffer_store)
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV 0x00000010
#endif // GL_EXT_NV_shader_buffer_store

#if defined(GL_EXT_NV_shader_subgroup_partitioned)
#define GL_SUBGROUP_FEATURE_PARTITIONED_BIT_NV 0x00000100
#endif // GL_EXT_NV_shader_subgroup_partitioned

#if defined(GL_EXT_NV_shader_thread_group)
#define GL_WARP_SIZE_NV 0x9339
#define GL_WARPS_PER_SM_NV 0x933A
#define GL_SM_COUNT_NV 0x933B
#endif // GL_EXT_NV_shader_thread_group

#if defined(GL_EXT_NV_shading_rate_image)
#define GL_SHADING_RATE_IMAGE_NV 0x9563
#define GL_SHADING_RATE_NO_INVOCATIONS_NV 0x9564
#define GL_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV 0x9565
#define GL_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV 0x9566
#define GL_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV 0x9567
#define GL_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV 0x9568
#define GL_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV 0x9569
#define GL_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV 0x956A
#define GL_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV 0x956B
#define GL_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV 0x956C
#define GL_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV 0x956D
#define GL_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV 0x956E
#define GL_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV 0x956F
#define GL_SHADING_RATE_IMAGE_BINDING_NV 0x955B
#define GL_SHADING_RATE_IMAGE_TEXEL_WIDTH_NV 0x955C
#define GL_SHADING_RATE_IMAGE_TEXEL_HEIGHT_NV 0x955D
#define GL_SHADING_RATE_IMAGE_PALETTE_SIZE_NV 0x955E
#define GL_MAX_COARSE_FRAGMENT_SAMPLES_NV 0x955F
#define GL_SHADING_RATE_SAMPLE_ORDER_DEFAULT_NV 0x95AE
#define GL_SHADING_RATE_SAMPLE_ORDER_PIXEL_MAJOR_NV 0x95AF
#define GL_SHADING_RATE_SAMPLE_ORDER_SAMPLE_MAJOR_NV 0x95B0
typedef void (APIENTRYP PFNGLBINDSHADINGRATEIMAGENVPROC)(GLuint texture);
#define glBindShadingRateImageNV gll_glBindShadingRateImageNV
typedef void (APIENTRYP PFNGLGETSHADINGRATEIMAGEPALETTENVPROC)(GLuint viewport, GLuint entry, GLenum * rate);
#define glGetShadingRateImagePaletteNV gll_glGetShadingRateImagePaletteNV
typedef void (APIENTRYP PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC)(GLenum rate, GLuint samples, GLuint index, GLint * location);
#define glGetShadingRateSampleLocationivNV gll_glGetShadingRateSampleLocationivNV
typedef void (APIENTRYP PFNGLSHADINGRATEIMAGEBARRIERNVPROC)(GLboolean synchronize);
#define glShadingRateImageBarrierNV gll_glShadingRateImageBarrierNV
typedef void (APIENTRYP PFNGLSHADINGRATEIMAGEPALETTENVPROC)(GLuint viewport, GLuint first, GLsizei count, const GLenum * rates);
#define glShadingRateImagePaletteNV gll_glShadingRateImagePaletteNV
typedef void (APIENTRYP PFNGLSHADINGRATESAMPLEORDERNVPROC)(GLenum order);
#define glShadingRateSampleOrderNV gll_glShadingRateSampleOrderNV
typedef void (APIENTRYP PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC)(GLenum rate, GLuint samples, const GLint * locations);
#define glShadingRateSampleOrderCustomNV gll_glShadingRateSampleOrderCustomNV
#endif // GL_EXT_NV_shading_rate_image

#if defined(GL_EXT_NV_texture_barrier)
typedef void (APIENTRYP PFNGLTEXTUREBARRIERNVPROC)(void);
#define glTextureBarrierNV gll_glTextureBarrierNV
#endif // GL_EXT_NV_texture_barrier

#if defined(GL_EXT_NV_uniform_buffer_unified_memory)
#define GL_UNIFORM_BUFFER_UNIFIED_NV 0x936E
#define GL_UNIFORM_BUFFER_ADDRESS_NV 0x936F
#define GL_UNIFORM_BUFFER_LENGTH_NV 0x9370
#endif // GL_EXT_NV_uniform_buffer_unified_memory

#if defined(GL_EXT_NV_vertex_attrib_integer_64bit)
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1I64NVPROC)(GLuint index, GLint64EXT x);
#define glVertexAttribL1i64NV gll_glVertexAttribL1i64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y);
#define glVertexAttribL2i64NV gll_glVertexAttribL2i64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
#define glVertexAttribL3i64NV gll_glVertexAttribL3i64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4I64NVPROC)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
#define glVertexAttribL4i64NV gll_glVertexAttribL4i64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1I64VNVPROC)(GLuint index, const GLint64EXT * v);
#define glVertexAttribL1i64vNV gll_glVertexAttribL1i64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2I64VNVPROC)(GLuint index, const GLint64EXT * v);
#define glVertexAttribL2i64vNV gll_glVertexAttribL2i64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3I64VNVPROC)(GLuint index, const GLint64EXT * v);
#define glVertexAttribL3i64vNV gll_glVertexAttribL3i64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4I64VNVPROC)(GLuint index, const GLint64EXT * v);
#define glVertexAttribL4i64vNV gll_glVertexAttribL4i64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64NVPROC)(GLuint index, GLuint64EXT x);
#define glVertexAttribL1ui64NV gll_glVertexAttribL1ui64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y);
#define glVertexAttribL2ui64NV gll_glVertexAttribL2ui64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
#define glVertexAttribL3ui64NV gll_glVertexAttribL3ui64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4UI64NVPROC)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
#define glVertexAttribL4ui64NV gll_glVertexAttribL4ui64NV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VNVPROC)(GLuint index, const GLuint64EXT * v);
#define glVertexAttribL1ui64vNV gll_glVertexAttribL1ui64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2UI64VNVPROC)(GLuint index, const GLuint64EXT * v);
#define glVertexAttribL2ui64vNV gll_glVertexAttribL2ui64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3UI64VNVPROC)(GLuint index, const GLuint64EXT * v);
#define glVertexAttribL3ui64vNV gll_glVertexAttribL3ui64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4UI64VNVPROC)(GLuint index, const GLuint64EXT * v);
#define glVertexAttribL4ui64vNV gll_glVertexAttribL4ui64vNV
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLI64VNVPROC)(GLuint index, GLenum pname, GLint64EXT * params);
#define glGetVertexAttribLi64vNV gll_glGetVertexAttribLi64vNV
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VNVPROC)(GLuint index, GLenum pname, GLuint64EXT * params);
#define glGetVertexAttribLui64vNV gll_glGetVertexAttribLui64vNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLsizei stride);
#define glVertexAttribLFormatNV gll_glVertexAttribLFormatNV
#endif // GL_EXT_NV_vertex_attrib_integer_64bit

#if defined(GL_EXT_NV_vertex_buffer_unified_memory)
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV 0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV 0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV 0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV 0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV 0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV 0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV 0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV 0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV 0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV 0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV 0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV 0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV 0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV 0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV 0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV 0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV 0x8F33
#define GL_DRAW_INDIRECT_UNIFIED_NV 0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV 0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV 0x8F42
typedef void (APIENTRYP PFNGLBUFFERADDRESSRANGENVPROC)(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
#define glBufferAddressRangeNV gll_glBufferAddressRangeNV
typedef void (APIENTRYP PFNGLVERTEXFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
#define glVertexFormatNV gll_glVertexFormatNV
typedef void (APIENTRYP PFNGLNORMALFORMATNVPROC)(GLenum type, GLsizei stride);
#define glNormalFormatNV gll_glNormalFormatNV
typedef void (APIENTRYP PFNGLCOLORFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
#define glColorFormatNV gll_glColorFormatNV
typedef void (APIENTRYP PFNGLINDEXFORMATNVPROC)(GLenum type, GLsizei stride);
#define glIndexFormatNV gll_glIndexFormatNV
typedef void (APIENTRYP PFNGLTEXCOORDFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
#define glTexCoordFormatNV gll_glTexCoordFormatNV
typedef void (APIENTRYP PFNGLEDGEFLAGFORMATNVPROC)(GLsizei stride);
#define glEdgeFlagFormatNV gll_glEdgeFlagFormatNV
typedef void (APIENTRYP PFNGLSECONDARYCOLORFORMATNVPROC)(GLint size, GLenum type, GLsizei stride);
#define glSecondaryColorFormatNV gll_glSecondaryColorFormatNV
typedef void (APIENTRYP PFNGLFOGCOORDFORMATNVPROC)(GLenum type, GLsizei stride);
#define glFogCoordFormatNV gll_glFogCoordFormatNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
#define glVertexAttribFormatNV gll_glVertexAttribFormatNV
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATNVPROC)(GLuint index, GLint size, GLenum type, GLsizei stride);
#define glVertexAttribIFormatNV gll_glVertexAttribIFormatNV
typedef void (APIENTRYP PFNGLGETINTEGERUI64I_VNVPROC)(GLenum value, GLuint index, GLuint64EXT * result);
#define glGetIntegerui64i_vNV gll_glGetIntegerui64i_vNV
#endif // GL_EXT_NV_vertex_buffer_unified_memory

#if defined(GL_EXT_NV_viewport_swizzle)
#define GL_VIEWPORT_SWIZZLE_POSITIVE_X_NV 0x9350
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_X_NV 0x9351
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Y_NV 0x9352
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Y_NV 0x9353
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Z_NV 0x9354
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Z_NV 0x9355
#define GL_VIEWPORT_SWIZZLE_POSITIVE_W_NV 0x9356
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_W_NV 0x9357
#define GL_VIEWPORT_SWIZZLE_X_NV 0x9358
#define GL_VIEWPORT_SWIZZLE_Y_NV 0x9359
#define GL_VIEWPORT_SWIZZLE_Z_NV 0x935A
#define GL_VIEWPORT_SWIZZLE_W_NV 0x935B
typedef void (APIENTRYP PFNGLVIEWPORTSWIZZLENVPROC)(GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
#define glViewportSwizzleNV gll_glViewportSwizzleNV
#endif // GL_EXT_NV_viewport_swizzle

#if defined(GL_EXT_OVR_multiview)
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR 0x9630
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR 0x9632
#define GL_MAX_VIEWS_OVR 0x9631
#define GL_FRAMEBUFFER_INCOMPLETE_VIEW_TARGETS_OVR 0x9633
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
#define glFramebufferTextureMultiviewOVR gll_glFramebufferTextureMultiviewOVR
#endif // GL_EXT_OVR_multiview

#define GL_AMD_framebuffer_multisample_advanced_FUNCTIONS \
	X(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC, glRenderbufferStorageMultisampleAdvancedAMD) \
	X(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC, glNamedRenderbufferStorageMultisampleAdvancedAMD) \

#define GL_AMD_performance_monitor_FUNCTIONS \
	X(PFNGLGETPERFMONITORGROUPSAMDPROC, glGetPerfMonitorGroupsAMD) \
	X(PFNGLGETPERFMONITORCOUNTERSAMDPROC, glGetPerfMonitorCountersAMD) \
	X(PFNGLGETPERFMONITORGROUPSTRINGAMDPROC, glGetPerfMonitorGroupStringAMD) \
	X(PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC, glGetPerfMonitorCounterStringAMD) \
	X(PFNGLGETPERFMONITORCOUNTERINFOAMDPROC, glGetPerfMonitorCounterInfoAMD) \
	X(PFNGLGENPERFMONITORSAMDPROC, glGenPerfMonitorsAMD) \
	X(PFNGLDELETEPERFMONITORSAMDPROC, glDeletePerfMonitorsAMD) \
	X(PFNGLSELECTPERFMONITORCOUNTERSAMDPROC, glSelectPerfMonitorCountersAMD) \
	X(PFNGLBEGINPERFMONITORAMDPROC, glBeginPerfMonitorAMD) \
	X(PFNGLENDPERFMONITORAMDPROC, glEndPerfMonitorAMD) \
	X(PFNGLGETPERFMONITORCOUNTERDATAAMDPROC, glGetPerfMonitorCounterDataAMD) \

#define GL_APPLE_rgb_422_FUNCTIONS \

#define GL_ARB_ES2_compatibility_FUNCTIONS \
	X(PFNGLRELEASESHADERCOMPILERPROC, glReleaseShaderCompiler) \
	X(PFNGLSHADERBINARYPROC, glShaderBinary) \
	X(PFNGLGETSHADERPRECISIONFORMATPROC, glGetShaderPrecisionFormat) \
	X(PFNGLDEPTHRANGEFPROC, glDepthRangef) \
	X(PFNGLCLEARDEPTHFPROC, glClearDepthf) \

#define GL_ARB_ES3_1_compatibility_FUNCTIONS \
	X(PFNGLMEMORYBARRIERBYREGIONPROC, glMemoryBarrierByRegion) \

#define GL_ARB_ES3_2_compatibility_FUNCTIONS \
	X(PFNGLPRIMITIVEBOUNDINGBOXARBPROC, glPrimitiveBoundingBoxARB) \

#define GL_ARB_ES3_compatibility_FUNCTIONS \

#define GL_ARB_base_instance_FUNCTIONS \
	X(PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC, glDrawArraysInstancedBaseInstance) \
	X(PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC, glDrawElementsInstancedBaseInstance) \
	X(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC, glDrawElementsInstancedBaseVertexBaseInstance) \

#define GL_ARB_bindless_texture_FUNCTIONS \
	X(PFNGLGETTEXTUREHANDLEARBPROC, glGetTextureHandleARB) \
	X(PFNGLGETTEXTURESAMPLERHANDLEARBPROC, glGetTextureSamplerHandleARB) \
	X(PFNGLMAKETEXTUREHANDLERESIDENTARBPROC, glMakeTextureHandleResidentARB) \
	X(PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC, glMakeTextureHandleNonResidentARB) \
	X(PFNGLGETIMAGEHANDLEARBPROC, glGetImageHandleARB) \
	X(PFNGLMAKEIMAGEHANDLERESIDENTARBPROC, glMakeImageHandleResidentARB) \
	X(PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC, glMakeImageHandleNonResidentARB) \
	X(PFNGLUNIFORMHANDLEUI64ARBPROC, glUniformHandleui64ARB) \
	X(PFNGLUNIFORMHANDLEUI64VARBPROC, glUniformHandleui64vARB) \
	X(PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC, glProgramUniformHandleui64ARB) \
	X(PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC, glProgramUniformHandleui64vARB) \
	X(PFNGLISTEXTUREHANDLERESIDENTARBPROC, glIsTextureHandleResidentARB) \
	X(PFNGLISIMAGEHANDLERESIDENTARBPROC, glIsImageHandleResidentARB) \
	X(PFNGLVERTEXATTRIBL1UI64ARBPROC, glVertexAttribL1ui64ARB) \
	X(PFNGLVERTEXATTRIBL1UI64VARBPROC, glVertexAttribL1ui64vARB) \
	X(PFNGLGETVERTEXATTRIBLUI64VARBPROC, glGetVertexAttribLui64vARB) \

#define GL_ARB_blend_func_extended_FUNCTIONS \
	X(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC, glBindFragDataLocationIndexed) \
	X(PFNGLGETFRAGDATAINDEXPROC, glGetFragDataIndex) \

#define GL_ARB_buffer_storage_FUNCTIONS \
	X(PFNGLBUFFERSTORAGEPROC, glBufferStorage) \

#define GL_ARB_cl_event_FUNCTIONS \
	X(PFNGLCREATESYNCFROMCLEVENTARBPROC, glCreateSyncFromCLeventARB) \

#define GL_ARB_clear_buffer_object_FUNCTIONS \
	X(PFNGLCLEARBUFFERDATAPROC, glClearBufferData) \
	X(PFNGLCLEARBUFFERSUBDATAPROC, glClearBufferSubData) \

#define GL_ARB_clear_texture_FUNCTIONS \
	X(PFNGLCLEARTEXIMAGEPROC, glClearTexImage) \
	X(PFNGLCLEARTEXSUBIMAGEPROC, glClearTexSubImage) \

#define GL_ARB_clip_control_FUNCTIONS \
	X(PFNGLCLIPCONTROLPROC, glClipControl) \

#define GL_ARB_compressed_texture_pixel_storage_FUNCTIONS \

#define GL_ARB_compute_shader_FUNCTIONS \
	X(PFNGLDISPATCHCOMPUTEPROC, glDispatchCompute) \
	X(PFNGLDISPATCHCOMPUTEINDIRECTPROC, glDispatchComputeIndirect) \

#define GL_ARB_compute_variable_group_size_FUNCTIONS \
	X(PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC, glDispatchComputeGroupSizeARB) \

#define GL_ARB_conditional_render_inverted_FUNCTIONS \

#define GL_ARB_copy_buffer_FUNCTIONS \
	X(PFNGLCOPYBUFFERSUBDATAPROC, glCopyBufferSubData) \

#define GL_ARB_copy_image_FUNCTIONS \
	X(PFNGLCOPYIMAGESUBDATAPROC, glCopyImageSubData) \

#define GL_ARB_cull_distance_FUNCTIONS \

#define GL_ARB_debug_output_FUNCTIONS \
	X(PFNGLDEBUGMESSAGECONTROLARBPROC, glDebugMessageControlARB) \
	X(PFNGLDEBUGMESSAGEINSERTARBPROC, glDebugMessageInsertARB) \
	X(PFNGLDEBUGMESSAGECALLBACKARBPROC, glDebugMessageCallbackARB) \
	X(PFNGLGETDEBUGMESSAGELOGARBPROC, glGetDebugMessageLogARB) \

#define GL_ARB_depth_buffer_float_FUNCTIONS \

#define GL_ARB_depth_clamp_FUNCTIONS \

#define GL_ARB_direct_state_access_FUNCTIONS \
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

#define GL_ARB_draw_buffers_blend_FUNCTIONS \
	X(PFNGLBLENDEQUATIONIARBPROC, glBlendEquationiARB) \
	X(PFNGLBLENDEQUATIONSEPARATEIARBPROC, glBlendEquationSeparateiARB) \
	X(PFNGLBLENDFUNCIARBPROC, glBlendFunciARB) \
	X(PFNGLBLENDFUNCSEPARATEIARBPROC, glBlendFuncSeparateiARB) \

#define GL_ARB_draw_elements_base_vertex_FUNCTIONS \
	X(PFNGLDRAWELEMENTSBASEVERTEXPROC, glDrawElementsBaseVertex) \
	X(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC, glDrawRangeElementsBaseVertex) \
	X(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, glDrawElementsInstancedBaseVertex) \
	X(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC, glMultiDrawElementsBaseVertex) \

#define GL_ARB_draw_indirect_FUNCTIONS \
	X(PFNGLDRAWARRAYSINDIRECTPROC, glDrawArraysIndirect) \
	X(PFNGLDRAWELEMENTSINDIRECTPROC, glDrawElementsIndirect) \

#define GL_ARB_draw_instanced_FUNCTIONS \
	X(PFNGLDRAWARRAYSINSTANCEDARBPROC, glDrawArraysInstancedARB) \
	X(PFNGLDRAWELEMENTSINSTANCEDARBPROC, glDrawElementsInstancedARB) \

#define GL_ARB_enhanced_layouts_FUNCTIONS \

#define GL_ARB_explicit_uniform_location_FUNCTIONS \

#define GL_ARB_framebuffer_no_attachments_FUNCTIONS \
	X(PFNGLFRAMEBUFFERPARAMETERIPROC, glFramebufferParameteri) \
	X(PFNGLGETFRAMEBUFFERPARAMETERIVPROC, glGetFramebufferParameteriv) \

#define GL_ARB_framebuffer_object_FUNCTIONS \
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

#define GL_ARB_framebuffer_sRGB_FUNCTIONS \

#define GL_ARB_geometry_shader4_FUNCTIONS \
	X(PFNGLPROGRAMPARAMETERIARBPROC, glProgramParameteriARB) \
	X(PFNGLFRAMEBUFFERTEXTUREARBPROC, glFramebufferTextureARB) \
	X(PFNGLFRAMEBUFFERTEXTURELAYERARBPROC, glFramebufferTextureLayerARB) \
	X(PFNGLFRAMEBUFFERTEXTUREFACEARBPROC, glFramebufferTextureFaceARB) \

#define GL_ARB_get_program_binary_FUNCTIONS \
	X(PFNGLGETPROGRAMBINARYPROC, glGetProgramBinary) \
	X(PFNGLPROGRAMBINARYPROC, glProgramBinary) \
	X(PFNGLPROGRAMPARAMETERIPROC, glProgramParameteri) \

#define GL_ARB_get_texture_sub_image_FUNCTIONS \
	X(PFNGLGETTEXTURESUBIMAGEPROC, glGetTextureSubImage) \
	X(PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC, glGetCompressedTextureSubImage) \

#define GL_ARB_gl_spirv_FUNCTIONS \
	X(PFNGLSPECIALIZESHADERARBPROC, glSpecializeShaderARB) \

#define GL_ARB_gpu_shader5_FUNCTIONS \

#define GL_ARB_gpu_shader_fp64_FUNCTIONS \
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

#define GL_ARB_gpu_shader_int64_FUNCTIONS \
	X(PFNGLUNIFORM1I64ARBPROC, glUniform1i64ARB) \
	X(PFNGLUNIFORM2I64ARBPROC, glUniform2i64ARB) \
	X(PFNGLUNIFORM3I64ARBPROC, glUniform3i64ARB) \
	X(PFNGLUNIFORM4I64ARBPROC, glUniform4i64ARB) \
	X(PFNGLUNIFORM1I64VARBPROC, glUniform1i64vARB) \
	X(PFNGLUNIFORM2I64VARBPROC, glUniform2i64vARB) \
	X(PFNGLUNIFORM3I64VARBPROC, glUniform3i64vARB) \
	X(PFNGLUNIFORM4I64VARBPROC, glUniform4i64vARB) \
	X(PFNGLUNIFORM1UI64ARBPROC, glUniform1ui64ARB) \
	X(PFNGLUNIFORM2UI64ARBPROC, glUniform2ui64ARB) \
	X(PFNGLUNIFORM3UI64ARBPROC, glUniform3ui64ARB) \
	X(PFNGLUNIFORM4UI64ARBPROC, glUniform4ui64ARB) \
	X(PFNGLUNIFORM1UI64VARBPROC, glUniform1ui64vARB) \
	X(PFNGLUNIFORM2UI64VARBPROC, glUniform2ui64vARB) \
	X(PFNGLUNIFORM3UI64VARBPROC, glUniform3ui64vARB) \
	X(PFNGLUNIFORM4UI64VARBPROC, glUniform4ui64vARB) \
	X(PFNGLGETUNIFORMI64VARBPROC, glGetUniformi64vARB) \
	X(PFNGLGETUNIFORMUI64VARBPROC, glGetUniformui64vARB) \
	X(PFNGLGETNUNIFORMI64VARBPROC, glGetnUniformi64vARB) \
	X(PFNGLGETNUNIFORMUI64VARBPROC, glGetnUniformui64vARB) \
	X(PFNGLPROGRAMUNIFORM1I64ARBPROC, glProgramUniform1i64ARB) \
	X(PFNGLPROGRAMUNIFORM2I64ARBPROC, glProgramUniform2i64ARB) \
	X(PFNGLPROGRAMUNIFORM3I64ARBPROC, glProgramUniform3i64ARB) \
	X(PFNGLPROGRAMUNIFORM4I64ARBPROC, glProgramUniform4i64ARB) \
	X(PFNGLPROGRAMUNIFORM1I64VARBPROC, glProgramUniform1i64vARB) \
	X(PFNGLPROGRAMUNIFORM2I64VARBPROC, glProgramUniform2i64vARB) \
	X(PFNGLPROGRAMUNIFORM3I64VARBPROC, glProgramUniform3i64vARB) \
	X(PFNGLPROGRAMUNIFORM4I64VARBPROC, glProgramUniform4i64vARB) \
	X(PFNGLPROGRAMUNIFORM1UI64ARBPROC, glProgramUniform1ui64ARB) \
	X(PFNGLPROGRAMUNIFORM2UI64ARBPROC, glProgramUniform2ui64ARB) \
	X(PFNGLPROGRAMUNIFORM3UI64ARBPROC, glProgramUniform3ui64ARB) \
	X(PFNGLPROGRAMUNIFORM4UI64ARBPROC, glProgramUniform4ui64ARB) \
	X(PFNGLPROGRAMUNIFORM1UI64VARBPROC, glProgramUniform1ui64vARB) \
	X(PFNGLPROGRAMUNIFORM2UI64VARBPROC, glProgramUniform2ui64vARB) \
	X(PFNGLPROGRAMUNIFORM3UI64VARBPROC, glProgramUniform3ui64vARB) \
	X(PFNGLPROGRAMUNIFORM4UI64VARBPROC, glProgramUniform4ui64vARB) \

#define GL_ARB_half_float_vertex_FUNCTIONS \

#define GL_ARB_imaging_FUNCTIONS \
	X(PFNGLBLENDCOLORPROC, glBlendColor) \
	X(PFNGLBLENDEQUATIONPROC, glBlendEquation) \
	X(PFNGLCOLORTABLEPROC, glColorTable) \
	X(PFNGLCOLORTABLEPARAMETERFVPROC, glColorTableParameterfv) \
	X(PFNGLCOLORTABLEPARAMETERIVPROC, glColorTableParameteriv) \
	X(PFNGLCOPYCOLORTABLEPROC, glCopyColorTable) \
	X(PFNGLGETCOLORTABLEPROC, glGetColorTable) \
	X(PFNGLGETCOLORTABLEPARAMETERFVPROC, glGetColorTableParameterfv) \
	X(PFNGLGETCOLORTABLEPARAMETERIVPROC, glGetColorTableParameteriv) \
	X(PFNGLCOLORSUBTABLEPROC, glColorSubTable) \
	X(PFNGLCOPYCOLORSUBTABLEPROC, glCopyColorSubTable) \
	X(PFNGLCONVOLUTIONFILTER1DPROC, glConvolutionFilter1D) \
	X(PFNGLCONVOLUTIONFILTER2DPROC, glConvolutionFilter2D) \
	X(PFNGLCONVOLUTIONPARAMETERFPROC, glConvolutionParameterf) \
	X(PFNGLCONVOLUTIONPARAMETERFVPROC, glConvolutionParameterfv) \
	X(PFNGLCONVOLUTIONPARAMETERIPROC, glConvolutionParameteri) \
	X(PFNGLCONVOLUTIONPARAMETERIVPROC, glConvolutionParameteriv) \
	X(PFNGLCOPYCONVOLUTIONFILTER1DPROC, glCopyConvolutionFilter1D) \
	X(PFNGLCOPYCONVOLUTIONFILTER2DPROC, glCopyConvolutionFilter2D) \
	X(PFNGLGETCONVOLUTIONFILTERPROC, glGetConvolutionFilter) \
	X(PFNGLGETCONVOLUTIONPARAMETERFVPROC, glGetConvolutionParameterfv) \
	X(PFNGLGETCONVOLUTIONPARAMETERIVPROC, glGetConvolutionParameteriv) \
	X(PFNGLGETSEPARABLEFILTERPROC, glGetSeparableFilter) \
	X(PFNGLSEPARABLEFILTER2DPROC, glSeparableFilter2D) \
	X(PFNGLGETHISTOGRAMPROC, glGetHistogram) \
	X(PFNGLGETHISTOGRAMPARAMETERFVPROC, glGetHistogramParameterfv) \
	X(PFNGLGETHISTOGRAMPARAMETERIVPROC, glGetHistogramParameteriv) \
	X(PFNGLGETMINMAXPROC, glGetMinmax) \
	X(PFNGLGETMINMAXPARAMETERFVPROC, glGetMinmaxParameterfv) \
	X(PFNGLGETMINMAXPARAMETERIVPROC, glGetMinmaxParameteriv) \
	X(PFNGLHISTOGRAMPROC, glHistogram) \
	X(PFNGLMINMAXPROC, glMinmax) \
	X(PFNGLRESETHISTOGRAMPROC, glResetHistogram) \
	X(PFNGLRESETMINMAXPROC, glResetMinmax) \

#define GL_ARB_indirect_parameters_FUNCTIONS \
	X(PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC, glMultiDrawArraysIndirectCountARB) \
	X(PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC, glMultiDrawElementsIndirectCountARB) \

#define GL_ARB_instanced_arrays_FUNCTIONS \
	X(PFNGLVERTEXATTRIBDIVISORARBPROC, glVertexAttribDivisorARB) \

#define GL_ARB_internalformat_query_FUNCTIONS \
	X(PFNGLGETINTERNALFORMATIVPROC, glGetInternalformativ) \

#define GL_ARB_internalformat_query2_FUNCTIONS \
	X(PFNGLGETINTERNALFORMATI64VPROC, glGetInternalformati64v) \

#define GL_ARB_invalidate_subdata_FUNCTIONS \
	X(PFNGLINVALIDATETEXSUBIMAGEPROC, glInvalidateTexSubImage) \
	X(PFNGLINVALIDATETEXIMAGEPROC, glInvalidateTexImage) \
	X(PFNGLINVALIDATEBUFFERSUBDATAPROC, glInvalidateBufferSubData) \
	X(PFNGLINVALIDATEBUFFERDATAPROC, glInvalidateBufferData) \
	X(PFNGLINVALIDATEFRAMEBUFFERPROC, glInvalidateFramebuffer) \
	X(PFNGLINVALIDATESUBFRAMEBUFFERPROC, glInvalidateSubFramebuffer) \

#define GL_ARB_map_buffer_alignment_FUNCTIONS \

#define GL_ARB_map_buffer_range_FUNCTIONS \
	X(PFNGLMAPBUFFERRANGEPROC, glMapBufferRange) \
	X(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, glFlushMappedBufferRange) \

#define GL_ARB_multi_bind_FUNCTIONS \
	X(PFNGLBINDBUFFERSBASEPROC, glBindBuffersBase) \
	X(PFNGLBINDBUFFERSRANGEPROC, glBindBuffersRange) \
	X(PFNGLBINDTEXTURESPROC, glBindTextures) \
	X(PFNGLBINDSAMPLERSPROC, glBindSamplers) \
	X(PFNGLBINDIMAGETEXTURESPROC, glBindImageTextures) \
	X(PFNGLBINDVERTEXBUFFERSPROC, glBindVertexBuffers) \

#define GL_ARB_multi_draw_indirect_FUNCTIONS \
	X(PFNGLMULTIDRAWARRAYSINDIRECTPROC, glMultiDrawArraysIndirect) \
	X(PFNGLMULTIDRAWELEMENTSINDIRECTPROC, glMultiDrawElementsIndirect) \

#define GL_ARB_occlusion_query2_FUNCTIONS \

#define GL_ARB_parallel_shader_compile_FUNCTIONS \
	X(PFNGLMAXSHADERCOMPILERTHREADSARBPROC, glMaxShaderCompilerThreadsARB) \

#define GL_ARB_pipeline_statistics_query_FUNCTIONS \

#define GL_ARB_pixel_buffer_object_FUNCTIONS \

#define GL_ARB_polygon_offset_clamp_FUNCTIONS \
	X(PFNGLPOLYGONOFFSETCLAMPPROC, glPolygonOffsetClamp) \

#define GL_ARB_program_interface_query_FUNCTIONS \
	X(PFNGLGETPROGRAMINTERFACEIVPROC, glGetProgramInterfaceiv) \
	X(PFNGLGETPROGRAMRESOURCEINDEXPROC, glGetProgramResourceIndex) \
	X(PFNGLGETPROGRAMRESOURCENAMEPROC, glGetProgramResourceName) \
	X(PFNGLGETPROGRAMRESOURCEIVPROC, glGetProgramResourceiv) \
	X(PFNGLGETPROGRAMRESOURCELOCATIONPROC, glGetProgramResourceLocation) \
	X(PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC, glGetProgramResourceLocationIndex) \

#define GL_ARB_provoking_vertex_FUNCTIONS \
	X(PFNGLPROVOKINGVERTEXPROC, glProvokingVertex) \

#define GL_ARB_query_buffer_object_FUNCTIONS \

#define GL_ARB_robustness_FUNCTIONS \
	X(PFNGLGETGRAPHICSRESETSTATUSARBPROC, glGetGraphicsResetStatusARB) \
	X(PFNGLGETNTEXIMAGEARBPROC, glGetnTexImageARB) \
	X(PFNGLREADNPIXELSARBPROC, glReadnPixelsARB) \
	X(PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC, glGetnCompressedTexImageARB) \
	X(PFNGLGETNUNIFORMFVARBPROC, glGetnUniformfvARB) \
	X(PFNGLGETNUNIFORMIVARBPROC, glGetnUniformivARB) \
	X(PFNGLGETNUNIFORMUIVARBPROC, glGetnUniformuivARB) \
	X(PFNGLGETNUNIFORMDVARBPROC, glGetnUniformdvARB) \
	X(PFNGLGETNMAPDVARBPROC, glGetnMapdvARB) \
	X(PFNGLGETNMAPFVARBPROC, glGetnMapfvARB) \
	X(PFNGLGETNMAPIVARBPROC, glGetnMapivARB) \
	X(PFNGLGETNPIXELMAPFVARBPROC, glGetnPixelMapfvARB) \
	X(PFNGLGETNPIXELMAPUIVARBPROC, glGetnPixelMapuivARB) \
	X(PFNGLGETNPIXELMAPUSVARBPROC, glGetnPixelMapusvARB) \
	X(PFNGLGETNPOLYGONSTIPPLEARBPROC, glGetnPolygonStippleARB) \
	X(PFNGLGETNCOLORTABLEARBPROC, glGetnColorTableARB) \
	X(PFNGLGETNCONVOLUTIONFILTERARBPROC, glGetnConvolutionFilterARB) \
	X(PFNGLGETNSEPARABLEFILTERARBPROC, glGetnSeparableFilterARB) \
	X(PFNGLGETNHISTOGRAMARBPROC, glGetnHistogramARB) \
	X(PFNGLGETNMINMAXARBPROC, glGetnMinmaxARB) \

#define GL_ARB_sample_locations_FUNCTIONS \
	X(PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC, glFramebufferSampleLocationsfvARB) \
	X(PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC, glNamedFramebufferSampleLocationsfvARB) \
	X(PFNGLEVALUATEDEPTHVALUESARBPROC, glEvaluateDepthValuesARB) \

#define GL_ARB_sample_shading_FUNCTIONS \
	X(PFNGLMINSAMPLESHADINGARBPROC, glMinSampleShadingARB) \

#define GL_ARB_sampler_objects_FUNCTIONS \
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

#define GL_ARB_seamless_cube_map_FUNCTIONS \

#define GL_ARB_seamless_cubemap_per_texture_FUNCTIONS \

#define GL_ARB_separate_shader_objects_FUNCTIONS \
	X(PFNGLUSEPROGRAMSTAGESPROC, glUseProgramStages) \
	X(PFNGLACTIVESHADERPROGRAMPROC, glActiveShaderProgram) \
	X(PFNGLCREATESHADERPROGRAMVPROC, glCreateShaderProgramv) \
	X(PFNGLBINDPROGRAMPIPELINEPROC, glBindProgramPipeline) \
	X(PFNGLDELETEPROGRAMPIPELINESPROC, glDeleteProgramPipelines) \
	X(PFNGLGENPROGRAMPIPELINESPROC, glGenProgramPipelines) \
	X(PFNGLISPROGRAMPIPELINEPROC, glIsProgramPipeline) \
	X(PFNGLGETPROGRAMPIPELINEIVPROC, glGetProgramPipelineiv) \
	X(PFNGLPROGRAMPARAMETERIPROC, glProgramParameteri) \
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

#define GL_ARB_shader_atomic_counters_FUNCTIONS \
	X(PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC, glGetActiveAtomicCounterBufferiv) \

#define GL_ARB_shader_image_load_store_FUNCTIONS \
	X(PFNGLBINDIMAGETEXTUREPROC, glBindImageTexture) \
	X(PFNGLMEMORYBARRIERPROC, glMemoryBarrier) \

#define GL_ARB_shader_storage_buffer_object_FUNCTIONS \
	X(PFNGLSHADERSTORAGEBLOCKBINDINGPROC, glShaderStorageBlockBinding) \

#define GL_ARB_shader_subroutine_FUNCTIONS \
	X(PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC, glGetSubroutineUniformLocation) \
	X(PFNGLGETSUBROUTINEINDEXPROC, glGetSubroutineIndex) \
	X(PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC, glGetActiveSubroutineUniformiv) \
	X(PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC, glGetActiveSubroutineUniformName) \
	X(PFNGLGETACTIVESUBROUTINENAMEPROC, glGetActiveSubroutineName) \
	X(PFNGLUNIFORMSUBROUTINESUIVPROC, glUniformSubroutinesuiv) \
	X(PFNGLGETUNIFORMSUBROUTINEUIVPROC, glGetUniformSubroutineuiv) \
	X(PFNGLGETPROGRAMSTAGEIVPROC, glGetProgramStageiv) \

#define GL_ARB_shading_language_include_FUNCTIONS \
	X(PFNGLNAMEDSTRINGARBPROC, glNamedStringARB) \
	X(PFNGLDELETENAMEDSTRINGARBPROC, glDeleteNamedStringARB) \
	X(PFNGLCOMPILESHADERINCLUDEARBPROC, glCompileShaderIncludeARB) \
	X(PFNGLISNAMEDSTRINGARBPROC, glIsNamedStringARB) \
	X(PFNGLGETNAMEDSTRINGARBPROC, glGetNamedStringARB) \
	X(PFNGLGETNAMEDSTRINGIVARBPROC, glGetNamedStringivARB) \

#define GL_ARB_sparse_buffer_FUNCTIONS \
	X(PFNGLBUFFERPAGECOMMITMENTARBPROC, glBufferPageCommitmentARB) \
	X(PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC, glNamedBufferPageCommitmentEXT) \
	X(PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC, glNamedBufferPageCommitmentARB) \

#define GL_ARB_sparse_texture_FUNCTIONS \
	X(PFNGLTEXPAGECOMMITMENTARBPROC, glTexPageCommitmentARB) \

#define GL_ARB_spirv_extensions_FUNCTIONS \

#define GL_ARB_stencil_texturing_FUNCTIONS \

#define GL_ARB_sync_FUNCTIONS \
	X(PFNGLFENCESYNCPROC, glFenceSync) \
	X(PFNGLISSYNCPROC, glIsSync) \
	X(PFNGLDELETESYNCPROC, glDeleteSync) \
	X(PFNGLCLIENTWAITSYNCPROC, glClientWaitSync) \
	X(PFNGLWAITSYNCPROC, glWaitSync) \
	X(PFNGLGETINTEGER64VPROC, glGetInteger64v) \
	X(PFNGLGETSYNCIVPROC, glGetSynciv) \

#define GL_ARB_tessellation_shader_FUNCTIONS \
	X(PFNGLPATCHPARAMETERIPROC, glPatchParameteri) \
	X(PFNGLPATCHPARAMETERFVPROC, glPatchParameterfv) \

#define GL_ARB_texture_barrier_FUNCTIONS \
	X(PFNGLTEXTUREBARRIERPROC, glTextureBarrier) \

#define GL_ARB_texture_border_clamp_FUNCTIONS \

#define GL_ARB_texture_buffer_object_FUNCTIONS \
	X(PFNGLTEXBUFFERARBPROC, glTexBufferARB) \

#define GL_ARB_texture_buffer_object_rgb32_FUNCTIONS \

#define GL_ARB_texture_buffer_range_FUNCTIONS \
	X(PFNGLTEXBUFFERRANGEPROC, glTexBufferRange) \

#define GL_ARB_texture_compression_bptc_FUNCTIONS \

#define GL_ARB_texture_compression_rgtc_FUNCTIONS \

#define GL_ARB_texture_cube_map_array_FUNCTIONS \

#define GL_ARB_texture_filter_anisotropic_FUNCTIONS \

#define GL_ARB_texture_filter_minmax_FUNCTIONS \

#define GL_ARB_texture_gather_FUNCTIONS \

#define GL_ARB_texture_mirror_clamp_to_edge_FUNCTIONS \

#define GL_ARB_texture_mirrored_repeat_FUNCTIONS \

#define GL_ARB_texture_multisample_FUNCTIONS \
	X(PFNGLTEXIMAGE2DMULTISAMPLEPROC, glTexImage2DMultisample) \
	X(PFNGLTEXIMAGE3DMULTISAMPLEPROC, glTexImage3DMultisample) \
	X(PFNGLGETMULTISAMPLEFVPROC, glGetMultisamplefv) \
	X(PFNGLSAMPLEMASKIPROC, glSampleMaski) \

#define GL_ARB_texture_rg_FUNCTIONS \

#define GL_ARB_texture_rgb10_a2ui_FUNCTIONS \

#define GL_ARB_texture_stencil8_FUNCTIONS \

#define GL_ARB_texture_storage_FUNCTIONS \
	X(PFNGLTEXSTORAGE1DPROC, glTexStorage1D) \
	X(PFNGLTEXSTORAGE2DPROC, glTexStorage2D) \
	X(PFNGLTEXSTORAGE3DPROC, glTexStorage3D) \

#define GL_ARB_texture_storage_multisample_FUNCTIONS \
	X(PFNGLTEXSTORAGE2DMULTISAMPLEPROC, glTexStorage2DMultisample) \
	X(PFNGLTEXSTORAGE3DMULTISAMPLEPROC, glTexStorage3DMultisample) \

#define GL_ARB_texture_swizzle_FUNCTIONS \

#define GL_ARB_texture_view_FUNCTIONS \
	X(PFNGLTEXTUREVIEWPROC, glTextureView) \

#define GL_ARB_timer_query_FUNCTIONS \
	X(PFNGLQUERYCOUNTERPROC, glQueryCounter) \
	X(PFNGLGETQUERYOBJECTI64VPROC, glGetQueryObjecti64v) \
	X(PFNGLGETQUERYOBJECTUI64VPROC, glGetQueryObjectui64v) \

#define GL_ARB_transform_feedback2_FUNCTIONS \
	X(PFNGLBINDTRANSFORMFEEDBACKPROC, glBindTransformFeedback) \
	X(PFNGLDELETETRANSFORMFEEDBACKSPROC, glDeleteTransformFeedbacks) \
	X(PFNGLGENTRANSFORMFEEDBACKSPROC, glGenTransformFeedbacks) \
	X(PFNGLISTRANSFORMFEEDBACKPROC, glIsTransformFeedback) \
	X(PFNGLPAUSETRANSFORMFEEDBACKPROC, glPauseTransformFeedback) \
	X(PFNGLRESUMETRANSFORMFEEDBACKPROC, glResumeTransformFeedback) \
	X(PFNGLDRAWTRANSFORMFEEDBACKPROC, glDrawTransformFeedback) \

#define GL_ARB_transform_feedback3_FUNCTIONS \
	X(PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC, glDrawTransformFeedbackStream) \
	X(PFNGLBEGINQUERYINDEXEDPROC, glBeginQueryIndexed) \
	X(PFNGLENDQUERYINDEXEDPROC, glEndQueryIndexed) \
	X(PFNGLGETQUERYINDEXEDIVPROC, glGetQueryIndexediv) \

#define GL_ARB_transform_feedback_instanced_FUNCTIONS \
	X(PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC, glDrawTransformFeedbackInstanced) \
	X(PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC, glDrawTransformFeedbackStreamInstanced) \

#define GL_ARB_transform_feedback_overflow_query_FUNCTIONS \

#define GL_ARB_uniform_buffer_object_FUNCTIONS \
	X(PFNGLGETUNIFORMINDICESPROC, glGetUniformIndices) \
	X(PFNGLGETACTIVEUNIFORMSIVPROC, glGetActiveUniformsiv) \
	X(PFNGLGETACTIVEUNIFORMNAMEPROC, glGetActiveUniformName) \
	X(PFNGLGETUNIFORMBLOCKINDEXPROC, glGetUniformBlockIndex) \
	X(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, glGetActiveUniformBlockiv) \
	X(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, glGetActiveUniformBlockName) \
	X(PFNGLUNIFORMBLOCKBINDINGPROC, glUniformBlockBinding) \
	X(PFNGLBINDBUFFERRANGEPROC, glBindBufferRange) \
	X(PFNGLBINDBUFFERBASEPROC, glBindBufferBase) \
	X(PFNGLGETINTEGERI_VPROC, glGetIntegeri_v) \

#define GL_ARB_vertex_array_bgra_FUNCTIONS \

#define GL_ARB_vertex_array_object_FUNCTIONS \
	X(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray) \
	X(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays) \
	X(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays) \
	X(PFNGLISVERTEXARRAYPROC, glIsVertexArray) \

#define GL_ARB_vertex_attrib_64bit_FUNCTIONS \
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

#define GL_ARB_vertex_attrib_binding_FUNCTIONS \
	X(PFNGLBINDVERTEXBUFFERPROC, glBindVertexBuffer) \
	X(PFNGLVERTEXATTRIBFORMATPROC, glVertexAttribFormat) \
	X(PFNGLVERTEXATTRIBIFORMATPROC, glVertexAttribIFormat) \
	X(PFNGLVERTEXATTRIBLFORMATPROC, glVertexAttribLFormat) \
	X(PFNGLVERTEXATTRIBBINDINGPROC, glVertexAttribBinding) \
	X(PFNGLVERTEXBINDINGDIVISORPROC, glVertexBindingDivisor) \

#define GL_ARB_vertex_type_10f_11f_11f_rev_FUNCTIONS \

#define GL_ARB_vertex_type_2_10_10_10_rev_FUNCTIONS \
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

#define GL_ARB_viewport_array_FUNCTIONS \
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
	X(PFNGLDEPTHRANGEARRAYDVNVPROC, glDepthRangeArraydvNV) \
	X(PFNGLDEPTHRANGEINDEXEDDNVPROC, glDepthRangeIndexeddNV) \

#define GL_EXT_EGL_image_storage_FUNCTIONS \
	X(PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC, glEGLImageTargetTexStorageEXT) \
	X(PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC, glEGLImageTargetTextureStorageEXT) \

#define GL_EXT_debug_label_FUNCTIONS \
	X(PFNGLLABELOBJECTEXTPROC, glLabelObjectEXT) \
	X(PFNGLGETOBJECTLABELEXTPROC, glGetObjectLabelEXT) \

#define GL_EXT_debug_marker_FUNCTIONS \
	X(PFNGLINSERTEVENTMARKEREXTPROC, glInsertEventMarkerEXT) \
	X(PFNGLPUSHGROUPMARKEREXTPROC, glPushGroupMarkerEXT) \
	X(PFNGLPOPGROUPMARKEREXTPROC, glPopGroupMarkerEXT) \

#define GL_EXT_direct_state_access_FUNCTIONS \
	X(PFNGLMATRIXLOADFEXTPROC, glMatrixLoadfEXT) \
	X(PFNGLMATRIXLOADDEXTPROC, glMatrixLoaddEXT) \
	X(PFNGLMATRIXMULTFEXTPROC, glMatrixMultfEXT) \
	X(PFNGLMATRIXMULTDEXTPROC, glMatrixMultdEXT) \
	X(PFNGLMATRIXLOADIDENTITYEXTPROC, glMatrixLoadIdentityEXT) \
	X(PFNGLMATRIXROTATEFEXTPROC, glMatrixRotatefEXT) \
	X(PFNGLMATRIXROTATEDEXTPROC, glMatrixRotatedEXT) \
	X(PFNGLMATRIXSCALEFEXTPROC, glMatrixScalefEXT) \
	X(PFNGLMATRIXSCALEDEXTPROC, glMatrixScaledEXT) \
	X(PFNGLMATRIXTRANSLATEFEXTPROC, glMatrixTranslatefEXT) \
	X(PFNGLMATRIXTRANSLATEDEXTPROC, glMatrixTranslatedEXT) \
	X(PFNGLMATRIXFRUSTUMEXTPROC, glMatrixFrustumEXT) \
	X(PFNGLMATRIXORTHOEXTPROC, glMatrixOrthoEXT) \
	X(PFNGLMATRIXPOPEXTPROC, glMatrixPopEXT) \
	X(PFNGLMATRIXPUSHEXTPROC, glMatrixPushEXT) \
	X(PFNGLCLIENTATTRIBDEFAULTEXTPROC, glClientAttribDefaultEXT) \
	X(PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC, glPushClientAttribDefaultEXT) \
	X(PFNGLTEXTUREPARAMETERFEXTPROC, glTextureParameterfEXT) \
	X(PFNGLTEXTUREPARAMETERFVEXTPROC, glTextureParameterfvEXT) \
	X(PFNGLTEXTUREPARAMETERIEXTPROC, glTextureParameteriEXT) \
	X(PFNGLTEXTUREPARAMETERIVEXTPROC, glTextureParameterivEXT) \
	X(PFNGLTEXTUREIMAGE1DEXTPROC, glTextureImage1DEXT) \
	X(PFNGLTEXTUREIMAGE2DEXTPROC, glTextureImage2DEXT) \
	X(PFNGLTEXTURESUBIMAGE1DEXTPROC, glTextureSubImage1DEXT) \
	X(PFNGLTEXTURESUBIMAGE2DEXTPROC, glTextureSubImage2DEXT) \
	X(PFNGLCOPYTEXTUREIMAGE1DEXTPROC, glCopyTextureImage1DEXT) \
	X(PFNGLCOPYTEXTUREIMAGE2DEXTPROC, glCopyTextureImage2DEXT) \
	X(PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC, glCopyTextureSubImage1DEXT) \
	X(PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC, glCopyTextureSubImage2DEXT) \
	X(PFNGLGETTEXTUREIMAGEEXTPROC, glGetTextureImageEXT) \
	X(PFNGLGETTEXTUREPARAMETERFVEXTPROC, glGetTextureParameterfvEXT) \
	X(PFNGLGETTEXTUREPARAMETERIVEXTPROC, glGetTextureParameterivEXT) \
	X(PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC, glGetTextureLevelParameterfvEXT) \
	X(PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC, glGetTextureLevelParameterivEXT) \
	X(PFNGLTEXTUREIMAGE3DEXTPROC, glTextureImage3DEXT) \
	X(PFNGLTEXTURESUBIMAGE3DEXTPROC, glTextureSubImage3DEXT) \
	X(PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC, glCopyTextureSubImage3DEXT) \
	X(PFNGLBINDMULTITEXTUREEXTPROC, glBindMultiTextureEXT) \
	X(PFNGLMULTITEXCOORDPOINTEREXTPROC, glMultiTexCoordPointerEXT) \
	X(PFNGLMULTITEXENVFEXTPROC, glMultiTexEnvfEXT) \
	X(PFNGLMULTITEXENVFVEXTPROC, glMultiTexEnvfvEXT) \
	X(PFNGLMULTITEXENVIEXTPROC, glMultiTexEnviEXT) \
	X(PFNGLMULTITEXENVIVEXTPROC, glMultiTexEnvivEXT) \
	X(PFNGLMULTITEXGENDEXTPROC, glMultiTexGendEXT) \
	X(PFNGLMULTITEXGENDVEXTPROC, glMultiTexGendvEXT) \
	X(PFNGLMULTITEXGENFEXTPROC, glMultiTexGenfEXT) \
	X(PFNGLMULTITEXGENFVEXTPROC, glMultiTexGenfvEXT) \
	X(PFNGLMULTITEXGENIEXTPROC, glMultiTexGeniEXT) \
	X(PFNGLMULTITEXGENIVEXTPROC, glMultiTexGenivEXT) \
	X(PFNGLGETMULTITEXENVFVEXTPROC, glGetMultiTexEnvfvEXT) \
	X(PFNGLGETMULTITEXENVIVEXTPROC, glGetMultiTexEnvivEXT) \
	X(PFNGLGETMULTITEXGENDVEXTPROC, glGetMultiTexGendvEXT) \
	X(PFNGLGETMULTITEXGENFVEXTPROC, glGetMultiTexGenfvEXT) \
	X(PFNGLGETMULTITEXGENIVEXTPROC, glGetMultiTexGenivEXT) \
	X(PFNGLMULTITEXPARAMETERIEXTPROC, glMultiTexParameteriEXT) \
	X(PFNGLMULTITEXPARAMETERIVEXTPROC, glMultiTexParameterivEXT) \
	X(PFNGLMULTITEXPARAMETERFEXTPROC, glMultiTexParameterfEXT) \
	X(PFNGLMULTITEXPARAMETERFVEXTPROC, glMultiTexParameterfvEXT) \
	X(PFNGLMULTITEXIMAGE1DEXTPROC, glMultiTexImage1DEXT) \
	X(PFNGLMULTITEXIMAGE2DEXTPROC, glMultiTexImage2DEXT) \
	X(PFNGLMULTITEXSUBIMAGE1DEXTPROC, glMultiTexSubImage1DEXT) \
	X(PFNGLMULTITEXSUBIMAGE2DEXTPROC, glMultiTexSubImage2DEXT) \
	X(PFNGLCOPYMULTITEXIMAGE1DEXTPROC, glCopyMultiTexImage1DEXT) \
	X(PFNGLCOPYMULTITEXIMAGE2DEXTPROC, glCopyMultiTexImage2DEXT) \
	X(PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC, glCopyMultiTexSubImage1DEXT) \
	X(PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC, glCopyMultiTexSubImage2DEXT) \
	X(PFNGLGETMULTITEXIMAGEEXTPROC, glGetMultiTexImageEXT) \
	X(PFNGLGETMULTITEXPARAMETERFVEXTPROC, glGetMultiTexParameterfvEXT) \
	X(PFNGLGETMULTITEXPARAMETERIVEXTPROC, glGetMultiTexParameterivEXT) \
	X(PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC, glGetMultiTexLevelParameterfvEXT) \
	X(PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC, glGetMultiTexLevelParameterivEXT) \
	X(PFNGLMULTITEXIMAGE3DEXTPROC, glMultiTexImage3DEXT) \
	X(PFNGLMULTITEXSUBIMAGE3DEXTPROC, glMultiTexSubImage3DEXT) \
	X(PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC, glCopyMultiTexSubImage3DEXT) \
	X(PFNGLENABLECLIENTSTATEINDEXEDEXTPROC, glEnableClientStateIndexedEXT) \
	X(PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC, glDisableClientStateIndexedEXT) \
	X(PFNGLGETFLOATINDEXEDVEXTPROC, glGetFloatIndexedvEXT) \
	X(PFNGLGETDOUBLEINDEXEDVEXTPROC, glGetDoubleIndexedvEXT) \
	X(PFNGLGETPOINTERINDEXEDVEXTPROC, glGetPointerIndexedvEXT) \
	X(PFNGLENABLEINDEXEDEXTPROC, glEnableIndexedEXT) \
	X(PFNGLDISABLEINDEXEDEXTPROC, glDisableIndexedEXT) \
	X(PFNGLISENABLEDINDEXEDEXTPROC, glIsEnabledIndexedEXT) \
	X(PFNGLGETINTEGERINDEXEDVEXTPROC, glGetIntegerIndexedvEXT) \
	X(PFNGLGETBOOLEANINDEXEDVEXTPROC, glGetBooleanIndexedvEXT) \
	X(PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC, glCompressedTextureImage3DEXT) \
	X(PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC, glCompressedTextureImage2DEXT) \
	X(PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC, glCompressedTextureImage1DEXT) \
	X(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC, glCompressedTextureSubImage3DEXT) \
	X(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC, glCompressedTextureSubImage2DEXT) \
	X(PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC, glCompressedTextureSubImage1DEXT) \
	X(PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC, glGetCompressedTextureImageEXT) \
	X(PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC, glCompressedMultiTexImage3DEXT) \
	X(PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC, glCompressedMultiTexImage2DEXT) \
	X(PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC, glCompressedMultiTexImage1DEXT) \
	X(PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC, glCompressedMultiTexSubImage3DEXT) \
	X(PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC, glCompressedMultiTexSubImage2DEXT) \
	X(PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC, glCompressedMultiTexSubImage1DEXT) \
	X(PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC, glGetCompressedMultiTexImageEXT) \
	X(PFNGLMATRIXLOADTRANSPOSEFEXTPROC, glMatrixLoadTransposefEXT) \
	X(PFNGLMATRIXLOADTRANSPOSEDEXTPROC, glMatrixLoadTransposedEXT) \
	X(PFNGLMATRIXMULTTRANSPOSEFEXTPROC, glMatrixMultTransposefEXT) \
	X(PFNGLMATRIXMULTTRANSPOSEDEXTPROC, glMatrixMultTransposedEXT) \
	X(PFNGLNAMEDBUFFERDATAEXTPROC, glNamedBufferDataEXT) \
	X(PFNGLNAMEDBUFFERSUBDATAEXTPROC, glNamedBufferSubDataEXT) \
	X(PFNGLMAPNAMEDBUFFEREXTPROC, glMapNamedBufferEXT) \
	X(PFNGLUNMAPNAMEDBUFFEREXTPROC, glUnmapNamedBufferEXT) \
	X(PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC, glGetNamedBufferParameterivEXT) \
	X(PFNGLGETNAMEDBUFFERPOINTERVEXTPROC, glGetNamedBufferPointervEXT) \
	X(PFNGLGETNAMEDBUFFERSUBDATAEXTPROC, glGetNamedBufferSubDataEXT) \
	X(PFNGLPROGRAMUNIFORM1FEXTPROC, glProgramUniform1fEXT) \
	X(PFNGLPROGRAMUNIFORM2FEXTPROC, glProgramUniform2fEXT) \
	X(PFNGLPROGRAMUNIFORM3FEXTPROC, glProgramUniform3fEXT) \
	X(PFNGLPROGRAMUNIFORM4FEXTPROC, glProgramUniform4fEXT) \
	X(PFNGLPROGRAMUNIFORM1IEXTPROC, glProgramUniform1iEXT) \
	X(PFNGLPROGRAMUNIFORM2IEXTPROC, glProgramUniform2iEXT) \
	X(PFNGLPROGRAMUNIFORM3IEXTPROC, glProgramUniform3iEXT) \
	X(PFNGLPROGRAMUNIFORM4IEXTPROC, glProgramUniform4iEXT) \
	X(PFNGLPROGRAMUNIFORM1FVEXTPROC, glProgramUniform1fvEXT) \
	X(PFNGLPROGRAMUNIFORM2FVEXTPROC, glProgramUniform2fvEXT) \
	X(PFNGLPROGRAMUNIFORM3FVEXTPROC, glProgramUniform3fvEXT) \
	X(PFNGLPROGRAMUNIFORM4FVEXTPROC, glProgramUniform4fvEXT) \
	X(PFNGLPROGRAMUNIFORM1IVEXTPROC, glProgramUniform1ivEXT) \
	X(PFNGLPROGRAMUNIFORM2IVEXTPROC, glProgramUniform2ivEXT) \
	X(PFNGLPROGRAMUNIFORM3IVEXTPROC, glProgramUniform3ivEXT) \
	X(PFNGLPROGRAMUNIFORM4IVEXTPROC, glProgramUniform4ivEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC, glProgramUniformMatrix2fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC, glProgramUniformMatrix3fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC, glProgramUniformMatrix4fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC, glProgramUniformMatrix2x3fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC, glProgramUniformMatrix3x2fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC, glProgramUniformMatrix2x4fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC, glProgramUniformMatrix4x2fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC, glProgramUniformMatrix3x4fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC, glProgramUniformMatrix4x3fvEXT) \
	X(PFNGLTEXTUREBUFFEREXTPROC, glTextureBufferEXT) \
	X(PFNGLMULTITEXBUFFEREXTPROC, glMultiTexBufferEXT) \
	X(PFNGLTEXTUREPARAMETERIIVEXTPROC, glTextureParameterIivEXT) \
	X(PFNGLTEXTUREPARAMETERIUIVEXTPROC, glTextureParameterIuivEXT) \
	X(PFNGLGETTEXTUREPARAMETERIIVEXTPROC, glGetTextureParameterIivEXT) \
	X(PFNGLGETTEXTUREPARAMETERIUIVEXTPROC, glGetTextureParameterIuivEXT) \
	X(PFNGLMULTITEXPARAMETERIIVEXTPROC, glMultiTexParameterIivEXT) \
	X(PFNGLMULTITEXPARAMETERIUIVEXTPROC, glMultiTexParameterIuivEXT) \
	X(PFNGLGETMULTITEXPARAMETERIIVEXTPROC, glGetMultiTexParameterIivEXT) \
	X(PFNGLGETMULTITEXPARAMETERIUIVEXTPROC, glGetMultiTexParameterIuivEXT) \
	X(PFNGLPROGRAMUNIFORM1UIEXTPROC, glProgramUniform1uiEXT) \
	X(PFNGLPROGRAMUNIFORM2UIEXTPROC, glProgramUniform2uiEXT) \
	X(PFNGLPROGRAMUNIFORM3UIEXTPROC, glProgramUniform3uiEXT) \
	X(PFNGLPROGRAMUNIFORM4UIEXTPROC, glProgramUniform4uiEXT) \
	X(PFNGLPROGRAMUNIFORM1UIVEXTPROC, glProgramUniform1uivEXT) \
	X(PFNGLPROGRAMUNIFORM2UIVEXTPROC, glProgramUniform2uivEXT) \
	X(PFNGLPROGRAMUNIFORM3UIVEXTPROC, glProgramUniform3uivEXT) \
	X(PFNGLPROGRAMUNIFORM4UIVEXTPROC, glProgramUniform4uivEXT) \
	X(PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC, glNamedProgramLocalParameters4fvEXT) \
	X(PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC, glNamedProgramLocalParameterI4iEXT) \
	X(PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC, glNamedProgramLocalParameterI4ivEXT) \
	X(PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC, glNamedProgramLocalParametersI4ivEXT) \
	X(PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC, glNamedProgramLocalParameterI4uiEXT) \
	X(PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC, glNamedProgramLocalParameterI4uivEXT) \
	X(PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC, glNamedProgramLocalParametersI4uivEXT) \
	X(PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC, glGetNamedProgramLocalParameterIivEXT) \
	X(PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC, glGetNamedProgramLocalParameterIuivEXT) \
	X(PFNGLENABLECLIENTSTATEIEXTPROC, glEnableClientStateiEXT) \
	X(PFNGLDISABLECLIENTSTATEIEXTPROC, glDisableClientStateiEXT) \
	X(PFNGLGETFLOATI_VEXTPROC, glGetFloati_vEXT) \
	X(PFNGLGETDOUBLEI_VEXTPROC, glGetDoublei_vEXT) \
	X(PFNGLGETPOINTERI_VEXTPROC, glGetPointeri_vEXT) \
	X(PFNGLNAMEDPROGRAMSTRINGEXTPROC, glNamedProgramStringEXT) \
	X(PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC, glNamedProgramLocalParameter4dEXT) \
	X(PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC, glNamedProgramLocalParameter4dvEXT) \
	X(PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC, glNamedProgramLocalParameter4fEXT) \
	X(PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC, glNamedProgramLocalParameter4fvEXT) \
	X(PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC, glGetNamedProgramLocalParameterdvEXT) \
	X(PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC, glGetNamedProgramLocalParameterfvEXT) \
	X(PFNGLGETNAMEDPROGRAMIVEXTPROC, glGetNamedProgramivEXT) \
	X(PFNGLGETNAMEDPROGRAMSTRINGEXTPROC, glGetNamedProgramStringEXT) \
	X(PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC, glNamedRenderbufferStorageEXT) \
	X(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC, glGetNamedRenderbufferParameterivEXT) \
	X(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC, glNamedRenderbufferStorageMultisampleEXT) \
	X(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC, glNamedRenderbufferStorageMultisampleCoverageEXT) \
	X(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC, glCheckNamedFramebufferStatusEXT) \
	X(PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC, glNamedFramebufferTexture1DEXT) \
	X(PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC, glNamedFramebufferTexture2DEXT) \
	X(PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC, glNamedFramebufferTexture3DEXT) \
	X(PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC, glNamedFramebufferRenderbufferEXT) \
	X(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC, glGetNamedFramebufferAttachmentParameterivEXT) \
	X(PFNGLGENERATETEXTUREMIPMAPEXTPROC, glGenerateTextureMipmapEXT) \
	X(PFNGLGENERATEMULTITEXMIPMAPEXTPROC, glGenerateMultiTexMipmapEXT) \
	X(PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC, glFramebufferDrawBufferEXT) \
	X(PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC, glFramebufferDrawBuffersEXT) \
	X(PFNGLFRAMEBUFFERREADBUFFEREXTPROC, glFramebufferReadBufferEXT) \
	X(PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC, glGetFramebufferParameterivEXT) \
	X(PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC, glNamedCopyBufferSubDataEXT) \
	X(PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC, glNamedFramebufferTextureEXT) \
	X(PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC, glNamedFramebufferTextureLayerEXT) \
	X(PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC, glNamedFramebufferTextureFaceEXT) \
	X(PFNGLTEXTURERENDERBUFFEREXTPROC, glTextureRenderbufferEXT) \
	X(PFNGLMULTITEXRENDERBUFFEREXTPROC, glMultiTexRenderbufferEXT) \
	X(PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC, glVertexArrayVertexOffsetEXT) \
	X(PFNGLVERTEXARRAYCOLOROFFSETEXTPROC, glVertexArrayColorOffsetEXT) \
	X(PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC, glVertexArrayEdgeFlagOffsetEXT) \
	X(PFNGLVERTEXARRAYINDEXOFFSETEXTPROC, glVertexArrayIndexOffsetEXT) \
	X(PFNGLVERTEXARRAYNORMALOFFSETEXTPROC, glVertexArrayNormalOffsetEXT) \
	X(PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC, glVertexArrayTexCoordOffsetEXT) \
	X(PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC, glVertexArrayMultiTexCoordOffsetEXT) \
	X(PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC, glVertexArrayFogCoordOffsetEXT) \
	X(PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC, glVertexArraySecondaryColorOffsetEXT) \
	X(PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC, glVertexArrayVertexAttribOffsetEXT) \
	X(PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC, glVertexArrayVertexAttribIOffsetEXT) \
	X(PFNGLENABLEVERTEXARRAYEXTPROC, glEnableVertexArrayEXT) \
	X(PFNGLDISABLEVERTEXARRAYEXTPROC, glDisableVertexArrayEXT) \
	X(PFNGLENABLEVERTEXARRAYATTRIBEXTPROC, glEnableVertexArrayAttribEXT) \
	X(PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC, glDisableVertexArrayAttribEXT) \
	X(PFNGLGETVERTEXARRAYINTEGERVEXTPROC, glGetVertexArrayIntegervEXT) \
	X(PFNGLGETVERTEXARRAYPOINTERVEXTPROC, glGetVertexArrayPointervEXT) \
	X(PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC, glGetVertexArrayIntegeri_vEXT) \
	X(PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC, glGetVertexArrayPointeri_vEXT) \
	X(PFNGLMAPNAMEDBUFFERRANGEEXTPROC, glMapNamedBufferRangeEXT) \
	X(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC, glFlushMappedNamedBufferRangeEXT) \
	X(PFNGLNAMEDBUFFERSTORAGEEXTPROC, glNamedBufferStorageEXT) \
	X(PFNGLCLEARNAMEDBUFFERDATAEXTPROC, glClearNamedBufferDataEXT) \
	X(PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC, glClearNamedBufferSubDataEXT) \
	X(PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC, glNamedFramebufferParameteriEXT) \
	X(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC, glGetNamedFramebufferParameterivEXT) \
	X(PFNGLPROGRAMUNIFORM1DEXTPROC, glProgramUniform1dEXT) \
	X(PFNGLPROGRAMUNIFORM2DEXTPROC, glProgramUniform2dEXT) \
	X(PFNGLPROGRAMUNIFORM3DEXTPROC, glProgramUniform3dEXT) \
	X(PFNGLPROGRAMUNIFORM4DEXTPROC, glProgramUniform4dEXT) \
	X(PFNGLPROGRAMUNIFORM1DVEXTPROC, glProgramUniform1dvEXT) \
	X(PFNGLPROGRAMUNIFORM2DVEXTPROC, glProgramUniform2dvEXT) \
	X(PFNGLPROGRAMUNIFORM3DVEXTPROC, glProgramUniform3dvEXT) \
	X(PFNGLPROGRAMUNIFORM4DVEXTPROC, glProgramUniform4dvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC, glProgramUniformMatrix2dvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC, glProgramUniformMatrix3dvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC, glProgramUniformMatrix4dvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC, glProgramUniformMatrix2x3dvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC, glProgramUniformMatrix2x4dvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC, glProgramUniformMatrix3x2dvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC, glProgramUniformMatrix3x4dvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC, glProgramUniformMatrix4x2dvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC, glProgramUniformMatrix4x3dvEXT) \
	X(PFNGLTEXTUREBUFFERRANGEEXTPROC, glTextureBufferRangeEXT) \
	X(PFNGLTEXTURESTORAGE1DEXTPROC, glTextureStorage1DEXT) \
	X(PFNGLTEXTURESTORAGE2DEXTPROC, glTextureStorage2DEXT) \
	X(PFNGLTEXTURESTORAGE3DEXTPROC, glTextureStorage3DEXT) \
	X(PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC, glTextureStorage2DMultisampleEXT) \
	X(PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC, glTextureStorage3DMultisampleEXT) \
	X(PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC, glVertexArrayBindVertexBufferEXT) \
	X(PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC, glVertexArrayVertexAttribFormatEXT) \
	X(PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC, glVertexArrayVertexAttribIFormatEXT) \
	X(PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC, glVertexArrayVertexAttribLFormatEXT) \
	X(PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC, glVertexArrayVertexAttribBindingEXT) \
	X(PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC, glVertexArrayVertexBindingDivisorEXT) \
	X(PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC, glVertexArrayVertexAttribLOffsetEXT) \
	X(PFNGLTEXTUREPAGECOMMITMENTEXTPROC, glTexturePageCommitmentEXT) \
	X(PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC, glVertexArrayVertexAttribDivisorEXT) \

#define GL_EXT_draw_instanced_FUNCTIONS \
	X(PFNGLDRAWARRAYSINSTANCEDEXTPROC, glDrawArraysInstancedEXT) \
	X(PFNGLDRAWELEMENTSINSTANCEDEXTPROC, glDrawElementsInstancedEXT) \

#define GL_EXT_polygon_offset_clamp_FUNCTIONS \
	X(PFNGLPOLYGONOFFSETCLAMPEXTPROC, glPolygonOffsetClampEXT) \

#define GL_EXT_raster_multisample_FUNCTIONS \
	X(PFNGLRASTERSAMPLESEXTPROC, glRasterSamplesEXT) \

#define GL_EXT_separate_shader_objects_FUNCTIONS \
	X(PFNGLUSESHADERPROGRAMEXTPROC, glUseShaderProgramEXT) \
	X(PFNGLACTIVEPROGRAMEXTPROC, glActiveProgramEXT) \
	X(PFNGLCREATESHADERPROGRAMEXTPROC, glCreateShaderProgramEXT) \
	X(PFNGLACTIVESHADERPROGRAMEXTPROC, glActiveShaderProgramEXT) \
	X(PFNGLBINDPROGRAMPIPELINEEXTPROC, glBindProgramPipelineEXT) \
	X(PFNGLCREATESHADERPROGRAMVEXTPROC, glCreateShaderProgramvEXT) \
	X(PFNGLDELETEPROGRAMPIPELINESEXTPROC, glDeleteProgramPipelinesEXT) \
	X(PFNGLGENPROGRAMPIPELINESEXTPROC, glGenProgramPipelinesEXT) \
	X(PFNGLGETPROGRAMPIPELINEINFOLOGEXTPROC, glGetProgramPipelineInfoLogEXT) \
	X(PFNGLGETPROGRAMPIPELINEIVEXTPROC, glGetProgramPipelineivEXT) \
	X(PFNGLISPROGRAMPIPELINEEXTPROC, glIsProgramPipelineEXT) \
	X(PFNGLPROGRAMPARAMETERIEXTPROC, glProgramParameteriEXT) \
	X(PFNGLPROGRAMUNIFORM1FEXTPROC, glProgramUniform1fEXT) \
	X(PFNGLPROGRAMUNIFORM1FVEXTPROC, glProgramUniform1fvEXT) \
	X(PFNGLPROGRAMUNIFORM1IEXTPROC, glProgramUniform1iEXT) \
	X(PFNGLPROGRAMUNIFORM1IVEXTPROC, glProgramUniform1ivEXT) \
	X(PFNGLPROGRAMUNIFORM2FEXTPROC, glProgramUniform2fEXT) \
	X(PFNGLPROGRAMUNIFORM2FVEXTPROC, glProgramUniform2fvEXT) \
	X(PFNGLPROGRAMUNIFORM2IEXTPROC, glProgramUniform2iEXT) \
	X(PFNGLPROGRAMUNIFORM2IVEXTPROC, glProgramUniform2ivEXT) \
	X(PFNGLPROGRAMUNIFORM3FEXTPROC, glProgramUniform3fEXT) \
	X(PFNGLPROGRAMUNIFORM3FVEXTPROC, glProgramUniform3fvEXT) \
	X(PFNGLPROGRAMUNIFORM3IEXTPROC, glProgramUniform3iEXT) \
	X(PFNGLPROGRAMUNIFORM3IVEXTPROC, glProgramUniform3ivEXT) \
	X(PFNGLPROGRAMUNIFORM4FEXTPROC, glProgramUniform4fEXT) \
	X(PFNGLPROGRAMUNIFORM4FVEXTPROC, glProgramUniform4fvEXT) \
	X(PFNGLPROGRAMUNIFORM4IEXTPROC, glProgramUniform4iEXT) \
	X(PFNGLPROGRAMUNIFORM4IVEXTPROC, glProgramUniform4ivEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC, glProgramUniformMatrix2fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC, glProgramUniformMatrix3fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC, glProgramUniformMatrix4fvEXT) \
	X(PFNGLUSEPROGRAMSTAGESEXTPROC, glUseProgramStagesEXT) \
	X(PFNGLVALIDATEPROGRAMPIPELINEEXTPROC, glValidateProgramPipelineEXT) \
	X(PFNGLPROGRAMUNIFORM1UIEXTPROC, glProgramUniform1uiEXT) \
	X(PFNGLPROGRAMUNIFORM2UIEXTPROC, glProgramUniform2uiEXT) \
	X(PFNGLPROGRAMUNIFORM3UIEXTPROC, glProgramUniform3uiEXT) \
	X(PFNGLPROGRAMUNIFORM4UIEXTPROC, glProgramUniform4uiEXT) \
	X(PFNGLPROGRAMUNIFORM1UIVEXTPROC, glProgramUniform1uivEXT) \
	X(PFNGLPROGRAMUNIFORM2UIVEXTPROC, glProgramUniform2uivEXT) \
	X(PFNGLPROGRAMUNIFORM3UIVEXTPROC, glProgramUniform3uivEXT) \
	X(PFNGLPROGRAMUNIFORM4UIVEXTPROC, glProgramUniform4uivEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC, glProgramUniformMatrix2x3fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC, glProgramUniformMatrix3x2fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC, glProgramUniformMatrix2x4fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC, glProgramUniformMatrix4x2fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC, glProgramUniformMatrix3x4fvEXT) \
	X(PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC, glProgramUniformMatrix4x3fvEXT) \

#define GL_EXT_shader_framebuffer_fetch_FUNCTIONS \

#define GL_EXT_shader_framebuffer_fetch_non_coherent_FUNCTIONS \
	X(PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC, glFramebufferFetchBarrierEXT) \

#define GL_EXT_texture_compression_s3tc_FUNCTIONS \

#define GL_EXT_texture_filter_minmax_FUNCTIONS \

#define GL_EXT_texture_sRGB_R8_FUNCTIONS \

#define GL_EXT_texture_sRGB_RG8_FUNCTIONS \

#define GL_EXT_texture_sRGB_decode_FUNCTIONS \

#define GL_EXT_texture_storage_FUNCTIONS \
	X(PFNGLTEXSTORAGE1DEXTPROC, glTexStorage1DEXT) \
	X(PFNGLTEXSTORAGE2DEXTPROC, glTexStorage2DEXT) \
	X(PFNGLTEXSTORAGE3DEXTPROC, glTexStorage3DEXT) \
	X(PFNGLTEXTURESTORAGE1DEXTPROC, glTextureStorage1DEXT) \
	X(PFNGLTEXTURESTORAGE2DEXTPROC, glTextureStorage2DEXT) \
	X(PFNGLTEXTURESTORAGE3DEXTPROC, glTextureStorage3DEXT) \

#define GL_EXT_window_rectangles_FUNCTIONS \
	X(PFNGLWINDOWRECTANGLESEXTPROC, glWindowRectanglesEXT) \

#define GL_INTEL_conservative_rasterization_FUNCTIONS \

#define GL_INTEL_framebuffer_CMAA_FUNCTIONS \
	X(PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC, glApplyFramebufferAttachmentCMAAINTEL) \

#define GL_INTEL_blackhole_render_FUNCTIONS \

#define GL_INTEL_performance_query_FUNCTIONS \
	X(PFNGLBEGINPERFQUERYINTELPROC, glBeginPerfQueryINTEL) \
	X(PFNGLCREATEPERFQUERYINTELPROC, glCreatePerfQueryINTEL) \
	X(PFNGLDELETEPERFQUERYINTELPROC, glDeletePerfQueryINTEL) \
	X(PFNGLENDPERFQUERYINTELPROC, glEndPerfQueryINTEL) \
	X(PFNGLGETFIRSTPERFQUERYIDINTELPROC, glGetFirstPerfQueryIdINTEL) \
	X(PFNGLGETNEXTPERFQUERYIDINTELPROC, glGetNextPerfQueryIdINTEL) \
	X(PFNGLGETPERFCOUNTERINFOINTELPROC, glGetPerfCounterInfoINTEL) \
	X(PFNGLGETPERFQUERYDATAINTELPROC, glGetPerfQueryDataINTEL) \
	X(PFNGLGETPERFQUERYIDBYNAMEINTELPROC, glGetPerfQueryIdByNameINTEL) \
	X(PFNGLGETPERFQUERYINFOINTELPROC, glGetPerfQueryInfoINTEL) \

#define GL_KHR_blend_equation_advanced_FUNCTIONS \
	X(PFNGLBLENDBARRIERKHRPROC, glBlendBarrierKHR) \

#define GL_KHR_blend_equation_advanced_coherent_FUNCTIONS \

#define GL_KHR_context_flush_control_FUNCTIONS \

#define GL_KHR_debug_FUNCTIONS \
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
	X(PFNGLGETPOINTERVPROC, glGetPointerv) \
	X(PFNGLDEBUGMESSAGECONTROLKHRPROC, glDebugMessageControlKHR) \
	X(PFNGLDEBUGMESSAGEINSERTKHRPROC, glDebugMessageInsertKHR) \
	X(PFNGLDEBUGMESSAGECALLBACKKHRPROC, glDebugMessageCallbackKHR) \
	X(PFNGLGETDEBUGMESSAGELOGKHRPROC, glGetDebugMessageLogKHR) \
	X(PFNGLPUSHDEBUGGROUPKHRPROC, glPushDebugGroupKHR) \
	X(PFNGLPOPDEBUGGROUPKHRPROC, glPopDebugGroupKHR) \
	X(PFNGLOBJECTLABELKHRPROC, glObjectLabelKHR) \
	X(PFNGLGETOBJECTLABELKHRPROC, glGetObjectLabelKHR) \
	X(PFNGLOBJECTPTRLABELKHRPROC, glObjectPtrLabelKHR) \
	X(PFNGLGETOBJECTPTRLABELKHRPROC, glGetObjectPtrLabelKHR) \
	X(PFNGLGETPOINTERVKHRPROC, glGetPointervKHR) \

#define GL_KHR_no_error_FUNCTIONS \

#define GL_KHR_robustness_FUNCTIONS \
	X(PFNGLGETGRAPHICSRESETSTATUSPROC, glGetGraphicsResetStatus) \
	X(PFNGLREADNPIXELSPROC, glReadnPixels) \
	X(PFNGLGETNUNIFORMFVPROC, glGetnUniformfv) \
	X(PFNGLGETNUNIFORMIVPROC, glGetnUniformiv) \
	X(PFNGLGETNUNIFORMUIVPROC, glGetnUniformuiv) \
	X(PFNGLGETGRAPHICSRESETSTATUSKHRPROC, glGetGraphicsResetStatusKHR) \
	X(PFNGLREADNPIXELSKHRPROC, glReadnPixelsKHR) \
	X(PFNGLGETNUNIFORMFVKHRPROC, glGetnUniformfvKHR) \
	X(PFNGLGETNUNIFORMIVKHRPROC, glGetnUniformivKHR) \
	X(PFNGLGETNUNIFORMUIVKHRPROC, glGetnUniformuivKHR) \

#define GL_KHR_shader_subgroup_FUNCTIONS \

#define GL_KHR_texture_compression_astc_hdr_FUNCTIONS \

#define GL_KHR_texture_compression_astc_ldr_FUNCTIONS \

#define GL_KHR_parallel_shader_compile_FUNCTIONS \
	X(PFNGLMAXSHADERCOMPILERTHREADSKHRPROC, glMaxShaderCompilerThreadsKHR) \

#define GL_MESA_framebuffer_flip_x_FUNCTIONS \

#define GL_MESA_framebuffer_flip_y_FUNCTIONS \
	X(PFNGLFRAMEBUFFERPARAMETERIMESAPROC, glFramebufferParameteriMESA) \
	X(PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC, glGetFramebufferParameterivMESA) \

#define GL_MESA_framebuffer_swap_xy_FUNCTIONS \

#define GL_NV_bindless_multi_draw_indirect_FUNCTIONS \
	X(PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC, glMultiDrawArraysIndirectBindlessNV) \
	X(PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC, glMultiDrawElementsIndirectBindlessNV) \

#define GL_NV_bindless_multi_draw_indirect_count_FUNCTIONS \
	X(PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC, glMultiDrawArraysIndirectBindlessCountNV) \
	X(PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC, glMultiDrawElementsIndirectBindlessCountNV) \

#define GL_NV_bindless_texture_FUNCTIONS \
	X(PFNGLGETTEXTUREHANDLENVPROC, glGetTextureHandleNV) \
	X(PFNGLGETTEXTURESAMPLERHANDLENVPROC, glGetTextureSamplerHandleNV) \
	X(PFNGLMAKETEXTUREHANDLERESIDENTNVPROC, glMakeTextureHandleResidentNV) \
	X(PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC, glMakeTextureHandleNonResidentNV) \
	X(PFNGLGETIMAGEHANDLENVPROC, glGetImageHandleNV) \
	X(PFNGLMAKEIMAGEHANDLERESIDENTNVPROC, glMakeImageHandleResidentNV) \
	X(PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC, glMakeImageHandleNonResidentNV) \
	X(PFNGLUNIFORMHANDLEUI64NVPROC, glUniformHandleui64NV) \
	X(PFNGLUNIFORMHANDLEUI64VNVPROC, glUniformHandleui64vNV) \
	X(PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC, glProgramUniformHandleui64NV) \
	X(PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC, glProgramUniformHandleui64vNV) \
	X(PFNGLISTEXTUREHANDLERESIDENTNVPROC, glIsTextureHandleResidentNV) \
	X(PFNGLISIMAGEHANDLERESIDENTNVPROC, glIsImageHandleResidentNV) \

#define GL_NV_blend_equation_advanced_FUNCTIONS \
	X(PFNGLBLENDPARAMETERINVPROC, glBlendParameteriNV) \
	X(PFNGLBLENDBARRIERNVPROC, glBlendBarrierNV) \

#define GL_NV_blend_equation_advanced_coherent_FUNCTIONS \

#define GL_NV_blend_minmax_factor_FUNCTIONS \

#define GL_NV_clip_space_w_scaling_FUNCTIONS \
	X(PFNGLVIEWPORTPOSITIONWSCALENVPROC, glViewportPositionWScaleNV) \

#define GL_NV_command_list_FUNCTIONS \
	X(PFNGLCREATESTATESNVPROC, glCreateStatesNV) \
	X(PFNGLDELETESTATESNVPROC, glDeleteStatesNV) \
	X(PFNGLISSTATENVPROC, glIsStateNV) \
	X(PFNGLSTATECAPTURENVPROC, glStateCaptureNV) \
	X(PFNGLGETCOMMANDHEADERNVPROC, glGetCommandHeaderNV) \
	X(PFNGLGETSTAGEINDEXNVPROC, glGetStageIndexNV) \
	X(PFNGLDRAWCOMMANDSNVPROC, glDrawCommandsNV) \
	X(PFNGLDRAWCOMMANDSADDRESSNVPROC, glDrawCommandsAddressNV) \
	X(PFNGLDRAWCOMMANDSSTATESNVPROC, glDrawCommandsStatesNV) \
	X(PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC, glDrawCommandsStatesAddressNV) \
	X(PFNGLCREATECOMMANDLISTSNVPROC, glCreateCommandListsNV) \
	X(PFNGLDELETECOMMANDLISTSNVPROC, glDeleteCommandListsNV) \
	X(PFNGLISCOMMANDLISTNVPROC, glIsCommandListNV) \
	X(PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC, glListDrawCommandsStatesClientNV) \
	X(PFNGLCOMMANDLISTSEGMENTSNVPROC, glCommandListSegmentsNV) \
	X(PFNGLCOMPILECOMMANDLISTNVPROC, glCompileCommandListNV) \
	X(PFNGLCALLCOMMANDLISTNVPROC, glCallCommandListNV) \

#define GL_NV_conditional_render_FUNCTIONS \
	X(PFNGLBEGINCONDITIONALRENDERNVPROC, glBeginConditionalRenderNV) \
	X(PFNGLENDCONDITIONALRENDERNVPROC, glEndConditionalRenderNV) \

#define GL_NV_conservative_raster_FUNCTIONS \
	X(PFNGLSUBPIXELPRECISIONBIASNVPROC, glSubpixelPrecisionBiasNV) \

#define GL_NV_conservative_raster_dilate_FUNCTIONS \
	X(PFNGLCONSERVATIVERASTERPARAMETERFNVPROC, glConservativeRasterParameterfNV) \

#define GL_NV_conservative_raster_pre_snap_FUNCTIONS \

#define GL_NV_conservative_raster_pre_snap_triangles_FUNCTIONS \
	X(PFNGLCONSERVATIVERASTERPARAMETERINVPROC, glConservativeRasterParameteriNV) \

#define GL_NV_depth_buffer_float_FUNCTIONS \
	X(PFNGLDEPTHRANGEDNVPROC, glDepthRangedNV) \
	X(PFNGLCLEARDEPTHDNVPROC, glClearDepthdNV) \
	X(PFNGLDEPTHBOUNDSDNVPROC, glDepthBoundsdNV) \

#define GL_NV_draw_vulkan_image_FUNCTIONS \
	X(PFNGLDRAWVKIMAGENVPROC, glDrawVkImageNV) \
	X(PFNGLGETVKPROCADDRNVPROC, glGetVkProcAddrNV) \
	X(PFNGLWAITVKSEMAPHORENVPROC, glWaitVkSemaphoreNV) \
	X(PFNGLSIGNALVKSEMAPHORENVPROC, glSignalVkSemaphoreNV) \
	X(PFNGLSIGNALVKFENCENVPROC, glSignalVkFenceNV) \

#define GL_NV_fill_rectangle_FUNCTIONS \

#define GL_NV_fragment_coverage_to_color_FUNCTIONS \
	X(PFNGLFRAGMENTCOVERAGECOLORNVPROC, glFragmentCoverageColorNV) \

#define GL_NV_framebuffer_mixed_samples_FUNCTIONS \
	X(PFNGLRASTERSAMPLESEXTPROC, glRasterSamplesEXT) \
	X(PFNGLCOVERAGEMODULATIONTABLENVPROC, glCoverageModulationTableNV) \
	X(PFNGLGETCOVERAGEMODULATIONTABLENVPROC, glGetCoverageModulationTableNV) \
	X(PFNGLCOVERAGEMODULATIONNVPROC, glCoverageModulationNV) \

#define GL_NV_framebuffer_multisample_coverage_FUNCTIONS \
	X(PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC, glRenderbufferStorageMultisampleCoverageNV) \

#define GL_NV_gpu_shader5_FUNCTIONS \
	X(PFNGLUNIFORM1I64NVPROC, glUniform1i64NV) \
	X(PFNGLUNIFORM2I64NVPROC, glUniform2i64NV) \
	X(PFNGLUNIFORM3I64NVPROC, glUniform3i64NV) \
	X(PFNGLUNIFORM4I64NVPROC, glUniform4i64NV) \
	X(PFNGLUNIFORM1I64VNVPROC, glUniform1i64vNV) \
	X(PFNGLUNIFORM2I64VNVPROC, glUniform2i64vNV) \
	X(PFNGLUNIFORM3I64VNVPROC, glUniform3i64vNV) \
	X(PFNGLUNIFORM4I64VNVPROC, glUniform4i64vNV) \
	X(PFNGLUNIFORM1UI64NVPROC, glUniform1ui64NV) \
	X(PFNGLUNIFORM2UI64NVPROC, glUniform2ui64NV) \
	X(PFNGLUNIFORM3UI64NVPROC, glUniform3ui64NV) \
	X(PFNGLUNIFORM4UI64NVPROC, glUniform4ui64NV) \
	X(PFNGLUNIFORM1UI64VNVPROC, glUniform1ui64vNV) \
	X(PFNGLUNIFORM2UI64VNVPROC, glUniform2ui64vNV) \
	X(PFNGLUNIFORM3UI64VNVPROC, glUniform3ui64vNV) \
	X(PFNGLUNIFORM4UI64VNVPROC, glUniform4ui64vNV) \
	X(PFNGLGETUNIFORMI64VNVPROC, glGetUniformi64vNV) \
	X(PFNGLPROGRAMUNIFORM1I64NVPROC, glProgramUniform1i64NV) \
	X(PFNGLPROGRAMUNIFORM2I64NVPROC, glProgramUniform2i64NV) \
	X(PFNGLPROGRAMUNIFORM3I64NVPROC, glProgramUniform3i64NV) \
	X(PFNGLPROGRAMUNIFORM4I64NVPROC, glProgramUniform4i64NV) \
	X(PFNGLPROGRAMUNIFORM1I64VNVPROC, glProgramUniform1i64vNV) \
	X(PFNGLPROGRAMUNIFORM2I64VNVPROC, glProgramUniform2i64vNV) \
	X(PFNGLPROGRAMUNIFORM3I64VNVPROC, glProgramUniform3i64vNV) \
	X(PFNGLPROGRAMUNIFORM4I64VNVPROC, glProgramUniform4i64vNV) \
	X(PFNGLPROGRAMUNIFORM1UI64NVPROC, glProgramUniform1ui64NV) \
	X(PFNGLPROGRAMUNIFORM2UI64NVPROC, glProgramUniform2ui64NV) \
	X(PFNGLPROGRAMUNIFORM3UI64NVPROC, glProgramUniform3ui64NV) \
	X(PFNGLPROGRAMUNIFORM4UI64NVPROC, glProgramUniform4ui64NV) \
	X(PFNGLPROGRAMUNIFORM1UI64VNVPROC, glProgramUniform1ui64vNV) \
	X(PFNGLPROGRAMUNIFORM2UI64VNVPROC, glProgramUniform2ui64vNV) \
	X(PFNGLPROGRAMUNIFORM3UI64VNVPROC, glProgramUniform3ui64vNV) \
	X(PFNGLPROGRAMUNIFORM4UI64VNVPROC, glProgramUniform4ui64vNV) \

#define GL_NV_internalformat_sample_query_FUNCTIONS \
	X(PFNGLGETINTERNALFORMATSAMPLEIVNVPROC, glGetInternalformatSampleivNV) \

#define GL_NV_memory_attachment_FUNCTIONS \
	X(PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC, glGetMemoryObjectDetachedResourcesuivNV) \
	X(PFNGLRESETMEMORYOBJECTPARAMETERNVPROC, glResetMemoryObjectParameterNV) \
	X(PFNGLTEXATTACHMEMORYNVPROC, glTexAttachMemoryNV) \
	X(PFNGLBUFFERATTACHMEMORYNVPROC, glBufferAttachMemoryNV) \
	X(PFNGLTEXTUREATTACHMEMORYNVPROC, glTextureAttachMemoryNV) \
	X(PFNGLNAMEDBUFFERATTACHMEMORYNVPROC, glNamedBufferAttachMemoryNV) \

#define GL_NV_memory_object_sparse_FUNCTIONS \
	X(PFNGLBUFFERPAGECOMMITMENTMEMNVPROC, glBufferPageCommitmentMemNV) \
	X(PFNGLTEXPAGECOMMITMENTMEMNVPROC, glTexPageCommitmentMemNV) \
	X(PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC, glNamedBufferPageCommitmentMemNV) \
	X(PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC, glTexturePageCommitmentMemNV) \

#define GL_NV_mesh_shader_FUNCTIONS \
	X(PFNGLDRAWMESHTASKSNVPROC, glDrawMeshTasksNV) \
	X(PFNGLDRAWMESHTASKSINDIRECTNVPROC, glDrawMeshTasksIndirectNV) \
	X(PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC, glMultiDrawMeshTasksIndirectNV) \
	X(PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC, glMultiDrawMeshTasksIndirectCountNV) \

#define GL_NV_path_rendering_FUNCTIONS \
	X(PFNGLGENPATHSNVPROC, glGenPathsNV) \
	X(PFNGLDELETEPATHSNVPROC, glDeletePathsNV) \
	X(PFNGLISPATHNVPROC, glIsPathNV) \
	X(PFNGLPATHCOMMANDSNVPROC, glPathCommandsNV) \
	X(PFNGLPATHCOORDSNVPROC, glPathCoordsNV) \
	X(PFNGLPATHSUBCOMMANDSNVPROC, glPathSubCommandsNV) \
	X(PFNGLPATHSUBCOORDSNVPROC, glPathSubCoordsNV) \
	X(PFNGLPATHSTRINGNVPROC, glPathStringNV) \
	X(PFNGLPATHGLYPHSNVPROC, glPathGlyphsNV) \
	X(PFNGLPATHGLYPHRANGENVPROC, glPathGlyphRangeNV) \
	X(PFNGLWEIGHTPATHSNVPROC, glWeightPathsNV) \
	X(PFNGLCOPYPATHNVPROC, glCopyPathNV) \
	X(PFNGLINTERPOLATEPATHSNVPROC, glInterpolatePathsNV) \
	X(PFNGLTRANSFORMPATHNVPROC, glTransformPathNV) \
	X(PFNGLPATHPARAMETERIVNVPROC, glPathParameterivNV) \
	X(PFNGLPATHPARAMETERINVPROC, glPathParameteriNV) \
	X(PFNGLPATHPARAMETERFVNVPROC, glPathParameterfvNV) \
	X(PFNGLPATHPARAMETERFNVPROC, glPathParameterfNV) \
	X(PFNGLPATHDASHARRAYNVPROC, glPathDashArrayNV) \
	X(PFNGLPATHSTENCILFUNCNVPROC, glPathStencilFuncNV) \
	X(PFNGLPATHSTENCILDEPTHOFFSETNVPROC, glPathStencilDepthOffsetNV) \
	X(PFNGLSTENCILFILLPATHNVPROC, glStencilFillPathNV) \
	X(PFNGLSTENCILSTROKEPATHNVPROC, glStencilStrokePathNV) \
	X(PFNGLSTENCILFILLPATHINSTANCEDNVPROC, glStencilFillPathInstancedNV) \
	X(PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC, glStencilStrokePathInstancedNV) \
	X(PFNGLPATHCOVERDEPTHFUNCNVPROC, glPathCoverDepthFuncNV) \
	X(PFNGLCOVERFILLPATHNVPROC, glCoverFillPathNV) \
	X(PFNGLCOVERSTROKEPATHNVPROC, glCoverStrokePathNV) \
	X(PFNGLCOVERFILLPATHINSTANCEDNVPROC, glCoverFillPathInstancedNV) \
	X(PFNGLCOVERSTROKEPATHINSTANCEDNVPROC, glCoverStrokePathInstancedNV) \
	X(PFNGLGETPATHPARAMETERIVNVPROC, glGetPathParameterivNV) \
	X(PFNGLGETPATHPARAMETERFVNVPROC, glGetPathParameterfvNV) \
	X(PFNGLGETPATHCOMMANDSNVPROC, glGetPathCommandsNV) \
	X(PFNGLGETPATHCOORDSNVPROC, glGetPathCoordsNV) \
	X(PFNGLGETPATHDASHARRAYNVPROC, glGetPathDashArrayNV) \
	X(PFNGLGETPATHMETRICSNVPROC, glGetPathMetricsNV) \
	X(PFNGLGETPATHMETRICRANGENVPROC, glGetPathMetricRangeNV) \
	X(PFNGLGETPATHSPACINGNVPROC, glGetPathSpacingNV) \
	X(PFNGLISPOINTINFILLPATHNVPROC, glIsPointInFillPathNV) \
	X(PFNGLISPOINTINSTROKEPATHNVPROC, glIsPointInStrokePathNV) \
	X(PFNGLGETPATHLENGTHNVPROC, glGetPathLengthNV) \
	X(PFNGLPOINTALONGPATHNVPROC, glPointAlongPathNV) \
	X(PFNGLMATRIXLOAD3X2FNVPROC, glMatrixLoad3x2fNV) \
	X(PFNGLMATRIXLOAD3X3FNVPROC, glMatrixLoad3x3fNV) \
	X(PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC, glMatrixLoadTranspose3x3fNV) \
	X(PFNGLMATRIXMULT3X2FNVPROC, glMatrixMult3x2fNV) \
	X(PFNGLMATRIXMULT3X3FNVPROC, glMatrixMult3x3fNV) \
	X(PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC, glMatrixMultTranspose3x3fNV) \
	X(PFNGLSTENCILTHENCOVERFILLPATHNVPROC, glStencilThenCoverFillPathNV) \
	X(PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC, glStencilThenCoverStrokePathNV) \
	X(PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC, glStencilThenCoverFillPathInstancedNV) \
	X(PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC, glStencilThenCoverStrokePathInstancedNV) \
	X(PFNGLPATHGLYPHINDEXRANGENVPROC, glPathGlyphIndexRangeNV) \
	X(PFNGLPATHGLYPHINDEXARRAYNVPROC, glPathGlyphIndexArrayNV) \
	X(PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC, glPathMemoryGlyphIndexArrayNV) \
	X(PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC, glProgramPathFragmentInputGenNV) \
	X(PFNGLGETPROGRAMRESOURCEFVNVPROC, glGetProgramResourcefvNV) \
	X(PFNGLPATHCOLORGENNVPROC, glPathColorGenNV) \
	X(PFNGLPATHTEXGENNVPROC, glPathTexGenNV) \
	X(PFNGLPATHFOGGENNVPROC, glPathFogGenNV) \
	X(PFNGLGETPATHCOLORGENIVNVPROC, glGetPathColorGenivNV) \
	X(PFNGLGETPATHCOLORGENFVNVPROC, glGetPathColorGenfvNV) \
	X(PFNGLGETPATHTEXGENIVNVPROC, glGetPathTexGenivNV) \
	X(PFNGLGETPATHTEXGENFVNVPROC, glGetPathTexGenfvNV) \
	X(PFNGLMATRIXFRUSTUMEXTPROC, glMatrixFrustumEXT) \
	X(PFNGLMATRIXLOADIDENTITYEXTPROC, glMatrixLoadIdentityEXT) \
	X(PFNGLMATRIXLOADTRANSPOSEFEXTPROC, glMatrixLoadTransposefEXT) \
	X(PFNGLMATRIXLOADTRANSPOSEDEXTPROC, glMatrixLoadTransposedEXT) \
	X(PFNGLMATRIXLOADFEXTPROC, glMatrixLoadfEXT) \
	X(PFNGLMATRIXLOADDEXTPROC, glMatrixLoaddEXT) \
	X(PFNGLMATRIXMULTTRANSPOSEFEXTPROC, glMatrixMultTransposefEXT) \
	X(PFNGLMATRIXMULTTRANSPOSEDEXTPROC, glMatrixMultTransposedEXT) \
	X(PFNGLMATRIXMULTFEXTPROC, glMatrixMultfEXT) \
	X(PFNGLMATRIXMULTDEXTPROC, glMatrixMultdEXT) \
	X(PFNGLMATRIXORTHOEXTPROC, glMatrixOrthoEXT) \
	X(PFNGLMATRIXPOPEXTPROC, glMatrixPopEXT) \
	X(PFNGLMATRIXPUSHEXTPROC, glMatrixPushEXT) \
	X(PFNGLMATRIXROTATEFEXTPROC, glMatrixRotatefEXT) \
	X(PFNGLMATRIXROTATEDEXTPROC, glMatrixRotatedEXT) \
	X(PFNGLMATRIXSCALEFEXTPROC, glMatrixScalefEXT) \
	X(PFNGLMATRIXSCALEDEXTPROC, glMatrixScaledEXT) \
	X(PFNGLMATRIXTRANSLATEFEXTPROC, glMatrixTranslatefEXT) \
	X(PFNGLMATRIXTRANSLATEDEXTPROC, glMatrixTranslatedEXT) \

#define GL_NV_path_rendering_shared_edge_FUNCTIONS \

#define GL_NV_primitive_shading_rate_FUNCTIONS \

#define GL_NV_representative_fragment_test_FUNCTIONS \

#define GL_NV_sample_locations_FUNCTIONS \
	X(PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC, glFramebufferSampleLocationsfvNV) \
	X(PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC, glNamedFramebufferSampleLocationsfvNV) \
	X(PFNGLRESOLVEDEPTHVALUESNVPROC, glResolveDepthValuesNV) \

#define GL_NV_scissor_exclusive_FUNCTIONS \
	X(PFNGLSCISSOREXCLUSIVENVPROC, glScissorExclusiveNV) \
	X(PFNGLSCISSOREXCLUSIVEARRAYVNVPROC, glScissorExclusiveArrayvNV) \

#define GL_NV_shader_buffer_load_FUNCTIONS \
	X(PFNGLMAKEBUFFERRESIDENTNVPROC, glMakeBufferResidentNV) \
	X(PFNGLMAKEBUFFERNONRESIDENTNVPROC, glMakeBufferNonResidentNV) \
	X(PFNGLISBUFFERRESIDENTNVPROC, glIsBufferResidentNV) \
	X(PFNGLMAKENAMEDBUFFERRESIDENTNVPROC, glMakeNamedBufferResidentNV) \
	X(PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC, glMakeNamedBufferNonResidentNV) \
	X(PFNGLISNAMEDBUFFERRESIDENTNVPROC, glIsNamedBufferResidentNV) \
	X(PFNGLGETBUFFERPARAMETERUI64VNVPROC, glGetBufferParameterui64vNV) \
	X(PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC, glGetNamedBufferParameterui64vNV) \
	X(PFNGLGETINTEGERUI64VNVPROC, glGetIntegerui64vNV) \
	X(PFNGLUNIFORMUI64NVPROC, glUniformui64NV) \
	X(PFNGLUNIFORMUI64VNVPROC, glUniformui64vNV) \
	X(PFNGLGETUNIFORMUI64VNVPROC, glGetUniformui64vNV) \
	X(PFNGLPROGRAMUNIFORMUI64NVPROC, glProgramUniformui64NV) \
	X(PFNGLPROGRAMUNIFORMUI64VNVPROC, glProgramUniformui64vNV) \

#define GL_NV_shader_buffer_store_FUNCTIONS \

#define GL_NV_shader_subgroup_partitioned_FUNCTIONS \

#define GL_NV_shader_thread_group_FUNCTIONS \

#define GL_NV_shading_rate_image_FUNCTIONS \
	X(PFNGLBINDSHADINGRATEIMAGENVPROC, glBindShadingRateImageNV) \
	X(PFNGLGETSHADINGRATEIMAGEPALETTENVPROC, glGetShadingRateImagePaletteNV) \
	X(PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC, glGetShadingRateSampleLocationivNV) \
	X(PFNGLSHADINGRATEIMAGEBARRIERNVPROC, glShadingRateImageBarrierNV) \
	X(PFNGLSHADINGRATEIMAGEPALETTENVPROC, glShadingRateImagePaletteNV) \
	X(PFNGLSHADINGRATESAMPLEORDERNVPROC, glShadingRateSampleOrderNV) \
	X(PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC, glShadingRateSampleOrderCustomNV) \

#define GL_NV_texture_barrier_FUNCTIONS \
	X(PFNGLTEXTUREBARRIERNVPROC, glTextureBarrierNV) \

#define GL_NV_uniform_buffer_unified_memory_FUNCTIONS \

#define GL_NV_vertex_attrib_integer_64bit_FUNCTIONS \
	X(PFNGLVERTEXATTRIBL1I64NVPROC, glVertexAttribL1i64NV) \
	X(PFNGLVERTEXATTRIBL2I64NVPROC, glVertexAttribL2i64NV) \
	X(PFNGLVERTEXATTRIBL3I64NVPROC, glVertexAttribL3i64NV) \
	X(PFNGLVERTEXATTRIBL4I64NVPROC, glVertexAttribL4i64NV) \
	X(PFNGLVERTEXATTRIBL1I64VNVPROC, glVertexAttribL1i64vNV) \
	X(PFNGLVERTEXATTRIBL2I64VNVPROC, glVertexAttribL2i64vNV) \
	X(PFNGLVERTEXATTRIBL3I64VNVPROC, glVertexAttribL3i64vNV) \
	X(PFNGLVERTEXATTRIBL4I64VNVPROC, glVertexAttribL4i64vNV) \
	X(PFNGLVERTEXATTRIBL1UI64NVPROC, glVertexAttribL1ui64NV) \
	X(PFNGLVERTEXATTRIBL2UI64NVPROC, glVertexAttribL2ui64NV) \
	X(PFNGLVERTEXATTRIBL3UI64NVPROC, glVertexAttribL3ui64NV) \
	X(PFNGLVERTEXATTRIBL4UI64NVPROC, glVertexAttribL4ui64NV) \
	X(PFNGLVERTEXATTRIBL1UI64VNVPROC, glVertexAttribL1ui64vNV) \
	X(PFNGLVERTEXATTRIBL2UI64VNVPROC, glVertexAttribL2ui64vNV) \
	X(PFNGLVERTEXATTRIBL3UI64VNVPROC, glVertexAttribL3ui64vNV) \
	X(PFNGLVERTEXATTRIBL4UI64VNVPROC, glVertexAttribL4ui64vNV) \
	X(PFNGLGETVERTEXATTRIBLI64VNVPROC, glGetVertexAttribLi64vNV) \
	X(PFNGLGETVERTEXATTRIBLUI64VNVPROC, glGetVertexAttribLui64vNV) \
	X(PFNGLVERTEXATTRIBLFORMATNVPROC, glVertexAttribLFormatNV) \

#define GL_NV_vertex_buffer_unified_memory_FUNCTIONS \
	X(PFNGLBUFFERADDRESSRANGENVPROC, glBufferAddressRangeNV) \
	X(PFNGLVERTEXFORMATNVPROC, glVertexFormatNV) \
	X(PFNGLNORMALFORMATNVPROC, glNormalFormatNV) \
	X(PFNGLCOLORFORMATNVPROC, glColorFormatNV) \
	X(PFNGLINDEXFORMATNVPROC, glIndexFormatNV) \
	X(PFNGLTEXCOORDFORMATNVPROC, glTexCoordFormatNV) \
	X(PFNGLEDGEFLAGFORMATNVPROC, glEdgeFlagFormatNV) \
	X(PFNGLSECONDARYCOLORFORMATNVPROC, glSecondaryColorFormatNV) \
	X(PFNGLFOGCOORDFORMATNVPROC, glFogCoordFormatNV) \
	X(PFNGLVERTEXATTRIBFORMATNVPROC, glVertexAttribFormatNV) \
	X(PFNGLVERTEXATTRIBIFORMATNVPROC, glVertexAttribIFormatNV) \
	X(PFNGLGETINTEGERUI64I_VNVPROC, glGetIntegerui64i_vNV) \

#define GL_NV_viewport_swizzle_FUNCTIONS \
	X(PFNGLVIEWPORTSWIZZLENVPROC, glViewportSwizzleNV) \

#define GL_OVR_multiview_FUNCTIONS \
	X(PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC, glFramebufferTextureMultiviewOVR) \

#define X(T, N) extern T gll_##N;
#if defined(GL_EXT_AMD_framebuffer_multisample_advanced)
GL_AMD_framebuffer_multisample_advanced_FUNCTIONS
#endif
#if defined(GL_EXT_AMD_performance_monitor)
GL_AMD_performance_monitor_FUNCTIONS
#endif
#if defined(GL_EXT_APPLE_rgb_422)
GL_APPLE_rgb_422_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_ES2_compatibility)
GL_ARB_ES2_compatibility_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_ES3_1_compatibility)
GL_ARB_ES3_1_compatibility_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_ES3_2_compatibility)
GL_ARB_ES3_2_compatibility_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_ES3_compatibility)
GL_ARB_ES3_compatibility_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_base_instance)
GL_ARB_base_instance_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_bindless_texture)
GL_ARB_bindless_texture_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_blend_func_extended)
GL_ARB_blend_func_extended_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_buffer_storage)
GL_ARB_buffer_storage_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_cl_event)
GL_ARB_cl_event_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_clear_buffer_object)
GL_ARB_clear_buffer_object_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_clear_texture)
GL_ARB_clear_texture_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_clip_control)
GL_ARB_clip_control_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_compressed_texture_pixel_storage)
GL_ARB_compressed_texture_pixel_storage_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_compute_shader)
GL_ARB_compute_shader_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_compute_variable_group_size)
GL_ARB_compute_variable_group_size_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_conditional_render_inverted)
GL_ARB_conditional_render_inverted_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_copy_buffer)
GL_ARB_copy_buffer_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_copy_image)
GL_ARB_copy_image_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_cull_distance)
GL_ARB_cull_distance_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_debug_output)
GL_ARB_debug_output_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_depth_buffer_float)
GL_ARB_depth_buffer_float_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_depth_clamp)
GL_ARB_depth_clamp_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_direct_state_access)
GL_ARB_direct_state_access_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_draw_buffers_blend)
GL_ARB_draw_buffers_blend_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_draw_elements_base_vertex)
GL_ARB_draw_elements_base_vertex_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_draw_indirect)
GL_ARB_draw_indirect_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_draw_instanced)
GL_ARB_draw_instanced_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_enhanced_layouts)
GL_ARB_enhanced_layouts_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_explicit_uniform_location)
GL_ARB_explicit_uniform_location_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_framebuffer_no_attachments)
GL_ARB_framebuffer_no_attachments_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_framebuffer_object)
GL_ARB_framebuffer_object_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_framebuffer_sRGB)
GL_ARB_framebuffer_sRGB_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_geometry_shader4)
GL_ARB_geometry_shader4_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_get_program_binary)
GL_ARB_get_program_binary_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_get_texture_sub_image)
GL_ARB_get_texture_sub_image_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_gl_spirv)
GL_ARB_gl_spirv_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_gpu_shader5)
GL_ARB_gpu_shader5_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_gpu_shader_fp64)
GL_ARB_gpu_shader_fp64_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_gpu_shader_int64)
GL_ARB_gpu_shader_int64_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_half_float_vertex)
GL_ARB_half_float_vertex_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_imaging)
GL_ARB_imaging_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_indirect_parameters)
GL_ARB_indirect_parameters_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_instanced_arrays)
GL_ARB_instanced_arrays_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_internalformat_query)
GL_ARB_internalformat_query_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_internalformat_query2)
GL_ARB_internalformat_query2_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_invalidate_subdata)
GL_ARB_invalidate_subdata_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_map_buffer_alignment)
GL_ARB_map_buffer_alignment_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_map_buffer_range)
GL_ARB_map_buffer_range_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_multi_bind)
GL_ARB_multi_bind_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_multi_draw_indirect)
GL_ARB_multi_draw_indirect_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_occlusion_query2)
GL_ARB_occlusion_query2_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_parallel_shader_compile)
GL_ARB_parallel_shader_compile_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_pipeline_statistics_query)
GL_ARB_pipeline_statistics_query_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_pixel_buffer_object)
GL_ARB_pixel_buffer_object_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_polygon_offset_clamp)
GL_ARB_polygon_offset_clamp_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_program_interface_query)
GL_ARB_program_interface_query_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_provoking_vertex)
GL_ARB_provoking_vertex_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_query_buffer_object)
GL_ARB_query_buffer_object_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_robustness)
GL_ARB_robustness_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_sample_locations)
GL_ARB_sample_locations_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_sample_shading)
GL_ARB_sample_shading_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_sampler_objects)
GL_ARB_sampler_objects_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_seamless_cube_map)
GL_ARB_seamless_cube_map_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_seamless_cubemap_per_texture)
GL_ARB_seamless_cubemap_per_texture_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_separate_shader_objects)
GL_ARB_separate_shader_objects_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_shader_atomic_counters)
GL_ARB_shader_atomic_counters_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_shader_image_load_store)
GL_ARB_shader_image_load_store_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_shader_storage_buffer_object)
GL_ARB_shader_storage_buffer_object_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_shader_subroutine)
GL_ARB_shader_subroutine_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_shading_language_include)
GL_ARB_shading_language_include_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_sparse_buffer)
GL_ARB_sparse_buffer_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_sparse_texture)
GL_ARB_sparse_texture_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_spirv_extensions)
GL_ARB_spirv_extensions_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_stencil_texturing)
GL_ARB_stencil_texturing_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_sync)
GL_ARB_sync_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_tessellation_shader)
GL_ARB_tessellation_shader_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_barrier)
GL_ARB_texture_barrier_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_border_clamp)
GL_ARB_texture_border_clamp_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_buffer_object)
GL_ARB_texture_buffer_object_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_buffer_object_rgb32)
GL_ARB_texture_buffer_object_rgb32_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_buffer_range)
GL_ARB_texture_buffer_range_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_compression_bptc)
GL_ARB_texture_compression_bptc_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_compression_rgtc)
GL_ARB_texture_compression_rgtc_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_cube_map_array)
GL_ARB_texture_cube_map_array_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_filter_anisotropic)
GL_ARB_texture_filter_anisotropic_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_filter_minmax)
GL_ARB_texture_filter_minmax_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_gather)
GL_ARB_texture_gather_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_mirror_clamp_to_edge)
GL_ARB_texture_mirror_clamp_to_edge_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_mirrored_repeat)
GL_ARB_texture_mirrored_repeat_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_multisample)
GL_ARB_texture_multisample_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_rg)
GL_ARB_texture_rg_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_rgb10_a2ui)
GL_ARB_texture_rgb10_a2ui_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_stencil8)
GL_ARB_texture_stencil8_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_storage)
GL_ARB_texture_storage_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_storage_multisample)
GL_ARB_texture_storage_multisample_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_swizzle)
GL_ARB_texture_swizzle_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_texture_view)
GL_ARB_texture_view_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_timer_query)
GL_ARB_timer_query_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_transform_feedback2)
GL_ARB_transform_feedback2_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_transform_feedback3)
GL_ARB_transform_feedback3_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_transform_feedback_instanced)
GL_ARB_transform_feedback_instanced_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_transform_feedback_overflow_query)
GL_ARB_transform_feedback_overflow_query_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_uniform_buffer_object)
GL_ARB_uniform_buffer_object_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_vertex_array_bgra)
GL_ARB_vertex_array_bgra_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_vertex_array_object)
GL_ARB_vertex_array_object_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_vertex_attrib_64bit)
GL_ARB_vertex_attrib_64bit_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_vertex_attrib_binding)
GL_ARB_vertex_attrib_binding_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_vertex_type_10f_11f_11f_rev)
GL_ARB_vertex_type_10f_11f_11f_rev_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_vertex_type_2_10_10_10_rev)
GL_ARB_vertex_type_2_10_10_10_rev_FUNCTIONS
#endif
#if defined(GL_EXT_ARB_viewport_array)
GL_ARB_viewport_array_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_EGL_image_storage)
GL_EXT_EGL_image_storage_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_debug_label)
GL_EXT_debug_label_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_debug_marker)
GL_EXT_debug_marker_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_direct_state_access)
GL_EXT_direct_state_access_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_draw_instanced)
GL_EXT_draw_instanced_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_polygon_offset_clamp)
GL_EXT_polygon_offset_clamp_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_raster_multisample)
GL_EXT_raster_multisample_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_separate_shader_objects)
GL_EXT_separate_shader_objects_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_shader_framebuffer_fetch)
GL_EXT_shader_framebuffer_fetch_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_shader_framebuffer_fetch_non_coherent)
GL_EXT_shader_framebuffer_fetch_non_coherent_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_texture_compression_s3tc)
GL_EXT_texture_compression_s3tc_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_texture_filter_minmax)
GL_EXT_texture_filter_minmax_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_texture_sRGB_R8)
GL_EXT_texture_sRGB_R8_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_texture_sRGB_RG8)
GL_EXT_texture_sRGB_RG8_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_texture_sRGB_decode)
GL_EXT_texture_sRGB_decode_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_texture_storage)
GL_EXT_texture_storage_FUNCTIONS
#endif
#if defined(GL_EXT_EXT_window_rectangles)
GL_EXT_window_rectangles_FUNCTIONS
#endif
#if defined(GL_EXT_INTEL_conservative_rasterization)
GL_INTEL_conservative_rasterization_FUNCTIONS
#endif
#if defined(GL_EXT_INTEL_framebuffer_CMAA)
GL_INTEL_framebuffer_CMAA_FUNCTIONS
#endif
#if defined(GL_EXT_INTEL_blackhole_render)
GL_INTEL_blackhole_render_FUNCTIONS
#endif
#if defined(GL_EXT_INTEL_performance_query)
GL_INTEL_performance_query_FUNCTIONS
#endif
#if defined(GL_EXT_KHR_blend_equation_advanced)
GL_KHR_blend_equation_advanced_FUNCTIONS
#endif
#if defined(GL_EXT_KHR_blend_equation_advanced_coherent)
GL_KHR_blend_equation_advanced_coherent_FUNCTIONS
#endif
#if defined(GL_EXT_KHR_context_flush_control)
GL_KHR_context_flush_control_FUNCTIONS
#endif
#if defined(GL_EXT_KHR_debug)
GL_KHR_debug_FUNCTIONS
#endif
#if defined(GL_EXT_KHR_no_error)
GL_KHR_no_error_FUNCTIONS
#endif
#if defined(GL_EXT_KHR_robustness)
GL_KHR_robustness_FUNCTIONS
#endif
#if defined(GL_EXT_KHR_shader_subgroup)
GL_KHR_shader_subgroup_FUNCTIONS
#endif
#if defined(GL_EXT_KHR_texture_compression_astc_hdr)
GL_KHR_texture_compression_astc_hdr_FUNCTIONS
#endif
#if defined(GL_EXT_KHR_texture_compression_astc_ldr)
GL_KHR_texture_compression_astc_ldr_FUNCTIONS
#endif
#if defined(GL_EXT_KHR_parallel_shader_compile)
GL_KHR_parallel_shader_compile_FUNCTIONS
#endif
#if defined(GL_EXT_MESA_framebuffer_flip_x)
GL_MESA_framebuffer_flip_x_FUNCTIONS
#endif
#if defined(GL_EXT_MESA_framebuffer_flip_y)
GL_MESA_framebuffer_flip_y_FUNCTIONS
#endif
#if defined(GL_EXT_MESA_framebuffer_swap_xy)
GL_MESA_framebuffer_swap_xy_FUNCTIONS
#endif
#if defined(GL_EXT_NV_bindless_multi_draw_indirect)
GL_NV_bindless_multi_draw_indirect_FUNCTIONS
#endif
#if defined(GL_EXT_NV_bindless_multi_draw_indirect_count)
GL_NV_bindless_multi_draw_indirect_count_FUNCTIONS
#endif
#if defined(GL_EXT_NV_bindless_texture)
GL_NV_bindless_texture_FUNCTIONS
#endif
#if defined(GL_EXT_NV_blend_equation_advanced)
GL_NV_blend_equation_advanced_FUNCTIONS
#endif
#if defined(GL_EXT_NV_blend_equation_advanced_coherent)
GL_NV_blend_equation_advanced_coherent_FUNCTIONS
#endif
#if defined(GL_EXT_NV_blend_minmax_factor)
GL_NV_blend_minmax_factor_FUNCTIONS
#endif
#if defined(GL_EXT_NV_clip_space_w_scaling)
GL_NV_clip_space_w_scaling_FUNCTIONS
#endif
#if defined(GL_EXT_NV_command_list)
GL_NV_command_list_FUNCTIONS
#endif
#if defined(GL_EXT_NV_conditional_render)
GL_NV_conditional_render_FUNCTIONS
#endif
#if defined(GL_EXT_NV_conservative_raster)
GL_NV_conservative_raster_FUNCTIONS
#endif
#if defined(GL_EXT_NV_conservative_raster_dilate)
GL_NV_conservative_raster_dilate_FUNCTIONS
#endif
#if defined(GL_EXT_NV_conservative_raster_pre_snap)
GL_NV_conservative_raster_pre_snap_FUNCTIONS
#endif
#if defined(GL_EXT_NV_conservative_raster_pre_snap_triangles)
GL_NV_conservative_raster_pre_snap_triangles_FUNCTIONS
#endif
#if defined(GL_EXT_NV_depth_buffer_float)
GL_NV_depth_buffer_float_FUNCTIONS
#endif
#if defined(GL_EXT_NV_draw_vulkan_image)
GL_NV_draw_vulkan_image_FUNCTIONS
#endif
#if defined(GL_EXT_NV_fill_rectangle)
GL_NV_fill_rectangle_FUNCTIONS
#endif
#if defined(GL_EXT_NV_fragment_coverage_to_color)
GL_NV_fragment_coverage_to_color_FUNCTIONS
#endif
#if defined(GL_EXT_NV_framebuffer_mixed_samples)
GL_NV_framebuffer_mixed_samples_FUNCTIONS
#endif
#if defined(GL_EXT_NV_framebuffer_multisample_coverage)
GL_NV_framebuffer_multisample_coverage_FUNCTIONS
#endif
#if defined(GL_EXT_NV_gpu_shader5)
GL_NV_gpu_shader5_FUNCTIONS
#endif
#if defined(GL_EXT_NV_internalformat_sample_query)
GL_NV_internalformat_sample_query_FUNCTIONS
#endif
#if defined(GL_EXT_NV_memory_attachment)
GL_NV_memory_attachment_FUNCTIONS
#endif
#if defined(GL_EXT_NV_memory_object_sparse)
GL_NV_memory_object_sparse_FUNCTIONS
#endif
#if defined(GL_EXT_NV_mesh_shader)
GL_NV_mesh_shader_FUNCTIONS
#endif
#if defined(GL_EXT_NV_path_rendering)
GL_NV_path_rendering_FUNCTIONS
#endif
#if defined(GL_EXT_NV_path_rendering_shared_edge)
GL_NV_path_rendering_shared_edge_FUNCTIONS
#endif
#if defined(GL_EXT_NV_primitive_shading_rate)
GL_NV_primitive_shading_rate_FUNCTIONS
#endif
#if defined(GL_EXT_NV_representative_fragment_test)
GL_NV_representative_fragment_test_FUNCTIONS
#endif
#if defined(GL_EXT_NV_sample_locations)
GL_NV_sample_locations_FUNCTIONS
#endif
#if defined(GL_EXT_NV_scissor_exclusive)
GL_NV_scissor_exclusive_FUNCTIONS
#endif
#if defined(GL_EXT_NV_shader_buffer_load)
GL_NV_shader_buffer_load_FUNCTIONS
#endif
#if defined(GL_EXT_NV_shader_buffer_store)
GL_NV_shader_buffer_store_FUNCTIONS
#endif
#if defined(GL_EXT_NV_shader_subgroup_partitioned)
GL_NV_shader_subgroup_partitioned_FUNCTIONS
#endif
#if defined(GL_EXT_NV_shader_thread_group)
GL_NV_shader_thread_group_FUNCTIONS
#endif
#if defined(GL_EXT_NV_shading_rate_image)
GL_NV_shading_rate_image_FUNCTIONS
#endif
#if defined(GL_EXT_NV_texture_barrier)
GL_NV_texture_barrier_FUNCTIONS
#endif
#if defined(GL_EXT_NV_uniform_buffer_unified_memory)
GL_NV_uniform_buffer_unified_memory_FUNCTIONS
#endif
#if defined(GL_EXT_NV_vertex_attrib_integer_64bit)
GL_NV_vertex_attrib_integer_64bit_FUNCTIONS
#endif
#if defined(GL_EXT_NV_vertex_buffer_unified_memory)
GL_NV_vertex_buffer_unified_memory_FUNCTIONS
#endif
#if defined(GL_EXT_NV_viewport_swizzle)
GL_NV_viewport_swizzle_FUNCTIONS
#endif
#if defined(GL_EXT_OVR_multiview)
GL_OVR_multiview_FUNCTIONS
#endif
#undef X

#ifdef __cplusplus
}
#endif
#endif // opengl_loader_h
