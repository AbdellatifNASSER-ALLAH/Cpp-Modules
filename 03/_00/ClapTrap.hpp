

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class	ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap &operator=(const ClapTrap& other);
		~ClapTrap();

	private:
		std::string	name;
                unsigned int hitPoints;
                unsigned int energyPoints;
                unsigned int attackDamage;
};

#endif
