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
 * @new_grid: rotated grid
 * @a: angle of rotation
 * @argv: array of arguments passed to the program
 * Return: the rotated grid
 */
SDL_Point ***rotategrid(SDL_Point ***grid, SDL_Point ***new_grid, int
		a, char **argv)
{

	if (!new_grid)
		new_grid = makegrid(argv);
	new_grid = Editgrid(grid, new_grid, a);

	return (new_grid);
}

/**
 * Editgrid - edits the coordinates of the original grid into the new grid
 * @grid: original grid
 * @new_grid: rotated grid
 * @a: angle of rotation
 * Return: the rotated grid
 */
SDL_Point ***Editgrid(SDL_Point ***grid, SDL_Point ***new_grid, int a)
{
	int i, j, k;

	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				new_grid[k][i][j].x = grid[k][i][j].x * cos(a) - grid[k][i][j].y * sin(a);
				new_grid[k][i][j].y = grid[k][i][j].x * sin(a) + grid[k][i][j].y * cos(a);
			}
		}
	}
	return (new_grid);
}

/**
 * freegrid - frees the original and rotated grid
 * @grid: the original grid
 * @new_grid: the rotated grid
 */
void freegrid(SDL_Point ***grid, SDL_Point ***new_grid)
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
	if (new_grid)
	{
		for (k = 0; k < 2; k++)
		{
			for (i = 0; i < 8; i++)
			{
				free(new_grid[k][i]);
			}
			free(new_grid[k]);
		}
		free(new_grid);

	}
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
