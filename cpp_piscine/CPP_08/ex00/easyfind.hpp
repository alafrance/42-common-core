#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class NotFindException: public std::exception {
public:
	const char* what() const throw () {
		return "Error : Find anything. Please try again";
	}
} NotFind;

template<typename T>
typename T::iterator	easyfind(T tofind, int index) {
	typename T::iterator it;
	it = std::find(tofind.begin(), tofind.end(), index);
	if (it == tofind.end())
		throw NotFind;
	return it;
}
#endif