/*      File : lettergrader2.c   
By   : Jake Castillo    
login: jakecast           
team : Hawaiians        
Date : 18 March 15        */

/*  This file contains the functions  */
#include "lettergrade2.h"

char assign_grade(int A, int B, int C, int D, int score){
    /*  Given: Numeric score
     *      Converts numeric score to letter grade
     *          Returns: letter grade
     *          */

    /* Letter grade is A if scores is between 100 & 90  */
    if(score <= 100 && score >= A){
	return 'A';
    }

    /* Letter grade is B if scores is between 89 & 80  */
    else if(score < A && score >= B){
	return 'B';
    }

    /* Letter grade is C if scores is between 79 & 70  */
    else if(score < B && score >= C){
	return 'C';
    }

    /* Letter grade is D if scores is between 69 & 60  */
    else if(score < C && score >= D){
	return 'D';
    }

    /* Letter grade is F if scores is between 59 & 0  */
    else if(score < D && score >= 0){
	return 'F';
    }

    /* Question mark is returned if score is above 100 & below 0  */
    else{
	return '?';
    }
}

char invalid_thresh(int A, int B, int C, int D)
{
    if((100 < A) || (B > A) || (C > B) || (C < D) || (D < 0))
    { return FALSE;
    }
    else
    { return TRUE;
    }

}
