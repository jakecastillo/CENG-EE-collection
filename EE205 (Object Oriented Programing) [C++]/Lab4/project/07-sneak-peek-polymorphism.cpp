#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

// In the next lab, inheritance will be used to implement polymorphism.
//
// This means "one type/command, different behavior/forms"
//
// Here, we will use an abstract class with virtual functions.
// This is so we can have IMagicSpell* but not IMagicSpell directly,
// sort of how you might want the "abstract idea" of a general "class of Shapes" 
// but not a Shape object directly, because "Shape" is a category over specific 
// types of shapes like "Square" or "Circle."
class IMagicSpell {
public:
    virtual void cast_spell(std::ostream& out) = 0;   
};

class Fireball : public IMagicSpell {
public:
    virtual void cast_spell(std::ostream& out) override {
        out << "Fireball!" << std::endl; 
    }
};

class Icebolt : public IMagicSpell {
public:
    virtual void cast_spell(std::ostream& out) override {
        out << "Icebolt!" << std::endl;
    }
};

class Zap: public IMagicSpell {
public:
	virtual void cast_spell(std::ostream& out) override {
	out << "Zap!" <<std::endl;
	}
};

// *** Your task is to implement a class named Zap
// that inherits from IMagicSpell, and overrides cast_spell()
// similarly to the other classes to print "Zap!" on its own line when
// that function is called.
//
// You don't need to know polymorphism -- you just need to magically
// copy the code above and slightly modify it.
//
// The purpose of this part is to give you exposure to concepts needed for the 
// lab.

int main() {
    std::vector<IMagicSpell*> spells;
    spells.push_back(new Fireball());
    spells.push_back(new Icebolt());
  
    ////////////////////////////////////////////////////////////////////// 
    ////                UNCOMMENT THIS LINE OF CODE BELOW             ////
    //////////////////////////////////////////////////////////////////////
    spells.push_back(new Zap());
    
    std::stringstream ss;
    
    for (int i = 0; i < spells.size(); ++i) {
        // One pointer type, but still calling the child class methods 
        // automatically?!
        //
        // MAGIC!!! (polymorphism)
        spells[i]->cast_spell(ss);
    }
    std::cout << ss.str() << std::endl;
    assert(ss.str() == "Fireball!\nIcebolt!\nZap!\n");

    // Here's a sneak peak at the modern C++11 `for` loop syntax
    // that uses something called "iterators" under the hood.
    //
    // Also, it uses `auto` which tries to have the compiler "fill-in-the-blank" 
    // automatically because it can usually figure out what type is supposed to 
    // go in "auto".
    for (auto it : spells) {
        delete it;
    }

    std::cout << "SUCCESS" << std::endl;
}

