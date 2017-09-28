#include "game_loop.h"
#include "game_object.h"
#include "text_manager.h"
#include <memory>


int main(int argc, char* argv[])
{
	const int WIDTH = 800;
	const int HEIGHT = 600;
	const int FPS = 60;
	const int delay_time = 1000 / FPS;
	Uint32 start_time;
	Uint32 current_time;

	std::unique_ptr<Game_loop> game = std::make_unique<Game_loop>();
	int pos[2] = { (WIDTH/2)/2,HEIGHT/3.5 };
	std::unique_ptr<Text_manager> txt = std::make_unique<Text_manager>(pos);

	SDL_Renderer* renderer = game->init_SDL("RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	std::unique_ptr<Game_object> main_menu_texture = std::make_unique<Game_object>("Art/Static/main_menu_border.png", renderer, 0, 0, 800, 600);
	SDL_Texture* main_menu_border_texture = main_menu_texture->load_texture();

	SDL_Texture* text_texture = txt->load_text("Font/712_serif.ttf", renderer);
	while (game->is_running())
	{
		start_time = SDL_GetTicks();
		game->input();
		game->render();

		txt->render(renderer, text_texture);

		main_menu_texture->render();

		SDL_RenderPresent(renderer);

		current_time = SDL_GetTicks() - start_time;
		if (current_time < delay_time){
			SDL_Delay(delay_time - current_time);
		}
	}
	
	game->clean();
	return 0;
}