#ifndef Dog_HPP
#define Dog_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
public:
	Dog();
	Dog(Dog const& src);
	virtual ~Dog();
	virtual void	makeSound() const;
	Dog& operator=(Dog const& rhs);
	Brain*	getBrain() const ;
	void	setBrain(Brain* brain);
private:
	Brain*	_brain;
};

#endif