#include "shell.h"

/**
 * main - Entry point of the shell program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * @env: Array of environment variable strings
 *
 * Return: Always 0
 */
int main(int argc, char *argv[], char **env)
{
	(void)argc;

	prompt(argv, env);

	return (0);
}
