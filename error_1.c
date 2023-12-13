#include "shell.h"

/**
 * _erratoi - Converts a string to an integer with error handling.
 * @t: The input string to be converted.
 *
 * Return: The integer value of the converted string.
 */

int _erratoi(char *t) 
{
int num = 0;
int sign = 1;
if (*t == '-') 
{
sign = -1;
t++;
}
while (*t != '\0')
{
num = num * 10 + (*t - '0');
t++;
}
return (num * sign);
}


/**
 * struct i_t - A structure to store error information.
 * @filename: The name of the file where the error occurred.
 * @line: The line number in the file where the error occurred.
 * @progname: The name of the program experiencing the error.
 */

typedef struct
{
const char *filename;
int line;
const char *progname;
} i_t;

/**
 * print_error - Prints an error message along with relevant information.
 * @info: Pointer to the error information structure.
 * @estr: The error message string to be printed.
 */

void print_error(i_t *info, char *estr);
void print_error(i_t *info, char *estr)
{
if (info != NULL) 
{
fprintf(stderr, "Error: %s\nProgram: %s\nFile: %s\nLine: %d\n",
estr,
info->progname,
info->filename,
info->line);
}
}

/**
 * print_char - Writes a character to the specified file descriptor.
 * @c: The character to be written.
 * @fd: The file descriptor where the character should be written.
 *
 * Return: Upon success, returns the number of characters written.
 */

int print_char(char c, int fd)
{
return write(fd, &c, 1);
}

/**
 * print_d - Prints an integer to the specified file descriptor.
 * @input: The integer to be printed.
 * @fd: The file descriptor where the integer should be written.
 *
 * Return: The total number of characters written.
 */

int print_d(int input, int fd) 
{
int char_count = 0;
if (input < 0)
{
char_count += print_char('-', fd);
input = -input;
}
if (input / 10)
{
char_count += print_d(input / 10, fd);
}
char_count += print_char('0' + input % 10, fd);
return (char_count);
}

/**
 * convert_number - Converts a long integer to a string in the specified base.
 * @num: The long integer to be converted.
 * @base: The base for conversion (e.g., 10 for decimal)
 * @flags: Flags to modify conversion behavior
 *
 * Return: A pointer to the converted string.
 */

static char buffer[65];
char *convert_number(long int num, int base, int flags)
{
char *ptr = &buffer[sizeof(buffer) - 1];
bool is_negative = false;
*ptr = '\0';
const char *digits = (flags & FLAG_UPPERCASE) ? "0123456789ABCDEF" : "0123456789abcdef";
if (flags & FLAG_SIGNED && num < 0)
{
is_negative = true;
num = -num;
}
do {
ptr--;
*ptr = digits[num % base];
num /= base;
} while (num != 0);
if (is_negative)
{
ptr--;
*ptr = '-';
}
return (ptr);
}

/**
 * remove_comments - Removes comments
 * @buf: The input buffer containing the string with comments.
 *
 * This function iterates through the characters
 * comments starting with a '#' character
 * modifying the original buffer
 */

void remove_comments(char *buf)
{
while (*buf) 
{
if (*buf == '#')
{
*buf = '\0';
break;
}
buf++;
}
}
