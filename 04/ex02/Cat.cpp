
#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;	
}

Cat::Cat(std::string &type) : Animal(type) {
	brain = new Brain();
	std::cout << "Cat parameterized constructor called" << std::endl;	
}

Cat::Cat(const Cat &other) : Animal(other) {
	this->brain = new Brain(*(other.brain));
	std::cout << "Cat copy constructor called" << std::endl;	
}

Cat &Cat::operator=(const Cat &other) { 
	if (this != &other) {
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*(other.brain));
	}
	std::cout << "Cat assigned" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;	
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

const std::string& Cat::getIdea(int index) const {
	return this->brain->getIdea(index);
}

void Cat::setIdea(int index, const std::string& idea) {
	this->brain->setIdea(index, idea);
}
