/*      File : driver1.c      
        By   : Jake Castillo                 
        login: jakecast                 
        team : Team Jake           
        Date : 9/29/16                 */

#include<stdio.h>
#include<math.h>
#include "maxmin.h"

int main(){
	float n1;
	float n2;
	float minimum = INFINITY;
	float maximum = -INFINITY;
    
    	printf("Enter two values (1st 2nd) [To quit enter ctrl+d]: \n"); //prompt user for two values
	while ( scanf("%f %f", &n1, &n2) !=EOF){ //get two values
		minimum = min(n1, n2); //function in maxmin.c
		maximum = max(n1, n2); //function in maxmin.c
		printf("%.1f is the minimum and %.1f is the maximum. \n", minimum, maximum);
    		printf("Enter two values (1st 2nd) [To quit enter ctrl+d]: \n"); //get two values
    	}
	
	printf("Program ended\n");
}
