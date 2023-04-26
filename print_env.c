#include "shell.h"

/**
 * print_env - Print the current environment variables.
 *
 * Return: Nothing
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * main - Entry point to the function.
 *
 * Return: Nothing
 */
int main(void)
{
	print_env();
	return (0);
}
