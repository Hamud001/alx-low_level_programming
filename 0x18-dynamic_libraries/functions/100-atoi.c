#include "main.h"

/**
 * _atoi - converts a str to an int
 * @s: str to be converted
 *
 * Return: the int converted from the str
 */
int _atoi(char *s)
{
	int i, e, m, len, f, digit;

	i = 0;
	e = 0;
	m = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++e;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (e % 2)
				digit = -digit;
			m = m * 10 + digit;
			e = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			e = 0;
		}
		i++;
	}

	if (e == 0)
		return (0);

	return (m);
}
