#include "PmergeMe.hpp"


int	main(int ac, char **av){

	PmergeMe::Vector	a;
	PmergeMe::Vector	d;

	PmergeMe::prepare(a, ac, av);
	PmergeMe::prepare(d, ac, av);

	PmergeMe::sort(a);
	PmergeMe::sort(d);

	return 0;
}
