#include "shell.h"

/**
 * main - Simple Shell (#cisfun$)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: NULL
 */

char *_getenv(const char *name)
{
    int i, j;
    extern char **environ;

    for (i = 0; environ[i] != NULL; i++)
    {
        j = 0;

        while (name[j] != '\0' && name[j] == environ[i][j])
        {
            j++;
        }
      
        while (name[j] == '\0' && environ[i][j] == '=')
        {
            return (&environ[i][j + 1]);
        }
    }

    return (NULL);
}
