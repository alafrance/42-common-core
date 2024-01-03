#ifndef HEADER
#define HEADER
#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(Fixed const& src);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed&	operator=(Fixed const& rhs);
private:
	int _raw;
	static const int fractional;
};

#endif