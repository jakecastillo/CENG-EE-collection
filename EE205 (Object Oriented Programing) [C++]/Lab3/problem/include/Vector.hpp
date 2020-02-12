#ifndef EE205_VECTOR_HPP
#define EE205_VECTOR_HPP

#include <cstddef>          // for std::size_t

class Vector {
    private:
        int* arr;
        std::size_t length;
        std::size_t capacity;

        // Use this method to double the capacity of
        // the current vector
        void double_capacity();

    public:
        Vector();

        // Should perform a deep copy and allocate new
        // memory and copy the contents of the other
        // Vector over to this one.
        Vector(const Vector& other); 

        // Should "steal" the contents of the other vector,
        // and set the memory and length in the other vector
        // to nullptr or zero  accordingly
        Vector(Vector&& other);

        // Should deallocate the memory.
        ~Vector();

        // For all of the following functions,
        // throw a const char* (string) if the index is out of
        // the bounds of the list.

        // Appends a number to the end of the vector.
        // 
        // Throw a const char* if the index is out of bounds
        void append(int num);

        // Inserts a new number before the index (e.g. 0 
        // means at the front, this->length means at the back)
        // 
        // Throw a const char* if the index is out of bounds,
        // but appending at the end will still work (e.g.
        // vector.insert(vector.size(), 0) will work
        void insert(int index, int num);

        // Removes a number at the index 
        // 
        // Throw a const char* if the index is out of bounds
        void remove(int index);

        // Gets a number at the index
        // 
        // Throw a const char* if the index is out of bounds
        int get(int index) const;

        // Returns the length of the vector
        std::size_t size() const;

        // Returns a readable/writable referece to an element
        // 
        // Throw a const char* if the index is out of bounds
        int& operator[](int index);
};

#endif // EE205_VECTOR_HPP
