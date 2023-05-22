#ifndef _SHELL_H_
#define _SHELL_H_

/*
 * File: shell.h
 * Author: [Your Name]
 */

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/* Global environment */
extern char **environ;
/* Global program name */
extern char *prog_name;
/* Global history counter */
extern int history_counter;

/**
 * struct directory_s - Structure for a directory node in the linked list.
 * @path: The directory path.
 * @next: Pointer to the next directory node.
 */
typedef struct directory_s
{
	char *path;
	struct directory_s *next;
} directory_t;

/**
 * struct builtin_s - Structure for a builtin command.
 * @name: The name of the builtin command.
 * @function: Function pointer to the implementation of the builtin command.
 */
typedef struct builtin_s
{
	char *name;
	int (*function)(char **args, char **front);
} builtin_t;

/**
 * struct alias_s - Structure for an alias.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: Pointer to the next alias.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* Global aliases linked list */
extern alias_t *aliases_list;

/* Main Helpers */
ssize_t _shell_getline(char **lineptr, size_t *n, FILE *stream);
void *_shell_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_shell_strtok(char *line, char *delim);
char *get_command_location(char *command);
directory_t *get_directory(char *path);
int execute_command(char **args, char **front);
void free_directory_list(directory_t *head);
char *_shell_itoa(int num);

/* Input Helpers */
void handle_input_line(char **line, ssize_t read);
void variable_replacement(char **args, int *exit_status);
char *get_arguments(char *line, int *exit_status);
int process_arguments(char **args, char **front, int *exit_status);
int run_arguments(char **args, char **front, int *exit_status);
int handle_arguments(int *exit_status);
int validate_arguments(char **args);
void free_arguments(char **args, char **front);
char **replace_aliases(char **args);

/* String functions */
int _shell_strlen(const char *s);
char *_shell_strcat(char *dest, const char *src);
char *_shell_strncat(char *dest, const char *src, size_t n);
char *_shell_strcpy(char *dest, const char *src);
char *_shell_strchr(char *s, char c);
int _shell_strspn(char *s, char *accept);
int _shell_strcmp(char *s1, char *s2);
int _shell_strncmp(const char *s1, const char *s2, size_t n);

/* Builtins */
int (*get_builtin_function(char *command))(char **args, char **front);
int shell_exit(char **args, char **front);
int shell_env(char **args, char **front);
int shell_setenv(char **args, char **front);
int shell_unsetenv(char **args, char **front);
int shell_cd(char **args, char **front);
int shell_alias(char **args, char **front);
int shell_help(char **args, char **front);

/* Builtin Helpers */
char **copy_environment(void);
void free_environment(void);
char **get_environment_variable(const char *variable);

/* Error Handling */
int handle_error(char **args, int error_code);
char *get_error_message_env(char **args);
char *get_error_message_1(char **args);
char *get_error_message_2_exit(char **args);
char *get_error_message_2_cd(char **args);
char *get_error_message_2_syntax(char **args);
char *get_error_message_126(char **args);
char *get_error_message_127(char **args);

/* Linked List Helpers */
alias_t *add_alias(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
directory_t *add_directory(directory_t **head, char *path);
void free_directory_list(directory_t *head);

void print_all_help(void);
void print_alias_help(void);
void print_cd_help(void);
void print_exit_help(void);
void print_help_help(void);
void print_env_help(void);
void print_setenv_help(void);
void print_unsetenv_help(void);
void print_history_help(void);

int process_file_commands(char *file_path, int *exit_status);
#endif
