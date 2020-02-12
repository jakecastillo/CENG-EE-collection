#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "SupplyRunner.hpp"
#include "Storeroom.hpp"

#include <queue>

TEST_CASE("Single Ingredient", "[SupplyRunner]") {
    // Given: A Storeroom with only 2 ingredients
    Storeroom storeroom = {
        {"Potato", 1},
        {"Tomato", 1}
    }; 
    // Given: A SupplyRunner who is constructed with a Storeroom&
    SupplyRunner runner(storeroom);
    // When: A SupplyRunner is asked to get 1 Potato
    std::vector<Ingredient> fetched =
        runner.get_ingredients({
                {"Potato", 1}
        });

    // Then: The SupplyRunner should return 1 Potato
    REQUIRE(fetched == std::vector<Ingredient>{"Potato"});
    // Then: The Storeroom shoudld have no Potato but 1 Tomato
    REQUIRE(storeroom["Potato"] == 0);
    REQUIRE(storeroom["Tomato"] == 1);
}

TEST_CASE("Double Ingredients", "[SupplyRunner]") {
    // Given: A Storeroom with only 10 of 1 ingredient
    Storeroom storeroom = {
        {"SmallCup", 10}
    };
    // Given: A SupplyRunner who has mutable access to a Storeroom
    SupplyRunner runner(storeroom);
    // When: A supplyRunner is asked to get 2 SmallCup
    std::vector<Ingredient> fetched = runner.get_ingredients({
            {"SmallCup", 2}
    });
    // Then: The SupplyRunner should return 2 SmallCup
    REQUIRE(fetched == std::vector<Ingredient>{"SmallCup", "SmallCup"});
    // Then: THe Storeroom should have 10 - 2 SmallCup
    REQUIRE(storeroom["SmallCup"] == 10-2);
}

TEST_CASE("Multi Ingredients", "[SupplyRunner]") {
    // Given: A Storeroom with multiple types of ingredients
    Storeroom storeroom = {
        {"Cheese", 10},
        {"Lettuce", 10},
        {"MediumCup", 10},
    };
    // Given: A SupplyRunner who has mutable access to a Storeroom
    SupplyRunner runner(storeroom);
    // When: A SupplyRunner is asked to get 2 SmallCup
    std::vector<Ingredient> fetched = runner.get_ingredients({
            {"Cheese", 1},
            {"Lettuce", 2},
            {"MediumCup", 3}
    });
    // Then: The SupplyRunner should return 2 SmallCup
    REQUIRE_THAT(fetched, Catch::Matchers::Contains<Ingredient>({"Cheese"}));
    REQUIRE_THAT(fetched, Catch::Matchers::Contains<Ingredient>({"Lettuce", "Lettuce"}));
    REQUIRE_THAT(fetched, Catch::Matchers::Contains<Ingredient>({"MediumCup", "MediumCup", "MediumCup"}));

    // Then: THe Storeroom should have 10 - 2 SmallCup
    REQUIRE(storeroom["Cheese"] == 10-1);
    REQUIRE(storeroom["Lettuce"] == 10-2);
    REQUIRE(storeroom["MediumCup"] == 10-3);
}

TEST_CASE("No ingredients? Throw const char*", "[SupplyRunner]") {
    // Given: A Storeroom with Potato and SugarCone
    Storeroom storeroom = {
        {"Potato", 25},
        {"SugarCone", 12}    
    };
    // Given: A SupplyRunner setup to use the Storeroom
    SupplyRunner runner(storeroom);
    // When: A SupplyRunner is asked to get a single ingredient Cheese
    // that is not in the Storeroom
    REQUIRE_THROWS_AS([&]() {
        std::vector<Ingredient> fetched = runner.get_ingredients({
                {"Cheese", 1}
        });
    }(), const char*);
    // Then: The SupplyRunner should throw a const char*
    // Then: The Storeroom should not be touched.
    REQUIRE(storeroom["Potato"] == 25); 
    REQUIRE(storeroom["SugarCone"] == 12); 
}


