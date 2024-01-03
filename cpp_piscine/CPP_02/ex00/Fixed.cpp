#include "Fixed.hpp"
const int Fixed::fractional = 8;

/* CONSTRUCTOR AND DESTRUCTOR */
Fixed::Fixed(void): _raw(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/* ACCESSORS */
void	Fixed::setRawBits(int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_raw = raw;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

/* OPERATOR */
Fixed & Fixed::operator=(Fixed const& rhs) {
	std::cout << "Assignation operator called" << std::endl;
	_raw = rhs.getRawBits();
	return *this;
}
