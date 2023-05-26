^ “The Gates of Shell”, by Spencer Cheng, featuring Julien Barbier Project to be done in teams of 2 people (your team: Alvin Kang'ara, Aron Mang'ati)

Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

General
Who designed and implemented the original Unix operating system Who wrote the first version of the UNIX shell Who invented the B programming language (the direct predecessor to the C programming language) Who is Ken Thompson How does a shell work What is a pid and a ppid How to manipulate the environment of the current process What is the difference between a function and a system call How to create processes What are the three prototypes of main How does the shell use the PATH to find the programs How to execute another program with the execve system call How to suspend the execution of a process until one of its children terminates What is EOF / “end-of-file”?

Requirements
General
Allowed editors: vi, vim, emacs All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89 All your files should end with a new line A README.md file, at the root of the folder of the project is mandatory Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl Your shell should not have any memory leaks No more than 5 functions per file All your header files should be include guarded Use system calls only when you need to (why?)

GitHub
*There should be one project repository per group. If you and your partner have a repository with the same name in both your accounts, you risk a 0% score. Add your partner as a collaborator. *

More Info Output Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below) Example of error with sh:

$ echo "qwerty" | /bin/sh /bin/sh: 1: qwerty: not found $ echo "qwerty" | /bin/../bin/sh /bin/../bin/sh: 1: qwerty: not found $ Same error with your program hsh:

$ echo "qwerty" | ./hsh ./hsh: 1: qwerty: not found $ echo "qwerty" | ./././hsh ./././hsh: 1: qwerty: not found $

List of allowed functions and system calls
access (man 2 access) chdir (man 2 chdir) close (man 2 close) closedir (man 3 closedir) execve (man 2 execve) exit (man 3 exit) _exit (man 2 _exit) fflush (man 3 fflush) fork (man 2 fork) free (man 3 free) getcwd (man 3 getcwd) getline (man 3 getline) getpid (man 2 getpid) isatty (man 3 isatty) kill (man 2 kill) malloc (man 3 malloc) open (man 2 open) opendir (man 3 opendir) perror (man 3 perror) read (man 2 read) readdir (man 3 readdir) signal (man 2 signal) stat (__xstat) (man 2 stat) lstat (__lxstat) (man 2 lstat) fstat (__fxstat) (man 2 fstat) strtok (man 3 strtok) wait (man 2 wait) waitpid (man 2 waitpid) wait3 (man 2 wait3) wait4 (man 2 wait4) write (man 2 write)

Compilation
Your shell will be compiled this way:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

files
README.md - description about the project repo
AUTHORS - file at the root of your repository, listing all individuals having contributed content to the repository.
builtin_commands.c: Implements various built-in commands of the shell.
command_parser.c: Parses and processes user commands into executable commands.
dynamic_memory.c: Provides functions for dynamic memory allocation and deallocation.
environment.c: Manages the shell environment variables.
environment_utils.c: Contains utility functions for working with environment variables.
exit_handler.c: Handles the exit functionality of the shell.
history_io.c: Manages the reading from and writing to the history file.
info_utils.c: Contains utility functions for working with the shell's info structure.
input_handler.c: Handles user input and command line editing.
io_utils.c: Provides input/output utility functions.
linked_list.c: Implements a linked list data structure.
linked_list.c~: A backup or temporary file of the linked list implementation.
linked_list_utils.c: Contains utility functions for working with linked lists.
main.c: Contains the main function of the shell.
main_shell.c: Implements the main shell loop and command execution logic.
memory_utils.c: Provides utility functions for memory management.
more_builtin_commands.c: Additional built-in commands for the shell.
more_io_utils.c: Additional input/output utility functions.
more_string_utils.c: Additional string manipulation utility functions.
shell.h: Header file containing function prototypes, structure definitions, and macros for the shell.
string_conversion.c: Functions for converting data types to strings.
string_tokenizer.c: Implements a string tokenizer to split strings into tokens.
string_utils.c: Provides utility functions for string manipulation.
variable_utils.c: Contains utility functions for working with variables.
