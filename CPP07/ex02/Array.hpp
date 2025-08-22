#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <exception>

template <typename T> class Array {
    private:
        size_t _size;
        T* _data;
    public:
        Array();
        Array(int size);
        Array(const Array& other);
        Array& operator=(const Array& other);
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        ~Array();
        size_t size() const;
};

#include "Array.tpp"  // Include the implementation
#endif // ARRAY_HPP