#include "terrain.h"

/**
 * _atoi - converts a string into integer
 * @s: the string
 * Return: integer
 */
int _atoi(char *s)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (integer);
}

/**
 * _strdup - copies a string in a newly allocated memory area
 * @str: the string that will be copied
 * Return: the copy of str
 */
char *_strdup(char *str)
{
	int i, l;
	char *new;

	if (!str)
	{
		return (0);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (0);
	}
	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}
	new[l] = str[l];
	return (new);
}

/**
 * splitstring - creates an array of words from a string
 * @str: the string
 * @delim: the delimiter of words
 * Return: an array of words
 */
char **splitstring(char *str, const char *delim)
{
	int i, wn;
	char **array;
	char *token;
	char *copy;

	copy = _strdup(str);

	token = strtok(copy, delim);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	i = 1;
	wn = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		array = realloc(array, (sizeof(char *) * wn));
		array[i] = _strdup(token);
		i++;
		wn++;
	}
	free(copy);
	return (array);
}

/**
 * freearv - frees the array of words arv
 *@arv: array of words
 */

void freearv(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}

/**
 * get_altitudes - reads a file of altitudes
 * and stores the altitudes in a 2D array of integers
 * @argv: array of arguments entered to the main program
 * Return: 2D array of integers
 */
int **get_altitudes(char **argv)
{
	char mybuf[1024];
	char **lines;
	char **chars[8];
	int **numbers;
	int fd, i, j;

	fd = open(argv[1], O_RDWR);
	read(fd, mybuf, 1023);
	close(fd);

	numbers = malloc(sizeof(int *) * 8);
	for (i = 0; i < 8; i++)

		numbers[i] = malloc(sizeof(int) * 8);
	lines = splitstring(mybuf, "\n");

	for (i = 0; lines[i]; i++)
	{
		chars[i] = splitstring(lines[i], " ");
	}

	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 8; i++)
		{
			numbers[j][i] = _atoi(chars[j][i]);
		}
	}

	freearv(lines);
	for (i = 0; i < 8; i++)
		freearv(chars[i]);

	return (numbers);
}






