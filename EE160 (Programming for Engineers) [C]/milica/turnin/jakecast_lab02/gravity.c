// Title: gravity.c
// Creator: Jake Castillo

#include<stdio.h>

#define g 9.8

double v, d, t;

int main()
{
	//prompt user to enter time in seconds
	printf("Insert time in seconds that object falls\n");
	scanf("%lf", &t);
	
	//reprints their input
	printf("t=%f seconds \n", t);
	
	//calculate velocity and distance 
	v = g * t;
	d = g * t * t / 2;

	//print results
	printf("v=%f m/s\t d=%f meters\n", v, d);
}
