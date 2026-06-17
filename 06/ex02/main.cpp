#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int r = std::rand() % 3;
	if (r == 0)
	{
		std::cout << "Generated: A" << std::endl;
		return new A();
	}
	else if (r == 1)
	{
		std::cout << "Generated: B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Generated: C" << std::endl;
		return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (...) {}
}

int main()
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Test " << i + 1 << ":" << std::endl;
		Base* p = generate();
		
		std::cout << "Identify by pointer: ";
		identify(p);
		
		std::cout << "Identify by reference: ";
		identify(*p);
		
		delete p;
		std::cout << "--------------------" << std::endl;
	}

	return 0;
}
