#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 1024
extern char **environ;

void prompt(void);
char **parse_args(char *line);
char *find_path(char *command);
void print_env(void);
char *_getline(void);
void handle_builtin(char **cmd_args);
char **tokenize(char *str, const char *delimiter, int *num_tokens);
char *get_command(void);
int handle_program(char **cmd_args, int *status);
int is_numeric(char *str);
int set_env(char **env, char *name, char *value);
int unset_env(char **env, char *name);
void handle_setenv(char **cmd_args);
void handle_unsetenv(char **cmd_args);

#endif
