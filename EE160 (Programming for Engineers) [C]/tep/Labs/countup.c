/*      File : countup.c        *
 *      By   : Jake Castillo                 *
 *      login: jakecast                 *
 *      team : Hawaiians                 *
 *      Date : 2/6/15                 */

/*  A program to count from 1 to 20, one per line  */

#include <stdio.h>

int main()
{
  int count;

	count = 1;
	while (count <= 20)
		{
		printf("%d\n", count);
		count = count + 1;
		}
}
