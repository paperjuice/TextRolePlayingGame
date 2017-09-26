#include "text_manager.h"

Text_manager::Text_manager()
{
}

SDL_Texture * Text_manager::load_test(const char * font_path, SDL_Renderer * renderer)
{
	if (TTF_Init()==-1) { std::cout << "Initialization failed: " << TTF_GetError()<< std::endl; };

	TTF_Font* font = TTF_OpenFont(font_path, 16);

	SDL_Color col = { 200,200,200,255 };
	SDL_Surface* temp_surface = TTF_RenderText_Solid(font, "THis is My text this is my text wtf text wut are you doing", col);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	return texture;
}

void Text_manager::render(SDL_Renderer* renderer, SDL_Texture* texture)
{
	SDL_Rect pos;;
	pos.x = pos.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(renderer, texture, NULL, &pos); 
}
