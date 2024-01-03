#ifndef HEADER
#define HEADER
#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(Fixed const& src);
	~Fixed();
	Fixed(int n);
	Fixed(float n);
	Fixed&	operator=(Fixed const& rhs);

	int		getRawBits(void) const;
	void	setRawBits(int raw);
	int		toInt(void) const ;
	float	toFloat(void) const ;

	bool	operator>(Fixed const& rhs);
	bool	operator<(Fixed const& rhs);
	bool	operator>=(Fixed const& rhs);
	bool	operator<=(Fixed const& rhs);
	bool	operator==(Fixed const& rhs);
	bool	operator!=(Fixed const& rhs);
	Fixed	operator+(Fixed const& rhs);
	Fixed	operator-(Fixed const& rhs);
	Fixed	operator*(Fixed const& rhs);
	Fixed	operator/(Fixed const& rhs);
	Fixed&	operator++(); // Prefix increment i++
	Fixed	operator++(int); // Postfix increment operator ++i
	Fixed&	operator--(); // Prefix decrement i--
	Fixed	operator--(int a); // Postfix decrement --i1
	static const Fixed& min(const Fixed& val1, const Fixed& val2); 
	static Fixed& min(Fixed& val1, Fixed& val2);
	static const Fixed& max(const Fixed& val1, const Fixed& val2);
	static Fixed& max(Fixed& val1, Fixed& val2);

private:
	int _raw;
	static const int fractional;
};

std::ostream & operator<<(std::ostream &o, Fixed const& rhs);

#endif