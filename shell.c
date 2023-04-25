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

	while (1) {
		/* Display the prompt */
		printf("cisfun$");

		/* Wait for user input */
		nread = getline(&line, &len, stdin);
		if (nread == -1) {
			/* End of file reached (Ctrl+D) */
			putchar('\n');
			exit(EXIT_SUCCESS);
		}

		/* Remove the trailing newline character */
		if (line[nread - 1] == '\n') {
			line[nread - 1] = '\0';
		}

		/* Fork a new process */
		child_pid = fork();

		if (child_pid == -1) {
			/* Error occurred */
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0) {
			/* Child process */

			/* Execute the command */
			if (execlp(line, line, NULL) == -1) {
				/* Error occurred */
				perror(line);
				exit(EXIT_FAILURE);
			}
		} else {
			/* Parent process */

			/* Wait for the child to complete */
			do {
				if (waitpid(child_pid, &status, WUNTRACED) == -1) {
					/* Error occurred */
					perror("waitpid");
					exit(EXIT_FAILURE);
				}
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
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
