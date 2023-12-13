#include "shell.h"

/**
 * _eputs - Writes a null-terminated string to the standard error stream
 * @s: The string to be written.
 */

void _eputs(char *s)
{
while (*s)
{
_eputchar(*s++);
}
}


/**
 * _eputchar - Writes a character to the standard error stream
 * @c: The character to be written.
 *
 * Return: On success, returns (characters written). On buffer flush
 */

int _eputchar(char c)
{
static char buffer[BUFFER_SIZE];
static int i = 0;
int written;
if (c == '\n' || i >= BUFFER_SIZE - 1)
{
written = write(2, buffer, i);
i = 0;
if (c == '\n')
{
buffer[0] = c;
write(2, buffer, 1);
}
return (written);
}
buffer[i++] = c;
return (i);
}

/**
 * _putfd - Writes a character to a file descriptor
 * @s: The character to be written.
 * @f: The file descriptor to write to.
 *
 * Return: On success, returns(updated buffer index). Or On buffer flush
 */
int _putfd(char s, int f)
{
if (s == BUF_FLUSH || buffer_index == WRITE_BUF_SIZE)
{
_flush_buffer(f);
if (s == BUF_FLUSH)
{
return write(f, &s, 1);
}
}
buffer[buffer_index++] = s;
return (buffer_index);
}



/**
 * _putfd - Writes a character to a file descriptor
 * @c: The character to be written.
 * @fd: The file descriptor to write to.
 *
 * Return: Always returns 1.
 */

int _putfd(char c, int fd)
{
if (c == BUF_FLUSH || write_index == WRITE_BUF_SIZE)
{
_flush_buffer(fd);
}
if (c != BUF_FLUSH)
{
write_buffer[write_index++] = c;
}
if (write_index == WRITE_BUF_SIZE - 1 || c == BUF_FLUSH)
{
_flush_buffer(fd);
}
return (1);
}

/**
 * _putsfd - Writes a null-terminated string to a file descriptor
 * @s: The string to be written.
 * @fd: The file descriptor to write to.
 *
 * Return: Returns the number of characters written.
 */

int _putsfd(char *s, int fd)
{
int count = 0;
while (*s)
{
_putfd(*s++, fd);
count++;
}
_flush_buffer(fd);
return (count);
}
