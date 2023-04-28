#include "shell.h"

/**
 * signal_handler - Handles the SIGINT signal.
 * @sig_id: The signal identifier.
 *
 * This function handles the SIGINT signal and prints a prompt to stdout.
 */
void signal_handler(int sig_id)
{
	if (sig_id == SIGINT)
	{
		const char prompt[] = "\n($) ";
		ssize_t prompt_len = sizeof(prompt) - 1;

		write(STDOUT_FILENO, prompt, prompt_len);
	}
}

