#include "span.hpp"
#include <iostream>

#define SIZE_SPAN 42000
int main() {
	Span sp(SIZE_SPAN);
	srand(static_cast<unsigned>(time(0)));
	
	// TEST SHORTEST AND LONGEST SPAN
	try {
		sp.addNumberRange(SIZE_SPAN);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(Span::FullIntException& e) {
		std::cout << e.what() << std::endl;
	}
	catch(Span::NoSpanToFindException& e) {
		std::cout << e.what() << std::endl;
	}

	// TEST SHORTEST AND LONGEST SPAN
	try {
		Span sp2(SIZE_SPAN);
		std::vector<int> vec = sp.getNb();
		sp2.addNumberRange(vec);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(Span::FullIntException& e) {
		std::cout << e.what() << std::endl;
	}
	catch(Span::NoSpanToFindException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Span sp3(5);

		sp3.addNumber(5);
		sp3.addNumber(3);
		sp3.addNumber(17);
		sp3.addNumber(9);
		sp3.addNumber(11);
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch(Span::FullIntException& e) {
		std::cout << e.what() << std::endl;
	}
	catch(Span::NoSpanToFindException& e) {
		std::cout << e.what() << std::endl;
	}
	// // TEST ADD CLASS FULL
	try {
		std::cout << "ERROR TEST : \n";
		Span sp3(6);

		std::cout << sp3.shortestSpan() << std::endl;
		sp3.addNumber(5);
		sp3.addNumber(3);
		sp3.addNumber(120);
		sp3.addNumber(4);
		sp3.addNumber(4);
		sp3.addNumber(4);
		sp3.addNumber(4);
		sp3.addNumber(4);
		sp3.addNumber(4);
		sp3.addNumber(4);
		sp3.addNumber(4);
	}
	catch(Span::FullIntException& e) {
		std::cout << e.what() << std::endl;
	}
	catch(Span::NoSpanToFindException& e) {
		std::cout << e.what() << std::endl;
	}

	// TEST ADD CLASS FULL
	try {
		Span sp4(2);
		std::vector<int> vec = sp.getNb();
		sp4.addNumberRange(vec);
	}
	catch(Span::FullIntException& e) {
		std::cout << e.what() << std::endl;
	}
	catch(Span::NoSpanToFindException& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
