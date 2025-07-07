#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "Dog " << this->_type << " has been created!" << std::endl;
}


Dog::Dog(std::string name) : Animal(name)
{
	std::cout << "Dog " << this->_type << " has been created!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other._type)
{
	std::cout << "Dog " << this->_type << " has been copied!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Dog " << this->_type << " has been assigned!" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog descontructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof bitch!" << std::endl;
}