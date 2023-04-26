#include "shell.h"
#include <stdio.h>
#include <signal.h>

/**
 * sigintHandler - Signal Handler for SIGINT
 *
 * @sig_num: SIGNAL NUMBER to catch
 */
void sigintHandler(int sig_num __attribute__((unused)))
{
	/* Reset handler to catch SIGINT next time. */
	signal(SIGINT, sigintHandler);

	/* Print the name of the shell and the prompt symbol. */
	char *shell_name = "my_shell";
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, shell_name, _strlen(shell_name));
	write(STDOUT_FILENO, " $ ", 3);
	fflush(stdout);
}

