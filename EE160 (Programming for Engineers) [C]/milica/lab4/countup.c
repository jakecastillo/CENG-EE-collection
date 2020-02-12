// File: countup.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 9/15/16
/*  A program to count from 1 to 20, one per line  */

#include <stdio.h>

int main()
{
	//initialize variables
	int count;
	//initialize number
        count = 1;
	
	//while loop: count is less than 20
        while (count <= 20){
                printf("%d\n", count);
                count = count + 1;
        }
}
