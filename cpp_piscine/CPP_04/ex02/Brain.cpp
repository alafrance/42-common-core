#include "Brain.hpp"

/* CANONICAL FORM */
Brain::Brain(void){
	std::cout << "Default constructor called (Brain)\n";
}

Brain::~Brain(void){
	std::cout << "Destructor called (Brain)\n";
}

Brain::Brain(Brain const& src){
	*this = src;
}

Brain&	Brain::operator=(Brain const& rhs){
	for (int i = 0; i < 100; ++i) {
		_ideas[i] = rhs._ideas[i];
	}
	return *this;
}
/* ACCESSORS */

void Brain::printIdeas(void) const {
	std::cout << _ideas[0] << std::endl;
}

void	Brain::setIdeas(std::string *ideas, int length) {
	for (int i = 0 ; i < length && i < 100 ; i++) {
		_ideas[i] = ideas[i]; 
	}
}
/* MAIN */