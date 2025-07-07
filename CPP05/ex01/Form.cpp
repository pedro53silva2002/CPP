#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150){
	//std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form& other): _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	//std::cout << "Form copy constructor called" << std::endl;
}
Form &Form::operator=(const Form &src)
{
	//std::cout << "Form assignation operator called" << std::endl;
	if (this != &src)
	{
		_isSigned = src._isSigned;
	}
	return *this;
}

Form::~Form()
{
	//std::cout << "Form descontructor called" << std::endl;
}

Form::Form(std::string name, int signgrade, int execgrade) : _name(name), _isSigned(false), _signGrade(signgrade), _execGrade(execgrade)
{
	//std::cout << "Form constructor called" << std::endl;
	setGrade(signgrade);
	setGrade(execgrade);
}

std::string Form::getName() const
{
	return _name;
}

int Form::signedGrade() const
{
	return _signGrade;
}

int Form::execGrade() const
{
	return _execGrade;
}

bool Form::isSigned() const
{
	return _isSigned;
}

int Form::setGrade(int grade)
{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	return grade;
}

bool Form::beSigned(Bureaucrat const &src)
{
	if (_isSigned)
	{
		return _isSigned;
	}
	if (src.getGrade() > _signGrade)
	{
		throw GradeTooLowException();
	}
	_isSigned = true;
	return _isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", exec grade required " << form.execGrade() << ", sign grade required " << form.signedGrade() << " and is signed? " << (form.isSigned() ? "Yes" : "No");
	return os;
}