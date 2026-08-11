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
				std::cout << "Error: not enough numbers for operation" << std::endl;
				return;
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
					std::cout << "Error: division by zero" << std::endl;
					return;
				}
				numbs.push(b / a);
			}
		}
		else
		{
			std::cout << "Error: invalid character" << std::endl;
			return;
		}
	}

	if (numbs.size() != 1)
	{
		std::cout << "Error: invalid expression" << std::endl;
		return;
	}
	std::cout << numbs.top() << std::endl;
	return;
}
