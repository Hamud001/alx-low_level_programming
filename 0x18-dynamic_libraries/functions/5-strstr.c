#include "main.h"
#include <stdio.h>

/**
 * *_strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, k;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (k = 0; needle[k] != '\0'; k++)
		{
			if (haystack[i + k] != needle[k])
				break;
		}
		if (!needle[k])
			return (&haystack[i]);
	}
	return (NULL);
}
