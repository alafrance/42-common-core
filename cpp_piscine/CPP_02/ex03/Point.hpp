#ifndef POINT
#define POINT
#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(Point const& src);
	Point(float const x, float const y);
	Point(Fixed x, Fixed y);
	~Point();
	Point& operator=(Point const& rhs);
	Fixed	getX(void) const;
	Fixed	getY(void) const;
private:
	Fixed const _x;
	Fixed const _y;
};

#endif
