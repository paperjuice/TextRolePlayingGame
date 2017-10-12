#include <memory>
#include "utils.h"
#include "text_mesh.h"
#include "sprite.h"

int main(int argc, char* argv[])
{
	const char* TITLE = "RPG";
	const int POS_X = SDL_WINDOWPOS_CENTERED;
	const int POS_Y = SDL_WINDOWPOS_CENTERED;
	const int WIDTH = 620;
	const int HEIGHT = 400;

	bool is_running = true;

	std::unique_ptr<Utils> utils = std::make_unique<Utils>();
	SDL_Renderer* renderer = utils->init_SDL(TITLE, POS_X, POS_Y, WIDTH, HEIGHT, false);

	std::unique_ptr<Sprite> title = 
		std::make_unique<Sprite>(0, 0, 0, WIDTH, HEIGHT, renderer);
	title->load_texture("Art/Static/title_beneth.png");
	title->set_scale(50, 50);

	std::unique_ptr<Sprite> main_menu_border = 
		std::make_unique<Sprite>(0, 0, 0, 100, 100, renderer);
	main_menu_border->load_texture("Art/Static/main_menu_border.png");


	// text - start game
	std::unique_ptr<Text_mesh> text_start_game = 
		std::make_unique<Text_mesh>(50, 210, 0, 300, 300, renderer);
	text_start_game->load_text("Font/712_serif.ttf",
		                  32,
		                  "Start game",
						  { 163,192,209,255 },
		                  500);

	// text - quit
	std::unique_ptr<Text_mesh> text_quit =
		std::make_unique<Text_mesh>(50, 240, 0, 300, 300, renderer);
	text_quit->load_text("Font/712_serif.ttf",
		32,
		"Quit",
		{ 163,192,209,255 },
		500);

	while(is_running)
	{
	
		if (utils->input(SDLK_q))
		{
			is_running = false;
		}

		SDL_SetRenderDrawColor(renderer, 47, 49, 51, 255);
		SDL_RenderClear(renderer);

		
		main_menu_border->render(false);
		
		title->render(false);

		text_start_game->render(false);
		text_quit->render(false);


		SDL_RenderPresent(renderer);
	}



	return 0;
}