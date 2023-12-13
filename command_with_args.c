#include "main.h"

/**
 * parse_command_with_args - takes command with its argument
 * @command: the command to be parsed
 *
 * Return: the args
 */

char **parse_command_with_args(const char *command)
{
	int arg_count = 0;
	char *token;
	char *line_copy;
	char **args = malloc((MAX_ARGS + 1) * sizeof(char *));

	if (args == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	/* copy command line read */
	line_copy = strdup(command);

	if (line_copy == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	/* Tokenize the command line into arguments */
	token = strtok(line_copy, " \t\n");

	while (token != NULL && arg_count < MAX_ARGS)
	{
		args[arg_count] = strdup(token);  /* Create a copy of each argument */
		if (args[arg_count] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " \t\n");
		arg_count++;
	}

	args[arg_count] = NULL;  /* Null-terminate the array of arguments */
	free(line_copy);

	return (args);
}
