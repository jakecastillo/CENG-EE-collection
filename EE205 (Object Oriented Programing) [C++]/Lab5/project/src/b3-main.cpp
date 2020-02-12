#include <iostream>
#include <cassert>

#include "string_conversion.hpp"

// A type that we will overload operator<< for
// so that we can print it out.
template <typename Left, typename Right>
struct Pair {
    Left left;
    Right right;
};

// Pairs use the operator<< of their left and right member
// variable types, separate the results using a | and
// encapsulate them using a ().
//
// So, Pair<int, int> where left = 1 and right = 2 ===> Pair(1|2).
template <typename Left, typename Right>
std::ostream& operator<<(std::ostream& lhs, Pair<Left, Right> rhs) {
    lhs << "Pair(" << rhs.left << "|" << rhs.right << ")";
    return lhs;
}

int main() {
    // Let's create varying amounts of types to test.
    int i = 123;
    float f = 456;
    std::string s = "hello world";
    Pair<std::string, double> pair;
    pair.left = "abc";
    pair.right = 3.1415;

    Pair<int, Pair<float, float>> nested_pair;
    nested_pair.left = -900;
    nested_pair.right.left = 1.23;
    nested_pair.right.right = 4.56;

    // Let's test a bunch of cases for lexical cast.
    assert(lexical_cast(i) == "123");
    assert(lexical_cast(f) == "456");
    assert(lexical_cast(s) == "hello world");
    assert(lexical_cast(pair) == "Pair(abc|3.1415)");
    assert(lexical_cast(nested_pair) == "Pair(-900|Pair(1.23|4.56))");

    ////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////

    std::vector<
        Pair<int, std::string>
    > people;
    // The {1, "Bob"} gets converted using list initialization
    // automatically a Pair<int, std::string>.
    //
    // This is so I can use the default constructor that initializes
    // struct-like types automatically without writing the
    // constructor above in Pair!
    people.push_back({1, "Bob"});
    people.push_back({2, "Jane"});
    people.push_back({3, "Qybert"});

    assert(vector_to_string(people) == "Pair(1|Bob),Pair(2|Jane),Pair(3|Qybert)");

    // Erase the 2nd element in the vector.
    //
    // vector.begin() returns what is called an iterator, an
    // important concept for C++ standard library container types.
    people.erase(people.begin() + 1);

    // vector_to_string() should respond to changes in the vector.
    assert(vector_to_string(people) == "Pair(1|Bob),Pair(3|Qybert)");

    std::cout << "SUCCESS" << std::endl;

}
