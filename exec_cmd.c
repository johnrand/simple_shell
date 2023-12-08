#include "main.h"

/**
 * exec_cmd - executes a command
 * description: takes command as argument and executes it
 * @command: command to be executed
 *
 * Return: void
 */
void exec_cmd(char *command)
{
	pid_t pid;
	int status;

	/* create a child process */
	pid = fork();
	if (pid == 0)
	{
		/* execute command by calling the execve system call */
		char **cmd_argv = malloc(sizeof(char *) * 2);

		if (cmd_argv == NULL)
		{
			perror("no command found");
			exit(EXIT_FAILURE);
		}
		cmd_argv[0] = command;
		cmd_argv[1] = NULL;
		if (execve(command, cmd_argv, environ) == -1)
		{
			perror("simple shell");
			exit(EXIT_FAILURE);
		}
		free(cmd_argv);
	}
	else if (pid < 0)
	{
		/* error creating child process */
		perror("error executing command");
	}
	else
	{
		/* wait for child to finish */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
