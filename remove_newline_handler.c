#include "shell.h"

/**
 * remove_new_line - Removes a new line character from string
 * @str: The string
 *
 * Return: The string without a new line character
 */
char *remove_new_line(char *str)
{
	char *result = NULL;
	int i = 0, len = 0;

	if (!str)
		return (NULL);

	while (str[len] != '\0')
		len++;

	result = malloc(sizeof(char) * len);
	if (!result)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		if (str[i] == '\n')
			result[i] = '\0';
		else
			result[i] = str[i];
	}
	result[i] = '\0';

	return (result);
}

