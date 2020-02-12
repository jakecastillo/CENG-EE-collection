// File: weight.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 9/22/16

/*  A program to compute the sum of numbers given on the input  */

#include <stdio.h>

int main()
{

        /*  Initialize the average             */
	int input;
	int weight;
	int num=0;
	int sum=0;
	int total_weight=0;
	float avg;
        /*  Get the first input            */
	printf("Enter a weight/value pair (ctrl + d to end): ");

        /*  While there is more input      */
	while ( scanf("%i %i", &weight, &input) !=EOF )
	{
                /*  Accumulate the sum     */
		sum = sum + (weight * input);
		total_weight = total_weight + weight;
		num = num + 1; //running counter
                /*  Get the next input     */
		printf("Enter a weight/value pair (ctrl + d to end): ");
	}
	//average calculation	
	avg = (float)sum / total_weight;
        /*  Print the results              */
	printf("\nThe average of %i input vaules is: %f \n", num, avg);

}

