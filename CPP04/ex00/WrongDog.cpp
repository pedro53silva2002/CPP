#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("dog")
{
	std::cout << "Dog " << this->_type << " has been created!" << std::endl;
}


WrongDog::WrongDog(std::string name) : WrongAnimal(name)
{
	std::cout << "Dog " << this->_type << " has been created!" << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other._type)
{
	std::cout << "Dog " << this->_type << " has been copied!" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Dog " << this->_type << " has been assigned!" << std::endl;
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << "Dog descontructor called" << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << "Woof woof bitch!" << std::endl;
}