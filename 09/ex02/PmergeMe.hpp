#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

class	PmergeMe {
	public:
		typedef int                     value_type;
		typedef std::deque<value_type>  Deque;
		typedef std::vector<value_type> Vector;

		static int _nb_cmp;

		static void sort(Vector &a);
		static void sort(Deque &a);
		static void prepare(Vector &vec, int ac, char **av);

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		static	void	mergeInsert(Vector &vec, int size_g);
		static	void	pairwiseSort(Vector &vec, int size_g);
		static	void	insertion(Vector &vec, int size_g);

};


#endif
