#include "shell.h"

/**
 * _strcmp - compares two strings
 * @str1: first string to compare
 * @str2: second string to compare
 *
 * Return: an integer less than, equal to, or greater than zero if str1 is
 * found, respectively, to be less than, to match, or be greater than str2.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}
