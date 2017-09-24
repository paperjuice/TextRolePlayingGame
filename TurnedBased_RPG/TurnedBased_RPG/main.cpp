#include "game_loop.h"
#include "game_object.h"
#include <memory>

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int delay_time = 1000 / FPS;
	Uint32 start_time;
	Uint32 current_time;

	std::unique_ptr<Game_loop> game = std::make_unique<Game_loop>();

	SDL_Renderer* renderer = game->init_SDL("RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	std::unique_ptr<Game_object> player = std::make_unique<Game_object>("Art/knight.png", renderer, 400-164/2, 400, 164, 164);
	SDL_Texture* player_texture = player->load_texture();

	while (game->is_running())
	{
		start_time = SDL_GetTicks();


		game->input();
		//game->update();
		game->render();

		player->render();

		SDL_RenderPresent(renderer);


		current_time = SDL_GetTicks() - start_time;
		if (current_time < delay_time){
			SDL_Delay(delay_time - current_time);
		}
	}
	
	game->clean();
	return 0;
}