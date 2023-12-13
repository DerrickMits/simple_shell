#include "shell.h"

/**
 * myexit - Handles the exit command in the shell, setting the exit error number.
 * @info: Pointer to the information structure.
 * @arg: Argument representing the exit status.
 */

int myexit(i_t *info, char *arg)
{
char *endptr;
long int val;
if (!arg || *arg == '\0')
{
info->err_num = -1;
return (-2);
}
errno = 0;
val = strtol(arg, &endptr, 10);
if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
|| (errno != 0 && val == 0))
{
perror("strtol");
return (1);
}
if (endptr == arg)
{
fprintf(stderr, "No digits were found\n");
return (1);
}
if (val < 0 || val > 255)
{
fprintf(stderr, "Illegal exit number: %ld\n", val);
return (1);
}
info->err_num = (int)val;
return (-2);
}


/**
 * mycd - Changes the current working directory based on the provided path.
 * @info: Pointer to the information structure.
 * @path: The path to change to.
 *
 * Return: 0 on success, -1 on error.
 */

int mycd(i_t *info, const char *path)
{
char oldpwd[PATH_MAX];
if (!_getenv("PWD", oldpwd, sizeof(oldpwd)))
{
info->err_num = errno;
return (-1);
}
if (path == NULL || strcmp(path, "~") == 0)
{
char homedir[PATH_MAX];
if (!_getenv("HOME", homedir, sizeof(homedir)))
{
info->err_num = errno;
return (-1);
}
path = homedir;
}
if (chdir(path) != 0)
{
info->err_num = errno;
return (-1);
}
char newpwd[PATH_MAX];
if (getcwd(newpwd, sizeof(newpwd)) == NULL)
{
info->err_num = errno;
return (-1);
}
if (_setenv("PWD", newpwd, 1) != 0)
{
info->err_num = errno;
return (-1);
}
if (_setenv("OLDPWD", oldpwd, 1) != 0)
{
info->err_num = errno;
return (-1);
}
info->pwd = strdup(newpwd);
return (0);
}

/**
 * myhelp - Displays information about the 'help' command.
 * @info: Pointer to the information structure.
 *
 * Return: Always returns 0.
 */
int myhelp(i_t *info)
{
printf("The 'help' command is recognized but not yet implemented.\n");
return (0);
}

