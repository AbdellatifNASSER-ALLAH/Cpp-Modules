#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	// Test 1: Using an lvalue (variable). This compiles with 'int& find'.
	int target = 20;
	std::vector<int>::iterator it1 = easyfind(vec, target);
	if (it1 != vec.end())
		std::cout << "Test 1 - Found variable: " << *it1 << std::endl;

	// Test 2: Using an rvalue (literal). 
	std::vector<int>::iterator it2 = easyfind(vec, 30);
	if (it2 != vec.end())
		std::cout << "Test 2 - Found literal: " << *it2 << std::endl;

	// Test 3: not in the vector 
	std::vector<int>::iterator it3 = easyfind(vec, 32);
	if (it3 != vec.end())
		std::cout << "Test 3 - should now print this : " << *it3 << std::endl;

	return 0;
}
