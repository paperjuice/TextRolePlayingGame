#include "game_object.h"

Game_object::Game_object(const char * image_path, SDL_Renderer * renderer, int trans_x, int trans_y, int trans_w, int trans_h)
	:m_renderer(renderer), m_image_path(image_path)
{
	m_texture_position.x = trans_x;
	m_texture_position.y = trans_y;
	m_texture_position.w = trans_w;
	m_texture_position.h = trans_h;
}

Game_object::~Game_object()
{
	SDL_DestroyRenderer(m_renderer);
}

SDL_Texture* Game_object::load_texture()
{
	SDL_Surface* temp_surface = IMG_Load(m_image_path);
	if (!temp_surface) { std::cout << "Image not loaded" << std::endl; }

	m_texture = SDL_CreateTextureFromSurface(m_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	return m_texture;
}

void Game_object::render()
{
	//SDL_RenderCopy(m_renderer, m_texture, NULL, &m_texture_position);
	SDL_RenderCopyEx(m_renderer, m_texture, NULL, &m_texture_position, 0, 0, SDL_RendererFlip::SDL_FLIP_HORIZONTAL);
}

void Game_object::set_transform(Transform transform)
{
	m_texture_position.x = transform.x;
	m_texture_position.y = transform.y;
	m_texture_position.w = transform.w;
	m_texture_position.h = transform.h;
}
