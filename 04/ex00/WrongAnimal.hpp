
#ifndef WANIMAL_HPP
#define WANIMAL_HPP

#include <string>

class	WrongAnimal {
	protected:
		std::string	type;
	public: 
		WrongAnimal();
		WrongAnimal(std::string& type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		virtual	~WrongAnimal();

		void	makeSound(void) const;
		std::string	getType(void) const;
};

#endif 
