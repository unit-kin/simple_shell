#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char *line = NULL;
	size_t line_size = 0;
	ssize_t line_len = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		line_len = getline(&line, &line_size, stdin);
		if (line_len == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove the newline character from the end of the line */
		line[line_len - 1] = '\0';

		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			/* Child process */

			/* Execute the command using execve */
			char *args[] = {line, NULL};

			execve(line, args, NULL);

			/* If execve returns, an error occurred */
			perror(line);
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Parent process */

			/* Wait for the child process to complete */
			int status;

			waitpid(child_pid, &status, 0);

			if (WIFEXITED(status))
			{
				/* Child process exited normally */
				int exit_status = WEXITSTATUS(status);

				printf("Child process exited with status %d\n", exit_status);
			}
			else if (WIFSIGNALED(status))
			{
				/* Child process terminated by a signal */
				int signal_number = WTERMSIG(status);

				printf("Child process terminated by signal %d\n", signal_number);
			}
		}
	}

	free(line);
	return (0);
}

