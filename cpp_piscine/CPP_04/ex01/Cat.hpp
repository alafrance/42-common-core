#ifndef Cat_HPP
#define Cat_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
public:
	Cat();
	Cat(Cat const& src);
	virtual ~Cat();
	virtual void	makeSound() const;
	Cat& operator=(Cat const& rhs);
	Brain*	getBrain() const ;
	void	setBrain(Brain* brain);
private:
	Brain*	_brain;
};

#endif