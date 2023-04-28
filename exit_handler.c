#include "shell.h"

/**
 * handle_exit - Handles the "exit" command.
 *
 * @u_tokens: An array of strings containing the parsed user input.
 * @line: A pointer to the user input.
 *
 * Return: Nothing.
 */
void handle_exit(char **u_tokens, char *line)
{
	int status = 0;

	if (u_tokens[1] == NULL || (!compare_strings(u_tokens[1], "0")))
		goto exit;

	status = _atoi(u_tokens[1]);
	if (status != 0)
		goto exit;

	_puts("exit: Illegal number: ");
	_puts(u_tokens[1]);
	_puts("\n");
	status = 2;

 exit:
	free_tokens(u_tokens);
	free(line);
	exit(status);
}
