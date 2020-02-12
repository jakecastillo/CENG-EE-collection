/*      File : countdown.c      *
 *      By   : Jake Castillo                 *
 *      login: jakecast                 *
 *      team : Hawaiians                 *
 *      Date : 2/9/14                 */

/*  A program to count from 10 down to 1, one per line and print "blastoff"  */

#include <stdio.h>

int main()
{

int count;

        count = 10;			//Set number to start

        while(count >= 0)		//Set number to end loop
        {
                printf("%d\n", count);  //Print numbers
		count = count - 1;	//Number's decreased by 1
        }

        printf("BLASTOFF!\n");

}

