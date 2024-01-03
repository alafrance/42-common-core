#include <iostream>
#include "easyfind.hpp"

int main() {
	std::list<int>  mylist;
	for (int i = 0; i < 10; i++)
		mylist.push_back(i);
	try {
		std::list<int>::iterator it = easyfind(mylist, 5);
		std::cout << *it << std::endl;
		it = easyfind(mylist, 1);
		std::cout << *it << std::endl;
		it = easyfind(mylist, 11);
		std::cout << *it << std::endl;
	}
	catch(NotFindException& e) {
		std::cout << e.what() << std::endl;
	}

}
