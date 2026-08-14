#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>

class	BitcoinExchange {
	private:
		std::map<std::string, float>	data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange &operator=(const BitcoinExchange &);
		~BitcoinExchange();

		void	processInputFile(const std::string &);

	private:
		static	bool	isValidDate(const std::string&);
		static	bool isValidValue(const std::string &str);
		static	std::string trim(const std::string &str);
};

#endif
