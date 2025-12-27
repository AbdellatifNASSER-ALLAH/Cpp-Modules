#include "Zombie.hpp"

int main() {
	int N = 5;
	
	std::cout << "=== Creating a horde of " << N << " zombies ===" << std::endl;
	Zombie* horde = zombieHorde(N, "HordeZombie");
	
	std::cout << "\n=== Announcing all zombies ===" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}
	
	std::cout << "\n=== Destroying the horde ===" << std::endl;
	delete[] horde;
	
	std::cout << "\n=== Program ending ===" << std::endl;
	return 0;
}
