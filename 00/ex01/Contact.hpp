

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
	private:
		std::string	first_name = "";
		std::string	last_name = "";
		std::string	darkest_secret = "";
		int		phone_number = 0;

	public:
		Contact();
		~Contact();
};

#endif
