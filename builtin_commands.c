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
			print_error_message(info, "Illegal number: ");
			_print_string(info->argv[1]);
			_putchar_stderr('\n');
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
		print_string("TODO: getcwd failure emsg here\n");
	if (!info->argv[1])
	{
		dir = get_environment_variable(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = get_environment_variable(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (str_compare(info->argv[1], "-") == 0)
	{
		if (!get_environment_variable(info, "OLDPWD="))
		{
			print_string(s);
			print_character('\n');
			return (1);
		}
		print_string(get_environment_variable(info, "OLDPWD="));
		print_character('\n');
		chdir_ret = chdir((dir = get_environment_variable(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error_message(info, "can't cd to ");
		_print_string(info->argv[1]);
		_putchar_stderr('\n');
	}
	else
	{
		set_environment(info, "OLDPWD", get_environment_variable(info, "PWD="));
		set_environment(info, "PWD", getcwd(buffer, 1024));
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
	print_string("Welcome to the ALX simple shell help page \n");
	if (*arg_array)
		print_string(*arg_array);
	return (0);
}
