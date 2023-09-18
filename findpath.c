#include "shell.h"

int findpath(char* command)
{
	char *env_path = getenv("PATH");
	if (env_path == NULL)
	{
		perror("getenv failed");
		return 0;
	}
	char* path_copy = strdup(env_path);

	char* piece = strtok(path_copy, ":");
	while (piece != NULL)
	{
		char *full_path = malloc(strlen(piece) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc failed");
			free(path_copy);
			return (0);
		}
		snprintf(full_path, strlen(piece) + strlen(command) + 2, "%s/%s", piece, command);
		printf("%s\n", full_path);
		if (access(full_path, X_OK) == 0)
		{
			free(full_path);
			free(path_copy);
			return 1;
		}
		free(full_path);
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
