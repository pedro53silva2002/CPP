#include "Fixed.hpp"

Fixed::Fixed() : _fp_nbr(0)
{
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int nbr)
{
	this->_fp_nbr = nbr << _fractional_bits;
}
Fixed::Fixed(const float nbr)
{
	this->_fp_nbr = roundf(nbr * (1 << _fractional_bits));
}


Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
	{
		this->_fp_nbr = src.getRawBits();
	}
	return *this;
}

Fixed Fixed::operator+(const Fixed &src) const
{
	Fixed result;
	result.setRawBits(this->_fp_nbr + src.getRawBits());
	return result;
}
Fixed Fixed::operator-(const Fixed &src) const
{
	Fixed result;
	result.setRawBits(this->_fp_nbr - src.getRawBits());
	return result;
}
Fixed Fixed::operator*(const Fixed &src) const
{
	Fixed result;
	result.setRawBits((this->_fp_nbr * src.getRawBits()) >> _fractional_bits);
	return result;
}
Fixed Fixed::operator/(const Fixed &src) const
{
	Fixed result;
	result.setRawBits((this->_fp_nbr << _fractional_bits) / src.getRawBits());
	return result;
}
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fp_nbr++;
	return temp;
}
Fixed Fixed::operator++()
{
	this->_fp_nbr++;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fp_nbr--;
	return temp;
}
Fixed Fixed::operator--()
{
	this->_fp_nbr--;
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return this->_fp_nbr;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? b : a);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? b : a);
}

void Fixed::setRawBits(int const raw)
{
	this->_fp_nbr = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_fp_nbr / (1 << _fractional_bits);
}

int Fixed::toInt(void) const
{
	return this->_fp_nbr >> _fractional_bits;
}

bool Fixed::operator>(const Fixed &src) const
{
	return this->_fp_nbr > src.getRawBits();
}

bool Fixed::operator<(const Fixed &src) const
{
	return this->_fp_nbr < src.getRawBits();
}

bool Fixed::operator>=(const Fixed &src) const
{
	return this->_fp_nbr >= src.getRawBits();
}

bool Fixed::operator<=(const Fixed &src) const
{
	return this->_fp_nbr <= src.getRawBits();
}

bool Fixed::operator==(const Fixed &src) const
{
	return this->_fp_nbr == src.getRawBits();
}

bool Fixed::operator!=(const Fixed &src) const
{
	return this->_fp_nbr != src.getRawBits();
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
