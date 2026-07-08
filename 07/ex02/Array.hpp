
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>


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
Array<T>::Array(unsigned int n) { 
	try {
		content = new T[n]();
	}catch (std::exception &e) {
		content = NULL;
		std::cout << "Exception " << e.what() << std::endl;
	}
}

template <typename T>
Array<T>::Array(const Array& other) : n(other.n) {
	try {
		content = new T[n]();
		for (unsigned int i = 0; i < n; i++)
			content[i] = other.content[i];
	}catch (std::exception &e) {
		content = NULL;
		std::cout << "Exception " << e.what() << std::endl;
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		if (content)
			delete[] content;
		n = other.n;
		try {
			content = new T[n]();
			for (unsigned int i = 0; i < n; i++)
				content[i] = other.content[i];
		}catch (std::exception &e) {
			content = NULL;
			std::cout << "Exception " << e.what() << std::endl;
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](int i) {
	if (i < 0 || static_cast<unsigned int>(i) >= n) {
		throw std::out_of_range("Index out of range");
	} else {
		return content[i];
	}
}

template <typename T>
Array<T>::~Array() { 
	if (content)
		delete[] content; 
}

#endif // ARRAY_HPP
