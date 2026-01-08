

#ifndef WCAT_HPP
#define WCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class	WrongCat : public WrongAnimal {
	public: 
		WrongCat();
		WrongCat(std::string& type);
		WrongCat(const WrongCat& other);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat();

		void	makeSound() const;
};

#endif
