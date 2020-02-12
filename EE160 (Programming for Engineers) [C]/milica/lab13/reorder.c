//File: swapbig.c
//Name: Jake Castilo
//Login: jakecast
//Date: 11/10/16

#include <stdio.h>
#include "reorder.h"
#include "swap.h"
#include "swapbig.h"

#define DEBUG

void reorder(float *a, float *b, float *c)
{
	float temp;
	//keep running until in order
	while(*a > *b || *b > *c){
		//run swapbig to order numbers
			swap_big(a,b);
			swap_big(b,c);
			swap_big(a,c);
		
	}
}
