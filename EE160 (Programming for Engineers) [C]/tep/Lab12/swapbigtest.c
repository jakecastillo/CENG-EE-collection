/*      File : swapbigtest.c       *
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

	while(scanf("%f %f", &a, &b) !=EOF) //get data, end on EOF
	{
	#ifdef DEBUG
	printf("Initial values:\t a = %f, b = %f\n",a, b); //print data recieved
	#endif

	swap_big(&a, &b); //recall swap_big

	#ifdef DEBUG
	printf("Final values:\t a = %f, b = %f\n\n",a, b); //print final data
	#endif
}
}

