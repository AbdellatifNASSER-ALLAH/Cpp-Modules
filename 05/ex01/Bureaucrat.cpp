

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other.getName()), _grade(other.getGrade()) {}

Bureaucrat&  Bureaucrat::operator=(const Bureaucrat& other) {
	if (this !=  &other)
		_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const	std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return  _grade;
}

void	Bureaucrat::plusGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}
void	Bureaucrat::minusGrade() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

std::ostream& operator<< (std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}
