#include "shell.h"

int _setenv(const char *_varname, const char *_varvalue, int overwrite)
{
    if (_varname == NULL || _varname[0] == '\0' || strchr(_varname,'=') != NULL)
    {
        return (-1);
    }
  
    char *existingvalue = _getenv(_varname);

    if (existingvalue != NULL && !overwrite)
    {
        return (-1);
    }

    size_t size = _strlen(_varname) + _strlen(_varvalue) + 2;

    char *p = malloc(sizeof(char) * size);
    if (p == NULL)
    {
        return (-1);
    }

    snprintf(p, size, "%s=%s", _varname, _varvalue);

    int n = _putenv(p);
    if (n != 0)
    {
        free(p);
        return (-1);
    }

    return (0);
}
