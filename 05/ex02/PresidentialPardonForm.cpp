#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", false, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other.getTarget();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string& PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	this->checkRequirements(executor);
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
