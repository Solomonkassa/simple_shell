

                       _____ _   _ _____    ____    _  _____ _____ ____     ___  _____ 
                      |_   _| | | | ____|  / ___|  / \|_   _| ____/ ___|   / _ \|  ___|
                        | | | |_| |  _|   | |  _  / _ \ | | |  _| \___ \  | | | | |_   
                        | | |  _  | |___  | |_| |/ ___ \| | | |___ ___) | | |_| |  _|  
                        |_| |_| |_|_____|  \____/_/   \_\_| |_____|____/   \___/|_|    

                                       ____  _   _ _____ _     _     
                                      / ___|| | | | ____| |   | |    
                                      \___ \| |_| |  _| | |   | |    
                                       ___) |  _  | |___| |___| |___ 
                                      |____/|_| |_|_____|_____|_____|



# Simple shell 

## Overview
This project is a simple implementation of a shell in C language. A shell is a program that allows users to interact with the operating system by accepting user input in the form of commands and executing those commands. This shell allows the user to execute basic commands such as `ls`, `pwd`, and `cd`. Additionally, the shell supports I/O redirection and piping, which are advanced features of shells.

## Functionality
The shell takes in commands from the user and executes them. It reads user input from the command line and processes it to determine which command to run. The shell supports the execution of basic shell commands and can also handle I/O redirection and piping. I/O redirection allows users to redirect the input or output of a command to a file instead of the terminal. Piping allows users to chain multiple commands together, with the output of one command serving as the input of the next command.

The shell continues to run until the user types in the "exit" command. This means that the user can execute multiple commands in a single session, making the shell useful for batch processing or automation.

## Usage
To compile the shell, run the following command in the terminal:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

This command starts the shell and puts the user in interactive mode, allowing them to execute commands and see the output.



## Contributors
This project was created by:

- [Solomon Kassa](https://github.com/Solomonkassa)
- [Nawwal Ismael](https://github.com/Newi-M)

