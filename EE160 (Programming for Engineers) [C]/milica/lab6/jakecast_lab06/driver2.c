/*      File : driver2.c      
        By   : Jake Castillo                 
        login: jakecast                 
        team : Team Jake                 
        Date : 9/29/16                 */

#include<stdio.h>
#include<math.h>
#include "maxmin.h"
//#define DEBUG
int main(){
float n;
float minimum = INFINITY;
float maximum = -INFINITY;
    
    printf("Enter value [To quit enter ctrl+d]: \n"); //prompt user for value
    	while ( scanf("%f", &n) !=EOF){
    		minimum = min(n, minimum); //function in maxmin.c
    		maximum = max(n, maximum); //function in maxmin.c
    		#ifdef DEBUG
    		printf("%.1f is the minimum and %.1f is the maximum. \n", minimum, maximum);
    		#endif
    		printf("Enter value [To quit enter ctrl+d]: \n"); //get value
   	 }
    printf("%.1f is the minimum and %.1f is the maximum \n", minimum, maximum); //return values
}
