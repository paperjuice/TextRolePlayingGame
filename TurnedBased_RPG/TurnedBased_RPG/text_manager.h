#ifndef TEXT_MANAGER_H
#define TEXT_MANAGER_H
#include "game_loop.h"
#include <SDL_ttf.h>


class Text_manager
{
public:
	Text_manager();
	SDL_Texture* load_test(const char* font_path, SDL_Renderer* renderer);
	void render(SDL_Renderer* renderer, SDL_Texture* texture);


};





#endif
