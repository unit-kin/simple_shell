#include "shell.h"

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count the words in
 *
 * Return: The number of words found in the string
 */
int count_words(char *str)
{
	int num_words = 0;
	int in_word = 0;

	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			num_words++;
		}

		str++;
	}

	return (num_words);
}

/**
 * count_delimiters - Counts the number of delimiters in a string
 * @str: The string to count the delimiters in
 * @del: The delimiters to count
 *
 * Return: The number of delimiters found in the string
 */
int count_delimiters(char *str, char *del)
{
	int num_delimiters = 0;

	while (*del != '\0')
	{
		char *tmp_str = str;

		while (*tmp_str != '\0')
		{
			if (*tmp_str == *del)
			{
				num_delimiters++;
			}

			tmp_str++;
		}
		del++;
	}

	return (num_delimiters);
}
