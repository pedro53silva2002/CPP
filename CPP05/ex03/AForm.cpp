#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150){
	//std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	if (other._signGrade < 1 || other._execGrade < 1)
		throw GradeTooHighException();
	else if (other._signGrade > 150 || other._execGrade > 150)
		throw GradeTooLowException();
	//std::cout << "Form copy constructor called" << std::endl;
}
AForm &AForm::operator=(const AForm &src)
{
	//std::cout << "Form assignation operator called" << std::endl;
	if (this != &src)
	{
		_isSigned = src._isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	//std::cout << "Form descontructor called" << std::endl;
}

AForm::AForm(std::string name, int signgrade, int execgrade) : _name(name), _isSigned(false), _signGrade(signgrade), _execGrade(execgrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	//std::cout << "Form constructor called" << std::endl;
}

std::string AForm::getName() const
{
	return _name;
}

int AForm::signedGrade() const
{
	return _signGrade;
}

int AForm::execGrade() const
{
	return _execGrade;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

int AForm::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return grade;
}

bool AForm::beSigned(Bureaucrat const &src)
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

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << form.getName() << ", exec grade required " << form.execGrade() << ", sign grade required " << form.signedGrade() << " and is signed? " << (form.isSigned() ? "Yes" : "No");
	return os;
}

bool AForm::execute(Bureaucrat const &executor) const
{
	(void) executor;
	//std::cout << executor.getName() << "IS HEREEEEEEE" << _name << std::endl;
	return true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::NotSigned::what() const throw()
{
	return "Not signed yet";
}