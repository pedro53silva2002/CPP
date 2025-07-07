#ifndef FORM_HPP
#define FORM_HPP

#pragma once
//#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class Bureaucrat; // Forward declaration of Bureaucrat class

class Form
{
	private:
		const std::string _name;
		bool _isSigned; // Indicates if the form is signed or not
		const int _signGrade; // Grade of the bureaucrat, must be between 1 and 150
		const int _execGrade; // Grade of the bureaucrat, must be between 1 and 150

	public:
		Form();
		Form(std::string name, int signgrade, int execgrade);
		Form(Form const & src);
		Form & operator=(Form const & src);
		~Form();
		std::string getName() const; // Returns the name of the bureaucrat
		int signedGrade() const;
		int execGrade() const;
		bool isSigned() const; // Returns if the form is signed or not
		void incrementGrade(); // Increments the grade of the bureaucrat
		void decrementGrade(); // Decrements the grade of the bureaucrat
		int setGrade(int grade); // Sets the grade of the bureaucrat, throws exceptions if the grade is invalid
		bool beSigned(Bureaucrat const &src); // Marks the form as signed
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

std::ostream &operator<<(std::ostream &os, const Form &form);


#endif