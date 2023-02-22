#include "shell.h"


/**
 * main - Entry point for the shell
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Return: Always returns 0
 */


int main()
{
  char *cmd = NULL;
    int i = 0;
    char *arr[80];
    char s[80];
    char *token;
    char *oldpwd = NULL;
    char *path;
    char *env;
    char buffer[80];
    char *temp;

    while (1)
    {
        if (write(STDOUT_FILENO, "#cisfun$ ", 9) == -1)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
        cmd = _getline();
        if (feof(stdin))
        {
          break;
        }
        token = _strtok(cmd, " \n");
        while (token != NULL)
        {
            arr[i] = token;
            i++;
            token = _strtok(NULL, " \n");
        }
        arr[i] = NULL;

        if (i > 0)
        {
            if (_strcmp(arr[0], "exit") == 0)
            {
                free(cmd);
                exit(0);
            }
            else if (_strcmp(arr[0], "cd") == 0)
       {
           if (arr[1] == NULL)
           {
          const char* home = getenv("HOME");
          if (home == NULL)
           {
            fprintf(stderr, "cd: HOME not set\n");
            return 1;
           }

          if (oldpwd != NULL)
          {
            free(oldpwd);
            oldpwd = NULL;
          }

         oldpwd = getcwd(NULL, 0);
         if (oldpwd == NULL)
         {
            perror("cd");
            return 1;
         }

        if (chdir(home) == -1)
        {
            perror("cd");
            free(oldpwd);
            oldpwd = NULL;
            return 1;
        }
    }
    else if (_strcmp(arr[1], "-") == 0)
    {
        if (oldpwd == NULL)
        {
            fprintf(stderr, "cd: OLDPWD not set\n");
            return 1;
        }

        temp = getcwd(NULL, 0);
        if (temp == NULL)
        {
            perror("cd");
            return 1;
        }

        if (chdir(oldpwd) == -1)
        {
            perror("cd");
            free(temp);
            return 1;
        }

        free(oldpwd);
        oldpwd = temp;
    }
    else
    {
        if (oldpwd != NULL)
        {
            free(oldpwd);
            oldpwd = NULL;
        }

        oldpwd = getcwd(NULL, 0);
        if (oldpwd == NULL)
        {
            perror("cd");
            return 1;
        }

        if (chdir(arr[1]) == -1)
        {
            perror("cd");
            free(oldpwd);
            oldpwd = NULL;
            return 1;
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
                    env = _getenv("PATH");
                    path = _strtok(env, ":");

                    while (path != NULL)
                    {
                       
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
