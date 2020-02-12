//File: swapbigtest.c
//Name: Jake Castillo
//Login: jakecast
//Date: 11/10/16

#include <stdio.h>
#include "reorder.h"
#include "swap.h"
#include "swapbig.h"

#define DEBUG


int main()
{
   float a;
   float b;
   float c;
	//scan in values for a and b
	while ( scanf("%f %f %f", &a, &b, &c) !=EOF ){
		//run swapbig function making the first pointer point to lowest number first
		reorder(&a, &b, &c);
		//print values of a and b
		printf("In order a = %f b = %f c = %f \n", a, b, c);
	}
}

