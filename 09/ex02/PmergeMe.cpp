#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

void	PmergeMe::prepare(Vector &vec, int ac, char **av) {
	
	if (ac < 2)
		throw std::invalid_argument("Error: No input numbers provided.");

	for (int i = 1; i < ac; i++) {
		int num = std::atoi(av[i]);
		vec.push_back(num);
	}
}

bool	PmergeMe::isLess(value_type &a, value_type &b) {
	_nb_cmp++;
	return (a < b);
}

bool	PmergeMe::isLess(Vector &a, Vector &b) {
	_nb_cmp++;
	return (a.back() < b.back());
}

bool	PmergeMe::isLess(Deque &a, Deque &b) {
	_nb_cmp++;
	return (a.back() < b.back());
}

// ---------------------

void	PmergeMe::sort(Vector &vec) {
	if (vec.size() < 2)
		return;
	_nb_cmp = 0;
	mergeInsert(vec, 1);
}

void	PmergeMe::mergeInsert(Vector &vec, int size_g) {
	if (size_g >= vec.size())
		return;

	pairwiseSort(vec, size_g);
	mergeInsert(vec, size_g * 2);
	insertion(vec, size_g);
}

void	PmergeMe::pairwiseSort(Vector &vec, int size_g) {

	std::size_t step = size_g * 2;

	for (std::size_t i = 0; i + step <= vec.size(); i += step)
	{
		std::size_t first_group_last	= i + size_g - 1;
		std::size_t second_group_last	= i + step - 1;

		if (isLess(vec[second_group_last], vec[first_group_last]))
		{
			std::swap_ranges(
					vec.begin() + i,
					vec.begin() + i + size_g,
					vec.begin() + i + size_g
					);
		}
	}
}

std::vector<PmergeMe::Vector>	PmergeMe::getMainChain(Vector &vec, int size_g) {
	std::vector<Vector>	main;
	std::size_t step = size_g * 2;

	for (std::size_t i = 0; i + step <= vec.size(); i += step)
	{
		Vector group(vec.begin() + i + size_g, vec.begin() + i + step);
		main.push_back(group);
	}
	return main;
}

std::vector<PmergeMe::Vector>	PmergeMe::getPend(Vector &vec, int size_g) {
	std::vector<Vector>	pend;
	std::size_t step = size_g * 2;
	std::size_t i = 0;

	for (; i + step <= vec.size(); i += step)
	{
		Vector group(vec.begin() + i, vec.begin() + i + size_g);
		pend.push_back(group);
	}
	
	if (i < vec.size())
	{
		Vector leftover(vec.begin() + i, vec.end());
		pend.push_back(leftover);
	}

	return pend;
}

void	PmergeMe::insertion(Vector &vec, int size_g) {

	std::vector<Vector>	main = getMainChain(vec, size_g);
	std::vector<Vector>	pend = getPend(vec, size_g);

	if (pend.empty()) return;
	


}
