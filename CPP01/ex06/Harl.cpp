#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain(std::string level)
{
	int i = 0;
	std::string levels[4] = {"debug", "info", "warning", "error"};
	void (Harl::*complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for(; i < 4; i++)
	{
		if(level == levels[i])
			break;
	}
	switch (i)
	{
		case 0:
			std::cout << "[DEBUG]" << std::endl;
			(this->*complain[0])();
			std::cout << std::endl;
		case 1:
			std::cout << "[INFO]" << std::endl;
			(this->*complain[1])();
			std::cout << std::endl;
		case 2:
			std::cout << "[WARNING]" << std::endl;
			(this->*complain[2])();
			std::cout << std::endl;
		case 3:
			std::cout << "[ERROR]" << std::endl;
			(this->*complain[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}