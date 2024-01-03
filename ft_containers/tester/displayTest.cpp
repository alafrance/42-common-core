//
// Created by Alexis Lafrance on 12/9/21.
//
#include "tester.hpp"
#include <iostream>

static int countTest = 1;
void displayTestOk(std::string msg) {
	std::cout << GREEN << "✅️️️ " << countTest++ << " OK : " << msg << RESET << std::endl;
	global_error = 0;
}

void displayTestError(std::string msg) {
	std::cout << RED << "🔴" << countTest++ << "ERROR : " << msg << RESET << std::endl;
	global_error = 0;
}

void displayPart(std::string msg) {
	std::cout << BLUE << "------------------- " << msg << " -------------------" << RESET << std::endl;
}
