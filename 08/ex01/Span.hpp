
#ifndef	SPAN_H
#define	SPAN_H

#include <vector>
class	Span{
	private:
		unsigned int _size;
		std::vector<int> _numbers;

		Span();
	public:
		Span(unsigned int);
		~Span();

		void	addNumber(int);
		int	shortestSpan() const;
		int	longestSpan() const;
		template <typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end) {
			for (InputIterator it = begin; it != end; ++it) {
				addNumber(*it);
			}
		}

};

#endif
