/*      File : lettergrader.c   
        By   : Jake Castillo    
        login: jakecast           
        team : Hawaiians        
        Date : 18 March 15        */

/*  This file contains the functions  */

char assign_grade(int score){
/*  Given: Numeric score
 *      Converts numeric score to letter grade
 *          Returns: letter grade
 *          */

    /* Letter grade is A if scores is between 100 & 90  */
    if(score <= 100 && score >= 90){
        return 'A';
    }
    
    /* Letter grade is B if scores is between 89 & 80  */
    if(score <= 89 && score >= 80){
        return 'B';
    }
    
    /* Letter grade is C if scores is between 79 & 70  */
    if(score <= 79 && score >= 70){
        return 'C';
    }
    
    /* Letter grade is D if scores is between 69 & 60  */
    if(score <= 69 && score >= 60){
        return 'D';
    }
    
    /* Letter grade is F if scores is between 59 & 0  */
    if(score <= 59 && score >= 0){
        return 'F';
    }
    
    /* Question mark is returned if score is above 100 & below 0  */
    else{
       return '?';
    }
}
