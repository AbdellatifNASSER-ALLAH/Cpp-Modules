
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _sign(false), _grade_sign(150), _grade_exec(150) {}

Form::Form(const std::string& name, const bool sign, const int grade_sign, const int grade_exec) : _name(name), _sign(sign), _grade_sign(grade_sign), _grade_exec(grade_exec) {
	if (grade_sign < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : _name(other.getName()), _sign(other.getSign()), _grade_sign(other.getGradeSign()), _grade_exec(other.getGradeExec()) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		_sign = other.getSign();
	return (*this);
}

Form::~Form() {}

const std::string	Form::getName() const {	return (_name); }
bool			Form::getSign() const {	return (_sign); }
int		Form::getGradeSign() const { return (_grade_sign); }
int		Form::getGradeExec() const { return (_grade_exec); }

void	Form::beSigned(const Bureaucrat& obj) {
	if ( _grade_sign < obj.getGrade())
		throw Form::GradeTooLowException();
	_sign = true;
}

const	char* Form::GradeTooLowException::what() const throw() {
	return (RED "Grade too low" RESET);
}

const	char* Form::GradeTooHighException::what() const throw(){
	return (RED "Grade too high" RESET);
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << obj.getName() << ", form sign " << obj.getSign() << ", grade sign " << obj.getGradeSign() << ", grade exec " << obj.getGradeExec() << ".";
	return os;
}
