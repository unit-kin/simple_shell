#include "shell.h"

/**
 * remove_character - Removes a specified character from string
 * @string: The string
 *
 * Return: The modified string
 */
char *remove_character(char *string)
{
	int i = 0, j = 0;

	while (string[i])
	{
		if (string[i] != '\n')
			string[j++] = string[i];
		i++;
	}

	string[j] = '\0';
	return (string);
}
