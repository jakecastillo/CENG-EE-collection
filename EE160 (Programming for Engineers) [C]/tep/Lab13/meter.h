/*  File:       meter.h
 *      by:         Tep Dobry
 *          date:       29 Jul 93
 *          */


float compute_usage(int num, int *vals, int use[], int *hi_idx);
/*  this function is given the count of meter readings available,
 *          and the array of meter readings.  It computes the water
 *                  usage for each hourly interval in the array use, and
 *                          returns (directly) the average usage for the day and
 *                                  (indirectly) the index of the highest water usage value.  */
