/*      File : avg.c            *
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
	int answer=0;
	int num=0;
	float avg;
        /*  Get the first input            */
	printf("Enter a number: \n");

        /*  While there is more input      */
	while ( scanf("%i", &input) !=EOF )
		{
                /*  Accumulate the sum     */
		answer = answer + input;
		num = num + 1; //running counter
                /*  Get the next input     */
		printf("Enter a number: \n");
		}
		//average calculation	
		avg = (float)answer / num;
        /*  Print the results              */
	printf("The average of %i input vaules is: %f \n", num, avg);

}

