// File: counters.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 10/20/16

/*  A set of counting functions written using while loops. */

#include <stdio.h>

/*  Prototypes  */
void count_up(int n);
void count_down(int n);
void count_some(int start, int finish, int incr);

int main()
{
        count_up(10);            /* count up from 1 to 10  */
        count_down(10);          /* count down from 10 to 1 */
        count_some(5, 15, 3);    /* count from 5 to 15 by 3 */
        count_some(15, 5, -3);   /* count from 15 to 5 by -3 */
}

/*  Function to count values up  */
void count_up(int n)
{
  int i;
        i = 1;
        while (i <= n)
        {
                printf("%d\n", i);
                i++;
        }
}

/*  Function to count values down  */
void count_down(int n)
{
  int i;
        i = n;
        while (i >= 1)
        {
                printf("%d\n", i);
                i--;
        }
}

/*  Function to count by a set of parameters  */
void count_some(int start, int finish, int incr)
{
        if (incr == 0)
                return;           /* do nothing if no increment */
        if (incr > 0)       /* count up */
                while (start <= finish)
                {
                        printf("%d\n", start);
                        start += incr;
                }
        else                /* count down */
                while (start >= finish)
                {
                        printf("%d\n", start);
                        start += incr;
                }
}
