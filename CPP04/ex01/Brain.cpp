#include "Brain.hpp"

Brain::Brain()
{
	for (size_t i = 0; i < 100; i++)
	{
		this->_ideas[i] = "";
	}
	std::cout << "Brain contructor called" << std::endl;
}

Brain::Brain(std:: string ideas[100]) : _ideas()
{
	for (size_t i = 0; i < 100; i++)
	{
		this->_ideas[i] = ideas[i];
	}
	std::cout << "Brain contructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (size_t i = 0; i < 100; i++)
		{
			this->_ideas[i] = src._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain descontructor called" << std::endl;
}