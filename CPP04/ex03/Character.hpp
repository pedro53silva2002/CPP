#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class Character : public ICharacter
{
	protected:
		std::string _name;
		AMateria* _materia[4];
		/* int _idx;
		Character();
		Character(Character const & src);
		Character & operator=(Character const & src); */

	public:
		Character();
		Character(std::string const & name);
		Character(Character const & src);
		Character & operator=(Character const & src);
		virtual ~Character();
		virtual std::string const & getName() const; //Returns the materia type
		void equip(AMateria* m); //Equips a materia
		void unequip(int idx); //Unequips a materia
		void use(int idx, ICharacter& target); //ICharacterUses a materia
		void setName(std::string name);
		bool inInventory(AMateria* m);

};

#endif