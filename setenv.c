#include "shell.h"

/**
 * set_env - Initialize or modify environment variable
 * @env: Array of strings containing the environment variables
 * @name: Name of the environment variable to set
 * @value: Value to set the environment variable to
 *
 * Return: 0 on success, or -1 on failure
 */
int set_env(char **env, char *name, char *value)
{
	char *new_var, *temp;
	int i, len;

	for (i = 0; env[i]; i++)
	{
		len = strlen(name);
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			temp = strdup(env[i] + len + 1);
			if (!temp)
				return (-1);

			free(env[i]);
			new_var = strcat(strcat(name, "="), value);
			if (!new_var)
				return (-1);

			env[i] = strcat(new_var, temp);
			if (!env[i])
				return (-1);

			free(temp);
			free(new_var);
			return (0);
		}
	}

	new_var = strcat(strcat(name, "="), value);
	if (!new_var)
		return (-1);

	env[i] = new_var;
	env[i + 1] = NULL;

	return (0);
}
