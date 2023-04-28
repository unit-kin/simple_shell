#include "shell.h"

/**
 * combine_paths - Combine two strings
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to combined string
 */
char *combine_paths(char *dest, const char *src)
{
	int dest_len = get_string_length(dest);
	int src_len = get_string_length(src);
	char *new_str = malloc(sizeof(char) * (dest_len + src_len + 2));
	int i = 0, j = 0;

	if (!new_str)
		return (NULL);

	while (dest[i] != '\0')
	{
		new_str[i] = dest[i];
		i++;
	}
	while (src[j] != '\0')
	{
		new_str[i] = src[j];
		i++;
		j++;
	}
	new_str[i] = '\0';

	return (new_str);
}

/**
 * find_command - Search for a command in the system
 * @command_name: The name of the command to search for
 *
 * Return: The path to the command if found, NULL otherwise
 */
char *find_command(char *command_name)
{
	char *path_env = NULL;
	char **path_tokens = NULL;
	int num_tokens = 0, i;
	struct stat sb;

	if (!command_name)
		return (NULL);

	if (stat(command_name, &sb) == 0)
		return (_strdup(command_name));

	path_env = find_env_var("PATH");
	if (!path_env)
		return (NULL);

	num_tokens = count_delimiters(path_env, ":") + 1;
	path_tokens = split_string(path_env, ":", &num_tokens);

	for (i = 0; i < num_tokens; i++)
	{
		char *command_path = combine_paths(path_tokens[i], command_name);

		if (stat(command_path, &sb) == 0)
		{
			free(command_name);
			free(path_env);
			free_tokens(path_tokens);
			return (command_path);
		}

		free(command_path);
	}

	free(path_env);
	free_tokens(path_tokens);
	return (NULL);
}

/**
 * execute_command - Executes a command with its options
 * @command: The command to execute
 * @options: The options or flags to the command
 *
 * Return: A integer status value
 */
int execute_command(char *command, char **options)
{
	pid_t pid;
	int status;

	switch (pid = fork())
	{
	case -1:
		perror("fork failed");
		return (-1);
	case 0:
		execve(command, options, environ);
		perror(command);
		exit(EXIT_FAILURE);
		break;
	default:
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}

	return (0);
}
