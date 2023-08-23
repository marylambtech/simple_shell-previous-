#include "shell.h"
#include <sys/wait.h>
/**
* prompt: This function display a prompt to the user and wait for input
* @argv: Argument 1
* @env: environment variable
*/
void prompt(char **argv, char **env)
{
	char **lineptr = NULL;
	int e, status;
size_t n = 0;
	ssize_t n_char;
	char *argv[] = (NULL, NULL)
	pid_t chpid;  child pid

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf(“simple_shell$  “);

		n_char = getline(&lineptr, &n, stdin);
		if (n_char == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
e = 0;
while (lineptr[e])
{
	if (lineptr[e] == “\n”)
		lineptr[e] = 0;
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
		printf("%s: No such file or directory\n", av[0]);
}
else
	wait(&status);
	}
}
