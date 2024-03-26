#include "main.h"

/**
 * _strncpy - copies a str
 * @dest: destination str
 * @src: source str
 * @n: number of bytes to copy
 *
 * Return: pointer to the resulting str
 */
char *_strncpy(char *dest, char *src, int n)
{
	int x;

	x = 0;

	while (src[x] != '\0' && x < n)
	{
		dest[x] = src[x];
		x++;
	}

	while (x < n)
	{
		dest[x] = '\0';
		x++;
	}

	return (dest);
}
