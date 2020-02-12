// File: questions.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 10/20/16

/*  Ask the user a question. */

#include <stdio.h>
#include "tfdef.h"
#define UPPER 1
#define IS_UPPER(c) ((c) >= 'A' && (c) <= 'Z')

int yesOrNo(void);
int tolower(int c);

int main()
{
        printf("Don't you just love this class? ");
        if (yesOrNo()){
                printf("YES!  We knew it.\n");
		}
        else{
                printf("NO?  Come on, you know you love this class.\n");
	}
}

int  yesOrNo(void)
{
  int answer;                        /* holds input character */
  int c;

        while(c = getchar())
        {
                /* process each input line */
                if ((answer = tolower(c)) == EOF) {
                        return FALSE;
		}                  /* EOF is NO! */
                /* read characters until the end of the line */
                while (c != '\n' && c != EOF){
                        c = getchar();
                }
                /* return an appropriate value for Yes or No */
                if (answer == 'y'){
                        return TRUE;
		}
                if (answer == 'n'){
                        return FALSE;
		}

                /* error message if there's a problem */
                printf("Please answer with a YES or NO: ");
		}
}

int tolower(int c){
	if(IS_UPPER(c)) return c - 'A' + 'a' ;
	return c;
}	
