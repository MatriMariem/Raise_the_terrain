#include "terrain.h"

/**
 * freegrid - frees a grid
 * @grid: the original grid
 */
void freegrid(SDL_Point ***grid)
{
	int k, i;

	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 8; i++)
		{
			free(grid[k][i]);
		}
		free(grid[k]);
	}
	free(grid);
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

/**
 * Destroy_Quit - destroys the Renderer and the window and Quits
 * @ren: Renderer
 * @win: window
 */
void Destroy_Quit(SDL_Renderer *ren, SDL_Window *win)
{

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
