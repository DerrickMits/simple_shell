#include "shell.h"

/**
 * clear_info - Frees the memory associated with the command-line arguments
 * @info: Pointer to the information structure.
 *
 * This function frees the memory allocated for the command-line arguments
 */

void clear_info(i_t *info)
{
if (info->ave)
{
for (int i = 0; info->ave[i] != NULL; i++)
{
free(info->ave[i]);
}
free(info->ave);
info->ave = NULL;
}
info->z = 0;
}

/**
 * set_info - Sets the command-line arguments in the information structure.
 * @info: Pointer to the information structure.
 * @ave: Array of command-line arguments.
 *
 * This function sets the command-line arguments in the information structure
 * allocating memory for each argument.
 */
void set_info(i_t *info, char **ave)
{
int length;
for (length = 0; ave[length] != NULL; ++length);
info->ave = (char **)malloc((length + 1) * sizeof(char *));
for (int i = 0; i < length; ++i)
{
info->ave[i] = strdup(ave[i]);
}
info->ave[length] = NULL;
info->z = 0;
}

/**
 * free_info - Frees the memory associated with the command-line arguments
 * @info: Pointer to the information structure.
 * @z: Exit status to set in the information structure.
 *
 * This function frees the memory associated with the command-line arguments
 * in the information structure
 * and sets the exit status specified by 'z'.
 */
void free_info(i_t *info, int z)
{
if (info->ave != NULL)
{
clear_info(info);
}
info->z = z;
}
