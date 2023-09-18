#include "shell.h"
/**
 * main - main shell function
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variable
 * Return: Always 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char *lineptr = NULL;
	size_t no = 0;
	ssize_t ret_val;
	char *args[MAX_COMMAND];
	size_t len;
	int i;
	char *token;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("Myshell> ");
		ret_val = getline(&lineptr, &no, stdin);
		if (ret_val == -1)
		{
			write(STDOUT_FILENO, "\n", 2);
			break;
		}
		len = strlen(lineptr);
		if (len > 0 && lineptr[len - 1] == '\n')
			lineptr[len - 1] = '\0';
		i = 0;
		token = strtok(lineptr, " ");
		while (token != NULL && i < MAX_COMMAND)
		{
			args[i++] = strdup(token);
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		if (i == 0)
			continue;
		if (findpath(args[0]))
			execute(args[0], args);
	}
	return (0);
}