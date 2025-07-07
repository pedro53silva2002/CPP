#ifndef BRAIN_HPP
#define BRAIN_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class Brain
{
	protected:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(std::string _ideas[100]);
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		virtual ~Brain();
};

#endif