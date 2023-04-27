#include "shell.h"
#include <ctype.h>

/**
 * is_string_integer - Checks if a string can be converted to an integer
 *
 * @s: The string to check
 *
 * Return: Returns 1 if the string can be converted to an integer, 0 otherwise
 */
int is_string_integer(const char *s)
{
	if (!s || *s == '\0') {
		return 0;
	}

	for (; *s != '\0'; s++) {
		if (!isdigit(*s)) {
			return 0;
		}
	}

	return 1;
}

