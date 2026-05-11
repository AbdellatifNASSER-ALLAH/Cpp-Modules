
#include "Intern.hpp"

Intern::Intern() { std::cout << "Intern default constructor called" << std::endl; }

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) { 
	if (this != &other)
		(void)other;
	return *this; 
}

Intern::~Intern() { std::cout << "Intern destructor called" << std::endl; }

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	std::string	formNames[] = { "robotomy request","presidential pardon", "shrubbery creation" };
	Intern::formCreators	functions[] = { &Intern::_createRobotomy , &Intern::_createPardon, &Intern::_createShurbbery };

	for(int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*functions[i])(target);
		}
	}
	std::cout << "Error: Form name '" << name << "' not found." << std::endl;
	return NULL;
}
