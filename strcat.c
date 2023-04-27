#include "shell.h"

/**
 * print_strings - prints a variable number of strings separated by a delimiter
 * @separator: the string to be printed between the strings
 * @n: the number of strings to be printed
 * @...: variadic list of strings to be printed
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	char *str;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);
		if (str != NULL)
			_puts(str);
		else
			_puts("(nil)");

		if (separator != NULL && i != n - 1)
			_puts(separator);
	}

	va_end(args);

	_putchar('\n');
}

/**
 * _putchar - writes a character to stdout
 * @c: the character to write
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _puts - prints a string to stdout
 * @str: the string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
