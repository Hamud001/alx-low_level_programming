#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * append_text_to_file -a function that appends text at the end of a file
 * @filename: the name of the file
 * @text_content:  is the NULL terminated string to add at the end of the file
 * Return: if filename is NULL return -1
 * If text_content is NULL, do not add anything to the file.
 * Return 1 if the file exists and -1 if the file does not exist
 * or if you do not have the required permissions to write the file
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int n = 0, fn;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";


	while (text_content[n] != '\0')
	{
		n++;
	}

	fn = open(filename, O_WRONLY | O_APPEND);

	if (fn == -1)
		return (-1);

	write(fn, text_content, n);

	return (1);
}
