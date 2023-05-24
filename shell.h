#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\0'
#define CONVERT_UNSIGNED 1
#define CONVERT_LOWERCASE 2

typedef struct list_s {
    char *str;
    int num;
    struct list_s *next;
} list_t;

typedef struct {
    int readfd;
} info_t;

typedef struct {
    char *name;
    int (*func)(info_t *info);
} builtin_table;

int is_interactive_mode(info_t *info);
int is_delimiter(char c, char *delim);
int is_alpha(int c);
int atoi_custom(char *s);
int handle_exit(info_t *info);
int handle_cd(info_t *info);
int print_shell_help(info_t *info);
int display_history(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int manage_alias(info_t *info);
int display_environment(info_t *info);
char *get_environment_variable(info_t *info, const char *name);
int set_environment_variable(info_t *info);
int unset_environment_variable(info_t *info);
int populate_environment_list(info_t *info);
void _print_string(char *str);
int _putchar_stderr(char c);
int _putchar_fd(char c, int fd);
int _print_string_fd(char *str, int fd);
int err_atoi(char *s);
void print_error_message(info_t *info, char *error_string);
int print_decimal(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);
char *str_copy(char *dest, char *src, int n);
char *str_concat(char *dest, char *src);
char *str_find_char(char *s, char c);
char **get_environment(info_t *info);
int unset_environment(info_t *info, char *variable);
int set_environment(info_t *info, char *variable, char *value);
void clear_info_struct(info_t *info);
void set_info_struct(info_t *info, char **args);
void free_info_struct(info_t *info, int free_all);
ssize_t buffer_input(info_t *info, char **buffer, size_t *length);
ssize_t get_input(info_t *info);
ssize_t read_buffer(info_t *info, char *buffer, size_t *i);
int get_line(info_t *info, char **ptr, size_t *length);
void interruptHandler(__attribute__((unused)) int sig_num);
char *get_history_file_path(info_t *info);
int write_history_file(info_t *info);
int read_history_file(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history_list(info_t *info);
list_t *add(list_t **head, const char *str, int num);
list_t *add_end(list_t **head, const char *str, int num);
size_t print_str_list(const list_t *head);
int delete_node_at(list_t **head, unsigned int index);
void free_str_list(list_t **head_ptr);
size_t list_length(const list_t *head);
char **list_to_array(list_t *head);
int is_chain_delimiter(info_t *info, char *buf, size_t *p);
void check_chain_continuation(info_t *info, char *buf, size_t *p, size_t i, size_t len);
int replace_alias(info_t *info);
int replace_vars(info_t *info);
int replace_string(char **old, char *new);
char **split_string(char *str, char *delimiters);
char **split_string2(char *str, char delimiter);
int str_length(char *str);
int str_compare(char *str1, char *str2);
char *str_starts_with(const char *haystack, const char *needle);
char *copy_string(char *dest, char *src);
char *duplicate_string(const char *str);
void print_string(char *str);
int print_character(char c);

#endif
