#ifndef REPLACE_HPP
#define REPLACE_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

class File
{
	private:
		std::string _filename;

	public:
		File(std::string filename);
		~File();
		void replace(std::string s1, std::string s2);
};


#endif