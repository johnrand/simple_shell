#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* declare the external environment variable */
extern char **environ;

#define MAX_INPUT_SIZE 1024

void prompt_user(void);

int _putchar(char c);

int _strlen(char *s);

void exec_cmd(char *command);

char *read_command_line(void);

#endif /* MAIN_h */
