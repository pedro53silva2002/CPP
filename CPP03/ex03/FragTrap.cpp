#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ad = 30;
	_ep = 100;
	std::cout << "FragTrap " << this->_name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other._name)
{
	_hp = other._hp;
	_ad = other._ad;
	_ep = other._ep;
	std::cout << "FragTrap " << this->_name << " has been copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ad = other._ad;
		this->_ep = other._ep;
	}
	std::cout << "FragTrap " << this->_name << " has been assigned!" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap descontructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_ep <= 0)
	{
		std::cout << "FragTrap " << this->_name << " can't make the stand appear!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << " , causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep -= 1;
}

void FragTrap::highFivesGuys()
{
	if (this->_ep <= 0)
	{
		std::cout << "FragTrap " << this->_name << " can't high five!" << std::endl;
		return;
	}
	this->_ep -= 1;
	std::cout << "FragTrap " << this->_name << " high fives guys!" << std::endl;
}