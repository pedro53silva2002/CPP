#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		WrongDog(std::string name);
		WrongDog(const WrongDog& other);
		WrongDog& operator=(const WrongDog& other);
		virtual ~WrongDog();
		virtual void makeSound() const;
};

#endif