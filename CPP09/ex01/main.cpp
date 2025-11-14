#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: not enough arguments" << std::endl;
        return 1;
    }
    for (size_t i = 0; argv[1][i]; i++)
    {
        if (argv[1][i] != ' ' && argv[1][i] != '+' && argv[1][i] != '-' && argv[1][i] != '*' && argv[1][i] != '/' && !isdigit(argv[1][i]))
        {
            std::cerr << "Error: invalid character in input." << std::endl;
            return 1;
        }
        /* if (i == 0 || i % 2 != 0)
        {
            for (size_t j = 0; j < argv[1][i][j]; j++)
            {
                if (!isdigit(argv[1][i][j]))
                {
                    std::cerr << "Error: it needs to be all digits" << std::endl;
                    return 1;
                }
            }
        }
        else if (i % 2 == 0 && argv[1][i] != ' ')
        {
            std::cerr << "Error: invalid format." << std::endl;
            return 1;
        } */
    }
    //std::string input = argv[1];
   /*  while (1)
    {
        std::size_t found = input.find(' ');
        if (found == std::string::npos)
			break;
    } */
    
    
    //RPN testequation(argv[1]);
    // Step 1: Initialize all RPN objects
    RPN testequation("3 4 +");               // 3 + 4 = 7
    RPN testequation1("5 2 -");              // 5 - 2 = 3
    RPN testequation2("2 3 *");              // 2 * 3 = 6
    RPN testequation3("8 2 /");              // 8 / 2 = 4
    RPN testequation4("5 1 2 + *");          // 1 + 2 = 3; 5 * 3 = 15
    RPN testequation5("3 2 4 * +");          // 2 * 4 = 8; 3 + 8 = 11
    RPN testequation6("4 2 + 1 3 * +");      // 4 + 2 = 6; 1 * 3 = 3; 6 + 3 = 9
    RPN testequation7("2 3 + 4 *");          // 2 + 3 = 5; 5 * 4 = 20
    RPN testequation8("7 3 2 + -");          // 3 + 2 = 5; 7 - 5 = 2
    RPN testequation9("1 2 3 + *");          // 2 + 3 = 5; 1 * 5 = 5
    RPN testequation10("2 2 * 3 +");         // 2 * 2 = 4; 4 + 3 = 7
    RPN testequation11("5 1 2 + 4 * +");     // 1 + 2 = 3; 3 * 4 = 12; 5 + 12 = 17
    RPN testequation12("3 4 5 * +");         // 4 * 5 = 20; 3 + 20 = 23
    RPN testequation13("6 2 1 - *");         // 2 - 1 = 1; 6 * 1 = 6
    RPN testequation14("3 3 3 + +");         // 3 + 3 = 6; 6 + 3 = 9
    //RPN testequation15("(3 3 3 + +)"); 

    // Then call equate() on all of them
    testequation.equate();
    testequation1.equate();
    testequation2.equate();
    testequation3.equate();
    testequation4.equate();
    testequation5.equate();
    testequation6.equate();
    testequation7.equate();
    testequation8.equate();
    testequation9.equate();
    testequation10.equate();
    testequation11.equate();
    testequation12.equate();
    testequation13.equate();
    testequation14.equate();
    //testequation15.equate();


    return 0;
}