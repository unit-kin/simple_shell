#include "shell.h"

/**
 * is_interactive_mode - checks if the shell is in interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int is_interactive_mode(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->read_fd <= 2);
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_delimiter(char c, char *delim)
{
    while (*delim)
    {
        if (*delim++ == c)
            return (1);
    }
    return (0);
}

/**
 * is_alpha - checks for alphabetic character
 * @c: the character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int is_alpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

/**
 * atoi_custom - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */
int atoi_custom(char *s)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
            sign *= -1;

        if (s[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return (output);
}
