#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
/* #include <limits>
#include <cstdlib>
#include <signal.h>
#include <stdlib.h> */

Phonebook::Phonebook(){
	this->index = 0;
	this->len = 0;
}

Phonebook::~Phonebook(){

}

std::string Phonebook::ft_getline(std::string prompt)
{
	std::string line;
	while (1)
	{
		std::cout << prompt;
		std::getline(std::cin, line);
		if (std::cin.eof())
			exit(0);
		if (line.empty())
		{
			std::cout << "Invalid input." << std::endl;
		}
		else
		{
			return line;
			break;
		}
	}
	return line;
}

void Phonebook::ft_add()
{
	if (this->index == 8)
	{
		this->index = 0;
	}
	this->contacts[this->index].set_index(this->index + 1);
	this->contacts[this->index].set_first_name(ft_getline("First name: "));
	this->contacts[this->index].set_last_name(ft_getline("Last name: "));
	this->contacts[this->index].set_nickname(ft_getline("Nickname: "));
	this->contacts[this->index].set_phone_number(ft_getline("Phone number: "));
	this->contacts[this->index].set_darkest_secret(ft_getline("Darkest secret: "));
	this->index++;
	if (this->len < 8)
		this->len++;
	std::cout << "\nContact added\n" << std::endl;
}

void Phonebook::ft_search()
{
	//std::vector<std::string> words = {"Hello", "World", "C++", "Rocks"};
	std::cout << "Index     |First name|Last name |  Nickname" << std::endl;
	for (int i = 0; i < this->len; i++)
	{
		if (this->contacts[i].get_index(true) != "")
		{
			std::cout << std::setw(10) << this->contacts[i].get_index(true)<< "|";
			std::cout << std::setw(10) << this->contacts[i].get_first_name(true) << "|";
			std::cout << std::setw(10) << this->contacts[i].get_last_name(true) << "|";
			std::cout << std::setw(10) << this->contacts[i].get_nickname(true) << std::endl;
		}
		/* std::cout << this->contacts[i].get_index() << "\t|";
		std::cout << this->contacts[i].get_first_name() << "         |";
		std::cout << this->contacts[i].get_last_name() << "         |";
		std::cout << this->contacts[i].get_nickname() << std::endl; */
	}
	while (1)
	{
		int number;
		std::string index;
		//std::string index = ft_getline("Let's someone dark secret: ");
		std::cout << "Let's someone dark secret: ";
		std::getline(std::cin, index);
		if (std::cin.eof())
			exit(0);
		std::istringstream iss(index);
		iss >> number;
		if ( number == 8 || number > len || number <= 0)
		{
			std::cout << "There's noone there "<< std::endl;
			std::cout << "\n";
			break;
		}
		else
		{
			std::cout << "\n";
			std::cout << "First name: " << this->contacts[number - 1].get_first_name(false) << std::endl;
			std::cout << "Last name: " << this->contacts[number - 1].get_last_name(false) << std::endl;
			std::cout << "Nickname: " << this->contacts[number - 1].get_nickname(false) << std::endl;
			std::cout << "Phone number: " << this->contacts[number - 1].get_phone_number(false) << std::endl;
			std::cout << "Darkest secret: " << this->contacts[number - 1].get_darkest_secret(false) << std::endl;
			std::cout << "\n";
			break;
		}
	}
}