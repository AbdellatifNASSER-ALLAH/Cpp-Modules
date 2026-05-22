#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str) {
	ScalarConverter	convert;

	// TODO: Implement robust C++98 type detection and conversion
	// TODO: Handle special literals (nan, nanf, +inf, etc.)
	if (str.length() == 1 && !isdigit(str[0])) {
		convert._printChar(str[0]);
	} else if (str.find('.') != std::string::npos) {
		if (str[str.length() - 1 ] == 'f') {
			// convert._printfloat(str);
		} else {
			// convert._printDouble(str);
		}
	} else if (str.find_first_not_of("0123456789") == std::string::npos) {
		// TODO: Replace C++11 std::stoi with C++98 compatible conversion
		//convert._printInt(str);
	} else {
		std::cout << "char	: Impossible" << std::endl;
		std::cout << "int	: Impossible" << std::endl;
		std::cout << "float	: Impossible" << std::endl;
		std::cout << "double	: Impossible" << std::endl;
	}

}

// TODO: Implement _printFloat and _printDouble helper methods
void	ScalarConverter::_printChar(const char c) {
	std::cout << "char	: '" << c << "'" << std::endl;
	std::cout << "int	: " << static_cast<int>(c) << std::endl;
	std::cout << "float	: " << static_cast<float>(c) << std::endl;
	std::cout << "double	: " << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::_printInt(const int i) {
	std::cout << "char	: '"; 
	if (i >= 32 && i <= 126) {
		std::cout << static_cast<char>(i) << "'" << std::endl;
	} else {
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int	: " << i << std::endl;
	std::cout << "float	: " << static_cast<float>(i) << std::endl;
	std::cout << "double	: " << static_cast<double>(i) << std::endl;

}
