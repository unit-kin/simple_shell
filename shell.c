#include "shell.h"

/**
 * getline - Wait for user input
 * prompt - Display a prompt and wait for user input.
 */
void prompt(void)
{
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
		}
	}
}

/**
 * main - Entry point.
 *
 * Return: Always 0.
 */
int main(void)
{
	prompt();
	return (0);
}
