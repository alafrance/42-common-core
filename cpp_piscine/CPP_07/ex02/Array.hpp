//
// Created by Alexis Lafrance on 9/30/21.
//

#ifndef EX02_ARRAY_HPP
#define EX02_ARRAY_HPP
#include <iostream>

template<typename T>
class Array
{
private:
	T *array;
	unsigned int n;
public:
	// CONSTRUCTOR
	Array() {
		array = new T;
		n = 0;
	};
	Array(Array const &src): n(src.n) {
		array = new T[n];
		*this = src;
	}
	explicit Array(unsigned int n ) : n(n) {
		array = new T[n];
		for (unsigned int i = 0; i < n; ++i) {
			array[i] = 0;
		}
	};
	// DESTRUCTOR
	virtual ~Array() {
		delete[]  array;
	};
	//OPERATOR
	Array &operator=(Array const &inst) {
		for (unsigned int i = 0 ; i < n ; i++) {
			array[i] = inst.array[i];
		}
		return (*this);
	};
	T&	operator[](unsigned int index) {
		if (index >= n)
			throw incorrectIndex;
		return array[index];
	}
	// UTILITY
	unsigned int size() {
		return n;
	}
	// EXCEPTION
	class IncorrectIndexException : public std::exception {
	public:
		const char * what () const throw ()
		{
			return "Wrong Index. Please try again";
		}
	} incorrectIndex;
};
#endif //EX02_ARRAY_HPP
