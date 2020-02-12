#include <iostream>
#include <algorithm>    // for std::max()
#include <cassert>      // for assert()
#include <utility>      // for std::move()

class Unit {
private:
    std::string name;
    int health;
    int mana;
    int attack;
    int defense;
public:
    // Constructs a unit with the correct fields.
    Unit(std::string name_,
         int health_,
         int mana_,
         int attack_,
         int defense_) :
        name(name_), health(health_),
        mana(mana_),
        attack(attack_),
        defense(defense_) {}

    // Copy constructor.
    Unit(const Unit& other) :
        name(other.name),
        health(other.health),
        mana(other.mana),
        attack(other.attack),
        defense(other.defense) {}

    // Move constructor.
    Unit(Unit&& other) :
        name(std::move(other.name)),
        health(std::move(other.health)),
        mana(std::move(other.mana)),
        attack(std::move(other.attack)),
        defense(std::move(other.defense)) {} 

    void attack_other(Unit& other) {
        int damage = std::max(0, this->attack - other.defense);
        other.on_attack(damage);
    }

    void on_attack(int damage) {
        std::cout << name << " was attacked for "
                  << damage << " points!" << std::endl;
        this->health -= damage;

        if (this->health <= 0) {
            on_death();
        }
    }

    bool is_dead() const {
        return this->health <= 0;
    }

    void on_death() {
        std::cout << name << " passed out!" << std::endl;
    } 
    std::string get_name() const { return name; }
    int get_health() const { return health; }
    int get_mana() const { return mana; }
    int get_attack() const { return attack; }
    int get_defense() const { return defense; }

    void set_name(std::string s) {  name = s; }
    void set_health(int i) { health = i; }
    void set_mana(int i) { mana = i; }
    void set_attack(int i) { attack = i; }
    void set_defense(int i) { defense = i; }
};

// Create two classes that inherit from Unit: Goblin and Wizard
// such that Goblin gets initialized with:
//
//      health = 100
//      mana = 10
//      attack = 10
//      defense = 10
//
// and Wizard gets initialized with:
//
//      health = 1000
//      mana = 100
//      attack = 10
//      defense = 0
//
// by supplying these parameters to the base class constructor
// in their own constructor's initialization list.
//
// Wizard should also get a member function called
//  
//      void blizzard(Goblin& other);
//
// that, when called, will reduced other.defense to 0.
//
// Of course, you will still need to take the std::string as the name
// for the "wizard" or "goblin."

/* Create the Goblin and Wizard classes here */

class Goblin:public Unit{
	public:
	Goblin(std::string name_):Unit(name_,100,10,10,10) { }
};
class Wizard:public Unit{
	public:
	Wizard(std::string name_):Unit(name_,1000,100,10,0) { }
	void blizzard(Goblin& other){
		other.set_defense(0);
	}
};

/* ******************************************** */

int main() {

    Wizard w("Jayna");
    assert(w.get_name() == "Jayna");
    Goblin g("Thrull");
    assert(g.get_name() == "Thrull");

    // Jayna will not be be able to damage Thrull because its
    // defense will be 10, completely nullifying the 10 attack.
    for (int i = 0; i < 20; ++i) {
        w.attack_other(g);    
        assert(!w.is_dead() && !g.is_dead());
    }

    // When Jayna uses Blizzard, Thrull's defense should be reduced to 0.
    w.blizzard(g);

    // After 10 attacks of 10 attack each dealing 100 points total,
    // Thrull should pass out.
    for (int i = 0; i < 10; ++i) {
        assert(!w.is_dead() && !g.is_dead());
        w.attack_other(g);
    }
    assert(g.is_dead());

    std::cout << "SUCCESS" << std::endl;
} 
