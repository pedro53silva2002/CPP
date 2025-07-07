#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("John Doe", 1);
        std::cout << bureaucrat << std::endl;
        std::cout << std::endl;
        Bureaucrat bureaucrat2("Arthur Morgan", 100);
        std::cout << bureaucrat2 << std::endl;
        std::cout << std::endl;
        Bureaucrat bureaucrat3("John Marston", 150);
        std::cout << bureaucrat3 << std::endl << std::endl << std::endl;

        bureaucrat2.incrementGrade();
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl << std::endl << std::endl;

        RobotomyRequestForm form("Dave");
        std::cout << form << std::endl;
        bureaucrat.signForm(form);
        std::cout << form << std::endl << std::endl;
        PresidentialPardonForm form2("Washington Bush");
        std::cout << form2 << std::endl;
        bureaucrat2.signForm(form2);
        std::cout << form2 << std::endl << std::endl;
        ShrubberyCreationForm form3("Greenhouse");
        std::cout << form3 << std::endl;
        bureaucrat3.signForm(form3);
        std::cout << form3 << std::endl << std::endl << std::endl;

        bureaucrat.executeForm(form);
        bureaucrat2.executeForm(form2);
        bureaucrat3.executeForm(form3);
        std::cout << std::endl << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}