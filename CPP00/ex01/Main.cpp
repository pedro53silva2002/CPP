#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <csignal>

void ft_handle_sigint(int sig){
	(void)sig;
	std::cout << "\nGoodbye!" << std::endl;
	exit(0);
}

int main(void){
	Phonebook phone;
	std::cout << "Welcome to the phonebook!" << std::endl;
	std::signal(SIGINT, ft_handle_sigint);
	while (1){
		std::string command;
		std::cout << "Whatchu want? ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			break;
		}
		if (command == "ADD"){
			//std::cout << command << std::endl;
			phone.ft_add();
		}
		else if (command == "SEARCH"){
			//std::cout << command << std::endl;
			std::cout << "\n";
			phone.ft_search();
		}
		else if (command == "EXIT"){
			//std::cout << command << std::endl;
			break;
		}
		else{
			std::cout << "Invalid command." << std::endl;
		}
	}
}