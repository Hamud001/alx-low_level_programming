#include <stdio.h>

/**
 * get_endianness -  a function that checks the endianness
 * Prototype: int get_endianness(void)
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int n;

	return ((int) (((char *)&n)[0]));
}
