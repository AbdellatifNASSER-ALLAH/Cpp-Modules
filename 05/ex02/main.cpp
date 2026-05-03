#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(NULL));

	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "[ TEST 1: ShrubberyCreationForm ]" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	try {
		Bureaucrat high("High", 1);
		Bureaucrat low("Low", 150);
		ShrubberyCreationForm form("Home");

		std::cout << form << std::endl;
		low.signForm(form); // Should fail
		high.executeForm(form); // Should fail (not signed)
		
		high.signForm(form); // Success
		low.executeForm(form); // Should fail (grade too low)
		high.executeForm(form); // Success
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n-------------------------------------------------------" << std::endl;
	std::cout << "[ TEST 2: RobotomyRequestForm ]" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	try {
		Bureaucrat middle("Middle", 50);
		RobotomyRequestForm form("Bender");

		std::cout << form << std::endl;
		middle.signForm(form); // Success
		middle.executeForm(form); // Success (50% chance of success)
		middle.executeForm(form); // Another try
		middle.executeForm(form); // Another try
		middle.executeForm(form); // Another try
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n-------------------------------------------------------" << std::endl;
	std::cout << "[ TEST 3: PresidentialPardonForm ]" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	try {
		Bureaucrat president("President", 1);
		Bureaucrat intern("Intern", 20);
		PresidentialPardonForm form("Arthur Dent");

		std::cout << form << std::endl;
		intern.signForm(form); // Success
		intern.executeForm(form); // Fail (grade too low to execute)
		president.executeForm(form); // Success
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
