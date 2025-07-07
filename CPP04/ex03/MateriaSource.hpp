#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria* _materia[4];
		int _idx;

	public:
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		MateriaSource & operator=(MateriaSource const & src);
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria* m); //Learns a materia
		virtual AMateria* createMateria(std::string const & type); //Creates a materia
};


#endif