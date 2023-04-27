#include "shell.h"
#include <stdlib.h>

/**
 * _getenv_value - Gets the value of an environment variable.
 *
 * @var_name: Name of the environment variable.
 *
 * Return: Value of the environment variable or NULL if the variable is not found.
 */
char *_getenv_value(const char *var_name)
{
	size_t var_len = _strlen((char *)var_name);
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp((char *)var_name, *env, var_len) == 0 && (*env)[var_len] == '=')
			return (&(*env)[var_len + 1]);
	}
	return (NULL);
}

