#include "shell.h"

/**
 * handle_cd - changes the current working directory of the shell
 * @cmd_args: an array of strings containing the command and arguments
 *
 * Return: Always 0
 */
int handle_cd(char **cmd_args)
{
	char *new_dir;

	if (cmd_args[1] == NULL)
	{
		new_dir = getenv("HOME");
		if (new_dir == NULL)
		{
			perror("getenv");
			return (1);
		}
	}
	else if (strcmp(cmd_args[1], "-") == 0)
	{
		new_dir = getenv("OLDPWD");
		if (new_dir == NULL)
		{
			perror("getenv");
			return (1);
		}
		printf("%s\n", new_dir);
	}
	else
	{
		new_dir = cmd_args[1];
	}

	if (chdir(new_dir) == -1)
	{
		perror("chdir");
		return (1);
	}

	if (setenv("OLDPWD", getenv("PWD"), 1) == -1)
	{
		perror("setenv");
		return (1);
	}

	if (setenv("PWD", getcwd(NULL, 0), 1) == -1)
	{
		perror("setenv");
		return (1);
	}

	return (0);
}

/**
 * main - Simple shell entry point
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
	char *input = malloc(MAX_INPUT_SIZE);
	char **cmd_args;
	pid_t pid = fork();
	int num_tokens = 0;
	int status;

	while (1)
	{
		printf("$ ");
		fgets(input, MAX_INPUT_SIZE, stdin);

		input[strcspn(input, "\n")] = '\0';

		cmd_args = tokenize(input, " ", &num_tokens);

		handle_builtin(cmd_args);

		if (pid == -1)
		{
			perror("fork");
		}
		else if (pid == 0)
		{
			if (execvp(cmd_args[0], cmd_args) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}

		free(cmd_args);
	}

	free(input);

	return (0);
}
