#include "game_loop.h"

Game_loop::Game_loop() {}
Game_loop::~Game_loop() {}

SDL_Renderer* Game_loop::init_SDL(const char* title, const int& xpos, const int& ypos, const int& width, const int& height, const int flag)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
		if (!window){
			std::cout << "Windows creation failed" << std::endl;
			m_is_running = false;
		}

		renderer = SDL_CreateRenderer(window, -1, 0); // SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
		if (!renderer) { 
			std::cout << "Renderer creation failed"; 
			m_is_running = false;
		}
		return renderer;
	}
	else {
		m_is_running = false;
		return 0;
	}
}

void Game_loop::update()
{
	
}

void Game_loop::input()
{
	if (SDL_PollEvent(&event) != 0)
	{
		if(event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym)
			{
			case SDLK_q:
				m_is_running = false;
				break;
			default:
				break;
			}
	}
}

void Game_loop::render()
{
	SDL_SetRenderDrawColor(renderer, 37, 38, 41, 255);
	SDL_RenderClear(renderer);
}

void Game_loop::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}