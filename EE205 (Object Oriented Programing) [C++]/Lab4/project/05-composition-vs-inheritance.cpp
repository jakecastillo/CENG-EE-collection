#include <iostream>
#include <string>
#include <cassert>

class Human {
private:
    std::string name;
public: 
    Human(std::string name_) :
        name(name_) {}
}; 

class MagicStaff {
public:
    void cast_fireball() const {
        std::cout << "Fireball!" << std::endl;
    }
};

// The current design of the class Wizard, conceptually, is sort of faulty.
//
// When using inheritance, you should have some sort of property that says that 
// "Derived is-a Base class."
//
// With multiple inheritance here, is it correct to say that "Wizard is-a Human 
// and is-a MagicStaff?"
//
// Usually, we would think that "a Wizard HAS-A MagicStaff."
//
// IS-A == INHERITANCE (object trait inheriting)
// HAS-A == COMPOSITION (object owning)
//
// e.g. a Car has-a Wheel but not is-a Wheel.
//
// *** FIX THE WIZARD CLASS BY MAKING IT ***NOT** INHERIT FROM MAGICSTAFF.
//
// INSTEAD, HAVE WIZARD OWN A MAGICSTAFF OBJECT THAT IT WILL CALL IN 
// Wizard.cast_spell().

class Wizard : public Human {
private:
    int num_spells_casted;
    MagicStaff staff;
public:
	Wizard(std::string name):
        Human(name),
        num_spells_casted(0) {}
    // Upon first cast, print, on its own line:
    //
    //     Your spell fizzles out...
    //
    // Upon the N = 2 and greater cast, call MagicStaff.cast_fireball()
    // N-1 times.
    void cast_spell() {
        if (num_spells_casted <= 0) {
            std::cout << "Your spell fizzles out..." << std::endl;
            ++num_spells_casted;
        } else {
            for (int i = 0; i < num_spells_casted; ++i) {
                this->staff.cast_fireball();
            }
            ++num_spells_casted;
        }
    }
};

bool wizard_has_cast_fireball();

int main() {
    Wizard ghadkar("Ghadkar");
    
    // Should fizz the first time
    ghadkar.cast_spell();

    // fireball() should be cast a total of 6 times.
    ghadkar.cast_spell();
    ghadkar.cast_spell();
    ghadkar.cast_spell();

    assert(!wizard_has_cast_fireball());

    std::cout << "SUCCESS" << std::endl;

    // You should not be able to do: ghadkar.fireball();
    //
    // Otherwise, my SFINAE will be able to detect at compile-time.
}


////////////////////////////////////////////////////////////////////////////////
// BEWARE OF TEMPLATE METAPROGRAMMING
//
// DO NOT LOOK BELOW
//
// (The code below is used to check for the existance of a member function
// at compile-time using templates. Not needed to understand for this lab.)
////////////////////////////////////////////////////////////////////////////////

#include <type_traits>

template <typename>
struct sfinae_true : std::true_type {};

namespace detail {
    template <typename T>
    static auto test_cast_fireball(int)
        -> sfinae_true< decltype(std::declval<T>().cast_fireball()) >;

    template <typename>
    static auto test_cast_fireball(long)
        -> std::false_type;
}

template <typename T>
struct has_cast_fireball : decltype(detail::test_cast_fireball<T>(0)) {};

bool wizard_has_cast_fireball() {
    return has_cast_fireball<Wizard>::value;
}
