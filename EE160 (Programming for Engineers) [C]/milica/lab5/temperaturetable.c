// File: temptbl.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 9/22/16

#include <stdio.h>

int temptable(float start, float stop);
float tocelsius(float fahrenheit);
  /*  Given: starting and ending temperatures in degrees Fahrenheit
      The function prints a table of conversions from degrees
      Fahrenheit to degrees Celsius from start to at most stop
      in five degree F increments, one conversion per line.

      Returns: the number of table lines printed. */

int main()
{/* set variables */
  float fahrenheit;
  float celsius;
  float start;
  float stop;
  float step;

	printf("Enter start and stop (ctrl + d to end): \n"); //ask for start, stop

	/* set parameters */
	while ( scanf("%f %f", &start, &stop) !=EOF) //user gives start, stop

		{
		
		temptable(start,stop); //recall temptable
		printf("Enter start and stop (ctrl + d to end): \n");

		}
	
}

//define function
int temptable (float start, float stop)
{
   /* Variable in function */
   float celsius;
   int num=0;
   float step = 5;
	
	if (step < 0) //turn negative into positive value
	{
		step = (step * -1);
	}
	
	if (start <= stop) //run this loop in start is less than or equal to stop
	{
		printf("Fahrenheit \t|\t Celsius\n");
		while (start <= stop) //set parameter
		{
		celsius = tocelsius(start); //recall to celsius
		printf("%.2f\t\t|\t%.2f \n", start, celsius); //print values
		start = start + step; //increase by given step
		num = num + 1; //number of values computed
		}
	}
	
	else //if start is not less than or equal to stop
	{
		printf("Fahrenheit \t|\t Celsius\n");
		while (start >= stop) //run this instead
		{
		celsius = tocelsius(start); //recall to celsius
		printf("%.2f\t\t|\t %.2f \n", start, celsius); //print values
		start = start - step; //decrease by given step
		num = num + 1; //number of values computed
		}
	}
	printf("Computed %i temperatures\n", num);
}

//define function
float tocelsius (float fahrenheit)
{
   /* Variable in function */
   float celsius;
                                                                           
	/* Convert Fahrenheit to Celsius */
	celsius = (fahrenheit - 32) * 5 / 9;

	return celsius;
}
