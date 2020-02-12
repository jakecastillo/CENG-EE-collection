/*  File:    util.c
 *      by:        Jake Castillo
 *          date:   14 Apr 15
 *          */

/*  This file contains the set of utilities functions  */

#include "util.h"
#include "tfdef.h"

/*   Function computes factorial of n using a for loop. */
int factorial(int n)
{    int i, product;

    product = 1;
    for (i = 1; i <= n; i = i + 1)
        product = product * i;
    return product;
}

/*  Function computes the result of the exponent  */
float pos_power(float base, int exponent){
  float expon_value = 1;  //result

    if(exponent < 0){   //If exponent is negative
        return 0;       //print 0
    }

    while(exponent > 0){    //while exponent is positive
        expon_value = expon_value * base;     //Compute result
        
        #ifdef DEBUG
        printf("Exponent: %i \n", exponent);
        #endif
         
        exponent = exponent - 1;              //Exponent decrease
    }

  return expon_value;   //return result
}

/*  Calculate the next term until the difference less than 0.00005  */ 
int close_enough(float term1, float term2){

    /*  Check if difference is less then 0.00005  */
    if(term1 - term2 <= 0.00005){
        return TRUE;    //Return true if less then
    } else {
        return FALSE;   //Return false if not
    }
}
