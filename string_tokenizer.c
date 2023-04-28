#include "shell.h"

/**
 * split_string - Splits a string into an array of substrings
 * @string: The string to split
 * @delimiter: The delimiter used to split the string
 * @num_tokens: Pointer to an integer to store the number of tokens
 *
 * Return: An array of substrings
 */
char **split_string(char *string, char *delimiter, int *num_tokens)
{
	char **tokens = NULL, *token = NULL, *temp_str = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * (*num_tokens + 1));
	if (!tokens)
		return (NULL);

	string = remove_character(string);
	temp_str = _strdup(string);
	token = strtok(temp_str, delimiter);

	while (token)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}

	tokens[i] = NULL;
	free(temp_str);
	return (tokens);
}
