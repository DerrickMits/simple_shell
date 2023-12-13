#include "shell.h"

/**
 * myhistory - Displays the command history stored in the information structure.
 * @info: Pointer to the information structure.
 *
 * Return: Always returns 0.
 */

int myhistory(i_t *info) 
{
if (info && info->history) 
{
print_list(info->history);
} else 
{
printf("No history available.\n");
}
return (0);
}

/**
 * print_list - Prints the command history linked list.
 * @list: Pointer to the head of the history linked list.
 */

void print_list(const t_history *list) 
{
int count = 0;
while (list != NULL) 
{
printf("%d: %s\n", ++count, list->command);
list = list->next;
}
}

/**
 * delete_alias - Deletes an alias with the specified name.
 * @info: Pointer to the information structure.
 * @s: Name of the alias to be deleted.
 *
 * Return: 0 on success, -1 on failure.
 */

int delete_alias(i_t *info, char *s) 
{
t_alias *current = info->aliases;
t_alias *prev = NULL;
while (current != NULL) 
{
if (strcmp(current->name, s) == 0) 
{
if (prev == NULL) 
{
info->aliases = current->next;
}
else
{
prev->next = current->next;
}
free(current->name);
free(current->value);
free(current);
return (0);
}
prev = current;
current = current->next;
}
return (-1);
}


/**
 * set_alias - Sets or updates an alias with the provided name and value.
 * @info: Pointer to the information structure.
 * @s: String containing alias name and value.
 *
 * Return: 0 on success, -1 on failure.
 */

int set_alias(i_t *info, char *s) 
{
char *name, *value, *equals;
equals = strchr(s, '=');
if (equals == NULL) 
{
return (-1);
}
name = strndup(s, equals - s);
if (name == NULL) 
{
return (-1);
}
value = equals + 1;
unset_alias(info, name);
if (*value == '\0')
{
free(name);
} 
else 
{
if (add_alias(info, name, value) != 0) 
{
free(name);
return (-1);
}
}
free(name);
return (0);
}

/**
 * unset_alias - Unsets or removes an alias with the specified name.
 * @info: Pointer to the information structure.
 * @name: Name of the alias to be unset.
 *
 * Return: 0 on success, -1 on failure.
 */

int unset_alias(i_t *info, char *name) 
{
t_alias *current = info->aliases, *prev = NULL;
while (current)
{
if (strcmp(current->name, name) == 0)
{
free(current->name);
free(current->value);
if (prev)
{
prev->next = current->next;
} else 
{
info->aliases = current->next;
}
free(current);
return (0);
}
prev = current;
current = current->next;
}
return (-1);
}
int add_alias(i_t *info, char *name, char *value)
{
t_alias *new_alias = (t_alias *)malloc(sizeof(t_alias));
if (!new_alias)
{
return (-1);
}
new_alias->name = strdup(name);
new_alias->value = strdup(value);
if (!new_alias->name || !new_alias->value)
{
free(new_alias->name);
free(new_alias->value);
free(new_alias);
return (-1);
}
new_alias->next = info->aliases;
info->aliases = new_alias;
return (0);
}


/**
 * add_alias - Adds a new alias with the specified name and value.
 * @info: Pointer to the information structure.
 * @name: Name of the new alias.
 * @value: Value of the new alias.
 *
 * Return: 0 on success, -1 on failure.
 */


int print_alias(l_t *node)
{
if(node == NULL)
{
return (-1);
}  
printf("alias %s='%s'\n", node->name, node->value);
return (0);
}
/**
 * find_alias - Finds an alias with the specified name.
 * @info: Pointer to the information structure.
 * @name: Name of the alias to be found.
 *
 * Return: Pointer to the found alias or NULL if not found.
 */

alias_t *find_alias(i_t *info, const char *name)
{
alias_t *current = info->alias_list;
while (current != NULL)
{
if (strcmp(current->name, name) == 0)
{
return (current);
}
current = current->next;
}
return NULL;
}
/**
 * create_alias - Creates a new alias with the specified name and command.
 * @name: Name of the new alias.
 * @command: Command value of the new alias.
 *
 * Return: Pointer to the newly created alias or NULL on failure.
 */

alias_t *create_alias(const char *name, const char *command)
{
alias_t *new_alias = malloc(sizeof(alias_t));
if (new_alias == NULL)
{
return NULL;
}
new_alias->name = strdup(name);
new_alias->command = strdup(command);
new_alias->next = NULL;
return (new_alias);
}

/**
 * _myalias - Sets or updates an alias with the provided name and command.
 * @info: Pointer to the information structure.
 * @alias_name: Name of the alias to be set or updated.
 * @alias_command: Command value of the alias.
 *
 * Return: 0 on success, -1 on failure.
 */

int _myalias(i_t *info, char *alias_name, char *alias_command)
{
if (alias_name == NULL || alias_command == NULL)
{
printf("Usage: alias name='command'\n");
return (-1);
}
alias_t *existing_alias = find_alias(info, alias_name);
if (existing_alias != NULL)
{
free(existing_alias->command);
existing_alias->command = strdup(alias_command);
}
else 
{
alias_t *new_alias = create_alias(alias_name, alias_command);
if (new_alias == NULL) {
perror("Allocation error");
return (-1);
}
new_alias->next = info->alias_list;
info->alias_list = new_alias;
}
return (0);
}
