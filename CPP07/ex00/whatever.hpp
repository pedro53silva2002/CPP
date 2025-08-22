#ifndef WHATEVER_HPP
#define WHATEVER_HPP

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
template <typename T> T max(T x, T y) {
    return (x > y) ? x : y;
}

template <typename T> T min(T x, T y) {
    return (x < y) ? x : y;
}

template <typename T> void swap(T &x, T &y) {
    T temp;
	temp = x;
	x = y;
	y = temp;
}

#endif