#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <climits>

Span::Span() {}
Span::~Span() {}

Span::Span(unsigned int n) : _size(n) {
	_numbers.reserve(n);
}

void	Span::addNumber(int n) {
	if (_numbers.size() >= _size)
		throw std::runtime_error("Span is full");
	if (std::find(_numbers.begin(), _numbers.end(), n) != _numbers.end())
		throw std::runtime_error("Number already exists in the span");
	_numbers.push_back(n);
}

int	Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	std::vector<int>::iterator it = sortedNumbers.begin();
	std::vector<int>::iterator next = it + 1;
	long span, shortest = LONG_MAX;
	while (next != sortedNumbers.end()) {
		span = static_cast<long>(*next) - static_cast<long>(*it);
		shortest = (span < shortest) ? span : shortest;
		++it;
		++next;
	}
	return shortest;
}

int	Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return max - min;
}
