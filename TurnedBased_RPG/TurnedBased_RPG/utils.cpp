#include "utils.h"

Utils::~Utils()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

SDL_Renderer* Utils::init_SDL(const char* TITLE,
							  int POS_X,
							  int POS_Y,
	                          int WIDTH,
	                          int HEIGHT,
	                          bool is_fullscreen)
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL failed to initialize" << std::endl;
	}
	Uint32 flags = (is_fullscreen) ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
	window = SDL_CreateWindow(TITLE, POS_X, POS_Y, WIDTH, HEIGHT, flags);
	if (window == nullptr){
		std::cout << "Window failed to create" << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << "Renderer failed to initialize" << std::endl;
	}
	return renderer;
}