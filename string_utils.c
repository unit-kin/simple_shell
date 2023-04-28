#include "shell.h"

/**
 * concatenate_strings - Concatenates two strings
 * @destination: The destination string
 * @source: The source string
 *
 * Return: A pointer to the resulting string destination
 */
char *concatenate_strings(char *destination, char *source)
{
	int dest_len = 0, i = 0;

	while (destination[dest_len])
		dest_len++;

	for (i = 0; source[i] != '\0'; i++)
	{
		destination[dest_len] = source[i];
		dest_len++;
	}

	destination[dest_len] = '\0';
	return (destination);
}

/**
 * get_string_length - Counts the length of a string
 * @string: The string to count
 *
 * Return: The length of the string
 */
int get_string_length(const char *string)
{
	int length = 0;

	while (string[length])
		length++;

	return (length);
}

/**
 * compare_strings - Compares two strings
 * @string1: The first string to compare
 * @string2: The second string to compare
 *
 * Return: integer value
 */
int compare_strings(char *string1, char *string2)
{
	int length1 = 0, length2 = 0, position = 0, difference = 0, limit = 0;

	length1 = get_string_length(string1);
	length2 = get_string_length(string2);

	if (length1 <= length2)
		limit = length1;
	else
		limit = length2;

	while (position <= limit)
	{
		if (string1[position] == string2[position])
		{
			position++;
			continue;
		}
		else
		{
			difference = string1[position] - string2[position];
			break;
		}

		position++;
	}

	return (difference);
}

/**
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	char *dup_str;
	size_t len, i;

	if (!str)
		return (NULL);

	len = get_string_length(str);

	dup_str = malloc(sizeof(char) * (len + 1));
	if (!dup_str)
		return (NULL);

	for (i = 0; i < len; i++)
		dup_str[i] = str[i];

	dup_str[len] = '\0';

	return (dup_str);
}

/**
 * _atoi - Convert a string to an integer.
 * @str: The pointer to convert
 *
 * Return: The integer value of the converted string
 */
int _atoi(char *str)
{
	int sign = 1, digit, result = 0;

	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		else if (*str >= '0' && *str <= '9')
		{
			digit = *str - '0';
			result = (result * 10) + digit;
		}
		else if (result > 0)
			break;
		str++;
	}

	return (sign * result);
}
