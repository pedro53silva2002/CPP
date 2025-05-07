#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
	//std::cout << "Constructor called for HumanB" << std::endl;
}

HumanB::~HumanB()
{
	//std::cout << "Destructor called for HumanB" << std::endl;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
