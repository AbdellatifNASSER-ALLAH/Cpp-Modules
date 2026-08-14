#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src) {
    this->numbs = src.numbs;
}

RPN &RPN::operator=(const RPN &src) {
    if (this != &src) {
	this->numbs = src.numbs;
    }
    return *this;
}

RPN::~RPN() {}

RPN::RPN(const std::string &str)
{
	int a, b;

	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == ' ')
			continue;

		if (str[i] >= '0' && str[i] <= '9')
		{
			numbs.push(str[i] - '0');
		}
		else if (str[i] == '+' || str[i] == '-' ||
				str[i] == '*' || str[i] == '/')
		{
			if (numbs.size() < 2)
			{
				std::cerr << "Error: not enough numbers for operation" << std::endl;
				throw RPNException();
			}

			a = numbs.top();
			numbs.pop();

			b = numbs.top();
			numbs.pop();

			if (str[i] == '+')
				numbs.push(b + a);
			else if (str[i] == '-')
				numbs.push(b - a);
			else if (str[i] == '*')
				numbs.push(b * a);
			else if (str[i] == '/')
			{
				if (a == 0)
				{
					std::cerr << "Error: division by zero" << std::endl;
					throw RPNException();
				}
				numbs.push(b / a);
			}
		}
		else
		{
			std::cerr << "Error: invalid character" << std::endl;
			throw RPNException();
		}
	}

	if (numbs.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		throw RPNException();
	}
	std::cout << numbs.top() << std::endl;
	return;
}
