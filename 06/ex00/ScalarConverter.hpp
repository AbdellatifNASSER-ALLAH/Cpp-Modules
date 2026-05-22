
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		void	_printChar(const char c);
		void	_printInt(const int i);
		//void	_printFloat(const float f);
		//void	_printDouble(const double d);

	public:
		static	void	convert(const std::string& str);
};

#endif
