// Title: gravity.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 9/8/16
#include<stdio.h>

#define g 9.8

int main()
{

        double v, d, t;

        //prompt user to enter time in seconds
        printf("Insert time in seconds that object falls\n");
        scanf("%lf", &t);

        //reprints their input
        printf("time=%f seconds \n", t);

        //calculate velocity and distance
        v = g * t;
        d = g * t * t / 2;

        //print results
        printf("velocity=%f m/s\t distance=%f meters\n", v, d);
}
