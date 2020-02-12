/*      File : gas.c         *
 *      By   : Jake Castillo *
 *      Login: jakecast      *
 *      Team : Hawaiians     *
 *      Date : 2/4/15        */

#include<stdio.h>

main()
{ /* set variables */
   float gas; /* gallons used */
   float miles; /* miles since last fill up */
   float mpg; /* miles per gallon */
   float cpf; /* cost per fill up */
   float cpg = 3.12; /* cost per gallon */
   float cpm; /* cost per mile */

	/* get gallons used from user */
	printf("Enter the gallons used: ");
	scanf("%f", &gas);
	printf("Enter number of miles: ");
	scanf("%f", &miles);

	/* computations */
	mpg = miles / gas;
	cpf = cpg * gas;
	cpm = cpf / miles;

	/* print output */
	printf("Number of gallons used: %f \n", gas);
	printf("Cost of fill-up: %f \n", cpf);
	printf("Cost per mile: %f \n", cpm);
	printf("MPG: %f \n", mpg);
}		
