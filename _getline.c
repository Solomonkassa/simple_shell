#include "shell.h"

/**
 * _getline - reads the input from stdin provided by the user
 * Return: the input string
 */

char *_getline(void)
{
	char c;
	char *buffer;
	int i = 0;
	int size = 80;

	buffer = malloc(size * sizeof(char));
	if (buffer == NULL)
	{
		return (NULL);
	}

	while (read(STDIN_FILENO, &c, 1) > 0 && c != '\n')
	{
		buffer[i++] = c;
	}

	buffer[i] = '\0';

	return (buffer);
}
