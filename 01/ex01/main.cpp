

#include "Zombie.hpp"

int	main() {
	int		N = 5;
	Zombie *hored = zombieHorde(N, "!!ZombiezzzZ!!");
	for (int i = 0; i < N; i++)
		hored[i].announce();
	delete[] hored;
	return 0;
}
