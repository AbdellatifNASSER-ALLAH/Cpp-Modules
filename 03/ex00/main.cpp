#include <iostream>
#include "ClapTrap.hpp"

int main() {
    std::cout << "=== Test 1: Construction & Basic Actions ===" << std::endl;
    ClapTrap hero("Hero");
    ClapTrap villain("Villain");

    hero.attack("Villain");
    villain.takeDamage(0); // Damage is 0 by default for ClapTrap
    villain.beRepaired(5);

    std::cout << "\n=== Test 2: Energy Exhaustion ===" << std::endl;
    ClapTrap tired("Tired");
    // ClapTrap has 10 Energy Points. Let's use them all.
    for (int i = 0; i < 10; ++i) {
        tired.attack("Dummy");
    }
    std::cout << "--- Should fail now ---" << std::endl;
    tired.attack("Dummy");
    tired.beRepaired(10);

    std::cout << "\n=== Test 3: Taking Fatal Damage ===" << std::endl;
    ClapTrap victim("Victim");
    victim.takeDamage(5);
    victim.takeDamage(5); // HP should be 0 now
    std::cout << "--- Should fail now (Dead) ---" << std::endl;
    victim.attack("Ghost");
    victim.beRepaired(5);

    std::cout << "\n=== Test 4: Copy & Assignment ===" << std::endl;
    ClapTrap original("Original");
    ClapTrap copy(original);
    ClapTrap assigned("Assigned");
    assigned = original;

    std::cout << "\n=== Destruction Phase ===" << std::endl;
    return 0;
}