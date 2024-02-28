#include "main.h"

/**
 * my_getline - extracts chars from stream
 * @stream: input stream
 * @n: size of stream
 * @lineptr: storage for the buffer
 *
 * Return: numChars
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 1024;
	ssize_t numChars = 0;
	int c;

	if (*lineptr == NULL)
	{
		*lineptr = malloc(bufsize);

		if (*lineptr == NULL)
		{
			return (-1);
		}
		*n = bufsize;
	}

	numChars = 0;

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		(*lineptr)[numChars++] = c;
		if ((size_t)numChars >= *n)
		{
			bufsize += 1024;
			*lineptr = realloc(*lineptr, bufsize);
			if (*lineptr == NULL)
			{
				return (-1);
			}
			*n = bufsize;
		}
	}

	if (c == EOF && numChars == 0)
	{
		return (-1);
	}

	(*lineptr)[numChars] = '\0';
	return (numChars);
}
