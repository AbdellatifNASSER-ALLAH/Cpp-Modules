
#ifndef FORM_HPP
#define FORM_HPP

#define RED "\033[31m"
#define RESET "\033[0m"

#include <exception>
#include <string>
#include <ostream>

class	Form {
	private:
		const std::string	_name;
		bool			_sign;
		const	int		_grade_sign;
		const	int		_grade_exec;

	public:
		Form();
		Form(const std::string& name, const bool sign, const int grade_sign, const int grade_exec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string	getName() const;
		bool			getSign() const;
		int		getGradeSign() const;
		int		getGradeExec() const;

		void	beSigned(const class Bureaucrat& obj);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
