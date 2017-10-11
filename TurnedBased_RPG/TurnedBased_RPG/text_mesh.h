#ifndef TEXT_MESH_H
#define TEXT_MESH_H
#include "texture.h"
#include "entity.h"
#include "SDL_ttf.h"


class Text_mesh: public Texture, public Entity
{
public:
	Text_mesh(int pos_x,
		      int pos_y,
		      int rotation,
		      int scale_x,
		      int scale_y,
		      SDL_Renderer* renderer);
	
	SDL_Texture* load_text(const char* path, const char* message, SDL_Color col, Uint16 range);
	void render(const bool& is_flip);

private:
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
};

#endif // TEXT_MESH_H
