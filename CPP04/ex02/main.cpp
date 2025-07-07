#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
    /* AAnimal a;
    a = new Dog(); */
    std::cout << std::endl;
    const AAnimal *animals[6];
    animals[0] = new Dog();
    std::cout << std::endl;
    animals[1] = new Cat();
    std::cout << std::endl;
    animals[2] = new Dog();
    std::cout << std::endl;
    animals[3] = new Cat();
    std::cout << std::endl;
    animals[4] = new Dog();
    std::cout << std::endl;
    animals[5] = new Cat();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < 6; i++)
    {
        delete animals[i];
        std::cout << std::endl;
    }
    return 0;
}