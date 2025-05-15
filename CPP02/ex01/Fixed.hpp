#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class Fixed
{
	private:
		int	_fp_nbr;
		static const int _fractional_bits = 8;

	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
#endif