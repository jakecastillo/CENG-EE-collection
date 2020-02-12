#include<stdio.h>
#include "water.h"
#include "meter.h"

float compute_usage(int num, int *vals, int use[], int *hi_idx){
    int i;                //Counter
    double sum = 0;        //Total of values added
    float total = 0;        //Total average
    int biggest = 0; //Biggest   
    for(i = 0; i < num - 1; ++i){
	use[i] = vals[i + 1] - vals[i];

	/*  Calculate the sum  */
	sum += use[i];

	/*  Find the higest usage  */
	if(use[i] > use[biggest]){
	    biggest = i;
	}
	}
		*hi_idx = biggest;  


    /*  Calculate the average  */
    total = sum / (num - 1);

    return total;      //Return total average
}
