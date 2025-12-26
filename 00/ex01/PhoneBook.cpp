

#include "PhoneBook.hpp"
#include <iomanip>
#include <ostream>

PhoneBook::PhoneBook() {
	count = 0;
}

PhoneBook::~PhoneBook() {
	//empty
}

void	PhoneBook::addContact() {
	Contact		newContact;
	std::string	str;

	std::cout << "First Name : ";
	std::getline(std::cin, str);
	if (str.empty()) { std::cout << "No empty fields ! " << std::endl; return;}
	newContact.setFirstName(str);

	std::cout << "Last Name : ";
	std::getline(std::cin, str);
	if (str.empty()) { std::cout << "No empty fields ! " << std::endl; return;}
	newContact.setLastName(str);

	std::cout << "Nickname : ";
	std::getline(std::cin, str);
	if (str.empty()) { std::cout << "No empty fields ! " << std::endl; return;}
	newContact.setNickname(str);

	std::cout << "Phone Number : ";
	std::getline(std::cin, str);
	if (str.empty()) { std::cout << "No empty fields ! " << std::endl; return;}
	newContact.setPhoneNumber(str);

	std::cout << "Darkest Secret : ";
	std::getline(std::cin, str);
	if (str.empty()) { std::cout << "No empty fields ! " << std::endl; return;}
	newContact.setDarkestSecret(str);

	contacts[ count % 8 ] = newContact;
	(count < 8) ? count++ : 0;
	std::cout << "Contact added" << std::endl;
}

std::string	PhoneBook::truncate(std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::displayTable() const {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < count; i++) {
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
	}
}

void	PhoneBook::searchContact() {
	int index, max;

	if (count == 0) {
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	displayTable();

	std::cout << "Enter index: ";
	std::cin >> index;
	--index;

	max = (count < 8) ? count : 8;
	if (index < 0 || index >= max) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
