#ifndef	RPN_HPP
#define	RPN_HPP

#include <iostream>
#include <stack>

class	RPN {
	private:
		std::stack<int>	numbs;

		RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
	public:
		~RPN();
		RPN(const std::string &str);

};

#endif
