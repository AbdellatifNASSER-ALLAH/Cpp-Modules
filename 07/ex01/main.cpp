
#include "iter.hpp"
#include <climits>
#include <string>

template <typename T>
void	print(const T& a) {
	std::cout << a << " ";
}

template <typename T>
void	increment(T& x) {
	x++;
}

void	suffix(std::string &s) {
	s = s + "_suffix";
}

int main(void)
{
	std::string	str[5] = {"Hello", "World", "This", "Is", "Iter"};
	const	std::string str1[5] = {"Hello", "World", "This", "Is", "Iter"};
	int		arr[5] = {1, 2, 3, 4, 5};
	const int		arr1[5] = {1, 2, 3, 4, 5};

	iter(str, 5, print<std::string>);
	std::cout << std::endl;

	iter(str, 5, suffix);
	iter(str, 5, print<std::string>);
	std::cout << std::endl;

	iter(str1, 5, print<std::string>);
	std::cout << std::endl;

	iter(arr, 5, print<int>);
	std::cout << std::endl;

	iter(arr, 5, increment<int>);


	iter(arr, 5, print<int>);
	std::cout << std::endl;

	iter(arr1, 5, print<int>);
	std::cout << std::endl;
	return (0);
}
