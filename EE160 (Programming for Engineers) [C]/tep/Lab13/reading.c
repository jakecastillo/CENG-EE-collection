/*  File:       reading.c
 *      by:         Tep Dobry
 *          date:       29 Jul 93
 *          */
         
#include <stdio.h>
#include "water.h"
#include "reading.h"
 

int get_data(int times[], int reads[])
/*  given an array for hours and readings, this function reads
 *          the data from the stdin returning the number read  */
{  int i = 0;

        /*  while there is more data  */
        while((i < (HOURS + 1)) && (scanf("%d:00", times+i) != EOF))
        {       /*  read data  */
                scanf("%d", reads+i);
                /*  increment counter  */
                i++;
        }

        /*  return count  */
        return i;   
}

void print_results(int num, int use[], int hrs[], int hi, float avg)
/*  given number of intervals, usage and hours data, the hi index,
 *          and average, this function prints the results.  */   
{  int i;

        /*  print the usage data  */
        for(i = 0; i < num - 1; i++)
                printf("\t\t%2d:00\t%d\n",hrs[i], use[i]);
                
        printf("\n\nthe average usage was %f\n", avg);
        printf("the hi usage was %d at %d:00\n",use[hi], hrs[hi]);
}
