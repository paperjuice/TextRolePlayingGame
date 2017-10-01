#include <memory>
#include "utils.h"

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

	while(is_running)
	{
	
		if (utils->input(SDLK_q))
		{
			is_running = false;
		}

		SDL_SetRenderDrawColor(renderer, 8, 82, 82, 255);
		SDL_RenderClear(renderer);

    main_menu_border->render(false);



		SDL_RenderPresent(renderer);
	}



	return 0;
}
//
//const int WIDTH = 800;
//const int HEIGHT = 600;
//const int FPS = 60;
//const int delay_time = 1000 / FPS;
//Uint32 start_time;
//Uint32 current_time;
//
//std::unique_ptr<Game_loop> game = std::make_unique<Game_loop>();
//int pos[2] = { (WIDTH / 2) / 2,HEIGHT / 3.5 };
//std::unique_ptr<Text_manager> txt = std::make_unique<Text_manager>(pos);
//
//SDL_Renderer* renderer = game->init_SDL("RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
//
//std::unique_ptr<Game_object> main_menu_texture = std::make_unique<Game_object>("Art/Static/main_menu_border.png", renderer, 0, 0, 800, 600);
//SDL_Texture* main_menu_border_texture = main_menu_texture->load_texture();
//
//
//SDL_Surface* temp_fire = IMG_Load("Art/Static/fire_lantern.png");
//SDL_Texture* fire_lantern_texture = SDL_CreateTextureFromSurface(renderer, temp_fire);
//SDL_FreeSurface(temp_fire);
//SDL_Rect fire_sprite;
//SDL_Rect fire_pos;
//int texture_width = 0, texture_height = 0;
//int temp_x = 0;
//int temp_y = 0;
//SDL_QueryTexture(fire_lantern_texture, NULL, NULL, &texture_width, &texture_height);
//fire_sprite.x = fire_sprite.y = 32;
//fire_sprite.w = texture_width / 2;
//fire_sprite.h = texture_height / 2;
//
//
//
//SDL_Texture* text_texture = txt->load_text("Font/712_serif.ttf", renderer);
//while (game->is_running())
//{
//	start_time = SDL_GetTicks();
//	game->input();
//	game->render();
//
//	txt->render(renderer, text_texture);
//
//	main_menu_texture->render();
//
//	SDL_RenderPresent(renderer);
//
//
//
//	//---------------------
//
//	SDL_RenderCopy(renderer, fire_lantern_texture, NULL, NULL);
//
//
//	/*if (temp_x == 1)
//	{
//	fire_sprite.x += 32;
//	if (temp_x == 1)
//	{
//	++temp_y;
//	temp_x = 0;
//	fire_sprite.y += 32;
//	if (temp_y == 1)
//	{
//	temp_y = 0;
//	fire_sprite.y = 0;
//	}
//
//	}
//	}
//	++temp_x;*/
//
//	//-------------------
//
//
//
//	current_time = SDL_GetTicks() - start_time;
//	if (current_time < delay_time) {
//		SDL_Delay(delay_time - current_time);
//	}
//}
//
//game->clean();