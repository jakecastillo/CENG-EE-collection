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

std::ostream& operator<<(std::ostream& lhs, const Dish& rhs) {
    lhs << "Dish(";
    if (rhs == Dish::FRIES) {
        lhs << "Fries";
    }
    else if (rhs == Dish::BURGER) {
        lhs << "Burger";
    }
    else if (rhs == Dish::DOUBLE_BURGER) {
        lhs << "DoubleBurger";
    }
    else if (rhs == Dish::SMALL_DRINK) {
        lhs << "SmallDrink";
    }
    else if (rhs == Dish::MEDIUM_DRINK) {
        lhs << "MediumDrink";
    }
    else if (rhs == Dish::LARGE_DRINK) {
        lhs << "LargeDrink";
    }
    else if (rhs == Dish::SALAD) {
        lhs << "Salad";
    }
    else if (rhs == Dish::ICE_CREAM_CONE) {
        lhs << "IceCreamCone";
    }
    else if (rhs == Dish::NO_1) {
        lhs << "#1";
    }
    else if (rhs == Dish::NO_2) {
        lhs << "#2";
    }
    else if (rhs == Dish::NO_3) {
        lhs << "#3";
    } else {
        lhs << "<inedible>";
    }
    lhs << ")";
    return lhs;
}

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

    // Create a Storeroom of ingredients.
    Storeroom storeroom = {
        {"Potato",          20},
        {"Lettuce",         25},
        {"CanolaOil",       30},
        {"Tomato",          10},
        {"WheatBun",        30},
        {"BeefPatty",       25},
        {"Cheese",          20},
        {"SmallCup",        20},
        {"MediumCup",       20},
        {"LargeCup",        20},
        {"SugarCone",       15},
        {"VanillaCream",    15},
        {"SaladDressing",   15},
        {"Fork",            15}
    };

    Kitchen kitchen;
    Cashier cashier(100);
    SupplyRunner runner(storeroom);
    Cook cook(runner, kitchen);

    // Get each item out of the queue, and print it.
    while (!customer_line.empty()) {
        std::cout << customer_line.front() << std::endl;
        cashier.serve_customer(customer_line, order_stack); 
        cook.prepare_dish(order_stack, finished_dishes);
    }

    // Print out the order stack.
    while (!order_stack.empty()) {
        std::cout << order_stack.top() << std::endl;
        order_stack.pop();
    }

    // Print out the finished dishes queue.
    while (!finished_dishes.empty()) {
        std::cout << "{" << finished_dishes.front().first
            << "|" << finished_dishes.front().second << "}" << std::endl;
        finished_dishes.pop();
    }

    std::cout << "Number of customers expelled: " << expelled_count << std::endl;
}
