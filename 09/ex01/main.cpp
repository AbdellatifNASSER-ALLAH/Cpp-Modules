#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return 1;
	}

	try {
		RPN rnp(av[1]);
	} catch (const std::exception &e) {
		return 1;
	}

	return 0;
}
