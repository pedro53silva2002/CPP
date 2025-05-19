#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap Dio("Dio");
    ClapTrap Jotaro("Jotaro");

    std::cout <<"OH you're approaching me?!" << std::endl;
    std::cout <<"I can't be the shit out of you without getting closer." << std::endl;
    for (size_t i = 0; i < 11; i++)
    {
        if (i == 9)
        {
            Dio.beRepaired(2);
            Jotaro.beRepaired(2);
        }
        Jotaro.attack("Dio");
        Dio.attack("Jotaro");
        if (i < 9)
        {
            Dio.takeDamage(1);
            Jotaro.takeDamage(1);
        }
    }
    Dio.beRepaired(2);
    Jotaro.beRepaired(2);
    return 0;
}