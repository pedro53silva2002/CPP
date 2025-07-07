#include "AMateria.hpp"

AMateria::AMateria(std:: string const &type) : _type(type)
{
	//std::cout << "AMateria contructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria descontructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

/* AMateria* AMateria::clone() const
{
	std::cerr << "Error: clone() should be implemented in a derived class." << std::endl;
	return nullptr;
} */

void AMateria::use(ICharacter& target)
{
	(void)target;
	//std::cout << "Using AMateria " << _type << " on " << target.getName() << std::endl;
	//std::cout << "This not supposed to happear if you calling from a type." << std::endl;
}