#include "RPN.hpp"

RPN::RPN() {
	_dataBase = std::list<int>();
	/* for (std::map<std::string, float>::iterator i = _dataBase.begin(); i != _dataBase.end(); ++i) 
        std::cout << i->first << " " << i->second << std::endl; */
	//std::cout << "BitcoinExchange default constructor called" << std::endl;
}

RPN::RPN(std::string equation) {
	std::string item;
	std::list<std::string> dummyBase;
	while (1)
	{
		std::size_t found = equation.find(' ');
		//std::cout << "EQUATION: " << equation << std::endl;
		if (equation[0] == '+' || equation[0] == '-' || equation[0] == '*' || equation[0] == '/')
		{
			if (equation.find(' '))
				item = equation.substr(0, equation.find(' '));
			else
				item = equation;
			dummyBase.push_back(item.c_str());
			_dataBase.push_back(item.c_str()[0]);
			equation = equation.substr(equation.find(' ') + 1);
		}
		else
		{
			item = equation.substr(0, equation.find(' '));
			dummyBase.push_back(item.c_str());
			_dataBase.push_back(std::atoi(item.c_str()));
			equation = equation.substr(equation.find(' ') + 1);
		}
		if (found == std::string::npos)
			break;
	}
	//std::cout << "EQUATION SIZE: " << _dataBase.size() << std::endl;
	if (_dataBase.size() < 3)
	{
		std::cerr << "Error: Gotta be atleast 3 arguments." << std::endl;
		exit(1);
	}
	else if((_dataBase.size() % 2) == 0)
	{
		std::cerr << "Error: Invalid size" << std::endl;
		exit(1);
	}
	int i = 0;
	while (!dummyBase.empty())
	{
		//std::cout << "DIGIT: " << dummyBase.front() << "\tCondition: " << isdigit(dummyBase.front()[0]) << std::endl;
		if (isdigit(dummyBase.front()[0]))
        {
			if (atoi(dummyBase.front().c_str()) > 9)
			{
				std::cerr << "Error: It gotta be smaller than 10" << std::endl;
				exit(1);
			}
        }
        else if (dummyBase.front() != "+" && dummyBase.front() != "-" && dummyBase.front() != "*" && dummyBase.front() != "/")
        {
            std::cerr << "Error: only one of the signs" << std::endl;
            exit(1);
        }
		dummyBase.pop_front();
		i++;
	}
	
}

RPN::RPN(std::list<int> dataBase) {
	_dataBase = dataBase;
	//std::cout << "BitcoinExchange default constructor called" << std::endl;
}

RPN::RPN(const RPN& other)
{
	//std::cout << "BitcoinExchange copy assignation called" << std::endl;
	*this = other;
}

RPN &RPN::operator=(const RPN &src)
{
	//std::cout << "BitcoinExchange assignation operator called" << std::endl;
	if (this != &src)
		_dataBase = src._dataBase;
	return *this;
}

RPN::~RPN()
{
	//std::cout << "BitcoinExchange descontructor called" << std::endl;
}

void RPN::equate()
{
	std::list<int> tempNbrs;
	std::list<int> tempOps;
	while (!_dataBase.empty())
	{
		int current = _dataBase.front();
		_dataBase.pop_front();
		if (current == '+' || current == '-' || current == '*' || current == '/')
		{
			tempOps.push_back(current);
		}
		else
		{
			tempNbrs.push_back(current);
		}
		if (tempNbrs.size() >= 2 && !tempOps.empty())
		{
			int second = tempNbrs.back();
			tempNbrs.pop_back();
			int first = tempNbrs.back();
			tempNbrs.pop_back();
			char op = char(tempOps.front());
			tempOps.pop_front();
			switch (op)
			{
				case '+':
					tempNbrs.push_back(first + second);
					break;
				case '-':
					tempNbrs.push_back(first - second);
					break;
				case '*':
					tempNbrs.push_back(first * second);
					break;
				case '/':
					tempNbrs.push_back(first / second);
					break;
				default:
					break;
			}
		}
	}
	std::cout << "Result: " << tempNbrs.front() << std::endl;
}