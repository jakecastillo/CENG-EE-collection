#include "BankAccount.h"

struct BankAccount {
    double balance;
    double last_withdrawl;
    double last_deposit;
};

/*
 * Implement the definitions for the
 * functions involving BankAccount from BankAccount.h here,
 *
 * Make sure to produce comments that look like this!
 * (Try to copy the formatting.)
 *
 * For BankAccount_construct() and BankAccount_destroy(),
 * if you do not remember malloc() and free(), review them
 * by creating a toy program.
 */

BankAccount* BankAccount_construct(double balance) {
	struct BankAccount *ba = malloc(sizeof(struct BankAccount));
	ba->balance = 0; //initiate balance to 0
}

void BankAccount_destory(BankAccount* ba){
	free(ba); //will reallocate data back to OS/server
}

int BankAccount_deposit(BankAccount* ba, double amount){
ba->last_deposit = amount; //store last deposit to be called later
ba->balance += amount; //add to total balance
		
}

int BankAccount_withdraw(BankAccount* ba, double amount){
ba->last_withdrawl = amount; //store last withdrawl to be called later
ba->balance -= amount; //subtract to total balance
}

double BankAccount_get_balance(BankAccount* ba){
return ba->balance; //get balance in bank account struct
}

double BankAccount_get_last_deposit(BankAccount* ba){
return ba->last_deposit; //get last deposit in bank account struct
}

double BankAccount_get_last_withdrawal(BankAccount* ba){
return ba->last_withdrawl; //get last withdrawl in bank account struct
}
