
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Default"), _sign(false), _grade_sign(150), _grade_exec(150) {}

AForm::AForm(const std::string& name, const bool sign, const int grade_sign, const int grade_exec) : _name(name), _sign(sign), _grade_sign(grade_sign), _grade_exec(grade_exec) {
	if (grade_sign < 1 || grade_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other.getName()), _sign(other.getSign()), _grade_sign(other.getGradeSign()), _grade_exec(other.getGradeExec()) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		_sign = other.getSign();
	return (*this);
}

AForm::~AForm() {}

const std::string	AForm::getName() const {	return (_name); }
bool			AForm::getSign() const {	return (_sign); }
int		AForm::getGradeSign() const { return (_grade_sign); }
int		AForm::getGradeExec() const { return (_grade_exec); }

void	AForm::beSigned(const Bureaucrat& obj) {
	if ( _grade_sign < obj.getGrade())
		throw AForm::GradeTooLowException();
	_sign = true;
}

const	char* AForm::GradeTooLowException::what() const throw() {
	return (RED "Grade too low" RESET);
}

const	char* AForm::GradeTooHighException::what() const throw(){
	return (RED "Grade too high" RESET);
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << obj.getName() << ", form sign " << obj.getSign() << ", grade sign " << obj.getGradeSign() << ", grade exec " << obj.getGradeExec() << ".";
	return os;
}
