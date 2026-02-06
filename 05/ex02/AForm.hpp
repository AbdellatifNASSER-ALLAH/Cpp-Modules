
#ifndef AFORM_HPP
#define AFORM_HPP

#include <cstdio>
#define RED "\033[31m"
#define RESET "\033[0m"

#include <exception>
#include <string>
#include <ostream>

class	Bureaucrat;

class	AForm {
	private:
		const std::string	_name;
		bool			_sign;
		const	int		_grade_sign;
		const	int		_grade_exec;

	public:
		AForm();
		AForm(const std::string& name, const bool sign, const int grade_sign, const int grade_exec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual	~AForm();

		virtual	void	execute(Bureaucrat const& executer) const = 0;

		const std::string	getName() const;
		bool			getSign() const;
		int		getGradeSign() const;
		int		getGradeExec() const;

		void	beSigned(const Bureaucrat& obj);

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
