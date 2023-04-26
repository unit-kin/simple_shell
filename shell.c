#include "shell.h"
#include <signal.h>

/**
 * main - Entry point for the shell program
 *
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 * @envp: Array of environment variables
 *
 * Return: Returns 0 (Always Success)
 */
int main(int argc __attribute__((unused)), char **argv, char **envp)
{
	char **args, *buffer = NULL;
	ssize_t n_read;
	size_t n = 0;
	int fd = STDIN_FILENO;

	buffer = NULL;
	while (1)
	{
		_puts("cisfun$ ");
		fflush(stdout);
		n_read = _getline(&buffer, &n, fd);
		if (n_read <= 0)
		{
			free(buffer);
			exit_shell(argv[0], NULL, buffer);
		}
		buffer[n_read - 1] = '\0';
		args = split_line(buffer);
		if (_strcmp(args[0], "exit") == 0)
		{
			if (exit_shell(argv[0], args, buffer) == 1)
				continue;
		}
		execute(args, envp, argv[0]);
		free(args);
	}
	return (0);
}

