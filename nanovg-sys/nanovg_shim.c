#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/gl3.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#include <GLUT/glut.h>
#elif defined(_WIN32)
#include <glad.h>
#elif defined(NANOVG_GLES3_IMPLEMENTATION)
// GLES 3 headers declare every function nanovg_gl.h calls.
#include <GLES3/gl3.h>
#elif defined(NANOVG_GLES2_IMPLEMENTATION)
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#else
// Desktop GL: <GL/gl.h> only declares GL 1.x. Prototypes for shaders, VAOs,
// UBOs etc. come from glext.h. Without them gcc >= 14 fails with
// "implicit declaration of function" errors.
#define GL_GLEXT_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glext.h>
#endif

#include <nanovg.h>
#include <nanovg_gl.h>
#include <nanovg_gl_utils.h>
