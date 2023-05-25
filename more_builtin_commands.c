#include "shell.h"

/**
 * display_history - displays the history list, one command by line, preceded
 *                   with line numbers, starting at 0.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int display_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - removes an alias from the alias list
 * @info: parameter struct
 * @str: the alias string
 *
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = str_find_char(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = '\0';
	ret = delete_node_at(&(info->alias),
		get_node_index(info->alias, find_node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - adds or updates an alias in the alias list
 * @info: parameter struct
 * @str: the alias string
 *
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = str_find_char(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = str_find_char(node->str, '=');
		for (a = node->str; a <= p; a++)
			print_character(*a);
		print_character('\'');
		print_string(p + 1);
		print_string("'\n");
		return (0);
	}
	return (1);
}

/**
 * manage_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int manage_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = str_find_char(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(find_node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
