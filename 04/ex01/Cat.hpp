

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {
	public: 
		Cat();
		Cat(std::string& type);
		Cat(const Cat& other);
		Cat &operator=(const Cat &other);
		virtual ~Cat();

		virtual void	makeSound() const;
	private:
		Brain	*brain;
};

#endif
