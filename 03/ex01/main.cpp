#include "ScavTrap.hpp"

int main() {
	std::cout << "--- Testing ClapTrap ---" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("Target");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n--- Testing ScavTrap ---" << std::endl;
	ScavTrap scav("Scavvy");
	scav.attack("Another Target");
	scav.beRepaired(20);
	scav.guardGate();
	scav.takeDamage(150);
	scav.attack("Target"); // Should fail (no hit points)

	std::cout << "\n--- Testing Copy and Assignment ---" << std::endl;
	ScavTrap scavCopy(scav);
	ScavTrap scavAssign("Assignee");
	scavAssign = scav;

	std::cout << "\n--- Destructors ---" << std::endl;
	return 0;
}