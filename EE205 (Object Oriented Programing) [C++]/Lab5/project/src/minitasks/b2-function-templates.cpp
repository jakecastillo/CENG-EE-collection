#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <cassert>

template <typename Container>
void print(std::ostream& out, const Container& cont) {
    for (int i = 0; i < cont.size(); ++i) {
        out << cont[i] << std::endl;
    }
}

template <typename FirstContainer, typename SecondContainer>
bool is_equal (FirstContainer lhs, SecondContainer rhs) {
    // How can you write an algorithm to automatically go through
    // each item in each container, compare them element-wise, and return
    // whether they have the same exact elements in the same exact order?
    //
    // It is recommneded to use operator== or operator!= for this.
 
    int x = lhs.size();
    if(x < rhs.size()){
    x = rhs.size();
    }
    for(int i = 0; i < x; i++)
    {
    	if(lhs[i] != rhs[i]){
	return false;
	}
    }
    return true;
}

int main() {
    std::deque<long> container_1;

    container_1.push_back(1);
    container_1.push_back(2);
    container_1.push_back(3);

    std::vector<float> container_2;

    container_2.push_back(1.0);
    container_2.push_back(2.0);
    container_2.push_back(3.0);

    std::array<int, 3> container_3;

    container_3[0] = 4;
    container_3[1] = 3;
    container_3[2] = 2;

    print(std::cout, container_1);
    print(std::cout, container_2);
    print(std::cout, container_3);

    assert(is_equal(container_1, container_2)
            && "You are not comparing double-ended queue and vector correctly.");
    assert(!is_equal(container_2, container_3)
            && "The vector and array should be considered non-equal.");
    assert(!is_equal(container_1, container_3)
            && "The deque and the array are not carrying the name items.");

    std::cout << "SUCCESS" << std::endl;
}
