#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename:  is the name of the file to create and text_content is
 * a NULL terminated string to write to the file
 * @text_content: content file
 * Return: if filename is NULL return -1,
 * if text_content is NULL create an empty file
 */

int create_file(const char *filename, char *text_content)
{
	int n = 0, file;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";


	while (text_content[n] != '\0')
	{
		n++;
	}

	file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (file == -1)
		return (-1);

	write(file, text_content, n);

	return (1);
}
