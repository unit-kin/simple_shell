#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

char *concatenate_strings(char *destination, char *source);
int get_string_length(const char *string);
int compare_strings(char *string1, char *string2);
char *_strdup(const char *str);
int _atoi(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
void _puts(const char *s);
void *array_resize(void *array, size_t old_len, size_t new_len);
int _putchar(char ch);
void handle_exit(char **u_tokens, char *line);
char *remove_character(char *string);
char **split_string(char *string, char *delimiter, int *num_tokens);
void handle_signal(int signal_id);
void free_env_variable(char *env_var);
void free_tokens(char **tokens);
char *find_env_var(const char *name);
void print_environment(void);
void print_shell_help(void);
int exec_builtins(char **tokens, char *line);
int count_words(char *str);
int count_delimiters(char *str, char *del);
char *combine_paths(char *dest, const char *src);
char *find_command(char *command_name);
int execute_command(char *command, char **options);

#endif
