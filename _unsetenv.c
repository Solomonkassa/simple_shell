#include "shell.h"

/**
 * _unsetenv - removes an environment variable
 * @varname: the name of the variable to remove
 *
 * Return: 0 on success, -1 on failure
 */

int _unsetenv(char *varname)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		j = 0;

		for (; varname[j] != '\0' && varname[j] == environ[i][j];)
		{
			j++;
		}

		if (varname[j] == '\0')
		{
			for (; environ[i] != NULL; i++)
			{
				environ[i] = environ[i + 1];
			}

			return (0);
		}
	}

	return (-1);
}
