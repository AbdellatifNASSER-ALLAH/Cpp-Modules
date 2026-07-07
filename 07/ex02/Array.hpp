
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

template <typename T>
Array<T>::Array() : n(0), content( new T()) {}


template <typename T>
Array<T>::~Array() { delete[] content; }

#endif // ARRAY_HPP
