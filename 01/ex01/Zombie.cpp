

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	std::cout << "Zombie Constructor." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie Destructor." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name){
	_name = name;
}
