#ifndef ITER
#define ITER
#include <iostream>
template<typename T>
void iter(T *array, size_t const &length, void(*fct)(T const&)) {
	for (size_t i = 0; i < length; i++) {
		(*fct)(array[i]);
	}
}
#endif