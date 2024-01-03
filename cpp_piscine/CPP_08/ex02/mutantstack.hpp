#ifndef MutantStack_HPP
#define MutantStack_HPP
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <stack>
template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
private:
public:
	MutantStack(): std::stack<T, Container>() {}
	MutantStack(MutantStack const& src): std::stack<T, Container>() { *this = src; }
	virtual ~MutantStack() {}
	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
	iterator begin() {return this->c.begin();};
	iterator end() {return this->c.end();};
	reverse_iterator rbegin() {return this->c.rbegin();};
	reverse_iterator rend() {return this->c.rend();};
	const_iterator cbegin() {return this->c.cbegin();};
	const_iterator cend() {return this->c.cend();};
	const_reverse_iterator crbegin() {return this->c.crbegin();};
	const_reverse_iterator crend() {return this->c.crend();};
	MutantStack& operator=(MutantStack const& rhs) { std::stack<T>::operator=(rhs); return (*this);}
};

#endif