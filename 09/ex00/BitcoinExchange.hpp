#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>

class	BitcoinExchange {
	private:
		std::map<std::string, float>	data;
		std::map<std::string, float>	input;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	processInputFile(const std::string &filename);
		void	printExchangeRates() const;
};

#endif
