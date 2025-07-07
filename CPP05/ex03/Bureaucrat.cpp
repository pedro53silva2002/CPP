#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	//std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	//std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &src)
	{
		_grade = src._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat descontructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	//std::cout << "Bureaucrat constructor called" << std::endl;
	setGrade(grade);
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

int Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	return _grade;
}

void Bureaucrat::incrementGrade()
{
		if (_grade <= 1)
			throw GradeTooHighException();
		_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw std::out_of_range("Grade too low");
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

void Bureaucrat::signForm(AForm &form) const
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
		std::cout << _name << " couldn't sign " << form.getName() << " because " << _grade << " > " << form.signedGrade() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
	try {
		form.execute(*this);
		std::cerr << _name << " execute " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
}