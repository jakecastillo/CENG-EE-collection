/*
 *
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * The function's input is the char string 'str[]' and its length
 * It will find the longest substring that has just one character.
 * We will refer to such a substring as a "single-string" since 
 * it has only a single character.
 * For example, the longest substring in "aababbbbaa" is "bbbb".
 * It returns the index of the first and last characters in the 
 * substring.  In the example, first = 4 and last = 7.
 */ 
int strlength(char str[], int length, int *first, int *last);

/*
 * This function will return the length of the char string
 */
int total_length(char str[]);

char str1[] = "aababbbbaabba";
char str2[] = "acbcbbabcccbbca";

void main(int argc, char *argv[])
{
int first, last;

int length = strlength(str1, total_length(str1), &first, &last);
printf("Longest substring of '%s' has length=%d, starts at %d, ends at %d\n", str1, length,first, last);

length = strlength(str2, total_length(str1), &first, &last);
printf("Longest substring of '%s' has length=%d, starts at %d, ends at %d\n", str2, length,first, last);
}

int strlength(char str[], int length, int *first, int *last){


   int best_first = 0;  
   int best_last = 0;
   int best_length = 1;
   int curr_first = 0;
   char val1 = str[0];
   char val2; 

    if(val1 == str[1]);
        val2 = str[2];

   for (int i=0; i <= length; i++) {
       if((str[i] == val2) || (str[i] == val1)){
           best_first = curr_first;
           best_last = i;
           best_length = best_last - best_first + 1;
       }

       else if ((str[i] != val1) && (str[i] != val2) ){
           if((best_length < length - i)){
               val1 = str[i-1];
               val2 = str[i];
               curr_first = i-1;
            }
       }
   }
   *first = best_first;
   *last = best_last;
   return best_length;
}

int total_length(char str[])
{
int k;
for (k=0; str[k]!='\0'; k++);
return k;
}
