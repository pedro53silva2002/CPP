#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name")
{
	this->_name = name;
	this->_hp = 100;
	this->_ad = 30;
	this->_ep = 50;
	std::cout << "DiamondTrap " << this->_name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other._name + "_clap_name") , ScavTrap(other._name + "_scav_name"), FragTrap(other._name + "_frag_name")
{
	this->_name = other._name;
	this->_hp = FragTrap::_hp;
	this->_ad = FragTrap::_ad;
	this->_ep = ScavTrap::_ep;
	std::cout << "DiamondTrap " << this->_name << " has been copied!" << std::endl;
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = FragTrap::_hp;
		this->_ad = FragTrap::_ad;
		this->_ep = ScavTrap::_ep;
	}
	std::cout << "DiamondTrap " << this->_name << " has been assigned!" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap descontructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << this->_name << " is also called " << ClapTrap::_name << std::endl;
}