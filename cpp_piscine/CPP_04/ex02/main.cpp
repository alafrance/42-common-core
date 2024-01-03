#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main()
{
	AAnimal *cat = new Cat();
	std::cout << cat->getType() << std::endl;
	/* It shouldn't works */
	// AAnimal *animal = new AAnimal();
	std::cout << "No instance possible for abstract class\n";
	delete cat;
}