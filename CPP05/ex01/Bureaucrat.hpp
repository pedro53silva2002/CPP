#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#pragma once
#include "Form.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade; // Grade of the bureaucrat, must be between 1 and 150

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat & operator=(Bureaucrat const & src);
		~Bureaucrat();
		std::string getName() const; // Returns the name of the bureaucrat
		int getGrade() const; // Returns the grade of the bureaucrat
		void incrementGrade(); // Increments the grade of the bureaucrat
		void decrementGrade(); // Decrements the grade of the bureaucrat
		int setGrade(int grade); // Sets the grade of the bureaucrat, throws exceptions if the grade is invalid
		void signForm(Form &form) const; // Simulates signing a form by the bureaucrat

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


#endif