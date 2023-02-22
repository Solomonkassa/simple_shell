#include "shell.h"


#define MAX_ALIAS 100
#define MAX_CMD_LEN 100

typedef struct {
    char* name;
    char* value;
} Alias;

Alias aliases[MAX_ALIAS];
int num_aliases = 0;

/**
 * print_aliases - Prints all aliases
 */
void print_aliases() 
{
    for (int i = 0; i < num_aliases; i++) 
    {
        printf("%s='%s'\n", aliases[i].name, aliases[i].value);
    }
}

/**
 * print_alias - Prints an alias with the given name
 * @name: The name of the alias to print
 */
void print_alias(char* name) 
{
    for (int i = 0; i < num_aliases; i++) 
    {
        if (strcmp(aliases[i].name, name) == 0) 
        {
            printf("%s='%s'\n", aliases[i].name, aliases[i].value);
            return;
        }
    }
    fprintf(stderr, "alias: %s: not found\n", name);
}

/**
 * set_alias - Sets an alias with the given name and value
 * @name: The name of the alias to set
 * @value: The value of the alias to set
 */
void set_alias(char* name, char* value) 
{
    for (int i = 0; i < num_aliases; i++) 
    {
        if (strcmp(aliases[i].name, name) == 0) 
        {
            free(aliases[i].value);
            aliases[i].value = strdup(value);
            return;
        }
    }
    if (num_aliases >= MAX_ALIAS) 
    {
        fprintf(stderr, "alias: too many aliases defined\n");
        return;
    }
    aliases[num_aliases].name = strdup(name);
    aliases[num_aliases].value = strdup(value);
    num_aliases++;
}

/**
 * main - The entry point of the shell program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
  char *cmd = NULL;
  int i = 0, j = 0;
  char *arr[80];
  char *token;
  char *buffer2;
  char s[80];
  
  while (1)
  {
    write(STDOUT_FILENO, "#cisfun$ ", 9);
    cmd = _getline();
    
    token = _strtok(cmd, " \n");
    while (token != NULL)
    {
      arr[i] = token;
      i++;
      token = _strtok(NULL, " \n");
    }
    arr[i] = NULL;
    int l = i;
    
    if (i > 0)   //alias l
    {
      if (_strcmp(arr[0], "exit") == 0)
      {
        free(cmd);
        exit(0);
      }
      else if (_strcmp(arr[0], "alias") == 0)
      {
        if (l == 1) 
        {
          print_aliases();
          return (0);
        }
        for (int i = 1; i < l; i++) 
        {
        char* arg = arr[i];
        char* equals = strchr(arg, '=');
        if (equals == NULL) 
        {
            print_alias(arg);
        } else 
        {
            *equals = '\0';
            set_alias(arg, equals+1);
        }
    }
      }
      else if (_strcmp(arr[0], "pwd") == 0)
      {
        if (getcwd(s, 80 * sizeof(char)) != NULL)
           {
           printf("%s\n", s);
           }
           else
           {
           perror(" ");
           }
      }
      else if (_strcmp(arr[0], "setenv") == 0)
      {
        if (i < 3) 
        {
          printf(" ");
        } 
        else 
        {
          _setenv(arr[1], arr[2], 1);
        }
      }
      else if (_strcmp(arr[0], "unsetenv") == 0)
      {
        if (i < 2)
        {
          printf(" "); 
        }
        else
        {
          _unsetenv(arr[1]);
        }
      }
      else
      {
        pid_t pid;
        pid = fork();

        if (pid == 0)
        {
          char *_env = _getenv("PATH");
          char *path = _strtok(_env, ":");

          while (path != NULL)
          {
            char buffer[80];
            snprintf(buffer, sizeof(buffer), "%s/%s", path, arr[0]);
            execve(buffer, arr, environ);
            path = _strtok(NULL, ":");
          }
          perror(" ");
          exit(1);
        }
        else
        {
          waitpid(pid, NULL, 0);
        }
      }
    }
   
    i = 0;
    free(cmd);
}
  
  return (0);
}
