#include "Cashier.hpp"
#include "Order.hpp"
#include "restaurant-utility.cpp"
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
	using namespace std;

#define DEBUG 1

Cashier::Cashier(double money_,std::size_t uid_count):
	money(money_),
	uid_count(uid_count),{}

double get_money() const {
std::cout << "Cashier: The cashier is holding " << money << std::endl;
return this-> money;

void Cashier::serve_customer(
    queue<Customer> & line,
    stack<Order> & orders) {
		//Variables used in separating order items
		double item_cost;
		vector<string> ord;
		if(DEBUG) {cout << "Serving customers in queue" << endl; }
     	//Check if Customer line is empty
     	if(line.empty()) return;
     	//Get current customer
     	Customer current = line.front();
		if(DEBUG) {cout << "**CUSTOMER**"<<endl<<current.get_money()<<endl<<current.get_order()<<endl<<current.take_order()<<endl; }
     	//Separate order items into a temporary vector
     	vector<string> temp = split(current.take_order(),' ');

	//Expand items into individual elements (e.g. "2burger" to "burger,burger")
	//and add to Order stack
	if(DEBUG) {cout << "Current order: " << endl;} 
    for(vector<string>::iterator i = temp.begin() ; i != temp.end(); i=i+2) {
	if(DEBUG) {cout << "\titem: " << endl; }
    //convert string iterator to an int and iterate through list
    for(int it = stoi(*i) ; it > 0 ; --it) {
        ord.push_back(*(i+1));
	if(DEBUG) {cout << "\t\t" << *(ord.end()-1) << endl;}
        }
    }
	if(DEBUG) {cout << "Order finished" << endl;}
	//Calculate cost of the order, if the order item is invalid, throw exception
	try {item_cost = calculate_order_cost(ord);}
	//Expel customer if order item is invalid or customer's broke
	catch (...) {current.expel();}
	if(current.get_money() < item_cost && !current.is_expelled()) current.expel();

	//Ignore customer order if expelled
	if(current.is_expelled()) {
        line.pop();
        return;
     }

     //Send finished order to stack
     else {
        current.charge_money(item_cost);
        this->money += item_cost;
		if(DEBUG) {cout << "Successfully charged customer" << endl;}
		orders.push(Order(uid_count,ord));
		if(DEBUG) {cout << "Pushed customer order to stack" << endl;}
		//Increment number of uid's of the cashier
		uid_count++;
		line.pop();
			}