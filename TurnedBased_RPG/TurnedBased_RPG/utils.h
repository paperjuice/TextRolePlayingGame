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

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};






#endif // !UTILS_H
