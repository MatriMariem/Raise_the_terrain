#include "terrain.h"
/**
 * Drawgrid - draws a grid on the renderer
 * @ren: renderer
 * @grid: the grid
 */
void Drawgrid(SDL_Renderer *ren, SDL_Point ***grid)
{
	int i;

	SDL_SetRenderDrawColor(ren, 255,  255, 255, 255);
	for (i = 0; i < 8; i++)
		SDL_RenderDrawLines(ren, grid[0][i], 8);
	for (i = 0; i < 8; i++)
		SDL_RenderDrawLines(ren, grid[1][i], 8);
	SDL_RenderPresent(ren);

}

/**
 * rotategrid - rotates the points of a grid
 * @grid: original isometric grid
 * @a: angle of rotation
 * Return: the rotated grid
 */
SDL_Point ***rotategrid(SDL_Point ***grid, float a)
{
	int i, j, k;
	SDL_Point ***new_grid;

	new_grid = malloc(sizeof(SDL_Point **) * 2);
	new_grid[0] = malloc(sizeof(SDL_Point *) * 8);
	new_grid[1] = malloc(sizeof(SDL_Point *) * 8);
	for (i = 0; i < 8; i++)
	{
		new_grid[0][i] = malloc(sizeof(SDL_Point) * 8);
		new_grid[1][i] = malloc(sizeof(SDL_Point) * 8);
	}
	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				new_grid[k][i][j].x =
				(grid[k][i][j].x - 500) * cos(a) -
				(grid[k][i][j].y - 400) * sin(a) + 500;
				new_grid[k][i][j].y =
				(grid[k][i][j].x - 500) * sin(a) +
				(grid[k][i][j].y - 400) * cos(a) + 400;
			}
		}
	}
	return (new_grid);
}

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
