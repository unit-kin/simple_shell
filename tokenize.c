#include "shell.h"

/**
 * tokenize - Tokenize a string based on a delimiter
 * @str: String to tokenize
 * @delimiter: Delimiter to use for tokenization
 * @num_tokens: Pointer to integer to store the number of tokens
 *
 * Return: Array of pointers to the tokens
 */
char **tokenize(char *str, const char *delimiter, int *num_tokens)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	*num_tokens = 0;

	tokens = malloc(sizeof(char *));

	if (!tokens)
		return (NULL);

	token = strtok(str, delimiter);

	while (token)
	{
		tokens = realloc(tokens, sizeof(char *) * (*num_tokens + 1));
		if (!tokens)
			return (NULL);

		tokens[i] = strdup(token);

		if (!tokens[i])
			return (NULL);

		(*num_tokens)++;
		i++;

		token = strtok(NULL, delimiter);
	}

	tokens = realloc(tokens, sizeof(char *) * (*num_tokens + 1));

	if (!tokens)
		return (NULL);

	tokens[i] = NULL;

	return (tokens);
}
