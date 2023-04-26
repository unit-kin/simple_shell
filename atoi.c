#include "shell.h"
#include <limits.h>

/**
 * string_to_int - Converts a string to an integer
 *
 * @str: The string to convert
 *
 * Return: The integer value of the string, or 0 if the string is not a valid integer
 */
int string_to_int(char *str)
{
	int result = 0;
	int i;

	for (i = 0; str[i]; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return 0;
		}

		int digit = str[i] - '0';
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
		{
			return 0;
		}

		result = result * 10 + digit;
	}

	return result;
}

