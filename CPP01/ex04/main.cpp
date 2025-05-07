#include "Replace.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <csignal>

// This program demonstrates the use of pointers and references in C++.
// It creates a string variable, a pointer to that string, and a reference to the string.
// It then prints the addresses of the string, pointer, and reference, as well as their values.
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: Wrong number of arguments." << std::endl;
        return 1;
    }
    std::string file_name = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    File file(file_name);
    /* std::cout << "file_name: " << file_name << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl; */
    file.replace(s1, s2);
    std::cout << "File replaced successfully." << std::endl;
    return 0;
}