
#ifndef __AQUA__SDL2_SRC_FUNCTIONS_VIDEO_H
	#define __AQUA__SDL2_SRC_FUNCTIONS_VIDEO_H
	
	#include "../macros_and_inclusions.h"
	
	void video_clear(void) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
	}
	
	void video_clear_colour(unsigned long long r, unsigned long long g, unsigned long long b, unsigned long long a) {
		glClearColor((float) r / _UI64_MAX, (float) g / _UI64_MAX, (float) b / _UI64_MAX, (float) a / _UI64_MAX);
		
	}
	
	void video_draw(void) {
		printf("WARNING This function (`video_draw`) is deprecated\n");
		
	}
	
	void video_flip(void) {
		SDL_GL_SwapWindow(current_kos->window);
		
	}
	
	unsigned long long video_width(void) { return current_kos->width; }
	unsigned long long video_height(void) { return current_kos->height; }
	
	static unsigned long long kos_last_time;
	
	unsigned long long video_fps(void) {
		unsigned long long tick_time = SDL_GetTicks();
		float fps = 1000.0f / (float) (tick_time - kos_last_time);
		kos_last_time = tick_time;
		
		return (unsigned long long) fps;
		
	}
	
	void set_video_visibility(unsigned long long state) {
		if (state == HIDDEN) {
			SDL_MinimizeWindow(current_kos->window);
			
		}
		
	}
	
	static unsigned char kos_is_mouse_pressed = 0;
	
	void get_events(event_list_t* this) { // I guess this shouldn't be here but idc tbh
		SDL_Event event;
		
		this->quit = 0;
		this->pointer_click_type = kos_is_mouse_pressed;
		
		SDL_GetMouseState((int*) &this->pointer_x, (int*) &this->pointer_y);
		
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				this->quit = 1;
				return;
				
			} else if (event.type == SDL_MOUSEBUTTONDOWN) {
				kos_is_mouse_pressed = 1;
				return;
				
			} else if (event.type == SDL_MOUSEBUTTONUP) {
				kos_is_mouse_pressed = 0;
				return;
				
			}
			
		}
		
	}
	
	void free_events(event_list_t* this) {
		
	}
	
#endif
