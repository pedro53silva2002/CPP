#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() : _input("Default") {
	//_type = "string";
	//std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string input) : _input(input)
{
	//_type = "string";
	//std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	//std::cout << "ScalarConverter copy assignation called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	//std::cout << "ScalarConverter assignation operator called" << std::endl;
	if (this != &src)
	{
		_input = src.getInput();
		_intValue = src.getIntValue();
		_charValue = src.getCharValue();
		_doubleValue = src.getDoubleValue();
		_floatValue = src.getFloatValue();
		_type = src.getType();
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	//std::cout << "ScalarConverter descontructor called" << std::endl;
}

void ScalarConverter::convert(std::string literal)
{	
	bool isInt = true;

	if (!isConvertible(literal)){
		std::cerr << "Invalid input: " << literal << std::endl;
		return;
	}
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]) && literal[i] != '-' && literal[i] != '+')
			isInt= false;
	}
	if (literal == "nan" || literal == "nanf")
	{
		ScalarConverter converter(literal);
		converter.convertFromNan();
	}
	else if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
	{
		ScalarConverter converter(literal);
		converter.convertFromInf();
	}
	else if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		ScalarConverter converter(literal);
		converter.convertFromChar();
	}
	else if (isInt)
	{
		ScalarConverter converter(literal);
		converter.convertFromInt();
	}
	else if (literal.find('.') != std::string::npos || literal.find('f') != std::string::npos)
	{
		if (literal[literal.length() - 1] == 'f')
		{
			ScalarConverter converter(literal);
			converter.convertFromFloat();
		}
		else
		{
			ScalarConverter converter(literal);
			converter.convertFromDouble();
		}
	}
	//std::cout << "Converting literal: " << literal << std::endl;
}

bool ScalarConverter::isConvertible(std::string _input)
{
	int dotCount = 0;
	int fCount = 0;
	int plusCount = 0;
	int minusCount = 0;

	if (_input == "nan" || _input == "nanf" || _input == "inf" || _input == "inff" || _input == "+inf" || _input == "-inf" || _input == "+inff" || _input == "-inff" || _input.size() == 1)
		return true;
	for (size_t i = 0; i < _input.length(); i++)
	{
		if (_input[i] == '.')
		{
			dotCount++;
			if (dotCount > 1)
				return false;
		}
		else if (_input[i] == 'f')
		{
			fCount++;
			if (fCount > 1 || i != _input.length() - 1)
				return false;
		}
		else if (_input[i] == '+')
		{
			plusCount++;
			if (plusCount > 1 || i != 0)
				return false;
		}
		else if (_input[i] == '-')
		{
			minusCount++;
			if (minusCount > 1 || i != 0)
				return false;
		}
		if (!std::isdigit(_input[i]) && _input[i] != '-' && _input[i] != '+' && _input[i] != '.' && _input[i] != 'f')
			return false;
	}
	return true;
}

void ScalarConverter::convertFromInf()
{
	if (_input == "inf" || _input == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (_input == "+inf" || _input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (_input == "-inf" || _input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convertFromNan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convertFromChar()
{
	_charValue = _input[0];
	_intValue = static_cast<int>(_charValue);
	_floatValue = _intValue;
	_doubleValue = _floatValue;
	_type = "char";
	printConversions();
	//std::cout << "Converted from char: " << _intValue << std::endl;
}

void ScalarConverter::convertFromInt()
{
	_intValue = std::atoi(_input.c_str());
	if (_intValue < 33 || _intValue > 126)
		_charValue = '\0';
	else
		_charValue = static_cast<char>(_intValue);
	_floatValue = _intValue;
	_doubleValue = _intValue;
	_type = "int";
	printConversions();
	//std::cout << "Converted from int: " << _intValue << std::endl;
}

void ScalarConverter::convertFromFloat()
{
	_floatValue = std::atof(_input.c_str());
	if (_floatValue < 33 || _floatValue > 126)
		_charValue = '\0';
	else
		_charValue = static_cast<char>(_floatValue);
	_intValue = static_cast<int>(_floatValue);
	_doubleValue = _floatValue;
	_type = "float";
	printConversions();
	//std::cout << "Converted from float: " << _floatValue << std::endl;
}

void ScalarConverter::convertFromDouble()
{
	_doubleValue = std::atof(_input.c_str());
	if (_doubleValue < 33 || _doubleValue > 126)
		_charValue = '\0';
	else
		_charValue = static_cast<char>(_doubleValue);
	_intValue = static_cast<int>(_doubleValue);
	_floatValue = static_cast<float>(_doubleValue);
	_type = "double";
	printConversions();
	//std::cout << "Converted from double: " << _doubleValue << std::endl;
}

void ScalarConverter::printConversions()
{
	if (_intValue < 33 || _intValue > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << _charValue << "'" << std::endl;
	//std::cout << "char: " << _charValue << std::endl;
	std::cout << "int: " << _intValue << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << _floatValue <<  "f" << std::endl;
	//std::cout << "float: " << _floatValue << ".0f" << std::endl;
	for (size_t i = 0; i < _input.length(); i++)
	{
		if (_input[i] == '.')
		{
			std::cout << "double: " << _doubleValue << std::endl;
			return;
		}
	}
	std::cout << "double: " << _doubleValue << std::endl;
}

int ScalarConverter::getIntValue() const
{
	return _intValue;
}
float ScalarConverter::getFloatValue() const
{
	return _floatValue;
}
double ScalarConverter::getDoubleValue() const
{
	return _doubleValue;
}
char ScalarConverter::getCharValue() const
{
	return _charValue;
}
std::string ScalarConverter::getInput() const
{
	return _input;
}
std::string ScalarConverter::getType() const
{
	return _type;
}