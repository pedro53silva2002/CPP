#include "Span.hpp"

Span::Span() {
	_size = 0;
	_space = 0;
    _data.reserve(0); // Initialize with zero size
	//_type = "string";
	//std::cout << "ScalarConverter default constructor called" << std::endl;
}

Span::Span(int n) {
	//std::cout << "Span constructor called with size: " << n << std::endl;
	_size = n;
	_space = n; // Initialize space to the same value as size
	//std::cout << "Span constructor called with size: " << _size << std::endl;
	if (n <= 0) {
		throw std::invalid_argument("Size must be greater than zero");
	}
	_data.reserve(_size); // Reserve space for n elements
}


Span::Span(const Span& other)
{
	//std::cout << "ScalarConverter copy assignation called" << std::endl;
	*this = other;
}

std::vector<int> Span::getData() const
{
	return _data;
}


Span &Span::operator=(const Span &src)
{
	//std::cout << "ScalarConverter assignation operator called" << std::endl;
	if (this != &src)
	{
		_size = src._size;
		_space = src._space;
		_data.reserve(_size); // Allocate new memory
		for (int i = 0; i < _size; ++i) {
			_data[i] = src._data[i]; // Deep copy
		}
	}
	return *this;
}


Span::~Span()
{
	//std::cout << "ScalarConverter descontructor called" << std::endl;
}

int Span::shortestSpan() const
{
	int shortestSpan;
	//std::cout << "SIZE: " << _size << std::endl;
	if (_size <= 1) {
		throw std::logic_error("Not enough elements to find the shortest span");
	}
	for (int i = 0; i < _size; i++)
	{
		int temp = _data[i] - _data[i + 1];
		if (temp < 0) {
			temp = -temp; // Ensure positive difference
		}
		if (!shortestSpan) {
			shortestSpan = temp;
		}
		else {
			if (shortestSpan > temp) {
				shortestSpan = temp;
			}
		}
	}
	
	return shortestSpan;
}


int Span::longestSpan() const
{
	int longestSpan;
	//std::cout << "SIZE: " << _size << std::endl;
	if (_size <= 1) {
		throw std::logic_error("Not enough elements to find the longest span");
	}
	for (int i = 0; i < _size; i++)
	{
		int temp = _data[i] - _data[i + 1];
		if (temp < 0) {
			temp = -temp; // Ensure positive difference
		}
		if (!longestSpan) {
			longestSpan = temp;
		}
		else {
			if (longestSpan < temp) {
				longestSpan = temp;
			}
		}
	}
	
	return longestSpan;
}

void Span::addNumber(int number) 
{
	if (_space <= 0) {
		throw std::length_error("Span is full");
	}
	_data.push_back(number);
	_space--;
}

void Span::addMultipleNumbers(int count) 
{
	std::srand(time(0)); // seed with current time
	this->_space = count;
	for (int i = 0; i < count; i++)
	{
		addNumber(std::rand() % 1000000 + 1); // Add random numbers between 1 and 99999
	}
}