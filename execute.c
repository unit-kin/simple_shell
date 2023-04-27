#include "shell.h"

void _perror(char *prog, char *command);

/**
 * execute - Executes an array of arguments
 *
 * @argv: Array of arguments
 * @env: Array of environment variables
 * @prog: Main program name
 */
void execute(char **argv, char **env, char *prog)
{
	pid_t child;
	int status;
	char *arg;
	struct stat st;

	if (stat(argv[0], &st) == 0) {
		child = fork();
	}
	else {
		arg = malloc(_strlen(argv[0]) + 6);
		if (arg == NULL)
			return;
		arg = _strcpy(arg, "/bin/");
		arg = _strcat(arg, argv[0]);
		if (stat(arg, &st) == 0) {
			argv[0] = arg;
			child = fork();
		}
		else {
			_perror(prog, argv[0]);
			return;
		}
	}
	if (child == 0) {
		if ((execve(argv[0], argv, env) == -1)) {
			_perror(prog, argv[0]);
			return;
		}
		free(arg);
	}
	else if (child == -1) {
		free(arg);
		perror("Error:");
		return;
	}
	else {
		wait(&status);
		free(arg);
	}
}

/**
 * _perror - Prints sh error
 *
 * @prog: Program name
 * @command: Command name
 */
void _perror(char *prog, char *command)
{
	print_strings(
			NULL,
			4,
			prog,
			": 1: ",
			command,
			": not found"
		     );
}

