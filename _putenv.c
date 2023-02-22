#include "shell.h"

/**
 * _putenv - adds or modifies an environment variable
 * @s: the string containing the variable name and value
 * Return: 0 on success, -1 on failure
 */

int _putenv(char *s)
{
	int i = 0;
	char **env = environ;

	while (*env)
	{
		i++;
		env++;
	}

	environ[i] = s;
	environ[i + 1] = NULL;

	return (0);
}
