/*      File : averages.c       *
 *       *      By   : Jake Castillo    *
 *        *      login: jakecast           *
 *         *      team : Hawaiians        *
 *          *      Date : 28 Apr 15        */

/*
 *  * A program to read values, compute their averages, and to print
 *   * the values greater than or less than the average.
 *    */
 
#include <stdio.h>
#include "avg.h"

int main()
{
  /*  Declare variables  */
  double table[MAXVALS];    /* array to hold input values */
  int n;                    /* number of values in "table" */
  double average;            /* average input value */
  int equal;                /* number of values the same as average */
  int large;                /* number of values larger then average */
  int small;                /* number of values smaller then average */

    /*  Get a set of values  */ 
    n = tableFill(table, MAXVALS);
    
    /*  Calculate the average  */
    average = tableAverage(table, n);
    printf("Average of the %d values read is: %lf\n", n, average);
    
    /*  Get values that are same to the average  */
    equal = tableMatchingElements(table, n, average);
    printf("There are %d values equal to the average.\n", equal);
    
    /*  Get values above average  */
    large = countLarger(table, n, average);
    printf("There are %i values greater than the average:\n", large);
    tablePrintIfLarger(table, n, average);

    /*  Get values below average  */
    small = countSmaller(table, n, average);
    printf("There are %i values less than the average:\n", small);
    tablePrintIfSmaller(table, n, average);

}
