#include "shell.h"

/**
 * if_and - Runs a command with '&&' separator
 * @str: Command to run
 */
void if_and(char *str)
{
  
  char *args[1024];
  int i = 0;
  
  char *command = strtok(str, "&&");

    while (command != NULL)
    {
      args[i++] = command;
      command = strtok(NULL, "&&");
    }
    args[i] = NULL;
      
    int num_commands = i;
    int m = 0;

  for (i = 0; i < num_commands; i++)
    {
      if (args[i] != NULL)
      {
        m = execute_command(args[i]);
        if (m != 0)
        {
          break;
        }
      }
    }
      
}

/**
 * if_cmdseparator - Runs a command with ';' separator
 * @str: Command to run
 */
void if_cmdseparator(char *str)
{
  
  char *args[1024];
  int i = 0;
  
  char *command = strtok(str, ";");

    while (command != NULL)
    {
      args[i++] = command;
      command = strtok(NULL, ";");
    }
    args[i] = NULL;
      
    int num_commands = i;
    

  for (i = 0; i < num_commands; i++)
    {
      if (args[i] != NULL)
      {
         execute_command(args[i]);
      }
    }
      
}

/**
 * if_or - Runs a command with '||' separator
 * @str: Command to run
 */
void if_or(char *str)
{
  
  char *args[1024];
  int i = 0;
  
  char *command = strtok(str, "||");

    while (command != NULL)
    {
      args[i++] = command;
      command = strtok(NULL, "||");
    }
    args[i] = NULL;
      
    int num_commands = i;
    int m = 0;

  for (i = 0; i < num_commands; i++)
    {
      if (args[i] != NULL)
      {
        m = execute_command(args[i]);
        if (m == 0)
        {
          break;
        }
      }
    }
      
}

/**
 * execute_command - Executes a single command
 * @command: Command to execute
 *
 * Return: 0 on success, 1 on error
 */
int execute_command(char *command)
{
  char *args[1024];
  char *token = strtok(command, " \n");
  int i = 0, j = 0;

  while (token != NULL)
  {
    args[i++] = token;
    token = strtok(NULL, " \n");
  }

  args[i] = NULL;

  if (args[1] != NULL)
  {
    char *p = _strchr(args[1], '/');
    if (p != NULL)
    {
      int m = access(args[1], F_OK);
      if (m == -1)
      {
        perror(" ");
        return(1);
      }
    }
  }
  

  pid_t pid = fork();

  if (pid < 0)
  {
    perror("");
  }
  else if (pid == 0)
  {
    char *env = getenv("PATH");
    char *path = strtok(env, ":");

    while (path != NULL)
    {
      char buffer[100];
      snprintf(buffer, sizeof(buffer), "%s/%s", path, args[0]);
      execve(buffer, args, environ);
      path = strtok(NULL, ":");
    }
    exit (1);
  }
  else
    wait(NULL);
  return (0);
}

int main(int argc, char *argv[])
{
  char *cmd = NULL;
  size_t size = 0;
  char *args[1024];
  int i = 0;

  while (1)
  {

    write(STDOUT_FILENO, "#cisfun$ ", 9);
    if (getline(&cmd, &size, stdin) == -1)
    {
      break;
    }

    char *m = strstr(cmd, "&&");
    if (m != NULL)
    {
      if_and(cmd);
    }

    char *s = strstr(cmd, "||");
    if (s != NULL)
    {
      if_or(cmd);
    }

    char *q = strstr(cmd, ";");
    if (q != NULL)
    {
      if_cmdseparator(cmd);
    }

    if (m == NULL && s == NULL)
    {
      execute_command(cmd);
    }

    }
  free(cmd);
  return 0;

}
