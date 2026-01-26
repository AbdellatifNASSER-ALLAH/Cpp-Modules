
#include <iostream>
#include "Bureaucrat.hpp"


int	main() {

	Bureaucrat	a;
	Bureaucrat	b("the one", 1);
	Bureaucrat	c("the C", 150);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	try {
		b.plusGrade();
	}catch(std::exception& e) {
		std::cout << "Exception Caught : " << e.what() << std::endl;
	}

	std::cout << b << std::endl;
	std::cout << c << std::endl;

	return (0);
}
