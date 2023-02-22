#include "shell.h"

/**
 * _setenv - Set the value of an environment variable
 * @varname: The name of the variable to set
 * @varvalue: The value to set the variable to
 * @overwrite: Whether to overwrite the variable if it already exists
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *varname, const char *varvalue, int overwrite)
{
	if (varname == NULL || varname[0] == '\0' || strchr(varname, '=') != NULL)
		return (-1);

	char *existing_value = _getenv(varname);

	if (existing_value != NULL && !overwrite)
		return (-1);

	size_t size = _strlen(varname) + _strlen(varvalue) + 2;
	char *p = malloc(sizeof(char) * size);

	if (p == NULL)
		return (-1);

	snprintf(p, size, "%s=%s", varname, varvalue);

	int n = _putenv(p);

	if (n != 0)
	{
		free(p);
		return (-1);
	}

	return (0);
}

