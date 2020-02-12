// Title: averager.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 10/20/16

 /*  * Read in a number of values to read and then print the average
 *   * of those values.
 *    */

#include <stdio.h>
#include "tfdef.h"

int main()
{
  /*  Declare variables  */
  int expected;     //Total number of set values
  int count;        //Numbers of values entered
  double sum;       //Total sum of values
  int value;        //Values entered
  int flag;         //Flag for scanf expected
  int flag2  = 1;        //Flag for scanf value

	printf("Enter amount of values to average, press enter then type the numbers to average (ctrl+d to quit): ");
    /*  While there is a valid expected number  */
    while ((flag = scanf("%d", &expected)) == 1){
        sum = 0;    //initialize value

        /*  While there are valid values  */
        for (count = 0; count < expected && ((flag2 = scanf("%d", &value)) == 1); count++){
            sum += value;           //Add total of input
        }

        /*  Value is not a valid integer  */
        if(flag2 != 1){
            printf("Error! Can't read expected value #%d.\n", count);
        }

        /*  Print result  */
        printf("Average of %d values is %.2f\n", count, count != 0 ? sum / count : 0.0);
    }

    /*  Expected is not a valid integer  */
    if(flag == 0 && flag2 == 1){
        printf("Error! Can't read number of expected values.\n");
	return 0;
    }

}
