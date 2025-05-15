#include "Point.hpp"

int main( void ) {
    Point a(Fixed(2), Fixed(2));
    Point b(Fixed(4), Fixed(4));
    Point c(Fixed(6), Fixed(2));
    Point point(4, 3);
    Point point2(4, 5);
    Point point3(2, 2);
    Point point4(6, 3);
    Point point5(5, 3);

    std::cout << "Point a: " << a.getXCoor() << ", " << a.getYCoor() << std::endl;
    std::cout << "Point b: " << b.getXCoor() << ", " << b.getYCoor() << std::endl;
    std::cout << "Point c: " << c.getXCoor() << ", " << c.getYCoor() << std::endl;
    //std::cout << "Point a again: " << a.getXCoor() << ", " << a.getYCoor() << std::endl;
    if (bsp(a, b, c, point))
        std::cout << "Point point " << point.getXCoor() << "," << point.getYCoor() << " is inside the triangle" << std::endl;
    else
        std::cout << "Point point " << point.getXCoor() << "," << point.getYCoor() << " is outside the triangle" << std::endl;
    //std::cout << "Point a after: " << a.getXCoor() << ", " << a.getYCoor() << std::endl;
    if (bsp(a, b, c, point2))
        std::cout << "Point point2 " << point2.getXCoor() << "," << point2.getYCoor() << " is inside the triangle" << std::endl;
    else
        std::cout << "Point point2 " << point2.getXCoor() << "," << point2.getYCoor() << " is outside the triangle" << std::endl;
    if (bsp(a, b, c, point3))
    std::cout << "Point point3 " << point3.getXCoor() << "," << point3.getYCoor() << " is inside the triangle" << std::endl;
    else
        std::cout << "Point point3 " << point3.getXCoor() << "," << point3.getYCoor() << " is outside the triangle" << std::endl;
    if (bsp(a, b, c, point4))
    std::cout << "Point point4 " << point4.getXCoor() << "," << point4.getYCoor() << " is inside the triangle" << std::endl;
    else
        std::cout << "Point point4 " << point4.getXCoor() << "," << point4.getYCoor() << " is outside the triangle" << std::endl;
    if (bsp(a, b, c, point5))
    std::cout << "Point point5 " << point5.getXCoor() << "," << point5.getYCoor() << " is inside the triangle" << std::endl;
    else
        std::cout << "Point point5 " << point5.getXCoor() << "," << point5.getYCoor() << " is outside the triangle" << std::endl;
    return 0;
}