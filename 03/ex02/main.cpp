#include "FragTrap.hpp"

int main() {
	std::cout << "--- Testing FragTrap ---" << std::endl;
	FragTrap frag("Fraggy");
	frag.attack("Target");
	frag.beRepaired(20);
	frag.highFivesGuys();
	frag.takeDamage(50);
	frag.takeDamage(60);
	frag.highFivesGuys(); // Still can talk even if dead? Usually yes in these exercises unless specified.

	std::cout << "\n--- Destructors ---" << std::endl;
	return 0;
}

