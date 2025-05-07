#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	//std::cout << "Constructor called for Weapon" << std::endl;
}
Weapon::~Weapon()
{
	//std::cout << "Destructor called for Weapon" << std::endl;
}
std::string Weapon::getType(void)
{
	return this->type;
}
void Weapon::setType(std::string type)
{
	this->type = type;
}