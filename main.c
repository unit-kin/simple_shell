#include "shell.h"

/**
 * main - Entry point to the Shell
 *
 * Return: Always zero.
 */
int main(void)
{
	char *line = NULL, **tokens = NULL;
	int num_words = 0, exec_flag = 0;
	size_t line_size = 0;
	ssize_t line_len = 0;

	while (1)
	{
		signal(SIGINT, handle_signal);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		line_len = getline(&line, &line_size, stdin);
		if (line_len == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		num_words = count_words(line);
		if (line[0] != '\n' && num_words > 0)
		{
			tokens = split_string(line, " \t", &num_words);
			exec_flag = exec_builtins(tokens, line);
			if (!exec_flag)
			{
				tokens[0] = find_command(tokens[0]);
				if (tokens[0] && access(tokens[0], X_OK) == 0)
					execute_command(tokens[0], tokens);
				else
					perror("./hsh");
			}

			free_tokens(tokens);
		}


		if (line != NULL)
			free(line);
		line = NULL;
	}

	return (0);
}

