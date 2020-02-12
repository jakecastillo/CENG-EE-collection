// File: avgwitharray-vs2.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 10/20/16

 /* Compute average of its input values. */

#include <stdio.h>
#define MAXSIZE  999 //
int main()
{
  /*  Declare variables  */    
  int          SIZE, ARRAYLEN, next[MAXSIZE], flag; 
  int          temp;
  long         sum;                /* running total */
  unsigned int n;                  /* number of input values */
  int          result;             /* did we read another value? */
  double       avg;                /* average of input values */
    /*  initialize value  */
    sum = n = 0;
    printf("Enter values to average (ctrl+d to average) [Can't enter more than 999 values] ");
    /*  While there are more  */
        for (sum = n = 0; n < MAXSIZE && flag !=EOF; n++) {
	flag = scanf("%d", &temp);
	if ( flag != -EOF) next[n] = temp;
	}
	ARRAYLEN = n-1;
        sum = (next[0] + next[1] + next[2] + next[3] + next[4])/n;    //Add total of input
	

    /*  Print result  */
        printf("Average of %u values is %d.\n", n, sum);

}
