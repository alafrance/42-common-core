#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main() {
	Point point(4, 4);
	Point a(2, 3);
	Point b(4, 7);
	Point c(7, 1);
	if (bsp(a, b, c, point))
		std::cout << "\e[0;32mThe point is inside the triangle\n";
	else
		std::cout << "\e[0;31mThe point is NOT inside the triangle\n";
	std::cout << "\e[0m";
	return (0);
}
