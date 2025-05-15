#include "Point.hpp"

Fixed	triArea(Point const a, Point const b, Point const c)
{
	Fixed area = Fixed(
		a.getXCoor() * (b.getYCoor() - c.getYCoor()) +
		b.getXCoor() * (c.getYCoor() - a.getYCoor()) +
		c.getXCoor() * (a.getYCoor() - b.getYCoor())
	) / Fixed(2);
	if (area < 0)
		area = area * Fixed(-1);
	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	return triArea(a, b, c) == triArea(a, b, point) + triArea(a, point, c) + triArea(point, b, c);
}

/* #include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Point ap = Point(Fixed(a.getXCoor()) - Fixed(point.getXCoor()), Fixed(a.getYCoor()) - Fixed(point.getYCoor()));
    Point bp = Point(Fixed(b.getXCoor()) - Fixed(point.getXCoor()), Fixed(b.getYCoor()) - Fixed(point.getYCoor()));
    Point cp = Point(Fixed(c.getXCoor()) - Fixed(point.getXCoor()), Fixed(c.getYCoor()) - Fixed(point.getYCoor()));
    Point ab = Point(Fixed(b.getXCoor()) - Fixed(a.getXCoor()), Fixed(b.getYCoor()) - Fixed(a.getYCoor()));
    Point ac = Point(Fixed(c.getXCoor()) - Fixed(a.getXCoor()), Fixed(c.getYCoor()) - Fixed(a.getYCoor()));

    Fixed area = ((ab.getXCoor() * ac.getYCoor())) - ((ab.getYCoor() * ac.getXCoor())) / 2;

    Fixed parea1 = ((ap.getXCoor() * bp.getYCoor())) - ((ap.getYCoor() * bp.getXCoor())) / 2;
    Fixed parea2 = ((bp.getXCoor() * cp.getYCoor())) - ((bp.getYCoor() * cp.getXCoor())) / 2;
    Fixed parea3 = ((cp.getXCoor() * ap.getYCoor())) - ((cp.getYCoor() * ap.getXCoor())) / 2;

    if (parea1 < 0 || parea2 < 0 || parea3 < 0)
        return false;
    if (parea1 + parea2 + parea3 != area)
        return false;
    return true;
} */