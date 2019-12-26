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
	int **altitudes;
	SDL_Window *win;
	SDL_Renderer *ren;
	SDL_Point ***grid;
int i;

	if (argc != 2)
	{
		printf("Usage: ./terrain altitudes\n");
		return (EXIT_FAILURE);
	}
	
	altitudes = get_altitudes(argv);
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("error in init : %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}

	win = SDL_CreateWindow("Welcome to SDL 2!", 0, 0, 1000, 800,
			SDL_WINDOW_OPENGL);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED
			| SDL_RENDERER_PRESENTVSYNC);


SDL_SetRenderDrawColor(ren, 255,  255, 255, 255);
grid = makegrid(altitudes);
for (i = 0; i < 8; i++)
SDL_RenderDrawLines(ren, grid[0][i], 8);
for (i = 0; i < 8; i++)
SDL_RenderDrawLines(ren, grid[1][i], 8);
SDL_RenderPresent(ren);


	freenumbers(altitudes);
/*free grid, row and col*/

	SDL_Delay(5000);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}


/**
 * freenumbers - frees a 2D array of integers
 * @numbers: name of the array
 */
void freenumbers(int **numbers)
{
	int i;

	for (i = 0; i < 8; i++)
		free(numbers[i]);
	free(numbers);
}
