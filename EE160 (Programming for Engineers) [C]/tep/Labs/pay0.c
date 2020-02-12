/*   File: pay0.c
     Programmer: Jake Castillo
     Date: Current Date
     This program calculates the pay for one person, given the hours worked
     and rate of pay.
*/


#include <stdio.h>

main()
{    /* declarations */
     int id_number;
     float hours_worked,
          rate_of_pay,
          pay;

     /* print title */
     printf("***Pay Calculation***\n");

     /* initialize variables */
     id_number = 123;
     hours_worked = 32;
     rate_of_pay = 9.75;

     /* calculate pay */
     pay = hours_worked * rate_of_pay;

     /* print data and results */
     printf("ID Number = %d\n", id_number);
     printf("Hours Worked = %f, Rate of Pay = %f\n",
               hours_worked, rate_of_pay);
     printf("Pay = %f\n", pay);
}
