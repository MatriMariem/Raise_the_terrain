#include "terrain.h"

/**
 * makegrid - creates an isometric grid
 * @argv: arguments passed to the main program
 * Return: grid
 */
SDL_Point ***makegrid(char **argv)
{
	SDL_Point ***grid;
	SDL_Point **row;
	SDL_Point **col;
	int **altitudes;

	grid = malloc(sizeof(SDL_Point **) * 2);
	altitudes = get_altitudes(argv);
	row = makerow(altitudes);
	col = makecol(altitudes);

	grid[0] = row;
	grid[1] = col;
	freenumbers(altitudes);
	return (grid);
}

/**
 * makerow - creates the isometric rows of the grid
 * @altitudes: altitudes of each point
 * Return: pointer to rows
 */
SDL_Point **makerow(int **altitudes)
{
	int i, j, x = 700, y = 0, isox, isoy;
	SDL_Point **row;

	row = malloc(sizeof(SDL_Point *) * 8);
	for (i = 0; i < 8; i++)
		row[i] = malloc(sizeof(SDL_Point) * 8);

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			row[i][j].x = x;
			row[i][j].y = y;
			x = row[i][j].x + 100;
			isox = 0.7 * row[i][j].x - 0.7 * row[i][j].y;
			isoy = 0.3 * row[i][j].x + 0.3 * row[i][j].y - altitudes[i][j];
			row[i][j].x = isox;
			row[i][j].y = isoy;
		}
		x = 700;
		y += 100;
	}

	return (row);
}

SDL_Point **makecol(int **altitudes)
{
	int i, j, x = 700, y = 0, isox, isoy;
	SDL_Point **col;

	col = malloc(sizeof(SDL_Point *) * 8);
	for (i = 0; i < 8; i++)
		col[i] = malloc(sizeof(SDL_Point) * 8);


	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			col[i][j].x = x;
			col[i][j].y = y;
			y = col[i][j].y + 100;
			isox = 0.7 * col[i][j].x - 0.7 * col[i][j].y;
			isoy = 0.3 * col[i][j].x + 0.3 * col[i][j].y - altitudes[j][i];
			col[i][j].x = isox;
			col[i][j].y = isoy;
		}
		y = 0;
		x += 100;
	}

	return (col);
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

