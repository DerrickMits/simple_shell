#include "shell.h"

/**
 * input_buf - Reads input from the standard input into a buffer.
 * @info: Pointer to the information structure.
 * @buf: Pointer to the buffer to store the input.
 * @len: Pointer to the length of the buffer.
 *
 * This function allocates memory for the buffer, reads input, and stores
 * the input information in the information structure.
 *
 * Return: The number of bytes read or -1 on failure.
 */

ssize_t input_buf(i_t *info, char **buf, s_t *len)
{
*buf = (char *)malloc(sizeof(char) * (*len));
if (*buf == NULL)
{
return (-1);
}
ssize_t n_read = read_buf(info, *buf, len);
if (n_read > 0)
{
info->buffer = *buf;
info->input_length = n_read;
info->buffer_size = *len;
}
return (n_read);
}

/**
 * get_input - Reads input from the standard input into a buffer.
 * @info: Pointer to the information structure.
 *
 * This function reads input from the standard input using _getline.
 *
 * Return: The number of bytes read or -1 on failure.
 */

ssize_t get_input(i_t *info)
{
size_t len = 0;
char *buf = NULL;
return _getline(info, &buf, &len);
}
ssize_t read_buf(i_t *info, char *buffer, s_t *i)
{
ssize_t read_bytes = read(STDIN_FILENO, buffer, *i);
return (read_bytes);
}

/**
 * _getline - Reads a line from the standard input into a buffer.
 * @info: Pointer to the information structure.
 * @ptr: Pointer to the buffer to store the input line.
 * @l: Pointer to the length of the buffer.
 *
 * This function reads a line from the standard input using getline,
 * and stores the input information in the information structure.
 *
 * Return: The number of bytes read or -1 on failure.
 */
int _getline(i_t *info, char **ptr, size_t *l)
{
ssize_t n_read;
char *buffer;
size_t buf_size = 1024;
if (*ptr == NULL || *l == 0)
{
*l = buf_size;
*ptr = (char *)malloc(buf_size);
 if (*ptr == NULL)
{
return (-1);
}
}
buffer = *ptr;
n_read = getline(&buffer, l, stdin);
if (n_read > 0)
{
info->buffer = buffer;
info->buffer_size = *l;
info->input_length = n_read;
}
else
{
if (buffer != *ptr)
free(buffer);
}
return (n_read);
}

/**
 * sigintHandler - Signal handler for SIGINT.
 * @sig: Signal number.
 *
 * This function writes a newline and a shell prompt after receiving a SIGINT signal.
 */
void sigintHandler(__attribute__((unused)) int sig)
{
write(STDOUT_FILENO, "\nShell Prompt > ", 15);
}
