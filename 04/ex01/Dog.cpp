

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;	
}

Dog::Dog(std::string &type) : Animal(type) {
	brain = new Brain();
	std::cout << "Dog parameterized constructor called" << std::endl;	
}

Dog::Dog(const Dog &other) : Animal(other) {
	this->brain = new Brain(*(other.brain));
	std::cout << "Dog copy constructor called" << std::endl;	
}

Dog &Dog::operator=(const Dog &other) { 
	if (this != &other) {
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	std::cout << "Dog assigned" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;	
}

void	Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}
