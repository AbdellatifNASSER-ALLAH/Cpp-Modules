
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <string>
#include <iostream>

class	PhoneBook {
	private:
		Contact contacts[8];
		int	count;
		int	max;
		std::string	truncate(std::string str) const;
		void		displayTable() const;

	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	searchContact();
};

#endif 
