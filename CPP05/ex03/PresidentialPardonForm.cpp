#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5){
	_target = "Default";
	//td::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other)
{
	_target = other._target;
	//std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
		_target = src._target;
	//std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "PresidentialPardonForm descontructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
	//std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form)
{
	os << form.getName() << ", exec grade required " << form.execGrade() << ", sign grade required " << form.signedGrade() << " and is signed? " << (form.isSigned() ? "Yes" : "No");
	return os;
}

bool PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() < execGrade() && isSigned())
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		return true;
	}
	if (executor.getGrade() > execGrade())
	{
		throw GradeTooLowException();
	}
	else if (!isSigned())
	{
		throw NotSigned();
	}
	return false;
}

AForm *PresidentialPardonForm::createPresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}