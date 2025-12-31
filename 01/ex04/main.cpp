

#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "Usage: " << av[0] << " <filename> <replace> <with>" << std::endl;
		return 1;
	}
}
