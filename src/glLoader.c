/* glLoader.c -- https://github.com/takeiteasy/fungl

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

#include "glLoader.h"

#define X(T, N) T gll_##N = (T)((void *)0);
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

#if defined(GL_EXT_AMD_framebuffer_multisample_advanced)
GL_AMD_framebuffer_multisample_advanced_FUNCTIONS
int EXT_GL_AMD_framebuffer_multisample_advanced_loaded = 0;
#endif
#if defined(GL_EXT_AMD_performance_monitor)
GL_AMD_performance_monitor_FUNCTIONS
int EXT_GL_AMD_performance_monitor_loaded = 0;
#endif
#if defined(GL_EXT_APPLE_rgb_422)
GL_APPLE_rgb_422_FUNCTIONS
int EXT_GL_APPLE_rgb_422_loaded = 0;
#endif
#if defined(GL_EXT_ARB_ES2_compatibility)
GL_ARB_ES2_compatibility_FUNCTIONS
int EXT_GL_ARB_ES2_compatibility_loaded = 0;
#endif
#if defined(GL_EXT_ARB_ES3_1_compatibility)
GL_ARB_ES3_1_compatibility_FUNCTIONS
int EXT_GL_ARB_ES3_1_compatibility_loaded = 0;
#endif
#if defined(GL_EXT_ARB_ES3_2_compatibility)
GL_ARB_ES3_2_compatibility_FUNCTIONS
int EXT_GL_ARB_ES3_2_compatibility_loaded = 0;
#endif
#if defined(GL_EXT_ARB_ES3_compatibility)
GL_ARB_ES3_compatibility_FUNCTIONS
int EXT_GL_ARB_ES3_compatibility_loaded = 0;
#endif
#if defined(GL_EXT_ARB_base_instance)
GL_ARB_base_instance_FUNCTIONS
int EXT_GL_ARB_base_instance_loaded = 0;
#endif
#if defined(GL_EXT_ARB_bindless_texture)
GL_ARB_bindless_texture_FUNCTIONS
int EXT_GL_ARB_bindless_texture_loaded = 0;
#endif
#if defined(GL_EXT_ARB_blend_func_extended)
GL_ARB_blend_func_extended_FUNCTIONS
int EXT_GL_ARB_blend_func_extended_loaded = 0;
#endif
#if defined(GL_EXT_ARB_buffer_storage)
GL_ARB_buffer_storage_FUNCTIONS
int EXT_GL_ARB_buffer_storage_loaded = 0;
#endif
#if defined(GL_EXT_ARB_cl_event)
GL_ARB_cl_event_FUNCTIONS
int EXT_GL_ARB_cl_event_loaded = 0;
#endif
#if defined(GL_EXT_ARB_clear_buffer_object)
GL_ARB_clear_buffer_object_FUNCTIONS
int EXT_GL_ARB_clear_buffer_object_loaded = 0;
#endif
#if defined(GL_EXT_ARB_clear_texture)
GL_ARB_clear_texture_FUNCTIONS
int EXT_GL_ARB_clear_texture_loaded = 0;
#endif
#if defined(GL_EXT_ARB_clip_control)
GL_ARB_clip_control_FUNCTIONS
int EXT_GL_ARB_clip_control_loaded = 0;
#endif
#if defined(GL_EXT_ARB_compressed_texture_pixel_storage)
GL_ARB_compressed_texture_pixel_storage_FUNCTIONS
int EXT_GL_ARB_compressed_texture_pixel_storage_loaded = 0;
#endif
#if defined(GL_EXT_ARB_compute_shader)
GL_ARB_compute_shader_FUNCTIONS
int EXT_GL_ARB_compute_shader_loaded = 0;
#endif
#if defined(GL_EXT_ARB_compute_variable_group_size)
GL_ARB_compute_variable_group_size_FUNCTIONS
int EXT_GL_ARB_compute_variable_group_size_loaded = 0;
#endif
#if defined(GL_EXT_ARB_conditional_render_inverted)
GL_ARB_conditional_render_inverted_FUNCTIONS
int EXT_GL_ARB_conditional_render_inverted_loaded = 0;
#endif
#if defined(GL_EXT_ARB_copy_buffer)
GL_ARB_copy_buffer_FUNCTIONS
int EXT_GL_ARB_copy_buffer_loaded = 0;
#endif
#if defined(GL_EXT_ARB_copy_image)
GL_ARB_copy_image_FUNCTIONS
int EXT_GL_ARB_copy_image_loaded = 0;
#endif
#if defined(GL_EXT_ARB_cull_distance)
GL_ARB_cull_distance_FUNCTIONS
int EXT_GL_ARB_cull_distance_loaded = 0;
#endif
#if defined(GL_EXT_ARB_debug_output)
GL_ARB_debug_output_FUNCTIONS
int EXT_GL_ARB_debug_output_loaded = 0;
#endif
#if defined(GL_EXT_ARB_depth_buffer_float)
GL_ARB_depth_buffer_float_FUNCTIONS
int EXT_GL_ARB_depth_buffer_float_loaded = 0;
#endif
#if defined(GL_EXT_ARB_depth_clamp)
GL_ARB_depth_clamp_FUNCTIONS
int EXT_GL_ARB_depth_clamp_loaded = 0;
#endif
#if defined(GL_EXT_ARB_direct_state_access)
GL_ARB_direct_state_access_FUNCTIONS
int EXT_GL_ARB_direct_state_access_loaded = 0;
#endif
#if defined(GL_EXT_ARB_draw_buffers_blend)
GL_ARB_draw_buffers_blend_FUNCTIONS
int EXT_GL_ARB_draw_buffers_blend_loaded = 0;
#endif
#if defined(GL_EXT_ARB_draw_elements_base_vertex)
GL_ARB_draw_elements_base_vertex_FUNCTIONS
int EXT_GL_ARB_draw_elements_base_vertex_loaded = 0;
#endif
#if defined(GL_EXT_ARB_draw_indirect)
GL_ARB_draw_indirect_FUNCTIONS
int EXT_GL_ARB_draw_indirect_loaded = 0;
#endif
#if defined(GL_EXT_ARB_draw_instanced)
GL_ARB_draw_instanced_FUNCTIONS
int EXT_GL_ARB_draw_instanced_loaded = 0;
#endif
#if defined(GL_EXT_ARB_enhanced_layouts)
GL_ARB_enhanced_layouts_FUNCTIONS
int EXT_GL_ARB_enhanced_layouts_loaded = 0;
#endif
#if defined(GL_EXT_ARB_explicit_uniform_location)
GL_ARB_explicit_uniform_location_FUNCTIONS
int EXT_GL_ARB_explicit_uniform_location_loaded = 0;
#endif
#if defined(GL_EXT_ARB_framebuffer_no_attachments)
GL_ARB_framebuffer_no_attachments_FUNCTIONS
int EXT_GL_ARB_framebuffer_no_attachments_loaded = 0;
#endif
#if defined(GL_EXT_ARB_framebuffer_object)
GL_ARB_framebuffer_object_FUNCTIONS
int EXT_GL_ARB_framebuffer_object_loaded = 0;
#endif
#if defined(GL_EXT_ARB_framebuffer_sRGB)
GL_ARB_framebuffer_sRGB_FUNCTIONS
int EXT_GL_ARB_framebuffer_sRGB_loaded = 0;
#endif
#if defined(GL_EXT_ARB_geometry_shader4)
GL_ARB_geometry_shader4_FUNCTIONS
int EXT_GL_ARB_geometry_shader4_loaded = 0;
#endif
#if defined(GL_EXT_ARB_get_program_binary)
GL_ARB_get_program_binary_FUNCTIONS
int EXT_GL_ARB_get_program_binary_loaded = 0;
#endif
#if defined(GL_EXT_ARB_get_texture_sub_image)
GL_ARB_get_texture_sub_image_FUNCTIONS
int EXT_GL_ARB_get_texture_sub_image_loaded = 0;
#endif
#if defined(GL_EXT_ARB_gl_spirv)
GL_ARB_gl_spirv_FUNCTIONS
int EXT_GL_ARB_gl_spirv_loaded = 0;
#endif
#if defined(GL_EXT_ARB_gpu_shader5)
GL_ARB_gpu_shader5_FUNCTIONS
int EXT_GL_ARB_gpu_shader5_loaded = 0;
#endif
#if defined(GL_EXT_ARB_gpu_shader_fp64)
GL_ARB_gpu_shader_fp64_FUNCTIONS
int EXT_GL_ARB_gpu_shader_fp64_loaded = 0;
#endif
#if defined(GL_EXT_ARB_gpu_shader_int64)
GL_ARB_gpu_shader_int64_FUNCTIONS
int EXT_GL_ARB_gpu_shader_int64_loaded = 0;
#endif
#if defined(GL_EXT_ARB_half_float_vertex)
GL_ARB_half_float_vertex_FUNCTIONS
int EXT_GL_ARB_half_float_vertex_loaded = 0;
#endif
#if defined(GL_EXT_ARB_imaging)
GL_ARB_imaging_FUNCTIONS
int EXT_GL_ARB_imaging_loaded = 0;
#endif
#if defined(GL_EXT_ARB_indirect_parameters)
GL_ARB_indirect_parameters_FUNCTIONS
int EXT_GL_ARB_indirect_parameters_loaded = 0;
#endif
#if defined(GL_EXT_ARB_instanced_arrays)
GL_ARB_instanced_arrays_FUNCTIONS
int EXT_GL_ARB_instanced_arrays_loaded = 0;
#endif
#if defined(GL_EXT_ARB_internalformat_query)
GL_ARB_internalformat_query_FUNCTIONS
int EXT_GL_ARB_internalformat_query_loaded = 0;
#endif
#if defined(GL_EXT_ARB_internalformat_query2)
GL_ARB_internalformat_query2_FUNCTIONS
int EXT_GL_ARB_internalformat_query2_loaded = 0;
#endif
#if defined(GL_EXT_ARB_invalidate_subdata)
GL_ARB_invalidate_subdata_FUNCTIONS
int EXT_GL_ARB_invalidate_subdata_loaded = 0;
#endif
#if defined(GL_EXT_ARB_map_buffer_alignment)
GL_ARB_map_buffer_alignment_FUNCTIONS
int EXT_GL_ARB_map_buffer_alignment_loaded = 0;
#endif
#if defined(GL_EXT_ARB_map_buffer_range)
GL_ARB_map_buffer_range_FUNCTIONS
int EXT_GL_ARB_map_buffer_range_loaded = 0;
#endif
#if defined(GL_EXT_ARB_multi_bind)
GL_ARB_multi_bind_FUNCTIONS
int EXT_GL_ARB_multi_bind_loaded = 0;
#endif
#if defined(GL_EXT_ARB_multi_draw_indirect)
GL_ARB_multi_draw_indirect_FUNCTIONS
int EXT_GL_ARB_multi_draw_indirect_loaded = 0;
#endif
#if defined(GL_EXT_ARB_occlusion_query2)
GL_ARB_occlusion_query2_FUNCTIONS
int EXT_GL_ARB_occlusion_query2_loaded = 0;
#endif
#if defined(GL_EXT_ARB_parallel_shader_compile)
GL_ARB_parallel_shader_compile_FUNCTIONS
int EXT_GL_ARB_parallel_shader_compile_loaded = 0;
#endif
#if defined(GL_EXT_ARB_pipeline_statistics_query)
GL_ARB_pipeline_statistics_query_FUNCTIONS
int EXT_GL_ARB_pipeline_statistics_query_loaded = 0;
#endif
#if defined(GL_EXT_ARB_pixel_buffer_object)
GL_ARB_pixel_buffer_object_FUNCTIONS
int EXT_GL_ARB_pixel_buffer_object_loaded = 0;
#endif
#if defined(GL_EXT_ARB_polygon_offset_clamp)
GL_ARB_polygon_offset_clamp_FUNCTIONS
int EXT_GL_ARB_polygon_offset_clamp_loaded = 0;
#endif
#if defined(GL_EXT_ARB_program_interface_query)
GL_ARB_program_interface_query_FUNCTIONS
int EXT_GL_ARB_program_interface_query_loaded = 0;
#endif
#if defined(GL_EXT_ARB_provoking_vertex)
GL_ARB_provoking_vertex_FUNCTIONS
int EXT_GL_ARB_provoking_vertex_loaded = 0;
#endif
#if defined(GL_EXT_ARB_query_buffer_object)
GL_ARB_query_buffer_object_FUNCTIONS
int EXT_GL_ARB_query_buffer_object_loaded = 0;
#endif
#if defined(GL_EXT_ARB_robustness)
GL_ARB_robustness_FUNCTIONS
int EXT_GL_ARB_robustness_loaded = 0;
#endif
#if defined(GL_EXT_ARB_sample_locations)
GL_ARB_sample_locations_FUNCTIONS
int EXT_GL_ARB_sample_locations_loaded = 0;
#endif
#if defined(GL_EXT_ARB_sample_shading)
GL_ARB_sample_shading_FUNCTIONS
int EXT_GL_ARB_sample_shading_loaded = 0;
#endif
#if defined(GL_EXT_ARB_sampler_objects)
GL_ARB_sampler_objects_FUNCTIONS
int EXT_GL_ARB_sampler_objects_loaded = 0;
#endif
#if defined(GL_EXT_ARB_seamless_cube_map)
GL_ARB_seamless_cube_map_FUNCTIONS
int EXT_GL_ARB_seamless_cube_map_loaded = 0;
#endif
#if defined(GL_EXT_ARB_seamless_cubemap_per_texture)
GL_ARB_seamless_cubemap_per_texture_FUNCTIONS
int EXT_GL_ARB_seamless_cubemap_per_texture_loaded = 0;
#endif
#if defined(GL_EXT_ARB_separate_shader_objects)
GL_ARB_separate_shader_objects_FUNCTIONS
int EXT_GL_ARB_separate_shader_objects_loaded = 0;
#endif
#if defined(GL_EXT_ARB_shader_atomic_counters)
GL_ARB_shader_atomic_counters_FUNCTIONS
int EXT_GL_ARB_shader_atomic_counters_loaded = 0;
#endif
#if defined(GL_EXT_ARB_shader_image_load_store)
GL_ARB_shader_image_load_store_FUNCTIONS
int EXT_GL_ARB_shader_image_load_store_loaded = 0;
#endif
#if defined(GL_EXT_ARB_shader_storage_buffer_object)
GL_ARB_shader_storage_buffer_object_FUNCTIONS
int EXT_GL_ARB_shader_storage_buffer_object_loaded = 0;
#endif
#if defined(GL_EXT_ARB_shader_subroutine)
GL_ARB_shader_subroutine_FUNCTIONS
int EXT_GL_ARB_shader_subroutine_loaded = 0;
#endif
#if defined(GL_EXT_ARB_shading_language_include)
GL_ARB_shading_language_include_FUNCTIONS
int EXT_GL_ARB_shading_language_include_loaded = 0;
#endif
#if defined(GL_EXT_ARB_sparse_buffer)
GL_ARB_sparse_buffer_FUNCTIONS
int EXT_GL_ARB_sparse_buffer_loaded = 0;
#endif
#if defined(GL_EXT_ARB_sparse_texture)
GL_ARB_sparse_texture_FUNCTIONS
int EXT_GL_ARB_sparse_texture_loaded = 0;
#endif
#if defined(GL_EXT_ARB_spirv_extensions)
GL_ARB_spirv_extensions_FUNCTIONS
int EXT_GL_ARB_spirv_extensions_loaded = 0;
#endif
#if defined(GL_EXT_ARB_stencil_texturing)
GL_ARB_stencil_texturing_FUNCTIONS
int EXT_GL_ARB_stencil_texturing_loaded = 0;
#endif
#if defined(GL_EXT_ARB_sync)
GL_ARB_sync_FUNCTIONS
int EXT_GL_ARB_sync_loaded = 0;
#endif
#if defined(GL_EXT_ARB_tessellation_shader)
GL_ARB_tessellation_shader_FUNCTIONS
int EXT_GL_ARB_tessellation_shader_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_barrier)
GL_ARB_texture_barrier_FUNCTIONS
int EXT_GL_ARB_texture_barrier_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_border_clamp)
GL_ARB_texture_border_clamp_FUNCTIONS
int EXT_GL_ARB_texture_border_clamp_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_buffer_object)
GL_ARB_texture_buffer_object_FUNCTIONS
int EXT_GL_ARB_texture_buffer_object_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_buffer_object_rgb32)
GL_ARB_texture_buffer_object_rgb32_FUNCTIONS
int EXT_GL_ARB_texture_buffer_object_rgb32_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_buffer_range)
GL_ARB_texture_buffer_range_FUNCTIONS
int EXT_GL_ARB_texture_buffer_range_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_compression_bptc)
GL_ARB_texture_compression_bptc_FUNCTIONS
int EXT_GL_ARB_texture_compression_bptc_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_compression_rgtc)
GL_ARB_texture_compression_rgtc_FUNCTIONS
int EXT_GL_ARB_texture_compression_rgtc_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_cube_map_array)
GL_ARB_texture_cube_map_array_FUNCTIONS
int EXT_GL_ARB_texture_cube_map_array_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_filter_anisotropic)
GL_ARB_texture_filter_anisotropic_FUNCTIONS
int EXT_GL_ARB_texture_filter_anisotropic_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_filter_minmax)
GL_ARB_texture_filter_minmax_FUNCTIONS
int EXT_GL_ARB_texture_filter_minmax_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_gather)
GL_ARB_texture_gather_FUNCTIONS
int EXT_GL_ARB_texture_gather_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_mirror_clamp_to_edge)
GL_ARB_texture_mirror_clamp_to_edge_FUNCTIONS
int EXT_GL_ARB_texture_mirror_clamp_to_edge_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_mirrored_repeat)
GL_ARB_texture_mirrored_repeat_FUNCTIONS
int EXT_GL_ARB_texture_mirrored_repeat_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_multisample)
GL_ARB_texture_multisample_FUNCTIONS
int EXT_GL_ARB_texture_multisample_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_rg)
GL_ARB_texture_rg_FUNCTIONS
int EXT_GL_ARB_texture_rg_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_rgb10_a2ui)
GL_ARB_texture_rgb10_a2ui_FUNCTIONS
int EXT_GL_ARB_texture_rgb10_a2ui_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_stencil8)
GL_ARB_texture_stencil8_FUNCTIONS
int EXT_GL_ARB_texture_stencil8_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_storage)
GL_ARB_texture_storage_FUNCTIONS
int EXT_GL_ARB_texture_storage_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_storage_multisample)
GL_ARB_texture_storage_multisample_FUNCTIONS
int EXT_GL_ARB_texture_storage_multisample_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_swizzle)
GL_ARB_texture_swizzle_FUNCTIONS
int EXT_GL_ARB_texture_swizzle_loaded = 0;
#endif
#if defined(GL_EXT_ARB_texture_view)
GL_ARB_texture_view_FUNCTIONS
int EXT_GL_ARB_texture_view_loaded = 0;
#endif
#if defined(GL_EXT_ARB_timer_query)
GL_ARB_timer_query_FUNCTIONS
int EXT_GL_ARB_timer_query_loaded = 0;
#endif
#if defined(GL_EXT_ARB_transform_feedback2)
GL_ARB_transform_feedback2_FUNCTIONS
int EXT_GL_ARB_transform_feedback2_loaded = 0;
#endif
#if defined(GL_EXT_ARB_transform_feedback3)
GL_ARB_transform_feedback3_FUNCTIONS
int EXT_GL_ARB_transform_feedback3_loaded = 0;
#endif
#if defined(GL_EXT_ARB_transform_feedback_instanced)
GL_ARB_transform_feedback_instanced_FUNCTIONS
int EXT_GL_ARB_transform_feedback_instanced_loaded = 0;
#endif
#if defined(GL_EXT_ARB_transform_feedback_overflow_query)
GL_ARB_transform_feedback_overflow_query_FUNCTIONS
int EXT_GL_ARB_transform_feedback_overflow_query_loaded = 0;
#endif
#if defined(GL_EXT_ARB_uniform_buffer_object)
GL_ARB_uniform_buffer_object_FUNCTIONS
int EXT_GL_ARB_uniform_buffer_object_loaded = 0;
#endif
#if defined(GL_EXT_ARB_vertex_array_bgra)
GL_ARB_vertex_array_bgra_FUNCTIONS
int EXT_GL_ARB_vertex_array_bgra_loaded = 0;
#endif
#if defined(GL_EXT_ARB_vertex_array_object)
GL_ARB_vertex_array_object_FUNCTIONS
int EXT_GL_ARB_vertex_array_object_loaded = 0;
#endif
#if defined(GL_EXT_ARB_vertex_attrib_64bit)
GL_ARB_vertex_attrib_64bit_FUNCTIONS
int EXT_GL_ARB_vertex_attrib_64bit_loaded = 0;
#endif
#if defined(GL_EXT_ARB_vertex_attrib_binding)
GL_ARB_vertex_attrib_binding_FUNCTIONS
int EXT_GL_ARB_vertex_attrib_binding_loaded = 0;
#endif
#if defined(GL_EXT_ARB_vertex_type_10f_11f_11f_rev)
GL_ARB_vertex_type_10f_11f_11f_rev_FUNCTIONS
int EXT_GL_ARB_vertex_type_10f_11f_11f_rev_loaded = 0;
#endif
#if defined(GL_EXT_ARB_vertex_type_2_10_10_10_rev)
GL_ARB_vertex_type_2_10_10_10_rev_FUNCTIONS
int EXT_GL_ARB_vertex_type_2_10_10_10_rev_loaded = 0;
#endif
#if defined(GL_EXT_ARB_viewport_array)
GL_ARB_viewport_array_FUNCTIONS
int EXT_GL_ARB_viewport_array_loaded = 0;
#endif
#if defined(GL_EXT_EXT_EGL_image_storage)
GL_EXT_EGL_image_storage_FUNCTIONS
int EXT_GL_EXT_EGL_image_storage_loaded = 0;
#endif
#if defined(GL_EXT_EXT_debug_label)
GL_EXT_debug_label_FUNCTIONS
int EXT_GL_EXT_debug_label_loaded = 0;
#endif
#if defined(GL_EXT_EXT_debug_marker)
GL_EXT_debug_marker_FUNCTIONS
int EXT_GL_EXT_debug_marker_loaded = 0;
#endif
#if defined(GL_EXT_EXT_direct_state_access)
GL_EXT_direct_state_access_FUNCTIONS
int EXT_GL_EXT_direct_state_access_loaded = 0;
#endif
#if defined(GL_EXT_EXT_draw_instanced)
GL_EXT_draw_instanced_FUNCTIONS
int EXT_GL_EXT_draw_instanced_loaded = 0;
#endif
#if defined(GL_EXT_EXT_polygon_offset_clamp)
GL_EXT_polygon_offset_clamp_FUNCTIONS
int EXT_GL_EXT_polygon_offset_clamp_loaded = 0;
#endif
#if defined(GL_EXT_EXT_raster_multisample)
GL_EXT_raster_multisample_FUNCTIONS
int EXT_GL_EXT_raster_multisample_loaded = 0;
#endif
#if defined(GL_EXT_EXT_separate_shader_objects)
GL_EXT_separate_shader_objects_FUNCTIONS
int EXT_GL_EXT_separate_shader_objects_loaded = 0;
#endif
#if defined(GL_EXT_EXT_shader_framebuffer_fetch)
GL_EXT_shader_framebuffer_fetch_FUNCTIONS
int EXT_GL_EXT_shader_framebuffer_fetch_loaded = 0;
#endif
#if defined(GL_EXT_EXT_shader_framebuffer_fetch_non_coherent)
GL_EXT_shader_framebuffer_fetch_non_coherent_FUNCTIONS
int EXT_GL_EXT_shader_framebuffer_fetch_non_coherent_loaded = 0;
#endif
#if defined(GL_EXT_EXT_texture_compression_s3tc)
GL_EXT_texture_compression_s3tc_FUNCTIONS
int EXT_GL_EXT_texture_compression_s3tc_loaded = 0;
#endif
#if defined(GL_EXT_EXT_texture_filter_minmax)
GL_EXT_texture_filter_minmax_FUNCTIONS
int EXT_GL_EXT_texture_filter_minmax_loaded = 0;
#endif
#if defined(GL_EXT_EXT_texture_sRGB_R8)
GL_EXT_texture_sRGB_R8_FUNCTIONS
int EXT_GL_EXT_texture_sRGB_R8_loaded = 0;
#endif
#if defined(GL_EXT_EXT_texture_sRGB_RG8)
GL_EXT_texture_sRGB_RG8_FUNCTIONS
int EXT_GL_EXT_texture_sRGB_RG8_loaded = 0;
#endif
#if defined(GL_EXT_EXT_texture_sRGB_decode)
GL_EXT_texture_sRGB_decode_FUNCTIONS
int EXT_GL_EXT_texture_sRGB_decode_loaded = 0;
#endif
#if defined(GL_EXT_EXT_texture_storage)
GL_EXT_texture_storage_FUNCTIONS
int EXT_GL_EXT_texture_storage_loaded = 0;
#endif
#if defined(GL_EXT_EXT_window_rectangles)
GL_EXT_window_rectangles_FUNCTIONS
int EXT_GL_EXT_window_rectangles_loaded = 0;
#endif
#if defined(GL_EXT_INTEL_conservative_rasterization)
GL_INTEL_conservative_rasterization_FUNCTIONS
int EXT_GL_INTEL_conservative_rasterization_loaded = 0;
#endif
#if defined(GL_EXT_INTEL_framebuffer_CMAA)
GL_INTEL_framebuffer_CMAA_FUNCTIONS
int EXT_GL_INTEL_framebuffer_CMAA_loaded = 0;
#endif
#if defined(GL_EXT_INTEL_blackhole_render)
GL_INTEL_blackhole_render_FUNCTIONS
int EXT_GL_INTEL_blackhole_render_loaded = 0;
#endif
#if defined(GL_EXT_INTEL_performance_query)
GL_INTEL_performance_query_FUNCTIONS
int EXT_GL_INTEL_performance_query_loaded = 0;
#endif
#if defined(GL_EXT_KHR_blend_equation_advanced)
GL_KHR_blend_equation_advanced_FUNCTIONS
int EXT_GL_KHR_blend_equation_advanced_loaded = 0;
#endif
#if defined(GL_EXT_KHR_blend_equation_advanced_coherent)
GL_KHR_blend_equation_advanced_coherent_FUNCTIONS
int EXT_GL_KHR_blend_equation_advanced_coherent_loaded = 0;
#endif
#if defined(GL_EXT_KHR_context_flush_control)
GL_KHR_context_flush_control_FUNCTIONS
int EXT_GL_KHR_context_flush_control_loaded = 0;
#endif
#if defined(GL_EXT_KHR_debug)
GL_KHR_debug_FUNCTIONS
int EXT_GL_KHR_debug_loaded = 0;
#endif
#if defined(GL_EXT_KHR_no_error)
GL_KHR_no_error_FUNCTIONS
int EXT_GL_KHR_no_error_loaded = 0;
#endif
#if defined(GL_EXT_KHR_robustness)
GL_KHR_robustness_FUNCTIONS
int EXT_GL_KHR_robustness_loaded = 0;
#endif
#if defined(GL_EXT_KHR_shader_subgroup)
GL_KHR_shader_subgroup_FUNCTIONS
int EXT_GL_KHR_shader_subgroup_loaded = 0;
#endif
#if defined(GL_EXT_KHR_texture_compression_astc_hdr)
GL_KHR_texture_compression_astc_hdr_FUNCTIONS
int EXT_GL_KHR_texture_compression_astc_hdr_loaded = 0;
#endif
#if defined(GL_EXT_KHR_texture_compression_astc_ldr)
GL_KHR_texture_compression_astc_ldr_FUNCTIONS
int EXT_GL_KHR_texture_compression_astc_ldr_loaded = 0;
#endif
#if defined(GL_EXT_KHR_parallel_shader_compile)
GL_KHR_parallel_shader_compile_FUNCTIONS
int EXT_GL_KHR_parallel_shader_compile_loaded = 0;
#endif
#if defined(GL_EXT_MESA_framebuffer_flip_x)
GL_MESA_framebuffer_flip_x_FUNCTIONS
int EXT_GL_MESA_framebuffer_flip_x_loaded = 0;
#endif
#if defined(GL_EXT_MESA_framebuffer_flip_y)
GL_MESA_framebuffer_flip_y_FUNCTIONS
int EXT_GL_MESA_framebuffer_flip_y_loaded = 0;
#endif
#if defined(GL_EXT_MESA_framebuffer_swap_xy)
GL_MESA_framebuffer_swap_xy_FUNCTIONS
int EXT_GL_MESA_framebuffer_swap_xy_loaded = 0;
#endif
#if defined(GL_EXT_NV_bindless_multi_draw_indirect)
GL_NV_bindless_multi_draw_indirect_FUNCTIONS
int EXT_GL_NV_bindless_multi_draw_indirect_loaded = 0;
#endif
#if defined(GL_EXT_NV_bindless_multi_draw_indirect_count)
GL_NV_bindless_multi_draw_indirect_count_FUNCTIONS
int EXT_GL_NV_bindless_multi_draw_indirect_count_loaded = 0;
#endif
#if defined(GL_EXT_NV_bindless_texture)
GL_NV_bindless_texture_FUNCTIONS
int EXT_GL_NV_bindless_texture_loaded = 0;
#endif
#if defined(GL_EXT_NV_blend_equation_advanced)
GL_NV_blend_equation_advanced_FUNCTIONS
int EXT_GL_NV_blend_equation_advanced_loaded = 0;
#endif
#if defined(GL_EXT_NV_blend_equation_advanced_coherent)
GL_NV_blend_equation_advanced_coherent_FUNCTIONS
int EXT_GL_NV_blend_equation_advanced_coherent_loaded = 0;
#endif
#if defined(GL_EXT_NV_blend_minmax_factor)
GL_NV_blend_minmax_factor_FUNCTIONS
int EXT_GL_NV_blend_minmax_factor_loaded = 0;
#endif
#if defined(GL_EXT_NV_clip_space_w_scaling)
GL_NV_clip_space_w_scaling_FUNCTIONS
int EXT_GL_NV_clip_space_w_scaling_loaded = 0;
#endif
#if defined(GL_EXT_NV_command_list)
GL_NV_command_list_FUNCTIONS
int EXT_GL_NV_command_list_loaded = 0;
#endif
#if defined(GL_EXT_NV_conditional_render)
GL_NV_conditional_render_FUNCTIONS
int EXT_GL_NV_conditional_render_loaded = 0;
#endif
#if defined(GL_EXT_NV_conservative_raster)
GL_NV_conservative_raster_FUNCTIONS
int EXT_GL_NV_conservative_raster_loaded = 0;
#endif
#if defined(GL_EXT_NV_conservative_raster_dilate)
GL_NV_conservative_raster_dilate_FUNCTIONS
int EXT_GL_NV_conservative_raster_dilate_loaded = 0;
#endif
#if defined(GL_EXT_NV_conservative_raster_pre_snap)
GL_NV_conservative_raster_pre_snap_FUNCTIONS
int EXT_GL_NV_conservative_raster_pre_snap_loaded = 0;
#endif
#if defined(GL_EXT_NV_conservative_raster_pre_snap_triangles)
GL_NV_conservative_raster_pre_snap_triangles_FUNCTIONS
int EXT_GL_NV_conservative_raster_pre_snap_triangles_loaded = 0;
#endif
#if defined(GL_EXT_NV_depth_buffer_float)
GL_NV_depth_buffer_float_FUNCTIONS
int EXT_GL_NV_depth_buffer_float_loaded = 0;
#endif
#if defined(GL_EXT_NV_draw_vulkan_image)
GL_NV_draw_vulkan_image_FUNCTIONS
int EXT_GL_NV_draw_vulkan_image_loaded = 0;
#endif
#if defined(GL_EXT_NV_fill_rectangle)
GL_NV_fill_rectangle_FUNCTIONS
int EXT_GL_NV_fill_rectangle_loaded = 0;
#endif
#if defined(GL_EXT_NV_fragment_coverage_to_color)
GL_NV_fragment_coverage_to_color_FUNCTIONS
int EXT_GL_NV_fragment_coverage_to_color_loaded = 0;
#endif
#if defined(GL_EXT_NV_framebuffer_mixed_samples)
GL_NV_framebuffer_mixed_samples_FUNCTIONS
int EXT_GL_NV_framebuffer_mixed_samples_loaded = 0;
#endif
#if defined(GL_EXT_NV_framebuffer_multisample_coverage)
GL_NV_framebuffer_multisample_coverage_FUNCTIONS
int EXT_GL_NV_framebuffer_multisample_coverage_loaded = 0;
#endif
#if defined(GL_EXT_NV_gpu_shader5)
GL_NV_gpu_shader5_FUNCTIONS
int EXT_GL_NV_gpu_shader5_loaded = 0;
#endif
#if defined(GL_EXT_NV_internalformat_sample_query)
GL_NV_internalformat_sample_query_FUNCTIONS
int EXT_GL_NV_internalformat_sample_query_loaded = 0;
#endif
#if defined(GL_EXT_NV_memory_attachment)
GL_NV_memory_attachment_FUNCTIONS
int EXT_GL_NV_memory_attachment_loaded = 0;
#endif
#if defined(GL_EXT_NV_memory_object_sparse)
GL_NV_memory_object_sparse_FUNCTIONS
int EXT_GL_NV_memory_object_sparse_loaded = 0;
#endif
#if defined(GL_EXT_NV_mesh_shader)
GL_NV_mesh_shader_FUNCTIONS
int EXT_GL_NV_mesh_shader_loaded = 0;
#endif
#if defined(GL_EXT_NV_path_rendering)
GL_NV_path_rendering_FUNCTIONS
int EXT_GL_NV_path_rendering_loaded = 0;
#endif
#if defined(GL_EXT_NV_path_rendering_shared_edge)
GL_NV_path_rendering_shared_edge_FUNCTIONS
int EXT_GL_NV_path_rendering_shared_edge_loaded = 0;
#endif
#if defined(GL_EXT_NV_primitive_shading_rate)
GL_NV_primitive_shading_rate_FUNCTIONS
int EXT_GL_NV_primitive_shading_rate_loaded = 0;
#endif
#if defined(GL_EXT_NV_representative_fragment_test)
GL_NV_representative_fragment_test_FUNCTIONS
int EXT_GL_NV_representative_fragment_test_loaded = 0;
#endif
#if defined(GL_EXT_NV_sample_locations)
GL_NV_sample_locations_FUNCTIONS
int EXT_GL_NV_sample_locations_loaded = 0;
#endif
#if defined(GL_EXT_NV_scissor_exclusive)
GL_NV_scissor_exclusive_FUNCTIONS
int EXT_GL_NV_scissor_exclusive_loaded = 0;
#endif
#if defined(GL_EXT_NV_shader_buffer_load)
GL_NV_shader_buffer_load_FUNCTIONS
int EXT_GL_NV_shader_buffer_load_loaded = 0;
#endif
#if defined(GL_EXT_NV_shader_buffer_store)
GL_NV_shader_buffer_store_FUNCTIONS
int EXT_GL_NV_shader_buffer_store_loaded = 0;
#endif
#if defined(GL_EXT_NV_shader_subgroup_partitioned)
GL_NV_shader_subgroup_partitioned_FUNCTIONS
int EXT_GL_NV_shader_subgroup_partitioned_loaded = 0;
#endif
#if defined(GL_EXT_NV_shader_thread_group)
GL_NV_shader_thread_group_FUNCTIONS
int EXT_GL_NV_shader_thread_group_loaded = 0;
#endif
#if defined(GL_EXT_NV_shading_rate_image)
GL_NV_shading_rate_image_FUNCTIONS
int EXT_GL_NV_shading_rate_image_loaded = 0;
#endif
#if defined(GL_EXT_NV_texture_barrier)
GL_NV_texture_barrier_FUNCTIONS
int EXT_GL_NV_texture_barrier_loaded = 0;
#endif
#if defined(GL_EXT_NV_uniform_buffer_unified_memory)
GL_NV_uniform_buffer_unified_memory_FUNCTIONS
int EXT_GL_NV_uniform_buffer_unified_memory_loaded = 0;
#endif
#if defined(GL_EXT_NV_vertex_attrib_integer_64bit)
GL_NV_vertex_attrib_integer_64bit_FUNCTIONS
int EXT_GL_NV_vertex_attrib_integer_64bit_loaded = 0;
#endif
#if defined(GL_EXT_NV_vertex_buffer_unified_memory)
GL_NV_vertex_buffer_unified_memory_FUNCTIONS
int EXT_GL_NV_vertex_buffer_unified_memory_loaded = 0;
#endif
#if defined(GL_EXT_NV_viewport_swizzle)
GL_NV_viewport_swizzle_FUNCTIONS
int EXT_GL_NV_viewport_swizzle_loaded = 0;
#endif
#if defined(GL_EXT_OVR_multiview)
GL_OVR_multiview_FUNCTIONS
int EXT_GL_OVR_multiview_loaded = 0;
#endif
#undef X

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(__CYGWIN__)
#ifndef _WINDOWS_
#undef APIENTRY
#endif
#include <windows.h>
static HMODULE libGL;

typedef void* (APIENTRYP PFNWGLGETPROCADDRESSPROC_PRIVATE)(const char*);
static PFNWGLGETPROCADDRESSPROC_PRIVATE glLoaderGetProcAddressPtr;

#ifdef _MSC_VER
#ifdef __has_include
#if __has_include(<winapifamily.h>)
#define HAVE_WINAPIFAMILY 1
#endif
#elif _MSC_VER >= 1700 && !_USING_V110_SDK71_
#define HAVE_WINAPIFAMILY 1
#endif
#endif

#ifdef HAVE_WINAPIFAMILY
#include <winapifamily.h>
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#define IS_UWP 1
#endif
#endif

static int OpenGLLibrary(void) {
#ifndef IS_UWP
    if ((libGL = LoadLibraryW(L"opengl32.dll"))) {
        void(*tmp)(void);
        tmp = (void(*)(void)) GetProcAddress(libGL, "wglGetProcAddress");
        glLoaderGetProcAddressPtr = (PFNWGLGETPROCADDRESSPROC_PRIVATE)tmp;
        return glLoaderGetProcAddressPtr != NULL;
    }
#endif
    return 0;
}

static void CloseGLLibrary(void) {
    if (libGL) {
        FreeLibrary((HMODULE)libGL);
        libGL = NULL;
    }
}
#else
#include <dlfcn.h>
static void* libGL;

#if !defined(__APPLE__) && !defined(__HAIKU__)
typedef void* (APIENTRYP PFNGLXGETPROCADDRESSPROC_PRIVATE)(const char*);
static PFNGLXGETPROCADDRESSPROC_PRIVATE glLoaderGetProcAddressPtr;
#endif

static int OpenGLLibrary(void) {
#ifdef __APPLE__
    static const char *NAMES[] = {
        "../Frameworks/OpenGL.framework/OpenGL",
        "/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"
    };
#else
    static const char *NAMES[] = {"libGL.so.1", "libGL.so"};
#endif

    unsigned int index = 0;
    for (index = 0; index < (sizeof(NAMES) / sizeof(NAMES[0])); index++) {
        if ((libGL = dlopen(NAMES[index], RTLD_NOW | RTLD_GLOBAL))) {
#if defined(__APPLE__) || defined(__HAIKU__)
            return 1;
#else
            glLoaderGetProcAddressPtr = (PFNGLXGETPROCADDRESSPROC_PRIVATE)dlsym(libGL,
                "glXGetProcAddressARB");
            return glLoaderGetProcAddressPtr != NULL;
#endif
        }
    }

    return 0;
}

static void CloseGLLibrary(void) {
    if (libGL) {
        dlclose(libGL);
        libGL = NULL;
    }
}
#endif

static void* GetGLProc(const char *namez) {
    void* result = NULL;
    if (libGL == NULL)
        return NULL;

#if !defined(__APPLE__) && !defined(__HAIKU__)
    if (glLoaderGetProcAddressPtr)
        result = glLoaderGetProcAddressPtr(namez);
#endif
    if (!result) {
#if defined(_WIN32) || defined(__CYGWIN__)
        result = (void*)GetProcAddress((HMODULE)libGL, namez);
#else
        result = dlsym(libGL, namez);
#endif
    }

    return result;
}

int glLoadFunctions(void) {
    int status = 0;

    if (OpenGLLibrary()) {
        status = glLoadGLLoader(&GetGLProc);
        CloseGLLibrary();
    }

    return status;
}

static int max_loaded_major = 1;
static int max_loaded_minor = 0;
static const char *exts = NULL;
static int num_exts_i = 0;
static char **exts_i = NULL;

static int GetExtensions(void) {
#if GL_LOAD_VERSION >= GL_VERSION_3_0
    if (max_loaded_major < 3) {
#endif
        exts = (const char*)glGetString(GL_EXTENSIONS);
#if GL_LOAD_VERSION >= GL_VERSION_3_0
    } else {
        unsigned int index;

        num_exts_i = 0;
        glGetIntegerv(GL_NUM_EXTENSIONS, &num_exts_i);
        if (num_exts_i > 0)
            exts_i = malloc((size_t)num_exts_i * (sizeof *exts_i));

        if (exts_i == NULL) {
            return 0;
        }

        for (index = 0; index < (unsigned)num_exts_i; index++) {
            const char *gl_str_tmp = (const char*)glGetStringi(GL_EXTENSIONS, index);
            size_t len = strlen(gl_str_tmp);

            char *local_str = malloc((len+1) * sizeof(char));
            if (local_str != NULL)
                memcpy(local_str, gl_str_tmp, (len+1) * sizeof(char));
            exts_i[index] = local_str;
        }
    }
#endif
    return 1;
}

static void FreeExtensions(void) {
    if (exts_i) {
        int index;
        for (index = 0; index < num_exts_i; index++)
            free((char *)exts_i[index]);
        free((void *)exts_i);
        exts_i = NULL;
    }
}

static int FindExtension(const char *ext) {
#if GL_LOAD_VERSION >= GL_VERSION_3_0
    if (max_loaded_major < 3) {
#endif
        const char *extensions;
        const char *loc;
        const char *terminator;
        extensions = exts;
        if (!extensions || !ext)
            return 0;

        while(1) {
            if (!(loc = strstr(extensions, ext)))
                return 0;

            terminator = loc + strlen(ext);
            if ((loc == extensions || *(loc - 1) == ' ') && (*terminator == ' ' || *terminator == '\0'))
                return 1;
            extensions = terminator;
        }
#if GL_LOAD_VERSION >= GL_VERSION_3_0
    } else {
        int index;
        if (exts_i == NULL) return 0;
        for (index = 0; index < num_exts_i; index++) {
            const char *e = exts_i[index];

            if (exts_i[index] != NULL && strcmp(e, ext) == 0)
                return 1;
        }
    }
#endif

    return 0;
}

static void FindGLCoreVersion(void) {
    /* Thank you @elmindreda
     * https://github.com/elmindreda/greg/blob/master/templates/greg.c.in#L176
     * https://github.com/glfw/glfw/blob/master/src/context.c#L36
     */
    const char* prefixes[] = {
        "OpenGL ES-CM ",
        "OpenGL ES-CL ",
        "OpenGL ES ",
        NULL
    };

    const char *version = (const char*)glGetString(GL_VERSION);
    if (!version)
        return;

    for (int i = 0;  prefixes[i];  i++) {
        const size_t length = strlen(prefixes[i]);
        if (strncmp(version, prefixes[i], length) == 0) {
            version += length;
            break;
        }
    }

/* PR #18 */
#ifdef _MSC_VER
    sscanf_s(version, "%d.%d", &max_loaded_major, &max_loaded_minor);
#else
    sscanf(version, "%d.%d", &max_loaded_major, &max_loaded_minor);
#endif
}

#define X(T, N)             \
    if (!(gll_##N = (T)load(#N))) \
        failures++;
int glLoadGLLoader(glLoadProc load) {
    int failures = 0;
    if (!(glGetString = (PFNGLGETSTRINGPROC)load("glGetString")))
        return 1;
    if (!glGetString(GL_VERSION))
        return 1;
    FindGLCoreVersion();
                      
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

    if (!GetExtensions())
        return failures + 1;

#define X(T, N)                   \
    if (!(gll_##N = (T)load(#N))) \
        failures++;               \
    else                          \
        EXT_##N##_loaded = 1;
#if defined(GL_EXT_AMD_framebuffer_multisample_advanced)
	if ((EXT_GL_AMD_framebuffer_multisample_advanced_loaded = FindExtension("GL_AMD_framebuffer_multisample_advanced"))) {
		GL_AMD_framebuffer_multisample_advanced_FUNCTIONS
	}
#endif
#if defined(GL_EXT_AMD_performance_monitor)
	if ((EXT_GL_AMD_performance_monitor_loaded = FindExtension("GL_AMD_performance_monitor"))) {
		GL_AMD_performance_monitor_FUNCTIONS
	}
#endif
#if defined(GL_EXT_APPLE_rgb_422)
	if ((EXT_GL_APPLE_rgb_422_loaded = FindExtension("GL_APPLE_rgb_422"))) {
		GL_APPLE_rgb_422_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_ES2_compatibility)
	if ((EXT_GL_ARB_ES2_compatibility_loaded = FindExtension("GL_ARB_ES2_compatibility"))) {
		GL_ARB_ES2_compatibility_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_ES3_1_compatibility)
	if ((EXT_GL_ARB_ES3_1_compatibility_loaded = FindExtension("GL_ARB_ES3_1_compatibility"))) {
		GL_ARB_ES3_1_compatibility_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_ES3_2_compatibility)
	if ((EXT_GL_ARB_ES3_2_compatibility_loaded = FindExtension("GL_ARB_ES3_2_compatibility"))) {
		GL_ARB_ES3_2_compatibility_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_ES3_compatibility)
	if ((EXT_GL_ARB_ES3_compatibility_loaded = FindExtension("GL_ARB_ES3_compatibility"))) {
		GL_ARB_ES3_compatibility_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_base_instance)
	if ((EXT_GL_ARB_base_instance_loaded = FindExtension("GL_ARB_base_instance"))) {
		GL_ARB_base_instance_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_bindless_texture)
	if ((EXT_GL_ARB_bindless_texture_loaded = FindExtension("GL_ARB_bindless_texture"))) {
		GL_ARB_bindless_texture_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_blend_func_extended)
	if ((EXT_GL_ARB_blend_func_extended_loaded = FindExtension("GL_ARB_blend_func_extended"))) {
		GL_ARB_blend_func_extended_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_buffer_storage)
	if ((EXT_GL_ARB_buffer_storage_loaded = FindExtension("GL_ARB_buffer_storage"))) {
		GL_ARB_buffer_storage_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_cl_event)
	if ((EXT_GL_ARB_cl_event_loaded = FindExtension("GL_ARB_cl_event"))) {
		GL_ARB_cl_event_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_clear_buffer_object)
	if ((EXT_GL_ARB_clear_buffer_object_loaded = FindExtension("GL_ARB_clear_buffer_object"))) {
		GL_ARB_clear_buffer_object_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_clear_texture)
	if ((EXT_GL_ARB_clear_texture_loaded = FindExtension("GL_ARB_clear_texture"))) {
		GL_ARB_clear_texture_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_clip_control)
	if ((EXT_GL_ARB_clip_control_loaded = FindExtension("GL_ARB_clip_control"))) {
		GL_ARB_clip_control_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_compressed_texture_pixel_storage)
	if ((EXT_GL_ARB_compressed_texture_pixel_storage_loaded = FindExtension("GL_ARB_compressed_texture_pixel_storage"))) {
		GL_ARB_compressed_texture_pixel_storage_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_compute_shader)
	if ((EXT_GL_ARB_compute_shader_loaded = FindExtension("GL_ARB_compute_shader"))) {
		GL_ARB_compute_shader_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_compute_variable_group_size)
	if ((EXT_GL_ARB_compute_variable_group_size_loaded = FindExtension("GL_ARB_compute_variable_group_size"))) {
		GL_ARB_compute_variable_group_size_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_conditional_render_inverted)
	if ((EXT_GL_ARB_conditional_render_inverted_loaded = FindExtension("GL_ARB_conditional_render_inverted"))) {
		GL_ARB_conditional_render_inverted_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_copy_buffer)
	if ((EXT_GL_ARB_copy_buffer_loaded = FindExtension("GL_ARB_copy_buffer"))) {
		GL_ARB_copy_buffer_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_copy_image)
	if ((EXT_GL_ARB_copy_image_loaded = FindExtension("GL_ARB_copy_image"))) {
		GL_ARB_copy_image_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_cull_distance)
	if ((EXT_GL_ARB_cull_distance_loaded = FindExtension("GL_ARB_cull_distance"))) {
		GL_ARB_cull_distance_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_debug_output)
	if ((EXT_GL_ARB_debug_output_loaded = FindExtension("GL_ARB_debug_output"))) {
		GL_ARB_debug_output_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_depth_buffer_float)
	if ((EXT_GL_ARB_depth_buffer_float_loaded = FindExtension("GL_ARB_depth_buffer_float"))) {
		GL_ARB_depth_buffer_float_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_depth_clamp)
	if ((EXT_GL_ARB_depth_clamp_loaded = FindExtension("GL_ARB_depth_clamp"))) {
		GL_ARB_depth_clamp_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_direct_state_access)
	if ((EXT_GL_ARB_direct_state_access_loaded = FindExtension("GL_ARB_direct_state_access"))) {
		GL_ARB_direct_state_access_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_draw_buffers_blend)
	if ((EXT_GL_ARB_draw_buffers_blend_loaded = FindExtension("GL_ARB_draw_buffers_blend"))) {
		GL_ARB_draw_buffers_blend_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_draw_elements_base_vertex)
	if ((EXT_GL_ARB_draw_elements_base_vertex_loaded = FindExtension("GL_ARB_draw_elements_base_vertex"))) {
		GL_ARB_draw_elements_base_vertex_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_draw_indirect)
	if ((EXT_GL_ARB_draw_indirect_loaded = FindExtension("GL_ARB_draw_indirect"))) {
		GL_ARB_draw_indirect_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_draw_instanced)
	if ((EXT_GL_ARB_draw_instanced_loaded = FindExtension("GL_ARB_draw_instanced"))) {
		GL_ARB_draw_instanced_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_enhanced_layouts)
	if ((EXT_GL_ARB_enhanced_layouts_loaded = FindExtension("GL_ARB_enhanced_layouts"))) {
		GL_ARB_enhanced_layouts_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_explicit_uniform_location)
	if ((EXT_GL_ARB_explicit_uniform_location_loaded = FindExtension("GL_ARB_explicit_uniform_location"))) {
		GL_ARB_explicit_uniform_location_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_framebuffer_no_attachments)
	if ((EXT_GL_ARB_framebuffer_no_attachments_loaded = FindExtension("GL_ARB_framebuffer_no_attachments"))) {
		GL_ARB_framebuffer_no_attachments_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_framebuffer_object)
	if ((EXT_GL_ARB_framebuffer_object_loaded = FindExtension("GL_ARB_framebuffer_object"))) {
		GL_ARB_framebuffer_object_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_framebuffer_sRGB)
	if ((EXT_GL_ARB_framebuffer_sRGB_loaded = FindExtension("GL_ARB_framebuffer_sRGB"))) {
		GL_ARB_framebuffer_sRGB_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_geometry_shader4)
	if ((EXT_GL_ARB_geometry_shader4_loaded = FindExtension("GL_ARB_geometry_shader4"))) {
		GL_ARB_geometry_shader4_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_get_program_binary)
	if ((EXT_GL_ARB_get_program_binary_loaded = FindExtension("GL_ARB_get_program_binary"))) {
		GL_ARB_get_program_binary_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_get_texture_sub_image)
	if ((EXT_GL_ARB_get_texture_sub_image_loaded = FindExtension("GL_ARB_get_texture_sub_image"))) {
		GL_ARB_get_texture_sub_image_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_gl_spirv)
	if ((EXT_GL_ARB_gl_spirv_loaded = FindExtension("GL_ARB_gl_spirv"))) {
		GL_ARB_gl_spirv_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_gpu_shader5)
	if ((EXT_GL_ARB_gpu_shader5_loaded = FindExtension("GL_ARB_gpu_shader5"))) {
		GL_ARB_gpu_shader5_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_gpu_shader_fp64)
	if ((EXT_GL_ARB_gpu_shader_fp64_loaded = FindExtension("GL_ARB_gpu_shader_fp64"))) {
		GL_ARB_gpu_shader_fp64_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_gpu_shader_int64)
	if ((EXT_GL_ARB_gpu_shader_int64_loaded = FindExtension("GL_ARB_gpu_shader_int64"))) {
		GL_ARB_gpu_shader_int64_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_half_float_vertex)
	if ((EXT_GL_ARB_half_float_vertex_loaded = FindExtension("GL_ARB_half_float_vertex"))) {
		GL_ARB_half_float_vertex_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_imaging)
	if ((EXT_GL_ARB_imaging_loaded = FindExtension("GL_ARB_imaging"))) {
		GL_ARB_imaging_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_indirect_parameters)
	if ((EXT_GL_ARB_indirect_parameters_loaded = FindExtension("GL_ARB_indirect_parameters"))) {
		GL_ARB_indirect_parameters_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_instanced_arrays)
	if ((EXT_GL_ARB_instanced_arrays_loaded = FindExtension("GL_ARB_instanced_arrays"))) {
		GL_ARB_instanced_arrays_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_internalformat_query)
	if ((EXT_GL_ARB_internalformat_query_loaded = FindExtension("GL_ARB_internalformat_query"))) {
		GL_ARB_internalformat_query_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_internalformat_query2)
	if ((EXT_GL_ARB_internalformat_query2_loaded = FindExtension("GL_ARB_internalformat_query2"))) {
		GL_ARB_internalformat_query2_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_invalidate_subdata)
	if ((EXT_GL_ARB_invalidate_subdata_loaded = FindExtension("GL_ARB_invalidate_subdata"))) {
		GL_ARB_invalidate_subdata_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_map_buffer_alignment)
	if ((EXT_GL_ARB_map_buffer_alignment_loaded = FindExtension("GL_ARB_map_buffer_alignment"))) {
		GL_ARB_map_buffer_alignment_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_map_buffer_range)
	if ((EXT_GL_ARB_map_buffer_range_loaded = FindExtension("GL_ARB_map_buffer_range"))) {
		GL_ARB_map_buffer_range_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_multi_bind)
	if ((EXT_GL_ARB_multi_bind_loaded = FindExtension("GL_ARB_multi_bind"))) {
		GL_ARB_multi_bind_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_multi_draw_indirect)
	if ((EXT_GL_ARB_multi_draw_indirect_loaded = FindExtension("GL_ARB_multi_draw_indirect"))) {
		GL_ARB_multi_draw_indirect_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_occlusion_query2)
	if ((EXT_GL_ARB_occlusion_query2_loaded = FindExtension("GL_ARB_occlusion_query2"))) {
		GL_ARB_occlusion_query2_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_parallel_shader_compile)
	if ((EXT_GL_ARB_parallel_shader_compile_loaded = FindExtension("GL_ARB_parallel_shader_compile"))) {
		GL_ARB_parallel_shader_compile_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_pipeline_statistics_query)
	if ((EXT_GL_ARB_pipeline_statistics_query_loaded = FindExtension("GL_ARB_pipeline_statistics_query"))) {
		GL_ARB_pipeline_statistics_query_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_pixel_buffer_object)
	if ((EXT_GL_ARB_pixel_buffer_object_loaded = FindExtension("GL_ARB_pixel_buffer_object"))) {
		GL_ARB_pixel_buffer_object_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_polygon_offset_clamp)
	if ((EXT_GL_ARB_polygon_offset_clamp_loaded = FindExtension("GL_ARB_polygon_offset_clamp"))) {
		GL_ARB_polygon_offset_clamp_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_program_interface_query)
	if ((EXT_GL_ARB_program_interface_query_loaded = FindExtension("GL_ARB_program_interface_query"))) {
		GL_ARB_program_interface_query_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_provoking_vertex)
	if ((EXT_GL_ARB_provoking_vertex_loaded = FindExtension("GL_ARB_provoking_vertex"))) {
		GL_ARB_provoking_vertex_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_query_buffer_object)
	if ((EXT_GL_ARB_query_buffer_object_loaded = FindExtension("GL_ARB_query_buffer_object"))) {
		GL_ARB_query_buffer_object_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_robustness)
	if ((EXT_GL_ARB_robustness_loaded = FindExtension("GL_ARB_robustness"))) {
		GL_ARB_robustness_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_sample_locations)
	if ((EXT_GL_ARB_sample_locations_loaded = FindExtension("GL_ARB_sample_locations"))) {
		GL_ARB_sample_locations_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_sample_shading)
	if ((EXT_GL_ARB_sample_shading_loaded = FindExtension("GL_ARB_sample_shading"))) {
		GL_ARB_sample_shading_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_sampler_objects)
	if ((EXT_GL_ARB_sampler_objects_loaded = FindExtension("GL_ARB_sampler_objects"))) {
		GL_ARB_sampler_objects_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_seamless_cube_map)
	if ((EXT_GL_ARB_seamless_cube_map_loaded = FindExtension("GL_ARB_seamless_cube_map"))) {
		GL_ARB_seamless_cube_map_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_seamless_cubemap_per_texture)
	if ((EXT_GL_ARB_seamless_cubemap_per_texture_loaded = FindExtension("GL_ARB_seamless_cubemap_per_texture"))) {
		GL_ARB_seamless_cubemap_per_texture_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_separate_shader_objects)
	if ((EXT_GL_ARB_separate_shader_objects_loaded = FindExtension("GL_ARB_separate_shader_objects"))) {
		GL_ARB_separate_shader_objects_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_shader_atomic_counters)
	if ((EXT_GL_ARB_shader_atomic_counters_loaded = FindExtension("GL_ARB_shader_atomic_counters"))) {
		GL_ARB_shader_atomic_counters_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_shader_image_load_store)
	if ((EXT_GL_ARB_shader_image_load_store_loaded = FindExtension("GL_ARB_shader_image_load_store"))) {
		GL_ARB_shader_image_load_store_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_shader_storage_buffer_object)
	if ((EXT_GL_ARB_shader_storage_buffer_object_loaded = FindExtension("GL_ARB_shader_storage_buffer_object"))) {
		GL_ARB_shader_storage_buffer_object_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_shader_subroutine)
	if ((EXT_GL_ARB_shader_subroutine_loaded = FindExtension("GL_ARB_shader_subroutine"))) {
		GL_ARB_shader_subroutine_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_shading_language_include)
	if ((EXT_GL_ARB_shading_language_include_loaded = FindExtension("GL_ARB_shading_language_include"))) {
		GL_ARB_shading_language_include_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_sparse_buffer)
	if ((EXT_GL_ARB_sparse_buffer_loaded = FindExtension("GL_ARB_sparse_buffer"))) {
		GL_ARB_sparse_buffer_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_sparse_texture)
	if ((EXT_GL_ARB_sparse_texture_loaded = FindExtension("GL_ARB_sparse_texture"))) {
		GL_ARB_sparse_texture_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_spirv_extensions)
	if ((EXT_GL_ARB_spirv_extensions_loaded = FindExtension("GL_ARB_spirv_extensions"))) {
		GL_ARB_spirv_extensions_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_stencil_texturing)
	if ((EXT_GL_ARB_stencil_texturing_loaded = FindExtension("GL_ARB_stencil_texturing"))) {
		GL_ARB_stencil_texturing_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_sync)
	if ((EXT_GL_ARB_sync_loaded = FindExtension("GL_ARB_sync"))) {
		GL_ARB_sync_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_tessellation_shader)
	if ((EXT_GL_ARB_tessellation_shader_loaded = FindExtension("GL_ARB_tessellation_shader"))) {
		GL_ARB_tessellation_shader_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_barrier)
	if ((EXT_GL_ARB_texture_barrier_loaded = FindExtension("GL_ARB_texture_barrier"))) {
		GL_ARB_texture_barrier_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_border_clamp)
	if ((EXT_GL_ARB_texture_border_clamp_loaded = FindExtension("GL_ARB_texture_border_clamp"))) {
		GL_ARB_texture_border_clamp_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_buffer_object)
	if ((EXT_GL_ARB_texture_buffer_object_loaded = FindExtension("GL_ARB_texture_buffer_object"))) {
		GL_ARB_texture_buffer_object_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_buffer_object_rgb32)
	if ((EXT_GL_ARB_texture_buffer_object_rgb32_loaded = FindExtension("GL_ARB_texture_buffer_object_rgb32"))) {
		GL_ARB_texture_buffer_object_rgb32_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_buffer_range)
	if ((EXT_GL_ARB_texture_buffer_range_loaded = FindExtension("GL_ARB_texture_buffer_range"))) {
		GL_ARB_texture_buffer_range_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_compression_bptc)
	if ((EXT_GL_ARB_texture_compression_bptc_loaded = FindExtension("GL_ARB_texture_compression_bptc"))) {
		GL_ARB_texture_compression_bptc_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_compression_rgtc)
	if ((EXT_GL_ARB_texture_compression_rgtc_loaded = FindExtension("GL_ARB_texture_compression_rgtc"))) {
		GL_ARB_texture_compression_rgtc_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_cube_map_array)
	if ((EXT_GL_ARB_texture_cube_map_array_loaded = FindExtension("GL_ARB_texture_cube_map_array"))) {
		GL_ARB_texture_cube_map_array_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_filter_anisotropic)
	if ((EXT_GL_ARB_texture_filter_anisotropic_loaded = FindExtension("GL_ARB_texture_filter_anisotropic"))) {
		GL_ARB_texture_filter_anisotropic_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_filter_minmax)
	if ((EXT_GL_ARB_texture_filter_minmax_loaded = FindExtension("GL_ARB_texture_filter_minmax"))) {
		GL_ARB_texture_filter_minmax_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_gather)
	if ((EXT_GL_ARB_texture_gather_loaded = FindExtension("GL_ARB_texture_gather"))) {
		GL_ARB_texture_gather_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_mirror_clamp_to_edge)
	if ((EXT_GL_ARB_texture_mirror_clamp_to_edge_loaded = FindExtension("GL_ARB_texture_mirror_clamp_to_edge"))) {
		GL_ARB_texture_mirror_clamp_to_edge_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_mirrored_repeat)
	if ((EXT_GL_ARB_texture_mirrored_repeat_loaded = FindExtension("GL_ARB_texture_mirrored_repeat"))) {
		GL_ARB_texture_mirrored_repeat_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_multisample)
	if ((EXT_GL_ARB_texture_multisample_loaded = FindExtension("GL_ARB_texture_multisample"))) {
		GL_ARB_texture_multisample_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_rg)
	if ((EXT_GL_ARB_texture_rg_loaded = FindExtension("GL_ARB_texture_rg"))) {
		GL_ARB_texture_rg_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_rgb10_a2ui)
	if ((EXT_GL_ARB_texture_rgb10_a2ui_loaded = FindExtension("GL_ARB_texture_rgb10_a2ui"))) {
		GL_ARB_texture_rgb10_a2ui_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_stencil8)
	if ((EXT_GL_ARB_texture_stencil8_loaded = FindExtension("GL_ARB_texture_stencil8"))) {
		GL_ARB_texture_stencil8_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_storage)
	if ((EXT_GL_ARB_texture_storage_loaded = FindExtension("GL_ARB_texture_storage"))) {
		GL_ARB_texture_storage_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_storage_multisample)
	if ((EXT_GL_ARB_texture_storage_multisample_loaded = FindExtension("GL_ARB_texture_storage_multisample"))) {
		GL_ARB_texture_storage_multisample_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_swizzle)
	if ((EXT_GL_ARB_texture_swizzle_loaded = FindExtension("GL_ARB_texture_swizzle"))) {
		GL_ARB_texture_swizzle_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_texture_view)
	if ((EXT_GL_ARB_texture_view_loaded = FindExtension("GL_ARB_texture_view"))) {
		GL_ARB_texture_view_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_timer_query)
	if ((EXT_GL_ARB_timer_query_loaded = FindExtension("GL_ARB_timer_query"))) {
		GL_ARB_timer_query_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_transform_feedback2)
	if ((EXT_GL_ARB_transform_feedback2_loaded = FindExtension("GL_ARB_transform_feedback2"))) {
		GL_ARB_transform_feedback2_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_transform_feedback3)
	if ((EXT_GL_ARB_transform_feedback3_loaded = FindExtension("GL_ARB_transform_feedback3"))) {
		GL_ARB_transform_feedback3_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_transform_feedback_instanced)
	if ((EXT_GL_ARB_transform_feedback_instanced_loaded = FindExtension("GL_ARB_transform_feedback_instanced"))) {
		GL_ARB_transform_feedback_instanced_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_transform_feedback_overflow_query)
	if ((EXT_GL_ARB_transform_feedback_overflow_query_loaded = FindExtension("GL_ARB_transform_feedback_overflow_query"))) {
		GL_ARB_transform_feedback_overflow_query_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_uniform_buffer_object)
	if ((EXT_GL_ARB_uniform_buffer_object_loaded = FindExtension("GL_ARB_uniform_buffer_object"))) {
		GL_ARB_uniform_buffer_object_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_vertex_array_bgra)
	if ((EXT_GL_ARB_vertex_array_bgra_loaded = FindExtension("GL_ARB_vertex_array_bgra"))) {
		GL_ARB_vertex_array_bgra_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_vertex_array_object)
	if ((EXT_GL_ARB_vertex_array_object_loaded = FindExtension("GL_ARB_vertex_array_object"))) {
		GL_ARB_vertex_array_object_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_vertex_attrib_64bit)
	if ((EXT_GL_ARB_vertex_attrib_64bit_loaded = FindExtension("GL_ARB_vertex_attrib_64bit"))) {
		GL_ARB_vertex_attrib_64bit_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_vertex_attrib_binding)
	if ((EXT_GL_ARB_vertex_attrib_binding_loaded = FindExtension("GL_ARB_vertex_attrib_binding"))) {
		GL_ARB_vertex_attrib_binding_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_vertex_type_10f_11f_11f_rev)
	if ((EXT_GL_ARB_vertex_type_10f_11f_11f_rev_loaded = FindExtension("GL_ARB_vertex_type_10f_11f_11f_rev"))) {
		GL_ARB_vertex_type_10f_11f_11f_rev_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_vertex_type_2_10_10_10_rev)
	if ((EXT_GL_ARB_vertex_type_2_10_10_10_rev_loaded = FindExtension("GL_ARB_vertex_type_2_10_10_10_rev"))) {
		GL_ARB_vertex_type_2_10_10_10_rev_FUNCTIONS
	}
#endif
#if defined(GL_EXT_ARB_viewport_array)
	if ((EXT_GL_ARB_viewport_array_loaded = FindExtension("GL_ARB_viewport_array"))) {
		GL_ARB_viewport_array_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_EGL_image_storage)
	if ((EXT_GL_EXT_EGL_image_storage_loaded = FindExtension("GL_EXT_EGL_image_storage"))) {
		GL_EXT_EGL_image_storage_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_debug_label)
	if ((EXT_GL_EXT_debug_label_loaded = FindExtension("GL_EXT_debug_label"))) {
		GL_EXT_debug_label_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_debug_marker)
	if ((EXT_GL_EXT_debug_marker_loaded = FindExtension("GL_EXT_debug_marker"))) {
		GL_EXT_debug_marker_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_direct_state_access)
	if ((EXT_GL_EXT_direct_state_access_loaded = FindExtension("GL_EXT_direct_state_access"))) {
		GL_EXT_direct_state_access_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_draw_instanced)
	if ((EXT_GL_EXT_draw_instanced_loaded = FindExtension("GL_EXT_draw_instanced"))) {
		GL_EXT_draw_instanced_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_polygon_offset_clamp)
	if ((EXT_GL_EXT_polygon_offset_clamp_loaded = FindExtension("GL_EXT_polygon_offset_clamp"))) {
		GL_EXT_polygon_offset_clamp_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_raster_multisample)
	if ((EXT_GL_EXT_raster_multisample_loaded = FindExtension("GL_EXT_raster_multisample"))) {
		GL_EXT_raster_multisample_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_separate_shader_objects)
	if ((EXT_GL_EXT_separate_shader_objects_loaded = FindExtension("GL_EXT_separate_shader_objects"))) {
		GL_EXT_separate_shader_objects_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_shader_framebuffer_fetch)
	if ((EXT_GL_EXT_shader_framebuffer_fetch_loaded = FindExtension("GL_EXT_shader_framebuffer_fetch"))) {
		GL_EXT_shader_framebuffer_fetch_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_shader_framebuffer_fetch_non_coherent)
	if ((EXT_GL_EXT_shader_framebuffer_fetch_non_coherent_loaded = FindExtension("GL_EXT_shader_framebuffer_fetch_non_coherent"))) {
		GL_EXT_shader_framebuffer_fetch_non_coherent_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_texture_compression_s3tc)
	if ((EXT_GL_EXT_texture_compression_s3tc_loaded = FindExtension("GL_EXT_texture_compression_s3tc"))) {
		GL_EXT_texture_compression_s3tc_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_texture_filter_minmax)
	if ((EXT_GL_EXT_texture_filter_minmax_loaded = FindExtension("GL_EXT_texture_filter_minmax"))) {
		GL_EXT_texture_filter_minmax_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_texture_sRGB_R8)
	if ((EXT_GL_EXT_texture_sRGB_R8_loaded = FindExtension("GL_EXT_texture_sRGB_R8"))) {
		GL_EXT_texture_sRGB_R8_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_texture_sRGB_RG8)
	if ((EXT_GL_EXT_texture_sRGB_RG8_loaded = FindExtension("GL_EXT_texture_sRGB_RG8"))) {
		GL_EXT_texture_sRGB_RG8_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_texture_sRGB_decode)
	if ((EXT_GL_EXT_texture_sRGB_decode_loaded = FindExtension("GL_EXT_texture_sRGB_decode"))) {
		GL_EXT_texture_sRGB_decode_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_texture_storage)
	if ((EXT_GL_EXT_texture_storage_loaded = FindExtension("GL_EXT_texture_storage"))) {
		GL_EXT_texture_storage_FUNCTIONS
	}
#endif
#if defined(GL_EXT_EXT_window_rectangles)
	if ((EXT_GL_EXT_window_rectangles_loaded = FindExtension("GL_EXT_window_rectangles"))) {
		GL_EXT_window_rectangles_FUNCTIONS
	}
#endif
#if defined(GL_EXT_INTEL_conservative_rasterization)
	if ((EXT_GL_INTEL_conservative_rasterization_loaded = FindExtension("GL_INTEL_conservative_rasterization"))) {
		GL_INTEL_conservative_rasterization_FUNCTIONS
	}
#endif
#if defined(GL_EXT_INTEL_framebuffer_CMAA)
	if ((EXT_GL_INTEL_framebuffer_CMAA_loaded = FindExtension("GL_INTEL_framebuffer_CMAA"))) {
		GL_INTEL_framebuffer_CMAA_FUNCTIONS
	}
#endif
#if defined(GL_EXT_INTEL_blackhole_render)
	if ((EXT_GL_INTEL_blackhole_render_loaded = FindExtension("GL_INTEL_blackhole_render"))) {
		GL_INTEL_blackhole_render_FUNCTIONS
	}
#endif
#if defined(GL_EXT_INTEL_performance_query)
	if ((EXT_GL_INTEL_performance_query_loaded = FindExtension("GL_INTEL_performance_query"))) {
		GL_INTEL_performance_query_FUNCTIONS
	}
#endif
#if defined(GL_EXT_KHR_blend_equation_advanced)
	if ((EXT_GL_KHR_blend_equation_advanced_loaded = FindExtension("GL_KHR_blend_equation_advanced"))) {
		GL_KHR_blend_equation_advanced_FUNCTIONS
	}
#endif
#if defined(GL_EXT_KHR_blend_equation_advanced_coherent)
	if ((EXT_GL_KHR_blend_equation_advanced_coherent_loaded = FindExtension("GL_KHR_blend_equation_advanced_coherent"))) {
		GL_KHR_blend_equation_advanced_coherent_FUNCTIONS
	}
#endif
#if defined(GL_EXT_KHR_context_flush_control)
	if ((EXT_GL_KHR_context_flush_control_loaded = FindExtension("GL_KHR_context_flush_control"))) {
		GL_KHR_context_flush_control_FUNCTIONS
	}
#endif
#if defined(GL_EXT_KHR_debug)
	if ((EXT_GL_KHR_debug_loaded = FindExtension("GL_KHR_debug"))) {
		GL_KHR_debug_FUNCTIONS
	}
#endif
#if defined(GL_EXT_KHR_no_error)
	if ((EXT_GL_KHR_no_error_loaded = FindExtension("GL_KHR_no_error"))) {
		GL_KHR_no_error_FUNCTIONS
	}
#endif
#if defined(GL_EXT_KHR_robustness)
	if ((EXT_GL_KHR_robustness_loaded = FindExtension("GL_KHR_robustness"))) {
		GL_KHR_robustness_FUNCTIONS
	}
#endif
#if defined(GL_EXT_KHR_shader_subgroup)
	if ((EXT_GL_KHR_shader_subgroup_loaded = FindExtension("GL_KHR_shader_subgroup"))) {
		GL_KHR_shader_subgroup_FUNCTIONS
	}
#endif
#if defined(GL_EXT_KHR_texture_compression_astc_hdr)
	if ((EXT_GL_KHR_texture_compression_astc_hdr_loaded = FindExtension("GL_KHR_texture_compression_astc_hdr"))) {
		GL_KHR_texture_compression_astc_hdr_FUNCTIONS
	}
#endif
#if defined(GL_EXT_KHR_texture_compression_astc_ldr)
	if ((EXT_GL_KHR_texture_compression_astc_ldr_loaded = FindExtension("GL_KHR_texture_compression_astc_ldr"))) {
		GL_KHR_texture_compression_astc_ldr_FUNCTIONS
	}
#endif
#if defined(GL_EXT_KHR_parallel_shader_compile)
	if ((EXT_GL_KHR_parallel_shader_compile_loaded = FindExtension("GL_KHR_parallel_shader_compile"))) {
		GL_KHR_parallel_shader_compile_FUNCTIONS
	}
#endif
#if defined(GL_EXT_MESA_framebuffer_flip_x)
	if ((EXT_GL_MESA_framebuffer_flip_x_loaded = FindExtension("GL_MESA_framebuffer_flip_x"))) {
		GL_MESA_framebuffer_flip_x_FUNCTIONS
	}
#endif
#if defined(GL_EXT_MESA_framebuffer_flip_y)
	if ((EXT_GL_MESA_framebuffer_flip_y_loaded = FindExtension("GL_MESA_framebuffer_flip_y"))) {
		GL_MESA_framebuffer_flip_y_FUNCTIONS
	}
#endif
#if defined(GL_EXT_MESA_framebuffer_swap_xy)
	if ((EXT_GL_MESA_framebuffer_swap_xy_loaded = FindExtension("GL_MESA_framebuffer_swap_xy"))) {
		GL_MESA_framebuffer_swap_xy_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_bindless_multi_draw_indirect)
	if ((EXT_GL_NV_bindless_multi_draw_indirect_loaded = FindExtension("GL_NV_bindless_multi_draw_indirect"))) {
		GL_NV_bindless_multi_draw_indirect_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_bindless_multi_draw_indirect_count)
	if ((EXT_GL_NV_bindless_multi_draw_indirect_count_loaded = FindExtension("GL_NV_bindless_multi_draw_indirect_count"))) {
		GL_NV_bindless_multi_draw_indirect_count_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_bindless_texture)
	if ((EXT_GL_NV_bindless_texture_loaded = FindExtension("GL_NV_bindless_texture"))) {
		GL_NV_bindless_texture_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_blend_equation_advanced)
	if ((EXT_GL_NV_blend_equation_advanced_loaded = FindExtension("GL_NV_blend_equation_advanced"))) {
		GL_NV_blend_equation_advanced_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_blend_equation_advanced_coherent)
	if ((EXT_GL_NV_blend_equation_advanced_coherent_loaded = FindExtension("GL_NV_blend_equation_advanced_coherent"))) {
		GL_NV_blend_equation_advanced_coherent_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_blend_minmax_factor)
	if ((EXT_GL_NV_blend_minmax_factor_loaded = FindExtension("GL_NV_blend_minmax_factor"))) {
		GL_NV_blend_minmax_factor_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_clip_space_w_scaling)
	if ((EXT_GL_NV_clip_space_w_scaling_loaded = FindExtension("GL_NV_clip_space_w_scaling"))) {
		GL_NV_clip_space_w_scaling_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_command_list)
	if ((EXT_GL_NV_command_list_loaded = FindExtension("GL_NV_command_list"))) {
		GL_NV_command_list_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_conditional_render)
	if ((EXT_GL_NV_conditional_render_loaded = FindExtension("GL_NV_conditional_render"))) {
		GL_NV_conditional_render_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_conservative_raster)
	if ((EXT_GL_NV_conservative_raster_loaded = FindExtension("GL_NV_conservative_raster"))) {
		GL_NV_conservative_raster_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_conservative_raster_dilate)
	if ((EXT_GL_NV_conservative_raster_dilate_loaded = FindExtension("GL_NV_conservative_raster_dilate"))) {
		GL_NV_conservative_raster_dilate_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_conservative_raster_pre_snap)
	if ((EXT_GL_NV_conservative_raster_pre_snap_loaded = FindExtension("GL_NV_conservative_raster_pre_snap"))) {
		GL_NV_conservative_raster_pre_snap_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_conservative_raster_pre_snap_triangles)
	if ((EXT_GL_NV_conservative_raster_pre_snap_triangles_loaded = FindExtension("GL_NV_conservative_raster_pre_snap_triangles"))) {
		GL_NV_conservative_raster_pre_snap_triangles_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_depth_buffer_float)
	if ((EXT_GL_NV_depth_buffer_float_loaded = FindExtension("GL_NV_depth_buffer_float"))) {
		GL_NV_depth_buffer_float_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_draw_vulkan_image)
	if ((EXT_GL_NV_draw_vulkan_image_loaded = FindExtension("GL_NV_draw_vulkan_image"))) {
		GL_NV_draw_vulkan_image_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_fill_rectangle)
	if ((EXT_GL_NV_fill_rectangle_loaded = FindExtension("GL_NV_fill_rectangle"))) {
		GL_NV_fill_rectangle_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_fragment_coverage_to_color)
	if ((EXT_GL_NV_fragment_coverage_to_color_loaded = FindExtension("GL_NV_fragment_coverage_to_color"))) {
		GL_NV_fragment_coverage_to_color_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_framebuffer_mixed_samples)
	if ((EXT_GL_NV_framebuffer_mixed_samples_loaded = FindExtension("GL_NV_framebuffer_mixed_samples"))) {
		GL_NV_framebuffer_mixed_samples_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_framebuffer_multisample_coverage)
	if ((EXT_GL_NV_framebuffer_multisample_coverage_loaded = FindExtension("GL_NV_framebuffer_multisample_coverage"))) {
		GL_NV_framebuffer_multisample_coverage_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_gpu_shader5)
	if ((EXT_GL_NV_gpu_shader5_loaded = FindExtension("GL_NV_gpu_shader5"))) {
		GL_NV_gpu_shader5_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_internalformat_sample_query)
	if ((EXT_GL_NV_internalformat_sample_query_loaded = FindExtension("GL_NV_internalformat_sample_query"))) {
		GL_NV_internalformat_sample_query_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_memory_attachment)
	if ((EXT_GL_NV_memory_attachment_loaded = FindExtension("GL_NV_memory_attachment"))) {
		GL_NV_memory_attachment_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_memory_object_sparse)
	if ((EXT_GL_NV_memory_object_sparse_loaded = FindExtension("GL_NV_memory_object_sparse"))) {
		GL_NV_memory_object_sparse_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_mesh_shader)
	if ((EXT_GL_NV_mesh_shader_loaded = FindExtension("GL_NV_mesh_shader"))) {
		GL_NV_mesh_shader_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_path_rendering)
	if ((EXT_GL_NV_path_rendering_loaded = FindExtension("GL_NV_path_rendering"))) {
		GL_NV_path_rendering_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_path_rendering_shared_edge)
	if ((EXT_GL_NV_path_rendering_shared_edge_loaded = FindExtension("GL_NV_path_rendering_shared_edge"))) {
		GL_NV_path_rendering_shared_edge_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_primitive_shading_rate)
	if ((EXT_GL_NV_primitive_shading_rate_loaded = FindExtension("GL_NV_primitive_shading_rate"))) {
		GL_NV_primitive_shading_rate_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_representative_fragment_test)
	if ((EXT_GL_NV_representative_fragment_test_loaded = FindExtension("GL_NV_representative_fragment_test"))) {
		GL_NV_representative_fragment_test_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_sample_locations)
	if ((EXT_GL_NV_sample_locations_loaded = FindExtension("GL_NV_sample_locations"))) {
		GL_NV_sample_locations_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_scissor_exclusive)
	if ((EXT_GL_NV_scissor_exclusive_loaded = FindExtension("GL_NV_scissor_exclusive"))) {
		GL_NV_scissor_exclusive_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_shader_buffer_load)
	if ((EXT_GL_NV_shader_buffer_load_loaded = FindExtension("GL_NV_shader_buffer_load"))) {
		GL_NV_shader_buffer_load_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_shader_buffer_store)
	if ((EXT_GL_NV_shader_buffer_store_loaded = FindExtension("GL_NV_shader_buffer_store"))) {
		GL_NV_shader_buffer_store_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_shader_subgroup_partitioned)
	if ((EXT_GL_NV_shader_subgroup_partitioned_loaded = FindExtension("GL_NV_shader_subgroup_partitioned"))) {
		GL_NV_shader_subgroup_partitioned_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_shader_thread_group)
	if ((EXT_GL_NV_shader_thread_group_loaded = FindExtension("GL_NV_shader_thread_group"))) {
		GL_NV_shader_thread_group_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_shading_rate_image)
	if ((EXT_GL_NV_shading_rate_image_loaded = FindExtension("GL_NV_shading_rate_image"))) {
		GL_NV_shading_rate_image_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_texture_barrier)
	if ((EXT_GL_NV_texture_barrier_loaded = FindExtension("GL_NV_texture_barrier"))) {
		GL_NV_texture_barrier_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_uniform_buffer_unified_memory)
	if ((EXT_GL_NV_uniform_buffer_unified_memory_loaded = FindExtension("GL_NV_uniform_buffer_unified_memory"))) {
		GL_NV_uniform_buffer_unified_memory_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_vertex_attrib_integer_64bit)
	if ((EXT_GL_NV_vertex_attrib_integer_64bit_loaded = FindExtension("GL_NV_vertex_attrib_integer_64bit"))) {
		GL_NV_vertex_attrib_integer_64bit_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_vertex_buffer_unified_memory)
	if ((EXT_GL_NV_vertex_buffer_unified_memory_loaded = FindExtension("GL_NV_vertex_buffer_unified_memory"))) {
		GL_NV_vertex_buffer_unified_memory_FUNCTIONS
	}
#endif
#if defined(GL_EXT_NV_viewport_swizzle)
	if ((EXT_GL_NV_viewport_swizzle_loaded = FindExtension("GL_NV_viewport_swizzle"))) {
		GL_NV_viewport_swizzle_FUNCTIONS
	}
#endif
#if defined(GL_EXT_OVR_multiview)
	if ((EXT_GL_OVR_multiview_loaded = FindExtension("GL_OVR_multiview"))) {
		GL_OVR_multiview_FUNCTIONS
	}
#endif
    FreeExtensions();
                      
    return failures;
}
#undef X
