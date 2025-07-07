#ifndef ICE_HPP
#define ICE_HPP

#pragma once
#include "AMateria.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const & src);
		Ice & operator=(Ice const & src);
		virtual ~Ice();
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif