#include "shell.h"

/**
 * find_env_var - Finds an environment variable
 * @name: The name of the environment variable
 *
 * Return: A pointer to the environment variable value or NULL if not found
 */
char *find_env_var(const char *name)
{
	int i = 0;
	char *env_var = NULL;

	while (environ[i])
	{
		if (_strncmp(name, environ[i], get_string_length(name)) == 0)
		{
			env_var = _strdup(environ[i]);
			while (*env_var != '=')
				env_var++;
			++env_var;
			return (env_var);
		}
		i++;
	}

	return (NULL);
}
