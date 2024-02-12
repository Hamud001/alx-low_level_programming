#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile -  a function that reads a text file
 * and prints it to the POSIX standard output
 * @filename: variable pointer
 * @letters: size letters
 * Return: if filename is NULL return 0, if write fails
 * or does not write the expected amount of bytes, return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file, let, n;
	char *value;

	value = malloc(letters);
	if (value == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);

	if (file == -1)
	{
		free(value);
		return (0);
	}

	let = read(file, value, letters);

	n = write(STDOUT_FILENO, value, let);

	close(file);

	return (n);
}
