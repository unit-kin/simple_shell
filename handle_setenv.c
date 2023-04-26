#include "shell.h"

/**
 * handle_setenv - Initializes or modify environment
 *
 * @cmd_args: An array of strings containing the command and its arguments
 *
 * Return: None
 */
void handle_setenv(char **cmd_args)
{
	if (cmd_args[1] == NULL || cmd_args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}

	if (setenv(cmd_args[1], cmd_args[2], 1) != 0)
	{
		perror("setenv");
	}
}
