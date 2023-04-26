#include "shell.h"

/**
 * _getline - read an entire line from a file descriptor
 *
 * Return: On success, a pointer to the line. On failure, NULL.
 */
char *_getline(void)
{
	static char *buffer;
	ssize_t nread;
	char *line = NULL;

	if (!buffer)
		buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);

	nread = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	if (nread == -1)
		return (NULL);
	if (nread == 0)
		return (NULL);

	line = strtok(buffer, "\n");
	if (!line)
		return (NULL);

	return (line);
}

/**
 * main - Entry point.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;

	while ((line = _getline()))
	{
		printf("%s\n", line);
	}

	return (0);
}
