#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int perfectSquares(int n);


void main()
{
int n=12;
printf("n=%d: perfect squares = %d\n", n, perfectSquares(n));
n=13;
printf("n=%d: perfect squares = %d\n", n, perfectSquares(n));
n=500;
printf("n=%d: perfect squares = %d\n", n, perfectSquares(n));
n=724;
printf("n=%d: perfect squares = %d\n", n, perfectSquares(n));
return;
}

int perfectSquares(int n)
{
    while (n % 4 == 0)
        n /= 4;
    if (n % 8 == 7)
        return 4;
    for (int a=0; a*a<=n; ++a) {
        int b = sqrt(n - a*a);
        if (a*a + b*b == n)
            return 1 + !!a;
    }
    return 3;
}