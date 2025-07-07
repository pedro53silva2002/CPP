#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

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
#include <cstdlib>
#include <ctime>  

class Bureaucrat; // Forward declaration of Bureaucrat class

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target; // Target of the form, must be a valid string

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
		~PresidentialPardonForm();
		bool execute(Bureaucrat const & executor) const;
		static AForm *createPresidentialPardonForm(std::string const &target);
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);


#endif