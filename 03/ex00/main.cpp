

#include <iostream>
#include "ClapTrap.hpp"
	

int main() {
    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trapster");

    clap1.attack("Trapster");
    clap2.takeDamage(5);
    clap2.beRepaired(3);

    clap1.attack("Trapster");
    clap2.takeDamage(5);
    clap2.beRepaired(10);

    return 0;
}
