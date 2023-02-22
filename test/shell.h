#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

char* _getline(void);
char* _strtok(char *str, const char *delim);
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
char *_getenv(const char *name);
int _setenv(const char *_varname, const char *_varvalue, int overwrite);
int _unsetenv(char *_varname);
int _putenv(char *s);

#endif
