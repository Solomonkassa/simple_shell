#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE 1024
#define MAX_ARGS 80

extern char **environ;

char *_getline(void);
char *_strtok(char *str, const char *delim);
int _strcmp(const char *str1, const char *str2);
char *_getenv(const char *name);
int _setenv(const char *varname, const char *varvalue, int overwrite);
int _strlen(const char *str);
int _unsetenv(char *varname);
int _putenv(char *s);


#endif
