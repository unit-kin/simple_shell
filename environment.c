#include "shell.h"

/**
 * display_environment - prints the current environment
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int display_environment(info_t *info)
{
	print_str_list(info->env);
	return (0);
}

/**
 * get_environment_variable - gets the value of an environment variable
 * @info: Structure containing potential arguments.
 * @name: environment variable name
 *
 * Return: the value of the environment variable
 */
char *get_environment_variable(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = str_starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * set_environment_variable - Initialize a new environment variable or modify an existing one
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int set_environment_variable(info_t *info)
{
	if (info->argc != 3)
	{
		_print_string("Incorrect number of arguments\n");
		return (1);
	}
	if (set_environment(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * unset_environment_variable - Remove an environment variable
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int unset_environment_variable(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_print_string("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		unset_environment(info, info->argv[i]);

	return (0);
}

/**
 * populate_environment_list - populates the environment linked list
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int populate_environment_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
