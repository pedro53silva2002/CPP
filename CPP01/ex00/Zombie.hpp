#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif