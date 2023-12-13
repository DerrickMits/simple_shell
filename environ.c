#include "shell.h"

/**
 * _myenv - Displays the environment variables stored in the 'environ' global variable.
 * @info: Pointer to the information structure.
 *
 * Return: Always returns 0.
 */

int _myenv(i_t *info)
{
int i = 0;
while (environ[i])
{
printf("%s\n", environ[i++]);
}
return (0);
}

/**
 * _getenv - Retrieves the value of an environment variable.
 * @info: Pointer to the information structure.
 * @name: Name of the environment variable to retrieve.
 *
 * Return: Value of the specified environment variable, or NULL if not found.
 */

char *_getenv(i_t *info, const char *name) 
{
env_var_t *current = info->env_vars;
while (current != NULL)
{
if (strcmp(current->name, name) == 0)
{
return current->value;
}
current = current->next;
}
return NULL;
}

/**
 * _mysetenv - Sets or updates the value of an environment variable.
 * @info: Pointer to the information structure.
 * @name: Name of the environment variable.
 * @value: Value to set for the environment variable.
 * @overwrite: Flag indicating whether to overwrite if the variable already exists.
 *
 * Return: 0 on success, -1 on failure.
 */

int _mysetenv(i_t *info, char *name, char *value, int overwrite)
{
if (name == NULL || value == NULL)
{
return (-1);
}
if (overwrite || getenv(name) == NULL)
{
return setenv(name, value, 1);
}
return (0);
}

/**
 * _myunsetenv - Unsets or removes an environment variable.
 * @info: Pointer to the information structure.
 * @name: Name of the environment variable to unset.
 *
 * Return: 0 on success, -1 on failure.
 */

int _myunsetenv(i_t *info, char *name)
{
if (name == NULL)
{
return (-1);
}
return unsetenv(name);
}


/**
 * create_env_node - Creates a new node for the environment variable linked list.
 * @env_var: Environment variable string.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */

env_list_t *create_env_node(const char *env_var)
{
env_list_t *node = (env_list_t *)malloc(sizeof(env_list_t));
if (node == NULL)
{
return NULL;
}
node->var = strdup(env_var);
if (node->var == NULL)
{
free(node);
return NULL;
}
node->next = NULL;
return (node);
}

/**
 * populate_env_list - Populates the environment variable linked list.
 * @info: Pointer to the information structure.
 *
 * Return: 0 on success, -1 on failure.
 */

int populate_env_list(i_t *info)
{
env_list_t *prev = NULL;
env_list_t *head = NULL;
for (int i = 0; environ[i]; ++i)
{
env_list_t *node = create_env_node(environ[i]);
if (node == NULL)
{
while (head != NULL)
{
env_list_t *temp = head;
head = head->next;
free(temp->var);
free(temp);
}
return (-1);
}
if (prev == NULL)
{
head = node;
} else
{
prev->next = node;
}
prev = node;
}
info->env = head;
return (0);
}
