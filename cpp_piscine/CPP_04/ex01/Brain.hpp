#ifndef Brain_HPP
#define Brain_HPP
#include <iostream>

class Brain {
public:
	Brain();
	Brain(Brain const& src);
	virtual ~Brain();

	void	setIdeas(std::string *ideas, int length);
	Brain& operator=(Brain const& rhs);
	void printIdeas(void) const;
private:
	std::string	_ideas[100];
};

#endif