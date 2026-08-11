#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>

class	BitcoinExchange {
	private:
		std::map<std::string, float>	data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	processInputFile(const std::string &filename);
		bool	isValidDate(const std::string& date) const;
};

#endif
