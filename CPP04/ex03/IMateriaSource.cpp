#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() : _idx(0)
{
	//std::cout << "IMateriaSource contructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}
IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
	*this = other;
}
IMateriaSource &IMateriaSource::operator=(const IMateriaSource &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
			this->_materia[i] = src._materia[i];
	}
	return *this;
}
IMateriaSource::~IMateriaSource()
{
	//std::cout << "IMateriaSource descontructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
}
void IMateriaSource::learnMateria(AMateria* m)
{
	if (this->_idx < 4 && m)
	{
		this->_materia[this->_idx] = m;
		this->_idx++;
	}
	/* else
		std::cout << "Materia source is full or materia is NULL" << std::endl; */
}
AMateria* IMateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_idx; i++)
	{
		if (this->_materia[i]->getType() == type)
			return this->_materia[i]->clone();
	}
	//std::cout << "Materia not found" << std::endl;
	return NULL;
}