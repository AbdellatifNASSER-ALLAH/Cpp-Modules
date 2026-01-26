
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

class	Bureaucrat {
	private:
		const std::string	_name;
		int			_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int	grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const	std::string	getName() const;
		int	getGrade() const;
		void	plusGrade(); 
		void	minusGrade();

		class	GradeTooHighException: public	std::exception {
			public:
				virtual	const	char* what() const throw(){
					return (RED"Grade too high" RESET);
				}
		};
		class	GradeTooLowException: public	std::exception { 
			public:
				virtual	const	char* what() const throw(){
					return (RED"Grade too low" RESET);
				}
		};
};

std::ostream& operator<< (std::ostream& os, const Bureaucrat& obj);

#endif
