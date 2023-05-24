#include "shell.h"

/**
 * shell_loop - main shell loop
 * @info: pointer to the info struct
 * @av: argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int shell_loop(info_t *info, char **av)
{
	ssize_t read_result = 0;
	int builtin_ret = 0;

	while (read_result != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (is_interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		read_result = get_input(info);
		if (read_result != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin_command(info);
			if (builtin_ret == -1)
				find_command(info);
		}
		else if (is_interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!is_interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->error_num == -1)
			exit(info->status);
		exit(info->error_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin_command - finds a builtin command
 * @info: pointer to the info struct
 *
 * Return: -1 if builtin not found,
 *         0 if builtin executed successfully,
 *         1 if builtin found but not successful,
 *         -2 if builtin signals exit()
 */
int find_builtin_command(info_t *info)
{
	int i, builtin_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].name; i++)
	{
		if (_strcmp(info->argv[0], builtintbl[i].name) == 0)
		{
			info->line_count++;
			builtin_ret = builtintbl[i].func(info);
			break;
		}
	}

	return (builtin_ret);
}

/**
 * find_command - finds a command in PATH
 * @info: pointer to the info struct
 *
 * Return: void
 */
void find_command(info_t *info)
{
	char *path = NULL;
	int i, arg_count = 0;

	info->path = info->argv[0];

	if (info->line_count_flag == 1)
	{
		info->line_count++;
		info->line_count_flag = 0;
	}

	for (i = 0; info->arg[i]; i++)
	{
		if (!is_delimiter(info->arg[i], " \t\n"))
			arg_count++;
	}

	if (!arg_count)
		return;

	path = find_command_path(info, _getenv(info, "PATH="), info->argv[0]);

	if (path)
	{
		info->path = path;
		fork_command(info);
	}
	else
	{
		if ((is_interactive(info) || _getenv(info, "PATH=") || info->argv[0][0] == '/') &&
		    is_cmd(info, info->argv[0]))
		{
			fork_command(info);
		}
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_command - forks an exec thread to run the command
 * @info: pointer to the info struct
 *
 * Return: void
 */
void fork_command(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);

			if (errno == EACCES)
				exit(126);

			exit(1);
		}
	}
	else
	{
		wait(&(info->status));

		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);

			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
