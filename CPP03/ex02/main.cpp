#include "FragTrap.hpp"

int main( void ) {
    FragTrap frag("Frag");
    FragTrap frag2("Frag2");
    FragTrap frag3(frag);
    FragTrap frag4 = frag2;
    std::cout << std::endl;
    std::cout << std::endl;
    frag.attack("target");
    frag2.attack("target");
    frag3.attack("target");
    frag4.attack("target");
    std::cout << std::endl;
    frag.highFivesGuys();
    frag2.highFivesGuys();
    frag3.highFivesGuys();
    frag4.highFivesGuys();
    std::cout << std::endl;
    frag.takeDamage(10);
    frag2.takeDamage(20);
    frag3.takeDamage(30);
    frag4.takeDamage(40);
    std::cout << std::endl;
    frag.beRepaired(10);
    frag2.beRepaired(20);
    frag3.beRepaired(30);
    frag4.beRepaired(40);
    std::cout << std::endl;
    frag.attack("target");
    frag2.attack("target");
    frag3.attack("target");
    frag4.attack("target");
    frag.highFivesGuys();
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}