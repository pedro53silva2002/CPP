#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <cmath>

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const Point &src);
		Point(const Fixed &x, const Fixed &y);
		Point& operator=(const Point &src);
		~Point();
		int getXCoor(void) const;
		int getYCoor(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif