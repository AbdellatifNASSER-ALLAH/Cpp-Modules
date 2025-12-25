

#include "Contact.hpp"

Contact::Contact() {
	first_name = "";
	last_name = "";
	nick_name = "";
	phone_number = "";
	darkest_secret = "";
}

Contact::~Contact() {
}

// Setters
void Contact::setFirstName(std::string firstName) {
	first_name = firstName;
}

void Contact::setLastName(std::string lastName) {
	last_name = lastName;
}

void	Contact::setNickname(std::string nickname) {
	nick_name = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	phone_number = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	darkest_secret = darkestSecret;
}

// Getters
std::string Contact::getFirstName() const {
	return first_name;
}

std::string Contact::getLastName() const {
	return last_name;
}

std::string Contact::getNickname() const {
	return nick_name;
}

std::string Contact::getPhoneNumber() const {
	return phone_number;
}

std::string Contact::getDarkestSecret() const {
	return darkest_secret;
}
