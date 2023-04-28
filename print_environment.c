#include "shell.h"

/**
 * print_environment - Prints the environment variables
 *
 * This function prints all environment variables
 * contained in the "environ" global variable.
 *
 * Return: Nothing.
 */
void print_environment(void)
{
	int i = 0, j = 0;

	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] != '\0')
		{
			_putchar(environ[i][j]);
			j++;
		}

		if (j != 0)
			_putchar('\n');

		i++;
	}
}
