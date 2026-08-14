#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime> 
#include <stdexcept>

class	PmergeMe {
	public:
		typedef int                     value_type;
		typedef std::deque<value_type>  Deque;
		typedef std::vector<value_type> Vector;

		static size_t _nb_cmp;

		static void sort(Vector &a);
		static void sort(Deque &a);
		static void prepare(Vector &vec, int ac, char **av);
		static void prepare(Deque &vec, int ac, char **av);

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		static	void			mergeInsert(Vector &vec, std::size_t size_g);
		static	void			pairwiseSort(Vector &vec, std::size_t size_g);
		static	void			insertion(Vector &vec, std::size_t size_g);
		static	std::vector<Vector>	getMainChain(Vector &vec, std::size_t size_g);
		static	std::vector<Vector>	getPend(Vector &vec, std::size_t size_g);

		static	void			mergeInsert(Deque &vec, std::size_t size_g);
		static	void			pairwiseSort(Deque &vec, std::size_t size_g);
		static	void			insertion(Deque &vec, std::size_t size_g);
		static	std::vector<Deque>	getMainChain(Deque &vec, std::size_t size_g);	
		static	std::vector<Deque>	getPend(Deque &vec, std::size_t size_g);

		static	std::vector<std::size_t>	buildJacobsthal(std::size_t pend_size);

		static	bool	isLess(const value_type &a, const value_type &b);
		static	bool	isLess(const Vector &a, const Vector &b);
		static	bool	isLess(const Deque &a, const Deque &b);

};


#endif
