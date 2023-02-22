#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE 80
#define MAX_ARGS 20

extern char **environ;
int last_exit_code;

char* _getline(void);
char* _strtok(char *str, const char *delim);
int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
char *_getenv(const char *name);
int _setenv(const char *_varname, const char *_varvalue, int overwrite);
int _unsetenv(char *_varname);
int _putenv(char *s);

void read_command(char *line, char **args);
void execute_command(char **args);


#endif
