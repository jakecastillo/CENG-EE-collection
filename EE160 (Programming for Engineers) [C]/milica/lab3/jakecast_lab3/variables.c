//Title: variables.c
//Creator: Jake Castillo
//Team name: Team Jake
//Date: 2/8/16

#include <stdio.h>

int main()
{ 
	int k;
	float z;

	k = 1;
	printf("k = %d\n", k);
	k = 2.5; //k will print as 2 and lose .5 because it's an interger
	printf("k = %d\n", k;)
	z = 2.3; //z will print as 2.3 because 2.3 is a float and it's printing a float
	printf("z = %f\n", z);
	k = 1 / 2; //k will print out 0 because 0.5 ---> 0 due to k being an interger data type
	printf("k = %d\n", k);
	z = 1 / 2; //z will print out 0 because 1 and 2 are interger numbers
	printf("z = %f\n", z);
	k = 1 + 1 / 2; //k will print out 1 because 1.5 ---> 1 due to k being an interget data type
	printf("k = %d\n", k);
	z = 1 + 1 / 2; //z will print 1 because 1 and 2 are intergers 1 / 2 = 0.5 ---> 0, 1 + 0 = 1
	printf("z = %f\n", z);
	k = 1.0 / 2.0; //k is an interger will return 0
	printf("k = %d\n", k);
	k = 1.0 / 2; //k is an interger will return 0
	printf("k = %d\n", k);
	k = 1 / 2.0; //k is an interger will return 0
	printf("k = %d\n", k);
	z = 1.0 / 2.0; //z will return 0.5 because float
	printf("z = %f\n", z);
	z = 1.0 / 2; //z will return 0.5 because float
	printf("z = %f\n", z);
	z = 1 / 2.0; //z will return 0.5 because float
	printf("z = %f\n", z);
	k = z + 1; //k will return 1 because k is still an interger and 0.5 + 1 = 1.5 ---> 1 
	printf("k = %d\n", k);
	k = z + 1.0; //k will return 1 because k is still an interger and 0.5 + 1.0 = 1.5 ---> 1
	printf("k = %d\n", k);
	k = k + 1; //k will return 2 because 1 from the previous entry + 1 = 1
	printf("k = %d\n", k);
	z = z + 1; //z will reutrn 1.5 because z was previously 0.5 + 1 and z is a float
	printf("z = %f\n", z);
}
