#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <SDL.h>

class Utils
{
public:
	~Utils();
	SDL_Renderer* init_SDL(const char* title,
		                   int pos_x,
		                   int pos_y,
		                   int WIDTH,
		                   int HEIGHT,
		                   bool is_fullscreen);

	bool input(SDL_Keycode);

private:
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	SDL_Event m_event;
};






#endif // !UTILS_H
