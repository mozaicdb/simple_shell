#include "shell.h"
/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argv;
	if (argc == 1)
		display();
	return (0);
}
