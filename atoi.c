#include "shell.h"
#include <limits.h>

/**
 * string_to_int - Converts a string to an integer
 * @str: The string to convert
 *
 * Return: The integer value of the string, or 0 if string = invalid integer
 */
int string_to_int(char *str)
{
	int res = 0;
	int i, digit;

	for (i = 0; str[i]; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);

		digit = str[i] - '0';
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10))
			return (0);

		res = res * 10 + digit;
	}

	return (res);
}

