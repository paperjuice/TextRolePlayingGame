#include "utils.h"

Utils::~Utils()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
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
	m_window = SDL_CreateWindow(TITLE, POS_X, POS_Y, WIDTH, HEIGHT, flags);
	if (m_window == nullptr){
		std::cout << "Window failed to create" << std::endl;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr) {
		std::cout << "Renderer failed to initialize" << std::endl;
	}
	return m_renderer;
}

bool Utils::input(SDL_Keycode key)
{
	if (SDL_PollEvent(&m_event) != 0)
	{
		if (m_event.type == SDL_KEYDOWN)
		{
			if (m_event.key.keysym.sym == key)
			{
				return 1;
			}
		}
	}
	return 0;
}