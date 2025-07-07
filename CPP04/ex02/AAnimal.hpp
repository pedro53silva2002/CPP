#ifndef AANIMAL_HPP
#define AANIMAL_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class AAnimal
{
	protected:
		std::string	_type;	//Type of Animal

	public:
		AAnimal();
		AAnimal(std::string name);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();
		virtual void makeSound() const = 0; // Pure virtual function
		std::string getType() const;
};

#endif