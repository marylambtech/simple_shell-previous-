#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * prompt - Simple Shell Command Line
 * @argv: Argument 1
 * @env: environment variable
 */
void prompt(char **argv, char **env)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t n_char;
	int e, status;
	pid_t chpid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		    printf("cisfun$ ");

	n_char = getline(&lineptr, &n, stdin);
	if (n_char == -1)
	{
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	e = 0;
	while (lineptr[e])
	{
		if (lineptr[e] == '\n')
			lineptr[e] = '\0';
		e++;
	}
	argv[0] = lineptr;
	chpid = fork();
	if (chpid == -1)
	{
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	if (chpid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		    printf("%s: No such file or directory\n", argv[0]);
	}
	else
		wait(&status);
	}
}
