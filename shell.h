#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <signal.h>
#include <stddef.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>
#include <string.h>

#define FLAG_UPPERCASE 1
#define HISTORY_FILE
#define FLAG_SIGNED    2
#define BUF_FLUSH fflush(stdout)
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define MAX_COMMAND_LENGTH 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH '\n'
static char write_buffer[WRITE_BUF_SIZE];
static int write_index = 0;

typedef struct history_entry {
char *command;
int index;
struct history_entry *next;
} history_entry;
typedef struct i_t {
history_entry *history_head;
} i_t;
typedef struct list_s {
char *str;
int number;
struct list_s *next;
} list_t;typedef struct {
int readfd;
char **env;
int err_num;
char *pwd;
char *name;
char *value;
char **envp;
env_list_t *env;
t_history *history;
char *buffer;
size_t buffer_size;
ssize_t input_length;
} i_t;
typedef ssize_t s_t;

typedef struct alias_t {
char *name;
char *command;
struct alias_t *next;
} alias_t;
typedef struct s_history {
char *command;
struct s_history *next;
} t_history;

typedef struct env_var {
char *name;
char *value;
struct env_var *next;
} env_var_t;
typedef struct {
env_var_t *env_vars;
} i_t;
typedef struct i_t {
char **ave;
int z;
} i_t;

int _flush_buffer(int f)
{
int written = write(f, buffer, buffer_index);
buffer_index = 0;
return (written);
}


// Macro to initialize an info_t structure
#define INFO_INIT { .readfd = STDIN_FILENO }

// Function prototypes
int _getenv(const char *name, char *buf, size_t buflen);
int _setenv(const char *name, const char *value, int overwrite);
void populate_env_list(info_t *info);
void read_history(info_t *info);
void hsh(info_t *info, char **av);
void print_prompt(void);
char *read_input(void);
char **parse_input(char *input);
int execute_command(char **args);
char *_strcat(char *x, char *g);
char *starts_with(const char *w, const char *z);
int _strcmp(char *t, char **y);
int _strlen(char **s);
char *_strcpy(char **y, char *s;)
char *_strdup(const char *str);
void _puts(char *str)
int _putchar(char b);
char **strtow2(char *s, char e);
void free_strtow(char **words);
char **strtow(char *s, char *e);
void remove_comments(char *buf);
int print_d(int input, int fd);
void print_error(i_t *info, char *estr);
int _erratoi(char *t);
extern int _eputchar(char c);
int _putsfd(char *s, int fd);
int _putfd(char s, int f);
int _putfd(char c, int fd);
void _eputs(char *s);
int _eputchar(char c);
int atoi(char *c);
int _isalpha(int b);
int is_delim(char b, char *d;)
int interactive(i_t *info);
int myhelp(i_t *info);
int mycd(i_t *info, const char *path);
int myexit(i_t *info, char *arg);
alias_t *find_alias(i_t *info, const char *name);
alias_t *create_alias(const char *name, const char *command);
int _myalias(i_t *info, char *alias_name, char *alias_command);
int print_alias(l_t *node);
int add_alias(i_t *info, char *name, char *value);
int unset_alias(i_t *info, char *name);
int set_alias(i_t *info, char *s);
int unset_alias(i_t *info, char *name);
int add_alias(i_t *info, char *name, char *value);
alias_t *create_alias(const char *name, const char *command);
alias_t *find_alias(i_t *info, const char *name);
void print_list(const t_history *list);
void print_list(const t_history *list);
int populate_env_list(i_t *info);
env_list_t *create_env_node(const char *env_var);
int _myunsetenv(i_t *info, char *name);
int _mysetenv(i_t *info, char *name, char *value, int overwrite);
char *_getenv(i_t *info, const char *name);
char **environ;
int _myenv(i_t *info);
char *strncpy(char *d, const char *s, int m);
char *_strncat(char *d, const char *s, int m);
char *strchr(const char *s, char c);
char **get_environ(i_t *info);
int _unsetenv(i_t *info, char *var);
int _setenv(i_t *info, char *var, char *value);
ssize_t input_buf(i_t *info, char **buf, s_t *len);
ssize_t read_buf(i_t *info, char *buffer, s_t *i);
int _getline(i_t *info, char **ptr, size_t *l);
void sigintHandler(__attribute__((unused)) int sig);
ssize_t get_input(i_t *info);
char *get_history_file(i_t *info);
int read_history(i_t *info);
int build_history_list(i_t *info, char *buffer, int linecount);
char *get_history_file(i_t *info);
int write_history(i_t *info);
int read_history(i_t *info);
int build_history_list(i_t *info, char *buffer, int linecount);
int renumber_history(i_t *info);
list_t *add_node(list_t **head, const char *s, int num);
list_t *add_node_end(list_t **head, const char *s, int num);
size_t print_list_str(const list_t *head);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head);

// Other utility functions
void _eputs(const char *str);
void _eputchar(char c);
int _eprintf(const char *format, ...);

#endif

