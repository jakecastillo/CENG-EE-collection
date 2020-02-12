/*      File : weight.c            *
 *      By   : Jake Castillo                 *
 *      login: jakecast                 *
 *      team : Hawaiians                 *
 *      Date : 2/18/15                 */

/*  A program to compute the sum of numbers given on the input  */

#include<stdio.h>

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
	printf("Enter a weight/value pair: \n");

        /*  While there is more input      */
	while ( scanf("%i %i", &weight, &input) !=EOF )
		{
                /*  Accumulate the sum     */
		sum = sum + (weight * input);
		total_weight = total_weight + weight;
		num = num + 1; //running counter
                /*  Get the next input     */
		printf("Enter a weight/value pair: \n");
		}
		//average calculation	
		avg = (float)sum / total_weight;
        /*  Print the results              */
	printf("The average of %i input vaules is: %f \n", num, avg);

}

