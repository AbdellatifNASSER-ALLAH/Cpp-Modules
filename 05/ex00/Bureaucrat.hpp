
#include <exception>
#include <string>

class	Bureaucrat {
	private:
		const std::string	_name;
		int			_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int& grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const	std::string	getName() const;
		const	int		getGrade() const;
		void	plusGrade() const;
		void	minusGrade() const;

	class	GradeTooHighException: public	std::exception {
		public:
			virtual	const	char* what() throw(){
				return ("Grade too high");
	};
	class	GradeTooLowException: public	std::exception { 
		public:
			virtual	const	char* what() throw(){
				return ("Grade too low");
	};
};

