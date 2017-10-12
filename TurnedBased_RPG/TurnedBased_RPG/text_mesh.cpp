#include "text_mesh.h"
#include <iostream>

Text_mesh::Text_mesh(int pos_x,
	int pos_y,
	int rotation,
	int scale_x,
	int scale_y,
	SDL_Renderer* renderer)
	:Entity(pos_x, pos_y, rotation, scale_x, scale_y),
	m_renderer(renderer)
{
	pos.x = pos_x;
	pos.y = pos_y;

}

SDL_Texture* Text_mesh::load_text(const char* path, const int& font_size, const char* message, SDL_Color col, Uint16 range)
{
	if (TTF_Init() == -1) { std::cout << "TTF_failed to initialise" << std::endl; }
	TTF_Font* font = TTF_OpenFont(path, font_size);
	SDL_Surface* temp_surface = TTF_RenderText_Blended_Wrapped(font, message, col, range);
	m_texture = SDL_CreateTextureFromSurface(m_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	return m_texture;
}

void Text_mesh::render(const bool& is_flip)
{
	SDL_QueryTexture(m_texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopyEx(m_renderer, m_texture, NULL, &pos, get_rotation(), nullptr, is_flip?SDL_FLIP_HORIZONTAL:SDL_FLIP_NONE);
}