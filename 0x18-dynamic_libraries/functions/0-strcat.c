#include "main.h"

/**
 * _strcat - concatenates two str
 * @dest: str to append to
 * @src: str to add
 *
 * Return: a pointer to the resulting str
 */
char *_strcat(char *dest, char *src)
{
	int i, k;

	i = 0;
	k = 0;

	while (dest[i] != '\0')
		i++;

	while (src[k] != '\0')
	{
		dest[i] = src[k];
		k++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
