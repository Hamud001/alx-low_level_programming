#include <stdio.h>
#include "main.h"

/**
 * set_bit - a function that sets the value of a bit to 1 at a given index
 * @index: is the index, starting from 0 of the bit you want to set.
 * @n: number
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int size;
	unsigned long int num;

	size = sizeof(*n) * 8 - 1;

	if (index > size)
		return (-1);

	num = 1 << index;

	*n = num | *n;

	return (1);
}
