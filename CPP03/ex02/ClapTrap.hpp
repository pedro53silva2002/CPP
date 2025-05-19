#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class ClapTrap
{
	protected:
		std::string	_name;	//Name of the claptrap
		int			_hp;	//Hit points (health)
		int			_ad;	//Attack Damage
		int			_ep;	//Energy Points

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		virtual ~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif