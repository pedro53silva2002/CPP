#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	//std::cout << "ICharacter contructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter& other)
{
	*this = other;
}

ICharacter &ICharacter::operator=(const ICharacter &src)
{
	(void)src;
	/* if (this != &src)
	{
		this->_type = src._type;
	} */
	return *this;
}

ICharacter::~ICharacter()
{
	//std::cout << "ICharacter descontructor called" << std::endl;
}

/* void ICharacter::equip(AMateria* m)
{
	//std::cout << "Cure descontructor called" << std::endl;
}
void ICharacter::unequip(int idx)
{
	// std::cout << "Unequiping a materia" << std::endl;
}
void ICharacter::use(int idx, ICharacter& target)
{
	// std::cout << "Using a materia" << std::endl;
}

std::string const & getName()
{
	std::cout << "Nothing to see here" << std::endl;
	//return this->_type;
} */