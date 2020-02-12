/* File: account.c *
 * By: Jake Castillo *
 * Login: jakecast *
 * Team: Hawaiians *
 * Date: 17 Feb 15 */

/*  a program that prints the accumulated value of an initial
 *  investment invested at a specified annual interest and compounded
 *  annually for a specified number of years  */

#include<stdio.h>

float calc_acc_amt(float acc_amount, float annual_interest, int years);     //prototype

main(){

    /*  Set Veriables  */
    float acc_amount;
    float annual_interest;
    int years;
    int interest_type;

    /*  Ask for initial amount  */
    printf("Enter the initial amount (0 to quit program): ");
    scanf("%f", &acc_amount);

    while(acc_amount > 0)      //End loop when 0 is entered

    {
	/*  Ask for interest rate  */
	printf("Enter annual interest rate: ");
	scanf("%f", &annual_interest);

	/*  Ask for number of years  */
	printf("Enter the number of years: ");
	scanf("%i", &years);

	/* Prompt user for annually, monthly, daily */
	printf("Enter 1 for annually, 2 for monthly, 3 for daily interest computation: ");
	scanf("%i", &interest_type);

	if(interest_type == 2) //monthly compute
	{
	    annual_interest = annual_interest / 12; //monthly interest
	    years = years * 12; // change years to month
	}

	if(interest_type == 3) //daily compute
	{
	    annual_interest = annual_interest / 365; //daily interest
	    years = years * 365; // change years to days
	}
	    /*  Calculations from function  */
	    acc_amount = calc_acc_amt(acc_amount, annual_interest, years);

	    /*  Print total accumulated result  */
	    printf("The new accumulated amount: %.2f \n\n", acc_amount);

	    /*  Ask for inital amount  */
	    printf("Enter the initial amount (0 to quit program): ");
	    scanf("%f", &acc_amount);
	

    }
}
    /*  function that calculate the total accumulated amount  */

    float calc_acc_amt(float acc_amount, float annual_interest, int years){

	while(years > 0)
{
	    acc_amount = acc_amount + acc_amount * annual_interest;
	    years = years - 1;     //Calculations
	}

	return acc_amount;    //Returns result

    }
