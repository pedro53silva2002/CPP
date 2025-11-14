#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: not enough arguments" << std::endl;
        return 1;
    }
   /*  while (1)
    {
        std::size_t found = input.find(' ');
        if (found == std::string::npos)
			break;
    } */
    
    PmergeMe pushswap(argv + 1);
    pushswap.pushswap();
    /* RPN testequation(argv[1]);
    testequation.equate(); */
    //btc.convert(argv[1]);
    return 0;
}