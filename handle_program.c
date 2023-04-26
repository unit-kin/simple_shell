#include "shell.h"

/**
 * handle_program - Execute non-built-in programs
 * @cmd_args: Null terminated array of strings
 * @status: Pointer to integer to store the exit status of the program
 *
 * Return: 1 on success, 0 on failure
 */
int handle_program(char **cmd_args, int *status)
{
	pid_t child_pid;
	int child_status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (0);
	}
	if (child_pid == 0)
	{
		execve(cmd_args[0], cmd_args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &child_status, 0);
		if (WIFEXITED(child_status))
			*status = WEXITSTATUS(child_status);
	}

	return (1);
}
