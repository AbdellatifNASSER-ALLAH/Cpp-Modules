

#include <iostream>
#include "Zombie.hpp"

int	main() {

	Zombie *hored = zombieHorde(5, "Zed");
	for (int i = 0; i < 5; i++)
		hored[i].announce();
	delete[] hored;
	return 0;
}
