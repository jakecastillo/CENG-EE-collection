//File: swapbig.c
//Name: Jake Castilo
//Login: jakecast
//Date: 11/10/16

#include <stdio.h>
#include "swapbig.h"
#include "swap.h"

#define DEBUG

void swap_big(float *a, float *b)
{
        float temp;
        if (*b <= *a){
	swap(a,b);
        }
}
