#include "shell.h"

/**
 * main - Programs entry point
 * @argc: Number of arguments passed to the program
 * @argv: Array of pointers to the arguments
 *
 * Return: Always zero
 */
int main(int argc, char **argv)
{
	char *cmd = NULL, **cmd_args = NULL;
	int status = 0, num_tokens = 0;

	while (1)
	{
		cmd = get_command();
		if (!cmd)
			continue;

		cmd_args = tokenize(cmd, " ", &num_tokens);
		if (!cmd_args || !*cmd_args)
		{
			free(cmd);
			continue;
		}

		handle_builtin(cmd_args);

		handle_setenv(cmd_args);

		handle_unsetenv(cmd_args);

		if (handle_program(cmd_args, &status) == 0)
			continue;

		fprintf(stderr, "hsh: command not found: %s\n", cmd_args[0]);
		status = 127;

		free(cmd_args);
		free(cmd);
	}

	free(cmd_args);
	free(cmd);

	if (argc > 1 && strcmp(argv[1], "exit") == 0)
	{
		if (argc == 2)
			exit(status);
		else if (argc == 3 && is_numeric(argv[2]))
			exit(atoi(argv[2]));
		else
			fprintf(stderr, "hsh: exit: Illegal number: %s\n", argv[2]);
	}

	return (0);
}
