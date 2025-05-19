#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std:: string name) : _name(name), _hp(10), _ad(1), _ep(10)
{
	std::cout << "ClapTrap contructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_ad = src._ad;
		this->_ep = src._ep;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap descontructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_ep <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't make the stand appear!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " , causing " << this->_ad << " points of damage!" << std::endl;
	this->_ep -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage! ";
	this->_hp -= amount;
	std::cout << this->_name << " life left: " << this->_hp << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_ep <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't heal!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " has healed " << amount << " points of health!";
	this->_hp += amount;
	std::cout << this->_name << " life left: " << this->_hp << std::endl;
	this->_ep -= 1;
}