/* Simple Shell */

#include "main.h"

/**
 * main - Entry point of the program
 *
 * Return: Always (0) succes
 */

int main(void)
{
	char *line_to_read;
	char **args;
	int status = 1; /* default for loop continuation */

	do {
		prompt_user();
		line_to_read = read_command_line();

		/* EOF handling */
		if (line_to_read == NULL)
		{
			printf("\n");
			break;
		}

		/* remove newline character */
		line_to_read[strcspn(line_to_read, "\n")] = '\0';

		args = parse_command_with_args(line_to_read);
		/* execute command */
		if (args != NULL && args[0] != NULL)
		{
			exec_cmd(args);
		}

		free_args(args);
	} while (status);

	return (EXIT_SUCCESS);
}
