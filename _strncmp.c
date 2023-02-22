#include "shell.h"

/**
 * _strncmp - Compare two strings
 * @str1: first string to compare
 * @str2: second string to compare
 * @n: maximum number of characters to compare
 *
 * Return: The difference between the first two differing bytes, or 0 if they are
 * equal. If n is reached before the two strings are different, return 0.
 */
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

    if (n == 0)
        return (0);
    else
        return (*str1 - *str2);
}
