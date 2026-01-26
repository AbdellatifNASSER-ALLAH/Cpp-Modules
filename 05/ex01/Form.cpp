
#include "Form.hpp"

const	char* Form::GradeTooLowException::what() const throw() {
	return (RED "Grade too low" RESET);
}

const	char* Form::GradeTooHighException::what() const throw(){
	return (RED "Grade too high" RESET);
}


std::ostream& operator<< (std::ostream& os, const Form& obj) {
	return os;
}
