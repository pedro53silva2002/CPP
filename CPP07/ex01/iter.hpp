#ifndef ITER_HPP
#define ITER_HPP

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

// Function template definition
template <typename T> void iter(T *x, int length, void (*f)(T &)) {
    if (x == NULL || f == NULL)
    {
        return ;
    }
    for (int i = 0; i < length; ++i) {
        f(x[i]);
    }
}

// Function template definition
template <typename T> void iter(const T *x, int length, void (*f)(T &)) {
    if (x == NULL || f == NULL)
    {
        return ;
    }
    for (int i = 0; i < length; ++i) {
        f(x[i]);
    }
}

// Function template definition
template <typename T> void iter(const T *x, int length, void (*f)(const T &)) {
    if (x == NULL || f == NULL)
    {
        return ;
    }
    for (int i = 0; i < length; ++i) {
        f(x[i]);
    }
}

// Function template definition
template <typename T> void iter(T *x, int length, void (*f)(const T &)) {
    if (x == NULL || f == NULL)
    {
        return ;
    }
    for (int i = 0; i < length; ++i) {
        f(x[i]);
    }
}

#endif