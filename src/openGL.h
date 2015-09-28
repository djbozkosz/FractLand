//------------------------------------------------------------------------------
#ifndef OPENGL_H
#define OPENGL_H

#include "context.h"
#include "headers/openGLTypes.h"

//------------------------------------------------------------------------------
class COpenGL : public CEngineBase
{
  private:
#ifndef QT_OPENGL_ES_2
    NOpenGLProc::TActiveTexture glActiveTexture;
    NOpenGLProc::TAttachShader glAttachShader;
    NOpenGLProc::TBindAttribLocation glBindAttribLocation;
    NOpenGLProc::TBindBuffer glBindBuffer;
    NOpenGLProc::TBindFramebuffer glBindFramebuffer;
    NOpenGLProc::TBindRenderbuffer glBindRenderbuffer;
    NOpenGLProc::TBlendColor glBlendColor;
    NOpenGLProc::TBlendEquation glBlendEquation;
    NOpenGLProc::TBlendEquationSeparate glBlendEquationSeparate;
    NOpenGLProc::TBlendFuncSeparate glBlendFuncSeparate;
    NOpenGLProc::TBufferData glBufferData;
    NOpenGLProc::TBufferSubData glBufferSubData;
    NOpenGLProc::TCheckFramebufferStatus glCheckFramebufferStatus;
    NOpenGLProc::TCompileShader glCompileShader;
    NOpenGLProc::TCompressedTexImage2D glCompressedTexImage2D;
    NOpenGLProc::TCompressedTexSubImage2D glCompressedTexSubImage2D;
    NOpenGLProc::TCreateProgram glCreateProgram;
    NOpenGLProc::TCreateShader glCreateShader;
    NOpenGLProc::TDeleteBuffers glDeleteBuffers;
    NOpenGLProc::TDeleteFramebuffers glDeleteFramebuffers;
    NOpenGLProc::TDeleteProgram glDeleteProgram;
    NOpenGLProc::TDeleteRenderbuffers glDeleteRenderbuffers;
    NOpenGLProc::TDeleteShader glDeleteShader;
    NOpenGLProc::TDetachShader glDetachShader;
    NOpenGLProc::TDisableVertexAttribArray glDisableVertexAttribArray;
    NOpenGLProc::TEnableVertexAttribArray glEnableVertexAttribArray;
    NOpenGLProc::TFramebufferRenderbuffer glFramebufferRenderbuffer;
    NOpenGLProc::TFramebufferTexture2D glFramebufferTexture2D;
    NOpenGLProc::TGenBuffers glGenBuffers;
    NOpenGLProc::TGenerateMipmap glGenerateMipmap;
    NOpenGLProc::TGenFramebuffers glGenFramebuffers;
    NOpenGLProc::TGenRenderbuffers glGenRenderbuffers;
    NOpenGLProc::TGetActiveAttrib glGetActiveAttrib;
    NOpenGLProc::TGetActiveUniform glGetActiveUniform;
    NOpenGLProc::TGetAttachedShaders glGetAttachedShaders;
    NOpenGLProc::TGetAttribLocation glGetAttribLocation;
    NOpenGLProc::TGetBufferParameteriv glGetBufferParameteriv;
    NOpenGLProc::TGetFramebufferAttachmentParameteriv glGetFramebufferAttachmentParameteriv;
    NOpenGLProc::TGetProgramiv glGetProgramiv;
    NOpenGLProc::TGetProgramInfoLog glGetProgramInfoLog;
    NOpenGLProc::TGetRenderbufferParameteriv glGetRenderbufferParameteriv;
    NOpenGLProc::TGetShaderiv glGetShaderiv;
    NOpenGLProc::TGetShaderInfoLog glGetShaderInfoLog;
    NOpenGLProc::TGetShaderPrecisionFormat glGetShaderPrecisionFormat;
    NOpenGLProc::TGetShaderSource glGetShaderSource;
    NOpenGLProc::TGetUniformfv glGetUniformfv;
    NOpenGLProc::TGetUniformiv glGetUniformiv;
    NOpenGLProc::TGetUniformLocation glGetUniformLocation;
    NOpenGLProc::TGetVertexAttribfv glGetVertexAttribfv;
    NOpenGLProc::TGetVertexAttribiv glGetVertexAttribiv;
    NOpenGLProc::TGetVertexAttribPointerv glGetVertexAttribPointerv;
    NOpenGLProc::TIsBuffer glIsBuffer;
    NOpenGLProc::TIsFramebuffer glIsFramebuffer;
    NOpenGLProc::TIsProgram glIsProgram;
    NOpenGLProc::TIsRenderbuffer glIsRenderbuffer;
    NOpenGLProc::TIsShader glIsShader;
    NOpenGLProc::TLinkProgram glLinkProgram;
    NOpenGLProc::TReleaseShaderCompiler glReleaseShaderCompiler;
    NOpenGLProc::TRenderbufferStorage glRenderbufferStorage;
    NOpenGLProc::TSampleCoverage glSampleCoverage;
    NOpenGLProc::TShaderBinary glShaderBinary;
    NOpenGLProc::TShaderSource glShaderSource;
    NOpenGLProc::TStencilFuncSeparate glStencilFuncSeparate;
    NOpenGLProc::TStencilMaskSeparate glStencilMaskSeparate;
    NOpenGLProc::TStencilOpSeparate glStencilOpSeparate;
    NOpenGLProc::TUniform1f glUniform1f;
    NOpenGLProc::TUniform1fv glUniform1fv;
    NOpenGLProc::TUniform1i glUniform1i;
    NOpenGLProc::TUniform1iv glUniform1iv;
    NOpenGLProc::TUniform2f glUniform2f;
    NOpenGLProc::TUniform2fv glUniform2fv;
    NOpenGLProc::TUniform2i glUniform2i;
    NOpenGLProc::TUniform2iv glUniform2iv;
    NOpenGLProc::TUniform3f glUniform3f;
    NOpenGLProc::TUniform3fv glUniform3fv;
    NOpenGLProc::TUniform3i glUniform3i;
    NOpenGLProc::TUniform3iv glUniform3iv;
    NOpenGLProc::TUniform4f glUniform4f;
    NOpenGLProc::TUniform4fv glUniform4fv;
    NOpenGLProc::TUniform4i glUniform4i;
    NOpenGLProc::TUniform4iv glUniform4iv;
    NOpenGLProc::TUniformMatrix2fv glUniformMatrix2fv;
    NOpenGLProc::TUniformMatrix3fv glUniformMatrix3fv;
    NOpenGLProc::TUniformMatrix4fv glUniformMatrix4fv;
    NOpenGLProc::TUseProgram glUseProgram;
    NOpenGLProc::TValidateProgram glValidateProgram;
    NOpenGLProc::TVertexAttrib1f glVertexAttrib1f;
    NOpenGLProc::TVertexAttrib1fv glVertexAttrib1fv;
    NOpenGLProc::TVertexAttrib2f glVertexAttrib2f;
    NOpenGLProc::TVertexAttrib2fv glVertexAttrib2fv;
    NOpenGLProc::TVertexAttrib3f glVertexAttrib3f;
    NOpenGLProc::TVertexAttrib3fv glVertexAttrib3fv;
    NOpenGLProc::TVertexAttrib4f glVertexAttrib4f;
    NOpenGLProc::TVertexAttrib4fv glVertexAttrib4fv;
    NOpenGLProc::TVertexAttribPointer glVertexAttribPointer;
#endif

  public:
    COpenGL(void);
    COpenGL(CContext *context);
    ~COpenGL(void);

#ifndef QT_OPENGL_ES_2
    inline void activeTexture(GLenum texture) { if(glActiveTexture) glActiveTexture(texture); }
    inline void attachShader(GLuint program, GLuint shader) { if(glAttachShader) glAttachShader(program, shader); }
    inline void bindAttribLocation(GLuint program, GLuint index, const GLchar *name) { if(glBindAttribLocation) glBindAttribLocation(program, index, name); }
    inline void bindBuffer(GLenum target, GLuint buffer) { if(glBindBuffer) glBindBuffer(target, buffer); }
    inline void bindFramebuffer(GLenum target, GLuint framebuffer) { if(glBindFramebuffer) glBindFramebuffer(target, framebuffer); }
    inline void bindRenderbuffer(GLenum target, GLuint renderbuffer) { if(glBindRenderbuffer) glBindRenderbuffer(target, renderbuffer); }
    inline void bindTexture(GLenum target, GLuint texture) { glBindTexture(target, texture); }
    inline void blendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) { if(glBlendColor) glBlendColor(red, green, blue, alpha); }
    inline void blendEquation(GLenum mode) { if(glBlendEquation) glBlendEquation(mode); }
    inline void blendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { if(glBlendEquationSeparate) glBlendEquationSeparate(modeRGB, modeAlpha); }
    inline void blendFunc(GLenum sfactor, GLenum dfactor) { glBlendFunc(sfactor, dfactor); }
    inline void blendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { if(glBlendFuncSeparate) glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha); }
    inline void bufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage) { if(glBufferData) glBufferData(target, size, data, usage); }
    inline void bufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data) { if(glBufferSubData) glBufferSubData(target, offset, size, data); }
    inline GLenum checkFramebufferStatus(GLenum target) { if(glCheckFramebufferStatus) return glCheckFramebufferStatus(target); return 0; }
    inline void clear(GLbitfield mask) { glClear(mask); }
    inline void clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) { glClearColor(red, green, blue, alpha); }
    inline void clearDepth(GLclampf depth) { glClearDepth(static_cast<double>(depth)); }
    inline void clearStencil(GLint s) { glClearStencil(s); }
    inline void colorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { glColorMask(red, green, blue, alpha); }
    inline void compileShader(GLuint shader) { if(glCompileShader) glCompileShader(shader); }
    inline void compressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) { if(glCompressedTexImage2D) glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
    inline void compressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) { if(glCompressedTexSubImage2D) glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
    inline void copyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) { glCopyTexImage2D(target, level, internalformat, x, y, width, height, border); }
    inline void copyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
    inline GLuint createProgram(void) { if(glCreateProgram) return glCreateProgram(); return 0; }
    inline GLuint createShader(GLenum type) { if(glCreateShader) return glCreateShader(type); return 0; }
    inline void cullFace(GLenum mode) { glCullFace(mode); }
    inline void deleteBuffers(GLsizei n, const GLuint *buffers) { if(glDeleteBuffers) glDeleteBuffers(n, buffers); }
    inline void deleteFramebuffers(GLsizei n, const GLuint *framebuffers) { if(glDeleteFramebuffers) glDeleteFramebuffers(n, framebuffers); }
    inline void deleteTextures(GLsizei n, const GLuint *textures) { glDeleteTextures(n, textures); }
    inline void deleteProgram(GLuint program) { if(glDeleteProgram) glDeleteProgram(program); }
    inline void deleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) { if(glDeleteRenderbuffers) glDeleteRenderbuffers(n, renderbuffers); }
    inline void deleteShader(GLuint shader) { if(glDeleteShader) glDeleteShader(shader); }
    inline void detachShader(GLuint program, GLuint shader) { if(glDetachShader) glDetachShader(program, shader); }
    inline void depthFunc(GLenum func) {  glDepthFunc(func); }
    inline void depthMask(GLboolean flag) { glDepthMask(flag); }
    inline void depthRange(GLclampf zNear, GLclampf zFar) { glDepthRange(static_cast<double>(zNear), static_cast<double>(zFar)); }
    inline void disable(GLenum cap) { glDisable(cap); }
    inline void disableVertexAttribArray(GLuint index) { if(glDisableVertexAttribArray) glDisableVertexAttribArray(index); }
    inline void drawArrays(GLenum mode, GLint first, GLsizei count) { glDrawArrays(mode, first, count); }
    inline void drawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) { glDrawElements(mode, count, type, indices); }
    inline void enable(GLenum cap) { glEnable(cap); }
    inline void enableVertexAttribArray(GLuint index) { if(glEnableVertexAttribArray) glEnableVertexAttribArray(index); }
    inline void finish(void) { glFinish(); }
    inline void flush(void) { glFlush(); }
    inline void framebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { if(glFramebufferRenderbuffer) glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); }
    inline void framebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { if(glFramebufferTexture2D) glFramebufferTexture2D(target, attachment, textarget, texture, level); }
    inline void frontFace(GLenum mode) { glFrontFace(mode); }
    inline void genBuffers(GLsizei n, GLuint *buffers) { if(glGenBuffers) glGenBuffers(n, buffers); }
    inline void generateMipmap(GLenum target) { if(glGenerateMipmap) glGenerateMipmap(target); }
    inline void genFramebuffers(GLsizei n, GLuint *framebuffers) { if(glGenFramebuffers) glGenFramebuffers(n, framebuffers); }
    inline void genRenderbuffers(GLsizei n, GLuint *renderbuffers) { if(glGenRenderbuffers) glGenRenderbuffers(n, renderbuffers); }
    inline void genTextures(GLsizei n, GLuint *textures) { glGenTextures(n, textures); }
    inline void getActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { if(glGetActiveAttrib) glGetActiveAttrib(program, index, bufsize, length, size, type, name); }
    inline void getActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { if(glGetActiveUniform) glGetActiveUniform(program, index, bufsize, length, size, type, name); }
    inline void getAttachedShaders(GLuint program, GLsizei maxcount, GLsizei *count, GLuint *shaders) { if(glGetAttachedShaders) glGetAttachedShaders(program, maxcount, count, shaders); }
    inline GLint getAttribLocation(GLuint program, const GLchar *name) { if(glGetAttribLocation) return glGetAttribLocation(program, name); return 0; }
    inline void getBooleanv(GLenum pname, GLboolean *params) { glGetBooleanv(pname, params); }
    inline void getBufferParameteriv(GLenum target, GLenum pname, GLint *params) { if(glGetBufferParameteriv) glGetBufferParameteriv(target, pname, params); }
    inline GLenum getError(void) { return glGetError(); }
    inline void getFloatv(GLenum pname, GLfloat *params) { glGetFloatv(pname, params); }
    inline void getFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) { if(glGetFramebufferAttachmentParameteriv) glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); }
    inline void getIntegerv(GLenum pname, GLint *params) { glGetIntegerv(pname, params); }
    inline void getProgramiv(GLuint program, GLenum pname, GLint *params) { if(glGetProgramiv) glGetProgramiv(program, pname, params); }
    inline void getProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei *length, GLchar *infolog) { if(glGetProgramInfoLog) glGetProgramInfoLog(program, bufsize, length, infolog); }
    inline void getRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) { if(glGetRenderbufferParameteriv) glGetRenderbufferParameteriv(target, pname, params); }
    inline void getShaderiv(GLuint shader, GLenum pname, GLint *params) { if(glGetShaderiv) glGetShaderiv(shader, pname, params); }
    inline void getShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *infolog) { if(glGetShaderInfoLog) glGetShaderInfoLog(shader, bufsize, length, infolog); }
    inline void getShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) { if(glGetShaderPrecisionFormat) glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision); }
    inline void getShaderSource(GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *source) { if(glGetShaderSource) glGetShaderSource(shader, bufsize, length, source); }
    inline const GLubyte *getString(GLenum name) { return getString(name); }
    inline void getTexParameterfv(GLenum target, GLenum pname, GLfloat *params) { glGetTexParameterfv(target, pname, params); }
    inline void getTexParameteriv(GLenum target, GLenum pname, GLint *params) { glGetTexParameteriv(target, pname, params); }
    inline void getUniformfv(GLuint program, GLint location, GLfloat *params) { if(glGetUniformfv) glGetUniformfv(program, location, params); }
    inline void getUniformiv(GLuint program, GLint location, GLint *params) { if(glGetUniformiv) glGetUniformiv(program, location, params); }
    inline GLint getUniformLocation(GLuint program, const GLchar *name) { if(glGetUniformLocation) return glGetUniformLocation(program, name); return 0; }
    inline void getVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) { if(glGetVertexAttribfv) glGetVertexAttribfv(index, pname, params); }
    inline void getVertexAttribiv(GLuint index, GLenum pname, GLint *params) { if(glGetVertexAttribiv) glGetVertexAttribiv(index, pname, params); }
    inline void getVertexAttribPointerv(GLuint index, GLenum pname, GLvoid **pointer) { if(glGetVertexAttribPointerv) glGetVertexAttribPointerv(index, pname, pointer); }
    inline void hint(GLenum target, GLenum mode) { glHint(target, mode); }
    inline GLboolean isBuffer(GLuint buffer) { if(glIsBuffer) return glIsBuffer(buffer); return NOpenGL::FALSE; }
    inline GLboolean isEnabled(GLenum cap) { return glIsEnabled(cap); }
    inline GLboolean isFramebuffer(GLuint framebuffer) { if(glIsFramebuffer) return glIsFramebuffer(framebuffer); return NOpenGL::FALSE; }
    inline GLboolean isProgram(GLuint program) { if(glIsProgram) return glIsProgram(program); return NOpenGL::FALSE; }
    inline GLboolean isRenderbuffer(GLuint renderbuffer) { if(glIsRenderbuffer) return glIsRenderbuffer(renderbuffer); return NOpenGL::FALSE; }
    inline GLboolean isShader(GLuint shader) { if(glIsShader) return glIsShader(shader); return NOpenGL::FALSE; }
    inline GLboolean isTexture(GLuint texture) { return glIsTexture(texture); }
    inline void lineWidth(GLfloat width) { glLineWidth(width); }
    inline void linkProgram(GLuint program) { if(glLinkProgram) glLinkProgram(program); }
    inline void pixelStorei(GLenum pname, GLint param) { glPixelStorei(pname, param); }
    inline void polygonOffset(GLfloat factor, GLfloat units) { glPolygonOffset(factor, units); }
    inline void readPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels) { glReadPixels(x, y, width, height, format, type, pixels); }
    inline void releaseShaderCompiler(void) { if(glReleaseShaderCompiler) glReleaseShaderCompiler(); }
    inline void renderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) { if(glRenderbufferStorage) glRenderbufferStorage(target, internalformat, width, height); }
    inline void sampleCoverage(GLclampf value, GLboolean invert) { if(glSampleCoverage) glSampleCoverage(value, invert); }
    inline void scissor(GLint x, GLint y, GLsizei width, GLsizei height) { glScissor(x, y, width, height); }
    inline void shaderBinary(GLint n, const GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLint length) { if(glShaderBinary) glShaderBinary(n, shaders, binaryformat, binary, length); }
    inline void shaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) { if(glShaderSource) glShaderSource(shader, count, string, length); }
    inline void stencilFunc(GLenum func, GLint ref, GLuint mask) { glStencilFunc(func, ref, mask); }
    inline void stencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { if(glStencilFuncSeparate) glStencilFuncSeparate(face, func, ref, mask); }
    inline void stencilMask(GLuint mask) { glStencilMask(mask); }
    inline void stencilMaskSeparate(GLenum face, GLuint mask) { if(glStencilMaskSeparate) glStencilMaskSeparate(face, mask); }
    inline void stencilOp(GLenum fail, GLenum zfail, GLenum zpass) { glStencilOp(fail, zfail, zpass); }
    inline void stencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass) { if(glStencilOpSeparate) glStencilOpSeparate(face, fail, zfail, zpass); }
    inline void texImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) { glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); }
    inline void texParameterf(GLenum target, GLenum pname, GLfloat param) { glTexParameterf(target, pname, param); }
    inline void texParameterfv(GLenum target, GLenum pname, const GLfloat *params) { glTexParameterfv(target, pname, params); }
    inline void texParameteri(GLenum target, GLenum pname, GLint param) { glTexParameteri(target, pname, param); }
    inline void texParameteriv(GLenum target, GLenum pname, const GLint *params) { glTexParameteriv(target, pname, params); }
    inline void texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) { glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }
    inline void uniform1f(GLint location, GLfloat x) { if(glUniform1f) glUniform1f(location, x); }
    inline void uniform1fv(GLint location, GLsizei count, const GLfloat *v) { if(glUniform1fv) glUniform1fv(location, count, v); }
    inline void uniform1i(GLint location, GLint x) { if(glUniform1i) glUniform1i(location, x); }
    inline void uniform1iv(GLint location, GLsizei count, const GLint *v) { if(glUniform1iv) glUniform1iv(location, count, v); }
    inline void uniform2f(GLint location, GLfloat x, GLfloat y) { if(glUniform2f) glUniform2f(location, x, y); }
    inline void uniform2fv(GLint location, GLsizei count, const GLfloat *v) { if(glUniform2fv) glUniform2fv(location, count, v); }
    inline void uniform2i(GLint location, GLint x, GLint y) { if(glUniform2i) glUniform2i(location, x, y); }
    inline void uniform2iv(GLint location, GLsizei count, const GLint *v) { if(glUniform2iv) glUniform2iv(location, count, v); }
    inline void uniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z) { if(glUniform3f) glUniform3f(location, x, y, z); }
    inline void uniform3fv(GLint location, GLsizei count, const GLfloat *v) { if(glUniform3fv) glUniform3fv(location, count, v); }
    inline void uniform3i(GLint location, GLint x, GLint y, GLint z) { if(glUniform3i) glUniform3i(location, x, y, z); }
    inline void uniform3iv(GLint location, GLsizei count, const GLint *v) { if(glUniform3iv) glUniform3iv(location, count, v); }
    inline void uniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { if(glUniform4f) glUniform4f(location, x, y, z, w); }
    inline void uniform4fv(GLint location, GLsizei count, const GLfloat *v) { if(glUniform4fv) glUniform4fv(location, count, v); }
    inline void uniform4i(GLint location, GLint x, GLint y, GLint z, GLint w) { if(glUniform4i) glUniform4i(location, x, y, z, w); }
    inline void uniform4iv(GLint location, GLsizei count, const GLint *v) { if(glUniform4iv) glUniform4iv(location, count, v); }
    inline void uniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if(glUniformMatrix2fv) glUniformMatrix2fv(location, count, transpose, value); }
    inline void uniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if(glUniformMatrix3fv) glUniformMatrix3fv(location, count, transpose, value); }
    inline void uniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { if(glUniformMatrix4fv) glUniformMatrix4fv(location, count, transpose, value); }
    inline void useProgram(GLuint program) { if(glUseProgram) glUseProgram(program); }
    inline void validateProgram(GLuint program) { if(glValidateProgram) glValidateProgram(program); }
    inline void vertexAttrib1f(GLuint indx, GLfloat x) { if(glVertexAttrib1f) glVertexAttrib1f(indx, x); }
    inline void vertexAttrib1fv(GLuint indx, const GLfloat *values) { if(glVertexAttrib1fv) glVertexAttrib1fv(indx, values); }
    inline void vertexAttrib2f(GLuint indx, GLfloat x, GLfloat y) { if(glVertexAttrib2f) glVertexAttrib2f(indx, x, y); }
    inline void vertexAttrib2fv(GLuint indx, const GLfloat *values) { if(glVertexAttrib2fv) glVertexAttrib2fv(indx, values); }
    inline void vertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z) { if(glVertexAttrib3f) glVertexAttrib3f(indx, x, y, z); }
    inline void vertexAttrib3fv(GLuint indx, const GLfloat *values) { if(glVertexAttrib3fv) glVertexAttrib3fv(indx, values); }
    inline void vertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { if(glVertexAttrib4f) glVertexAttrib4f(indx, x, y, z, w); }
    inline void vertexAttrib4fv(GLuint indx, const GLfloat *values) { if(glVertexAttrib4fv) glVertexAttrib4fv(indx, values); }
    inline void vertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *ptr) { if(glVertexAttribPointer) glVertexAttribPointer(indx, size, type, normalized, stride, ptr); }
    inline void viewport(GLint x, GLint y, GLsizei width, GLsizei height) { glViewport(x, y, width, height); }

    inline NOpenGLProc::TExtensionProc getExtension(QString name) { NOpenGLProc::TExtensionProc extension = reinterpret_cast<NOpenGLProc::TExtensionProc>(wglGetProcAddress(name.toStdString().c_str())); if(!extension) qDebug(QString("Unable to find OpenGL extension: \""+name+"\"!").toStdString().c_str()); return extension; }
#else
    inline void activeTexture(GLenum texture) { glActiveTexture(texture); }
    inline void attachShader(GLuint program, GLuint shader) { glAttachShader(program, shader); }
    inline void bindAttribLocation(GLuint program, GLuint index, const GLchar *name) { glBindAttribLocation(program, index, name); }
    inline void bindBuffer(GLenum target, GLuint buffer) { glBindBuffer(target, buffer); }
    inline void bindFramebuffer(GLenum target, GLuint framebuffer) { glBindFramebuffer(target, framebuffer); }
    inline void bindRenderbuffer(GLenum target, GLuint renderbuffer) { glBindRenderbuffer(target, renderbuffer); }
    inline void bindTexture(GLenum target, GLuint texture) { glBindTexture(target, texture); }
    inline void blendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) { glBlendColor(red, green, blue, alpha); }
    inline void blendEquation(GLenum mode) { glBlendEquation(mode); }
    inline void blendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { glBlendEquationSeparate(modeRGB, modeAlpha); }
    inline void blendFunc(GLenum sfactor, GLenum dfactor) { glBlendFunc(sfactor, dfactor); }
    inline void blendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha); }
    inline void bufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage) { glBufferData(target, size, data, usage); }
    inline void bufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data) { glBufferSubData(target, offset, size, data); }
    inline GLenum checkFramebufferStatus(GLenum target) { return glCheckFramebufferStatus(target); }
    inline void clear(GLbitfield mask) { glClear(mask); }
    inline void clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) { glClearColor(red, green, blue, alpha); }
    inline void clearDepth(GLclampf depth) { glClearDepthf(depth); }
    inline void clearStencil(GLint s) { glClearStencil(s); }
    inline void colorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { glColorMask(red, green, blue, alpha); }
    inline void compileShader(GLuint shader) { glCompileShader(shader); }
    inline void compressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) { glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
    inline void compressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) { glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
    inline void copyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) { glCopyTexImage2D(target, level, internalformat, x, y, width, height, border); }
    inline void copyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
    inline GLuint createProgram(void) { return glCreateProgram(); }
    inline GLuint createShader(GLenum type) { return glCreateShader(type); }
    inline void cullFace(GLenum mode) { glCullFace(mode); }
    inline void deleteBuffers(GLsizei n, const GLuint *buffers) { glDeleteBuffers(n, buffers); }
    inline void deleteFramebuffers(GLsizei n, const GLuint *framebuffers) { glDeleteFramebuffers(n, framebuffers); }
    inline void deleteTextures(GLsizei n, const GLuint *textures) { glDeleteTextures(n, textures); }
    inline void deleteProgram(GLuint program) { glDeleteProgram(program); }
    inline void deleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) { glDeleteRenderbuffers(n, renderbuffers); }
    inline void deleteShader(GLuint shader) { glDeleteShader(shader); }
    inline void detachShader(GLuint program, GLuint shader) { glDetachShader(program, shader); }
    inline void depthFunc(GLenum func) {  glDepthFunc(func); }
    inline void depthMask(GLboolean flag) { glDepthMask(flag); }
    inline void depthRange(GLclampf zNear, GLclampf zFar) { glDepthRangef(zNear, zFar); }
    inline void disable(GLenum cap) { glDisable(cap); }
    inline void disableVertexAttribArray(GLuint index) { glDisableVertexAttribArray(index); }
    inline void drawArrays(GLenum mode, GLint first, GLsizei count) { glDrawArrays(mode, first, count); }
    inline void drawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) { glDrawElements(mode, count, type, indices); }
    inline void enable(GLenum cap) { glEnable(cap); }
    inline void enableVertexAttribArray(GLuint index) { glEnableVertexAttribArray(index); }
    inline void finish(void) { glFinish(); }
    inline void flush(void) { glFlush(); }
    inline void framebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) { glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer); }
    inline void framebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { glFramebufferTexture2D(target, attachment, textarget, texture, level); }
    inline void frontFace(GLenum mode) { glFrontFace(mode); }
    inline void genBuffers(GLsizei n, GLuint *buffers) { glGenBuffers(n, buffers); }
    inline void generateMipmap(GLenum target) { glGenerateMipmap(target); }
    inline void genFramebuffers(GLsizei n, GLuint *framebuffers) { glGenFramebuffers(n, framebuffers); }
    inline void genRenderbuffers(GLsizei n, GLuint *renderbuffers) { glGenRenderbuffers(n, renderbuffers); }
    inline void genTextures(GLsizei n, GLuint *textures) { glGenTextures(n, textures); }
    inline void getActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { glGetActiveAttrib(program, index, bufsize, length, size, type, name); }
    inline void getActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { glGetActiveUniform(program, index, bufsize, length, size, type, name); }
    inline void getAttachedShaders(GLuint program, GLsizei maxcount, GLsizei *count, GLuint *shaders) { glGetAttachedShaders(program, maxcount, count, shaders); }
    inline int  getAttribLocation(GLuint program, const GLchar *name) { return glGetAttribLocation(program, name); }
    inline void getBooleanv(GLenum pname, GLboolean *params) { glGetBooleanv(pname, params); }
    inline void getBufferParameteriv(GLenum target, GLenum pname, GLint *params) { glGetBufferParameteriv(target, pname, params); }
    inline GLenum getError(void) { return glGetError(); }
    inline void getFloatv(GLenum pname, GLfloat *params) { glGetFloatv(pname, params); }
    inline void getFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) { glGetFramebufferAttachmentParameteriv(target, attachment, pname, params); }
    inline void getIntegerv(GLenum pname, GLint *params) { glGetIntegerv(pname, params); }
    inline void getProgramiv(GLuint program, GLenum pname, GLint *params) { glGetProgramiv(program, pname, params); }
    inline void getProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei *length, GLchar *infolog) { glGetProgramInfoLog(program, bufsize, length, infolog); }
    inline void getRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params) { glGetRenderbufferParameteriv(target, pname, params); }
    inline void getShaderiv(GLuint shader, GLenum pname, GLint *params) { glGetShaderiv(shader, pname, params); }
    inline void getShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *infolog) { glGetShaderInfoLog(shader, bufsize, length, infolog); }
    inline void getShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) { glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision); }
    inline void getShaderSource(GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *source) { glGetShaderSource(shader, bufsize, length, source); }
    inline const GLubyte *getString(GLenum name) { return getString(name); }
    inline void getTexParameterfv(GLenum target, GLenum pname, GLfloat *params) { glGetTexParameterfv(target, pname, params); }
    inline void getTexParameteriv(GLenum target, GLenum pname, GLint *params) { glGetTexParameteriv(target, pname, params); }
    inline void getUniformfv(GLuint program, GLint location, GLfloat *params) { glGetUniformfv(program, location, params); }
    inline void getUniformiv(GLuint program, GLint location, GLint *params) { glGetUniformiv(program, location, params); }
    inline int  getUniformLocation(GLuint program, const GLchar *name) { return glGetUniformLocation(program, name); }
    inline void getVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) { glGetVertexAttribfv(index, pname, params); }
    inline void getVertexAttribiv(GLuint index, GLenum pname, GLint *params) { glGetVertexAttribiv(index, pname, params); }
    inline void getVertexAttribPointerv(GLuint index, GLenum pname, GLvoid **pointer) { glGetVertexAttribPointerv(index, pname, pointer); }
    inline void hint(GLenum target, GLenum mode) { glHint(target, mode); }
    inline GLboolean isBuffer(GLuint buffer) { return glIsBuffer(buffer); }
    inline GLboolean isEnabled(GLenum cap) { return glIsEnabled(cap); }
    inline GLboolean isFramebuffer(GLuint framebuffer) { return glIsFramebuffer(framebuffer); }
    inline GLboolean isProgram(GLuint program) { return glIsProgram(program); }
    inline GLboolean isRenderbuffer(GLuint renderbuffer) { return glIsRenderbuffer(renderbuffer); }
    inline GLboolean isShader(GLuint shader) { return glIsShader(shader); }
    inline GLboolean isTexture(GLuint texture) { return glIsTexture(texture); }
    inline void lineWidth(GLfloat width) { glLineWidth(width); }
    inline void linkProgram(GLuint program) { glLinkProgram(program); }
    inline void pixelStorei(GLenum pname, GLint param) { glPixelStorei(pname, param); }
    inline void polygonOffset(GLfloat factor, GLfloat units) { glPolygonOffset(factor, units); }
    inline void readPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels) { glReadPixels(x, y, width, height, format, type, pixels); }
    inline void releaseShaderCompiler(void) { glReleaseShaderCompiler(); }
    inline void renderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) { glRenderbufferStorage(target, internalformat, width, height); }
    inline void sampleCoverage(GLclampf value, GLboolean invert) { glSampleCoverage(value, invert); }
    inline void scissor(GLint x, GLint y, GLsizei width, GLsizei height) { glScissor(x, y, width, height); }
    inline void shaderBinary(GLint n, const GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLint length) { glShaderBinary(n, shaders, binaryformat, binary, length); }
    inline void shaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) { glShaderSource(shader, count, string, length); }
    inline void stencilFunc(GLenum func, GLint ref, GLuint mask) { glStencilFunc(func, ref, mask); }
    inline void stencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { glStencilFuncSeparate(face, func, ref, mask); }
    inline void stencilMask(GLuint mask) { glStencilMask(mask); }
    inline void stencilMaskSeparate(GLenum face, GLuint mask) { glStencilMaskSeparate(face, mask); }
    inline void stencilOp(GLenum fail, GLenum zfail, GLenum zpass) { glStencilOp(fail, zfail, zpass); }
    inline void stencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass) { glStencilOpSeparate(face, fail, zfail, zpass); }
    inline void texImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) { glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); }
    inline void texParameterf(GLenum target, GLenum pname, GLfloat param) { glTexParameterf(target, pname, param); }
    inline void texParameterfv(GLenum target, GLenum pname, const GLfloat *params) { glTexParameterfv(target, pname, params); }
    inline void texParameteri(GLenum target, GLenum pname, GLint param) { glTexParameteri(target, pname, param); }
    inline void texParameteriv(GLenum target, GLenum pname, const GLint *params) { glTexParameteriv(target, pname, params); }
    inline void texSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) { glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }
    inline void uniform1f(GLint location, GLfloat x) { glUniform1f(location, x); }
    inline void uniform1fv(GLint location, GLsizei count, const GLfloat *v) { glUniform1fv(location, count, v); }
    inline void uniform1i(GLint location, GLint x) { glUniform1i(location, x); }
    inline void uniform1iv(GLint location, GLsizei count, const GLint *v) { glUniform1iv(location, count, v); }
    inline void uniform2f(GLint location, GLfloat x, GLfloat y) { glUniform2f(location, x, y); }
    inline void uniform2fv(GLint location, GLsizei count, const GLfloat *v) { glUniform2fv(location, count, v); }
    inline void uniform2i(GLint location, GLint x, GLint y) { glUniform2i(location, x, y); }
    inline void uniform2iv(GLint location, GLsizei count, const GLint *v) { glUniform2iv(location, count, v); }
    inline void uniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z) { glUniform3f(location, x, y, z); }
    inline void uniform3fv(GLint location, GLsizei count, const GLfloat *v) { glUniform3fv(location, count, v); }
    inline void uniform3i(GLint location, GLint x, GLint y, GLint z) { glUniform3i(location, x, y, z); }
    inline void uniform3iv(GLint location, GLsizei count, const GLint *v) { glUniform3iv(location, count, v); }
    inline void uniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { glUniform4f(location, x, y, z, w); }
    inline void uniform4fv(GLint location, GLsizei count, const GLfloat *v) { glUniform4fv(location, count, v); }
    inline void uniform4i(GLint location, GLint x, GLint y, GLint z, GLint w) { glUniform4i(location, x, y, z, w); }
    inline void uniform4iv(GLint location, GLsizei count, const GLint *v) { glUniform4iv(location, count, v); }
    inline void uniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix2fv(location, count, transpose, value); }
    inline void uniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix3fv(location, count, transpose, value); }
    inline void uniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { glUniformMatrix4fv(location, count, transpose, value); }
    inline void useProgram(GLuint program) { glUseProgram(program); }
    inline void validateProgram(GLuint program) { glValidateProgram(program); }
    inline void vertexAttrib1f(GLuint indx, GLfloat x) { glVertexAttrib1f(indx, x); }
    inline void vertexAttrib1fv(GLuint indx, const GLfloat *values) { glVertexAttrib1fv(indx, values); }
    inline void vertexAttrib2f(GLuint indx, GLfloat x, GLfloat y) { glVertexAttrib2f(indx, x, y); }
    inline void vertexAttrib2fv(GLuint indx, const GLfloat *values) { glVertexAttrib2fv(indx, values); }
    inline void vertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z) { glVertexAttrib3f(indx, x, y, z); }
    inline void vertexAttrib3fv(GLuint indx, const GLfloat *values) { glVertexAttrib3fv(indx, values); }
    inline void vertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { glVertexAttrib4f(indx, x, y, z, w); }
    inline void vertexAttrib4fv(GLuint indx, const GLfloat *values) { glVertexAttrib4fv(indx, values); }
    inline void vertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *ptr) { glVertexAttribPointer(indx, size, type, normalized, stride, ptr); }
    inline void viewport(GLint x, GLint y, GLsizei width, GLsizei height) { glViewport(x, y, width, height); }
#endif
};
//------------------------------------------------------------------------------
inline COpenGL::COpenGL() : CEngineBase()
#ifndef QT_OPENGL_ES_2
  ,
  glActiveTexture(NULL),
  glAttachShader(NULL),
  glBindAttribLocation(NULL),
  glBindBuffer(NULL),
  glBindFramebuffer(NULL),
  glBindRenderbuffer(NULL),
  glBlendColor(NULL),
  glBlendEquation(NULL),
  glBlendEquationSeparate(NULL),
  glBlendFuncSeparate(NULL),
  glBufferData(NULL),
  glBufferSubData(NULL),
  glCheckFramebufferStatus(NULL),
  glCompileShader(NULL),
  glCompressedTexImage2D(NULL),
  glCompressedTexSubImage2D(NULL),
  glCreateProgram(NULL),
  glCreateShader(NULL),
  glDeleteBuffers(NULL),
  glDeleteFramebuffers(NULL),
  glDeleteProgram(NULL),
  glDeleteRenderbuffers(NULL),
  glDeleteShader(NULL),
  glDetachShader(NULL),
  glDisableVertexAttribArray(NULL),
  glEnableVertexAttribArray(NULL),
  glFramebufferRenderbuffer(NULL),
  glFramebufferTexture2D(NULL),
  glGenBuffers(NULL),
  glGenerateMipmap(NULL),
  glGenFramebuffers(NULL),
  glGenRenderbuffers(NULL),
  glGetActiveAttrib(NULL),
  glGetActiveUniform(NULL),
  glGetAttachedShaders(NULL),
  glGetAttribLocation(NULL),
  glGetBufferParameteriv(NULL),
  glGetFramebufferAttachmentParameteriv(NULL),
  glGetProgramiv(NULL),
  glGetProgramInfoLog(NULL),
  glGetRenderbufferParameteriv(NULL),
  glGetShaderiv(NULL),
  glGetShaderInfoLog(NULL),
  glGetShaderPrecisionFormat(NULL),
  glGetShaderSource(NULL),
  glGetUniformfv(NULL),
  glGetUniformiv(NULL),
  glGetUniformLocation(NULL),
  glGetVertexAttribfv(NULL),
  glGetVertexAttribiv(NULL),
  glGetVertexAttribPointerv(NULL),
  glIsBuffer(NULL),
  glIsFramebuffer(NULL),
  glIsProgram(NULL),
  glIsRenderbuffer(NULL),
  glIsShader(NULL),
  glLinkProgram(NULL),
  glReleaseShaderCompiler(NULL),
  glRenderbufferStorage(NULL),
  glSampleCoverage(NULL),
  glShaderBinary(NULL),
  glShaderSource(NULL),
  glStencilFuncSeparate(NULL),
  glStencilMaskSeparate(NULL),
  glStencilOpSeparate(NULL),
  glUniform1f(NULL),
  glUniform1fv(NULL),
  glUniform1i(NULL),
  glUniform1iv(NULL),
  glUniform2f(NULL),
  glUniform2fv(NULL),
  glUniform2i(NULL),
  glUniform2iv(NULL),
  glUniform3f(NULL),
  glUniform3fv(NULL),
  glUniform3i(NULL),
  glUniform3iv(NULL),
  glUniform4f(NULL),
  glUniform4fv(NULL),
  glUniform4i(NULL),
  glUniform4iv(NULL),
  glUniformMatrix2fv(NULL),
  glUniformMatrix3fv(NULL),
  glUniformMatrix4fv(NULL),
  glUseProgram(NULL),
  glValidateProgram(NULL),
  glVertexAttrib1f(NULL),
  glVertexAttrib1fv(NULL),
  glVertexAttrib2f(NULL),
  glVertexAttrib2fv(NULL),
  glVertexAttrib3f(NULL),
  glVertexAttrib3fv(NULL),
  glVertexAttrib4f(NULL),
  glVertexAttrib4fv(NULL),
  glVertexAttribPointer(NULL)
#endif
{
}
//------------------------------------------------------------------------------
inline COpenGL::COpenGL(CContext *context) : CEngineBase(context)
{
#ifndef QT_OPENGL_ES_2
  glActiveTexture = reinterpret_cast<NOpenGLProc::TActiveTexture>(getExtension("glActiveTexture"));
  glAttachShader = reinterpret_cast<NOpenGLProc::TAttachShader>(getExtension("glAttachShader"));
  glBindAttribLocation = reinterpret_cast<NOpenGLProc::TBindAttribLocation>(getExtension("glBindAttribLocation"));
  glBindBuffer = reinterpret_cast<NOpenGLProc::TBindBuffer>(getExtension("glBindBuffer"));
  glBindFramebuffer = reinterpret_cast<NOpenGLProc::TBindFramebuffer>(getExtension("glBindFramebuffer"));
  glBindRenderbuffer = reinterpret_cast<NOpenGLProc::TBindRenderbuffer>(getExtension("glBindRenderbuffer"));
  glBlendColor = reinterpret_cast<NOpenGLProc::TBlendColor>(getExtension("glBlendColor"));
  glBlendEquation = reinterpret_cast<NOpenGLProc::TBlendEquation>(getExtension("glBlendEquation"));
  glBlendEquationSeparate = reinterpret_cast<NOpenGLProc::TBlendEquationSeparate>(getExtension("glBlendEquationSeparate"));
  glBlendFuncSeparate = reinterpret_cast<NOpenGLProc::TBlendFuncSeparate>(getExtension("glBlendFuncSeparate"));
  glBufferData = reinterpret_cast<NOpenGLProc::TBufferData>(getExtension("glBufferData"));
  glBufferSubData = reinterpret_cast<NOpenGLProc::TBufferSubData>(getExtension("glBufferSubData"));
  glCheckFramebufferStatus = reinterpret_cast<NOpenGLProc::TCheckFramebufferStatus>(getExtension("glCheckFramebufferStatus"));
  glCompileShader = reinterpret_cast<NOpenGLProc::TCompileShader>(getExtension("glCompileShader"));
  glCompressedTexImage2D = reinterpret_cast<NOpenGLProc::TCompressedTexImage2D>(getExtension("glCompressedTexImage2D"));
  glCompressedTexSubImage2D = reinterpret_cast<NOpenGLProc::TCompressedTexSubImage2D>(getExtension("glCompressedTexSubImage2D"));
  glCreateProgram = reinterpret_cast<NOpenGLProc::TCreateProgram>(getExtension("glCreateProgram"));
  glCreateShader = reinterpret_cast<NOpenGLProc::TCreateShader>(getExtension("glCreateShader"));
  glDeleteBuffers = reinterpret_cast<NOpenGLProc::TDeleteBuffers>(getExtension("glDeleteBuffers"));
  glDeleteFramebuffers = reinterpret_cast<NOpenGLProc::TDeleteFramebuffers>(getExtension("glDeleteFramebuffers"));
  glDeleteProgram = reinterpret_cast<NOpenGLProc::TDeleteProgram>(getExtension("glDeleteProgram"));
  glDeleteRenderbuffers = reinterpret_cast<NOpenGLProc::TDeleteRenderbuffers>(getExtension("glDeleteRenderbuffers"));
  glDeleteShader = reinterpret_cast<NOpenGLProc::TDeleteShader>(getExtension("glDeleteShader"));
  glDetachShader = reinterpret_cast<NOpenGLProc::TDetachShader>(getExtension("glDetachShader"));
  glDisableVertexAttribArray = reinterpret_cast<NOpenGLProc::TDisableVertexAttribArray>(getExtension("glDisableVertexAttribArray"));
  glEnableVertexAttribArray = reinterpret_cast<NOpenGLProc::TEnableVertexAttribArray>(getExtension("glEnableVertexAttribArray"));
  glFramebufferRenderbuffer = reinterpret_cast<NOpenGLProc::TFramebufferRenderbuffer>(getExtension("glFramebufferRenderbuffer"));
  glFramebufferTexture2D = reinterpret_cast<NOpenGLProc::TFramebufferTexture2D>(getExtension("glFramebufferTexture2D"));
  glGenBuffers = reinterpret_cast<NOpenGLProc::TGenBuffers>(getExtension("glGenBuffers"));
  glGenerateMipmap = reinterpret_cast<NOpenGLProc::TGenerateMipmap>(getExtension("glGenerateMipmap"));
  glGenFramebuffers = reinterpret_cast<NOpenGLProc::TGenFramebuffers>(getExtension("glGenFramebuffers"));
  glGenRenderbuffers = reinterpret_cast<NOpenGLProc::TGenRenderbuffers>(getExtension("glGenRenderbuffers"));
  glGetActiveAttrib = reinterpret_cast<NOpenGLProc::TGetActiveAttrib>(getExtension("glGetActiveAttrib"));
  glGetActiveUniform = reinterpret_cast<NOpenGLProc::TGetActiveUniform>(getExtension("glGetActiveUniform"));
  glGetAttachedShaders = reinterpret_cast<NOpenGLProc::TGetAttachedShaders>(getExtension("glGetAttachedShaders"));
  glGetAttribLocation = reinterpret_cast<NOpenGLProc::TGetAttribLocation>(getExtension("glGetAttribLocation"));
  glGetBufferParameteriv = reinterpret_cast<NOpenGLProc::TGetBufferParameteriv>(getExtension("glGetBufferParameteriv"));
  glGetFramebufferAttachmentParameteriv = reinterpret_cast<NOpenGLProc::TGetFramebufferAttachmentParameteriv>(getExtension("glGetFramebufferAttachmentParameteriv"));
  glGetProgramiv = reinterpret_cast<NOpenGLProc::TGetProgramiv>(getExtension("glGetProgramiv"));
  glGetProgramInfoLog = reinterpret_cast<NOpenGLProc::TGetProgramInfoLog>(getExtension("glGetProgramInfoLog"));
  glGetRenderbufferParameteriv = reinterpret_cast<NOpenGLProc::TGetRenderbufferParameteriv>(getExtension("glGetRenderbufferParameteriv"));
  glGetShaderiv = reinterpret_cast<NOpenGLProc::TGetShaderiv>(getExtension("glGetShaderiv"));
  glGetShaderInfoLog = reinterpret_cast<NOpenGLProc::TGetShaderInfoLog>(getExtension("glGetShaderInfoLog"));
  glGetShaderPrecisionFormat = reinterpret_cast<NOpenGLProc::TGetShaderPrecisionFormat>(getExtension("glGetShaderPrecisionFormat"));
  glGetShaderSource = reinterpret_cast<NOpenGLProc::TGetShaderSource>(getExtension("glGetShaderSource"));
  glGetUniformfv = reinterpret_cast<NOpenGLProc::TGetUniformfv>(getExtension("glGetUniformfv"));
  glGetUniformiv = reinterpret_cast<NOpenGLProc::TGetUniformiv>(getExtension("glGetUniformiv"));
  glGetUniformLocation = reinterpret_cast<NOpenGLProc::TGetUniformLocation>(getExtension("glGetUniformLocation"));
  glGetVertexAttribfv = reinterpret_cast<NOpenGLProc::TGetVertexAttribfv>(getExtension("glGetVertexAttribfv"));
  glGetVertexAttribiv = reinterpret_cast<NOpenGLProc::TGetVertexAttribiv>(getExtension("glGetVertexAttribiv"));
  glGetVertexAttribPointerv = reinterpret_cast<NOpenGLProc::TGetVertexAttribPointerv>(getExtension("glGetVertexAttribPointerv"));
  glIsBuffer = reinterpret_cast<NOpenGLProc::TIsBuffer>(getExtension("glIsBuffer"));
  glIsFramebuffer = reinterpret_cast<NOpenGLProc::TIsFramebuffer>(getExtension("glIsFramebuffer"));
  glIsProgram = reinterpret_cast<NOpenGLProc::TIsProgram>(getExtension("glIsProgram"));
  glIsRenderbuffer = reinterpret_cast<NOpenGLProc::TIsRenderbuffer>(getExtension("glIsRenderbuffer"));
  glIsShader = reinterpret_cast<NOpenGLProc::TIsShader>(getExtension("glIsShader"));
  glLinkProgram = reinterpret_cast<NOpenGLProc::TLinkProgram>(getExtension("glLinkProgram"));
  glReleaseShaderCompiler = reinterpret_cast<NOpenGLProc::TReleaseShaderCompiler>(getExtension("glReleaseShaderCompiler"));
  glRenderbufferStorage = reinterpret_cast<NOpenGLProc::TRenderbufferStorage>(getExtension("glRenderbufferStorage"));
  glSampleCoverage = reinterpret_cast<NOpenGLProc::TSampleCoverage>(getExtension("glSampleCoverage"));
  glShaderBinary = reinterpret_cast<NOpenGLProc::TShaderBinary>(getExtension("glShaderBinary"));
  glShaderSource = reinterpret_cast<NOpenGLProc::TShaderSource>(getExtension("glShaderSource"));
  glStencilFuncSeparate = reinterpret_cast<NOpenGLProc::TStencilFuncSeparate>(getExtension("glStencilFuncSeparate"));
  glStencilMaskSeparate = reinterpret_cast<NOpenGLProc::TStencilMaskSeparate>(getExtension("glStencilMaskSeparate"));
  glStencilOpSeparate = reinterpret_cast<NOpenGLProc::TStencilOpSeparate>(getExtension("glStencilOpSeparate"));
  glUniform1f = reinterpret_cast<NOpenGLProc::TUniform1f>(getExtension("glUniform1f"));
  glUniform1fv = reinterpret_cast<NOpenGLProc::TUniform1fv>(getExtension("glUniform1fv"));
  glUniform1i = reinterpret_cast<NOpenGLProc::TUniform1i>(getExtension("glUniform1i"));
  glUniform1iv = reinterpret_cast<NOpenGLProc::TUniform1iv>(getExtension("glUniform1iv"));
  glUniform2f = reinterpret_cast<NOpenGLProc::TUniform2f>(getExtension("glUniform2f"));
  glUniform2fv = reinterpret_cast<NOpenGLProc::TUniform2fv>(getExtension("glUniform2fv"));
  glUniform2i = reinterpret_cast<NOpenGLProc::TUniform2i>(getExtension("glUniform2i"));
  glUniform2iv = reinterpret_cast<NOpenGLProc::TUniform2iv>(getExtension("glUniform2iv"));
  glUniform3f = reinterpret_cast<NOpenGLProc::TUniform3f>(getExtension("glUniform3f"));
  glUniform3fv = reinterpret_cast<NOpenGLProc::TUniform3fv>(getExtension("glUniform3fv"));
  glUniform3i = reinterpret_cast<NOpenGLProc::TUniform3i>(getExtension("glUniform3i"));
  glUniform3iv = reinterpret_cast<NOpenGLProc::TUniform3iv>(getExtension("glUniform3iv"));
  glUniform4f = reinterpret_cast<NOpenGLProc::TUniform4f>(getExtension("glUniform4f"));
  glUniform4fv = reinterpret_cast<NOpenGLProc::TUniform4fv>(getExtension("glUniform4fv"));
  glUniform4i = reinterpret_cast<NOpenGLProc::TUniform4i>(getExtension("glUniform4i"));
  glUniform4iv = reinterpret_cast<NOpenGLProc::TUniform4iv>(getExtension("glUniform4iv"));
  glUniformMatrix2fv = reinterpret_cast<NOpenGLProc::TUniformMatrix2fv>(getExtension("glUniformMatrix2fv"));
  glUniformMatrix3fv = reinterpret_cast<NOpenGLProc::TUniformMatrix3fv>(getExtension("glUniformMatrix3fv"));
  glUniformMatrix4fv = reinterpret_cast<NOpenGLProc::TUniformMatrix4fv>(getExtension("glUniformMatrix4fv"));
  glUseProgram = reinterpret_cast<NOpenGLProc::TUseProgram>(getExtension("glUseProgram"));
  glValidateProgram = reinterpret_cast<NOpenGLProc::TValidateProgram>(getExtension("glValidateProgram"));
  glVertexAttrib1f = reinterpret_cast<NOpenGLProc::TVertexAttrib1f>(getExtension("glVertexAttrib1f"));
  glVertexAttrib1fv = reinterpret_cast<NOpenGLProc::TVertexAttrib1fv>(getExtension("glVertexAttrib1fv"));
  glVertexAttrib2f = reinterpret_cast<NOpenGLProc::TVertexAttrib2f>(getExtension("glVertexAttrib2f"));
  glVertexAttrib2fv = reinterpret_cast<NOpenGLProc::TVertexAttrib2fv>(getExtension("glVertexAttrib2fv"));
  glVertexAttrib3f = reinterpret_cast<NOpenGLProc::TVertexAttrib3f>(getExtension("glVertexAttrib3f"));
  glVertexAttrib3fv = reinterpret_cast<NOpenGLProc::TVertexAttrib3fv>(getExtension("glVertexAttrib3fv"));
  glVertexAttrib4f = reinterpret_cast<NOpenGLProc::TVertexAttrib4f>(getExtension("glVertexAttrib4f"));
  glVertexAttrib4fv = reinterpret_cast<NOpenGLProc::TVertexAttrib4fv>(getExtension("glVertexAttrib4fv"));
  glVertexAttribPointer = reinterpret_cast<NOpenGLProc::TVertexAttribPointer>(getExtension("glVertexAttribPointer"));
#endif
}
//------------------------------------------------------------------------------
inline COpenGL::~COpenGL()
{
}
//------------------------------------------------------------------------------
/*class COpenGL : public CEngineBase, public QGLFunctions
{
  private:
    //

  public:
    inline COpenGL() : CEngineBase() {}
    inline COpenGL(CContext *context, QGLContext *glContext) : CEngineBase(context), QGLFunctions(glContext) { if(glContext) initializeGLFunctions(); }
    inline ~COpenGL() {}
};*/
//------------------------------------------------------------------------------
#endif // OPENGL_H
