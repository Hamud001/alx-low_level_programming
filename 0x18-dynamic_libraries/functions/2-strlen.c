#include "main.h"

/**
 * _strlen - returns the length of a str
 * @s: str to evaluate
 *
 * Return: the length of the str
 */
int _strlen(char *s)
{
	int x;

	x = 0;

	while (s[x] != '\0')
	{
		x++;
	}

	return (x);
}
