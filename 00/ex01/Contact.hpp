

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	darkest_secret;
		std::string	phone_number;

	public:
		Contact();
		~Contact();
		
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickname(std::string lastName);
		void setPhoneNumber(std::string phoneNumber);
		void setDarkestSecret(std::string darkestSecret);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};

#endif
