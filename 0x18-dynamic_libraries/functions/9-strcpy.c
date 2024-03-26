#include "main.h"

/**
 * *_strcpy - copies the str pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which to copy the str
 * @src: str to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, x;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (x = 0; x < len; x++)
	{
		dest[x] = src[x];
	}
	dest[x] = '\0';

	return (dest);
}
