#include <iostream>
#include <sstream> // Stringstreams allow you to print to std::string!
#include <string>
#include <cassert>

// A is the base class.
class A { };

// Both B and C derive from A,
// and define the same member function name with the same type signature.
class B : public A {
    public:
        void print(std::ostream& out) {
            out << "B.print()" << std::endl;
        }
};
class C : public A {
    public:
        void print(std::ostream& out) {
            out << "C.print()" << std::endl;
        }
};

// What happens when D derives from B and C, and tries to call the function that 
// both have defined with the same signature?
//
// You'll have an error. This is the diamond problem (ambiguity in what function 
// to call). This is also why we use the scope operator.
//
// For this problem, please make it so that D.do_the_thing() will call print() 
// from the parent class of C.
class D : public B, public C {
public:
    // Even though I don't define a default constructor
    // C++ will provide a default constructor by default that does nothing
    //
    // A "default default constructor!"
    //
    void do_the_thing(std::ostream& out) {
        this->C::print(out);
    }
};

int main() {
    D assistant;

    // Remember std::cout?
    //
    // std::cout is of type std::ostream.
    //
    // std::stringstream will derive from both std::istream and std::ostream!
    //
    // So, you can pass it around as a std::ostream&.
    std::stringstream ss;

    // Write your output into the stringstream
    assistant.do_the_thing(ss);
   
    // Compare the output for correctness. 
    assert(ss.str() == std::string("C.print()\n"));


    // If it doesn't crash, print "SUCCESS" at the end.
    std::cout << "SUCCESS" << std::endl;
}
