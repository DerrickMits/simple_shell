#include "shell.h"

/**
 * _strlen - Calculate the total length of an array of strings.
 * @s: A pointer to an array of strings (char **).
 *
 * Return: The total length of all strings in the array.
 */
int _strlen(char **s)
{
if (!s)
return 0;
int totalLength = 0;
while (*s != NULL)
{
char *currentString = *s;
if (currentString != NULL)
{
while (*currentString != '\0')
{
totalLength++;
currentString++; 
}
}
s++;
}
return (totalLength);
}

/**
 * _strcmp - Perform comparison of two strings.
 * @t: The first string.
 * @y: The second string.
 * Return: Negative if t < y, positive if t > y, zero if t == y
 */

int _strcmp(char *t, char **y)
{
while (*t && **y)
{
if (*t != **y)
return (*t - **y);
t++;
(*y)++;
}
if (*t == **y)
return (0);
else
return (*t < **y ? -1 : 1);
}

/**
 * starts_with - Checks if a string starts with a specified substring.
 * @w: The string to search.
 * @z: The substring to find at the beginning of the string.
 *
 * Return: If a match is found, returns a pointer to the character in the
 * string immediately after the end of the substring. Otherwise, returns NULL.
 */
char *starts_with(const char *w, const char *z)
{
for (; *z; z++, w++)
{
if (*z != *w)
{
return NULL;
}
}
return (char *)w;
}

/**
 * _strcat - Concatenates two strings.
 * @x: The destination buffer.
 * @g: The source string to concatenate.
 *
 * Return: Pointer to the destination buffer (`x`).
 */
char *_strcat(char *x, char *g)
{
char *dest = x;
while (*dest)
{
dest++;
}
while (*g)
{
*dest++ = *g++;
}
*dest = '\0';
return (x);
}
