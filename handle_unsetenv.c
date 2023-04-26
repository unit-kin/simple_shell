#include "shell.h"

/**
 * handle_unsetenv - Removes an environment variable
 *
 * @cmd_args: An array of strings containing the command and its arguments
 *
 * Return: None
 */
void handle_unsetenv(char **cmd_args)
{
	if (cmd_args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;
	}

	if (unsetenv(cmd_args[1]) != 0)
	{
		perror("unsetenv");
	}
}
