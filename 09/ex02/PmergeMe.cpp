#include "PmergeMe.hpp"
#include <iterator>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

size_t PmergeMe::_nb_cmp = 0;

void	PmergeMe::prepare(Vector &vec, int ac, char **av) {
	
	if (ac < 2)
		throw std::invalid_argument("Error: No input numbers provided.");

	for (int i = 1; i < ac; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (!std::isdigit(av[i][j]))
				throw std::invalid_argument("Error: Invalid input character.");
		}
		if (av[i][0] == '\0')
			throw std::invalid_argument("Error: Empty argument.");
		int num = std::atoi(av[i]);
		if (num > 2147483647 || num < 0)
			throw std::invalid_argument("Error: Number out of integer bounds.");
		vec.push_back(num);
	}
}

bool	PmergeMe::isLess(const value_type &a, const value_type &b) {
	_nb_cmp++;
	return (a < b);
}

bool	PmergeMe::isLess(const Vector &a, const Vector &b) {
	_nb_cmp++;
	return (a.back() < b.back());
}

bool	PmergeMe::isLess(const Deque &a, const Deque &b) {
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

void	PmergeMe::mergeInsert(Vector &vec, std::size_t size_g) {
	if (size_g >= vec.size())
		return;

	pairwiseSort(vec, size_g);
	mergeInsert(vec, size_g * 2);
	insertion(vec, size_g);
}

void	PmergeMe::pairwiseSort(Vector &vec, std::size_t size_g) {

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

std::vector<PmergeMe::Vector>	PmergeMe::getMainChain(Vector &vec, std::size_t size_g) {
	std::vector<Vector>	main;
	std::size_t step = size_g * 2;

	for (std::size_t i = 0; i + step <= vec.size(); i += step)
	{
		Vector group(vec.begin() + i + size_g, vec.begin() + i + step);
		main.push_back(group);
	}
	return main;
}

std::vector<PmergeMe::Vector>	PmergeMe::getPend(Vector &vec, std::size_t size_g) {
	std::vector<Vector>	pend;
	std::size_t step = size_g * 2;
	std::size_t i = 0;

	for (; i + step <= vec.size(); i += step)
	{
		Vector group(vec.begin() + i, vec.begin() + i + size_g);
		pend.push_back(group);
	}

	if (vec.size() - i >= size_g)
	{
		Vector leftover(vec.begin() + i, vec.begin() + i + size_g);
		pend.push_back(leftover);
	}

	return pend;
}
std::vector<std::size_t>	PmergeMe::buildJacobsthal(std::size_t pend_size) {
	std::vector<std::size_t> jacob;
	jacob.push_back(1);
	jacob.push_back(3);

	while (jacob.back() < pend_size) {
		std::size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}
	return jacob;
}

void	PmergeMe::insertion(Vector &vec, std::size_t size_g) {
	std::vector<Vector> main = getMainChain(vec, size_g);
	std::vector<Vector> pend = getPend(vec, size_g);

	if (pend.empty()) return;

	std::size_t step = size_g * 2;
	std::size_t tail_start = 0;
	for (; tail_start + step <= vec.size(); tail_start += step) {}
	if (vec.size() - tail_start >= size_g) {
		tail_start += size_g;
	}
	Vector tail(vec.begin() + tail_start, vec.end());

	main.insert(main.begin(), pend[0]);

	std::vector<std::size_t> jacob = buildJacobsthal(pend.size());
	std::size_t	current_jacob, last_jacob = 1;
	std::size_t	inserted = 1;

	std::vector<Vector>::iterator end_bound;
	std::vector<Vector>::iterator insert_pos;
	Vector	chunk_to_insert;

	for (std::size_t i = 1; i < jacob.size(); ++i) {

		current_jacob = std::min(jacob[i], pend.size());

		for (std::size_t j = current_jacob; j > last_jacob; --j) {

			chunk_to_insert = pend[j - 1];

			if ((j - 1) + inserted > main.size())
				end_bound = main.end();
			else
				end_bound = main.begin() + (j - 1) + inserted;

			insert_pos = std::lower_bound(
					main.begin(),
					end_bound,
					chunk_to_insert,
					static_cast<bool(*)(const Vector&, const Vector&)>(isLess)
					);

			main.insert(insert_pos, chunk_to_insert);
			++inserted;
		}
		last_jacob = current_jacob;
	}

	vec.clear();
	for (std::size_t k = 0; k < main.size(); ++k) {
		vec.insert(vec.end(), main[k].begin(), main[k].end());
	}
	vec.insert(vec.end(), tail.begin(), tail.end());
}

// Deque Implementations

void	PmergeMe::prepare(Deque &vec, int ac, char **av) {

	if (ac < 2)
		throw std::invalid_argument("Error: No input numbers provided.");

	for (int i = 1; i < ac; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (!std::isdigit(av[i][j]))
				throw std::invalid_argument("Error: Invalid input character.");
		}
		int num = std::atoi(av[i]);
		vec.push_back(num);
	}
}

void	PmergeMe::sort(Deque &vec) {
	if (vec.size() < 2)
		return;

	_nb_cmp = 0;
	mergeInsert(vec, 1);
}

void	PmergeMe::mergeInsert(Deque &vec, std::size_t size_g) {
	if (size_g >= vec.size())
		return;

	pairwiseSort(vec, size_g);
	mergeInsert(vec, size_g * 2);
	insertion(vec, size_g);
}

void	PmergeMe::pairwiseSort(Deque &vec, std::size_t size_g) {

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

std::vector<PmergeMe::Deque>	PmergeMe::getMainChain(Deque &vec, std::size_t size_g) {
	std::vector<Deque>	main;
	std::size_t step = size_g * 2;

	for (std::size_t i = 0; i + step <= vec.size(); i += step)
	{
		Deque group(vec.begin() + i + size_g, vec.begin() + i + step);
		main.push_back(group);
	}
	return main;
}

std::vector<PmergeMe::Deque>	PmergeMe::getPend(Deque &vec, std::size_t size_g) {
	std::vector<Deque>	pend;
	std::size_t step = size_g * 2;
	std::size_t i = 0;

	for (; i + step <= vec.size(); i += step)
	{
		Deque group(vec.begin() + i, vec.begin() + i + size_g);
		pend.push_back(group);
	}

	if (vec.size() - i >= size_g)
	{
		Deque leftover(vec.begin() + i, vec.begin() + i + size_g);
		pend.push_back(leftover);
	}

	return pend;
}

void	PmergeMe::insertion(Deque &vec, std::size_t size_g) {
	std::vector<Deque> main = getMainChain(vec, size_g);
	std::vector<Deque> pend = getPend(vec, size_g);

	if (pend.empty()) return;

	std::size_t step = size_g * 2;
	std::size_t tail_start = 0;
	for (; tail_start + step <= vec.size(); tail_start += step) {}
	if (vec.size() - tail_start >= size_g) {
		tail_start += size_g;
	}
	Deque tail(vec.begin() + tail_start, vec.end());

	main.insert(main.begin(), pend[0]);

	std::vector<std::size_t> jacob = buildJacobsthal(pend.size());
	std::size_t	current_jacob, last_jacob = 1;
	std::size_t	inserted = 1;

	std::vector<Deque>::iterator end_bound;
	std::vector<Deque>::iterator insert_pos;
	Deque	chunk_to_insert;

	for (std::size_t i = 1; i < jacob.size(); ++i) {

		current_jacob = std::min(jacob[i], pend.size());

		for (std::size_t j = current_jacob; j > last_jacob; --j) {

			chunk_to_insert = pend[j - 1];

			if ((j - 1) + inserted > main.size())
				end_bound = main.end();
			else
				end_bound = main.begin() + (j - 1) + inserted;

			insert_pos = std::lower_bound(
					main.begin(),
					end_bound,
					chunk_to_insert,
					static_cast<bool(*)(const Deque&, const Deque&)>(isLess)
					);

			main.insert(insert_pos, chunk_to_insert);
			++inserted;
		}
		last_jacob = current_jacob;
	}

	vec.clear();
	for (std::size_t k = 0; k < main.size(); ++k) {
		vec.insert(vec.end(), main[k].begin(), main[k].end());
	}
	vec.insert(vec.end(), tail.begin(), tail.end());
}
