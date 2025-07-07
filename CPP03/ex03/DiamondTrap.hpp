#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class DiamondTrap : public ScavTrap, public FragTrap
{
	protected:
		std::string	_name;	//Name of the diamondtrap
		int			_hp;	//Hit points (health)
		int			_ad;	//Attack Damage
		int			_ep;	//Energy Points

	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap();
		void attack(const std::string& target);
		void whoAmI();
};

#endif