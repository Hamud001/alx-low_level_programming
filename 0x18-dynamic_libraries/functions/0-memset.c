#include "main.h"

/**
 * *_memset - function that fills memory with a constant byte
 * @s: memory to fill
 * @b: char to copy for the memory
 * @n: number of times to copy b
 *
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
	{
		s[x] = b;
	}

	return (s);
}
