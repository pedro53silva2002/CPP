#ifndef CURE_HPP
#define CURE_HPP

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

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const & src);
		Cure & operator=(Cure const & src);
		virtual ~Cure();
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif