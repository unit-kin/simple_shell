#include "shell.h"

/**
 * free_env_variable - Frees a string allocated as an environment variable
 * @env_var: The environment variable to free
 *
 * Return: Nothing
 */
void free_env_variable(char *env_var)
{
	int i;

	for (i = 4; i >= 0; i--)
		env_var--;

	free(env_var);
}

/**
 * free_tokens - Frees memory allocated for an array of tokens
 * @tokens: The array of tokens to free
 *
 * Return: Nothing
 */
void free_tokens(char **tokens)
{
	char **temp = tokens;

	if (tokens)
	{
		while (*tokens)
			free(*tokens++);

		free(temp);
	}
}
