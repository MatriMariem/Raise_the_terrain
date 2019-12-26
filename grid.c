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
