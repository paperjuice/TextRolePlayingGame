#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "game_loop.h"

struct Transform{
	int x, y, w, h;
};

struct Scale {
	int w, h;
};

class Game_object
{
public:
	Game_object(const char* image_path, SDL_Renderer* renderer, int trans_x, int trans_y, int trans_w, int trans_h);
	~Game_object();

	SDL_Texture* load_texture();
	void render();

	void set_transform(Transform transform);

private:
	const char* m_image_path;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;

	//SDL_Rect m_texture_scale;
	SDL_Rect m_texture_position;
};
#endif