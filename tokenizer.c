#include "shell.h"

/**
 * strtow - Split a string into an array of words based on delimiters.
 * @s: The input string to be split.
 * @e: The set of delimiters used for splitting.
 *
 * Return: An array of strings containing the words. NULL if memory allocation fails
 * or if the input string or delimiters are NULL.
 */
char **strtow(char *s, char *e)
char *s;
char *e;
int num_words;
int i;
char **words;
char *word_end;
int k;

{
if (s == NULL || e == NULL) {
return NULL;
}
int num_words = 0;
for (char *p = s; *p != '\0'; p++)
{
if (!is_delim(*p, e) && (is_delim(*(p + 1), e) || *(p + 1) == '\0'))
{
num_words++;
}
}
char **words = (char **)malloc((num_words + 1) * sizeof(char *));
if (words == NULL)
{
return NULL;
}
int i = 0;
while (*s != '\0')
{
while (is_delim(*s, e))
{
s++;
}
char *word_end = s;
while (!is_delim(*word_end, e) && *word_end != '\0')
{
word_end++;
}
words[i] = (char *)malloc((word_end - s + 1) * sizeof(char));
if (words[i] == NULL) 
{
for (int j = 0; j < i; j++)
{
free(words[j]);
}
free(words);
return NULL;
}
int k = 0;
while (s < word_end)
{
words[i][k++] = *s++;
}
words[i][k] = '\0';
i++;
}
words[i] = NULL;
return (words};
}

/**
 * free_strtow - Free memory allocated by strtow.
 * @words: The array of strings to be freed.
 */
void free_strtow(char **words)
char **words;
{
if (words != NULL)
{
for (int i = 0; words[i] != NULL; i++)
{
free(words[i]);
}
free(words);
}
}

/**
 * strtow2 - splits a string into an array of words based on a delimiter
 * @s: the input string
 * @e: the delimiter character
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *s, char e)
{
if (s == NULL || *s == '\0')
{
return NULL;
}

char **result = NULL;
int i, j, word_count = 0;
for (i = 0; s[i] != '\0'; i++) {
if (s[i] != e && (s[i + 1] == e || s[i + 1] == '\0'))
{
word_count++;
}
}

result = (char **)malloc((word_count + 1) * sizeof(char *));
if (result == NULL)
{
return NULL;
}
for (i = 0, j = 0; j < word_count; j++)
{
while (s[i] == e)
{
i++;
}
int word_length = 0;
while (s[i + word_length] != e && s[i + word_length] != '\0')
{
word_length++;
}
result[j] = (char *)malloc((word_length + 1) * sizeof(char));
if (result[j] == NULL)
{
for (int k = 0; k < j; k++)
{
free(result[k]);
}
free(result);
return NULL;
}
for (int k = 0; k < word_length; k++)
{
result[j][k] = s[i + k];
}
result[j][word_length] = '\0';
i += word_length;
}
result[word_count] = NULL;
return (result);
}

