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

int _atoi(char *s);
char *_strdup(char *str);
char **splitstring(char *str, const char *delim);
void freearv(char **arv);
int **get_altitudes(char **argv);
void freenumbers(int **numbers);

SDL_Point ***makegrid(int **altitudes);
SDL_Point **makerow(int **altitudes);
SDL_Point **makecol(int **altitudes);


#endif
