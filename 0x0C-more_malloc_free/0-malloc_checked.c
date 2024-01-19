#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * malloc_checked - does what malloc does and checks if null
 * @b: size to alloc for malloc
 *
 * Return: void pointer to allocated mem
 */
void *malloc_checked(unsigned int b)
{
	void *a;

	a = malloc(b);
	if (a == NULL)
		exit(98);
	return (a);
}
