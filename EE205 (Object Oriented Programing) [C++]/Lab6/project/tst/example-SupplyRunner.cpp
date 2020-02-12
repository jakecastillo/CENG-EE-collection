#include <iostream>

#include "Storeroom.hpp"
#include "SupplyRunner.hpp"

int main() {

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
    
    std::cout << storeroom << std::endl;
    SupplyRunner runner(storeroom);    

    try {
        runner.get_ingredients({
            {"Potato", 21}
        });
    } catch (const char* c) {
        std::cout << c << std::endl;
    }

    runner.get_ingredients({
        {"Potato", 20}
    });

    std::cout << storeroom << std::endl;;

    runner.get_ingredients({
        {"Fork", 1},
        {"Tomato", 1},
        {"SaladDressing", 1},
        {"Lettuce", 1}
    });

    std::cout << storeroom << std::endl;;
}
