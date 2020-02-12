/*      File : swapreordertest.c       *
 *      By   : Jake Castillo                 *
 *      login: jakecast                 *
 *      team : Hawaiians                 *
 *      Date : 4/22/15                 */

/*
 * A test driver for testing the swap() function
 */

#include <stdio.h>
#include "swap.h"

#define DEBUG


int main()
{
//define variables
   float a;
   float b;
   float c;

	while(scanf("%f %f %f", &a, &b, &c) !=EOF) //get data a, b, c. End on EOF.
	{
	#ifdef DEBUG
	printf("Initial values:\t a = %f, b = %f c = %f\n",a, b, c); //print initial data
	#endif

	reorder(&a, &b, &c); //recall reorder

	#ifdef DEBUG
	printf("Final values:\t a = %f, b = %f c = %f\n\n",a, b, c); //print final data
	#endif
}
}

