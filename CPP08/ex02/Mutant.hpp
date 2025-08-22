#ifndef MUTANT_HPP
#define MUTANT_HPP

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
#include <stack>
#include <list>
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

template <typename T> class MutantStack: public std::stack<int> {
	private:
		std::vector<int> _data;
		// int _size;
		// int _space;

	public:
		void push(int value) {
			this->std::stack<int>::push(value);
			_data.insert(_data.begin(), value);
		}

		void pop() {
			if (this->std::stack<int>::empty()) {
				throw std::length_error("Stack is empty");
			}
			this->std::stack<int>::pop();
			_data.erase(_data.begin());
		}
		/* MutantStack() : _size(0), _space(0) {}
		MutantStack(int size) : _size(0), _space(size) {
			_data.reserve(size);
		}
		MutantStack(const MutantStack &other) : _size(other._size), _space(other._space), _data(other._data) {}
		~MutantStack() {}

		void push(int value) {
			if (_size >= _space) {
				throw std::length_error("Stack is full");
			}
			_data.push_back(value);
			_size++;
		}

		void pop() {
			if (_size == 0) {
				throw std::length_error("Stack is empty");
			}
			_data.pop_back();
			_size--;
		}

		int top() const {
			if (_size == 0) {
				throw std::length_error("Stack is empty");
			}
			return _data.back();
		}

		int size() const {
			return _size;
		} */

		typedef typename std::vector<int>::iterator iterator;
		
		iterator begin() {
			return _data.begin();
		}

		iterator end() {
			return 	_data.end();
		}

};


#endif