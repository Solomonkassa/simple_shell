#include "shell.h"

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
    environ[i + 1] = 0;

    return (0);
}
