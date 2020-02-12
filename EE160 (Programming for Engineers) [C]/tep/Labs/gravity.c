 
/*     File : gravity.c     *
 *     By   : Jake Castillo               *
 *     login: jakecast              *
 *     Date : 1/28/15              */
 
/*
 *   This program computes the velocity and height of a falling
 *   object given the time.
 */

#include<stdio.h> 
 
main()
{  float velocity;
   float time;
   float distance;
 
        /*  get time from user  */
        printf("Enter time: ");
	scanf("%f", &time);
 
        /*  compute the velocity */
        velocity = 32.0 * time;
 
        /*  compute the distance  */
        distance = 32 * time * time / 2;
 
        /*  print the result  */
        printf("An object falling %4.2f feet in %4.2f seconds\n", distance, time);
        printf("is traveling %4.2f ft/sec\n",velocity);
 
}
