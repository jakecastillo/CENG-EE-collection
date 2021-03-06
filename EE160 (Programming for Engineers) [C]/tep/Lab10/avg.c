/*      File : avg.c            *
 *       *      By   : Jake Castillo    *
 *        *      login: jakecast           *
 *         *      team : Hawaiians        *
 *          *      Date : 1 Apr 15         */

/*
 *  * Compute average of its input values.
 *   */

#include <stdio.h>

int main()
{
  /*  Declare variables  */
  int          next;               /* next input value */
  long         sum;                /* running total */
  unsigned int n;                  /* number of input values */
  int          result;             /* did we read another value? */
  double       avg;                /* average of input values */
    /*  initialize value  */
    sum = n = 0;

    /*  While there are more  */
    while((result = scanf("%d", &next)) == 1){
        n++;            //Count number of input values
        sum += next;    //Add total of input
    }

    /*  Print result  */
    if (result != EOF)
        printf("Warning: bad input after reading %u values\n", n);
        printf("Average of %u values is %f.\n", n, (n == 0) ? 0.0 : (double) sum / n);

}
