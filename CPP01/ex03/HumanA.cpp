#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	/* this->name = name;
	this->weapon = weapon; */
	//std::cout << "Constructor called for HumanA" << std::endl;
}

HumanA::~HumanA()
{
	//std::cout << "Destructor called for HumanA" << std::endl;
}

void HumanA::attack()
{	
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}