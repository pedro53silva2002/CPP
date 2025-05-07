#include <iostream>
#include <string>
#include <iomanip>
#include <csignal>

// This program demonstrates the use of pointers and references in C++.
// It creates a string variable, a pointer to that string, and a reference to the string.
// It then prints the addresses of the string, pointer, and reference, as well as their values.
int main(void){
    std::string string = "HI THIS IS BRAIN";
    std::string *ptr = &string;
    std::string &ref = string;

    std::cout << "Address of string:\t" << &string << std::endl;
    std::cout << "Address of ptr:\t\t" << &ptr << std::endl;
    std::cout << "Address of ref:\t\t" << &ref << std::endl;
    std::cout << "String value:\t" << string << std::endl;
    std::cout << "Ptr value:\t" << *ptr << std::endl;
    std::cout << "Ref value:\t" << ref << std::endl;
    return 0;
}