

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() {
	count = 0;
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

	contacts[ count % 8 ] = newContact;
	count++;
	std::cout << "Contacted Added" << std::endl;
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

	int max = (count < 8) ? count : 8;
	for (int i = 0; i < max; i++) {
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
	}
}

void	PhoneBook::searchContact() {
	if (count == 0) {
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	displayTable();
	
	std::cout << "Enter index: ";
	int index;
	std::cin >> index;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	int max = (count < 8) ? count : 8;
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
