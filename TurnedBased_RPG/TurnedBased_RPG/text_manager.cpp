#include "text_manager.h"

Text_manager::Text_manager(int position[2])
{
	pos.x = position[0];
	pos.y = position[1];
}



SDL_Texture * Text_manager::load_text(const char * font_path, SDL_Renderer * renderer)
{
	if (TTF_Init()==-1) { std::cout << "Initialization failed: " << TTF_GetError()<< std::endl; };

	TTF_Font* font = TTF_OpenFont(font_path, 72);

	SDL_Color col = { 200,200,200,255 };
	SDL_Surface* temp_surface = TTF_RenderText_Blended_Wrapped(font, "THROUGH PIT ", col, 400);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	return texture;
}

void Text_manager::render(SDL_Renderer* renderer, SDL_Texture* texture)
{
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(renderer, texture, NULL, &pos); 
}
