/*  File:    avg.c
 *      by:        Jake Castillo
 *          date:    28 Apr 15
 *          */

/*  This file contains functions for calculations and printing set of values  */

#include<stdio.h>
#include "avg.h"

/*  A function that gets a set of values for an array  */
int tableFill(double a[], int max){
  double next;              /* next input value */
  int r;                    /* return from trying to read values */
  int cnt = 0;              /* count of values read */

    /*  While there are more values to read  */
    while ((r = scanf("%lf", &next)) != EOF){
        if (r != 1)         /* bad return from scanf */
        {
            printf("Error in the input after reading %d values.\n", cnt);
            break; 
        }
        if (cnt == max)         /* no room to store this value */
        {
            printf("Array full after reading %d values.\n", cnt);
            break;
        }
        a[cnt++] = next;    /* save element in array */
    }
    return cnt;        //Return the number of values
}

/*  A function that prints a value or set of values  */
void tablePrint(double a[], int num){              
  int i;

    for (i = 0; i < num; i++){
        printf("%f\n", a[i]);
    }

}

/*  A function that calculates the average of the values and returns it  */
double tableAverage(double a[], int num){
  int i;                //Counter
  double sum = 0;        //Total of values added
  double total = 0;        //Total average
    
    for(i = 0; i < num; i++){
        /*  Add values  */
        sum += a[i];
    }
    
    /*  Calculate the average  */
    total = sum / num;

    return total;      //Return total average
}

/*  A function that find the same value as the target of a set of values  */
int tableMatchingElements(double a[], int num, double target){
  int i;            //Counter
  int same = 0;        //Number of values same as target

    for(i = 0; i < num; i++){
        /*  Values is the same as the target  */
        if(a[i] == target){
            same++;        //Add 1 when value is same
        }
    }

    return same;        //Return number of values same as target
}

/*  A function that prints the values larger than the average  */
void tablePrintIfLarger(double a[], int num, double target){
  int i;            //Counter

    for (i = 0; i < num; i++){
        /*  Values larger then target  */
        if(a[i] > target){
            printf("%.0f\n", a[i]);        //Print values
        }
    }
}

/*  A function that prints the values smaller than the average  */
void tablePrintIfSmaller(double a[], int num, double target){              
  int i;            //Counter

    for (i = 0; i < num; i++){
        /*  Values smaller then target  */
        if(a[i] < target){
            printf("%.0f\n", a[i]);        //Print values
        }
    }
}

/*  A function that counts the values larger than the average  */
int countLarger(double a[], int num, double target){
  int i;            //Counter
  int big = 0;        //Number of values larger then target

    for (i = 0; i < num; i++){
        /*  Values larger then target  */
        if(a[i] > target){
            big++;                        //Count large values
        }
    }

    return big;            //Return number of values larger then target
}

/*  A function that counts the values smaller than the average  */
int countSmaller(double a[], int num, double target){              
  int i;            //Counter
  int small = 0;    //Number of values smaller then target

    for (i = 0; i < num; i++){
        /*  Values smaller then target  */
        if(a[i] < target){
            small++;                    //Count large values
        }
    }

    return small;        //Return number of values smaller then target
}
