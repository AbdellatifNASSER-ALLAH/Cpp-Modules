
#ifndef INTERN_H
#define INTERN_H

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class	Intern {
	private:
		AForm*	_createShrubbery(const std::string& target);
		AForm*	_createRobotomy(const std::string& target);
		AForm*	_createPardon(const std::string& target);
		typedef AForm* (Intern::*formCreators)(const std::string &);

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();
		
		AForm*	makeForm(const std::string& name, const std::string& target);
};

#endif
