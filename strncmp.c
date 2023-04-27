#include "shell.h"

/**
 * _strncmp - Compare two strings
 *
 * @s1: String 1
 * @s2: String 2
 * @n: Number of bytes to compare
 *
 * Return: 0 if strings are equal, otherwise difference between first
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
		{
			return s1[i] - s2[i];
		}
	}

	return 0;
}

