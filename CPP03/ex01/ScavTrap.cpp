#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ad = 20;
	_ep = 50;
	std::cout << "ScavTrap " << this->_name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other._name)
{
	_hp = other._hp;
	_ad = other._ad;
	_ep = other._ep;
	std::cout << "ScavTrap " << this->_name << " has been copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ad = other._ad;
		this->_ep = other._ep;
	}
	std::cout << "ScavTrap " << this->_name << " has been assigned!" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap descontructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_ep <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't make the stand appear!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " , causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep -= 1;
}

void ScavTrap::guardGate()
{
	if (this->_ep <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't enter Gate Keeper mode!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " entered Gate Keeper mode!" << std::endl;
}