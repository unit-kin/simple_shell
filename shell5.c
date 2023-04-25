#include "shell.h"

/**
 * env_shell - Print the current environment
 */
void env_shell(void)
{
	char **env = environ;
	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

