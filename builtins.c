#include "shell.h"

/**
 * exec_builtins - Executes a built-in command
 * @tokens: The tokenized command arguments
 * @line: The original input line
 *
 * Return: 1 if the command is a built-in, 0 otherwise
 */
int exec_builtins(char **tokens, char *line)
{
	int i = 0;
	char *builtin_commands[] = {"exit", "cd", "help", "env", NULL};

	while (builtin_commands[i])
	{
		if (compare_strings(tokens[0], builtin_commands[i]) == 0)
		{
			switch (i)
			{
			case 0:
				handle_exit(tokens, line);
				break;
			case 1:
				chdir(tokens[1]);
				return (1);
			case 2:
				print_shell_help();
				break;
			case 3:
				print_environment();
				break;
			}
			return (1);
		}
		i++;
	}
	return (0);
}
