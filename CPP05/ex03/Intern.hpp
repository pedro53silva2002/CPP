#ifndef INTERN_HPP
#define INTERN_HPP

#pragma once
#include "AForm.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

//class Form; // Forward declaration of Form class

class Intern
{
	public:
		Intern();
		Intern(Intern const & src);
		Intern & operator=(Intern const & src);
		~Intern();
		AForm *makeForm(std::string formName, std::string target) const;

	class FormNotFound : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

//std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


#endif