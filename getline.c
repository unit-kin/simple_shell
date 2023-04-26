#include "shell.h"

/**
<<<<<<< HEAD
 * _getline - Reads input from stdin
 *
 * @lineptr: Pointer to the buffer to store input
 * @n: Pointer to the number of bytes to read
 * @fd: File descriptor to read from
 *
 * Return: Number of characters read, including '\n' (Success),
 *         or -1 (Error),
 *         or -2 (Terminated by a signal).
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t n_read = 0;
	ssize_t ret = 0;
	char *p, *end, *new_ptr, *buf = malloc(BUFSIZ);

	if (buf == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*n = BUFSIZ;
		*lineptr = malloc(*n);

		if (*lineptr == NULL)
			return (free_buffer(-1, buf));
	}

	while ((n_read = read(fd, buf, BUFSIZ)) > 0)
	{
		p = buf;
		end = buf + n_read;

		while (p < end)
		{
			if ((size_t)ret >= *n)
			{
				*n *= 2;
				new_ptr = realloc(*lineptr, *n);

				if (new_ptr == NULL)
					return (free_buffer(-1, buf));

				*lineptr = new_ptr;
			}

			(*lineptr)[ret++] = *p++;

			if ((*lineptr)[ret - 1] == '\n')
				return (free_buffer(ret, buf));
		}
	}

	if (n_read == -1)
		return (print_error(buf));

	return (free_buffer(ret, buf));
}

/**
 * print_error - Prints error message
 *
 * @buf: Buffer to free
 *
 * Return: -1 (Error).
 */
ssize_t print_error(char *buf)
{
	if (errno == EINTR)
	{
		return (free_buffer(-2, buf));
	}
	else
	{
		return (free_buffer(-1, buf));
	}
}

/**
 * free_buffer - Frees the buffer
 *
 * @ret: Return value
 * @buf: Buffer to free
 *
 * Return: ret.
 */
ssize_t free_buffer(ssize_t ret, char *buf)
{
	free(buf);
	return (ret);
}

=======
 * _getline - read an entire line from a file descriptor
 *
 * Return: On success, a pointer to the line. On failure, NULL.
 */
char *_getline(void)
{
	static char *buffer;
	ssize_t nread;
	char *line = NULL;

	if (!buffer)
		buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);

	nread = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	if (nread == -1)
		return (NULL);
	if (nread == 0)
		return (NULL);

	line = strtok(buffer, "\n");
	if (!line)
		return (NULL);

	return (line);
}

/**
 * main - Entry point.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;

	while ((line = _getline()))
	{
		printf("%s\n", line);
	}

	return (0);
}
>>>>>>> 36abb189721558b4515b6580dcc046b297d23644
