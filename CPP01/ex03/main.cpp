#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <csignal>

// This program demonstrates the use of pointers and references in C++.
// It creates a string variable, a pointer to that string, and a reference to the string.
// It then prints the addresses of the string, pointer, and reference, as well as their values.
int main(void){
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}