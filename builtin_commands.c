#include "shell.h"

/**
 * handle_exit - exits the shell
 * @info: Structure containing potential arguments.
 *
 * Return: exits with a given exit status
 *         (0) if info->argv[0] != "exit"
 */
int handle_exit(info_t *info)
{
	int exit_check;

	if (info->argv[1])
	{
		exit_check = err_atoi(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = err_atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * handle_cd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int handle_cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: getcwd failure emsg here\n");
	if (!info->argv[1])
	{
		dir = getenv_value(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = getenv_value(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!getenv_value(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(getenv_value(info, "OLDPWD="));
		_putchar('\n');
		chdir_ret = chdir((dir = getenv_value(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]);
		_eputchar('\n');
	}
	else
	{
		setenv_value(info, "OLDPWD", getenv_value(info, "PWD="));
		setenv_value(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * print_shell_help - displays help information
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int print_shell_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Welcome to the ALX simple shell help page \n");
	if (*arg_array)
		_puts(*arg_array);
	return (0);
}
