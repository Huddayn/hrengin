/*
 * This file is automatically generated.
 */
#ifndef aw_gl_ext_opengl_3_3_h
#define aw_gl_ext_opengl_3_3_h
#include "types.h"
#include "gl_enum_33.h"

namespace gl {
namespace ext {
struct load_result {
	explicit operator bool() const
	{
		return is_loaded;
	}
	
	int num_missing() const { return missing; }
	
	load_result() = default;
	load_result(bool is_loaded, int num_missing)
		: is_loaded{is_loaded}, missing{num_missing}
	{}

private:
	bool is_loaded = false;
	int  missing   = 0;
};
} //namespace ext

namespace sys {
ext::load_result load_functions_3_3();

int get_minor_version();
int get_major_version();
bool is_version_geq(int major, int minor);
} //namespace sys

/* gl version 1.0 */
extern void (AWGL_API* blend_func)(GLenum sfactor, GLenum dfactor);
extern void (AWGL_API* clear)(GLbitfield mask);
extern void (AWGL_API* clear_color)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (AWGL_API* clear_depth)(GLdouble depth);
extern void (AWGL_API* clear_stencil)(GLint s);
extern void (AWGL_API* color_mask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern void (AWGL_API* cull_face)(GLenum mode);
extern void (AWGL_API* depth_func)(GLenum func);
extern void (AWGL_API* depth_mask)(GLboolean flag);
extern void (AWGL_API* depth_range)(GLdouble ren_near, GLdouble ren_far);
extern void (AWGL_API* disable)(GLenum cap);
extern void (AWGL_API* draw_buffer)(GLenum buf);
extern void (AWGL_API* enable)(GLenum cap);
extern void (AWGL_API* finish)(void);
extern void (AWGL_API* flush)(void);
extern void (AWGL_API* front_face)(GLenum mode);
extern void (AWGL_API* get_booleanv)(GLenum pname, GLboolean * data);
extern void (AWGL_API* get_doublev)(GLenum pname, GLdouble * data);
extern GLenum (AWGL_API* get_error)(void);
extern void (AWGL_API* get_floatv)(GLenum pname, GLfloat * data);
extern void (AWGL_API* get_integerv)(GLenum pname, GLint * data);
extern const GLubyte * (AWGL_API* get_string)(GLenum name);
extern void (AWGL_API* get_tex_image)(GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
extern void (AWGL_API* get_tex_level_parameterfv)(GLenum target, GLint level, GLenum pname, GLfloat * params);
extern void (AWGL_API* get_tex_level_parameteriv)(GLenum target, GLint level, GLenum pname, GLint * params);
extern void (AWGL_API* get_tex_parameterfv)(GLenum target, GLenum pname, GLfloat * params);
extern void (AWGL_API* get_tex_parameteriv)(GLenum target, GLenum pname, GLint * params);
extern void (AWGL_API* hint)(GLenum target, GLenum mode);
extern GLboolean (AWGL_API* is_enabled)(GLenum cap);
extern void (AWGL_API* line_width)(GLfloat width);
extern void (AWGL_API* logic_op)(GLenum opcode);
extern void (AWGL_API* pixel_storef)(GLenum pname, GLfloat param);
extern void (AWGL_API* pixel_storei)(GLenum pname, GLint param);
extern void (AWGL_API* point_size)(GLfloat size);
extern void (AWGL_API* polygon_mode)(GLenum face, GLenum mode);
extern void (AWGL_API* read_buffer)(GLenum src);
extern void (AWGL_API* read_pixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
extern void (AWGL_API* scissor)(GLint x, GLint y, GLsizei width, GLsizei height);
extern void (AWGL_API* stencil_func)(GLenum func, GLint ref, GLuint mask);
extern void (AWGL_API* stencil_mask)(GLuint mask);
extern void (AWGL_API* stencil_op)(GLenum fail, GLenum zfail, GLenum zpass);
extern void (AWGL_API* tex_image1_d)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
extern void (AWGL_API* tex_image2_d)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
extern void (AWGL_API* tex_parameterf)(GLenum target, GLenum pname, GLfloat param);
extern void (AWGL_API* tex_parameterfv)(GLenum target, GLenum pname, const GLfloat * params);
extern void (AWGL_API* tex_parameteri)(GLenum target, GLenum pname, GLint param);
extern void (AWGL_API* tex_parameteriv)(GLenum target, GLenum pname, const GLint * params);
extern void (AWGL_API* viewport)(GLint x, GLint y, GLsizei width, GLsizei height);

/* gl version 1.1 */
extern void (AWGL_API* bind_texture)(GLenum target, GLuint texture);
extern void (AWGL_API* copy_tex_image1_d)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
extern void (AWGL_API* copy_tex_image2_d)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void (AWGL_API* copy_tex_sub_image1_d)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern void (AWGL_API* copy_tex_sub_image2_d)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (AWGL_API* delete_textures)(GLsizei n, const GLuint * textures);
extern void (AWGL_API* draw_arrays)(GLenum mode, GLint first, GLsizei count);
extern void (AWGL_API* draw_elements)(GLenum mode, GLsizei count, GLenum type, const void * indices);
extern void (AWGL_API* gen_textures)(GLsizei n, GLuint * textures);
extern GLboolean (AWGL_API* is_texture)(GLuint texture);
extern void (AWGL_API* polygon_offset)(GLfloat factor, GLfloat units);
extern void (AWGL_API* tex_sub_image1_d)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
extern void (AWGL_API* tex_sub_image2_d)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);

/* gl version 1.2 */
extern void (AWGL_API* copy_tex_sub_image3_d)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void (AWGL_API* draw_range_elements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
extern void (AWGL_API* tex_image3_d)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
extern void (AWGL_API* tex_sub_image3_d)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);

/* gl version 1.3 */
extern void (AWGL_API* active_texture)(GLenum texture);
extern void (AWGL_API* compressed_tex_image1_d)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
extern void (AWGL_API* compressed_tex_image2_d)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
extern void (AWGL_API* compressed_tex_image3_d)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
extern void (AWGL_API* compressed_tex_sub_image1_d)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
extern void (AWGL_API* compressed_tex_sub_image2_d)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
extern void (AWGL_API* compressed_tex_sub_image3_d)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
extern void (AWGL_API* get_compressed_tex_image)(GLenum target, GLint level, void * img);
extern void (AWGL_API* sample_coverage)(GLfloat value, GLboolean invert);

/* gl version 1.4 */
extern void (AWGL_API* blend_color)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void (AWGL_API* blend_equation)(GLenum mode);
extern void (AWGL_API* blend_func_separate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
extern void (AWGL_API* multi_draw_arrays)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
extern void (AWGL_API* multi_draw_elements)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount);
extern void (AWGL_API* point_parameterf)(GLenum pname, GLfloat param);
extern void (AWGL_API* point_parameterfv)(GLenum pname, const GLfloat * params);
extern void (AWGL_API* point_parameteri)(GLenum pname, GLint param);
extern void (AWGL_API* point_parameteriv)(GLenum pname, const GLint * params);

/* gl version 1.5 */
extern void (AWGL_API* begin_query)(GLenum target, GLuint id);
extern void (AWGL_API* bind_buffer)(GLenum target, GLuint buffer);
extern void (AWGL_API* buffer_data)(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
extern void (AWGL_API* buffer_sub_data)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
extern void (AWGL_API* delete_buffers)(GLsizei n, const GLuint * buffers);
extern void (AWGL_API* delete_queries)(GLsizei n, const GLuint * ids);
extern void (AWGL_API* end_query)(GLenum target);
extern void (AWGL_API* gen_buffers)(GLsizei n, GLuint * buffers);
extern void (AWGL_API* gen_queries)(GLsizei n, GLuint * ids);
extern void (AWGL_API* get_buffer_parameteriv)(GLenum target, GLenum pname, GLint * params);
extern void (AWGL_API* get_buffer_pointerv)(GLenum target, GLenum pname, void ** params);
extern void (AWGL_API* get_buffer_sub_data)(GLenum target, GLintptr offset, GLsizeiptr size, void * data);
extern void (AWGL_API* get_query_objectiv)(GLuint id, GLenum pname, GLint * params);
extern void (AWGL_API* get_query_objectuiv)(GLuint id, GLenum pname, GLuint * params);
extern void (AWGL_API* get_queryiv)(GLenum target, GLenum pname, GLint * params);
extern GLboolean (AWGL_API* is_buffer)(GLuint buffer);
extern GLboolean (AWGL_API* is_query)(GLuint id);
extern void * (AWGL_API* map_buffer)(GLenum target, GLenum access);
extern GLboolean (AWGL_API* unmap_buffer)(GLenum target);

/* gl version 2.0 */
extern void (AWGL_API* attach_shader)(GLuint program, GLuint shader);
extern void (AWGL_API* bind_attrib_location)(GLuint program, GLuint index, const GLchar * name);
extern void (AWGL_API* blend_equation_separate)(GLenum modeRGB, GLenum modeAlpha);
extern void (AWGL_API* compile_shader)(GLuint shader);
extern GLuint (AWGL_API* create_program)(void);
extern GLuint (AWGL_API* create_shader)(GLenum type);
extern void (AWGL_API* delete_program)(GLuint program);
extern void (AWGL_API* delete_shader)(GLuint shader);
extern void (AWGL_API* detach_shader)(GLuint program, GLuint shader);
extern void (AWGL_API* disable_vertex_attrib_array)(GLuint index);
extern void (AWGL_API* draw_buffers)(GLsizei n, const GLenum * bufs);
extern void (AWGL_API* enable_vertex_attrib_array)(GLuint index);
extern void (AWGL_API* get_active_attrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
extern void (AWGL_API* get_active_uniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
extern void (AWGL_API* get_attached_shaders)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
extern GLint (AWGL_API* get_attrib_location)(GLuint program, const GLchar * name);
extern void (AWGL_API* get_program_info_log)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
extern void (AWGL_API* get_programiv)(GLuint program, GLenum pname, GLint * params);
extern void (AWGL_API* get_shader_info_log)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
extern void (AWGL_API* get_shader_source)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
extern void (AWGL_API* get_shaderiv)(GLuint shader, GLenum pname, GLint * params);
extern GLint (AWGL_API* get_uniform_location)(GLuint program, const GLchar * name);
extern void (AWGL_API* get_uniformfv)(GLuint program, GLint location, GLfloat * params);
extern void (AWGL_API* get_uniformiv)(GLuint program, GLint location, GLint * params);
extern void (AWGL_API* get_vertex_attrib_pointerv)(GLuint index, GLenum pname, void ** pointer);
extern void (AWGL_API* get_vertex_attribdv)(GLuint index, GLenum pname, GLdouble * params);
extern void (AWGL_API* get_vertex_attribfv)(GLuint index, GLenum pname, GLfloat * params);
extern void (AWGL_API* get_vertex_attribiv)(GLuint index, GLenum pname, GLint * params);
extern GLboolean (AWGL_API* is_program)(GLuint program);
extern GLboolean (AWGL_API* is_shader)(GLuint shader);
extern void (AWGL_API* link_program)(GLuint program);
extern void (AWGL_API* shader_source)(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length);
extern void (AWGL_API* stencil_func_separate)(GLenum face, GLenum func, GLint ref, GLuint mask);
extern void (AWGL_API* stencil_mask_separate)(GLenum face, GLuint mask);
extern void (AWGL_API* stencil_op_separate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
extern void (AWGL_API* uniform1f)(GLint location, GLfloat v0);
extern void (AWGL_API* uniform1fv)(GLint location, GLsizei count, const GLfloat * value);
extern void (AWGL_API* uniform1i)(GLint location, GLint v0);
extern void (AWGL_API* uniform1iv)(GLint location, GLsizei count, const GLint * value);
extern void (AWGL_API* uniform2f)(GLint location, GLfloat v0, GLfloat v1);
extern void (AWGL_API* uniform2fv)(GLint location, GLsizei count, const GLfloat * value);
extern void (AWGL_API* uniform2i)(GLint location, GLint v0, GLint v1);
extern void (AWGL_API* uniform2iv)(GLint location, GLsizei count, const GLint * value);
extern void (AWGL_API* uniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
extern void (AWGL_API* uniform3fv)(GLint location, GLsizei count, const GLfloat * value);
extern void (AWGL_API* uniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
extern void (AWGL_API* uniform3iv)(GLint location, GLsizei count, const GLint * value);
extern void (AWGL_API* uniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
extern void (AWGL_API* uniform4fv)(GLint location, GLsizei count, const GLfloat * value);
extern void (AWGL_API* uniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
extern void (AWGL_API* uniform4iv)(GLint location, GLsizei count, const GLint * value);
extern void (AWGL_API* uniform_matrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (AWGL_API* uniform_matrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (AWGL_API* uniform_matrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (AWGL_API* use_program)(GLuint program);
extern void (AWGL_API* validate_program)(GLuint program);
extern void (AWGL_API* vertex_attrib1d)(GLuint index, GLdouble x);
extern void (AWGL_API* vertex_attrib1dv)(GLuint index, const GLdouble * v);
extern void (AWGL_API* vertex_attrib1f)(GLuint index, GLfloat x);
extern void (AWGL_API* vertex_attrib1fv)(GLuint index, const GLfloat * v);
extern void (AWGL_API* vertex_attrib1s)(GLuint index, GLshort x);
extern void (AWGL_API* vertex_attrib1sv)(GLuint index, const GLshort * v);
extern void (AWGL_API* vertex_attrib2d)(GLuint index, GLdouble x, GLdouble y);
extern void (AWGL_API* vertex_attrib2dv)(GLuint index, const GLdouble * v);
extern void (AWGL_API* vertex_attrib2f)(GLuint index, GLfloat x, GLfloat y);
extern void (AWGL_API* vertex_attrib2fv)(GLuint index, const GLfloat * v);
extern void (AWGL_API* vertex_attrib2s)(GLuint index, GLshort x, GLshort y);
extern void (AWGL_API* vertex_attrib2sv)(GLuint index, const GLshort * v);
extern void (AWGL_API* vertex_attrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern void (AWGL_API* vertex_attrib3dv)(GLuint index, const GLdouble * v);
extern void (AWGL_API* vertex_attrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
extern void (AWGL_API* vertex_attrib3fv)(GLuint index, const GLfloat * v);
extern void (AWGL_API* vertex_attrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
extern void (AWGL_API* vertex_attrib3sv)(GLuint index, const GLshort * v);
extern void (AWGL_API* vertex_attrib4_nbv)(GLuint index, const GLbyte * v);
extern void (AWGL_API* vertex_attrib4_niv)(GLuint index, const GLint * v);
extern void (AWGL_API* vertex_attrib4_nsv)(GLuint index, const GLshort * v);
extern void (AWGL_API* vertex_attrib4_nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
extern void (AWGL_API* vertex_attrib4_nubv)(GLuint index, const GLubyte * v);
extern void (AWGL_API* vertex_attrib4_nuiv)(GLuint index, const GLuint * v);
extern void (AWGL_API* vertex_attrib4_nusv)(GLuint index, const GLushort * v);
extern void (AWGL_API* vertex_attrib4bv)(GLuint index, const GLbyte * v);
extern void (AWGL_API* vertex_attrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern void (AWGL_API* vertex_attrib4dv)(GLuint index, const GLdouble * v);
extern void (AWGL_API* vertex_attrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void (AWGL_API* vertex_attrib4fv)(GLuint index, const GLfloat * v);
extern void (AWGL_API* vertex_attrib4iv)(GLuint index, const GLint * v);
extern void (AWGL_API* vertex_attrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
extern void (AWGL_API* vertex_attrib4sv)(GLuint index, const GLshort * v);
extern void (AWGL_API* vertex_attrib4ubv)(GLuint index, const GLubyte * v);
extern void (AWGL_API* vertex_attrib4uiv)(GLuint index, const GLuint * v);
extern void (AWGL_API* vertex_attrib4usv)(GLuint index, const GLushort * v);
extern void (AWGL_API* vertex_attrib_pointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);

/* gl version 2.1 */
extern void (AWGL_API* uniform_matrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (AWGL_API* uniform_matrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (AWGL_API* uniform_matrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (AWGL_API* uniform_matrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (AWGL_API* uniform_matrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
extern void (AWGL_API* uniform_matrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);

/* gl version 3.0 */
extern void (AWGL_API* begin_conditional_render)(GLuint id, GLenum mode);
extern void (AWGL_API* begin_transform_feedback)(GLenum primitiveMode);
extern void (AWGL_API* bind_buffer_base)(GLenum target, GLuint index, GLuint buffer);
extern void (AWGL_API* bind_buffer_range)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern void (AWGL_API* bind_frag_data_location)(GLuint program, GLuint color, const GLchar * name);
extern void (AWGL_API* bind_framebuffer)(GLenum target, GLuint framebuffer);
extern void (AWGL_API* bind_renderbuffer)(GLenum target, GLuint renderbuffer);
extern void (AWGL_API* bind_vertex_array)(GLuint ren_array);
extern void (AWGL_API* blit_framebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
extern GLenum (AWGL_API* check_framebuffer_status)(GLenum target);
extern void (AWGL_API* clamp_color)(GLenum target, GLenum clamp);
extern void (AWGL_API* clear_bufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
extern void (AWGL_API* clear_bufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat * value);
extern void (AWGL_API* clear_bufferiv)(GLenum buffer, GLint drawbuffer, const GLint * value);
extern void (AWGL_API* clear_bufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint * value);
extern void (AWGL_API* color_maski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
extern void (AWGL_API* delete_framebuffers)(GLsizei n, const GLuint * framebuffers);
extern void (AWGL_API* delete_renderbuffers)(GLsizei n, const GLuint * renderbuffers);
extern void (AWGL_API* delete_vertex_arrays)(GLsizei n, const GLuint * arrays);
extern void (AWGL_API* disablei)(GLenum target, GLuint index);
extern void (AWGL_API* enablei)(GLenum target, GLuint index);
extern void (AWGL_API* end_conditional_render)(void);
extern void (AWGL_API* end_transform_feedback)(void);
extern void (AWGL_API* flush_mapped_buffer_range)(GLenum target, GLintptr offset, GLsizeiptr length);
extern void (AWGL_API* framebuffer_renderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void (AWGL_API* framebuffer_texture1_d)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (AWGL_API* framebuffer_texture2_d)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void (AWGL_API* framebuffer_texture3_d)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
extern void (AWGL_API* framebuffer_texture_layer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern void (AWGL_API* gen_framebuffers)(GLsizei n, GLuint * framebuffers);
extern void (AWGL_API* gen_renderbuffers)(GLsizei n, GLuint * renderbuffers);
extern void (AWGL_API* gen_vertex_arrays)(GLsizei n, GLuint * arrays);
extern void (AWGL_API* generate_mipmap)(GLenum target);
extern void (AWGL_API* get_booleani_v)(GLenum target, GLuint index, GLboolean * data);
extern GLint (AWGL_API* get_frag_data_location)(GLuint program, const GLchar * name);
extern void (AWGL_API* get_framebuffer_attachment_parameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
extern void (AWGL_API* get_integeri_v)(GLenum target, GLuint index, GLint * data);
extern void (AWGL_API* get_renderbuffer_parameteriv)(GLenum target, GLenum pname, GLint * params);
extern const GLubyte * (AWGL_API* get_stringi)(GLenum name, GLuint index);
extern void (AWGL_API* get_tex_parameter_iiv)(GLenum target, GLenum pname, GLint * params);
extern void (AWGL_API* get_tex_parameter_iuiv)(GLenum target, GLenum pname, GLuint * params);
extern void (AWGL_API* get_transform_feedback_varying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
extern void (AWGL_API* get_uniformuiv)(GLuint program, GLint location, GLuint * params);
extern void (AWGL_API* get_vertex_attrib_iiv)(GLuint index, GLenum pname, GLint * params);
extern void (AWGL_API* get_vertex_attrib_iuiv)(GLuint index, GLenum pname, GLuint * params);
extern GLboolean (AWGL_API* is_enabledi)(GLenum target, GLuint index);
extern GLboolean (AWGL_API* is_framebuffer)(GLuint framebuffer);
extern GLboolean (AWGL_API* is_renderbuffer)(GLuint renderbuffer);
extern GLboolean (AWGL_API* is_vertex_array)(GLuint ren_array);
extern void * (AWGL_API* map_buffer_range)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
extern void (AWGL_API* renderbuffer_storage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
extern void (AWGL_API* renderbuffer_storage_multisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
extern void (AWGL_API* tex_parameter_iiv)(GLenum target, GLenum pname, const GLint * params);
extern void (AWGL_API* tex_parameter_iuiv)(GLenum target, GLenum pname, const GLuint * params);
extern void (AWGL_API* transform_feedback_varyings)(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);
extern void (AWGL_API* uniform1ui)(GLint location, GLuint v0);
extern void (AWGL_API* uniform1uiv)(GLint location, GLsizei count, const GLuint * value);
extern void (AWGL_API* uniform2ui)(GLint location, GLuint v0, GLuint v1);
extern void (AWGL_API* uniform2uiv)(GLint location, GLsizei count, const GLuint * value);
extern void (AWGL_API* uniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
extern void (AWGL_API* uniform3uiv)(GLint location, GLsizei count, const GLuint * value);
extern void (AWGL_API* uniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
extern void (AWGL_API* uniform4uiv)(GLint location, GLsizei count, const GLuint * value);
extern void (AWGL_API* vertex_attrib_i1i)(GLuint index, GLint x);
extern void (AWGL_API* vertex_attrib_i1iv)(GLuint index, const GLint * v);
extern void (AWGL_API* vertex_attrib_i1ui)(GLuint index, GLuint x);
extern void (AWGL_API* vertex_attrib_i1uiv)(GLuint index, const GLuint * v);
extern void (AWGL_API* vertex_attrib_i2i)(GLuint index, GLint x, GLint y);
extern void (AWGL_API* vertex_attrib_i2iv)(GLuint index, const GLint * v);
extern void (AWGL_API* vertex_attrib_i2ui)(GLuint index, GLuint x, GLuint y);
extern void (AWGL_API* vertex_attrib_i2uiv)(GLuint index, const GLuint * v);
extern void (AWGL_API* vertex_attrib_i3i)(GLuint index, GLint x, GLint y, GLint z);
extern void (AWGL_API* vertex_attrib_i3iv)(GLuint index, const GLint * v);
extern void (AWGL_API* vertex_attrib_i3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
extern void (AWGL_API* vertex_attrib_i3uiv)(GLuint index, const GLuint * v);
extern void (AWGL_API* vertex_attrib_i4bv)(GLuint index, const GLbyte * v);
extern void (AWGL_API* vertex_attrib_i4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
extern void (AWGL_API* vertex_attrib_i4iv)(GLuint index, const GLint * v);
extern void (AWGL_API* vertex_attrib_i4sv)(GLuint index, const GLshort * v);
extern void (AWGL_API* vertex_attrib_i4ubv)(GLuint index, const GLubyte * v);
extern void (AWGL_API* vertex_attrib_i4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
extern void (AWGL_API* vertex_attrib_i4uiv)(GLuint index, const GLuint * v);
extern void (AWGL_API* vertex_attrib_i4usv)(GLuint index, const GLushort * v);
extern void (AWGL_API* vertex_attrib_i_pointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);

/* gl version 3.1 */
extern void (AWGL_API* copy_buffer_sub_data)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
extern void (AWGL_API* draw_arrays_instanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
extern void (AWGL_API* draw_elements_instanced)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount);
extern void (AWGL_API* get_active_uniform_block_name)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
extern void (AWGL_API* get_active_uniform_blockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
extern void (AWGL_API* get_active_uniform_name)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
extern void (AWGL_API* get_active_uniformsiv)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
extern GLuint (AWGL_API* get_uniform_block_index)(GLuint program, const GLchar * uniformBlockName);
extern void (AWGL_API* get_uniform_indices)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices);
extern void (AWGL_API* primitive_restart_index)(GLuint index);
extern void (AWGL_API* tex_buffer)(GLenum target, GLenum internalformat, GLuint buffer);
extern void (AWGL_API* uniform_block_binding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

/* gl version 3.2 */
extern GLenum (AWGL_API* client_wait_sync)(GLsync sync, GLbitfield flags, GLuint64 timeout);
extern void (AWGL_API* delete_sync)(GLsync sync);
extern void (AWGL_API* draw_elements_base_vertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
extern void (AWGL_API* draw_elements_instanced_base_vertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
extern void (AWGL_API* draw_range_elements_base_vertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
extern GLsync (AWGL_API* fence_sync)(GLenum condition, GLbitfield flags);
extern void (AWGL_API* framebuffer_texture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
extern void (AWGL_API* get_buffer_parameteri64v)(GLenum target, GLenum pname, GLint64 * params);
extern void (AWGL_API* get_integer64i_v)(GLenum target, GLuint index, GLint64 * data);
extern void (AWGL_API* get_integer64v)(GLenum pname, GLint64 * data);
extern void (AWGL_API* get_multisamplefv)(GLenum pname, GLuint index, GLfloat * val);
extern void (AWGL_API* get_synciv)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values);
extern GLboolean (AWGL_API* is_sync)(GLsync sync);
extern void (AWGL_API* multi_draw_elements_base_vertex)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex);
extern void (AWGL_API* provoking_vertex)(GLenum mode);
extern void (AWGL_API* sample_maski)(GLuint maskNumber, GLbitfield mask);
extern void (AWGL_API* tex_image2_d_multisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern void (AWGL_API* tex_image3_d_multisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern void (AWGL_API* wait_sync)(GLsync sync, GLbitfield flags, GLuint64 timeout);

/* gl version 3.3 */
extern void (AWGL_API* bind_frag_data_location_indexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name);
extern void (AWGL_API* bind_sampler)(GLuint unit, GLuint sampler);
extern void (AWGL_API* delete_samplers)(GLsizei count, const GLuint * samplers);
extern void (AWGL_API* gen_samplers)(GLsizei count, GLuint * samplers);
extern GLint (AWGL_API* get_frag_data_index)(GLuint program, const GLchar * name);
extern void (AWGL_API* get_query_objecti64v)(GLuint id, GLenum pname, GLint64 * params);
extern void (AWGL_API* get_query_objectui64v)(GLuint id, GLenum pname, GLuint64 * params);
extern void (AWGL_API* get_sampler_parameter_iiv)(GLuint sampler, GLenum pname, GLint * params);
extern void (AWGL_API* get_sampler_parameter_iuiv)(GLuint sampler, GLenum pname, GLuint * params);
extern void (AWGL_API* get_sampler_parameterfv)(GLuint sampler, GLenum pname, GLfloat * params);
extern void (AWGL_API* get_sampler_parameteriv)(GLuint sampler, GLenum pname, GLint * params);
extern GLboolean (AWGL_API* is_sampler)(GLuint sampler);
extern void (AWGL_API* query_counter)(GLuint id, GLenum target);
extern void (AWGL_API* sampler_parameter_iiv)(GLuint sampler, GLenum pname, const GLint * param);
extern void (AWGL_API* sampler_parameter_iuiv)(GLuint sampler, GLenum pname, const GLuint * param);
extern void (AWGL_API* sampler_parameterf)(GLuint sampler, GLenum pname, GLfloat param);
extern void (AWGL_API* sampler_parameterfv)(GLuint sampler, GLenum pname, const GLfloat * param);
extern void (AWGL_API* sampler_parameteri)(GLuint sampler, GLenum pname, GLint param);
extern void (AWGL_API* sampler_parameteriv)(GLuint sampler, GLenum pname, const GLint * param);
extern void (AWGL_API* vertex_attrib_divisor)(GLuint index, GLuint divisor);
extern void (AWGL_API* vertex_attrib_p1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (AWGL_API* vertex_attrib_p1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
extern void (AWGL_API* vertex_attrib_p2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (AWGL_API* vertex_attrib_p2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
extern void (AWGL_API* vertex_attrib_p3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (AWGL_API* vertex_attrib_p3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);
extern void (AWGL_API* vertex_attrib_p4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern void (AWGL_API* vertex_attrib_p4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value);

} //namespace gl
#endif//aw_gl_ext_opengl_3_3_h
