
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename A, typename Func>
void iter(A *arr, const size_t n, Func f) {
	if (!arr || n < 0 ) return ;
	for (size_t i = 0; i < n; i++)
		f(arr[i]);
}

#endif
