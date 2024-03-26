#include "main.h"

/**
 * _puts - prints a str to stdout
 * @str: pointer to the str to print
 */
void _puts(char *str)
{
	int a;

	for (a = 0; str[a] != '\0'; a++)
	{
		_putchar(str[a]);
	}
	_putchar('\n');
}
