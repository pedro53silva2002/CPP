#include "DiamondTrap.hpp"

int main( void ) {
    /* DiamondTrap frag("Frag");
    DiamondTrap frag2("Frag2");
    DiamondTrap frag3(frag);
    DiamondTrap frag4 = frag2;
    std::cout << std::endl;
    std::cout << std::endl;
    frag.attack("target");
    frag2.attack("target");
    frag3.attack("target");
    frag4.attack("target");
    std::cout << std::endl;
    frag.whoAmI();
    frag2.whoAmI();
    frag3.whoAmI();
    frag4.whoAmI();
    std::cout << std::endl; */
    /* frag.takeDamage(10);
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
    std::cout << std::endl; */
    
    DiamondTrap dio("dio");
	DiamondTrap jotaro("jotaro");

	jotaro.highFivesGuys();
	dio.guardGate();
	jotaro.whoAmI();
	dio.whoAmI();
	dio.attack("jotaro");
	jotaro.attack("dio");
	dio.takeDamage(4);
	dio.beRepaired(3);
	dio.attack("jotaro");
	jotaro.takeDamage(42);
	dio.beRepaired(1);
    return 0;
}