#ifndef	RPN_HPP
#define	RPN_HPP

#include <iostream>
#include <stack>
#include <exception>

class	RPN {
	private:
		std::stack<int>	numbs;

		RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
	public:
		~RPN();
		RPN(const std::string &str);

		class RPNException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "RPN Error";
				}
		};
};

#endif
