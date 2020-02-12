#include <iostream>
#include <cassert> 

#include "InsertionSortVector.hpp"
#include "BubbleSortVector.hpp"

int main() {
    InsertionSortVector<int> v1;
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(1);

    v1.sort();
    std::cout << "Insertion Sort:" << std::endl;
    for (int i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << std::endl;
    }

    for (int i = 1; i < v1.size(); ++i) {
        assert(v1[i] >= v1[i-1]
            && "The vector was not sorted correctly in ascending order "
            "using insertion sort.");
    }

    BubbleSortVector<int> v2;
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(1);

    v2.sort();
    std::cout << "Bubble Sort:" << std::endl;
    for (int i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] << std::endl;
    }
    for (int i = 1; i < v2.size(); ++i) {
        assert(v2[i] >= v2[i-1]
            && "The vector was not sorted correctly in ascending order "
            "using bubble sort.");
    }

    std::cout << "SUCCESS" << std::endl;

}
