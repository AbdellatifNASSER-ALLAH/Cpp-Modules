
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : value(0) {
}

Fixed::Fixed(const int ivalue) {
	this->value = ivalue << fractionalBits;
}
Fixed::Fixed(const float fvalue) {
	this->value = roundf(fvalue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
}

int	Fixed::getRawBits() const {
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float	Fixed::toFloat() const { 
	return ((float)this->value / (1 << fractionalBits));
}

int	Fixed::toInt() const {
	return (this->value >> fractionalBits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed ret;

	ret.value = this->value + other.value;
	return (ret);
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed ret;

	ret.value = this->value - other.value;
	return (ret);
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed ret;

	long long res = (long long)this->value * (long long)other.value;
	ret.setRawBits((int)(res >> fractionalBits));
	return (ret);
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed ret;

	ret.value = (this->value << fractionalBits) / other.value;
	return (ret);
}

bool	Fixed::operator<(const Fixed& other) const {
	return this->value < other.value;
}

bool	Fixed::operator>(const Fixed& other) const {
	return this->value > other.value;
}

bool	Fixed::operator<=(const Fixed& other)  const {
	return (this->value <= other.value);
}

bool	Fixed::operator>=(const Fixed& other) const {
	return this->value >= other.value;
}

bool	Fixed::operator!=(const Fixed& other) const {
	return this->value != other.value;
}

bool	Fixed::operator==(const Fixed& other) const {
	return this->value == other.value;
}

Fixed&	Fixed::operator++() {
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)  {
	Fixed temp(*this);
	this->value++;
	return (temp);
}

Fixed&	Fixed::operator--()  {
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)  {
	Fixed temp(*this);
	this->value--;
	return (temp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}
