#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	//std::cout << "Cure contructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	//std::cout << "Cure contructor called" << std::endl;
}


Ice &Ice::operator=(const Ice &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

Ice::~Ice()
{
	//std::cout << "Cure descontructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}