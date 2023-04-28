#include "shell.h"

/**
 * _strncmp - Compares at most the first n bytes of two strings
 * @s1: The first string
 * @s2: The second string
 * @n: The maximum number of bytes to compare
 *
 * Return: integer value
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	if (i == n)
	{
		return (0);
	}

	if (s1[i])
	{
		return (1);
	}

	return (-1);
}

/**
 * _puts - Prints a string
 * @s: The string to print
 *
 * Return: Nothing
 */
void _puts(const char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}
	_putchar('\n');
}

/**
 * array_resize - Resizes the ptr that was previously allocated
 * @array: The pointer previously allocated
 * @old_len: The old length of the array
 * @new_len: The new length of the array
 *
 * Return: A new pointer to the memory block allocated with the new size
 */
void *array_resize(void *array, size_t old_len, size_t new_len)
{
	char *new_array;
	size_t i;

	if (new_len == old_len)
		return (array);

	if (array == NULL)
	{
		new_array = malloc(new_len);

		if (new_array == NULL)
			return (NULL);

		return (new_array);
	}
	else
	{
		if (new_len == 0)
		{
			free(array);
			return (NULL);
		}
	}

	new_array = malloc(new_len);

	if (new_array == NULL)
		return (NULL);

	for (i = 0; i < old_len && i < new_len; i++)
	{
		new_array[i] = ((char *) array)[i];
	}

	free(array);
	return (new_array);
}

/**
 * _putchar - Writes a single character to stdout
 * @ch: The character to write
 *
 * Return: character written on success, otherwise EOF is returned
 */
int _putchar(char ch)
{
	ssize_t ret = write(STDOUT_FILENO, &ch, 1);

	return (ret == -1 ? EOF : (int) ret);
}
