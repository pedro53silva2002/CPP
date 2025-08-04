#include "ScalarConverter.hpp"

int main()
{
    ScalarConverter::convert("42");
    std::cout << std::endl << "------------------------" << std::endl << std::endl;
    ScalarConverter::convert("4");
    std::cout << std::endl << "------------------------" << std::endl << std::endl;
    ScalarConverter::convert("65.4f");
    std::cout << std::endl << "------------------------" << std::endl << std::endl;
    ScalarConverter::convert("54.7");
    std::cout << std::endl << "------------------------" << std::endl << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl << "------------------------" << std::endl << std::endl;
    ScalarConverter::convert("inf");
    std::cout << std::endl << "------------------------" << std::endl << std::endl;
    ScalarConverter::convert("+inff");
    std::cout << std::endl << "------------------------" << std::endl << std::endl;
    ScalarConverter::convert("a");
    std::cout << std::endl << "------------------------" << std::endl << std::endl;
    ScalarConverter::convert("42a");
    return 0;
}