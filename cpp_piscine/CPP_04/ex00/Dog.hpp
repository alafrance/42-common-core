#ifndef Dog_HPP
#define Dog_HPP
#include "Animal.hpp"

class Dog: public Animal {
public:
	Dog();
	Dog(Dog const& src);
	virtual ~Dog();
	virtual void	makeSound() const;
	Dog& operator=(Dog const& rhs);
private:
	
};

#endif