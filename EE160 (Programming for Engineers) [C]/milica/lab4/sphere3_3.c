// Title: sphere.c
// Edited by: Jake Castillo

#include <stdio.h>

#define PI 3.141592

int main()
{
	//initialize variables
	double r;
	int flag;

	//Read radius 
	printf("Enter radius in inches (ctrl+d to quit)\n");
	flag = scanf("%lf", &r); //read first input

	//while loop until ^D
	while(flag != EOF){
 
	printf("radius=%f inch \n",r);
	    
        //Calculate area and volume
        double s = 4.0 * r * r * PI;
        double v = 4.0/3.0 * r * r * r * PI;
   
        //OR we can use the pow function: 
        //double s = 4.0 * pow(r, 2) * PI;
        //double v = 4.0 * pow(r, 2) * PI;
    
        //Print the results
        printf("surface area=%.2f square inches\nvolume=%.2f cubic inches\n \n", s, v);
	printf("Enter radius in inches (ctrl+d to quit)\n");
	flag = scanf("%lf", &r); //read next input
	}

	return 0;
}
                                                
