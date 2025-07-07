#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45) {
	_target = "Default";
	//std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other)
{
	_target = other._target;
	//std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		_target = src._target;
	//std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "RobotomyRequestForm descontructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :  AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
	//std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form)
{
	os << form.getName() << ", exec grade required " << form.execGrade() << ", sign grade required " << form.signedGrade() << " and is signed? " << (form.isSigned() ? "Yes" : "No");
	return os;
}

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() < execGrade() && isSigned())
	{
		std::srand(std::time(0));

		// Generate a random number between 0 and RAND_MAX
		int random_number = std::rand();
		if (random_number % 2 == 0) {
			std::cout << _target << " has robotomized successfully!" << std::endl;
		} else {
			std::cout << _target << " failed to robotomize." << std::endl;
		}
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


AForm *RobotomyRequestForm::createRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}