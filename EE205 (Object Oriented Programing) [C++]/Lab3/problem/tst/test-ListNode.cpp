#include <iostream>
#include <cassert>
#include "ListNode.hpp"

int main() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);

    node1.set_next(&node3);

    assert(node1.get_next() == &node3);
    assert(node2.get_next() == nullptr);
    assert(node1.get_next()->get_next() == node3.get_next());
    assert(node1.get_next()->get_next() == nullptr);
    
    ListNode node4 = std::move(node1);

    assert(node4.get_data() == 1);
    assert(node4.get_next() == &node3);
    assert(node2.get_next() == nullptr);
    assert(node4.get_next()->get_next() == node3.get_next());
    assert(node4.get_next()->get_next() == nullptr);

    ListNode node5(node4);
        
    assert(node5.get_data() == node4.get_data());
    assert(node5.get_next() == node4.get_next());
    assert(node5.get_next()->get_next() == nullptr);
    assert(node5.get_next()->get_next() == node4.get_next()->get_next());
    assert(node5.get_next()->get_data() == node4.get_next()->get_data());

    std::cout << std::endl;
    std::cout << "SUCCESS" << std::endl;
    return 0;
}
