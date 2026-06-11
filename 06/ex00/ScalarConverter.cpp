#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iomanip>
#include <limits>
#include <cctype>

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
	std::string specialTypes[6] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};
	bool isSpecial = false;
	for (int i = 0; i < 6; i++) {
		if (str == specialTypes[i]) {
			isSpecial = true;
			break;
		}
	}

	char charVal = 0;
	int intVal = 0;
	float floatVal = 0.0f;
	double doubleVal = 0.0;

	bool possibleChar = true;
	bool possibleInt = true;
	bool possibleFloat = true;

	if (isSpecial) {
		possibleChar = false;
		possibleInt = false;
		doubleVal = atof(str.c_str());
		floatVal = static_cast<float>(doubleVal);
	} else if (str.length() == 1 && !isdigit(str[0])) {
		charVal = str[0];
		intVal = static_cast<int>(charVal);
		floatVal = static_cast<float>(charVal);
		doubleVal = static_cast<double>(charVal);
	} else {
		char *endptr;
		doubleVal = strtod(str.c_str(), &endptr);
		
		if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0')) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}

		if (doubleVal < 0 || doubleVal > 127)
			possibleChar = false;
		else
			charVal = static_cast<char>(doubleVal);

		if (doubleVal < INT_MIN || doubleVal > INT_MAX)
			possibleInt = false;
		else
			intVal = static_cast<int>(doubleVal);

		if (doubleVal < -std::numeric_limits<float>::max() || doubleVal > std::numeric_limits<float>::max()) {
            if (doubleVal != doubleVal || doubleVal > std::numeric_limits<double>::max() || doubleVal < -std::numeric_limits<double>::max()) {
                // handled by isSpecial or we allow inf
            } else {
                possibleFloat = false;
            }
        }
		floatVal = static_cast<float>(doubleVal);
	}

	// char
	std::cout << "char: ";
	if (!possibleChar)
		std::cout << "impossible" << std::endl;
	else if (isprint(charVal))
		std::cout << "'" << charVal << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	// int
	std::cout << "int: ";
	if (!possibleInt)
		std::cout << "impossible" << std::endl;
	else
		std::cout << intVal << std::endl;

	// float
	std::cout << "float: ";
    if (!possibleFloat && !isSpecial) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << floatVal;
        if (!isSpecial && floatVal == floor(floatVal) && floatVal < 1000000)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }

	// double
	std::cout << "double: ";
    std::cout << doubleVal;
    if (!isSpecial && doubleVal == floor(doubleVal) && doubleVal < 1000000)
        std::cout << ".0";
    std::cout << std::endl;
}
