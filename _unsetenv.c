#include "shell.h"

int _unsetenv(char *_varname)
{
    int i, j;
    extern char **environ;

    for (i = 0; environ[i] != NULL; i++)
    {
        j = 0;
        for (; _varname[j] != '\0' && _varname[j] == environ[i][j];)
        {
            j++;
        }
        if (_varname[j] == '\0')
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
