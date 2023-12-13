#include "shell.h"
/**
 * strncpy - Copies up to 'm' characters from the source string 's' to 'd'
 * @d: Pointer to the destination string.
 * @s: Pointer to the source string.
 * @m: Maximum number of characters to copy.
 *
 * Return: Pointer to the destination string.
 */

char *strncpy(char *d, const char *s, int m)
{
char *ptr = d;
while (*s && m--) 
{
*d++ = *s++;
}
while (m-- > 0)
{
*d++ = '\0';
}
return (ptr);
}

/**
 * _strncat - Appends up to 'm' characters from the source string 's' to 'd'
 * @d: Pointer to the destination string.
 * @s: Pointer to the source string.
 * @m: Maximum number of characters to append.
 *
 * Return: Pointer to the destination string.
 */

char *_strncat(char *d, const char *s, int m)
{
char *ptr = d;
while (*d) {
d++;
}
while (m-- && *s)
{
*d++ = *s++;
}
*d = '\0';
return (ptr);
}

/**
 * strchr - Locates the first occurrence of the character 'c' in the string 's'.
 * @s: Pointer to the string.
 * @c: Character to locate.
 *
 * Return: Pointer to the first occurrence of 'c' in 's', or NULL
 */
char *strchr(const char *s, char c)
{
while (*s != c)
{
if (!*s++)
{
return NULL;
}
}
return (char *)s;
}
