#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern() {
	//std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	//std::cout << "Intern assignation operator called" << std::endl;
	return *this;
}
Intern::~Intern()
{
	//std::cout << "Intern descontructor called" << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string target) const
{
	AForm *(*form[3])(std::string const &target) = {
        &ShrubberyCreationForm::createShrubberyCreationForm,
        &RobotomyRequestForm::createRobotomyRequestForm,
        &PresidentialPardonForm::createPresidentialPardonForm
    };

    std::string formNames[] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm"
    };

    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (form[i](target));
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
	throw FormNotFound();
	//return NULL;
}

const char *Intern::FormNotFound::what() const throw()
{
	return "Form not exists";
}