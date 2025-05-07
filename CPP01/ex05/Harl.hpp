#ifndef HARL_HPP
#define HARL_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void error(void);
		void warning(void);

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};


#endif