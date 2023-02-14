#include "main.h"

int _strncmp(const char *str1, const char *str2, size_t n) 
{
    while (*str1 && *str2 && n)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
        n--;
    }
    if (n == 0) return 0;
    else return (*str1 - *str2);
}
