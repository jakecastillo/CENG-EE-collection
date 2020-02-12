#include <iostream>
#include <cassert>

class InnerCityRing {
    // How can we make it so that inner_city_population
    // can be accessed by the child/derived class of OuterCityRing?
    //
    // You should change the access specifier below to NOT public or private.
    public:
        unsigned inner_city_population; 

    public:
        InnerCityRing(std::size_t pop) :
            inner_city_population(pop) {}
};

class OuterCityRing : public InnerCityRing {
    private:
        unsigned outer_city_population;

    public:
        OuterCityRing(std::size_t pop) :
            InnerCityRing(1),
            outer_city_population(pop) {}

        unsigned total_population() const {
            return this->outer_city_population +
                   this->inner_city_population;
        }
};

// The InnerCityRing's inner_city_population variable is private,
// so the OuterCityRing cannot access that variable.
int main() {
    OuterCityRing city(100000);
    std::cout << "There is no war within the walls. Census time!" << std::endl;
    std::cout << city.total_population() << std::endl;

    assert(city.total_population() == 100001);

    std::cout << "SUCCESS" << std::endl;
}
