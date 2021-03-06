#ifndef __H_OPENGL__
#define __H_OPENGL__

#ifdef _WIN32
	#define NOMINMAX
    #define FREEGLUT_STATIC
    #define GLEW_STATIC
    #include <windows.h>
    #include <GL/glew.h>
    #include <GL/wglew.h>
    #include <GL/GLU.h>
    //#include <GL/glext.h>
	#pragma warning(disable: 4505)
#else
    //#define GL_GLEXT_PROTOTYPES
    #include <GL/glew.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>
    #include <GL/glext.h>
#endif

/*
void BindGLFunctions()
{
#define REGISTER_GL_FUNC(func, type)	(func = (type)wglGetProcAddress(#func))
	// Example:
	// glGenFramebuffersEXT			= (PFNGLGENFRAMEBUFFERSEXTPROC)			wglGetProcAddress("glGenFramebuffersEXT");
	// becomes
	// REGISTER_GL_FUNC(glGenFramebuffersEXT, PFNGLGENFRAMEBUFFERSEXTPROC);

	REGISTER_GL_FUNC( glGenFramebuffersEXT, PFNGLGENFRAMEBUFFERSEXTPROC );
	REGISTER_GL_FUNC( glGenFramebuffers, PFNGLGENFRAMEBUFFERSPROC );
	REGISTER_GL_FUNC( glGenRenderbuffersEXT, PFNGLGENRENDERBUFFERSEXTPROC );
	REGISTER_GL_FUNC( glGenRenderbuffers, PFNGLGENRENDERBUFFERSPROC );
	REGISTER_GL_FUNC( glBindFramebufferEXT, PFNGLBINDFRAMEBUFFEREXTPROC );
	REGISTER_GL_FUNC( glBindFramebuffer, PFNGLBINDFRAMEBUFFERPROC );
	REGISTER_GL_FUNC( glBindRenderbufferEXT, PFNGLBINDRENDERBUFFEREXTPROC );
	REGISTER_GL_FUNC( glBindRenderbuffer, PFNGLBINDRENDERBUFFERPROC );
	REGISTER_GL_FUNC( glRenderbufferStorageEXT, PFNGLRENDERBUFFERSTORAGEEXTPROC );
	REGISTER_GL_FUNC( glRenderbufferStorage, PFNGLRENDERBUFFERSTORAGEPROC );
	REGISTER_GL_FUNC( glFramebufferRenderbufferEXT, PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC );
	REGISTER_GL_FUNC( glFramebufferRenderbuffer, PFNGLFRAMEBUFFERRENDERBUFFERPROC );
	REGISTER_GL_FUNC( glFramebufferTexture2DEXT, PFNGLFRAMEBUFFERTEXTURE2DEXTPROC );
	REGISTER_GL_FUNC( glFramebufferTexture2D, PFNGLFRAMEBUFFERTEXTURE2DPROC );
	REGISTER_GL_FUNC( glCheckFramebufferStatusEXT, PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC );
	REGISTER_GL_FUNC( glCheckFramebufferStatus, PFNGLCHECKFRAMEBUFFERSTATUSPROC );
	REGISTER_GL_FUNC( glDeleteFramebuffersEXT, PFNGLDELETEFRAMEBUFFERSEXTPROC );
	REGISTER_GL_FUNC( glDeleteFramebuffers, PFNGLDELETEFRAMEBUFFERSPROC );
	REGISTER_GL_FUNC( glDeleteRenderbuffersEXT, PFNGLDELETERENDERBUFFERSEXTPROC );
	REGISTER_GL_FUNC( glDeleteRenderbuffers, PFNGLDELETERENDERBUFFERSPROC );
	REGISTER_GL_FUNC( glActiveTextureARB, PFNGLACTIVETEXTUREARBPROC );
	REGISTER_GL_FUNC( glDrawBuffers, PFNGLDRAWBUFFERSPROC );
	REGISTER_GL_FUNC( glUseProgramObjectARB, PFNGLUSEPROGRAMOBJECTARBPROC );
	REGISTER_GL_FUNC( glActiveTextureARB, PFNGLACTIVETEXTUREARBPROC );
	REGISTER_GL_FUNC( glActiveTexture, PFNGLACTIVETEXTUREPROC );
	REGISTER_GL_FUNC( glUniform1iARB, PFNGLUNIFORM1IARBPROC );
	REGISTER_GL_FUNC( glUniform1fARB, PFNGLUNIFORM1FARBPROC );
	REGISTER_GL_FUNC( glUniform2iARB, PFNGLUNIFORM2IARBPROC );
	REGISTER_GL_FUNC( glUniform2fARB, PFNGLUNIFORM2FARBPROC );
	REGISTER_GL_FUNC( glUniform3iARB, PFNGLUNIFORM3IARBPROC );
	REGISTER_GL_FUNC( glUniform3fARB, PFNGLUNIFORM3FARBPROC );
	REGISTER_GL_FUNC( glUniform4iARB, PFNGLUNIFORM4IARBPROC );
	REGISTER_GL_FUNC( glUniform4fARB, PFNGLUNIFORM4FARBPROC );
	REGISTER_GL_FUNC( glCreateShaderObjectARB, PFNGLCREATESHADEROBJECTARBPROC );
	REGISTER_GL_FUNC( glShaderSourceARB, PFNGLSHADERSOURCEARBPROC );
	REGISTER_GL_FUNC( glCompileShaderARB, PFNGLCOMPILESHADERARBPROC );
	REGISTER_GL_FUNC( glGetObjectParameterivARB, PFNGLGETOBJECTPARAMETERIVARBPROC );
	REGISTER_GL_FUNC( glCreateProgramObjectARB, PFNGLCREATEPROGRAMOBJECTARBPROC );
	REGISTER_GL_FUNC( glAttachObjectARB, PFNGLATTACHOBJECTARBPROC );
	REGISTER_GL_FUNC( glLinkProgramARB, PFNGLLINKPROGRAMARBPROC );
	REGISTER_GL_FUNC( glGetUniformLocationARB, PFNGLGETUNIFORMLOCATIONARBPROC );
	REGISTER_GL_FUNC( glGetShaderInfoLog, PFNGLGETSHADERINFOLOGPROC );
	REGISTER_GL_FUNC( glGetProgramInfoLog, PFNGLGETPROGRAMINFOLOGPROC );
	REGISTER_GL_FUNC( glGenerateMipmap, PFNGLGENERATEMIPMAPPROC );
	REGISTER_GL_FUNC( glGenBuffers, PFNGLGENBUFFERSPROC );
	REGISTER_GL_FUNC( glBindBuffer, PFNGLBINDBUFFERPROC );
	REGISTER_GL_FUNC( glBufferData, PFNGLBUFFERDATAARBPROC );
	REGISTER_GL_FUNC( glBufferSubData, PFNGLBUFFERSUBDATAPROC );
	REGISTER_GL_FUNC( glDeleteBuffers, PFNGLDELETEBUFFERSPROC );
	REGISTER_GL_FUNC( glClientActiveTexture, PFNGLCLIENTACTIVETEXTUREPROC );
	REGISTER_GL_FUNC( glVertexAttribPointer, PFNGLVERTEXATTRIBPOINTERPROC );
	REGISTER_GL_FUNC( glBindAttribLocation, PFNGLBINDATTRIBLOCATIONPROC );
	REGISTER_GL_FUNC( glEnableVertexAttribArray, PFNGLENABLEVERTEXATTRIBARRAYPROC );
	REGISTER_GL_FUNC( glGetAttribLocation, PFNGLGETATTRIBLOCATIONPROC );
	REGISTER_GL_FUNC( glVertexAttrib1f, PFNGLVERTEXATTRIB1FPROC );
	REGISTER_GL_FUNC( glVertexAttrib2f, PFNGLVERTEXATTRIB2FPROC );
	REGISTER_GL_FUNC( glVertexAttrib3f, PFNGLVERTEXATTRIB3FPROC );
	REGISTER_GL_FUNC( glVertexAttrib4f, PFNGLVERTEXATTRIB4FPROC );
	REGISTER_GL_FUNC( glVertexAttrib1d, PFNGLVERTEXATTRIB1DPROC );
	REGISTER_GL_FUNC( glVertexAttrib2d, PFNGLVERTEXATTRIB2DPROC );
	REGISTER_GL_FUNC( glVertexAttrib3d, PFNGLVERTEXATTRIB3DPROC );
	REGISTER_GL_FUNC( glVertexAttrib4d, PFNGLVERTEXATTRIB4DPROC );
	REGISTER_GL_FUNC( glVertexAttrib1s, PFNGLVERTEXATTRIB1SPROC );
	REGISTER_GL_FUNC( glVertexAttrib2s, PFNGLVERTEXATTRIB2SPROC );
	REGISTER_GL_FUNC( glVertexAttrib3s, PFNGLVERTEXATTRIB3SPROC );
	REGISTER_GL_FUNC( glVertexAttrib4s, PFNGLVERTEXATTRIB4SPROC );
	REGISTER_GL_FUNC( glVertexAttrib4Nub, PFNGLVERTEXATTRIB4NUBPROC );
	REGISTER_GL_FUNC( glVertexAttrib1fv, PFNGLVERTEXATTRIB1FVPROC );
	REGISTER_GL_FUNC( glVertexAttrib2fv, PFNGLVERTEXATTRIB2FVPROC );
	REGISTER_GL_FUNC( glVertexAttrib3fv, PFNGLVERTEXATTRIB3FVPROC );
	REGISTER_GL_FUNC( glVertexAttrib4fv, PFNGLVERTEXATTRIB4FVPROC );
	REGISTER_GL_FUNC( glVertexAttrib1dv, PFNGLVERTEXATTRIB1DVPROC );
	REGISTER_GL_FUNC( glVertexAttrib2dv, PFNGLVERTEXATTRIB2DVPROC );
	REGISTER_GL_FUNC( glVertexAttrib3dv, PFNGLVERTEXATTRIB3DVPROC );
	REGISTER_GL_FUNC( glVertexAttrib4dv, PFNGLVERTEXATTRIB4DVPROC );
	REGISTER_GL_FUNC( glVertexAttrib1sv, PFNGLVERTEXATTRIB1SVPROC );
	REGISTER_GL_FUNC( glVertexAttrib2sv, PFNGLVERTEXATTRIB2SVPROC );
	REGISTER_GL_FUNC( glVertexAttrib3sv, PFNGLVERTEXATTRIB3SVPROC );
	REGISTER_GL_FUNC( glVertexAttrib4sv, PFNGLVERTEXATTRIB4SVPROC );
	REGISTER_GL_FUNC( glUseProgram, PFNGLUSEPROGRAMPROC );
	REGISTER_GL_FUNC( glUniform1i, PFNGLUNIFORM1IPROC );
	REGISTER_GL_FUNC( glUniform1iv, PFNGLUNIFORM1IVPROC );
	REGISTER_GL_FUNC( glUniform2i, PFNGLUNIFORM2IPROC );
	REGISTER_GL_FUNC( glUniform2iv, PFNGLUNIFORM2IVPROC );
	REGISTER_GL_FUNC( glUniform3i, PFNGLUNIFORM3IPROC );
	REGISTER_GL_FUNC( glUniform3iv, PFNGLUNIFORM3IVPROC );
	REGISTER_GL_FUNC( glUniform4i, PFNGLUNIFORM4IPROC );
	REGISTER_GL_FUNC( glUniform4iv, PFNGLUNIFORM4IVPROC );
	REGISTER_GL_FUNC( glUniform1f, PFNGLUNIFORM1FPROC );
	REGISTER_GL_FUNC( glUniform1fv, PFNGLUNIFORM1FVPROC );
	REGISTER_GL_FUNC( glUniform2f, PFNGLUNIFORM2FPROC );
	REGISTER_GL_FUNC( glUniform2fv, PFNGLUNIFORM2FVPROC );
	REGISTER_GL_FUNC( glUniform3f, PFNGLUNIFORM3FPROC );
	REGISTER_GL_FUNC( glUniform3fv, PFNGLUNIFORM3FVPROC );
	REGISTER_GL_FUNC( glUniform4f, PFNGLUNIFORM4FPROC );
	REGISTER_GL_FUNC( glUniform4fv, PFNGLUNIFORM4FVPROC );
	REGISTER_GL_FUNC( glUniform1d, PFNGLUNIFORM1DPROC );
	REGISTER_GL_FUNC( glUniform1dv, PFNGLUNIFORM1DVPROC );
	REGISTER_GL_FUNC( glUniform2d, PFNGLUNIFORM2DPROC );
	REGISTER_GL_FUNC( glUniform2dv, PFNGLUNIFORM2DVPROC );
	REGISTER_GL_FUNC( glUniform3d, PFNGLUNIFORM3DPROC );
	REGISTER_GL_FUNC( glUniform3dv, PFNGLUNIFORM3DVPROC );
	REGISTER_GL_FUNC( glUniform4d, PFNGLUNIFORM4DPROC );
	REGISTER_GL_FUNC( glUniform4dv, PFNGLUNIFORM4DVPROC );
	REGISTER_GL_FUNC( glUniform1ui, PFNGLUNIFORM1UIPROC );
	REGISTER_GL_FUNC( glUniform1uiv, PFNGLUNIFORM1UIVPROC );
	REGISTER_GL_FUNC( glUniform2ui, PFNGLUNIFORM2UIPROC );
	REGISTER_GL_FUNC( glUniform2uiv, PFNGLUNIFORM2UIVPROC );
	REGISTER_GL_FUNC( glUniform3ui, PFNGLUNIFORM3UIPROC );
	REGISTER_GL_FUNC( glUniform3uiv, PFNGLUNIFORM3UIVPROC );
	REGISTER_GL_FUNC( glUniform4ui, PFNGLUNIFORM4UIPROC );
	REGISTER_GL_FUNC( glUniform4uiv, PFNGLUNIFORM4UIVPROC );
	REGISTER_GL_FUNC( glGetUniformLocation, PFNGLGETUNIFORMLOCATIONPROC );
	REGISTER_GL_FUNC( glUniformMatrix4fv, PFNGLUNIFORMMATRIX4FVPROC );
	REGISTER_GL_FUNC( glGetFramebufferAttachmentParameteriv, PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC );
	REGISTER_GL_FUNC( glMapBuffer, PFNGLMAPBUFFERPROC );
	REGISTER_GL_FUNC( glUnmapBuffer, PFNGLUNMAPBUFFERPROC );
	REGISTER_GL_FUNC( glGenVertexArrays, PFNGLGENVERTEXARRAYSPROC );
	REGISTER_GL_FUNC( glDeleteVertexArrays, PFNGLDELETEVERTEXARRAYSPROC );
	REGISTER_GL_FUNC( glBindVertexArray, PFNGLBINDVERTEXARRAYPROC );

#undef REGISTER_GL_FUNC
}
*/
#endif
