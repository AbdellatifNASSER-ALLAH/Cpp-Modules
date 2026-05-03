#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string& RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	this->checkRequirements(executor);
	
	std::cout << "* drrrrr drrrrrrrrrrr bzzzzzzz *" << std::endl;
	
	if (std::rand() % 2 == 0) {
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed on " << _target << "." << std::endl;
	}
}
