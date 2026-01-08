
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class	Animal {
	protected:
		std::string	type;
	public: 
		Animal();
		Animal(std::string& type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual	~Animal();

		virtual void	makeSound(void) const = 0;
		std::string	getType(void) const;
};

#endif 
