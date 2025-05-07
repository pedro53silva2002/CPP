#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <csignal>

int main(void){
    Zombie *zombie = newZombie("Zombie heap");
    zombie->announce();
    randomChump("Zombie stack");
    delete zombie;
    return 0;
}