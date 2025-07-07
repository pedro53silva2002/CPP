#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	_type = "Some animal";
	std::cout << "Animal contructor called" << std::endl;
}

AAnimal::AAnimal(std:: string type) : _type(type)
{
	std::cout << "Animal contructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal descontructor called" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "U don't have any animal type" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->_type;
}