
#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;	
}

WrongCat::WrongCat(std::string &type) : WrongAnimal(type) {
	std::cout << "WrongCat parameterized constructor called" << std::endl;	
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;	
}

WrongCat &WrongCat::operator=(const WrongCat &other) { 
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "WrongCat assigned" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;	
}

void	WrongCat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}
