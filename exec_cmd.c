#include "main.h"

/**
 * exec_cmd - executes a command
 * description: takes command as argument and executes it
 * @args: command to be executed
 *
 * Return: void
 */

void exec_cmd(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)/*if no command is entered */
	{
		return;
	}
	if (_strcmp(args[0], "exit") == 0)/* check for builtin exit */
	{
		free_args(args);
		exit_simple_shell();
	}
	if (access(args[0], X_OK) == -1)/* check if command is in PATH */
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return;
	}
	/* create a child process */
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)/* execute using execve */
		{
			perror("failed to execute command");
			exit(EXIT_FAILURE);
		}
	} else if (pid < 0)
	{
		perror("error creating child process");
	} else
	{
		/* wait for child to finish */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
