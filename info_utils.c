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
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
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
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (free_all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
		info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
