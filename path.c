#include "main.h"

/**
 * handle_path - sets the environments path
 *@command: command to be handled if in PATH
 * Return: void
 */

char *handle_path(const char *command)
{
	char *path, *token, *full_path, *path_copy;

	path = getenv("PATH");
	if (path == NULL || command == NULL)
	{
		return (NULL);
	}
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(path_copy, ":");
	full_path = NULL;
	while (token != NULL)
	{/* Construct the full path by appending the command to the directory */
		free(full_path);
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", token, command);
		/* Check if the file exists and is executable */
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
