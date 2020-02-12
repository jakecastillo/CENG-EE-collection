// File: countdown.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 9/15/16

/*  A program to count from 10 down to 1, one per line and print "blastoff"  */

#include <stdio.h>

int main()
{
//initialize variables
int count;

        count = 10;                     //Set number to start

        while(count >= 0){               //Set number to end loop
                printf("%d\n", count);  //Print numbers
                count = count - 1;      //Number's decreased by 1
        }

        printf("BLASTOFF!\n");

}
