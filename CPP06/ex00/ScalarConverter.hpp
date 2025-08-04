#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
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
#include <exception>

class ScalarConverter
{
	private:
		int _intValue;
		float _floatValue;
		double _doubleValue;
		char _charValue;
		std::string _input;
		std::string _type;
		ScalarConverter();

		

	public:
		ScalarConverter(std::string _input);
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter & operator=(ScalarConverter const & src);
		~ScalarConverter();
		static void convert(std::string literal);
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
		static bool isConvertible(std::string _input);
};



#endif