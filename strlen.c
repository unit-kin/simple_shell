#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string to compute
 *
 * Return: the length of the string
 */
int _strlen(char *a)
{
	int len = 0;

	/* Iterate through string until null byte is reached */
	while (a[len] != '\0')
	{
		len++;
	}

	return (len);
}

