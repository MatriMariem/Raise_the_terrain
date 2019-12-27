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


SDL_Point ***allocategrid(void);
SDL_Point ***makegrid(void);
void makerow(SDL_Point ***simple_grid);
void makecol(SDL_Point ***simple_grid);
void makeiso(SDL_Point ***isogrid, char **argv);


void All_isogrid(SDL_Renderer *ren, char **argv);
void Drawgrid(SDL_Renderer *ren, SDL_Point ***grid);
void makerot(SDL_Point ***grid, float a);
void rotategrid(SDL_Renderer *ren, char **argv, float a);


void freegrid(SDL_Point ***grid);
void freenumbers(int **numbers);
void Destroy_Quit(SDL_Renderer *ren, SDL_Window *win);



#endif
