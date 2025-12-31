
#include "Harl.hpp"
#include <iostream>

void	Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
}

void	Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
}

void	Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
}

void 	Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
}

void	Harl::complain(const std::string& level) {
	void	(Harl::*funcs[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string	levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i < 4; i++)
		if (level == levels[i])
			this->*(funcs[i])();

}
