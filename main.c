#include "shell.h"

/**
 * main - entry point of the shell program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
    info_t info[] = { INFO_INIT };
    int file_descriptor = 2;

    asm (
        "mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (file_descriptor)
        : "r" (file_descriptor)
    );

    if (argc == 2)
    {
        file_descriptor = open(argv[1], O_RDONLY);
        if (file_descriptor == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _print_string(argv[0]);
                _print_string(": 0: Can't open ");
                _print_string(argv[1]);
                _putchar_stderr('\n');
                _putchar_stderr(BUF_FLUSH);
                exit(127);
            }
            return EXIT_FAILURE;
        }
        info->read_fd = file_descriptor;
    }

    populate_environment_list(info);
    read_history_file(info);
    shell_loop(info, argv);

    return EXIT_SUCCESS;
}
