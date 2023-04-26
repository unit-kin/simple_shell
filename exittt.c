#include "shell.h"

/**
 * exit_shell - Exits the shell
 *
 * @args: Contains the arguments passed to the exit command
 * @shell_name: Name of the shell program
 * @buffer: Buffer containing user input
 *
 * Return: Always 1 (Success)
 */
int exit_shell(char **args, char *shell_name, char *buffer)
{
	int status;

	if (args[1] == NULL)
	{
		free(buffer);
		free(args);
		exit(0);
	}
	else if (is_integer(args[1]) == 1)
	{
		status = _atoi(args[1]);
		free(buffer);
		free(args);
		exit(status);
	}
	else
	{
		print_strings(NULL, 5, shell_name, ": 1: ", args[0], ": Illegal number: ", args[1]);
		free(args);
		return (1);
	}
}

/**
 * is_integer - Checks if a string is an integer
 *
 * @str: String to check
 *
 * Return: 1 if @str is an integer, 0 otherwise
 */
int is_integer(char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	for (; *str; str++)
	{
		if (*str < '0' || *str > '9')
			return (0);
	}

	return (1);
}

