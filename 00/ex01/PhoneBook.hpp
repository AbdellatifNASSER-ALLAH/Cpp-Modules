
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class	PhoneBook {
	private:
		Contact contacts[8];
		int	count = 0;

	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	searchContact();
};

#endif 
