#include <iostream>
#include "mutantstack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(20);
	std::cout << "TOP : " <<  mstack.top() << std::endl;
	mstack.pop();
	std::cout << "SIZE: " << mstack.size() << std::endl;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "--- BEGIN TO END --- \n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "--- REVERSE MODE --- \n";
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	while (rit != rite) {
		std::cout << *rit << std::endl;
		rit++;
	}

	std::cout << "--- CONST ITERATOR MODE --- \n";
	MutantStack<int>::const_iterator cst_it = mstack.cbegin();
	MutantStack<int>::const_iterator cst_ite = mstack.cend();
	while (cst_it != cst_ite) {
		std::cout << *cst_it << std::endl;
		cst_it++;
	}
	std::cout << "SIZE: " << mstack.size() << std::endl;
	return 0;
}