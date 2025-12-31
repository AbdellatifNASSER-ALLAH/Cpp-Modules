

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}
HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void	HumanB::attack() const {
	std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
}
