#include "shell.h"

/**
 * _getenv - gets the value of the specified environment variable
 * @name: the name of the environment variable
 *
 * Return: the value of the environment variable or NULL if it doesn't exist
 */

char *_getenv(const char *name)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		j = 0;

		while (name[j] != '\0' && name[j] == environ[i][j])
		{
			j++;
		}

		if (name[j] == '\0' && environ[i][j] == '=')
		{
			return (&environ[i][j + 1]);
		}
	}

	return (NULL);
}
