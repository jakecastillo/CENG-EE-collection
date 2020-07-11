#include <stdlib.h>
#include <stdio.h>

#define NUM_MACHINES 2

enum choice {M0, M1, Move};

int plan(int length, int s[][length]);
int max_val(int a, int b);


void main()
{
int s[NUM_MACHINES][9] = {
	{2, 2, 3, 2, 4, 2, 7, 6, 5},
	{1, 1, 1, 9, 8, 1, 1, 1, 2}
};

printf("Solution: %d\n",plan(9, s));
}

int plan(int length, int s[][length])
{

int choice[length];   /* choice[m] = optimal plan's choice at minute m */

/* This for-loop can be deleted */
for (int i=0; i<length; i++) {
    if (i == 0) {
        int step = max_val(s[0][i],s[1][i]);
        
        if (step == s[0][i]) 
        choice[i] = 0;
        
        else choice[i] = 1;
        i++;
        
        step = max_val(s[0][i],s[1][i]);
        
        if (step == s[0][i]) 
        choice[i] = 0;
        
        else choice[i] = 1;
        continue;
    }
    int step = max_val(s[0][i],s[1][i]);
    
    if (step == s[0][i]) 
    choice[i] = 0;
    
    else choice[i] = 1;
    
    if (choice[i-1] == -1 || choice[i-2] == -1 || choice[i-3] == -1)
    continue;
    
    if (choice[i-2] != choice[i]) choice[i-1] = -1;
    
}
int sum = 0;
/* Do not delete next 6 lines since this the format for the output  */
printf("The following shows per minute, \n");
printf("(Steps at Machine 0, Steps at Machine 1),\n");
printf("Choice: 0 = Machine 0, 1 = Machine 1, -1 = Move\n"); 
for (int k=0; k<length; k++) {
    printf("Minute=%d: Steps=(%d, %d), Choice=%d\n",k,s[0][k],s[1][k],choice[k]);
    if (choice[k] != -1) sum += max_val(s[0][k],s[1][k]);
}

return sum;  /* This should be changed to return the optimal # steps */
}

int max_val(int a, int b)
{
if (a>b) return a;
else return  b;
}
