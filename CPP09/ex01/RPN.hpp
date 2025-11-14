#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <queue>
#include <limits>
#include <exception>

class RPN
{
	private:
		std::list<int> _dataBase;

	public:
        RPN();
		RPN(std::string equation);
		RPN(std::list<int> dataBase);
		RPN(RPN const & src);
		RPN & operator=(RPN const & src);
		~RPN();
		void equate();
		//int specialequation(std::queue<int> &dataBase, int first_nbr);
		/* void convert(std::string input);
		bool checkData(std::string date, float rate); */
		/* static void convert(std::string literal);
		void convertFromChar();
		void convertFromInt();
		void convertFromFloat();
		void convertFromDouble();
		void convertFromNan();
		void convertFromInf();
		int getIntValue() const;
		float getFloatValue() const;
		double getDoubleValue() const;
		char getCharValue() const;
		std::string getInput() const;
		std::string getType() const;
		void printConversions();
		static bool isConvertible(std::string _input); */
};

#endif