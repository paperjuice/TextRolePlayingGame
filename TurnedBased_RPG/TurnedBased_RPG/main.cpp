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

	std::unique_ptr<Sprite> main_menu_border = std::make_unique<Sprite>(0, 0, 0, WIDTH, HEIGHT, renderer);
	main_menu_border->load_texture("Art/Static/main_menu_border.png");

	std::unique_ptr<Text_mesh> text_title = std::make_unique<Text_mesh>(0, 0, 0, 0, 0, renderer);
	text_title->load_text("Font/712_serif.ttf", "Mega cave", { 255,20,25,255 }, 200);

	while(is_running)
	{
	
		if (utils->input(SDLK_q))
		{
			is_running = false;
		}

		SDL_SetRenderDrawColor(renderer, 8, 82, 82, 255);
		SDL_RenderClear(renderer);

		main_menu_border->render(false);
		text_title->render(false);


		SDL_RenderPresent(renderer);
	}



	return 0;
}