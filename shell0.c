#include "shell.h"

/**
 * main - Simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		prompt();
		line = read_line();
		args = parse_args(line);
		status = execute_command(args);
		free(line);
		free(args);
	} while (status);

	exit_shell(); /* ALVIN KANG'ARA AND ARON MANG'ATI */

	return (0);
}

