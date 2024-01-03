#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {

}

Point::~Point(void){

}

Point::Point(float x, float y): _x(x), _y(y) {

}


Point::Point(Fixed x, Fixed y): _x(x), _y(y) {

}

Point::Point(Point const& src): _x(src._x), _y(src._y){

}

Fixed	Point::getX(void) const {
	return (_x);
}

 Fixed	Point::getY(void) const {
	return (_y);
}

Point&	Point::operator=(Point const& rhs){
	(void)rhs;
	return *this;
}
