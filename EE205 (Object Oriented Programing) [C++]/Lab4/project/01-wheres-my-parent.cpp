#include <iostream>
#include <cassert>

class Mammal {
private:
    unsigned count;
public:
    Mammal() :
        count(0) {}

    Mammal(unsigned i) :
        count(i) {}

    void heartbeat() { 
        count = (count + 1) % 4;
        if (count == 0) {
            std::cout << "Boom" << std::endl;
        } else {
            std::cout << "Thump" << std::endl;
        }
    }
};

class Human:public Mammal {
    public:
        Human() :
            // This is how you call the base class constructor
            // from within the derived class constructor's
            // initialization list
            Mammal(1) {}

        void idle() {
            heartbeat(); 
        } 

        void panic() {
            heartbeat();
            heartbeat();
            heartbeat();
            heartbeat();
            heartbeat();
        }
};

// This program does not compile.
//
// Why not? The problem is with the Human class, not with main() or Mammal.
//
// Change the Human class so that it can use methods/member functions from the 
// Mammal class by inheriting from Mammal.
int main() {
    Human nitsua;

    nitsua.idle();

    nitsua.panic();
    nitsua.panic();
    nitsua.panic();

    std::cout << "\n\nCongrats, Human now inherits from Mammal!\n\n"
              << std::endl;
    std::cout << "SUCCESS" << std::endl;

    assert(true);
}
