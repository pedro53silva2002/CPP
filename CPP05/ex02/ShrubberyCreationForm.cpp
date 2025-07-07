#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137) {
	_target = "Default";
	//std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
	_target = other._target;
	//std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		_target = src._target;
	//std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "ShrubberyCreationForm descontructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :  AForm("ShrubberyCreationForm", 25, 5)
{
	_target = target;
	//std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form)
{
	os << form.getName() << ", exec grade required " << form.execGrade() << ", sign grade required " << form.signedGrade() << " and is signed? " << (form.isSigned() ? "Yes" : "No");
	return os;
}

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() < execGrade() && isSigned())
	{
		std::ofstream Myfile;
		Myfile.open((_target + "_shrubbery.txt").c_str());
		if (!Myfile.is_open())
		{
			std::cerr << "Error opening file for writing." << std::endl;
			return false;
		}
		Myfile << "       _-_\n";
		Myfile << "    /~~   ~~\\\n";
		Myfile << " /~~         ~~\\\n";
		Myfile << "{               }\n";
		Myfile << " \\  _-     -_  /\n";
		Myfile << "    ~  \\ /  ~\n";
		Myfile << "_- -   | | _- _\n";
		Myfile << "  _ -  | |   -_\n";
		Myfile << "       / \\ \n";
		Myfile.close();
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