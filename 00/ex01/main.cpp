

#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;

	std::cout << "Welcome the the Foking awsome Phone Book form 80's" << std::endl;
	std::cout << "The program only accepts ADD, SEARCH and EXIT." << std::endl;
	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display specific contact" << std::endl;
	
	while (1) {
		std::cin >> input;
		if (std::cin.fail())
			break ;
		if (input.compare("EXIT") == 0)
			break ;
		else if (input.compare("ADD") == 0)
			phoneBook.addContact();
		else if (input.compare("SEARCH") == 0)
			phoneBook.searchContact();
	}
	return 0;
}
