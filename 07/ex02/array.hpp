
#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class	Array {
	private:
		unsigned int	n;
		T	*content;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();

		Array& operator=(const Array& other);
		T& operator[](int i);
};

#include "array.tpp"

#endif // ARRAY_HPP
