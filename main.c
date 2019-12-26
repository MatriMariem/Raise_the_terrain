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
	SDL_Point ***grid;
int i;

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

/*free grid, row and col*/

	SDL_Delay(5000);
	Destroy_Quit(ren, win);
	return (0);
}
