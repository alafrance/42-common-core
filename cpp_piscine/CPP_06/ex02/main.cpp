#include <iostream>

class Base { public:virtual ~Base() {}};
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void) {
	int result = rand() % 3;
	if (result == 0)
		return (new A);
	else if (result == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	std::cout << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch (std::exception &b) {
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
	}
	catch (std::exception &b) {
	}
	try {
		(void)dynamic_cast<C&>(p);
			std::cout << "C";
	}
	catch (std::exception& b) {
	}
	std::cout << std::endl;
}

int main() {
	srand(static_cast<unsigned>(time(0)));
	Base * g = generate();
	identify(*g);
	identify(g);
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
}