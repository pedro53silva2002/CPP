#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
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
//#include <array>
#include <exception>

// Function template definition
template <typename T> void easyfind(T &array,int y) {
    if (std::find(array.begin(), array.end(), y) != array.end()) {
        std::cout << "Found: " << y << std::endl;
        return;
    }
    else {
        throw std::runtime_error("Value not found in the container");
    }
}

#endif