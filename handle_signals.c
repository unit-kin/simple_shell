#include "shell.h"

/**
 * handle_signal - handles the given signal
 * @signal_id: the identifier of the signal to handle
 *
 * Return: nothing
 */
void handle_signal(int signal_id)
{
	if (signal_id == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}
