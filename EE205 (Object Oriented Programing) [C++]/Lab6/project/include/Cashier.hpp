#ifndef EE205_CASHIER_HPP
#define EE205_CASHIER_HPP

#include "Customer.hpp"
#include "Order.hpp"

#include "restaurant-utility.hpp"

#include <queue>
#include <stack> 

/**
 * @brief Interacts with Customers, charges them money, and parses their orders.
 *
 * @note Must give each Customer upon interaction a unique ID number, counting 
 * up from 0.
 */
class Cashier {
    private:
        /**
         * @brief The amount of money that the Cashier currently has.
         */
        double money;
        /**
         * @brief The current count of the unique ID (uid) of the Cashier kept 
         * for customers.
         */
        std::size_t uid_count; 

    public:
        /**
         * @brief Constructs the Cashier with a set amount of money.
         */
        Cashier(double money_);

        /**
         * @brief Gets the amount of money that the cashier holds.
         */
        double get_money() const;

        /**
         * @brief Serves a customer by taking them off the queue, and possibly 
         * putting an order, if valid, onto the order stack.
         *
         * - Retrieves the customer from the queue, popping them off.
         *
         * - Receives the customer's desired order items in string format:
         *
         *      <number-of-items> <name-of-item-with-no-spaces>
         *   
         *      - Multiple items are separated simply by a space
         *
         * - If the Cashier detects an order for an invalid item that is not on 
         *   the menu, it must expel() the customer.
         *
         * - Must calculate the cost of all the items ordered, and charge the 
         *   customer.
         *
         *      - It the customer does not have enough money to pay, do not 
         *      charge the customer, but instead, expel() them.
         *
         * - Once paid for, the order items must be consolidated into an Order, 
         *   which is tagged with the unique customer ID generated at the
         *   beginning of this function, and then push it onto the stack.
         *
         * @see Customer
         * @see Order
         */
        void serve_customer(
                std::queue<Customer>& line,
                std::stack<Order>& orders);
};

#endif // EE205_CASHIER_HPP
