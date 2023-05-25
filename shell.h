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
#include <limits.h>
#include <string.h>

#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CONVERT_UNSIGNED 1
#define CONVERT_LOWERCASE 2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

typedef struct list_s {
    char *str;
    int num;
    struct list_s *next;
} list_t;

typedef struct passinfo {
    	int read_fd;
    	char **argv;
    	int status;
  	int err_num;
    	int error_num;
  	char *arg;
  	char *arguments;
	char *path;
	int argc;
  	unsigned int line_count;
	int line_count_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	char **cmd_buffer;
  	int cmd_buffer_type;
	int hist_count;
} info_t;

#define INFO_INIT \
{0, NULL, 0, 0, 0, NULL, NULL, NULL, 0, 0, 0, NULL, 0, NULL, NULL, \
    NULL, 0, NULL, 0, 0}

typedef struct builtin{
    char *name;
    int (*func)(info_t *);
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
char *strn_concat(char *dest, char *src, int n);
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
size_t print_list(const list_t *head);
list_t *find_node_starts_with(list_t *head, char *prefix, char next_char);
ssize_t get_node_index(list_t *head, list_t *node);
int free_ptr(void **ptr);
int is_executable_cmd(info_t *info, char *path);
char *duplicate_chars(char *pathstr, int start, int stop);
char *find_cmd_path(info_t *info, char *pathstr, char *cmd);
char *_set_memory(char *dest, char ch, unsigned int n);
void free_string_array(char **str_array);
void *_realloc_memory(void *ptr, unsigned int old_size, unsigned int new_size);
int shell_loop(info_t *info, char **av);
int find_builtin_command(info_t *info);
void find_command(info_t *info);
void fork_command(info_t *info);
int str_length(char *str);
int str_compare(char *str1, char *str2);
char *str_starts_with(const char *haystack, const char *needle);
char *str_concat(char *dest, char *src);
char *copy_string(char *dest, char *src);
char *duplicate_string(const char *str);
void print_string(char *str);
int print_character(char c);
char **split_string(char *str, char *delimiters);
char **split_string2(char *str, char delimiter);
int is_chain_delimiter(info_t *info, char *buf, size_t *p);
void check_chain_continuation(info_t *info, char *buf, size_t *p, size_t i, size_t len);
int replace_alias(info_t *info);
int replace_vars(info_t *info);
int replace_string(char **old, char *new);

#endif
