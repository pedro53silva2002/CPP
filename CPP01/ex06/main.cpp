#include "Harl.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <csignal>

// This program demonstrates the use of pointers and references in C++.
// It creates a string variable, a pointer to that string, and a reference to the string.
// It then prints the addresses of the string, pointer, and reference, as well as their values.
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: Wrong number of arguments." << std::endl;
        return 1;
    }
    Harl harl;
    /* std::cout << "\t\t\tAutomatic tests" << std::endl;
    std::cout << "Debug" << std::endl;
    harl.complain("debug");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Warning" << std::endl;
    harl.complain("warning");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Info" << std::endl;
    harl.complain("info");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Error" << std::endl;
    harl.complain("error");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "User test: " << argv[1] << std::endl; */
    harl.complain(argv[1]);
    return 0;
}