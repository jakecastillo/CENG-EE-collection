//Jake Castillo
//EE 367

/*
 *  Type your name here:  Name:  <Your name>
 *
 *  The program will first fill an array with pseudo random numbers.
 *  Then it will display
 *     > sum of the array
 *     > minimum value of the array
 *     > maximum value of th array
 *
 *  There is a missing typedef for a function pointer data type.
 *
 *  Make the change where the comment starts with "INSERT HERE"
 *
 *  When it's correct, you can compile by gcc hw1.c
 */

#include <stdlib.h>
#include <stdio.h>
#define MAXLENGTH 20

/* INSERT HERE: Missing typedef for "process_oper".  It's a function pointer */
typedef int (*process_oper)();

/*
 *  Operations applied to the array
 *     o  sum_oper: sum the array
 *     o  max_oper: find the maximum
 *     o  min_oper: find the minimum
 */

int sum_oper(int a, int b)
{
return a+b;
}

int max_oper(int a, int b)
{
if (a > b) return a;
else return b;
}

int min_oper(int a, int b)
{
if(a < b) return a;
else return b;
}

/* Processes an array by applying an operation 'oper' to the values */
int process_array(int a[], int length, process_oper op)
{
int result=a[0];

for (int i=1; i<length; i++) {
   result = op(a[i],result);
}
return result;
}

/* Initialize an array with pseudo random values. */
void init_array(int a[], int length);


void main()
{
int data[MAXLENGTH];

init_array(data, MAXLENGTH);

printf("Sum result = %d\n", process_array(data, MAXLENGTH, sum_oper));
printf("Max result = %d\n", process_array(data, MAXLENGTH, max_oper));
printf("Min result = %d\n", process_array(data, MAXLENGTH, min_oper));
}


void init_array(int a[], int length)
{
int pseudorand = 31; /* Some initial seed value */

for (int i=0; i<length; i++) {
   pseudorand = (31*pseudorand + 17)%length;
   a[i] = pseudorand;
}

printf("Values of array\n");
for (int i=0; i<length; i++) {
   printf("a[%d] = %d\n",i,a[i]);
}
}
