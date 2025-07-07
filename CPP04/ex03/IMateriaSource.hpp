#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

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

class IMateriaSource
{
	protected:
		AMateria* _materia[4];
		int _idx;
		IMateriaSource();
		IMateriaSource(IMateriaSource const & src);
		IMateriaSource & operator=(IMateriaSource const & src);

	public:
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria* m) = 0; //Learns a materia
		virtual AMateria* createMateria(std::string const & type) = 0; //Creates a materia
};

#endif