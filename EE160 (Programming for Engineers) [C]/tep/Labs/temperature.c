/*     File : temperature.c       *
 *     By   : Jake Castillo   *
 *     Login: jakecast        *
 *     Team : Hawaiians       *
 *     date : 2/4/15          */

#include <stdio.h>

float tocelsius(float fahrenheit);
/*  Given:  a temperature reading in degrees Fahrenheit
    Returns: the temperature in degrees Celsius  */
main()
{/* set variables */
  float fahrenheit;
  float celsius;

	/* get temperature from user */
	printf("Enter the Fahrenheit (Fahrenheit < -500 to quit): ");
	scanf("%f", &fahrenheit);
	while (fahrenheit > -500)

		{
		/* compute celsius */
		celsius = tocelsius(fahrenheit);

		/* print output */
		printf("celsius = %f degrees\n", celsius);

		/* get temperature from user */
		printf("Enter the Fahrenheit (Fahrenheit < -500 to quit): ");
		scanf("%f", &fahrenheit);
		}
				

	
}

float tocelsius (float fahrenheit)
{
   /* Variable in function */
   float celsius;

	/* Convert Fahrenheit to Celsius */
	celsius = (fahrenheit - 32) * 5 / 9;

	return celsius;
}
