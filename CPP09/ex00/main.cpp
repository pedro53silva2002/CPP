#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    //std::ifstream file;
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::ifstream MyReadFile(argv[1]);
    if (!MyReadFile) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    MyReadFile.close();
    //file.open(argv[1], std::ios::in);
    /* else if (!file.open(argv[1], std::ios::in))
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    } */
    BitcoinExchange btc;
    btc.convert(argv[1]);
    return 0;
}