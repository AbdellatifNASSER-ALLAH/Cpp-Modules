

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
	public: 
		Dog();
		Dog(std::string& type);
		Dog(const Dog& other);
		Dog &operator=(const Dog &other);
		virtual ~Dog();

		virtual void	makeSound() const;
		const std::string&	getIdea(int index) const;
		void				setIdea(int index, const std::string& idea);
	private:
		Brain	*brain;
};

#endif
