// Title: sphere.c
// Edited by: Jake Castillo

#include <stdio.h>

#define PI 3.141592

void main()
{
	double r;

	//Read radius 
	printf("Enter radius in inches\n");
	scanf("%lf", &r); 
	printf("r=%f inch \n",r);
    
        //Calculate area and volume
        double s = 4.0 * r * r * PI;
        double v = 4.0/3.0 * r * r * r * PI;
   
        //OR we can use the pow function: 
        //double s = 4.0 * pow(r, 2) * PI;
        //double v = 4.0 * pow(r, 2) * PI;
    
        //Print the results
        printf("s=%f square inches\t v=%f cubic inches\n", s, v);
}
                                                
