/*      File : grader2.c         
By   : Jake Castillo    
login: jakecast           
team : Hawaiians        
Date : 18 March 15        */

/*  A program to assign letter grades to scores  */

#include<stdio.h>
#include "lettergrade2.h"

int main()
{
    /*  Declare values  */
    int score;    //Numeric grade
    char grade;   //Letter grade
    int A, B, C, D; //Threshold
    int valid; // TRUE or FALSE check
    int count_pass = 0; //count pass
    int count_fail = 0; //count fail
    int count_invalid=0; //cound invalid
    /* Ask user for score threshold */
    printf("Enter four numbers to represent the A, B, C, and D threshold (In that order):");
    scanf("%i %i %i %i", &A, &B, &C, &D); //get A, B, C, D threshold
    valid = invalid_thresh(A,B,C,D); //check if valid numbers

    if(valid == TRUE) //run if true
    {
	/*  Ask user for a score  */
	printf("Enter a score (EOF to quit): ");

	/*  While there are more scores  */
	while(scanf("%d", &score) != EOF)
	{

	    /*  Conver score to letter grade  */
	    grade = assign_grade(A,B,C,D,score);

	    /*  Print Result  */
	    if(grade == '?'){
		printf("%d: illegal score\n", score);
	    } else {
		printf("%d: %c\n", score, grade);
	    }
	    if(grade >= 'A' && grade <= 'C')
		{
		count_pass = count_pass + 1;
		}
	    else if(grade <= 'F' && grade >= 'D')
		{
		count_fail = count_fail + 1;
		}
	    else
		{
		count_invalid = count_invalid + 1;
		}
	    /*  Ask user for another score  */
	    printf("Enter a score (EOF to quit): ");
	}
    //Clean up screen
    printf("\n");
    //print counts
    printf("Passing scores: %i \n", count_pass);
    printf("Failing scores: %i \n", count_fail);
    printf("Illegal scores: %i \n", count_invalid);
    }
    else
    { 
	printf("invalid grading scale");
    }

}

