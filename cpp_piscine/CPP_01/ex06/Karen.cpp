#include "Karen.hpp"
#include <iostream>

Karen::Karen() {

}

Karen::~Karen() {

}

void Karen::debug(void) {
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info(void) {
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;	
}

void Karen::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error(void) {
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::display_level(std::string header, ptrMemFunc func) {
	std::cout << "[" << header << "]" << std::endl;
	(this->*func)();
	std::cout << std::endl; 
}

void Karen::complain( std::string level ) {

	int i = 0;
	std::string	level_string[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	ptrMemFunc level_fct[4] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	for ( i = 0 ; i < 4 ; i++){
		if (level == level_string[i])
			break;
	}
	switch (i)
	{
		case 0:
			display_level(level_string[0], level_fct[0]);
		case 1:
			display_level(level_string[1], level_fct[1]);
		case 2:
			display_level(level_string[2], level_fct[2]);
		case 3:
			display_level(level_string[3], level_fct[3]);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}