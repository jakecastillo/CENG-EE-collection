/*      File : driver1.c      
        By   : Jake Castillo                 
        login: jakecast                 
        team : Hawaiiians           
        Date : 2/25/15                 */

#include<stdio.h>
#include "maxmin.h"

main(){
    float n1;
    float n2;
    float minimum;
    float maximum;
    
    printf("Enter two values (1st 2nd) [To quit enter EOF]: \n"); //prompt user for two values
    while ( scanf("%f %f", &n1, &n2) !=EOF) //get two values
    {
    minimum = min(n1, n2); //function in maxmin.c
    maximum = max(n1, n2); //function in maxmin.c
    printf("%.1f is the minimum and %.1f is the maximum. \n\n", minimum, maximum);
    printf("Enter two values (1st 2nd) [To quit enter EOF]: \n"); //get two values
    }

}
