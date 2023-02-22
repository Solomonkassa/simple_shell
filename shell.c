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
  size_t size = 0;
  int i = 0;

  while (1)
    {
      printf("#cisfun$ ");
      
      if (getline(&cmd, &size, stdin) == -1) 
      {
        break;
      }

      char *token = strtok(cmd, "\n");
      char *args[] = {token, NULL};
      pid_t pid;
      pid = fork();

      if (pid == 0)
      {
        execve(token, args, environ);
        perror("./shell");
        exit (1);
      }
      else
      {
        waitpid(pid, NULL, 0);
      }
    }
  return (0);
}
