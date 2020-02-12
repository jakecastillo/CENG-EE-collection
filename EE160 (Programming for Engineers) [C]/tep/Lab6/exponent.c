/*      File : exponent.c
        By   : Jake Castillo
        login: jakecast
        team : Team Jake
        Date : 9/29/16                 */

#include "exponent.h"
#include <stdio.h>
float pos_power(float base, int exponent){
  float expon_value = 1; //result
  
  if(exponent < 0){ //when exponent is negative
      return 0; //print 0
      
  }
  while (exponent > 0) //while exponent is positive
	{ 
	  expon_value = expon_value * base; //compute result
	  #ifdef DEBUG
	  printf("Exponent: %d \n", exponent);
	  #endif
	  exponent = exponent - 1; //exponent counts down
	}
	
	return expon_value; //return expon_value to driver
	  

}

