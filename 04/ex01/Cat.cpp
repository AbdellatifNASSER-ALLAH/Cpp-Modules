
#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;	
}

Cat::Cat(std::string &type) : Animal(type) {
	std::cout << "Cat parameterized constructor called" << std::endl;	
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;	
}

Cat &Cat::operator=(const Cat &other) { 
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat assigned" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;	
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}
