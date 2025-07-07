#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat("John Doe", 1);
        std::cout << bureaucrat << std::endl;
        std::cout << std::endl;
        Bureaucrat bureaucrat2("Arthur Morgan", 100);
        std::cout << bureaucrat2 << std::endl;
        std::cout << std::endl;
        Bureaucrat bureaucrat3("John Marston", 150);
        std::cout << bureaucrat3 << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        bureaucrat2.incrementGrade();
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        Form form("Form 1", 100, 100);
        std::cout << form << std::endl;
        bureaucrat2.signForm(form);
        std::cout << form << std::endl  << std::endl;
        Form form2("Form 2", 100, 100);
        std::cout << form2 << std::endl;
        bureaucrat3.signForm(form2);
        std::cout << std::endl << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}