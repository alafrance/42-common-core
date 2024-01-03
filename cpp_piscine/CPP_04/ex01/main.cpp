#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Brain	*brain1 = new Brain();
	Brain	*brain2 = new Brain();
	std::string	*ideas = new std::string[4];

	/* INIT IDEAS, BRAIN AND DOG */
	ideas[0] = "coucou";
	ideas[1] = "je";
	ideas[2] = "pense";
	ideas[3] = "beaucoup";
	brain1->setIdeas(ideas, 4);
	brain2->setIdeas(ideas, 4);
	Dog dog;
	dog.setBrain(brain1);
	dog.getBrain()->printIdeas();

	{
		/* DEEP COPY */
		Dog dog2 = dog;
		/* CHANGE IDEAS TO SEE DEEP COPY */
		ideas[0] = "hello";
		brain2->setIdeas(ideas, 4);
		dog.setBrain(brain2);
		/* DISPLAY THE IDEAS */
		dog2.getBrain()->printIdeas();
		dog.getBrain()->printIdeas();
	}

	delete[] ideas;
}