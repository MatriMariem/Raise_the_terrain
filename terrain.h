#ifndef TERRAIN_H
#define TERRAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

#include <SDL.h>
#include <math.h>

int _atoi(char *s);
char *_strdup(char *str);
char **splitstring(char *str, const char *delim);
void freearv(char **arv);
int **get_altitudes(char **argv);
void freenumbers(int **numbers);

SDL_Point ***makegrid(char **argv);
SDL_Point **makerow(int **altitudes);
SDL_Point **makecol(int **altitudes);

void Drawgrid(SDL_Renderer *ren, SDL_Point ***grid);
void Destroy_Quit(SDL_Renderer *ren, SDL_Window *win);

SDL_Point ***rotategrid(SDL_Point ***grid, SDL_Point ***new_grid, int
		a, char **argv);
SDL_Point ***Editgrid(SDL_Point ***grid, SDL_Point ***new_grid, int a);
void freegrid(SDL_Point ***grid, SDL_Point ***new_grid);

#endif
