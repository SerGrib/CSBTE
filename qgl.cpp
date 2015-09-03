#include <metahook.h>
#include <gl/gl.h>
#include <triangleapi.h>
#include "LoadTGA.h"
#include "qgl.h"
#include "plugins.h"

#ifdef _DEBUG
#pragma comment(lib, "opengl32.lib")
#endif

extern "C"
{
	void (APIENTRY *qglAccum)(GLenum op, GLfloat value) = NULL;
	void (APIENTRY *qglAlphaFunc)(GLenum func, GLclampf ref) = NULL;
	GLboolean (APIENTRY *qglAreTexturesResident)(GLsizei n, const GLuint *textures, GLboolean *residences) = NULL;
	void (APIENTRY *qglArrayElement)(GLint i) = NULL;
	void (APIENTRY *qglBegin)(GLenum mode) = NULL;
	void (APIENTRY *qglBindTexture)(GLenum target, GLuint texture) = NULL;
	void (APIENTRY *qglBitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) = NULL;
	void (APIENTRY *qglBlendFunc)(GLenum sfactor, GLenum dfactor) = NULL;
	void (APIENTRY *qglCallList)(GLuint list) = NULL;
	void (APIENTRY *qglCallLists)(GLsizei n, GLenum type, const GLvoid *lists) = NULL;
	void (APIENTRY *qglClear)(GLbitfield mask) = NULL;
	void (APIENTRY *qglClearAccum)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = NULL;
	void (APIENTRY *qglClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) = NULL;
	void (APIENTRY *qglClearDepth)(GLclampd depth) = NULL;
	void (APIENTRY *qglClearIndex)(GLfloat c) = NULL;
	void (APIENTRY *qglClearStencil)(GLint s) = NULL;
	void (APIENTRY *qglClipPlane)(GLenum plane, const GLdouble *equation) = NULL;
	void (APIENTRY *qglColor3b)(GLbyte red, GLbyte green, GLbyte blue) = NULL;
	void (APIENTRY *qglColor3bv)(const GLbyte *v) = NULL;
	void (APIENTRY *qglColor3d)(GLdouble red, GLdouble green, GLdouble blue) = NULL;
	void (APIENTRY *qglColor3dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglColor3f)(GLfloat red, GLfloat green, GLfloat blue) = NULL;
	void (APIENTRY *qglColor3fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglColor3i)(GLint red, GLint green, GLint blue) = NULL;
	void (APIENTRY *qglColor3iv)(const GLint *v) = NULL;
	void (APIENTRY *qglColor3s)(GLshort red, GLshort green, GLshort blue) = NULL;
	void (APIENTRY *qglColor3sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglColor3ub)(GLubyte red, GLubyte green, GLubyte blue) = NULL;
	void (APIENTRY *qglColor3ubv)(const GLubyte *v) = NULL;
	void (APIENTRY *qglColor3ui)(GLuint red, GLuint green, GLuint blue) = NULL;
	void (APIENTRY *qglColor3uiv)(const GLuint *v) = NULL;
	void (APIENTRY *qglColor3us)(GLushort red, GLushort green, GLushort blue) = NULL;
	void (APIENTRY *qglColor3usv)(const GLushort *v) = NULL;
	void (APIENTRY *qglColor4b)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) = NULL;
	void (APIENTRY *qglColor4bv)(const GLbyte *v) = NULL;
	void (APIENTRY *qglColor4d)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) = NULL;
	void (APIENTRY *qglColor4dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglColor4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = NULL;
	void (APIENTRY *qglColor4fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglColor4i)(GLint red, GLint green, GLint blue, GLint alpha) = NULL;
	void (APIENTRY *qglColor4iv)(const GLint *v) = NULL;
	void (APIENTRY *qglColor4s)(GLshort red, GLshort green, GLshort blue, GLshort alpha) = NULL;
	void (APIENTRY *qglColor4sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglColor4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) = NULL;
	void (APIENTRY *qglColor4ubv)(const GLubyte *v) = NULL;
	void (APIENTRY *qglColor4ui)(GLuint red, GLuint green, GLuint blue, GLuint alpha) = NULL;
	void (APIENTRY *qglColor4uiv)(const GLuint *v) = NULL;
	void (APIENTRY *qglColor4us)(GLushort red, GLushort green, GLushort blue, GLushort alpha) = NULL;
	void (APIENTRY *qglColor4usv)(const GLushort *v) = NULL;
	void (APIENTRY *qglColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) = NULL;
	void (APIENTRY *qglColorMaterial)(GLenum face, GLenum mode) = NULL;
	void (APIENTRY *qglColorPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) = NULL;
	void (APIENTRY *qglCopyPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) = NULL;
	void (APIENTRY *qglCopyTexImage1D)(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border) = NULL;
	void (APIENTRY *qglCopyTexImage2D)(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) = NULL;
	void (APIENTRY *qglCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) = NULL;
	void (APIENTRY *qglCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
	void (APIENTRY *qglCullFace)(GLenum mode) = NULL;
	void (APIENTRY *qglDeleteLists)(GLuint list, GLsizei range) = NULL;
	void (APIENTRY *qglDeleteTextures)(GLsizei n, const GLuint *textures) = NULL;
	void (APIENTRY *qglDepthFunc)(GLenum func) = NULL;
	void (APIENTRY *qglDepthMask)(GLboolean flag) = NULL;
	void (APIENTRY *qglDepthRange)(GLclampd zNear, GLclampd zFar) = NULL;
	void (APIENTRY *qglDisable)(GLenum cap) = NULL;
	void (APIENTRY *qglDisableClientState)(GLenum array) = NULL;
	void (APIENTRY *qglDrawArrays)(GLenum mode, GLint first, GLsizei count) = NULL;
	void (APIENTRY *qglDrawBuffer)(GLenum mode) = NULL;
	void (APIENTRY *qglDrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) = NULL;
	void (APIENTRY *qglDrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) = NULL;
	void (APIENTRY *qglEdgeFlag)(GLboolean flag) = NULL;
	void (APIENTRY *qglEdgeFlagPointer)(GLsizei stride, const GLvoid *pointer) = NULL;
	void (APIENTRY *qglEdgeFlagv)(const GLboolean *flag) = NULL;
	void (APIENTRY *qglEnable)(GLenum cap) = NULL;
	void (APIENTRY *qglEnableClientState)(GLenum array) = NULL;
	void (APIENTRY *qglEnd)(void) = NULL;
	void (APIENTRY *qglEndList)(void) = NULL;
	void (APIENTRY *qglEvalCoord1d)(GLdouble u) = NULL;
	void (APIENTRY *qglEvalCoord1dv)(const GLdouble *u) = NULL;
	void (APIENTRY *qglEvalCoord1f)(GLfloat u) = NULL;
	void (APIENTRY *qglEvalCoord1fv)(const GLfloat *u) = NULL;
	void (APIENTRY *qglEvalCoord2d)(GLdouble u, GLdouble v) = NULL;
	void (APIENTRY *qglEvalCoord2dv)(const GLdouble *u) = NULL;
	void (APIENTRY *qglEvalCoord2f)(GLfloat u, GLfloat v) = NULL;
	void (APIENTRY *qglEvalCoord2fv)(const GLfloat *u) = NULL;
	void (APIENTRY *qglEvalMesh1)(GLenum mode, GLint i1, GLint i2) = NULL;
	void (APIENTRY *qglEvalMesh2)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) = NULL;
	void (APIENTRY *qglEvalPoint1)(GLint i) = NULL;
	void (APIENTRY *qglEvalPoint2)(GLint i, GLint j) = NULL;
	void (APIENTRY *qglFeedbackBuffer)(GLsizei size, GLenum type, GLfloat *buffer) = NULL;
	void (APIENTRY *qglFinish)(void) = NULL;
	void (APIENTRY *qglFlush)(void) = NULL;
	void (APIENTRY *qglFogf)(GLenum pname, GLfloat param) = NULL;
	void (APIENTRY *qglFogfv)(GLenum pname, const GLfloat *params) = NULL;
	void (APIENTRY *qglFogi)(GLenum pname, GLint param) = NULL;
	void (APIENTRY *qglFogiv)(GLenum pname, const GLint *params) = NULL;
	void (APIENTRY *qglFrontFace)(GLenum mode) = NULL;
	void (APIENTRY *qglFrustum)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) = NULL;
	GLuint (APIENTRY *qglGenLists)(GLsizei range) = NULL;
	void (APIENTRY *qglGenTextures)(GLsizei n, GLuint *textures) = NULL;
	void (APIENTRY *qglGetBooleanv)(GLenum pname, GLboolean *params) = NULL;
	void (APIENTRY *qglGetClipPlane)(GLenum plane, GLdouble *equation) = NULL;
	void (APIENTRY *qglGetDoublev)(GLenum pname, GLdouble *params) = NULL;
	GLenum (APIENTRY *qglGetError)(void) = NULL;
	void (APIENTRY *qglGetFloatv)(GLenum pname, GLfloat *params) = NULL;
	void (APIENTRY *qglGetIntegerv)(GLenum pname, GLint *params) = NULL;
	void (APIENTRY *qglGetLightfv)(GLenum light, GLenum pname, GLfloat *params) = NULL;
	void (APIENTRY *qglGetLightiv)(GLenum light, GLenum pname, GLint *params) = NULL;
	void (APIENTRY *qglGetMapdv)(GLenum target, GLenum query, GLdouble *v) = NULL;
	void (APIENTRY *qglGetMapfv)(GLenum target, GLenum query, GLfloat *v) = NULL;
	void (APIENTRY *qglGetMapiv)(GLenum target, GLenum query, GLint *v) = NULL;
	void (APIENTRY *qglGetMaterialfv)(GLenum face, GLenum pname, GLfloat *params) = NULL;
	void (APIENTRY *qglGetMaterialiv)(GLenum face, GLenum pname, GLint *params) = NULL;
	void (APIENTRY *qglGetPixelMapfv)(GLenum map, GLfloat *values) = NULL;
	void (APIENTRY *qglGetPixelMapuiv)(GLenum map, GLuint *values) = NULL;
	void (APIENTRY *qglGetPixelMapusv)(GLenum map, GLushort *values) = NULL;
	void (APIENTRY *qglGetPointerv)(GLenum pname, GLvoid* *params) = NULL;
	void (APIENTRY *qglGetPolygonStipple)(GLubyte *mask) = NULL;
	const GLubyte * (APIENTRY *qglGetString)(GLenum name) = NULL;
	void (APIENTRY *qglGetTexEnvfv)(GLenum target, GLenum pname, GLfloat *params) = NULL;
	void (APIENTRY *qglGetTexEnviv)(GLenum target, GLenum pname, GLint *params) = NULL;
	void (APIENTRY *qglGetTexGendv)(GLenum coord, GLenum pname, GLdouble *params) = NULL;
	void (APIENTRY *qglGetTexGenfv)(GLenum coord, GLenum pname, GLfloat *params) = NULL;
	void (APIENTRY *qglGetTexGeniv)(GLenum coord, GLenum pname, GLint *params) = NULL;
	void (APIENTRY *qglGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) = NULL;
	void (APIENTRY *qglGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params) = NULL;
	void (APIENTRY *qglGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params) = NULL;
	void (APIENTRY *qglGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params) = NULL;
	void (APIENTRY *qglGetTexParameteriv)(GLenum target, GLenum pname, GLint *params) = NULL;
	void (APIENTRY *qglHint)(GLenum target, GLenum mode) = NULL;
	void (APIENTRY *qglIndexMask)(GLuint mask) = NULL;
	void (APIENTRY *qglIndexPointer)(GLenum type, GLsizei stride, const GLvoid *pointer) = NULL;
	void (APIENTRY *qglIndexd)(GLdouble c) = NULL;
	void (APIENTRY *qglIndexdv)(const GLdouble *c) = NULL;
	void (APIENTRY *qglIndexf)(GLfloat c) = NULL;
	void (APIENTRY *qglIndexfv)(const GLfloat *c) = NULL;
	void (APIENTRY *qglIndexi)(GLint c) = NULL;
	void (APIENTRY *qglIndexiv)(const GLint *c) = NULL;
	void (APIENTRY *qglIndexs)(GLshort c) = NULL;
	void (APIENTRY *qglIndexsv)(const GLshort *c) = NULL;
	void (APIENTRY *qglIndexub)(GLubyte c) = NULL;
	void (APIENTRY *qglIndexubv)(const GLubyte *c) = NULL;
	void (APIENTRY *qglInitNames)(void) = NULL;
	void (APIENTRY *qglInterleavedArrays)(GLenum format, GLsizei stride, const GLvoid *pointer) = NULL;
	GLboolean (APIENTRY *qglIsEnabled)(GLenum cap) = NULL;
	GLboolean (APIENTRY *qglIsList)(GLuint list) = NULL;
	GLboolean (APIENTRY *qglIsTexture)(GLuint texture) = NULL;
	void (APIENTRY *qglLightModelf)(GLenum pname, GLfloat param) = NULL;
	void (APIENTRY *qglLightModelfv)(GLenum pname, const GLfloat *params) = NULL;
	void (APIENTRY *qglLightModeli)(GLenum pname, GLint param) = NULL;
	void (APIENTRY *qglLightModeliv)(GLenum pname, const GLint *params) = NULL;
	void (APIENTRY *qglLightf)(GLenum light, GLenum pname, GLfloat param) = NULL;
	void (APIENTRY *qglLightfv)(GLenum light, GLenum pname, const GLfloat *params) = NULL;
	void (APIENTRY *qglLighti)(GLenum light, GLenum pname, GLint param) = NULL;
	void (APIENTRY *qglLightiv)(GLenum light, GLenum pname, const GLint *params) = NULL;
	void (APIENTRY *qglLineStipple)(GLint factor, GLushort pattern) = NULL;
	void (APIENTRY *qglLineWidth)(GLfloat width) = NULL;
	void (APIENTRY *qglListBase)(GLuint base) = NULL;
	void (APIENTRY *qglLoadIdentity)(void) = NULL;
	void (APIENTRY *qglLoadMatrixd)(const GLdouble *m) = NULL;
	void (APIENTRY *qglLoadMatrixf)(const GLfloat *m) = NULL;
	void (APIENTRY *qglLoadName)(GLuint name) = NULL;
	void (APIENTRY *qglLogicOp)(GLenum opcode) = NULL;
	void (APIENTRY *qglMap1d)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points) = NULL;
	void (APIENTRY *qglMap1f)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points) = NULL;
	void (APIENTRY *qglMap2d)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points) = NULL;
	void (APIENTRY *qglMap2f)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points) = NULL;
	void (APIENTRY *qglMapGrid1d)(GLint un, GLdouble u1, GLdouble u2) = NULL;
	void (APIENTRY *qglMapGrid1f)(GLint un, GLfloat u1, GLfloat u2) = NULL;
	void (APIENTRY *qglMapGrid2d)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) = NULL;
	void (APIENTRY *qglMapGrid2f)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) = NULL;
	void (APIENTRY *qglMaterialf)(GLenum face, GLenum pname, GLfloat param) = NULL;
	void (APIENTRY *qglMaterialfv)(GLenum face, GLenum pname, const GLfloat *params) = NULL;
	void (APIENTRY *qglMateriali)(GLenum face, GLenum pname, GLint param) = NULL;
	void (APIENTRY *qglMaterialiv)(GLenum face, GLenum pname, const GLint *params) = NULL;
	void (APIENTRY *qglMatrixMode)(GLenum mode) = NULL;
	void (APIENTRY *qglMultMatrixd)(const GLdouble *m) = NULL;
	void (APIENTRY *qglMultMatrixf)(const GLfloat *m) = NULL;
	void (APIENTRY *qglNewList)(GLuint list, GLenum mode) = NULL;
	void (APIENTRY *qglNormal3b)(GLbyte nx, GLbyte ny, GLbyte nz) = NULL;
	void (APIENTRY *qglNormal3bv)(const GLbyte *v) = NULL;
	void (APIENTRY *qglNormal3d)(GLdouble nx, GLdouble ny, GLdouble nz) = NULL;
	void (APIENTRY *qglNormal3dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglNormal3f)(GLfloat nx, GLfloat ny, GLfloat nz) = NULL;
	void (APIENTRY *qglNormal3fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglNormal3i)(GLint nx, GLint ny, GLint nz) = NULL;
	void (APIENTRY *qglNormal3iv)(const GLint *v) = NULL;
	void (APIENTRY *qglNormal3s)(GLshort nx, GLshort ny, GLshort nz) = NULL;
	void (APIENTRY *qglNormal3sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglNormalPointer)(GLenum type, GLsizei stride, const GLvoid *pointer) = NULL;
	void (APIENTRY *qglOrtho)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) = NULL;
	void (APIENTRY *qglPassThrough)(GLfloat token) = NULL;
	void (APIENTRY *qglPixelMapfv)(GLenum map, GLsizei mapsize, const GLfloat *values) = NULL;
	void (APIENTRY *qglPixelMapuiv)(GLenum map, GLsizei mapsize, const GLuint *values) = NULL;
	void (APIENTRY *qglPixelMapusv)(GLenum map, GLsizei mapsize, const GLushort *values) = NULL;
	void (APIENTRY *qglPixelStoref)(GLenum pname, GLfloat param) = NULL;
	void (APIENTRY *qglPixelStorei)(GLenum pname, GLint param) = NULL;
	void (APIENTRY *qglPixelTransferf)(GLenum pname, GLfloat param) = NULL;
	void (APIENTRY *qglPixelTransferi)(GLenum pname, GLint param) = NULL;
	void (APIENTRY *qglPixelZoom)(GLfloat xfactor, GLfloat yfactor) = NULL;
	void (APIENTRY *qglPointSize)(GLfloat size) = NULL;
	void (APIENTRY *qglPolygonMode)(GLenum face, GLenum mode) = NULL;
	void (APIENTRY *qglPolygonOffset)(GLfloat factor, GLfloat units) = NULL;
	void (APIENTRY *qglPolygonStipple)(const GLubyte *mask) = NULL;
	void (APIENTRY *qglPopAttrib)(void) = NULL;
	void (APIENTRY *qglPopClientAttrib)(void) = NULL;
	void (APIENTRY *qglPopMatrix)(void) = NULL;
	void (APIENTRY *qglPopName)(void) = NULL;
	void (APIENTRY *qglPrioritizeTextures)(GLsizei n, const GLuint *textures, const GLclampf *priorities) = NULL;
	void (APIENTRY *qglPushAttrib)(GLbitfield mask) = NULL;
	void (APIENTRY *qglPushClientAttrib)(GLbitfield mask) = NULL;
	void (APIENTRY *qglPushMatrix)(void) = NULL;
	void (APIENTRY *qglPushName)(GLuint name) = NULL;
	void (APIENTRY *qglRasterPos2d)(GLdouble x, GLdouble y) = NULL;
	void (APIENTRY *qglRasterPos2dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglRasterPos2f)(GLfloat x, GLfloat y) = NULL;
	void (APIENTRY *qglRasterPos2fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglRasterPos2i)(GLint x, GLint y) = NULL;
	void (APIENTRY *qglRasterPos2iv)(const GLint *v) = NULL;
	void (APIENTRY *qglRasterPos2s)(GLshort x, GLshort y) = NULL;
	void (APIENTRY *qglRasterPos2sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglRasterPos3d)(GLdouble x, GLdouble y, GLdouble z) = NULL;
	void (APIENTRY *qglRasterPos3dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglRasterPos3f)(GLfloat x, GLfloat y, GLfloat z) = NULL;
	void (APIENTRY *qglRasterPos3fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglRasterPos3i)(GLint x, GLint y, GLint z) = NULL;
	void (APIENTRY *qglRasterPos3iv)(const GLint *v) = NULL;
	void (APIENTRY *qglRasterPos3s)(GLshort x, GLshort y, GLshort z) = NULL;
	void (APIENTRY *qglRasterPos3sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglRasterPos4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
	void (APIENTRY *qglRasterPos4dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglRasterPos4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
	void (APIENTRY *qglRasterPos4fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglRasterPos4i)(GLint x, GLint y, GLint z, GLint w) = NULL;
	void (APIENTRY *qglRasterPos4iv)(const GLint *v) = NULL;
	void (APIENTRY *qglRasterPos4s)(GLshort x, GLshort y, GLshort z, GLshort w) = NULL;
	void (APIENTRY *qglRasterPos4sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglReadBuffer)(GLenum mode) = NULL;
	void (APIENTRY *qglReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels) = NULL;
	void (APIENTRY *qglRectd)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) = NULL;
	void (APIENTRY *qglRectdv)(const GLdouble *v1, const GLdouble *v2) = NULL;
	void (APIENTRY *qglRectf)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) = NULL;
	void (APIENTRY *qglRectfv)(const GLfloat *v1, const GLfloat *v2) = NULL;
	void (APIENTRY *qglRecti)(GLint x1, GLint y1, GLint x2, GLint y2) = NULL;
	void (APIENTRY *qglRectiv)(const GLint *v1, const GLint *v2) = NULL;
	void (APIENTRY *qglRects)(GLshort x1, GLshort y1, GLshort x2, GLshort y2) = NULL;
	void (APIENTRY *qglRectsv)(const GLshort *v1, const GLshort *v2) = NULL;
	GLint (APIENTRY *qglRenderMode)(GLenum mode) = NULL;
	void (APIENTRY *qglRotated)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) = NULL;
	void (APIENTRY *qglRotatef)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) = NULL;
	void (APIENTRY *qglScaled)(GLdouble x, GLdouble y, GLdouble z) = NULL;
	void (APIENTRY *qglScalef)(GLfloat x, GLfloat y, GLfloat z) = NULL;
	void (APIENTRY *qglScissor)(GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
	void (APIENTRY *qglSelectBuffer)(GLsizei size, GLuint *buffer) = NULL;
	void (APIENTRY *qglShadeModel)(GLenum mode) = NULL;
	void (APIENTRY *qglStencilFunc)(GLenum func, GLint ref, GLuint mask) = NULL;
	void (APIENTRY *qglStencilMask)(GLuint mask) = NULL;
	void (APIENTRY *qglStencilOp)(GLenum fail, GLenum zfail, GLenum zpass) = NULL;
	void (APIENTRY *qglTexCoord1d)(GLdouble s) = NULL;
	void (APIENTRY *qglTexCoord1dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglTexCoord1f)(GLfloat s) = NULL;
	void (APIENTRY *qglTexCoord1fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglTexCoord1i)(GLint s) = NULL;
	void (APIENTRY *qglTexCoord1iv)(const GLint *v) = NULL;
	void (APIENTRY *qglTexCoord1s)(GLshort s) = NULL;
	void (APIENTRY *qglTexCoord1sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglTexCoord2d)(GLdouble s, GLdouble t) = NULL;
	void (APIENTRY *qglTexCoord2dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglTexCoord2f)(GLfloat s, GLfloat t) = NULL;
	void (APIENTRY *qglTexCoord2fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglTexCoord2i)(GLint s, GLint t) = NULL;
	void (APIENTRY *qglTexCoord2iv)(const GLint *v) = NULL;
	void (APIENTRY *qglTexCoord2s)(GLshort s, GLshort t) = NULL;
	void (APIENTRY *qglTexCoord2sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglTexCoord3d)(GLdouble s, GLdouble t, GLdouble r) = NULL;
	void (APIENTRY *qglTexCoord3dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglTexCoord3f)(GLfloat s, GLfloat t, GLfloat r) = NULL;
	void (APIENTRY *qglTexCoord3fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglTexCoord3i)(GLint s, GLint t, GLint r) = NULL;
	void (APIENTRY *qglTexCoord3iv)(const GLint *v) = NULL;
	void (APIENTRY *qglTexCoord3s)(GLshort s, GLshort t, GLshort r) = NULL;
	void (APIENTRY *qglTexCoord3sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglTexCoord4d)(GLdouble s, GLdouble t, GLdouble r, GLdouble q) = NULL;
	void (APIENTRY *qglTexCoord4dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglTexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q) = NULL;
	void (APIENTRY *qglTexCoord4fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglTexCoord4i)(GLint s, GLint t, GLint r, GLint q) = NULL;
	void (APIENTRY *qglTexCoord4iv)(const GLint *v) = NULL;
	void (APIENTRY *qglTexCoord4s)(GLshort s, GLshort t, GLshort r, GLshort q) = NULL;
	void (APIENTRY *qglTexCoord4sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglTexCoordPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) = NULL;
	void (APIENTRY *qglTexEnvf)(GLenum target, GLenum pname, GLfloat param) = NULL;
	void (APIENTRY *qglTexEnvfv)(GLenum target, GLenum pname, const GLfloat *params) = NULL;
	void (APIENTRY *qglTexEnvi)(GLenum target, GLenum pname, GLint param) = NULL;
	void (APIENTRY *qglTexEnviv)(GLenum target, GLenum pname, const GLint *params) = NULL;
	void (APIENTRY *qglTexGend)(GLenum coord, GLenum pname, GLdouble param) = NULL;
	void (APIENTRY *qglTexGendv)(GLenum coord, GLenum pname, const GLdouble *params) = NULL;
	void (APIENTRY *qglTexGenf)(GLenum coord, GLenum pname, GLfloat param) = NULL;
	void (APIENTRY *qglTexGenfv)(GLenum coord, GLenum pname, const GLfloat *params) = NULL;
	void (APIENTRY *qglTexGeni)(GLenum coord, GLenum pname, GLint param) = NULL;
	void (APIENTRY *qglTexGeniv)(GLenum coord, GLenum pname, const GLint *params) = NULL;
	void (APIENTRY *qglTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) = NULL;
	void (APIENTRY *qglTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) = NULL;
	void (APIENTRY *qglTexParameterf)(GLenum target, GLenum pname, GLfloat param) = NULL;
	void (APIENTRY *qglTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params) = NULL;
	void (APIENTRY *qglTexParameteri)(GLenum target, GLenum pname, GLint param) = NULL;
	void (APIENTRY *qglTexParameteriv)(GLenum target, GLenum pname, const GLint *params) = NULL;
	void (APIENTRY *qglTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) = NULL;
	void (APIENTRY *qglTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) = NULL;
	void (APIENTRY *qglTranslated)(GLdouble x, GLdouble y, GLdouble z) = NULL;
	void (APIENTRY *qglTranslatef)(GLfloat x, GLfloat y, GLfloat z) = NULL;
	void (APIENTRY *qglVertex2d)(GLdouble x, GLdouble y) = NULL;
	void (APIENTRY *qglVertex2dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglVertex2f)(GLfloat x, GLfloat y) = NULL;
	void (APIENTRY *qglVertex2fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglVertex2i)(GLint x, GLint y) = NULL;
	void (APIENTRY *qglVertex2iv)(const GLint *v) = NULL;
	void (APIENTRY *qglVertex2s)(GLshort x, GLshort y) = NULL;
	void (APIENTRY *qglVertex2sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglVertex3d)(GLdouble x, GLdouble y, GLdouble z) = NULL;
	void (APIENTRY *qglVertex3dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglVertex3f)(GLfloat x, GLfloat y, GLfloat z) = NULL;
	void (APIENTRY *qglVertex3fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglVertex3i)(GLint x, GLint y, GLint z) = NULL;
	void (APIENTRY *qglVertex3iv)(const GLint *v) = NULL;
	void (APIENTRY *qglVertex3s)(GLshort x, GLshort y, GLshort z) = NULL;
	void (APIENTRY *qglVertex3sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglVertex4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
	void (APIENTRY *qglVertex4dv)(const GLdouble *v) = NULL;
	void (APIENTRY *qglVertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
	void (APIENTRY *qglVertex4fv)(const GLfloat *v) = NULL;
	void (APIENTRY *qglVertex4i)(GLint x, GLint y, GLint z, GLint w) = NULL;
	void (APIENTRY *qglVertex4iv)(const GLint *v) = NULL;
	void (APIENTRY *qglVertex4s)(GLshort x, GLshort y, GLshort z, GLshort w) = NULL;
	void (APIENTRY *qglVertex4sv)(const GLshort *v) = NULL;
	void (APIENTRY *qglVertexPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) = NULL;
	void (APIENTRY *qglViewport)(GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
}

void APIENTRY QGL_TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	if (target == 3553 && level == 0 && border == 0 && format == 6408 && type == 5121)
	{
		if (g_bLoadingTGA)
		{
			width = g_iLastTGAWidth;
			height = g_iLastTGAHeight;
			pixels = g_bTGABuffer;
		}

		g_bLoadingTGA = FALSE;
	}

	qglTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

void QGL_Init(void)
{
	bool initialized = false;

	if (g_iVideoMode == VIDEOMODE_OPENGL)
	{
		HMODULE hOpenGL = GetModuleHandle("opengl32.dll");

		if (hOpenGL)
		{
			qglAccum = (void (APIENTRY *)(GLenum, GLfloat))GetProcAddress(hOpenGL, "glAccum");
			qglAlphaFunc = (void (APIENTRY *)(GLenum, GLclampf))GetProcAddress(hOpenGL, "glAlphaFunc");
			qglAreTexturesResident = (GLboolean (APIENTRY *)(GLsizei, const GLuint *, GLboolean *))GetProcAddress(hOpenGL, "glAreTexturesResident");
			qglBlendFunc = (void (APIENTRY *)(GLenum, GLenum))GetProcAddress(hOpenGL, "glBlendFunc");
			qglTexImage2D = (void (APIENTRY *)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))GetProcAddress(hOpenGL, "glTexImage2D");
			qglGenTextures = (void (APIENTRY *)(GLsizei, GLuint *))GetProcAddress(hOpenGL, "glGenTextures");
			qglBindTexture = (void (APIENTRY *)(GLenum, GLuint))GetProcAddress(hOpenGL, "glBindTexture");
			qglTexParameteri = (void (APIENTRY *) (GLenum, GLenum, GLint))GetProcAddress(hOpenGL, "glTexParameteri");
			qglTexImage2D = (void (APIENTRY *)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))GetProcAddress(hOpenGL, "glTexImage2D");
			qglIsTexture = (GLboolean (APIENTRY *)(GLuint))GetProcAddress(hOpenGL, "glIsTexture");
			qglGetIntegerv = (void (APIENTRY *)(GLenum, GLint *))GetProcAddress(hOpenGL, "glGetIntegerv");
			qglDrawElements = (void (APIENTRY *)(GLenum, GLsizei, GLenum, const GLvoid *))GetProcAddress(hOpenGL, "glDrawElements");
			qglDrawArrays = (void (APIENTRY *)(GLenum, GLint, GLsizei))GetProcAddress(hOpenGL, "glDrawArrays");
			qglEnable = (void (APIENTRY *) (GLenum))GetProcAddress(hOpenGL, "glEnable");
			qglDisable = (void (APIENTRY *) (GLenum))GetProcAddress(hOpenGL, "glDisable");
			qglPushAttrib = (void (APIENTRY *)(GLbitfield))GetProcAddress(hOpenGL, "glPushAttrib");
			qglPopAttrib = (void (APIENTRY *)(void))GetProcAddress(hOpenGL, "glPopAttrib");
			qglDeleteTextures = (void (APIENTRY *)(GLsizei, const GLuint *))GetProcAddress(hOpenGL, "glDeleteTextures");
			qglTexSubImage2D = (void (APIENTRY *)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))GetProcAddress(hOpenGL, "glTexSubImage2D");
			qglVertex2f = (void (APIENTRY *)(GLfloat, GLfloat))GetProcAddress(hOpenGL, "glVertex2f");
			qglEnd = (void (APIENTRY *)(void))GetProcAddress(hOpenGL, "glEnd");
			qglTexEnvf = (void (APIENTRY *)(GLenum, GLenum, GLfloat))GetProcAddress(hOpenGL, "glTexEnvf");
			qglColor4f = (void (APIENTRY *)(GLfloat, GLfloat, GLfloat, GLfloat))GetProcAddress(hOpenGL, "glColor4f");
			qglColor3f = (void (APIENTRY *)(GLfloat, GLfloat, GLfloat))GetProcAddress(hOpenGL, "glColor3f");
			qglScissor = (void (APIENTRY *)(GLint, GLint, GLsizei, GLsizei))GetProcAddress(hOpenGL, "glScissor");
			qglColor4ub = (void (APIENTRY *)(GLubyte, GLubyte, GLubyte, GLubyte))GetProcAddress(hOpenGL, "glColor4ub");
			qglBegin = (void (APIENTRY *)(GLenum))GetProcAddress(hOpenGL, "glBegin");
			qglTexCoord2f = (void (APIENTRY *)(GLfloat, GLfloat))GetProcAddress(hOpenGL, "glTexCoord2f");
			qglColorMask = (void (APIENTRY *)(GLboolean, GLboolean, GLboolean, GLboolean))GetProcAddress(hOpenGL, "glColorMask");
			qglGetTexImage = (void (APIENTRY *)(GLenum, GLint, GLenum, GLenum, GLvoid *))GetProcAddress(hOpenGL, "glGetTexImage");
			qglStencilFunc = (void (APIENTRY *)(GLenum, GLint, GLuint))GetProcAddress(hOpenGL, "glStencilFunc");
			qglStencilOp = (void (APIENTRY *)(GLenum, GLenum, GLenum))GetProcAddress(hOpenGL, "glStencilOp");
			qglClear = (void (APIENTRY *)(GLbitfield))GetProcAddress(hOpenGL, "glClear");
			qglStencilMask = (void (APIENTRY *)(GLuint))GetProcAddress(hOpenGL, "glStencilMask");
			qglVertex3f = (void (APIENTRY *)(GLfloat, GLfloat, GLfloat))GetProcAddress(hOpenGL, "glVertex3f");
			qglTexCoord2fv = (void (APIENTRY *)(const GLfloat *))GetProcAddress(hOpenGL, "glTexCoord2fv");
			qglTexParameterf = (void (APIENTRY *)(GLenum, GLenum, GLfloat))GetProcAddress(hOpenGL, "glTexParameterf");
			qglPixelStorei = (void (APIENTRY *)(GLenum, GLint))GetProcAddress(hOpenGL, "glPixelStorei");

			initialized = true;
		}
	}

	if (!initialized)
	{
		DWORD base = *(DWORD *)((DWORD)gEngfuncs.pTriAPI->RenderMode + 0x47);

		qglAccum = (void (APIENTRY *)(GLenum, GLfloat))(*(DWORD *)(base - 0xB4));
		qglAlphaFunc = (void (APIENTRY *)(GLenum, GLclampf))(*(DWORD *)(base - 0x374));
		qglAreTexturesResident = (GLboolean (APIENTRY *)(GLsizei, const GLuint *, GLboolean *))(*(DWORD *)(base - 0x3A8));
		qglBlendFunc = (void (APIENTRY *)(GLenum, GLenum))(*(DWORD *)base);
		qglTexImage2D = (void (APIENTRY *)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))(*(DWORD *)(base - 0x24C));
		qglGenTextures = (void (APIENTRY *)(GLsizei, GLuint *))(*(DWORD *)(base - 0x6C));
		qglBindTexture = (void (APIENTRY *)(GLenum, GLuint))(*(DWORD *)(base - 0x224));
		qglTexParameteri = (void (APIENTRY *) (GLenum, GLenum, GLint))(*(DWORD *)(base - 0x524));
		qglTexImage2D = (void (APIENTRY *)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))(*(DWORD *)(base + 0x1EC));
		qglIsTexture = (GLboolean (APIENTRY *)(GLuint))(*(DWORD *)(base + 0x250));
		qglGetIntegerv = (void (APIENTRY *)(GLenum, GLint *))(*(DWORD *)(base + 0x3C0));
		qglDrawElements = (void (APIENTRY *)(GLenum, GLsizei, GLenum, const GLvoid *))(*(DWORD *)(base - 0x4C0));
		qglDrawArrays = (void (APIENTRY *)(GLenum, GLint, GLsizei))(*(DWORD *)(base + 0X270));
		qglEnable = (void (APIENTRY *) (GLenum))(*(DWORD *)(base - 0x4BC));
		qglDisable = (void (APIENTRY *) (GLenum))(*(DWORD *)(base + 0x380));
		qglPushAttrib = (void (APIENTRY *)(GLbitfield))(*(DWORD *)(base - 0x1C));
		qglPopAttrib = (void (APIENTRY *)(void))(*(DWORD *)(base + 0xF8));
		qglDeleteTextures = (void (APIENTRY *)(GLsizei, const GLuint *))(*(DWORD *)(base + 0x110));
		qglTexSubImage2D = (void (APIENTRY *)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))(*(DWORD *)(base + 0x44));
		qglVertex2f = (void (APIENTRY *)(GLfloat, GLfloat))(*(DWORD *)(base + 0x36C));
		qglEnd = (void (APIENTRY *)(void))(*(DWORD *)(base - 0x428));
		qglTexEnvf = (void (APIENTRY *)(GLenum, GLenum, GLfloat))(*(DWORD *)(base - 0x564));
		qglColor4f = (void (APIENTRY *)(GLfloat, GLfloat, GLfloat, GLfloat))(*(DWORD *)(base - 0x468));
		qglColor3f = (void (APIENTRY *)(GLfloat, GLfloat, GLfloat))(*(DWORD *)(base - 0x48C));
		qglScissor = (void (APIENTRY *)(GLint, GLint, GLsizei, GLsizei))(*(DWORD *)(base + 0x294));
		qglColor4ub = (void (APIENTRY *)(GLubyte, GLubyte, GLubyte, GLubyte))(*(DWORD *)(base + 0x1E8));
		qglColorMask = (void (APIENTRY *)(GLboolean, GLboolean, GLboolean, GLboolean))(*(DWORD *)(base + 0x194));
		qglStencilFunc = (void (APIENTRY *)(GLenum, GLint, GLuint))(*(DWORD *)(base - 0x2B4));
		qglStencilOp = (void (APIENTRY *)(GLenum, GLenum, GLenum))(*(DWORD *)(base - 0x268));
		qglGetTexImage = (void (APIENTRY *)(GLenum, GLint, GLenum, GLenum, GLvoid *))(*(DWORD *)(base + 0x3D4));
		qglVertex3f = (void (APIENTRY *)(GLfloat, GLfloat, GLfloat))(*(DWORD *)(base + 0x30C));
		qglTexCoord2fv = (void (APIENTRY *)(const GLfloat *))(*(DWORD *)(base - 0xE4));
		qglTexParameterf = (void (APIENTRY *)(GLenum, GLenum, GLfloat))(*(DWORD *)(base - 0xA0));
		qglPixelStorei = (void (APIENTRY *)(GLenum, GLint))(*(DWORD *)(base - 0x394));

		if (g_dwEngineBuildnum < 4554)
		{
			qglBegin = (void (APIENTRY *)(GLenum))(*(DWORD *)(base + 0x410));
			qglTexCoord2f = (void (APIENTRY *)(GLfloat, GLfloat))(*(DWORD *)(base + 0x46C));
		}
		else
		{
			qglBegin = (void (APIENTRY *)(GLenum))(*(DWORD *)(base + 0x414));
			qglTexCoord2f = (void (APIENTRY *)(GLfloat, GLfloat))(*(DWORD *)(base + 0x474));
		}
	}

	g_pMetaHookAPI->InlineHook(qglTexImage2D, QGL_TexImage2D, (void *&)qglTexImage2D);
}