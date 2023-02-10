<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
  </head>
  <body>
    <h1>Simple Shell Project</h1>
    <h2>Overview</h2>
    <p>
      This project is a simple implementation of a shell in C language. The shell allows the user to execute basic commands such as ls, pwd, and cd. Additionally, the shell supports I/O redirection and piping.
    </p>
    <h2>Functionality</h2>
    <p>
      The shell takes in commands from the user and executes them. It supports the execution of basic shell commands and can also handle I/O redirection and piping. The shell continues to run until the user types in the "exit" command.
    </p>
    <h2>Usage</h2>
    <p>
      To compile the shell, run the following command in the terminal:
    </p>
    <pre>
     gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
    </pre>
    <p>
      Then, execute the shell with the following command:
    </p>
    <pre>
      ./shell
    </pre>
    <h2>Contributors</h2>
    <ul>
      <li> <a href="https://github.com/Solomonkassa">Solomon Kassa</a></li>
      <li><a href="https://github.com/Newi-M">Nawwal Ismael</a></li>
    </ul>
  </body>
</html>
