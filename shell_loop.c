#include "shell.h"

/**
 * print_prompt - Prints the shell prompt
 */
void print_prompt(void) {
printf("$ ");
fflush(stdout);
}

/**
 * read_input - Reads input from the user
 *
 * Return: A dynamically allocated string containing user input
 */
char *read_input(void) {
char *input = NULL;
size_t len = 0;
getline(&input, &len, stdin);
return (input);
}

/**
 * parse_input - Parses input string into tokens
 * @input: User input string
 *
 * Return: An array of tokens (strings)
 */
char **parse_input(char *input) {
char **tokens = malloc(MAX_TOKENS * sizeof(char *));
if (!tokens)
{
perror("malloc");
exit(EXIT_FAILURE);
}
char *token = strtok(input, " \t\n");
int i = 0;
while (token)
{
tokens[i++] = token;
oken = strtok(NULL, " \t\n");
if (i == MAX_TOKENS)
{
fprintf(stderr, "Too many arguments\n");
exit(EXIT_FAILURE);
}
}
tokens[i] = NULL;
return (tokens);
}

/**
 * execute_command - Executes a command in a child process
 * @args: Array of command arguments
 *
 * Return: 1 to continue the shell loop
 */
int execute_command(char **args)
{
pid_t pid, wpid;
int status;
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("shell");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("shell");
}
else 
{
do {
wpid = waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}

/**
 * main - Entry point of the shell program
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(void) {
char *input;
char **args;
int status;
do {
print_prompt();
input = read_input();
args = parse_input(input);
status = execute_command(args);
free(input);
free(args);
} while (status);
return (EXIT_SUCCESS);
}
