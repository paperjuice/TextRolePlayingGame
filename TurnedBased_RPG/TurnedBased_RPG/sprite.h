#ifndef SPRITE_H
#define SPRITE_H

#include "texture.h"
#include "entity.h"
#include <SDL_image.h>


class Sprite: public Texture, public Entity
{
public:
  Sprite(int pos_x,
         int pos_y,
         int rotation,
         int scale_x,
         int scale_y,
         SDL_Renderer* renderer);
  ~Sprite();
  SDL_Texture* load_texture(const char* SPRITE_PATH);
  void render(const bool& is_flip);

private:
  SDL_Texture* m_texture;
  SDL_Renderer* m_renderer;
};
#endif
