/*  File:       reading.h
 *      by:         Tep Dobry
 *          date:       29 Jul 93
 *          */

int get_data(int times[], int reads[]);
/*  given an array for hours and readings, this function reads
 *          the data from the stdin returning the number read  */

void print_results(int num, int use[], int hrs[], int hi, float avg);
/*  given number of intervals, usage and hours data, the hi index,
 *          and average, this function prints the results.  */
