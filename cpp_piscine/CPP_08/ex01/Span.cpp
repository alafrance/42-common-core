#include "span.hpp"
#include <cstdlib>
#include <time.h>
#include <cmath>

/* CANONICAL FORM */
Span::Span(void): size(0){
}

Span::Span(unsigned int N): size(N){

}

Span::~Span(void){
}

Span::Span(Span const& src){
	*this = src;
}

void	Span::addNumber(int n) {
	if (nb.size() == size)
		throw FullInt;
	nb.push_back(n);
}

void	Span::addNumberRange(unsigned int range) {
	if (size < static_cast<unsigned int>(nb.size()) + range)
		throw FullInt;
	srand(static_cast<unsigned>(time(0)));
	for(unsigned int i = 0 ; i < range ; i++) {
		nb.push_back(rand());
	}
}

void	Span::addNumberRange(std::vector<int> &list) {
	if (size < nb.size() + list.size())
		throw FullInt;
	for(std::vector<int>::const_iterator i = list.begin(); i != list.end() ; i++) {
		nb.push_back(*i);
	}
}

int Span::shortestSpan() const {
	if (nb.size() <= 1)
		throw NoSpanToFind;

	std::vector<int> tmp = nb;
	std::vector<int>::iterator it = tmp.begin();
	std::sort(tmp.begin(), tmp.end());
	it++;
	int min = static_cast<int>(std::abs(*it - *(it - 1)));
	for (unsigned long i = 1 ; i < tmp.size() ; i++) {
		if (min > static_cast<int>(std::abs(*it - *(it - 1))))
			min = static_cast<int>(std::abs(*it - *(it - 1)));
		it++;
	}
	return (static_cast<int>(min));
}

int Span::longestSpan() const {
	if (nb.size() <= 1)
		throw NoSpanToFind;
	int min = *std::min_element(nb.begin(), nb.end());
	int max = *std::max_element(nb.begin(), nb.end());
	return (max - min);
}

Span&	Span::operator=(Span const& rhs){
	size = rhs.size;
	for(std::vector<int>::const_iterator i = rhs.nb.begin(); i != rhs.nb.end() ; i++)
		nb.push_back(*i);
	return *this;
}

/* ACCESSORS */
std::vector<int>	Span::getNb(void) const {
	return nb;
}

/* MAIN */