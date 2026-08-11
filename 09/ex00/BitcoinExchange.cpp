#include "BitcoinExchange.hpp"
#include <fstream>

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
			firstLine = false;
			continue;
		}

		std::string date = line.substr(0, line.find(','));
		if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
			std::cerr << "Error: invalid date format in data.csv" << std::endl;
			return;
		}

		float value = std::stof(line.substr(line.find(',') + 1));
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
	input = other.input;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		data = other.data;
		input = other.input;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::processInputFile(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open " << filename << std::endl;
		return;
	}

	std::string line;
	int	firstLine = 1;

	while (std::getline(file, line)) {
		if (firstLine) {
			if (line != "date | value") {
				std::cerr << "Error: invalid header in " << filename << std::endl;
				return;
			}
			firstLine = 0;
			continue;
		}

		std::string date = line.substr(0, line.find('|') - 1);
		if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
			std::cerr << "Error: invalid date format in " << filename << std::endl;
			continue;
		}

		float value = std::stof(line.substr(line.find('|') + 2));
		if (value < 0) {
			std::cerr << "Error: negative value in " << filename << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: value too large in " << filename << std::endl;
			continue;
		}

		input[date] = value;
	}
	file.close();
}

void BitcoinExchange::printExchangeRates() const {
	for (std::map<std::string, float>::const_iterator it = input.begin(); it != input.end(); ++it) {

		std::map<std::string, float>::const_iterator dataIt = data.lower_bound(it->first);

		if (dataIt == data.end() || dataIt->first > it->first) {
			if (dataIt == data.begin()) {
				std::cerr << "Error: no exchange rate available for " << it->first << std::endl;
				continue;
			}
			--dataIt;
		}

		if (dataIt != data.end()) {
			float exchangeRate = dataIt->second;
			float result = it->second * exchangeRate;
			std::cout << it->first << " => " << it->second << " = " << result << std::endl;
		} else {
			std::cerr << "Error: no exchange rate available for " << it->first << std::endl;
		}
	}
}
