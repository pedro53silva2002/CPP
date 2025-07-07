#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat("John Doe", 1);
        std::cout << bureaucrat << std::endl;
        std::cout << std::endl;
        Bureaucrat bureaucrat2("Arthur Morgan", 4);
        std::cout << bureaucrat2 << std::endl;
        std::cout << std::endl;
        Bureaucrat bureaucrat3("John Marston", 150);
        std::cout << bureaucrat3 << std::endl << std::endl << std::endl;

        bureaucrat2.incrementGrade();
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl << std::endl << std::endl;

        Intern intern;
        try {
            AForm *dummyform = intern.makeForm("dummyform", "Form1");
            std::cout << dummyform  << std::endl << std::endl;
            //delete dummyform; // Clean up if the form was created
        } catch (const Intern::FormNotFound &e) {
            std::cerr << "Exception: " << e.what() << std::endl << std::endl;
        }
        AForm *form = intern.makeForm("PresidentialPardonForm", "Form1");
        std::cout << *form << std::endl;
        bureaucrat2.signForm(*form);
        std::cout << *form << std::endl;
        bureaucrat2.executeForm(*form);
        std::cout << std::endl << std::endl;
        AForm *form2 = intern.makeForm("ShrubberyCreationForm", "Form2");
        std::cout << *form2 << std::endl;
        bureaucrat3.signForm(*form2);
        std::cout << *form2 << std::endl;
        bureaucrat3.executeForm(*form2);
        std::cout << std::endl << std::endl;
        delete form;
        delete form2;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}