#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;
    std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;
    std::cout << "b.getRawBits() = " << b.getRawBits() << std::endl;
    std::cout << "c.getRawBits() = " << c.getRawBits() << std::endl;
    return 0;
}