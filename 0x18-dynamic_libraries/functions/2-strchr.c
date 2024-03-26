#include "main.h"
#include <stdio.h>

/**
 * *_strchr - locates a character in a str
 * @s: str to search
 * @c: char to find
 *
 * Return: a pointer to the first occurrence of the value
 * c in the str s, or NULL if the value is not found
 */
char *_strchr(char *s, char c)
{
		int x;

		while (1)
		{
			x = *s++;
			if (x == c)
			{
				return (s - 1);
			}
			if (x == 0)
			{
				return (NULL);
			}
		}
}
