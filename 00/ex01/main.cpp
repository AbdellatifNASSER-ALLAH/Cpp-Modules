

#include "PhoneBook.hpp"
#include <iostream>
#include <climits>

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;

	std::cout << "Welcome to the Awseome Phone Book form the 80's" << std::endl;
	std::cout << "The program only accepts ADD, SEARCH and EXIT." << std::endl;
	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display specific contact" << std::endl;
	
	while (1) {
		std::cin >> input;
		std::cin.ignore(LONG_MAX, '\n');
		if (std::cin.fail())
			break ;
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
	}
	return 0;
}
