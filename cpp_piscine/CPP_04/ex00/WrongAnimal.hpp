#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP
#include <iostream>
class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const& src);
	virtual ~WrongAnimal();

	WrongAnimal& operator=(WrongAnimal const& rhs);
	void	makeSound() const;
	std::string		getType() const;
protected:
	std::string _type;
};

#endif