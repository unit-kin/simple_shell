#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * split_line - Splits a string of words separated by spaces
 * @str: The string to split
 *
 * Return: An array of null-terminated strings or NULL if allocation fails
 */
char **split_line(char *str)
{
	char **arr;
	char *token, *s;
	int len = 0, i = 0;

	/* Check if string is NULL or empty */
	if (str == NULL || *str == '\0')
		return (NULL);

	/* Count the number of words */
	len++;
	s = str;
	while (*s)
	{
		if (*s == ' ' && *(s + 1) != ' ')
			len++;
		s++;
	}
	len++;

	/* Allocate memory for the array of strings */
	arr = malloc(sizeof(char *) * len);
	if (arr == NULL)
		return (NULL);

	/* Tokenize the string and store the words in the array */
	token = strtok(str, " ");
	while (token != NULL)
	{
		arr[i++] = token;
		token = strtok(NULL, " ");
	}
	arr[i] = NULL;

	return (arr);
}
