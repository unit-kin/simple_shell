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

extern char **environ;

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
#endif /* SHELL_H */

