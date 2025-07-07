#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "Some animal";
	std::cout << "Animal contructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std:: string type) : _type(type)
{
	std::cout << "Animal contructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Animal descontructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "U don't have any animal type" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}