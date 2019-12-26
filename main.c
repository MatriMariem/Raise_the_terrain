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
	SDL_Point ***grid, ***new_grid = NULL;
	SDL_bool running = SDL_TRUE;
	SDL_Event event;
	int a, Angle = 0;

	if (argc != 2)
	{
		printf("Usage: ./terrain altitudes\n");
		return (EXIT_FAILURE);
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("error in init : %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}
	win = SDL_CreateWindow("Welcome to SDL 2!", 0, 0, 1000, 800,
			SDL_WINDOW_OPENGL);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED
			| SDL_RENDERER_PRESENTVSYNC);
	grid = makegrid(argv);
	Drawgrid(ren, grid);
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
				if (event.key.keysym.sym == SDLK_RIGHT)
					Angle++;
				else
					Angle--;
				a = Angle * M_PI / 180;
				new_grid = rotategrid(grid, new_grid, a, argv);
				SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
				SDL_RenderClear(ren);
				Drawgrid(ren, new_grid);
				SDL_RenderPresent(ren);
			}
		}
	}
	freegrid(grid, new_grid);
	Destroy_Quit(ren, win);
	return (0);
}
