#include "shell.h"

/**
 * free_env - Frees an environment variable
 * @env_var: The environment variable to free
 *
 * Return: void
 */
void free_env(char *env_var)
{
	if (env_var)
		free(env_var);
}

/**
 * free_tokens - Frees an array of tokens
 * @tokens: The array of tokens to free
 *
 * Return: void
 */
void free_tokens(char **tokens)
{
	char **temp = tokens;

	if (tokens)
	{
		while (*tokens)
		{
			free(*tokens);
			tokens++;
		}
		free(temp);
	}
}

