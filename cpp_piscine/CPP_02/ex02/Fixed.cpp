#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional = 8;

/* CONSTRUCTOR AND DESTRUCTOR */
Fixed::Fixed(void): _raw(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n): _raw(n * pow(2, fractional)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float n){
	_raw = roundf(n * pow(2, fractional));
	std::cout << "Float constructor called " << std::endl;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/* ACCESSORS */

void	Fixed::setRawBits(int raw) {
	_raw = raw;
}

int		Fixed::getRawBits(void) const {
	return (this->_raw);
}

int		Fixed::toInt(void) const {
	return (int)roundf(_raw / pow(2, fractional));
}

float	Fixed::toFloat(void) const {
	return ((float)_raw / pow(2, fractional));
}

/* OPERATOR */
Fixed & Fixed::operator=(Fixed const& rhs) {
	std::cout << "Assignation operator called " << std::endl;
	_raw = rhs.getRawBits();
	return *this;
}

std::ostream	& operator<<(std::ostream &o, Fixed const& rhs) {
	o << rhs.toFloat();
	return o;
}

/* COMPARISON OPERATOR */

bool	Fixed::operator>(Fixed const& rhs) {
	return _raw > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const& rhs) {
	return _raw < rhs.getRawBits();

}

bool	Fixed::operator>=(Fixed const& rhs) {
	return _raw >= rhs.getRawBits();

}

bool	Fixed::operator<=(Fixed const& rhs) {
	return _raw <= rhs.getRawBits();

}

bool	Fixed::operator==(Fixed const& rhs) {
	return _raw == rhs.getRawBits();

}

bool	Fixed::operator!=(Fixed const& rhs) {
	return _raw != rhs.getRawBits();

}

/* 	ARITHMETIC OPERATORS */

Fixed	Fixed::operator+(Fixed const& rhs) {
	return ((_raw + rhs.getRawBits()) / powf(2, 8));
}

Fixed	Fixed::operator-(Fixed const& rhs) {
	return ((_raw - rhs.getRawBits()) / powf(2, 8));
}

Fixed	Fixed::operator*(Fixed const& rhs) {
	return (_raw * rhs.getRawBits() / powf(2, 16));
}

Fixed Fixed::operator/(Fixed const& rhs) {
	return ((float)_raw / (float)rhs.getRawBits());
}

/* INCREMENT OPERATORS */

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	_raw++;
	return tmp;
}

Fixed&	Fixed::operator++() {
	_raw++;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	_raw--;
	return tmp;
}

Fixed&	Fixed::operator--() {
	_raw--;
	return *this;
}

/* STATIC MEMBER */

const Fixed& 	Fixed::min(const Fixed& val1, const Fixed& val2) {
	return val1.getRawBits() < val2.getRawBits() ? val1 : val2;
}

Fixed& 			Fixed::min(Fixed& val1, Fixed& val2) {
	return val1.getRawBits() < val2.getRawBits() ? val1 : val2;
}

const Fixed& 	Fixed::max(const Fixed& val1, const Fixed& val2) {
	return val1.getRawBits() > val2.getRawBits() ? val1 : val2;
}

Fixed& 			Fixed::max(Fixed& val1, Fixed& val2) {
	return val1.getRawBits() > val2.getRawBits() ? val1 : val2;
}