#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include <functional>
#include <stdexcept>

// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Note: Compile this program by -I the directory of where the catch.hpp
// header is. I compiled it with:
//
//      g++ -std=c++11 02-catch2.cpp -I../dep/
//
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//    specific test case name
//        |||||||||||||
//        |||||||||||||   test case suite name
//        |||||||||||||         |||||||
//        vvvvvvvvvvvvv         vvvvvvv
TEST_CASE("Introducing Catch", "[Catch]") {

    //////////////////////////////////////////////////////////////////////
    // 1. Introducing Catch2
    //////////////////////////////////////////////////////////////////////
    //
    // Catch2 is a testing framework for C++. (It is named Catch2 because it is 
    // a second version for the prior Catch testing framework.)
    //
    // Notice that the `catch.hpp` header resides in the dep/ folder. Catch2 is 
    // a header-only library -- this means it's easy to use in your own project 
    // by using copying and including the header when you need it, but it also 
    // means that the compile-time is bloated because you need to recompile 
    // Catch2 every time you use it.
    //
    // This is to signal that Catch2 is a dependency that exists outside of our 
    // own code that we are "importing" to use in our own program.
    //
    // This is an example of a test case. Note that the way Catch2 setups a test 
    // case is to use this `TEST_CASE(<case name>, <suite name>, <body>)` macro 
    // that is turned into some sort of function.
    //
    // Note that a main() is supplied automatically because the C preprocessor 
    // flag `CATCH_CONFIG_MAIN` will generate a correct main() function for you.
    // So, it's really easy just to boot up a new file and create new test 
    // cases, using test case files to organize as you see fit.
   
    //////////////////////////////////////////////////////////////////////
    // 2. CHECK and REQUIRE
    //////////////////////////////////////////////////////////////////////
    //
    // So, what does Catch2 actually do for you?
    //
    // Catch2 provides macros that can test your programs by checking whether 
    // conditions are true or false.
    //
    // CHECK(bool) will report whether the boolean it is given is true or false. 
    // It will not abort the test case but report an error for the test case.
    //
    // REQUIRE(bool) will abort the test if it is given false.

    CHECK(1 == 2);
    REQUIRE(std::string("abc") == "abc");
}

TEST_CASE("Testing Exceptions", "[Catch]") {

    //////////////////////////////////////////////////////////////////////
    // 3. Testing Exceptions
    //////////////////////////////////////////////////////////////////////
    //
    // Catch2 provides a macro to even check whether exceptions are thrown 
    // within a certain expression.
    //
    // Below, we use a feature you haven't seen before: C++11 lambda expressions 
    // to create a function literal that can be stored in a variable.
    //
    // The syntax is: [](<args>) { <body> }
    //
    // If you are assigning it to a variable, you still need the semicolon 
    // after.

    // std::function is defined in <functional>
    std::function<int(int, int)> divide = [](int a, int b) {
        if (b == 0) {
            // std::runtime_error is defined in <stdexcept>
            throw std::runtime_error("divide: divisor cannot be 0");
        }
        return a / b;
    };
    // This just created a function object for use in this scope/test case.

    // We can use the REQUIRE_THROWS_AS macro to check whether we are throwing
    // the correct type of exception.
    REQUIRE_THROWS_AS(
        divide(1, 0),       // the expression to execute
        std::runtime_error  // the exception type to be thrown
    );
    REQUIRE(divide(2, 2) == 1);

    // We can also create a temporary lambda expression and immediately invoke 
    // it. Here, we create a void(void) function that just simply always throws 
    // "Hello world" and then immediately invoke it. We wrap that with a 
    // REQUIRE_THROWS_AS macro that checks whether we threw a const char* (a 
    // C-style string) from within the expression (which it always does).
    REQUIRE_THROWS_AS([](){
            throw "Hello world!";
        }(),
        const char*
    );
}
