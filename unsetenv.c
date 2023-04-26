#include "shell.h"

/**
 * unset_env - Remove an environment variable
 * @env: Array of strings containing the environment variables
 * @name: Name of the environment variable to unset
 *
 * Return: 0 on success, or -1 on failure
 */
int unset_env(char **env, char *name)
{
	int i, j, len;

	len = strlen(name);
	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			free(env[i]);

			for (j = i; env[j + 1]; j++)
				env[j] = env[j + 1];

			env[j] = NULL;
			return (0);
		}
	}

	return (-1);
}
