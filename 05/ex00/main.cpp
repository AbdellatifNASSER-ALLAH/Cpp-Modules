
#include <iostream>
#include "Bureaucrat.hpp"


int	main() {

	{
		Bureaucrat	a;
		Bureaucrat	b("the one", 1);
		Bureaucrat	c(b);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}

	return (0);
}
