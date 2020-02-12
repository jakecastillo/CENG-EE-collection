/*      File : driver2.c
        By   : Jake Castillo
        login: jakecast
        team : Hawaiians
        Date : 2/25/15                 */

#include<stdio.h>
//#define DEBUG
main(){
    /*  Declare values  */
    int number;                     //User input
    int counter = 0;                //Count number of values
    int even_counter = 0;           //Count number of evens
    int positive_even_counter = 0;  //Count number of positve evens
    int positive_counter = 0;       //Count number of positives
    int odd_counter = 0;            //Count number of odds
    int negative_odd_counter = 0;   //Count number of negative odds
    int negative_counter = 0;       //Count number of negatives
    int total = 0;                  //Total of all values
    int positive_total = 0;         //Total of positive
    int negative_total = 0;         //Total of negatives
    int even_total = 0;             //Total of evens
    int odd_total = 0;              //Total of odds
    int positive_even_total = 0;    //Total of positive evens
    int negative_odd_total = 0;     //Total of negative odds
    
    
    /*  Ask for the first value  */
    printf("Enter an integer (0 to quit): ");
    scanf("%i", &number);
    
    /*  While theres more numbers  */
    while(number != 0){
    counter = counter + 1;
    total = total + number;
    
        if(number > 0){ //check if value is positive
            positive_counter = positive_counter + 1; //count number of positives
            positive_total = positive_total + number; //add total of positives
	    #ifdef DEBUG
            printf("%i is positive(count = %i, total = %i) \n", number, positive_counter, positive_total);
	    #endif
        } else { //check if number is negative
            negative_counter = negative_counter + 1; //count number of negatives
            negative_total = negative_total + number; //count total of negatives
	    #ifdef DEBUG
            printf("%i is negative(count = %i, total = %i) \n", number, negative_counter, negative_total);
	    #endif
        }
        
        if(number % 2 == 0){ //check if number is even
            even_counter = even_counter + 1; //count number of evens
            even_total = even_total + number; //add total of negatives
	    #ifdef DEBUG
            printf("%i is even(count = %i, total = %i) \n", number, even_counter, even_total);
	    #endif
        } else { //check if number is odd
            odd_counter = odd_counter + 1; //count number of odds
            odd_total = odd_total + number; //add total of odds
	    #ifdef DEBUG
            printf("%i is odd(count = %i, total = %i) \n", number, odd_counter, odd_total);
	    #endif
        }
        
        if(number > 0 && number % 2 == 0){ //check if number is positive or even
            positive_even_counter = positive_even_counter + 1; //count number of positives and evens
            positive_even_total = positive_even_total + number; //add total of positives and evens
	    #ifdef DEBUG
            printf("%i is positive and even(count = %i, total = %i) \n", number, positive_even_counter, positive_even_total);
	    #endif
        }
        
        if(number < 0 && number % 2 != 0){ //check if number is negative or odd
            negative_odd_counter = negative_odd_counter + 1; //count number of negative and odd
            negative_odd_total = negative_odd_total + number; //add total of negative and odd
	    #ifdef DEBUG
            printf("%i is negative and odd(count = %i, total = %i) \n", number, negative_odd_counter, negative_odd_total);
	    #endif
        }
        

        /*  Print the total  */
	#ifdef DEBUG
        printf("Total(count = %i, total = %i) \n", counter, total);
        #endif
        
        /*  Ask for the next value  */
        printf("\n");
        printf("Enter an integer (0 to quit): ");
        scanf("%i", &number);
    }
    
    /*  Print the overall output  */
    printf("There were %i positive numbers totaling %i \n", positive_counter, positive_total);
    printf("There were %i negative numbers totaling %i \n", negative_counter, negative_total);
    printf("There were %i even numbers totaling %i \n", even_counter, even_total);
    printf("There were %i odd numbers totaling %i \n", odd_counter, odd_total);
    printf("There were %i positive even numbers totaling %i \n", positive_even_counter, positive_even_total);
    printf("There were %i negative odd numbers totaling %i \n", negative_odd_counter, negative_odd_total);
    printf("There were %i total numbers totaling %i \n", counter, total);
}
