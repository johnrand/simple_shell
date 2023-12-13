#include "main.h"

/**
 * prompt_user - the function displays a prompt for user to input commands.
 * Description: takes no arguments
 *
 * Return: void
 */

void prompt_user(void)
{
	char *prompt = "R&JShell:$ ";
	size_t length_of_prompt = _strlen(prompt);
	size_t i;

	for (i = 0; i < length_of_prompt; ++i)
	{
		_putchar(prompt[i]);
	}
	fflush(stdout);
}
