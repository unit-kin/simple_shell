#include "shell.h"

/**
 * _print_env - Prints the environment built-in
 *
 * Return: Nothing to returns
 */
void _print_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

