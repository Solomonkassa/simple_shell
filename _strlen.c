#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @str: string to calculate length
 * Return: Length of the string
 */

int _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	return (i);
}
