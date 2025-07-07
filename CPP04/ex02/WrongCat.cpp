#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("cat")
{
	std::cout << "WrongCat " << this->_type << " has been created!" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat " << this->_type << " has been created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other._type)
{
	std::cout << "WrongCat " << this->_type << " has been copied!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Cat " << this->_type << " has been assigned!" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Cat descontructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow meow motherfucker!" << std::endl;
}