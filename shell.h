#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024
#define MAX_INPUT_SIZE 1024
#define BUFFER_SIZE 1024
extern char **environ;
#define BUFSIZE 1024
#define TOK_DELIM " \t\r\n\a"
#define CMD_DELIM ";"

void exit_shell(void);
int execute_command(char **args, int status);
int execute_pipeline(char ***args, int num_commands);
char **split_line(char *line, char *delimiter);
char **split_commands(char *line);
char **split_arguments(char *line);
int shell_loop(void);
void prompt(void);
int _putchar(char c);
void _puts(char *str);
void print_strings(const char *seperator, const unsigned int n, ...);
int exit_shell(char **arr, char *prog, char *buffer);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2,  unsigned int n);
int _atoi(char *str);
int isinteger(char *s);
int _isdigit(int c);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char **split_line(char *str);
char *_getenv(const char *name);
void execute(char **argv, char **env, char *prog);
void sigintHandler(int sig_num);
void handle_builtin(char **cmd_args);
char **tokenize(char *str, const char *delimiter, int *num_tokens);
char *get_command(void);
int handle_program(char **cmd_args, int *status);
int is_numeric(char *str);
int set_env(char **env, char *name, char *value);
int unset_env(char **env, char *name);
void handle_setenv(char **cmd_args);
void handle_unsetenv(char **cmd_args);
int handle_cd(char **cmd_args);

#endif
