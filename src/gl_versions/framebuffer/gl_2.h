
#ifndef __AQUA__SDL2_SRC_KOS_GL_VERSIONS_FRAMEBUFFER_GL_2_H
	#define __AQUA__SDL2_SRC_KOS_GL_VERSIONS_FRAMEBUFFER_GL_2_H
	
	#include "../../macros_and_inclusions.h"
	#include "../../gl_common/texture.h"
	
	int glDeleteFramebuffers     ();
	int glCheckFramebufferStatus ();
	int glDrawBuffers            ();
	int glFramebufferTexture     ();
	int glFramebufferRenderbuffer();
	int glRenderbufferStorage    ();
	int glBindRenderbuffer       ();
	int glGenRenderbuffers       ();
	int glBindFramebuffer        ();
	int glGenFramebuffers        ();
	
	framebuffer_t gl2_framebuffer_create(texture_t texture) {
		GLint                                  old_framebuffer;
		glGetIntegerv(GL_FRAMEBUFFER_BINDING, &old_framebuffer);
		
		GLuint framebuffer_id = 0;
		glGenFramebuffers(1, &framebuffer_id);
		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer_id);
		glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, texture, 0);
		glBindFramebuffer   (GL_FRAMEBUFFER, old_framebuffer);
		
		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
			printf("WARNING Failed to create framebuffer\n");
			return 0;
			
		}
		
		return framebuffer_id;
		
	}
	
	void gl2_framebuffer_bind(framebuffer_t this, unsigned long long width, unsigned long long height) {
		glBindFramebuffer(GL_FRAMEBUFFER, this);
		glViewport(0, 0, width, height);
		
	}
	
	void gl2_framebuffer_remove(framebuffer_t this) {
		glDeleteFramebuffers(1, &this);
		
	}
	
#endif
