#include "shell.h"

/**
 * clear_info_struct - initializes info_t struct
 * @info: struct address
 */
void clear_info_struct(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info_struct - initializes info_t struct
 * @info: struct address
 * @args: argument vector
 */
void set_info_struct(info_t *info, char **args)
{
	int i = 0;

	info->fname = args[0];
	if (info->arg)
	{
		info->argv = split_string(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = duplicate_string(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info_struct - frees info_t struct fields
 * @info: struct address
 * @free_all: true if freeing all fields
 */
void free_info_struct(info_t *info, int free_all)
{
	free_string_array(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (free_all)
	{
		if (!info->cmd_buffer)
			free(info->arg);
		if (info->env)
			free_str_list(&(info->env));
		if (info->history)
			free_str_list(&(info->history));
		if (info->alias)
			free_str_list(&(info->alias));
		free_string_array(info->environ);
		info->environ = NULL;
		free_ptr((void **)info->cmd_buffer);
		if (info->read_fd > 2)
			close(info->read_fd);
		print_character(BUF_FLUSH);
	}
}
