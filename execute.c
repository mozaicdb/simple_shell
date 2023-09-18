#include "shell.h"

void execute(char *command, char *args[])
{
	int status;
	char *av[] = {NULL, NULL};

	pid_t my_pid = fork();

	if (my_pid == -1)
	{
		exit(EXIT_FAILURE);
	}
	else if (my_pid == 0)
	{
		char *envp[] = {NULL};
		av[0] = strdup(command);
		if (execvp(command, args) == -1)
			perror("execve failed");
		free(av[0]);
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
