#include "ScalarConverter.hpp"
#include <cerrno>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	UNKNOWN
};

static bool isChar(const std::string& str) {
	return str.length() == 1 && !isdigit(str[0]) && isprint(str[0]);
}

static bool isInt(const std::string& str) {
	if (str.empty()) return false;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-') i++;
	if (i == str.length()) return false;
	for (; i < str.length(); i++) {
		if (!isdigit(str[i])) return false;
	}
	return true;
}

static bool isFloat(const std::string& str) {
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff") return true;
	if (str.empty() || str[str.length() - 1] != 'f') return false;
	
	bool foundDot = false;
	bool foundDigit = false;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-') i++;
	if (i == str.length() - 1) return false; // only sign and 'f'
	
	for (; i < str.length() - 1; i++) {
		if (str[i] == '.') {
			if (foundDot) return false;
			foundDot = true;
		} else if (isdigit(str[i])) {
			foundDigit = true;
		} else {
			return false;
		}
	}
	return foundDigit;
}

static bool isDouble(const std::string& str) {
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf") return true;
	if (str.empty()) return false;

	bool foundDot = false;
	bool foundDigit = false;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-') i++;
	if (i == str.length()) return false; // only sign

	for (; i < str.length(); i++) {
		if (str[i] == '.') {
			if (foundDot) return false;
			foundDot = true;
		} else if (isdigit(str[i])) {
			foundDigit = true;
		} else {
			return false;
		}
	}
	return foundDigit;
}

static void printResults(char c, int i, float f, double d, bool possibleChar, bool possibleInt, bool isSpecial) {
	// Char output
	std::cout << "char: ";
	if (isSpecial || !possibleChar)
		std::cout << "impossible" << std::endl;
	else if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	// Int output
	std::cout << "int: ";
	if (isSpecial || !possibleInt)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;

	// Float output
	std::cout << "float: ";
	if (isSpecial) {
		std::cout << f << "f" << std::endl;
	} else {
		if (f == static_cast<float>(static_cast<int>(f)))
			std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		else
			std::cout << f << "f" << std::endl;
	}

	// Double output
	std::cout << "double: ";
	if (isSpecial) {
		std::cout << d << std::endl;
	} else {
		if (d == static_cast<double>(static_cast<int>(d)))
			std::cout << std::fixed << std::setprecision(1) << d << std::endl;
		else
			std::cout << d << std::endl;
	}
	std::cout.unsetf(std::ios::floatfield);
}

void ScalarConverter::convert(const std::string &str) {
	e_type type = UNKNOWN;

	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf" ||
		str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		type = SPECIAL;
	else if (isChar(str))
		type = CHAR;
	else if (isInt(str))
		type = INT;
	else if (isFloat(str))
		type = FLOAT;
	else if (isDouble(str))
		type = DOUBLE;

	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;
	bool possibleChar = true;
	bool possibleInt = true;

	switch (type) {
		case CHAR:
			c = str[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case INT: {
			long l = strtol(str.c_str(), NULL, 10);
			if (l > INT_MAX || l < INT_MIN) {
				possibleInt = false;
				d = strtod(str.c_str(), NULL);
				f = static_cast<float>(d);
			} else {
				i = static_cast<int>(l);
				c = static_cast<char>(i);
				f = static_cast<float>(i);
				d = static_cast<double>(i);
			}
			break;
		}
		case FLOAT:
			f = strtof(str.c_str(), NULL);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case DOUBLE:
			d = strtod(str.c_str(), NULL);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
		case SPECIAL:
			d = strtod(str.c_str(), NULL);
			f = static_cast<float>(d);
			printResults(0, 0, f, d, false, false, true);
			return;
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
	}

	if (type != CHAR) {
		if (d < 0 || d > 127) possibleChar = false;
		if (d < INT_MIN || d > INT_MAX) possibleInt = false;
	}

	printResults(c, i, f, d, possibleChar, possibleInt, false);
}
