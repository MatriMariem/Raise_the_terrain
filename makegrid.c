#include "terrain.h"

/**
 * allocategrid - allocates memory for a grid
 * Return: pointer to the allocated memory
 */
SDL_Point ***allocategrid(void)
{
	int i;
	SDL_Point ***grid;

	grid = malloc(sizeof(SDL_Point **) * 2);
	grid[0] = malloc(sizeof(SDL_Point *) * 8);
	grid[1] = malloc(sizeof(SDL_Point *) * 8);
	for (i = 0; i < 8; i++)
	{
		grid[0][i] = malloc(sizeof(SDL_Point) * 8);
		grid[1][i] = malloc(sizeof(SDL_Point) * 8);
	}
	return (grid);
}
/**
 * makegrid - creates a simple grid
 * Return: pointer to the simple grid
 */
SDL_Point ***makegrid(void)
{
	SDL_Point ***simple_grid;

	simple_grid = allocategrid();

	makerow(simple_grid);
	makecol(simple_grid);
	return (simple_grid);
}

/**
 * makerow - fills the rows of a simple grid
 * @simple_grid: pointer of the simple grid
 */
void makerow(SDL_Point ***simple_grid)
{
	int i, j, x = 700, y = 0;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			simple_grid[0][i][j].x = x;
			simple_grid[0][i][j].y = y;
			x = simple_grid[0][i][j].x + 100;
		}
		x = 700;
		y += 100;
	}
}

/**
 * makecol - fills the columns of a simple grid
 * @simple_grid: pointer of the simple grid
 */
void makecol(SDL_Point ***simple_grid)
{
	int i, j, x = 700, y = 0;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			simple_grid[1][i][j].x = x;
			simple_grid[1][i][j].y = y;
			y = simple_grid[1][i][j].y + 100;
		}
		y = 0;
		x += 100;
	}

}

/**
 * makeiso - makes a grid become isometric
 * @isogrid: the initial grid
 * @argv: arguments passed to the main program
 */
void makeiso(SDL_Point ***isogrid, char **argv)
{
	int **altitudes;
	int i, j, isox, isoy;

	altitudes = get_altitudes(argv);

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			isox = 0.7 * isogrid[0][i][j].x -
				0.7 * isogrid[0][i][j].y;

			isoy = 0.3 * isogrid[0][i][j].x +
				0.3 * isogrid[0][i][j].y - altitudes[i][j];
			isogrid[0][i][j].x = isox;
			isogrid[0][i][j].y = isoy;
		}
	}

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			isox = 0.7 * isogrid[1][i][j].x -
				0.7 * isogrid[1][i][j].y;

			isoy = 0.3 * isogrid[1][i][j].x +
				0.3 * isogrid[1][i][j].y - altitudes[j][i];

			isogrid[1][i][j].x = isox;
			isogrid[1][i][j].y = isoy;
		}
	}

	freenumbers(altitudes);
}

