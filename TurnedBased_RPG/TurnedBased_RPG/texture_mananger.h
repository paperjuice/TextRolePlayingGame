#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>


class Texture_manager
{
public:
	SDL_Texture* load_texture(const char* texture_path, SDL_Renderer* renderer);

private:
	SDL_Texture* texture;
};


#endif