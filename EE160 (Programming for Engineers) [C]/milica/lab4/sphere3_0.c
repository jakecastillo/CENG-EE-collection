// Title: sphere3_0.c
// Edited by: Jake Castillo
// Team name: Team Jake
// Date: 9/15/16

#include <stdio.h>

#define PI 3.141592

int main()
{
	double r;

	//Read radius 
	printf("Enter radius in inches:\n");
	scanf("%lf", &r);
	printf("r=%.2f inch \n",r);

	//if r is negative
	if (r<0){
		//end program and tell user that it can't compute
		printf("Entered negative number, can't computer\n");
		return 0;
	}
	
	//if r is positive
	else{
    
        	//Calculate area and volume
        	double s = 4.0 * r * r * PI;
        	double v = 4.0/3.0 * r * r * r * PI;
   
        	//OR we can use the pow function: 
        	//double s = 4.0 * pow(r, 2) * PI;
        	//double v = 4.0 * pow(r, 2) * PI;
    
        	//Print the results
        	printf("s=%.2f square inches\nv=%.2f cubic inches\n", s, v);
	}
	
	return 0;
}
                                                
