#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class AMateria;

class ICharacter
{
	protected:
		ICharacter();
		ICharacter(ICharacter const & src);
		ICharacter & operator=(ICharacter const & src);

	public:
		virtual ~ICharacter();
		virtual std::string const & getName() const = 0; //Returns the materia type
		virtual void equip(AMateria* m) = 0; //Equips a materia
		virtual void unequip(int idx) = 0; //Unequips a materia
		virtual void use(int idx, ICharacter& target) = 0; //Uses a materia
};

#endif