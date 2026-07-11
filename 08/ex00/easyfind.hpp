
#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int find) {
	typename T::iterator it = std::find(container.begin(), container.end(), find);
	return (it);
}

#endif // !EASYFIND_H
