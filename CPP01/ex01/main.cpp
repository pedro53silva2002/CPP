#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <csignal>

int main(void){
    int N = 3;
    Zombie *zombie = zombieHorde(N, "Harry");
    for (int i = 0; i < N; i++)
        zombie[i].announce();
    delete[] zombie;
    return 0;
}