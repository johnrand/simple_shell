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
	char *path;

	if (args[0] == NULL)/*if no command is entered */
	{
		return;
	}
	if (_strcmp(args[0], "exit") == 0)/* check for builtin exit */
	{
		free_args(args);
		exit_simple_shell();
	}
	path = handle_path(args[0]);
	if (path != NULL)/* check if command is in PATH */
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(path, args, environ) == -1)/* execute using execve */
			{
				perror("failed to execute command");
				exit(EXIT_FAILURE);
			}
		} else if (pid < 0)
		{
			perror("error creating child process");
		} else
		{
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		free(path);
	} else
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
	}
}
