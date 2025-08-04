#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

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
#include <stdint.h>

struct Data
{
	std::string string;
	int value;
};


class Serializer
{
	private:
		Serializer(); // Private constructor to prevent instantiation

	public:
		Serializer(Serializer const & src);
		Serializer & operator=(Serializer const & src);
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif