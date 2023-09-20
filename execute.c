#include "shell.h"

/**
 * execute -function that executes commands
 * @command: command passed
 * @args: argument count
 * Return: void
 */

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
		if (execvp(command, args) == -1)
			perror("execve failed");
			exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}
