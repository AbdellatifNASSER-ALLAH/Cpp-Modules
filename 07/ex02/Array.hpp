#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
	private:
		unsigned int	n;
		T		*content;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();

		Array& operator=(const Array& other);

		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;

		unsigned int size() const;
};

template <typename T>
Array<T>::Array() : n(0), content(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : n(n) {
	if (n > 0)
		content = new T[n]();
	else
		content = NULL;
}

template <typename T>
Array<T>::Array(const Array& other) : n(other.n), content(NULL) {
	if (n > 0) {
		content = new T[n]();
		for (unsigned int i = 0; i < n; i++)
			content[i] = other.content[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] content;
		
		n = other.n;
		if (n > 0) {
			content = new T[n]();
			for (unsigned int i = 0; i < n; i++)
				content[i] = other.content[i];
		} else {
			content = NULL;
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= n)
		throw std::out_of_range("Index out of bounds");
	return content[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
	if (i >= n)
		throw std::out_of_range("Index out of bounds");
	return content[i];
}

template <typename T>
unsigned int Array<T>::size() const {
	return n;
}

template <typename T>
Array<T>::~Array() {
	delete[] content;
}

#endif // ARRAY_HPP
