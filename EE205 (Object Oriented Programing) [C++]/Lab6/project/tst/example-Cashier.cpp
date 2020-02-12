#include "Customer.hpp"
#include "Order.hpp"
#include "Cashier.hpp"
#include "Dish.hpp"
#include "Cook.hpp"

#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <utility>

int main() {
    std::vector<Customer> customers = {
        {100, "1 Burger 1 Fries"},
        {10, "2 SmallDrink 1 IceCreamCone"},
        {0, "1 DoubleBurger"},
        {15, "1 Salad"},
        {25, "3 LargeDrink 3 IceCreamCone"},
        {300, "1 BreakfastPlatter"},
        {30, "1 BobKebob"}
    };

    // Create the customer line.
    std::queue<Customer> customer_line;
    for (const auto& it : customers) {
        customer_line.push(it);
    }

    // Create the order stack.
    std::stack<Order> order_stack;

    // Create a queue for finished dishes
    std::queue<std::pair<std::size_t, Dish>> finished_dishes;

    Cashier cashier(100);

    // Get each item out of the queue, and print it.
    while (!customer_line.empty()) {
        std::cout << customer_line.front() << std::endl;
        cashier.serve_customer(customer_line, order_stack); 
    }

    while (!order_stack.empty()) {
        std::cout << order_stack.top() << std::endl;
        order_stack.pop();
    }
}
