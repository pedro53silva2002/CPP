#include "Replace.hpp"

File::File(std::string filename)/*  : _filename(filename) */
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		exit(1);
	}
	file.close();
	this->_filename = filename;
}

File::~File()
{
}

void File::replace(std::string s1, std::string s2)
{
	std::ifstream file(_filename);
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file " << _filename << std::endl;
		exit(1);
	}
	std::string line;
	std::string text;
	std::string new_text;
	std::string new_file = _filename + ".replace";
	std::ofstream new_file_stream(new_file);
	if (!new_file_stream.is_open())
	{
		std::cerr << "Error: Could not create file " << new_file << std::endl;
		exit(1);
	}
	else
	{
		while (std::getline(file, line))
		{
			text += line;
			text += "\n";
		}
		int start = 0;
		std::cout << "text: " << text << std::endl;
		std::cerr << "SOME TEXT HERE " << new_file << std::endl;
		while (text[start] != '\0')
		{
			if (text.substr(start, s1.length()) == s1 && start + s1.length() <= text.length())
			{
				new_text += s2;
				start += s1.length();
			}
			else
			{
				new_text += text[start];
				start++;
			}
		}
		new_file_stream << new_text;
	}
	
}