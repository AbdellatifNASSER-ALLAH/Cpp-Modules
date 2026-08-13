#include "PmergeMe.hpp"


int	main(int ac, char **av){

	PmergeMe::Vector	a;

	PmergeMe::prepare(a, ac, av);

	PmergeMe::sort(a);

	return 0;
}
