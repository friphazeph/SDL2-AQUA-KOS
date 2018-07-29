
#ifndef __AQUA__SDL2_SRC_GL_COMMON_SHADERS_H
	#define __AQUA__SDL2_SRC_GL_COMMON_SHADERS_H
	
	#include "../gl_versions/shaders/gl_1.h"
	#include "../gl_versions/shaders/gl_2.h"
	#include "../gl_versions/shaders/gl_3.h"
	#include "../gl_versions/shaders/gl_4.h"
	
	int gl_load_shaders(GLuint* program, char* vertex_code, char* fragment_code) {
		switch (kos_best_gl_version_major) {
			case 1: return 1;
			case 2: return gl2_load_shaders(program, vertex_code, fragment_code);
			case 3: return 1;
			case 4: return 1;
			case 5: return 1;
			
			default: {
				KOS_WARN_NO_GL_VERSION
				return 1;
				
			}
			
		}
		
	}
	
#endif