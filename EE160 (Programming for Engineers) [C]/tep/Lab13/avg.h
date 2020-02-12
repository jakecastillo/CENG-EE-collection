/*  File:    avg.h
 *      by:        Jake Castillo
 *          date:   28 Apr 15
 *          */

/*  This file contains macros and prototypes for avg.c  */

/* max number of values we can process */
#define MAXVALS 100

int tableFill(double a[], int max);
/*  A function that gets a set of values for an array  */

void tablePrint(double a[], int num);
/*  A function that prints a value or set of values for a condition  */

double tableAverage(double a[], int num);
/*  A function that calculates the average of the values and returns it  */

int tableMatchingElements(double a[], int num, double target);
/*  A function that find the same value as the target of a set of values  */

void tablePrintIfLarger(double a[], int num, double target);
/*  A function that prints the values larger than the average  */

void tablePrintIfSmaller(double a[], int num, double target);
/*  A function that prints the values smaller than the average  */

int countLarger(double a[], int num, double target);
/*  A function that counts the values larger than the average  */

int countSmaller(double a[], int num, double target);
/*  A function that counts the values smaller than the average  */
