#include "Cat.hpp"

Cat::Cat() : AAnimal("cat")
{
	std::cout << "Cat " << this->_type << " has been created!" << std::endl;
	_brain = new Brain();
}

Cat::Cat(std::string type) : AAnimal(type)
{
	std::cout << "Cat " << this->_type << " has been created!" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other._type)
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
	delete _brain;
	std::cout << "Cat descontructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow motherfucker!" << std::endl;
}