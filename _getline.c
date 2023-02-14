#include "main.h"

char *_getline()
{
    char c;
    int i = 0;
    int size = 80;

    char *buffer = malloc(size * sizeof(char));
    if (buffer == NULL)
    {
        return NULL;
    }

    while ((c = getchar()) != '\n' && c != EOF)
    {
        buffer[i++] = c;

        if (i == size)
        {
            size *= 2;
            char *temp = realloc(buffer, size * sizeof(char));

            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }
    }
    buffer[i] = '\0';
    return buffer;
}
