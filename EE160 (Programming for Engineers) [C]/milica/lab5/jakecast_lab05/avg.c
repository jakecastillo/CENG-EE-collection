// File: avg.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 9/22/16

/*  A program to compute the sum of numbers given on the input  */

#include <stdio.h>

int main()
{

        /*  Initialize the average             */
	int input=0;
	int answer=0;
	int num=0;
	float avg;
        /*  Get the first input            */
	printf("Enter a number: ");

        /*  While there is more input      */
	while ( scanf("%i", &input) !=EOF )
		{
                /*  Accumulate the sum     */
		answer = answer + input;
		num = num + 1; //running counter
                /*  Get the next input     */
		printf("Enter a number: ");
		}
		//average calculation
	if(num == 0)
	{
		printf("This is not a number\n");
	}
	else
	{
		avg = (float)answer / num;
        /*  Print the results              */
	printf("\nThe average of %i input vaules is: %f \n", num, avg);

	}
}

