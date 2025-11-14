#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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
#include <limits>
#include <exception>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _dataBase;

	public:
        BitcoinExchange();
		BitcoinExchange(std::map<std::string, float> dataBase);
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange & operator=(BitcoinExchange const & src);
		~BitcoinExchange();
		void convert(std::string input);
		bool checkData(std::string date, float rate);
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