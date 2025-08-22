#include "Array.hpp"
template <typename T>
Array<T>::Array() {
    _size = 0;
    _data = new T[_size];
}

template <typename T>
Array<T>::Array(int size) {
    _size = size;
    _data = new T[_size];
}

template <typename T>
Array<T>::Array(const Array<T>& other) {
    _size = other._size;
    _data = new T[_size];
    for (size_t i = 0; i < _size; ++i)
        _data[i] = other._data[i]; // deep copy
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this == &other)  // Step 1: self-assignment check
        return *this;

     if (_data) {
        delete[] _data; // Step 5: free memory
    } // Step 2: free existing memory

    _size = other._size;
    _data = new T[_size]; // Step 2: allocate new memory
    for (size_t i = 0; i < _size; ++i)
        _data[i] = other._data[i]; // deep copy

    return *this; // Step 4
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of rangeee");
    }
    return _data[index]; // Step 3: return reference to element
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of rangeee");
    }
    return _data[index]; // Step 3: return reference to element
}

template <typename T>
Array<T>::~Array() {
    std::cout << "Destructor called" << std::endl;
    if (_data) {
        delete[] _data; // Step 5: free memory
    }
}

template <typename T>
size_t Array<T>::size() const {
    return _size; // Return the size of the array
}