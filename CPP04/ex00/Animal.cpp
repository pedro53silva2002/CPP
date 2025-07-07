#include "Animal.hpp"

Animal::Animal()
{
	_type = "Some animal";
	std::cout << "Animal contructor called" << std::endl;
}

Animal::Animal(std:: string type) : _type(type)
{
	std::cout << "Animal contructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
}

Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal descontructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "U don't have any animal type" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}