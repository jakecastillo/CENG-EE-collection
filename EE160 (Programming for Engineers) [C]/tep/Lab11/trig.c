/*  File:    trig.c
 *      by:        Jake Castillo
 *          date:   14 Apr 15
 *          */

/*  This file contains functions for cos  */

#include "trig.h"
#include "util.h"
#include "tfdef.h"

/*  Calculate the cos of an angle (radians) using the Taylor series  */
double cos_angle(float radians){
  /*  Declare variables  */
  int n = 1;
  float degree;
  float term1, term2;
  double angle;

    /*  Convert radians to degree  */
    degree = radians * (180.0 / PI);
    
    /*  While difference in terms is not true  */
    while(!close_enough(term1, term2)){
        /*  Calculate of the equation  */
        term1 = pos_power(-1, n);
        term2 = pos_power(degree, 2 * n) / factorial(2*n);
    }
    
    angle = term1 - term2;
    
    /*  Return answer  */
    return angle;
    
}
