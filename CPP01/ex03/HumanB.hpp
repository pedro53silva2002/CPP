#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

class HumanB
{
private:
	std::string name;
	Weapon *weapon;

public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &weapon);
};


#endif