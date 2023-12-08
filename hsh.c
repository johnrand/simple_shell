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

		/* execute command */
		if (_strlen(line_to_read) > 0)
		{
			exec_cmd(line_to_read);
		}

		free(line_to_read);
	} while (status);

	return (EXIT_SUCCESS);
}
