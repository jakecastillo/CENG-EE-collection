/*      File : countgrades.c   
        By   : Jake Castillo    
        login: jakecast           
        team : Hawaiians        
        Date : 17 March 15        */

/*  A program to count the number of grades occuring in the input */

#include <stdio.h>
// #define DEBUG
int main()
{
  /*  Declare values  */
  int a;
  int b;
  int c;
  int d;
  int f;
  int others;
  char grade;

    /*  Set values  */
    a = b = c = d = f = 0;
    others = 0;
    
  /*  While there are more grades  */
  while ((grade = getchar()) != EOF){
        
	#ifdef DEBUG
        printf("value: %c \n", grade);
     	#endif

        switch(grade){
            case 'A': //if A or a, count 1
            case 'a': a++;
                break;
                
            case 'B': //if B or b, count 1
            case 'b': b++;
                break;
                
            case 'C': //if C or c, count 1
            case 'c': c++;
                break;
                
            case 'D': //if D or d, count 1
            case 'd': d++;
                break;
                
            case 'F': //if F or f, count 1
            case 'f': f++;
                break;
           
	    case '\n': //if new line, do nothing
		break;
 
            default: others++; //if not Aa Bb Cc Dd Ff, count others
                break;
        }
    }

    /*  Print results  */
    printf("Grade counts:\n");
    printf("  A's: %d\n", a);
    printf("  B's: %d\n", b);
    printf("  C's: %d\n", c);
    printf("  D's: %d\n", d);
    printf("  F's: %d\n", f);
    printf("  Other grades: %d\n", others);
}
