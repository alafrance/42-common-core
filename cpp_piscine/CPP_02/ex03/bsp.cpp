#include "Point.hpp"

Fixed	inside_or_not(Point p, Point v1, Point v2)
{
    return (p.getX() - v2.getX()) * (v1.getY() - v2.getY()) - (v1.getX() - v2.getX()) * (p.getY() - v2.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	bool b1, b2, b3;
	Fixed zero(0.0f);

	b1 = inside_or_not(point, a, b) < zero;
	b2 = inside_or_not(point, b, c) < zero;
	b3 = inside_or_not(point, c, a) < zero;
	return ((b1 == b2) && (b2 == b3));
}
