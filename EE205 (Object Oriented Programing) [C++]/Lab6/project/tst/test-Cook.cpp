#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Cook.hpp"
#include "Order.hpp"

#include <stack>
#include <queue>

TEST_CASE("One Item", "[Cook]") {
    // Given: a Storeroom and a Kitchen for the Cook to use
    Storeroom storeroom = {
        {"Potato",      1},
        {"CanolaOil",   1}
    };
    Kitchen kitchen;

    // Given: a SupplyRunner who is setup to go search for
    // Ingredients in the Storeroom
    SupplyRunner runner(storeroom);

    // Given: a Cook with a SupplyRunner and a Kitchen.
    Cook cook(runner, kitchen);

    // Given: an empty, ready queue of pairs of ids and dishes
    std::queue<std::pair<std::size_t, Dish>> finished_dishes;

    // Given: 1 order for Fries
    std::stack<Order> orders({
        {0, {"Fries"}}
    });

    // When: the cook prepares the dish corresponding to the order
    cook.prepare_dish(orders, finished_dishes);

    // Then: the order stack should be empty
    REQUIRE(orders.empty());

    // Then: the created dishes should be the following (since we take things
    // off the stack in the reverse order they appear, and feed them into
    // the queue)
    REQUIRE(finished_dishes == std::queue<std::pair<std::size_t, Dish>>({
            {0, Dish::FRIES}
    }));

}

TEST_CASE("All Single Items", "[Cook]") {
    // Given: a Storeroom and a Kitchen for the Cook to use
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

    // Given: a SupplyRunner who is setup to go search for
    // Ingredients in the Storeroom
    SupplyRunner runner(storeroom);

    // Given: a Cook with a SupplyRunner and a Kitchen.
    Cook cook(runner, kitchen);

    // Given: an empty, ready queue of pairs of ids and dishes
    std::queue<std::pair<std::size_t, Dish>> finished_dishes;

    // Given: 1 order of every kind of Dish on the stack of orders
    std::stack<Order> orders({
        {0, {"Fries"}},
        {1, {"Burger"}},
        {2, {"DoubleBurger"}},
        {3, {"IceCreamCone"}},
        {4, {"SmallDrink"}},
        {5, {"MediumDrink"}},
        {6, {"LargeDrink"}},
        {7, {"Salad"}},
        {8, {"#1"}},
        {9, {"#2"}},
        {10, {"#3"}}
    });

    // When: The cook takes and processes every order, taking them
    // off the stack progressively.
    while(!orders.empty()) {
        cook.prepare_dish(orders, finished_dishes);
    }

    // Then: the order stack should be empty
    REQUIRE(orders.empty());

    // Then: the created dishes should be the following (since we take things
    // off the stack in the reverse order they appear, and feed them into
    // the queue)
    REQUIRE(finished_dishes == std::queue<std::pair<std::size_t, Dish>>({
        {10, Dish::NO_3},
        {9, Dish::NO_2},
        {8, Dish::NO_1},
        {7, Dish::SALAD},
        {6, Dish::LARGE_DRINK},
        {5, Dish::MEDIUM_DRINK},
        {4, Dish::SMALL_DRINK},
        {3, Dish::ICE_CREAM_CONE},
        {2, Dish::DOUBLE_BURGER},
        {1, Dish::BURGER},
        {0, Dish::FRIES},
    }));
}

TEST_CASE("No ingredients? Throw const char*", "[Cook]") {

    // Given: an empty Storeroom
    Storeroom storeroom = {};
    // Given: a Kitchen, a SupplyRunner to use the Storeroom
    Kitchen kitchen;
    SupplyRunner runner(storeroom);
    // Given: a Cook to use the SupplyRunner and the Kitchen
    Cook cook(runner, kitchen);
    // Given: a single order for Fries
    std::stack<Order> orders({
        {0, {"Fries"}}
    });
    // Given: an output queue to put the (id, Dish) in
    std::queue<std::pair<std::size_t, Dish>> dishes;
    // When: the Cook tries to prepare the Order but there are no
    // ingredients since the SupplyRunner will throw a const char*
    // Then: the Cook should also throw a const char*
    REQUIRE_THROWS_AS(
            cook.prepare_dish(orders, dishes),
            const char *);
}

TEST_CASE("No orders? Do nothing", "[Cook]") {
    // Given: an empty Storeroom
    Storeroom storeroom = {};
    // Given: a Kitchen, a SupplyRunner to use the Storeroom
    Kitchen kitchen;
    SupplyRunner runner(storeroom);
    // Given: a Cook to use the SupplyRunner and the Kitchen
    Cook cook(runner, kitchen);
    // Given: an output queue to put the (id, Dish) in
    std::queue<std::pair<std::size_t, Dish>> dishes;
    // Given: no orders at all
    std::stack<Order> orders;
    // When: the cook tries to prepare a dish from an order
    cook.prepare_dish(orders, dishes);
    // Then: the stack should be unchanged
    REQUIRE(orders.empty());
    // Then: the queue should be unchanged
    REQUIRE(dishes.empty());
}
