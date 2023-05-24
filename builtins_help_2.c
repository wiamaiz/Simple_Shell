#include "shell.h"

void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);

/**
 * help_env - Displays information on the shellby builtin command 'env'.
 */
void help_env(void)
{
    char *msg = "env: env\n\tPrints the current environment.\n";

    write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_setenv - Displays information on the shellby builtin command 'setenv'.
 */
void help_setenv(void)
{
    char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";
    /* Alternative description for help_setenv */
    char *altMsg = "setenv: setenv [VARIABLE] [VALUE]\n\tDefines or modifies an environment variable.\n";

    write(STDOUT_FILENO, altMsg, _strlen(altMsg));
}

/**
 * help_unsetenv - Displays information on the shellby builtin command 'unsetenv'.
 */
void help_unsetenv(void)
{
    char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";
    /* Alternative description for help_unsetenv */
    char *altMsg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an environment variable.\n";

    write(STDOUT_FILENO, altMsg, _strlen(altMsg));
}

