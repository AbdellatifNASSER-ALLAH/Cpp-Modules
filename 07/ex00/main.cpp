#include "whatever.hpp"
#include <iostream>

int	main() {
	{
		int a = 1, b = 3;
		std::cout << "Integers a = " << a << " b = " << b << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		::swap(a, b);
		std::cout << "After swap: a = " << a << " b = " << b << std::endl;
	}
	{
		std::cout << "-----------------------" << std::endl;
		std::string a = "Hello", b = "World";
		std::cout << "Strings a = " << a << " b = " << b << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		::swap(a, b);
		std::cout << "After swap: a = " << a << " b = " << b << std::endl;
	}
	{
		std::cout << "-----------------------" << std::endl;
		float a = 1.5f, b = 2.5f;
		std::cout << "Floats a = " << a << " b = " << b << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		::swap(a, b);
		std::cout << "After swap: a = " << a << " b = " << b << std::endl;
	}
	{
		std::cout << "-----------------------" << std::endl;
		double a = 3.14, b = 2.71;
		std::cout << "Doubles a = " << a << " b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		::swap(a, b);
		std::cout << "After swap: a = " << a << " b = " << b << std::endl;
	}
	{
		std::cout << "-----------------------" << std::endl;
		char a = 'A', b = 'Z';
		std::cout << "Chars a = " << a << " b = " << b << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		::swap(a, b);
		std::cout << "After swap: a = " << a << " b = " << b << std::endl;
	}
	{
		std::cout << "-----------------------" << std::endl;
		bool a = true, b = false;
		std::cout << "Bools a = " << a << " b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		::swap(a, b);
		std::cout << "After swap: a = " << a << " b = " << b << std::endl;
	}
	{
		std::cout << "-----------------------" << std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << "-----------------------" << std::endl;
		std::cout << "Testing 'Equal Values Return Second Parameter' Requirement:" << std::endl;
		int x = 42;
		int y = 42;
		const int& r_min = ::min(x, y);
		const int& r_max = ::max(x, y);
		std::cout << "Address of x: " << &x << std::endl;
		std::cout << "Address of y: " << &y << std::endl;
		std::cout << "Address of min(x, y) result: " << &r_min << std::endl;
		std::cout << "Address of max(x, y) result: " << &r_max << std::endl;
		if (&r_min == &y && &r_max == &y) {
			std::cout << "SUCCESS: Both min and max returned the second parameter (y)!" << std::endl;
		} else {
			std::cout << "FAILURE: Did not return the second parameter!" << std::endl;
		}
	}
	return 0;
}
