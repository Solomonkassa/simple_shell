#include "shell.h"

char* _strtok(char* str, const char* delim)
{
    static char* last;
    char* token;

    if (str != NULL)
    {
        last = str;
    }

    if (*last == '\0')
    {
        return NULL;
    }

    token = last;

    while (*last != '\0')
    {
        const char* d = delim;
        for (const char *d = delim; *d != '\0'; d++)
        {
            if (*last == *d)
            {
                *last = '\0';
                last++;
                return (token);
            }
        }
        
        last++;
    }
    
    return (token);
}
