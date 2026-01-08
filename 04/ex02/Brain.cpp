

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = "Brain idea";
	}
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	*this = other;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &other) { 
	if (this != &other) {
		for (int i = 0; i < 100; ++i) 
			this->setIdea(i, other.getIdea(i));
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Desconstructor called" << std::endl;
}

const std::string& Brain::getIdea(int index) const {
	if (index < 0 || index >= 100)
		return this->ideas[0];
	return this->ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}
