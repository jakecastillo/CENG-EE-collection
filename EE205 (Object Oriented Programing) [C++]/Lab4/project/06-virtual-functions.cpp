#include <iostream>
#include <sstream>
#include <cassert>

// *** Your task is to add the virtual keyword before the `void` in both classes 
// below.
//
// You'll also have to add `override` after the `print()` but before the `{`.
//
// (It's sort of like the same syntax for `int get_x() const {}` for the `const` 
// part.)

class A {
public:
    virtual void print(std::ostream& out) { out << "A.print()" << std::endl; }
};

class ChildA : public A {
public:
   virtual void print(std::ostream& out) override{ out << "ChildA.print()" << std::endl; }
};


int main() {
    A a;
    ChildA kid_a;

    // A* = A*
    A* ptr_a = &a;
    // A* = ChildA*
    A* ptr_child_a = &kid_a;
    // ChildA* = ChildA*
    ChildA* ptr_kid_a = &kid_a;

    // Call print() using all of the 3 pointers
    ptr_a->print(std::cout);
    ptr_child_a->print(std::cout);
    ptr_kid_a->print(std::cout);

    // Check our answers!
    std::stringstream ss;

    ptr_a->print(ss);
    assert(ss.str() == "A.print()\n");
    ss.str(""); ss.clear();

    ptr_child_a->print(ss);
    assert(ss.str() == "ChildA.print()\n");
    ss.str(""); ss.clear();

    ptr_kid_a->print(ss);
    assert(ss.str() == "ChildA.print()\n");
    ss.str(""); ss.clear();

    std::cout << "SUCCESS" << std::endl;
}
