#ifndef WrongCat_HPP
#define WrongCat_HPP
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
	WrongCat();
	WrongCat(WrongCat const& src);
	virtual ~WrongCat();
	void	makeSound() const;
	WrongCat& operator=(WrongCat const& rhs);
private:
	
};

#endif