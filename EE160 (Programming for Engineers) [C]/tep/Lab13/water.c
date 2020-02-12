/*  File:       water.c
 *      by:         Tep Dobry
 *          date:       29 Jul 93
 *          */

#include <stdio.h>
#include "water.h"
#include "meter.h"
#include "reading.h"

main()
{  int time[HOURS+1];           /*  the hours array */
   int readings[HOURS+1];       /*  the meter readings data  */
   int usage[HOURS];            /*  the useage for each hour interval  */
   int hours;                   /*  the number of data readings  */
   int hi;                      /*  index of the highest usage  */
   float avg;                   /*  average usage for the day  */

        /*  get the readings data  */
        hours = get_data(time, readings);

        /*  process the data  */
        avg = compute_usage(hours, readings, usage, &hi);

        /*  print the results  */
        print_results(hours,usage,time,hi,avg);

}
