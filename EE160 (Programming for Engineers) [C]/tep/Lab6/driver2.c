/*      File : driver2.c      
        By   : Jake Castillo                 
        login: jakecast                 
        team : Hawaiians                 
        Date : 2/25/15                 */

#include<stdio.h>
#include "maxmin.h"
//#define DEBUG
main(){
    float n;
    float minimum;
    float maximum;
    
    printf("Enter value [To quit enter EOF]: \n"); //prompt user for value
    while ( scanf("%f", &n) !=EOF) //get 
    {
    minimum = min(n, minimum); //function in maxmin.c
    maximum = max(n, maximum); //function in maxmin.c
    #ifdef DEBUG
    printf("%.1f is the minimum and %.1f is the maximum. \n", minimum, maximum);
    #endif
    printf("Enter value [To quit enter EOF]: \n"); //get value
    }
    printf("%.1f is the minimum and %.1f is the maximum \n", minimum, maximum);
}
