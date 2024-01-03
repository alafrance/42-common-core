#ifndef Cat_HPP
#define Cat_HPP
#include "Animal.hpp"

class Cat: public Animal {
public:
	Cat();
	Cat(Cat const& src);
	virtual ~Cat();
	virtual void	makeSound() const;
	Cat& operator=(Cat const& rhs);
private:
	
};

#endif