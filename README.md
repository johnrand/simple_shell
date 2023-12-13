# Simple Shell

A basic UNIX command line interpreter (shell) written in C.

## Features

- Displays a prompt and waits for the user to type a command.
- The prompt is displayed again each time a command has been executed.
- Handles simple command lines consisting of only one word.
- Prints an error message and displays the prompt again if an executable cannot be found.
- Handles the "end of file" condition (Ctrl+D).
- Has built in exit
- Doesn't call fork if command is not in PATH
- Handles commands with arguments
