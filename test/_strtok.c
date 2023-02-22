#include "shell.h"

/**
 * _strtok - function that tokenizes a string
 * @str: the string to tokenize
 * @delim: the delimiter to use
 *
 * Return: a pointer to the next token in the string
 */

char *_strtok(char *str, const char *delim)
{
	static char *last;
	char *token;

	if (str != NULL)
	{
		last = str;
	}

	if (*last == '\0')
	{
		return (NULL);
	}

	token = last;

	while (*last != '\0')
	{
		const char *d = delim;

		for (d = delim; *d != '\0'; d++)
		{
			if (*last == *d)
			{
				*last = '\0';
				last++;
				return (token);
			}
		}

		last++;
	}

	return (token);
}
