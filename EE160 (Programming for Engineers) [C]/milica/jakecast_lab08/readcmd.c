/*      File : readcmd.c        *
 *      By   : Jake Castillo                 *
 *      login: jakecast                 *
 *      team : Team Jake                 *
 *      Date : 13 Oct 16                 */

/*
 * Read a command, skipping over leading blanks and any trailing
 * characters.
 */

#include <stdio.h>

//declare variables
int skipBlanks(void);
int skipOverRestOfCommand(void);

int main()
{
    //initialize variables
    int cmd;
    cmd = skipBlanks();
    while (cmd != EOF){	
	//while cmd is not end of file, run loop
	//if character is a-z or A-Z
	if ((cmd >= 'a' && cmd <= 'z') || (cmd >= 'A' && cmd <= 'Z')){
	    printf("The command is: %c\n", cmd); //print first character
	    skipOverRestOfCommand();
	}

	else if(cmd == ';' || cmd == '\n'){ 
	    //if ; or space, tell user that command is missing
	    printf("Error: missing command\n");
	}

	else{
	    printf("Error: %c is not a letter\n", cmd); 
	    //If something else is entered, it will print first
	    //character and say it is not a letter
	    skipOverRestOfCommand();
	}
	cmd = skipBlanks();
    }
}

//function to skip over blanks
int skipBlanks(void){
    int c;
 
    c = getchar(); //get character
    while (c == ' ' || c== '\t') 
	//if character is a space or a tab, 
	//c = the character they enter first
	c = getchar();
    return c; //give back c
}

//bunction to skip rest of command
int skipOverRestOfCommand(void){
    int c;

    c = getchar(); //get character
    while (c != '\n' && c != ';')
	c = getchar();
    return c;
}
