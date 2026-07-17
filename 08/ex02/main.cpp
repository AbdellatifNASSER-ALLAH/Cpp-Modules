#include <iostream>
#include "MutantStack.hpp"

void test_basic();
void test_iteration();

int	main() {
	void test_basic();
	void test_iteration();
	return 0;
}

void test_basic()
{
	std::stack<int> st;
	MutantStack<int> mst;

	// push
	for (int i = 1; i <= 5; ++i)
	{
		st.push(i);
		mst.push(i);
	}

	// top
	std::cout << "Top std: " << st.top() << std::endl;
	std::cout << "Top mst: " << mst.top() << std::endl;

	// size
	std::cout << "Size std: " << st.size() << std::endl;
	std::cout << "Size mst: " << mst.size() << std::endl;

	// pop
	st.pop();
	mst.pop();

	std::cout << "After pop:\n";
	std::cout << "Top std: " << st.top() << std::endl;
	std::cout << "Top mst: " << mst.top() << std::endl;

	// empty
	std::cout << "Empty std: " << st.empty() << std::endl;
	std::cout << "Empty mst: " << mst.empty() << std::endl;

	// clear all
	while (!st.empty())
		st.pop();
	while (!mst.empty())
		mst.pop();

	std::cout << "After clearing:\n";
	std::cout << "Empty std: " << st.empty() << std::endl;
	std::cout << "Empty mst: " << mst.empty() << std::endl;
}

void test_iteration()
{
	MutantStack<int> mst;

	for (int i = 1; i <= 5; ++i)
		mst.push(i);

	std::cout << "Iterating mst: ";
	MutantStack<int>::iterator it = mst.begin();
	MutantStack<int>::iterator ite = mst.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
} 
