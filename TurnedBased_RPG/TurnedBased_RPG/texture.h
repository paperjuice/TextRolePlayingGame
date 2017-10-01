#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
public:
  virtual ~Texture() {};

  //virtual SDL_Texture* load_texture(const char* SPRITE_PATH) = 0;
  virtual void render(const bool& is_flip) = 0;
};

#endif