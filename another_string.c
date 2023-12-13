#include "shell.h"

/**
 * _strcpy - Copy the content of the source string to the destination buffer.
 * @y: A pointer to a pointer to a character, representing the destination buffer.
 * @s: A pointer to a character, representing the source string.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char **y, char *s)
{
char *dest = *y;
char *ret = dest;
for (; *s; s++, dest++)
{
*dest = *s;
}
*dest = '\0';
*y = ret;
return (ret);

/**
 * _strdup - Duplicate a string.
 * @str: A pointer to a constant character, representing the input string.
 *
 * Return: A pointer to allocated memory containing a duplicate string.
 * Returns NULL if memory allocation fails or if the input string is NULL.
 */

char *_strdup(const char *str)
{
if (str == NULL)
return NULL;
size_t length = 0;
const char *temp = str;
while (*temp++)
{
length++;
}
char *duplicate = (char *)malloc(length + 1);
if (duplicate == NULL)
{
return NULL;
}
for (size_t i = 0; i <= length; i++) {
duplicate[i] = str[i];
}
return (duplicate);
}


/**
 * _puts - Prints a string to the standard output.
 * @str: The string to be printed.
 */
void _puts(char *str)
{
char *current_char = str;
if (str != NULL)
{
while (*current_char != '\0')
{
write(1, current_char, 1);
current_char++;
}
}
write(1, "\n", 1);
}

/**
 * _putchar - Emulates the behavior of the stdout
 * @b: The character to be written.
 *
 * Return: 1 on success.
 */
int _putchar(char b) 
{
static int position = 0;
static char buffer[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || position >= WRITE_BUF_SIZE) {
write(1, buffer, position);
position = 0;
}
if (b != BUF_FLUSH)
{
buffer[position++] = b;
}
return (1);
}
