#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "Cat " << this->_type << " has been created!" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat " << this->_type << " has been created!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other._type)
{
	std::cout << "Cat " << this->_type << " has been copied!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Cat " << this->_type << " has been assigned!" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat descontructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow motherfucker!" << std::endl;
}