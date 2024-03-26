#include "main.h"

/**
 * *_strspn - gets the length of a prefix substr
 * @s: str to evaluate
 * @accept: str containing the list of values to match in s
 *
 * Return: the number of bytes in the initial segment
 * of s which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, k, g, flag;

	g = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		flag = 0;
		for (k = 0; accept[k] != '\0'; k++)
		{
			if (s[i] == accept[k])
			{
				g++;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return (g);
		}
	}

	return (0);
}
