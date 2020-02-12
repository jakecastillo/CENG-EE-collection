//file: driver3.c
//team: Team Jake
//login: jakecast
//date: 9/29/16

#include<stdio.h>
#include "julian.h"
#include "julian.c"

main(){
    /*  Declare values  */
    int month;          //Month user entered
    int day;            //Day user entered
    int year;           //Year user entered
    int total_days;     //Julian date
    
    /*  Ask user for month and year  */
    printf("Enter month, day, year (month day year) [Enter EOF to quit]: ");
    
    /*  While there are more  */
    while( scanf("%i %i %i", &month, &day, &year) != EOF){
        
        /* The julian date  */
        total_days = julian_date(day, month, year);
        
        /*  Print the total of days  */
        printf("The number of days are %i. \n", total_days);
        
        /*  Ask user for another month and year  */
        printf("Enter month, day, year (month day year) [Enter EOF to quit]: ");
    }
    
    printf("\n");
}
