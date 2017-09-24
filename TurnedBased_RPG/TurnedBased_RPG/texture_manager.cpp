#include "texture_mananger.h"


SDL_Texture* Texture_manager::load_texture(const char* texture_path, SDL_Renderer* renderer)
{
	SDL_Surface* temp_surface = IMG_Load(texture_path);
	if (!temp_surface) { std::cout << "Loading image failed" << std::endl; }
	
	texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	return texture;
}