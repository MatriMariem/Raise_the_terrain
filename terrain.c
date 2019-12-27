#include "terrain.h"

/**
 * main - draws an isometric projection of a grid
 * and rotates it when pressing RIGHT or LEFT arrows
 * and quits when pressing ESC or Quit button
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on Success, EXIT_FAILURE on failure
 */

int main(int argc, char **argv)
{
	SDL_Window *win;
	SDL_Renderer *ren;
	SDL_bool running = SDL_TRUE;
	SDL_Event event;
	int Angle;
	float a;

	if (argc != 2)
	{
		printf("Usage: ./terrain altitudes\n");
		return (EXIT_FAILURE);
	}
	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("Welcome to SDL 2!", 0, 0, 1000, 800,
			SDL_WINDOW_OPENGL);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED
			| SDL_RENDERER_PRESENTVSYNC);
	All_isogrid(ren, argv);
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT ||
					(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			{
				running = SDL_FALSE;
				break;
			}
			if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT)
			{
				Angle = (event.key.keysym.sym == SDLK_RIGHT) ? Angle + 1 : Angle - 1;
				a = Angle * M_PI / 180;
				SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
				SDL_RenderClear(ren);
				rotategrid(ren, argv, a);
			}
		}
	}
	Destroy_Quit(ren, win);
	return (0);
}
