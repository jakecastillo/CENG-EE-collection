// Title: sum.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 9/15/16

/*  A program to compute the sum of numbers given on the input  */

#include<stdio.h>

int main()
{

        /*  Initialize the sum             */
	int input;
	int answer=0;
        /*  Get the first input            */
	printf("Enter a number (ctrl+d to get sum): \n");
        /*  While there is more input      */
	while ( scanf("%i", &input) !=EOF ){
                /*  Accumulate the sum     */
		answer = answer + input;

                /*  Get the next input     */
		printf("Enter a number (ctrl+d to get sum): \n");
	}
        /*  Print the results              */
	printf("The sum is: %i \n", answer);

}

