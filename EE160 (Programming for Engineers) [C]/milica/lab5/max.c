// File: max.c
// Creator: Jake Catillo
// Team name: Team Jake
// Date: 9/22/16

#include <stdio.h>
#include <math.h>

int main()
{
	//declaring variables and initializing output
	float input;
	float max = -INFINITY;

	//get first input
	printf("Enter numbers (ctrl+d to get maximum of of series): \n");

	//while there is more input
	while (scanf("%f", &input) !=EOF)
	{
		if (input > max) //comparing values of input and what's currently in max
		
			max = input; //changes new max
		}
		//to make it calculate minimum instead of maximum, you would just have to
		//change the inequality in the if statement to <. Also change the variable
		//name to min so that it would make more sense
	}
	printf("The maxmimum is %.2f \n", max);
}
