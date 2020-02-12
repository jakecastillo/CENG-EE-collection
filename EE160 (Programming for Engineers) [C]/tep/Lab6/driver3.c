/*      File : driver3.c
        By   : Jake Castillo
        login: jakecast
        team : Hawaiians
        Date : 2/25/15                 */

#include<stdio.h>
#include "exponent.h"

main(){ //define variables
    float base;
    int exponent;
    float expon_value;
    
    printf("Enter a base value: \n"); //prompt for base value
    scanf("%f", &base); //get base value
    printf("Enter a exponent: \n"); //prompt for exponent
    scanf("%i", &exponent); //get exponent
    
    expon_value = pos_power(base, exponent); //function from exponent.c
    
    printf("Result: %.2f \n", expon_value); //result
}
