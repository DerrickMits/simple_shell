#include "shell.h"

/**
 * get_history_file - Returns the path to the history file.
 * @info: Pointer to the information structure.
 *
 * This function returns a duplicate string containing the path(History file)
 *
 * Return: A dynamically allocated string with the path to the history file.
 */
char *get_history_file(i_t *info)
{
return strdup(HISTORY_FILE);
}

/**
 * write_history - Writes the command history to a file.
 * @info: Pointer to the information structure.
 *
 * This function opens the history file and writes it
 *
 * Return: 0 on success, -1 on failure.
 */
int write_history(i_t *info)
{
FILE *file = fopen(get_history_file(info), "w");
if (file == NULL)
{
return (-1);
}
history_entry *current = info->history_head;
while (current != NULL)
{
fprintf(file, "%d %s\n", current->index, current->command);
current = current->next;
}
fclose(file);
return (0);
}

/**
 * read_history - Reads command history from a file and builds it
 * @info: Pointer to the information structure.
 *
 * This function opens the history file, reads its content, and builts
 *
 * Return: 0 on success, -1 on failure.
 */
int read_history(i_t *info)
{
FILE *file = fopen(get_history_file(info), "r");
char *line = NULL;
size_t len = 0;
ssize_t read;
int linecount = 0;
if (file == NULL)
{
return (-1);
}
while ((read = getline(&line, &len, file)) != -1)
{
build_history_list(info, line, linecount++);
}
if (line)
{
free(line);
}
fclose(file);
return (0);
}

/**
 * build_history_list - Builds the command history list.
 * @info: Pointer to the information structure.
 * @buffer: The input buffer containing a history entry.
 * @linecount: The index of the history entry.
 *
 * This function creates a new history entry and adds it (command history list)
 *
 * Return: 0 on success, -1 on failure.
 */
int build_history_list(i_t *info, char *buffer, int linecount)
{
history_entry *new_entry = (history_entry *)malloc(sizeof(history_entry));
if (new_entry == NULL)
{
return (-1);
}
new_entry->command = strdup(buffer);
new_entry->index = linecount;
new_entry->next = NULL;
if (info->history_head == NULL)
{
info->history_head = new_entry;
}
else
{
history_entry *current = info->history_head;
while (current->next != NULL)
{
current = current->next;
}
current->next = new_entry;
}
return (0);
}

/**
 * renumber_history - Renumbers the indices of command history entries.
 * @info: Pointer to the information structure.
 *
 * This function updates the indices of command history entries.
 *
 * Return: 0 on success, -1 on failure.
 */
int renumber_history(i_t *info)
{
int idx = 0;
history_entry *current = info->history_head;
while (current != NULL)
{
current->index = idx++;
current = current->next;
}
return (0);
}
