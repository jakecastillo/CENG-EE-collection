/*      File : swap.c           *
 *      By   : Jake Castillo                 * 
 *      login: jakecast                 *
 *      team : Hawaiians                 *
 *      Date : 4/22/15                 */

/*
 *  A function to swap floarting point values using pointers.
 */

#include <stdio.h>
#include "swap.h"

//define DEBUG


void swap( float *x, float *y)
/* Given: pointers to two floating point variables
   Returns: nothing directly, swaps values at the two adresses given
 */
{
   float temp;

	#ifdef DEBUG
	printf("\tEntering sawp() with\n");
	printf("\t\tx is address = %x, contents %f\n", x, *x);
	printf("\t\ty is address = %x, contents %f\n", y, *y);
	#endif

	/* save first value  */
	temp = *x;

	/* move second value to first  */
	*x = *y;

	/* restore first value to second */
	*y = temp;

	#ifdef DEBUG
	printf("\tExiting sawp() with\n");
	printf("\t\tx is address = %x, contents %f\n", x, *x);
	printf("\t\ty is address = %x, contents %f\n", y, *y);
	#endif

}

void swap_big(float *a, float *b) //make a smaller than b

{
	if(*a >= *b) //swap if a is greater than or equal to b
	{ swap(a,b); //recall swap function
}
}

void reorder(float *a, float *b, float *c) //order a, b, c in numerical order
{
	swap_big(a,b); //recall swap_big function
	swap_big(a,c); //recall swap_big function
	swap_big(b,c); //recall swap_big function
}
