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
<<<<<<< HEAD
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
=======
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("cisfun$");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			putchar('\n');
			exit(EXIT_SUCCESS);
		}

		if (line[nread - 1] == '\n')
		{
			line[nread - 1] = '\0';
		}

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{

			if (execlp(line, line, NULL) == -1)
			{
				perror(line);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			do
			{
				if (waitpid(child_pid, &status, WUNTRACED) == -1)
				{
					perror("waitpid");
					exit(EXIT_FAILURE);
				}
			}
			while (!WIFEXITED(status) && !WIFSIGNALED(status));
>>>>>>> 36abb189721558b4515b6580dcc046b297d23644
		}
		execute(args, envp, argv[0]);
		free(args);
	}
	return (0);
}

