#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

#ifndef NUM_SIZE
#define NUM_SIZE 1024
#endif

/**
 * main - a program that copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int file_begin, file_end;
	ssize_t value;
	char num[NUM_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_begin = open(argv[1], O_RDONLY);
	if (file_begin == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_end = open(argv[2], O_CREAT | O_WRONLY, 0664);
	if (file_end == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	while ((value = read(file_begin, num, NUM_SIZE)) > 0)
	{
		if (write(file_end, num, value) != value)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (value == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if ((close(file_begin) == -1) || (close(file_end) == -1))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_begin);
		exit(100);
	}
	return (0);
}
