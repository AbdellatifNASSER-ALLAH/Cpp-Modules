#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){

	std::ifstream file("data.csv");
	if (!file.is_open()) {
		std::cerr << "Error: could not open data.csv" << std::endl;
		return;
	}

	std::string line;
	int	firstLine = 1;

	while (std::getline(file, line)) {
		if (firstLine) {
			if (line != "date,exchange_rate") {
				std::cerr << "Error: invalid header in data.csv" << std::endl;
				return;
			}
			firstLine = 0;
			continue;
		}

		std::string date = line.substr(0, line.find(','));
		if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
			std::cerr << "Error: invalid date format in data.csv" << std::endl;
			return;
		}
		float value = std::atof(line.substr(line.find(',') + 1).c_str());
		if (value < 0) {
			std::cerr << "Error: negative value in data.csv" << std::endl;
			return;
		}

		data[date] = value;
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	data = other.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		data = other.data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}
void BitcoinExchange::processInputFile(const std::string &filename) {
	std::ifstream file(filename.c_str());

	if (!file.is_open()) {
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}

	std::string line;

	// Check header
	if (!std::getline(file, line)) {
		std::cerr << "Error: empty file" << std::endl;
		return;
	}

	if (line != "date | value") {
		std::cerr << "Error: invalid header in " << filename << std::endl;
		return;
	}

	while (std::getline(file, line)) {

		std::string::size_type separator = line.find('|');

		if (separator == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, separator - 1);
		float value = std::atof(line.substr(separator + 2).c_str());

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::const_iterator dataIt =
			data.lower_bound(date);

		if (dataIt == data.end()) {
			--dataIt;
		}
		else if (dataIt->first > date) {
			if (dataIt == data.begin()) {
				std::cerr << "Error: no exchange rate available for "
						  << date << std::endl;
				continue;
			}
			--dataIt;
		}

		float exchangeRate = dataIt->second;
		float result = value * exchangeRate;

		std::cout << date << " => " << value
				  << " = " << result << std::endl;
	}

	file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.size() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.size(); ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	// Leap year
	if (month == 2 &&
			(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
		daysInMonth[1] = 29;
	}

	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}
