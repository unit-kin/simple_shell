#include "shell.h"

/**
 * main - Entry point
 *
 * Return: always zero
 */
int main(void)
{
	shell_loop();

	return (EXIT_SUCCESS);
}

/**
 * shell_loop - Runs the main loop of the simple shell.
 *
 * Return: Always returns 0.
 */
int shell_loop(void)
{
	char *line = NULL;
	char **commands = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	int status = 0;
	int i;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &bufsize, stdin);
		if (nread == -1)
		{
			break;
		}
		line[nread - 1] = '\0';

		commands = split_commands(line);
		for (i = 0; commands[i] != NULL; i++)
		{
			status = execute_command(split_arguments(commands[i]));
		}

		free(commands);
	}

	free(line);

	return (status);
}

/**
 * execute_command - Executes a command
 * @args: A NULL-terminated array of strings
 *
 * Return: 0 if successful
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		return 0;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (status);
}

/**
 * split_commands - Splits a command line into separate commands.
 * @line: A string containing the command line to split.
 *
 * Return: A NULL-terminated array of strings
 */
char **split_commands(char *line)
{
	char **commands = NULL;
	size_t bufsize = 0;
	int i = 0;
	char *token = strtok(line, ";");

	commands = malloc(sizeof(char *) * (bufsize + 1));
	if (commands == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	
	while (token != NULL)
	{
		commands[i++] = token;
		token = strtok(NULL, ";");
	}
	commands[i] = NULL;

	return (commands);
}

/**
 * split_arguments - Splits a command into separate arguments.
 * @line: A string containing the command to split.
 *
 * Return: A NULL-terminated array of strings
 */
char **split_arguments(char *line)
{
	char **args = NULL;
	size_t bufsize = 0;
	int i = 0;
	char *token = strtok(line, " ");

	args = malloc(sizeof(char *) * (bufsize + 1));
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (args);
}
