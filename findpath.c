#include "shell.h"

/**
 * findpath - finds the path variable
 * @command: command passed
 * Return: Always 0
 */

int findpath(char* command)
{
	char *env_path = getenv("PATH");
	char *full_path;
	char *piece;
	char *path_copy;

	if (env_path == NULL)
	{
		perror("getenv failed");
		return 0;
	}
	path_copy = strdup(env_path);

	piece = strtok(path_copy, ":");
	while (piece != NULL)
	{
		full_path = malloc(strlen(piece) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc failed");
			free(path_copy);
			return (0);
		}
		snprintf(full_path, strlen(piece) + strlen(command) + 2, "%s/%s", piece, command);
		if (access(full_path, X_OK) == 0)
		{
			free(full_path);
			free(path_copy);
			return 1;
		}
		else
		{
			free(full_path);
		}
		piece = strtok(NULL, ":");
	}
	if (access(command, X_OK) == 0)
	{
		free(path_copy);
		return 1;
	}
	free(path_copy);
	return 0;
}
