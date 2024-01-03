#include <iostream>
#include "Fixed.hpp"

// int main(void){
// 	Fixed		a;
// 	Fixed		const	b(Fixed(3.02f));
// 	Fixed		c(2);

// 	std::cout << b << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << --a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a-- << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;

// 	if (a > b) {
// 		std::cout << "a is upper to b" << std::endl;
// 	}
// 	if (a < b) {
// 		std::cout << "a is lower to b" << std::endl;
// 	}
// 	a = a + 2;
// 	if (a <= b) {
// 		std::cout << "a is lower or equal to b" << std::endl;
// 	}
// 	if (a >= b) {
// 		std::cout << "a is upper or equal to b" << std::endl;
// 	}
// 	if (a == b) {
// 		std::cout << "a is equal to b" << std::endl;
// 	}
// 	if (a != b) {
// 		std::cout << "a is not equal to b" << std::endl;
// 	}
// 	std::cout << "Max a/b : " << Fixed::max(a, b ) << std::endl;
// 	std::cout << "Min a/b : " << Fixed::min(a, b ) << std::endl;
// 	std::cout << "Max a/c : " << Fixed::max(a, c) << std::endl;
// }

// MAIN SUBJECT
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
