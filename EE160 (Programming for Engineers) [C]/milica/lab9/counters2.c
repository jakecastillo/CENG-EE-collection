// File: counters2.c
// Creator: Jake Castillo
// Team name: Team Jake
// Date: 10/20/16

/*  A set of counting functions written using for loops.  */

#include <stdio.h>

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

void count_up(int n)
{
  int i;

        i = 1;
        for (i = 1; i <= n ; i++)
        { 
                printf("%d\n", i);
        }
}

void count_down(int n)
{
  int i;

        i = n;
        for (i=n ; i >= 1 ; i--)
        { 
                printf("%d\n", i);
        }
}

void count_some(int start, int finish, int incr)
{
        if (incr == 0)
                return;           /* do nothing if no increment */

        if (incr > 0)       /* count up */
                for (start = start ; start <= finish ; start += incr)
                { 
                        printf("%d\n", start);
                }
        else                /* count down */
                for (start = start ; start >= finish ; start += incr)
                { 
                        printf("%d\n", start);
                }
}
