#include "main.h"
#include <stdio.h>

/**
 * *_strpbrk - searches a str for any of a set of bytes
 * @s: str to search
 * @accept: strcontaining the bytes searched
 *
 * Return: pointer to the byte in s that matches
 * or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int i, k;

	for (i = 0; *s != '\0'; i++)
	{
		for (k = 0; accept[k] != '\0'; k++)
		{
			if (*s == accept[k])
			{
				return (s);
			}
		}
		s++;
	}

	return (NULL);
}
