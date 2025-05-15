#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y)
{
	//std::cout << "Point constructor called" << std::endl;
	/* std::cout << "Point x: " << this->_x.toInt() << std::endl;
	std::cout << "Point y: " << this->_y.toInt() << std::endl; */
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
}

Point::~Point()
{
}

int Point::getXCoor(void) const
{
	//std::cout << "getXCoor: " << this->_x.toFloat() << std::endl;
	return _x.toInt();
}

int Point::getYCoor(void) const
{
	return _y.toInt();
}

//Point &Point::operator=(const Point &src) = delete;

Point& Point::operator=(const Point &src)
{
	(void)src;
	// Assignment operator is not allowed for const members
	return *this;
}