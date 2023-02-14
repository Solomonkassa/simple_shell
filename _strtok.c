#include "main.h"


char *_strtok(char *str, const char *delim)
{
    static char *last;
    char *nextp;

    if (str != NULL)
    {
        last = str;
    }

    if (*last == '\0')
    {
        return NULL;
    }

    char *p = strpbrk(last, delim);

    if (p == NULL)
    {
        nextp = strchr(last, '\0');
    }
    else
    {
        *p = '\0';
        nextp = p + 1;
    }

    char *token = last;
    last = nextp;

    return token;
}
