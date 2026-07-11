
#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>

template <typename T>
int	easyfind(T& container, int& find) {
	std::find(container.began(), container.end(), find);	
	return (find);
}

#endif // !EASYFIND_H
