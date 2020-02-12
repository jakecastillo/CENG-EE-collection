/*      File : grader.c         
        By   : Jake Castillo    
        login: jakecast           
        team : Hawaiians        
        Date : 18 March 15        */

/*  A program to assign letter grades to scores  */

#include<stdio.h>
#include "lettergrade.h"

int main()
{
  /*  Declare values  */
  int score;    //Numeric grade
  char grade;   //Letter grade

    /*  Ask user for a score  */
    printf("Enter a score (EOF to quit): ");

    /*  While there are more scores  */
    while(scanf("%d", &score) != EOF)
    {
        
        /*  Conver score to letter grade  */
        grade = assign_grade(score);
        
        /*  Print Result  */
        if(grade == '?'){
            printf("%d: illegal score\n", score);
        } else {
            printf("%d: %c\n", score, grade);
        }
        
        /*  Ask user for another score  */
        printf("Enter a score (EOF to quit): ");
    }
    /*  Clean up screen  */
    printf("\n");
}

