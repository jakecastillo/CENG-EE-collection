//Title: gas.c
//Creator: Jake Castillo
//Team name: Team Jake
//Date: 2/9/16

#include<stdio.h>

int main()
{ /* set variables */
   float gas; /* gallons used */
   float miles; /* miles since last fill up */
   float mpg; /* miles per gallon */
   float cpf; /* cost per fill up */
   float cpg; /* cost per gallon */
   float cpm; /* cost per mile */

        /* get gallons used from user */
        printf("Enter the gallons used: ");
        scanf("%f", &gas);
        printf("Enter number of miles driven: ");
        scanf("%f", &miles);
	printf("Enter cost per gallon: ");
	scanf("%f", &cpg);

        /* computations */
        mpg = miles / gas;
        cpf = cpg * gas;
        cpm = cpf / miles;

        /* print output */
	printf("Cost per gallon: %f \n", cpg);
        printf("Number of gallons used: %f \n", gas);
        printf("Cost of fill-up: %f \n", cpf);
        printf("Cost per mile: %f \n", cpm);
        printf("MPG: %f \n", mpg);
}
