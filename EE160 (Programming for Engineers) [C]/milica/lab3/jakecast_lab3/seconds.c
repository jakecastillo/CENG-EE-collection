//Title: seconds.c
//Creator: Jake Castillo
//Team name: Team Jake
//Date: 9/8/16

#include <stdio.h>

int main()
{  int seconds;
   int hours;
   int minutes;

        /*  get the number of seconds  */
        printf("Enter the number of seconds:  ");
        scanf("%d", &seconds);

        /*  compute the number of hours  */
        hours = seconds / 3600;

        /*  compute the number of minutes  */
        minutes = (seconds-(3600*hours)) / 60;

        /*  compute the number of seconds remaining  */
        seconds = seconds % 60;

        /*  print the result  */
        printf("there are %d hours, %d minutes, %d seconds\n",
                hours, minutes, seconds);

}
