#include "Dog.hpp"

Dog::Dog() : AAnimal("dog")
{
	std::cout << "Dog " << this->_type << " has been created!" << std::endl;
	_brain = new Brain();
}


Dog::Dog(std::string name) : AAnimal(name)
{
	std::cout << "Dog " << this->_type << " has been created!" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other._type)
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
	delete _brain;
	std::cout << "Dog descontructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof bitch!" << std::endl;
}