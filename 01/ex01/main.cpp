

#include "Zombie.hpp"

int	main() {

	Zombie *hored = zombieHorde(5, "!!ZombiezzzZ!!");
	for (int i = 0; i < 5; i++)
		hored[i].announce();
	delete[] hored;
	return 0;
}
