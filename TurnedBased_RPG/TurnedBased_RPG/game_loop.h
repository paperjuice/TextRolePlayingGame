#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "texture_mananger.h"

class Game_loop : public Texture_manager
{
public:
	Game_loop();
	~Game_loop();
	SDL_Renderer* init_SDL(const char* title,const int& xpos, const int& ypos, const int& width, const int& height, const int flag);
	void update();
	void render();
	void input();
	void clean();

	bool is_running() { return m_is_running; }

private:
	bool m_is_running = true;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	SDL_Texture* m_player_texture;
	SDL_Rect m_player_rect;

	int count = 0;
};





#endif