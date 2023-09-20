#ifndef SHELL_H
#define SHELL_H

/** HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#define MAX_COMMAND 10

extern char **environ;

int findpath(char *command);
void print_env();
int display();
void execute(char *command, char *args[]);
#endif
