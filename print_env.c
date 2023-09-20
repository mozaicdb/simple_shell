#include "shell.h"

/**
 * print_env - prints environment
 * Return: void
 */
void print_env()
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
