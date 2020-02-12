#ifndef EE205_INSERTION_SORT_VECTOR_HPP
#define EE205_INSERTION_SORT_VECTOR_HPP

#include <vector>

#include "ISortable.hpp"


template <typename T>
class InsertionSortVector :
    public std::vector<T>,
    public ISortable {
public:
    virtual void sort() override;
};

#include "InsertionSortVector.tcc"

#endif // EE205_INSERTION_SORT_VECTOR_HPP
