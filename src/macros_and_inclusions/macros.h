
#ifndef __AQUA__SDL2_SRC_MACROS_AND_INCLUSIONS_MACROS_H
	#define __AQUA__SDL2_SRC_MACROS_AND_INCLUSIONS_MACROS_H
	
	#ifndef SYSTEM_ACCESS
		#define SYSTEM_ACCESS 0
	#endif
	
	#ifndef KOS_TEXTURE_WARNING
		#define KOS_TEXTURE_WARNING 0
	#endif
	
	#ifndef SHARP_TEXTURES
		#define SHARP_TEXTURES 1
	#endif
	
	#if !defined(KOS_ORIGINAL_WIDTH) || !defined(KOS_ORIGINAL_HEIGHT)
		#define KOS_ORIGINAL_WIDTH 800
		#define KOS_ORIGINAL_HEIGHT 480
	#endif
	
	#ifndef KOS_ERROR
		#define KOS_ERROR { \
			kos_quit(this); \
			return 1; \
		}
	#endif
	
	#define MAX_PATH_LENGTH 4096
	
	#define GET_PATH(_path) \
		char path[MAX_PATH_LENGTH] = "root/"; \
		strncat(path, (char*) (_path), MAX_PATH_LENGTH - strlen(path)); \
	
	#ifndef KOS_TODO
		#define KOS_TODO printf("TODO `%s` in `%s` line %d\n", __func__, __FILE__, __LINE__);
	#endif
	
	#ifndef KOS_DEPRECATED
		#define KOS_DEPRECATED printf("WARNING function `%s` is deprecated\n", __func__);
	#endif
	
	#if !defined(KOS_LOWEST_GL_VERSION_MAJOR) || !defined(KOS_LOWEST_GL_VERSION_MINOR)
		#define KOS_LOWEST_GL_VERSION_MAJOR 2
		#define KOS_LOWEST_GL_VERSION_MINOR 1
	#endif
	
	#if !defined(KOS_HIGHEST_GL_VERSION_MAJOR) || !defined(KOS_HIGHEST_GL_VERSION_MINOR)
		#define KOS_HIGHEST_GL_VERSION_MAJOR 2
		#define KOS_HIGHEST_GL_VERSION_MINOR 1
	#endif
	
	#ifndef KOS_BEST_GL_VERSION
		#define KOS_BEST_GL_VERSION { \
			char major = glGetString(GL_VERSION)[0] - '0'; \
			char minor = glGetString(GL_VERSION)[2] - '0'; \
			\
			if (major < KOS_LOWEST_GL_VERSION_MAJOR || (major == KOS_LOWEST_GL_VERSION_MAJOR && minor < KOS_LOWEST_GL_VERSION_MINOR)) { \
				printf("ERROR You have an unsupported GL version (%d.%d, minimum %d.%d)\n", major, minor, KOS_LOWEST_GL_VERSION_MAJOR, KOS_LOWEST_GL_VERSION_MINOR); \
				kos_quit(this); \
				\
			} else { \
				kos_best_gl_version_major = KOS_HIGHEST_GL_VERSION_MAJOR; \
				kos_best_gl_version_minor = KOS_HIGHEST_GL_VERSION_MINOR; \
			} \
		}
	#endif
	
#endif
