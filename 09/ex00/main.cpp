#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	
	if (ac != 2) {
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		return 1;
	}

	BitcoinExchange bitcoinExchange;

	bitcoinExchange.processInputFile(av[1]);
	bitcoinExchange.printExchangeRates();

	return 0;
}
