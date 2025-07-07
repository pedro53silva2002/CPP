#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	//std::cout << "Cure contructor called" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src)
{
	//std::cout << "Cure contructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

Cure::~Cure()
{
	//std::cout << "Cure descontructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}