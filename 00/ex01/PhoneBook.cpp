

#include "PhoneBook.hpp"
#include <string>

PhoneBook::PhoneBook() {
	//empty
}

PhoneBook::~PhoneBook() {
	//empty
}

void	PhoneBook::addContact() {
	Contact		newContact;
	std::string	str;
	
	std::cout << "First Name :";
	std::cin >> str;
	newContact.setFirstName(str);
	std::cout << "Last Name :";
	std::cin >> str;
	newContact.setLastName(str);
	std::cout << "Nickname :";
	std::cin >> str;
	newContact.setNickname(str);
	std::cout << "Phone Number :";
	std::cin >> str;
	newContact.setPhoneNumber(str);
	std::cout << "Darkest Secret :";
	std::cin >> str;
	newContact.setDarkestSecret(str);
}

void	PhoneBook::searchContact() {
	//body 
}
