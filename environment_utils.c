#include "shell.h"

/**
 * get_environment - returns the string array copy of our environment variables
 * @info: Structure containing potential arguments
 * Return: String array of environment variables
 */
char **get_environment(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_array(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * unset_environment - Remove an environment variable
 * @info: Structure containing potential arguments
 * @variable: The environment variable to remove
 * Return: 1 if variable is deleted, 0 otherwise
 */
int unset_environment(info_t *info, char *variable)
{
	list_t *node = info->env;
	size_t index = 0;
	char *p;

	if (!node || !variable)
		return (0);

	while (node)
	{
		p = str_starts_with(node->str, variable);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at(&(info->env), index);
			index = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		index++;
	}
	return (info->env_changed);
}

/**
 * set_environment - Initialize a new environment variable or modify an existing one
 * @info: Structure containing potential arguments
 * @variable: The environment variable to set or modify
 * @value: The value of the environment variable
 * Return: Always 0
 */
int set_environment(info_t *info, char *variable, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *p;

	if (!variable || !value)
		return (0);

	buffer = malloc(str_length(variable) + str_length(value) + 2);
	if (!buffer)
		return (1);
	copy_string(buffer, variable);
	str_concat(buffer, "=");
	str_concat(buffer, value);
	node = info->env;
	while (node)
	{
		p = str_starts_with(node->str, variable);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buffer;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add(&(info->env), buffer, 0);
	free(buffer);
	info->env_changed = 1;
	return (0);
}
