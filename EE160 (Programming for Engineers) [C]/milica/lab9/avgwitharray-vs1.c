// File: avgwitharray-vs1.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 10/20/16

 /* Compute average of its input values. */

#include <stdio.h>
#define SIZEOFARRAY1 5

int main()
{
  /*  Declare variables  */
  int          next[SIZEOFARRAY1];               /* next input value */
  long         sum;                /* running total */
  unsigned int n;                  /* number of input values */
  int          result;             /* did we read another value? */
  double       avg;                /* average of input values */
    /*  initialize value  */
    sum = n = 0;
    printf("Enter values to average (ctrl+d to average): ");
    /*  While there are more  */
        for (sum = n = 0; n < SIZEOFARRAY1 ; n++) {
	scanf("%d", &next[n]);
	printf("%d \n", next[n]);
	}
        sum = (next[0] + next[1] + next[2] + next[3] + next[4])/5;    //Add total of input
	

    /*  Print result  */
        printf("Average of %u values is %d.\n", n, sum);

}
