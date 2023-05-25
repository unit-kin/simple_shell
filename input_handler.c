#include "shell.h"

/**
 * buffer_input - buffers chained commands
 * @info: parameter struct
 * @buffer: address of buffer
 * @length: address of length var
 *
 * Return: bytes read
 */
ssize_t buffer_input(info_t *info, char **buffer, size_t *length)
{
	ssize_t read_bytes = 0;
	size_t length_p = 0;

	if (!*length)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, interruptHandler);
#if USE_GETLINE
		read_bytes = getline(buffer, &length_p, stdin);
#else
		read_bytes = get_line(info, buffer, &length_p);
#endif
		if (read_bytes > 0)
		{
			if ((*buffer)[read_bytes - 1] == '\n')
			{
				(*buffer)[read_bytes - 1] = '\0';
				read_bytes--;
			}
			info->line_count_flag = 1;
			remove_comments(*buffer);
			build_history_list(info, *buffer, info->hist_count++);
			{
				*length = read_bytes;
				info->cmd_buffer = buffer;
			}
		}
	}
	return (read_bytes);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buffer;
	static size_t i, j, length;
	ssize_t read_bytes = 0;
	char **buffer_p = &(info->arg), *p;

	print_character(BUF_FLUSH);
	read_bytes = buffer_input(info, &buffer, &length);
	if (read_bytes == -1)
		return (-1);
	if (length)
	{
		j = i;
		p = buffer + i;

		check_chain_continuation(info, buffer, &j, i, length);
		while (j < length)
		{
			if (is_chain_delimiter(info, buffer, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= length)
		{
			i = length = 0;
			info->cmd_buffer_type = CMD_NORM;
		}

		*buffer_p = p;
		return (str_length(p));
	}

	*buffer_p = buffer;
	return (read_bytes);
}

/**
 * read_buffer - reads a buffer
 * @info: parameter struct
 * @buffer: buffer
 * @i: size
 *
 * Return: read_bytes
 */
ssize_t read_buffer(info_t *info, char *buffer, size_t *i)
{
	ssize_t read_bytes = 0;

	if (*i)
		return (0);
	read_bytes = read(info->read_fd, buffer, READ_BUF_SIZE);
	if (read_bytes >= 0)
		*i = read_bytes;
	return (read_bytes);
}

/**
 * get_line - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: size
 */
int get_line(info_t *info, char **ptr, size_t *length)
{
	static char buffer[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t read_bytes = 0, size = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		size = *length;
	if (i == len)
		i = len = 0;

	read_bytes = read_buffer(info, buffer, &len);
	if (read_bytes == -1 || (read_bytes == 0 && len == 0))
		return (-1);

	c = str_find_char(buffer + i, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : len;
	new_p = _realloc_memory(p, size, size ? size + k : k + 1);
	if (!new_p)
		return (p ? (free(p), -1) : -1);

	if (size)
		strn_concat(new_p, buffer + i, k - i);
	else
		str_copy(new_p, buffer + i, k - i + 1);

	size += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = size;
	*ptr = p;
	return (size);
}

/**
 * interruptHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void interruptHandler(__attribute__((unused)) int sig_num)
{
	print_string("\n");
	print_string("$ ");
	print_character(BUF_FLUSH);
}
