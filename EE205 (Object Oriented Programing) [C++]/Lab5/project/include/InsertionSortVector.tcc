template <typename T>
void InsertionSortVector<T>::sort() {
    int i = 1;
    while (i < this->size()) {
        int j = i;
        while (j > 0 && (*this)[j-1] > (*this)[j]) {
            T temp = (*this)[j];
            (*this)[j] = (*this)[j-1];
            (*this)[j-1] = temp;    
            j = j-1;
        }
        i = i+1;
    }
}
