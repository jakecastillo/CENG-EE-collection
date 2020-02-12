// Title: decibels.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 9/15/16

#include <stdio.h>
#include <math.h>


int main()
{
        double intensity;
        double noise;

	//read radius
	printf("Enter I / I0 \n");
        scanf("%lf", &intensity);

	printf("intensity=%lf \n", intensity);

	//calculate noise
	noise= 10 * log10(intensity);

	//print results
	printf("noise=%lf decibels \n", noise);
}
