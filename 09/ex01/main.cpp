#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return 1;
	}


	RPN rnp(av[1]);

	return 0;
}
