#include "shell.h"

/**
 * handle_builtin - Execute built-in commands
 * @cmd_args: Null terminated array of strings
 *
 * Return: Nothing
 */
void handle_builtin(char **cmd_args)
{
	if (strcmp(cmd_args[0], "exit") == 0)
	{
		if (cmd_args[1] != NULL)
		{
			int status = atoi(cmd_args[1]);

			exit(status);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
}
