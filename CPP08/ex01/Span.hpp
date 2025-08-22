#ifndef SPAN_HPP
#define SPAN_HPP

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
//#include <array>
#include <exception>

/* // Function template definition
template <typename T> void easyfind(T &array,int y) {
    if (std::find(array.begin(), array.end(), y) != array.end()) {
        std::cout << "Found: " << y << std::endl;
        return;
    }
    else {
        throw std::runtime_error("Value not found in the container");
    }
} */

class Span {
	private:
		int _size;
		int _space;
		std::vector<int> _data;

	public:
        Span();
		Span(int n);
		Span(Span const & src);
		Span & operator=(Span const & src);
		~Span();
		std::vector<int> getData() const;
		int shortestSpan() const;
		int longestSpan() const;
		void addNumber(int number);
		void addMultipleNumbers(int count);
};


#endif