//File: swapbigtest.c
//Name: Jake Castillo
//Login: jakecast
//Date: 11/10/16

#include <stdio.h>
#include "swapbig.h"

#define DEBUG


int main()
{
   float a;
   float b;
	//scan in values for a and b
	while ( scanf("%f %f", &a, &b) !=EOF ){
	//run swapbig function making the first pointer point to lowest number first
	swap_big(&a, &b);
	//print values of a and b
	printf("%f is less than %f\n", a, b);
	}
}

