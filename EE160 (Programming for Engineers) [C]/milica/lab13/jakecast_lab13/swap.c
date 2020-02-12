/*      File : swap.c           *
//File: swap.c
//By: Jake Castillo
//Login: jakecast
//Team: Team Jake
//Date: 11/10/16

/* A function to swap floarting point values using pointers. */

#include <stdio.h>
#include "swap.h"

//#define DEBUG


void swap( float *x, float *y)
/* Given: pointers to two floating point variables
 *    Returns: nothing directly, swaps values at the two adresses given
 *     */
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
