#include "Character.hpp"

Character::Character() : _name("Some name"), _materia()
{
	/* for (int i = 0; i < 4; i++)
		this->_materia[i] = nullptr; */
	//std::cout << "Character contructor called" << std::endl;
}
Character::Character(std::string const &name) : _name(name), _materia()
{
	/* for (int i = 0; i < 4; i++)
		this->_materia[i] = nullptr; */
	//std::cout << "Character contructor called" << std::endl;
}
Character::Character(const Character& other)
{
	*this = other;
}
Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		/* for (int i = 0; i < 4; i++)
			this->_materia[i] = src._materia[i]; */
	}
	return *this;
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
	//std::cout << "Character descontructor called" << std::endl;
}
std::string const &Character::getName() const
{
	return this->_name;
}
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			//std::cout << "Equiping a materia" << std::endl;
			return;
		}
	}
	//std::cout << "No more space to equip a materia" << std::endl;
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		//std::cout << "Index out of range" << std::endl;
		return;
	}
	if (!this->_materia[idx])
	{
		//std::cout << "No materia to unequip" << std::endl;
		return;
	}
	//this->_materia[idx] = nullptr;
	//std::cout << "Unequiping a materia" << std::endl;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _materia[idx])
		_materia[idx]->use(target);
	/* else
		std::cout << "Can't find it" << std::endl; */
}

void Character::setName(std::string name)
{
	this->_name = name;
}
bool Character::inInventory(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == m)
			return true;
	}
	return false;
}
