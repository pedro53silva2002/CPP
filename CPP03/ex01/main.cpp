#include "ScavTrap.hpp"

int main( void ) {
    ScavTrap scav("Scavvy");
    ScavTrap scav2(scav);
    ScavTrap scav3 = scav2;
    scav.attack("target1");
    scav2.attack("target2");
    scav3.attack("target3");
    scav.takeDamage(5);
    scav.beRepaired(3);
    scav.guardGate();
    scav2.guardGate();
    scav3.guardGate();
    scav.takeDamage(10);
    scav.beRepaired(5);
    return 0;
}