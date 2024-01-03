#ifndef AAnimal_HPP
#define AAnimal_HPP
#include <iostream>
class AAnimal {
public:
	AAnimal();
	AAnimal(AAnimal const& src);
	virtual ~AAnimal();

	AAnimal& operator=(AAnimal const& rhs);
	virtual	void	makeSound() const = 0;
	std::string		getType() const;
protected:
	std::string _type;
};

#endif