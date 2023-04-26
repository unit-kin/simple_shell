#include "shell.h"

/**
 * get_command - Read the input command from stdin
 *
 * Return: Pointer to the input command on success, NULL on failure
 */
char *get_command(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&command, &len, stdin);
	if (read == -1)
		return (NULL);

	if (command[read - 1] == '\n')
		command[read - 1] = '\0';

	return (command);
}
