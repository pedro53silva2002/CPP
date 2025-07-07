#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class Animal
{
	protected:
		std::string	_type;	//Type of Animal

	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
};

#endif