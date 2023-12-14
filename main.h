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

#define MAX_ARGS 1024

void prompt_user(void);

int _putchar(char c);

int _strlen(char *s);

void exec_cmd(char **command);

char *read_command_line(void);

char **parse_command_with_args(const char *command);

void free_args(char **args);

void exit_simple_shell();

char *handle_path(const char *command);

int _strcmp(char *s1, char *s2);

#endif /* MAIN_h */
