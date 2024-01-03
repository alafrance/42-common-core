#ifndef Dog_HPP
#define Dog_HPP
#include "Brain.hpp"
#include "AAnimal.hpp"
class Dog: public AAnimal {
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