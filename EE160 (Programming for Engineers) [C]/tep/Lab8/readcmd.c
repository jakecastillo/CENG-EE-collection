/*      File : readcmd.c        *
 *      By   : Jake Castillo                 *
 *      login: jakecast                 *
 *      team : Hawaiians                 *
 *      Date : 11 Mar 15                 */

/*
 * Read a command, skipping over leading blanks and any trailing
 * characters.
 */

#include <stdio.h>

int skipBlanks(void);
int skipOverRestOfCommand(void);

int main()
{
    int cmd;

    cmd = skipBlanks();
    while (cmd != EOF)
    {	
	if ((cmd >= 'a' && cmd <= 'z') || (cmd >= 'A' && cmd <= 'Z'))
	{
	    printf("The command is: %c\n", cmd);
	    skipOverRestOfCommand();
	}

	else if(cmd == ';' || cmd == '\n')
	{
	    printf("Error: missing command\n");
	}

	else
	{
	    printf("Error: %c is not a letter\n", cmd);
	    skipOverRestOfCommand();
	}
	cmd = skipBlanks();
    }
}

int skipBlanks(void)
{
    int c;

    c = getchar();
    while (c == ' ' || c== '\t')
	c = getchar();
    return c;
}

int skipOverRestOfCommand(void)
{
    int c;

    c = getchar();
    while (c != '\n' && c != ';')
	c = getchar();
    return c;
}
