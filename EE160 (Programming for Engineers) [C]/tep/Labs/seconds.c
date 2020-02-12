/*      File : seconds.c        *
 *      By   : Jake Castillo                 *
 *      login: jakecast                 *
 *      team : Hawaiians                 *
 *      Date : 2/4/15                 */

/*
 *   This program reads a number of seconds and computes how
 *   many
 *     hours, minutes and seconds that corresponds to.
 */

#include <stdio.h>

main()
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
