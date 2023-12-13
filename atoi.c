#include "shell.h"

/**
 * interactive - Checks if the program is running in interactive mode.
 * @info: Pointer to the information structure.
 *
 * Return: 1 if running interactively, 0 otherwise.
 */
int interactive(i_t *info)
{
if (isatty(STDIN_FILENO) && info->readfd <= 2)
{
return (1);
}
return (0);
}

/**
 * is_delim - Checks if a character is a delimiter.
 * @b: The character to check.
 * @d: The delimiter string.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delim(char b, char *d)
{
while (*d)
{
if (b == *d++)
{
return (1);
}
}
return (0);
}

/**
 * _isalpha - Checks if a character is an alphabetic character.
 * @b: The character to check.
 *
 * Return: 1 if the character is an alphabetic character, 0 otherwise.
 */

int _isalpha(int b)
{
return ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'));
}

/**
 * atoi - Converts a string to an integer.
 * @c: The string to be converted.
 *
 * Return: The converted integer value.
 */

int atoi(char *c)
{
int res = 0;
int sign = 1;
if (*c == '-')
{
sign = -1;
c++;
}
while (*c >= '0' && *c <= '9')
{
res = res * 10 + (*c - '0');
c++;
}
return (res * sign);
}
