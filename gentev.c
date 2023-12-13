#inlcude "shell.h"

/**
 * get_environ - Retrieves the environment variables from the given information structure.
 * @info: Pointer to the information structure.
 *
 * Return: Pointer to the array of environment variables.
 */


char **get_environ(i_t *info)
{
return info->env;
}

/**
 * _unsetenv - Unsets the environment variable specified by 'var'.
 * @info: Pointer to the information structure.
 * @var: Name of the environment variable to unset.
 *
 * Return: 0 on success, -1 on failure.
 */

int _unsetenv(i_t *info, char *var)
{
int i = 0;
int var_len = strlen(var);
for (i = 0; info->env[i] != NULL; i++)
{
if (strncmp(info->env[i], var, var_len) == 0 && info->env[i][var_len] == '=')
{
while (info->env[i] != NULL)
{
info->env[i] = info->env[i + 1];
i++;
}
return (0);
}
}
return (-1);
}

/**
 * _setenv - Sets the environment variable specified by 'var' to the given 'value'.
 * @info: Pointer to the information structure.
 * @var: Name of the environment variable.
 * @value: Value to set for the environment variable.
 *
 * Return: 0 on success, -1 on failure.
 */

int _setenv(i_t *info, char *var, char *value)
{
int i = 0;
int var_len = strlen(var);
char *new_env_entry;
for (i = 0; info->env[i] != NULL; i++)
{
if (strncmp(info->env[i], var, var_len) == 0 && info->env[i][var_len] == '=')
{
free(info->env[i]);
break;
}
}
int new_entry_len = var_len + strlen(value) + 2; // Include space for '=' and '\0'
new_env_entry = (char *)malloc(new_entry_len);
if (!new_env_entry)
{
return (-1);
}
snprintf(new_env_entry, new_entry_len, "%s=%s", var, value);
if (info->env[i] != NULL)
{
info->env[i] = new_env_entry;
}
else
{
info->env = realloc(info->env, (i + 2) * sizeof(char *));
if (!info->env)
{
free(new_env_entry);
return (-1);
}
info->env[i] = new_env_entry;
info->env[i + 1] = NULL;
}
return (0);
}
