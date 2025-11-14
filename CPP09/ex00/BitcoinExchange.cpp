#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	_dataBase = std::map<std::string, float>();
    std::fstream file;
    file.open("data.csv", std::ios::in);
    while (file)
    {
        std::string line;
        std::getline(file, line);
        if (line.length() > 0 && line != "date,exchange_rate")
        {
            std::string date = line.substr(0, line.find(','));
            float rate = std::atof(line.substr(line.find(',') + 1).c_str());
            _dataBase.insert(std::make_pair(date, rate));
        }
    }
	/* for (std::map<std::string, float>::iterator i = _dataBase.begin(); i != _dataBase.end(); ++i) 
        std::cout << i->first << " " << i->second << std::endl; */
	//std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> dataBase) {
	_dataBase = dataBase;
	//std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	//std::cout << "BitcoinExchange copy assignation called" << std::endl;
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	//std::cout << "BitcoinExchange assignation operator called" << std::endl;
	if (this != &src)
		_dataBase = src._dataBase;
	/* if (this != &src)
	{
		_input = src.getInput();
		_intValue = src.getIntValue();
		_charValue = src.getCharValue();
		_doubleValue = src.getDoubleValue();
		_floatValue = src.getFloatValue();
		_type = src.getType();
	} */
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	//std::cout << "BitcoinExchange descontructor called" << std::endl;
}

void BitcoinExchange::convert(std::string input) {
	std::ifstream MyReadFile(input.c_str());
	bool found;
	/* if (!MyReadFile) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	} */
	std::string line;
	std::getline(MyReadFile, line); // Skip header line
	//std::cout << "FIRST" << std::endl;
	while (std::getline(MyReadFile, line))
	{
		found = false;
		//std::cout << "SECOND" << std::endl;
		std::string file_date = line.substr(0, line.find('|') - 1);
        float file_rate = std::atof(line.substr(line.find('|') + 1).c_str());
		//std::cout << file_date << std::endl;
		for (std::map<std::string, float>::iterator i = _dataBase.begin(); i != _dataBase.end(); ++i) 
        {
			//std::cout << "GOT IN" << std::endl;
			//std::cout << i->first << "\t\t" << file_date << std::endl;
			if (i->first == file_date) {
				found = true;
				if (checkData(file_date, file_rate))
					std::cout << file_date << " => " << file_rate << " = " << file_rate * i->second << std::endl;
				break;
			}
			else if (i->first > file_date && found == false) {
				found = true;
				if (checkData(file_date, file_rate))
				{
					std::cout << file_date << " => " << file_rate << " = " << file_rate * (--i)->second << std::endl;
					++i;
				}
				break;
			}
		}
	}
	MyReadFile.close();
	//std::cout << "BitcoinExchange convert function called" << std::endl;
}

bool BitcoinExchange::checkData(std::string date, float rate) {
	struct tm tm;
	if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (static_cast<double>(rate) > 1000.0) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	else if (rate < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	/* //std::string year_str = date.substr(0, date.find('-'));
	std::string month_str = date.substr(date.find('-') + 1, date.rfind('-') - date.find('-') - 1);
	std::string day_str = date.substr(date.rfind('-') + 1);
	//int year = std::atoi(year_str.c_str());
	int month = std::atoi(month_str.c_str());
	int day = std::atoi(day_str.c_str());
	if (month < 1 || month > 12) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (day < 1 || day > 31) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	} */
	return true;
}