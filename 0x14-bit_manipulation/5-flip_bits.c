#include <stdio.h>
#include "main.h"

/**
 * flip_bits -  a function that returns the number of bits you would need
 * to flip to get from one number to another
 * @n: initial number
 * @m: latter number
 *
 * Return: Number of bits needed to flip to get from n to m
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)

{
	unsigned int flip = 0, value, value1;

	while (!(n == 0 && m == 0))
	{
		value = n & 1;
		value1 = m & 1;
		n = n >> 1;
		m = m >> 1;
		if (value != value1)
			flip += 1;
	}
	return (flip);
}
