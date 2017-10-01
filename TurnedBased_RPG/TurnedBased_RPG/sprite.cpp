#include "sprite.h"

Sprite::Sprite(int pos_x,
               int pos_y,
               int rotation,
               int scale_x,
               int scale_y,
               SDL_Renderer* renderer)
:Entity(pos_x, pos_y, rotation, scale_x, scale_y),
m_renderer(renderer)
{}

Sprite::~Sprite()
{
  SDL_DestroyTexture(m_texture);
}

SDL_Texture* Sprite::load_texture(const char* SPRITE_PATH)
{
  SDL_Surface* temp_surface = IMG_Load(SPRITE_PATH);
  if (temp_surface == nullptr){
    std::cout << "Image failed to load" << std::endl;
  }

  m_texture = SDL_CreateTextureFromSurface(m_renderer, temp_surface);
  if (m_texture == nullptr) {
    std::cout << "Texture failed to load" << std::endl;
  }

  SDL_FreeSurface(temp_surface);
  return m_texture;
}

void Sprite::render(const bool& is_flip)
{
  //TODO: take image width and height and scale it based on those values
  SDL_RenderCopyEx(m_renderer,
                   m_texture,
                   NULL,
                   &get_transform(),
                   get_rotation(),
                   NULL,
                   (is_flip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

